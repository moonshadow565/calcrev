#!/bin/env python 
from __future__ import annotations 
import typing
import dataclasses
from typing import Optional, Union, Any, NamedTuple, Generic, TypeVar, Callable, Mapping

def Fnv1a32(s: Union[str, int]) -> int:
    if isinstance(s, int):
        return s
    if s.startswith('{') and s.endswith('}'):
        return int(s[1:-1], 16)
    if s.startswith('t_0x') or s.startswith('m_0x'):
        return int(s[4:], 16)
    h = 0x811c9dc5
    for b in s.encode('ascii').lower():
        h = ((h ^ b) * 0x01000193) % 0x100000000
    return h

NoneType = type(None)
TypeV = TypeVar('TypeV', covariant=True)


Int8 = int

UInt8 = int

Int16 = int

UInt16 = int

Int32 = int

UInt32 = int

Int64 = int

UInt64 = int

class Vec2(NamedTuple):
    x: float = float()
    y: float = float()

class Vec3(NamedTuple):
    x: float = float()
    y: float = float()
    z: float = float()

class Vec4(NamedTuple):
    x: float = float()
    y: float = float()
    z: float = float()
    w: float = float()

class Mtx44(NamedTuple):
    r0: Vec4 = Vec4()
    r1: Vec4 = Vec4()
    r2: Vec4 = Vec4()
    r3: Vec4 = Vec4()

class Color(NamedTuple):
    r: UInt8 = UInt8()
    g: UInt8 = UInt8()
    b: UInt8 = UInt8()
    a: UInt8 = UInt8()

class Hash:
    unhashed: Optional[str]
    hashed: int
    def __init__(self, value: Union[Hash, str, int, NoneType] = None):
        if value == None:
            self.unhashed = None
            self.hashed = 0
        elif isinstance(value, int):
            self.unashed = None
            self.hashed = value
        elif isinstance(value, Hash):
            self.unhashed = value.unhashed
            self.hashed = value.hashed
        elif value.startswith('{') and value.endswith('}'):
            self.unhashed = None
            self.hashed = int(value[1:-1], 16)
        else:
            self.unhashed = value
            h = 0x811c9dc5
            for b in value.encode('ascii').lower():
                h = ((h ^ b) * 0x01000193) % 0x100000000
            self.hashed = h
    def __str__(self) -> str:
        return repr(self.unhashed) if self.unhashed else f"0x{self.hashed:x}"
    def __repr__(self) -> str:
        return repr(self.unhashed) if self.unhashed else f"0x{self.hashed:x}"
    def __hash__(self) -> Any:
        return hash(self.hashed)
    def __bool__(self) -> bool:
        return not not self.hashed
    def __lt__(self, other: Union[Hash, str, int, NoneType]) -> bool:
        return self.hashed < Hash(other).hashed
    def __le__(self, other: Union[Hash, str, int, NoneType]) -> bool:
        return self.hashed < Hash(other).hashed
    def __eq__(self, other: Union[Hash, str, int, NoneType]) -> bool:
        return self.hashed == Hash(other).hashed
    def __ne__(self, other: Union[Hash, str, int, NoneType]) -> bool:
        return self.hashed != Hash(other).hashed
    def __gt__(self, other: Union[Hash, str, int, NoneType]) -> bool:
        return self.hashed > Hash(other).hashed
    def __ge__(self, other: Union[Hash, str, int, NoneType]) -> bool:
        return self.hashed >= Hash(other).hashed

class File(str):
    pass

@dataclasses.dataclass(frozen=True, order=True)
class Link(Generic[TypeV]):
    entry: str = ""
    type_name: Optional[type] = None

    def get(self, lookup: Mapping[str, Any]) -> Optional[V]:
        if self.entry in lookup:
            found = lookup[self.entry]
            if isinstance(found, dict):
                created = MetaCreate(self.type_name, found)
                lookup[self.entry] = created
                return created
            else:
                return found
        return None

@dataclasses.dataclass
class MetaBase:
    pass

_MetaClassList : dict[int, Any] = {}

_META_CREATE: dict[Any, Any] = {
    NoneType: lambda a, v: None,
    bool: lambda a, v: bool(v),
    Int8: lambda a, v: Int8(v),
    UInt8: lambda a, v: UInt8(v),
    Int16: lambda a, v: Int16(v),
    UInt16: lambda a, v: UInt16(v),
    Int32: lambda a, v: Int32(v),
    UInt32: lambda a, v: UInt32(v),
    Int64: lambda a, v: Int64(v),
    UInt64: lambda a, v: UInt64(v),
    float: lambda a, v: float(v),
    Vec2: lambda a, v: Vec2(*(float(x) for x in v)),
    Vec3: lambda a, v: Vec3(*(float(x) for x in v)),
    Vec4: lambda a, v: Vec4(*(float(x) for x in v)),
    Mtx44: lambda a, v: Mtx44(*(Vec4(*x) for x in v)),
    Color: lambda a, v: Color(*(UInt8(x) for x in v)),
    str: lambda a, v: str(v),
    Hash: lambda a, v: Hash(v),
    File: lambda a, v: File(v),
    Union: lambda a, v: None if v == None else MetaCreate(a[0], v),
    Link: lambda a, v: Link(v, a[0]),
    list: lambda a, v: list(MetaCreate(a[0], x) for x in v),
    dict: lambda a, v: dict((MetaCreate(a[0], x), MetaCreate(a[1], y)) for x,y in v.items()),
}

def MetaCreate(type_name: typing.Type[TypeV], value: Any) -> TypeV:
    type_args = typing.get_args(type_name)
    if type_args:
        type_origin = typing.get_origin(type_name)
        return _META_CREATE[type_origin](type_args, value)
    elif type_name in _META_CREATE:
        return _META_CREATE[type_name](type_args, value)
    else:
        type_ctor = _MetaClassList[Fnv1a32(value["__type"])]
        result = type_ctor()
        assert(isinstance(result, type_name))
        lookup = { Fnv1a32(k): v for k, v in value.items() }
        for field in dataclasses.fields(type_ctor):
            key = field.metadata["key"]
            if key in lookup:
                value = MetaCreate(eval(field.type), lookup[key]) # type: ignore
                setattr(result, field.name, value)
        return result

_META_DEFAULT: dict[str, Any] = {
    'NoneType': None,
    'bool': bool(),
    'Int8': Int8(),
    'UInt8': UInt8(),
    'Int16': Int16(),
    'UInt16': UInt16(),
    'Int32': Int32(),
    'UInt32': UInt32(),
    'Int64': Int64(),
    'UInt64': UInt64(),
    'float': float(),
    'Vec2': Vec2(),
    'Vec3': Vec3(),
    'Vec4': Vec4(),
    'Mtx44': Mtx44(),
    'Color': Color(),
    'str': str(),
    'Hash': Hash(),
    'File': File(),
}

def MetaField(key: int, type_name: str) -> dataclasses.Field:
    metadata: dict[str, Any] = { "key": key }
    if type_name.startswith('Optional['):
        return dataclasses.field(default = eval("None"), metadata = metadata)
    elif type_name in _META_DEFAULT:
        return dataclasses.field(default = _META_DEFAULT[type_name], metadata = metadata)
    else:
        return dataclasses.field(default_factory = lambda: eval(type_name)(), metadata = metadata)

def MetaClassEmpty(cls):
    chash = Fnv1a32(cls.__name__)
    _MetaClassList[chash] = cls
    return cls

def MetaClass(cls):
    for name, type_name in cls.__annotations__.items():
        setattr(cls, name, MetaField(Fnv1a32(name), type_name))
    return MetaClassEmpty(dataclasses.dataclass(cls))

@MetaClass
class WardSkinDisabler(MetaBase):
    DisableAllSkins: bool
    DisabledIds: list[UInt32]
    pass

@MetaClass
class IContextualAction(MetaBase):
    mHashedSituationTrigger: Hash
    mMaxOccurences: UInt32
    pass

@MetaClass
class ContextualActionPlayAnimation(IContextualAction):
    mHashedAnimationName: Hash
    mPlayAsEmote: bool
    pass

@MetaClassEmpty
class ContextualActionTriggerEvent(IContextualAction):
    pass

@MetaClass
class ContextualActionPlayAudio(IContextualAction):
    mSelfEventName: str
    mAllyEventName: str
    mEnemyEventName: str
    mSpectatorEventName: str
    mWaitForAnnouncerQueue: bool
    m_0x54cd5fca: bool
    m_0xbeb655b5: bool
    m_0x66a1c28b: str
    mWaitTimeout: float
    pass

@MetaClassEmpty
class ContextualActionPlayVo(ContextualActionPlayAudio):
    pass

@MetaClassEmpty
class IResource(MetaBase):
    pass

@MetaClass
class ContextualActionData(IResource):
    mCooldown: float
    m_0x9fd838b2: float
    mSituations: dict[Hash, ContextualSituation]
    mObjectPath: str
    pass

@MetaClassEmpty
class IContextualCondition(MetaBase):
    pass

@MetaClass
class ContextualConditionNegation(IContextualCondition):
    mChildCondition: Optional[IContextualCondition]
    pass

@MetaClass
class ContextualConditionItemId(IContextualCondition):
    mItems: list[Hash]
    pass

@MetaClass
class ContextualConditionMultikillSize(IContextualCondition):
    mMultikillSize: UInt8
    pass

@MetaClass
class ContextualConditionKillCount(IContextualCondition):
    mTotalKills: UInt16
    mCompareOp: UInt8
    pass

@MetaClass
class ContextualConditionItemVoGroup(IContextualCondition):
    mItemVoGroupHash: Hash
    pass

@MetaClass
class ContextualConditionHasItemFromVoGroup(IContextualCondition):
    mItemVoGroupHash: Hash
    pass

@MetaClass
class ContextualConditionLastBoughtItem(IContextualCondition):
    mItem: Hash
    pass

@MetaClass
class ContextualConditionRuleCooldown(IContextualCondition):
    mRuleCooldown: float
    pass

@MetaClass
class ContextualConditionChanceToPlay(IContextualCondition):
    mPercentChanceToPlay: UInt8
    pass

@MetaClass
class ContextualConditionMoveDistance(IContextualCondition):
    mDistance: float
    mCompareOp: UInt8
    pass

@MetaClass
class ContextualConditionCharacterLevel(IContextualCondition):
    mCharacterLevel: UInt8
    mCompareOp: UInt8
    pass

@MetaClass
class ContextualConditionTimeSinceStealthStateChange(IContextualCondition):
    mStateToCheck: UInt8
    mCompareOp: UInt8
    mTimeThreshold: float
    pass

@MetaClass
class ContextualConditionMarkerName(IContextualCondition):
    mMarkerNames: list[str]
    pass

@MetaClass
class ContextualConditionNeutralMinionMapSide(IContextualCondition):
    mTeamCompareOp: UInt8
    pass

@MetaClass
class ContextualConditionNeutralMinionCampName(IContextualCondition):
    mCampName: Hash
    pass

@MetaClass
class ContextualConditionNeutralMinionCampIsAlive(IContextualCondition):
    mCampIsAlive: bool
    pass

@MetaClass
class ContextualConditionNeutralCampId(IContextualCondition):
    mCampId: UInt8
    pass

@MetaClass
class ContextualConditionSituationHasRecentlyRun(IContextualCondition):
    mSituationNameHash: Hash
    mTime: float
    pass

@MetaClass
class ContextualConditionMapId(IContextualCondition):
    mMapIds: UInt32
    pass

@MetaClass
class ContextualConditionObjectiveTakeByMyTeam(IContextualCondition):
    mTakenObjective: UInt32
    pass

@MetaClass
class ContextualConditionMapRegionName(IContextualCondition):
    mRegionType: UInt8
    mRegionName: str
    pass

@MetaClass
class ContextualConditionTurretPosition(IContextualCondition):
    mTurretPosition: UInt8
    pass

@MetaClass
class ContextualConditionHasGold(IContextualCondition):
    mGold: float
    pass

@MetaClass
class ContextualConditionCustomTimer(IContextualCondition):
    mCustomTimer: float
    pass

@MetaClass
class ContextualConditionGameTimer(IContextualCondition):
    mGameTimeInMinutes: float
    mCompareOp: UInt8
    pass

@MetaClass
class ContextualConditionShopOpenCount(IContextualCondition):
    mShopOpenCount: UInt32
    pass

@MetaClass
class ContextualConditionShopCloseCount(IContextualCondition):
    mShopCloseCount: UInt32
    pass

@MetaClass
class ContextualConditionItemPurchased(IContextualCondition):
    mItemPurchased: bool
    pass

@MetaClass
class ContextualConditionItemCanBePurchased(IContextualCondition):
    mItemCanBePurchased: bool
    pass

@MetaClass
class ContextualConditionItemPriceMinimum(IContextualCondition):
    mItemPriceMinimum: UInt32
    pass

@MetaClass
class ContextualConditionOwnerTeamNetChampionKills(IContextualCondition):
    mOwnerTeamNetKillAdvantage: Int32
    mKillAdvantageCompareOp: UInt8
    mTimeFrameSeconds: float
    pass

@MetaClass
class ContextualConditionNearbyChampionCount(IContextualCondition):
    mTeamCompareOp: UInt8
    mCount: UInt32
    mCompareOp: UInt8
    pass

@MetaClass
class ContextualConditionNumberOfCharactersNearTargetPos(IContextualCondition):
    mNumberOfCharacters: UInt32
    mTeamCompareOp: UInt8
    mCompareOp: UInt8
    pass

@MetaClass
class ContextualConditionEnemyDeathsNearby(IContextualCondition):
    mEnemyDeaths: UInt32
    pass

@MetaClass
class ContextualConditionTeammateDeathsNearby(IContextualCondition):
    mTeammateDeaths: UInt32
    pass

@MetaClass
class ContextualConditionCharacter(IContextualCondition):
    mChildConditions: list[Optional[ICharacterSubcondition]]
    mCharacterType: UInt8
    pass

@MetaClass
class ContextualConditionAnyOtherHero(IContextualCondition):
    mChildConditions: list[Optional[ICharacterSubcondition]]
    pass

@MetaClassEmpty
class ICharacterSubcondition(MetaBase):
    pass

@MetaClass
class ContextualConditionCharacterName(ICharacterSubcondition):
    mCharacters: list[Hash]
    pass

@MetaClass
class ContextualConditionCharacterFormName(ICharacterSubcondition):
    mFormName: str
    pass

@MetaClass
class ContextualConditionCharacterSkinId(ICharacterSubcondition):
    mSkinIds: list[Int32]
    pass

@MetaClass
class ContextualConditionCharacterMetadata(ICharacterSubcondition):
    mCategory: str
    mData: str
    pass

@MetaClass
class ContextualConditionCharacterUnitTags(ICharacterSubcondition):
    mTagMode: UInt8
    mUnitTags: ObjectTags
    pass

@MetaClass
class ContextualConditionCharacterHealth(ICharacterSubcondition):
    mTargetHealth: float
    mCompareOp: UInt8
    pass

@MetaClass
class ContextualConditionIsAlly(ICharacterSubcondition):
    mIsAlly: bool
    pass

@MetaClass
class ContextualConditionCharacterPlayingEmote(ICharacterSubcondition):
    mEmoteId: UInt8
    pass

@MetaClass
class ContextualConditionCharacterPlayingAnimation(ICharacterSubcondition):
    mAnimationNameHash: Hash
    pass

@MetaClass
class ContextualConditionCharacterDistance(ICharacterSubcondition):
    mDistance: float
    mCompareOp: UInt8
    mDistanceTarget: UInt8
    pass

@MetaClassEmpty
class ContextualConditionCharacterInRangeForSyncedAnimation(ICharacterSubcondition):
    pass

@MetaClass
class ContextualConditionCharacterHasTimeRemainingForAnimation(ICharacterSubcondition):
    mAnimationName: Hash
    mMinRemainingTime: float
    pass

@MetaClassEmpty
class ContextualConditionCharacterIsCastingRecall(ICharacterSubcondition):
    pass

@MetaClass
class ContextualConditionCharacterRole(ICharacterSubcondition):
    mRole: UInt8
    pass

@MetaClass
class ContextualConditionCharacterHasCac(ICharacterSubcondition):
    mCacs: list[Hash]
    pass

@MetaClassEmpty
class IContextualConditionSpell(IContextualCondition):
    pass

@MetaClass
class ContextualConditionSpell(IContextualCondition):
    mSpellSlot: UInt32
    mChildConditions: list[Optional[IContextualConditionSpell]]
    pass

@MetaClass
class ContextualConditionSpellName(IContextualConditionSpell):
    mSpell: Hash
    pass

@MetaClass
class ContextualConditionSpellSlot(IContextualConditionSpell):
    mSpellSlot: UInt32
    pass

@MetaClass
class ContextualConditionSpellLevel(IContextualConditionSpell):
    mSpellLevel: UInt8
    mCompareOp: UInt8
    pass

@MetaClass
class ContextualConditionSpellIsReady(IContextualConditionSpell):
    mSpellIsReady: bool
    pass

@MetaClassEmpty
class IContextualConditionBuff(IContextualCondition):
    pass

@MetaClass
class t_0x0418b95a(IContextualConditionBuff):
    mBuff: Hash
    m_0x11206e1a: UInt8
    pass

@MetaClass
class t_0xb8d75e45(IContextualConditionBuff):
    mBuff: Hash
    m_0x11206e1a: UInt8
    pass

@MetaClass
class ContextualRule(MetaBase):
    mConditionRelationship: UInt32
    mConditions: list[Optional[IContextualCondition]]
    mAudioAction: Optional[ContextualActionPlayAudio]
    mAnimationAction: Optional[ContextualActionPlayAnimation]
    mTriggerEventAction: Optional[ContextualActionTriggerEvent]
    mPriority: Optional[UInt32]
    m_0x68fee3c4: bool
    pass

@MetaClass
class ContextualSituation(MetaBase):
    mRules: list[ContextualRule]
    mChooseRandomValidRule: bool
    mCoolDownTime: float
    pass

@MetaClass
class DamageSourceTemplate(MetaBase):
    Name: str
    DamageProperties: UInt32
    DamageTags: list[str]
    pass

@MetaClass
class DamageSourceSettings(MetaBase):
    DamageTagDefinition: list[str]
    TemplateDefinition: list[DamageSourceTemplate]
    pass

@MetaClass
class DeathTimesScalingPoint(MetaBase):
    mStartTime: UInt32
    mPercentIncrease: float
    pass

@MetaClass
class DeathTimes(MetaBase):
    mTimeDeadPerLevel: list[float]
    mScalingStartTime: UInt32
    mScalingIncrementTime: UInt32
    mScalingPercentIncrease: float
    mScalingPercentCap: float
    mScalingPoints: list[DeathTimesScalingPoint]
    mAllowRespawnMods: bool
    mStartDeathTimerForZombies: bool
    pass

@MetaClass
class AbilityResourceStateColorOptions(MetaBase):
    color: Color
    FadeColor: Color
    pass

@MetaClass
class AbilityResourceStateData(MetaBase):
    DefaultPalette: Optional[AbilityResourceStateColorOptions]
    ColorblindPalette: Optional[AbilityResourceStateColorOptions]
    TextureSuffix: str
    AnimationSuffix: str
    pass

@MetaClass
class AbilityResourceThresholdIndicatorRange(MetaBase):
    RangeStart: float
    RangeEnd: float
    pass

@MetaClass
class AbilityResourceTypeData(MetaBase):
    States: list[AbilityResourceStateData]
    ShowAbilityResource: bool
    ShowRegen: bool
    ThresholdIndicatorRanges: list[AbilityResourceThresholdIndicatorRange]
    pass

@MetaClass
class AbilityResourceTypeConfig(MetaBase):
    Mana: AbilityResourceTypeData
    Energy: AbilityResourceTypeData
    none: AbilityResourceTypeData
    Shield: AbilityResourceTypeData
    BattleFury: AbilityResourceTypeData
    DragonFury: AbilityResourceTypeData
    Rage: AbilityResourceTypeData
    Heat: AbilityResourceTypeData
    PrimalFury: AbilityResourceTypeData
    Ferocity: AbilityResourceTypeData
    Bloodwell: AbilityResourceTypeData
    Wind: AbilityResourceTypeData
    Ammo: AbilityResourceTypeData
    Moonlight: AbilityResourceTypeData
    Other: AbilityResourceTypeData
    pass

@MetaClass
class EvolutionDescription(MetaBase):
    mFlags: UInt32
    mTitle: str
    mTooltips: list[str]
    mIconNames: list[str]
    pass

@MetaClass
class ExperienceCurveData(MetaBase):
    mExperienceRequiredPerLevel: list[float]
    mExperienceGrantedForKillPerLevel: list[float]
    m_0x9980fa2e: list[float]
    mBaseExperienceMultiplier: float
    mLevelDifferenceExperienceMultiplier: float
    mMinimumExperienceMultiplier: float
    pass

@MetaClass
class ExperienceModData(MetaBase):
    mPlayerMinionSplitXp: list[float]
    pass

@MetaClass
class StatUiData(MetaBase):
    mName: str
    mAbbreviation: str
    mDisplayType: UInt8
    mIconKey: str
    mScalingTagKey: str
    pass

@MetaClass
class GlobalStatsUiData(MetaBase):
    mStatUiData: dict[UInt8, StatUiData]
    BaseOutputIconModifier: str
    BonusOutputIconModifier: str
    mNumberStyle: str
    mNumberStylePercent: str
    mNumberStyleBonus: str
    mNumberStyleBonusPercent: str
    FormulaPartStyleBonus: str
    FormulaPartStyleBonusPercent: str
    FormulaPartStyle: str
    FormulaPartStylePercent: str
    FormulaPartRangeStyleBonus: str
    FormulaPartRangeStyleBonusPercent: str
    FormulaPartRangeStyle: str
    FormulaPartRangeStylePercent: str
    mNumberStyleTotalAndCoefficient: str
    mNumberStyleTotalAndCoefficientPercent: str
    NumberStyleTotalAndScalingIcons: str
    NumberStyleTotalAndFormula: str
    mManaIconKey: str
    mManaScalingTagKey: str
    m_0x2fa6c4b0: str
    m_0x4ac09eef: str
    m_0xf04c21cd: UInt8
    m_0xa844caca: UInt8
    m_0x97343c80: UInt8
    pass

@MetaClass
class CameraTrapezoid(MetaBase):
    m_0x9811eb50: float
    m_0x82cb6669: float
    mMaxXTop: float
    mMaxXBottom: float
    pass

@MetaClass
class CameraConfig(MetaBase):
    m_0x0671c887: CameraTrapezoid
    mAccelerationTimeMouse: float
    mDecelerationTimeMouse: float
    mAccelerationTimeKeyboard: float
    mDecelerationTimeKeyboard: float
    mTopdownZoom: float
    mZoomMinDistance: float
    mZoomMaxDistance: float
    mZoomEaseTime: float
    mZoomMinSpeed: float
    mLockedCameraEasingDistance: float
    mDragScale: float
    mDragMomentumDecay: float
    mDragMomentumRecencyWeight: float
    mTransitionDurationIntoCinematicMode: float
    m_0x71c9323a: CameraTrapezoid
    m_0xf7617555: CameraTrapezoid
    m_0x383f51a8: float
    pass

@MetaClass
class MapAudioDataProperties(MetaBase):
    BaseData: Link[MapAudioDataProperties]
    BankUnits: list[BankUnit]
    Features: list[Link[FeatureAudioDataProperties]]
    pass

@MetaClass
class ClientStateAudioDataProperties(MetaBase):
    BankPaths: list[str]
    ThemeMusic: str
    pass

@MetaClass
class FeatureAudioDataProperties(MetaBase):
    BankUnits: list[BankUnit]
    Music: MusicAudioDataProperties
    Feature: Hash
    pass

@MetaClass
class BankUnit(MetaBase):
    Name: str
    BankPath: list[str]
    Events: list[str]
    Asynchrone: bool
    VoiceOver: bool
    pass

@MetaClass
class AudioTagListProperties(MetaBase):
    Tags: list[str]
    Key: str
    pass

@MetaClass
class AudioSystemDataProperties(MetaBase):
    SystemTagEventList: list[AudioTagListProperties]
    pass

@MetaClass
class AudioStatusEvents(MetaBase):
    RtpcName: str
    StartEvent: str
    StopEvent: str
    pass

@MetaClass
class GlobalAudioDataProperties(MetaBase):
    Systems: dict[Hash, Link[AudioSystemDataProperties]]
    CooldownVoiceOver: float
    LocalPlayerStatusEvents: dict[UInt8, AudioStatusEvents]
    m_0x103e4044: UInt32
    pass

@MetaClass
class MusicAudioDataProperties(MetaBase):
    ThemeMusicId: str
    ThemeMusicTransitionId: str
    LegacyThemeMusicId: str
    LegacyThemeMusicTransitionId: str
    VictoryMusicId: str
    DefeatMusicId: str
    VictoryBannerSound: str
    DefeatBannerSound: str
    AmbientEvent: str
    ReverbPreset: str
    GameStartEvent: str
    GameQuitEvent: str
    pass

@MetaClass
class EvoSettings(MetaBase):
    mEnableChatVo: bool
    mEnableAnnouncerVoReplacement: bool
    mChatVoThrottleCounterThreshold: Int32
    mChatVoThrottleCounterDecayTime: float
    mPingVoThrottleThreshold: float
    pass

@MetaClassEmpty
class ICatalogEntryOwner(MetaBase):
    pass

@MetaClass
class CatalogEntry(MetaBase):
    ContentId: str
    ItemId: UInt32
    OfferId: str
    pass

@MetaClass
class CensoredImage(MetaBase):
    Image: str
    UncensoredImages: dict[Hash, str]
    pass

@MetaClassEmpty
class WadFileDescriptor(MetaBase):
    pass

@MetaClass
class Champion(WadFileDescriptor):
    Name: str
    StatStoneSets: list[Hash]
    mChampionItemRecommendations: ChampionItemRecommendations
    AdditionalCharacters: list[Link[Character]]
    FixedLoadScreenPosition: Int8
    m_0xc7d8a053: UInt32
    pass

@MetaClass
class Character(MetaBase):
    Name: str
    pass

@MetaClass
class SkinCharacterDataProperties_CharacterIdleEffect(MetaBase):
    EffectKey: Hash
    EffectName: str
    Position: Vec3
    BoneName: str
    TargetBoneName: str
    pass

@MetaClass
class SkinCharacterMetaDataProperties_SpawningSkinOffset(MetaBase):
    Tag: str
    Offset: Int32
    pass

@MetaClass
class EsportTeamEntry(MetaBase):
    TeamName: str
    LeagueName: str
    TextureName: str
    pass

@MetaClass
class EsportLeagueEntry(MetaBase):
    LeagueName: str
    TextureName: str
    pass

@MetaClass
class SkinCharacterMetaDataProperties(MetaBase):
    EsportCharacter: bool
    EsportTeamTable: list[EsportTeamEntry]
    EsportLeagueTable: list[EsportLeagueEntry]
    SkinBasedRelativeColorScheme: bool
    RelativeColorSwapTable: list[Int32]
    SpawningSkinOffsets: list[SkinCharacterMetaDataProperties_SpawningSkinOffset]
    UseGdsBinaries: bool
    pass

@MetaClass
class SkinAudioProperties(MetaBase):
    TagEventList: list[str]
    BankUnits: list[BankUnit]
    pass

@MetaClass
class SkinAnimationProperties(MetaBase):
    AnimationGraphData: Link[AnimationGraphData]
    pass

@MetaClass
class SkinEmblem(MetaBase):
    mEmblemData: Link[EmblemData]
    mLoadingScreenAnchor: UInt32
    pass

@MetaClass
class SkinSummonerEmoteLoadout(MetaBase):
    mEmotes: list[Link[SummonerEmote]]
    pass

@MetaClass
class SkinCharacterDataProperties(MetaBase):
    SkinClassification: UInt32
    ChampionSkinName: str
    AttributeFlags: UInt32
    SkinParent: Int32
    MetaDataTags: str
    EmoteLoadout: Hash
    SkinUpgradeData: SkinUpgradeData
    EndOfGameAlias: str
    m_0x4678b8f7: str
    Loadscreen: CensoredImage
    LoadscreenVintage: CensoredImage
    SkinAudioProperties: SkinAudioProperties
    SkinAnimationProperties: SkinAnimationProperties
    SkinMeshProperties: SkinMeshDataProperties
    ArmorMaterial: str
    ThemeMusic: list[str]
    m_0x0592970c: bool
    HudMuteEvent: str
    HudUnmuteEvent: str
    DefaultAnimations: list[str]
    IdleParticlesEffects: list[SkinCharacterDataProperties_CharacterIdleEffect]
    ParticleOverride_ChampionKillDeathParticle: str
    ParticleOverride_DeathParticle: str
    mSpawnParticleName: str
    ExtraCharacterPreloads: list[str]
    HealthBarData: CharacterHealthBarDataRecord
    mEmblems: list[SkinEmblem]
    VoiceOverOverride: str
    SkipVoOverride: bool
    IconAvatar: str
    IconCircleScale: Optional[float]
    IconCircle: Optional[str]
    IconSquare: Optional[str]
    AlternateIconsCircle: list[str]
    AlternateIconsSquare: list[str]
    UncensoredIconCircles: dict[Hash, str]
    UncensoredIconSquares: dict[Hash, str]
    SecondaryResourceHudDisplayData: Optional[ISecondaryResourceDisplayData]
    mContextualActionData: Link[ContextualActionData]
    EmoteBuffbone: str
    EmoteYOffset: float
    GodrayFxBone: str
    mResourceResolver: Link[ResourceResolver]
    mAdditionalResourceResolvers: list[Link[ResourceResolver]]
    mOptionalBin: HudOptionalBinData
    m_0x25f9aa72: UInt32
    pass

@MetaClass
class SkinFilterData(MetaBase):
    FilterType: UInt32
    m_0xc176d167: bool
    SkinIds: list[UInt32]
    pass

@MetaClass
class CharacterPassiveData(MetaBase):
    m_0xbd3c31e4: Link[SpellObject]
    mComponentBuffs: list[Link[SpellObject]]
    mChildSpells: list[Link[SpellObject]]
    mDisplayFlags: UInt8
    SkinFilter: Optional[SkinFilterData]
    m_0x6346a946: bool
    pass

@MetaClass
class GlobalPerLevelStatsFactor(MetaBase):
    mPerLevelStatsFactor: list[float]
    pass

@MetaClass
class OverrideAutoAttackCastTimeData(MetaBase):
    mOverrideAutoattackCastTimeCalculation: Optional[IGameCalculation]
    pass

@MetaClass
class CharacterRecord(MetaBase):
    mCharacterName: str
    mFallbackCharacterName: str
    Flags: UInt32
    MinionFlags: UInt32
    AssetCategory: str
    PurchaseIdentities: list[Hash]
    mClientSideItemInventory: list[Hash]
    mPreferredPerkStyle: Link[PerkStyle]
    mPerkReplacements: PerkReplacementList
    BaseHp: float
    HpPerLevel: float
    BaseStaticHpRegen: float
    BaseFactorHpRegen: float
    HpRegenPerLevel: float
    HealthBarHeight: float
    HealthBarFullParallax: bool
    SelfChampSpecificHealthSuffix: str
    SelfCbChampSpecificHealthSuffix: str
    AllyChampSpecificHealthSuffix: str
    EnemyChampSpecificHealthSuffix: str
    HighlightHealthbarIcons: bool
    PrimaryAbilityResource: AbilityResourceSlotInfo
    SecondaryAbilityResource: AbilityResourceSlotInfo
    BaseDamage: float
    DamagePerLevel: float
    BaseArmor: float
    ArmorPerLevel: float
    BaseSpellBlock: float
    SpellBlockPerLevel: float
    BaseDodge: float
    DodgePerLevel: float
    BaseMissChance: float
    BaseCritChance: float
    CritPerLevel: float
    CritDamageMultiplier: float
    BaseMoveSpeed: float
    m_0xcb4451d3: float
    AttackRange: float
    AttackSpeed: float
    AttackSpeedRatio: float
    AttackSpeedPerLevel: float
    AbilityPowerIncPerLevel: float
    mAdaptiveForceToAbilityPowerWeight: float
    BasicAttack: AttackSlotData
    ExtraAttacks: list[AttackSlotData]
    CritAttacks: list[AttackSlotData]
    AcquisitionRange: float
    WakeUpRange: Optional[float]
    FirstAcquisitionRange: Optional[float]
    AttackAutoInterruptPercent: float
    TowerTargetingPriorityBoost: float
    GoldGivenOnDeath: float
    ExpGivenOnDeath: float
    GoldRadius: float
    ExperienceRadius: float
    DeathEventListeningRadius: float
    LocalGoldGivenOnDeath: float
    LocalExpGivenOnDeath: float
    LocalGoldSplitWithLastHitter: bool
    GlobalGoldGivenOnDeath: float
    GlobalExpGivenOnDeath: float
    PerceptionBubbleRadius: Optional[float]
    PerceptionBoundingBoxSize: Optional[Vec3]
    Significance: float
    UntargetableSpawnTime: float
    AbilityPower: float
    DeathTime: float
    OccludedUnitSelectableDistance: float
    CriticalAttack: str
    PassiveName: str
    PassiveLuaName: str
    PassiveToolTip: str
    PassiveSpell: str
    PassiveRange: float
    Passive1IconName: str
    HitFxScale: float
    SelectionHeight: float
    SelectionRadius: float
    PathfindingCollisionRadius: float
    OverrideGameplayCollisionRadius: Optional[float]
    SpellLevelUpInfo: list[SpellLevelUpInfo]
    RecSpellRankUpInfo: list[RecSpellRankUpInfo]
    ParName: str
    FriendlyTooltip: str
    EnemyTooltip: str
    Name: str
    OutlineBboxExpansion: float
    mUseCcAnimations: bool
    JointForAnimAdjustedSelection: str
    WeaponMaterials: list[str]
    CharAudioNameOverride: str
    MinimapIconOverride: str
    HoverIndicatorTextureName: str
    HoverLineIndicatorBaseTextureName: str
    HoverLineIndicatorTargetTextureName: str
    HoverLineIndicatorWidth: float
    HoverIndicatorRadius: float
    HoverLineIndicatorWidthMinimap: float
    HoverIndicatorRadiusMinimap: float
    HoverIndicatorRotateToPlayer: bool
    HoverIndicatorMinimapOverride: str
    AreaIndicatorRadius: float
    AreaIndicatorMinRadius: float
    AreaIndicatorMaxDistance: float
    AreaIndicatorTargetDistance: float
    AreaIndicatorMinDistance: float
    AreaIndicatorTextureSize: float
    AreaIndicatorTextureName: str
    SilhouetteAttachmentAnim: str
    TargetLaserEffects: Optional[TargetLaserComponentEffects]
    DisabledTargetLaserEffects: Optional[TargetLaserComponentEffects]
    EvolutionData: Optional[EvolutionDescription]
    UseableData: UseableData
    RecordAsWard: bool
    MinionScoreValue: float
    UseRiotRelationships: bool
    UnitTagsString: str
    FriendlyUxOverrideTeam: UInt32
    FriendlyUxOverrideIncludeTagsString: str
    FriendlyUxOverrideExcludeTagsString: str
    mEducationToolData: ToolEducationData
    mAbilitySlotCc: list[Int32]
    CharacterToolData: CharacterToolData
    PlatformEnabled: bool
    MovingTowardEnemyActivationAngle: float
    mAbilities: list[Link[AbilityObject]]
    OnKillEvent: UInt32
    OnKillEventSteal: UInt32
    OnKillEventForSpectator: UInt32
    mCharacterCalculations: dict[Hash, Optional[IGameCalculation]]
    mCharacterPassiveSpell: Link[SpellObject]
    mCharacterPassiveBuffs: list[CharacterPassiveData]
    SpellNames: list[str]
    ExtraSpells: list[str]
    mDefaultStatOverrides: StatFormulaDataList
    pass

@MetaClass
class AbilityResourceSlotInfo(MetaBase):
    ArType: UInt8
    ArBase: float
    ArPerLevel: float
    ArBaseStaticRegen: float
    ArBaseFactorRegen: float
    ArRegenPerLevel: float
    ArIncrements: float
    ArMaxSegments: Int32
    ArHasRegenText: bool
    ArAllowMaxValueToBeOverridden: bool
    ArContributesToHealthValues: bool
    ArPreventRegenWhileAtZero: bool
    ArDisplayAsPips: bool
    ArIsShown: bool
    ArIsShownOnlyOnLocalPlayer: bool
    ArOverrideSmallPipName: str
    arOverrideMediumPipName: str
    ArOverrideLargePipName: str
    ArOverrideEmptyPipName: str
    ArOverrideSpacerName: str
    ArNegativeSpacer: bool
    m_0xa9d3a87c: bool
    m_0x5ca738c0: bool
    pass

@MetaClass
class AttackSlotData(MetaBase):
    mAttackTotalTime: Optional[float]
    mAttackCastTime: Optional[float]
    mAttackDelayCastOffsetPercent: Optional[float]
    mAttackDelayCastOffsetPercentAttackSpeedRatio: Optional[float]
    mAttackProbability: Optional[float]
    mAttackName: Optional[str]
    mOverrideAutoattackCastTime: Optional[OverrideAutoAttackCastTimeData]
    pass

@MetaClass
class TargetLaserComponentEffects(MetaBase):
    BeamEffectDefinition: SkinCharacterDataProperties_CharacterIdleEffect
    TowerTargetingEffectDefinition: SkinCharacterDataProperties_CharacterIdleEffect
    ChampTargetingEffectDefinition: SkinCharacterDataProperties_CharacterIdleEffect
    pass

@MetaClass
class ToolEducationData(MetaBase):
    FirstItem: Int32
    SkillOrder: Int32
    pass

@MetaClass
class CharacterToolData(MetaBase):
    SearchTags: str
    SearchTagsSecondary: str
    pass

@MetaClassEmpty
class Companion(Character):
    pass

@MetaClass
class InteractionData(MetaBase):
    IdleAnim: str
    ShouldRandomizeIdleAnimPhase: bool
    pass

@MetaClassEmpty
class ISpellRankUpRequirement(MetaBase):
    pass

@MetaClassEmpty
class HasSkillPointRequirement(ISpellRankUpRequirement):
    pass

@MetaClass
class CharacterLevelRequirement(ISpellRankUpRequirement):
    mLevel: UInt32
    pass

@MetaClass
class HasBuffRequirement(ISpellRankUpRequirement):
    mBuffName: Hash
    mFromAnyone: bool
    pass

@MetaClass
class SpellRankUpRequirements(MetaBase):
    mRequirements: list[Optional[ISpellRankUpRequirement]]
    pass

@MetaClass
class SpellLevelUpInfo(MetaBase):
    mRequirements: list[SpellRankUpRequirements]
    pass

@MetaClass
class RecSpellRankUpInfo(MetaBase):
    mDefaultPriority: list[UInt8]
    mEarlyLevelOverrides: list[UInt8]
    pass

@MetaClass
class UseableData(MetaBase):
    Flags: UInt32
    UseHeroSpellName: str
    UseSpellName: str
    UseCooldownSpellSlot: Int32
    pass

@MetaClass
class CharacterHealthBarDataRecord(MetaBase):
    HpPerTick: float
    AttachToBone: str
    UnitHealthBarStyle: UInt8
    ShowWhileUntargetable: bool
    m_0x9c5124c0: bool
    m_0xe784dd2f: UInt32
    m_0x66a7d70a: bool
    m_0x8bdcfa04: bool
    m_0x7f0b706e: bool
    pass

@MetaClass
class SponsoredBanner(MetaBase):
    Banner: Link[EsportsBannerData]
    SponsorTexturePath: File
    pass

@MetaClass
class EsportsBannerConfiguration(MetaBase):
    Name: str
    IndividualBannerOverrides: list[SponsoredBanner]
    EsportsTeam: Hash
    EventMutator: Link[GameMutatorExpansions]
    LeagueName: str
    TexturePath: File
    pass

@MetaClass
class EsportsBannerData(MetaBase):
    BannerName: str
    Team: UInt32
    pass

@MetaClass
class EsportsData(MetaBase):
    Leagues: list[str]
    pass

@MetaClass
class ClashLogo(MetaBase):
    mClashLogoId: UInt32
    mClashLogoColorId: UInt32
    mLogoPath: str
    pass

@MetaClass
class EsportsBannerOptions(MetaBase):
    SubMeshName: str
    DefaultTexturePath: File
    IsSpectatorOnly: bool
    DefaultBlankMaterial: Link[IMaterialDef]
    pass

@MetaClass
class MasteryBadgeData(MetaBase):
    mName: Hash
    mParticleName: str
    mRenderScale: float
    mVerticalOffset: float
    mSummonerIconId: Int32
    mMasteryLevel: UInt32
    pass

@MetaClass
class MasteryBadgeConfig(MetaBase):
    mBadges: list[MasteryBadgeData]
    pass

@MetaClass
class MasteryData(MetaBase):
    Texture: str
    LevelTraKey: str
    DetailsTraKey: str
    pass

@MetaClass
class ChampionMasteryMap(MetaBase):
    MasteryData: dict[Int32, Link[MasteryData]]
    pass

@MetaClass
class BaseLoadoutData(ICatalogEntryOwner):
    CatalogEntry: CatalogEntry
    mNameTraKey: str
    mDescriptionTraKey: str
    pass

@MetaClass
class LoadoutFeatureData(MetaBase):
    mFeature: UInt32
    mMutator: Optional[str]
    mBinaryFile: Optional[str]
    mLoadoutCategory: str
    mLoadoutProperties: list[str]
    mGdsObjectPathTemplates: dict[str, str]
    mLoadFromContentIds: bool
    pass

@MetaClass
class RecallDecalData(MetaBase):
    EffectFile: str
    ArrivalEffectFile: str
    EmpoweredEffectFile: str
    EmpoweredArrivalFile: str
    RecallDecalId: UInt32
    pass

@MetaClass
class GearSkinUpgrade(MetaBase):
    mGearData: Optional[GearData]
    m_0x358d080b: str
    pass

@MetaClass
class SkinUpgradeData(MetaBase):
    mGearSkinUpgrades: list[Link[GearSkinUpgrade]]
    pass

@MetaClass
class TftCompanionBucket(MetaBase):
    Companions: list[Hash]
    pass

@MetaClass
class TftBotLoadoutConfiguration(MetaBase):
    m_0xeffbc65c: list[TftCompanionBucket]
    MapSkins: list[Hash]
    pass

@MetaClass
class BannerFlagData(MetaBase):
    SkinMeshProperties: SkinMeshDataProperties
    AnimationGraphData: Link[AnimationGraphData]
    pass

@MetaClass
class BannerFrameData(MetaBase):
    AnimationGraphData: Link[AnimationGraphData]
    SkinMeshProperties: SkinMeshDataProperties
    pass

@MetaClass
class CompanionData(BaseLoadoutData):
    Rarity: UInt32
    mCharacter: Hash
    mSkinId: UInt32
    Level: UInt32
    mDisabled: bool
    SpeciesLink: str
    mStandaloneCircleIcon: str
    mStandaloneLoadoutsIcon: str
    mStandaloneLoadoutsLargeIcon: str
    mLoadScreen: str
    pass

@MetaClass
class CompanionSpeciesData(MetaBase):
    mSpeciesName: str
    mSpeciesId: UInt32
    pass

@MetaClass
class SummonerEmote(MetaBase):
    SummonerEmoteId: UInt32
    VfxSystem: Link[VfxSystemDefinitionData]
    AnnouncementIcon: str
    SelectionIcon: str
    RenderScale: float
    VerticalOffset: float
    VisibleSelectionName: str
    pass

@MetaClass
class SummonerEmoteSettings(MetaBase):
    mFirstBlood: Link[SummonerEmote]
    mAce: Link[SummonerEmote]
    pass

@MetaClass
class GearData(MetaBase):
    SkinMeshProperties: SkinMeshDataProperties
    AnimationGraphData: Link[AnimationGraphData]
    mVfxResourceResolver: Optional[ResourceResolver]
    mEquipAnimation: str
    mSelfOnlyPortraitIcon: str
    mPortraitIcon: str
    m_0xb6c044fb: list[Hash]
    m_0x21b6167e: list[Hash]
    pass

@MetaClass
class ModeProgressionRewardData(BaseLoadoutData):
    mBuffName: str
    mCharacters: list[str]
    mVfxResourceResolver: Optional[ResourceResolver]
    pass

@MetaClass
class RegaliaData(BaseLoadoutData):
    Texture: str
    pass

@MetaClass
class RegaliaLookup(MetaBase):
    Tier: str
    RegaliaCrest: Link[RegaliaData]
    RegaliaCrown1: Link[RegaliaData]
    RegaliaCrown2: Link[RegaliaData]
    RegaliaCrown3: Link[RegaliaData]
    RegaliaCrown4: Link[RegaliaData]
    RegaliaTrim: Link[RegaliaData]
    RegaliaSplit1: Link[RegaliaData]
    RegaliaSplit2: Link[RegaliaData]
    RegaliaSplit3: Link[RegaliaData]
    pass

@MetaClass
class RegaliaRankedCrestEntry(MetaBase):
    Base: Link[RegaliaData]
    m_0xfbb20410: dict[Int32, Link[RegaliaData]]
    m_0xaf2e170a: dict[Int32, Link[RegaliaData]]
    pass

@MetaClass
class RegaliaRankedCrestMap(MetaBase):
    m_0x723d6f91: dict[str, RegaliaRankedCrestEntry]
    pass

@MetaClass
class RegaliaPrestigeCrestList(MetaBase):
    PrestigeCrests: list[Link[RegaliaData]]
    pass

@MetaClass
class RegaliaRankedBannerMap(MetaBase):
    m_0xc5b8b568: dict[str, Link[RegaliaData]]
    pass

@MetaClass
class t_0x2ba8fc33(MetaBase):
    m_0x5b1fd3c2: dict[str, RegaliaData]
    pass

@MetaClass
class StatStoneEventToTrack(MetaBase):
    EventToTrack: UInt32
    StatFilters: list[Optional[IStatStoneLogicDriver]]
    pass

@MetaClass
class StatStoneData(BaseLoadoutData):
    EventsToTrack: list[StatStoneEventToTrack]
    Category: Link[StatStoneCategory]
    m_0xfb2a56ef: UInt32
    m_0x286fc9c3: UInt32
    Milestones: list[UInt64]
    EpicStatStone: bool
    TriggeredFromScript: bool
    IsRetired: bool
    TrackingType: UInt8
    StoneName: str
    m_0x92bd18ab: bool
    pass

@MetaClassEmpty
class IStatStoneLogicDriver(MetaBase):
    pass

@MetaClass
class TargetHasUnitTagFilter(IStatStoneLogicDriver):
    UnitTags: ObjectTags
    pass

@MetaClassEmpty
class TrueDamageGivenFilter(IStatStoneLogicDriver):
    pass

@MetaClass
class CrowdControlFilter(IStatStoneLogicDriver):
    m_0x20cf84ac: list[UInt8]
    TrackDuration: bool
    pass

@MetaClass
class TargetHasBuffFilter(IStatStoneLogicDriver):
    ValidBuffs: list[UInt8]
    pass

@MetaClass
class SourceTypeFilter(IStatStoneLogicDriver):
    m_0x47bac313: bool
    m_0x1e3fcd64: bool
    m_0xd5e57340: bool
    pass

@MetaClass
class TargetTypeFilter(IStatStoneLogicDriver):
    m_0x47bac313: bool
    m_0x1e3fcd64: bool
    m_0xd5e57340: bool
    pass

@MetaClass
class TargetTeamFilter(IStatStoneLogicDriver):
    Ally: bool
    Enemy: bool
    Self: bool
    pass

@MetaClass
class SourceLessThanHealthPercentageFilter(IStatStoneLogicDriver):
    HealthPercentage: float
    pass

@MetaClass
class AssistCountFilter(IStatStoneLogicDriver):
    AssistCount: UInt8
    pass

@MetaClassEmpty
class MultiKillLogic(IStatStoneLogicDriver):
    pass

@MetaClass
class DamageShieldedLogic(IStatStoneLogicDriver):
    m_0xa1e033be: bool
    m_0x7944553a: bool
    m_0x2ad527a6: bool
    m_0x621e14db: bool
    m_0x60b7c1b6: bool
    m_0xcbc2f8ba: bool
    m_0x2efb9d27: bool
    m_0x1701ca0a: bool
    pass

@MetaClass
class GoldSourceFilter(IStatStoneLogicDriver):
    ValidGoldSource: UInt8
    pass

@MetaClass
class KillingSpreeFilter(IStatStoneLogicDriver):
    KillingSpreeCount: Int32
    pass

@MetaClassEmpty
class NeutralMinionCampClearedLogic(IStatStoneLogicDriver):
    pass

@MetaClassEmpty
class TurretFirstBloodLogic(IStatStoneLogicDriver):
    pass

@MetaClass
class StatStoneSet(ICatalogEntryOwner):
    Name: str
    CatalogEntry: CatalogEntry
    StatStones: list[Link[StatStoneData]]
    pass

@MetaClass
class StatStoneCategory(MetaBase):
    GameIconUnlit: str
    GameIconLit: str
    GameIconFull: str
    GameIconMini: str
    CategoryColor: Color
    pass

@MetaClass
class t_0xead1b379(MetaBase):
    m_0xfb403eda: dict[UInt32, Link[VfxSystemDefinitionData]]
    pass

@MetaClass
class t_0x32be2466(MetaBase):
    m_0x1a28d722: dict[UInt32, Link[t_0xead1b379]]
    pass

@MetaClass
class TftDamageSkin(BaseLoadoutData):
    StandaloneLoadoutsIcon: str
    StandaloneLoadoutsLargeIcon: str
    VfxResourceResolver: Link[ResourceResolver]
    AudioBankPaths: list[str]
    mName: str
    Rarity: UInt32
    DamageBuffName: str
    SkinId: UInt32
    Level: UInt32
    Disabled: bool
    m_0x7ed5b4a7: float
    m_0x31af5dc6: list[TftDamageSkinDescriptor]
    pass

@MetaClass
class TftDamageSkinDescriptor(MetaBase):
    EffectType: UInt32
    EffectKey: str
    AttachedToBone: UInt32
    EffectDelay: float
    m_0x9d0cca5b: UInt32
    pass

@MetaClass
class TftMapGroupData(MetaBase):
    mName: str
    mId: UInt32
    pass

@MetaClass
class TftMapSkin(BaseLoadoutData):
    StandaloneLoadoutsIcon: str
    StandaloneLoadoutsLargeIcon: str
    GroupLink: str
    Rarity: UInt32
    AudioBankPaths: list[str]
    Characters: list[Hash]
    MapContainer: str
    m_0xafc467eb: UInt16
    m_0x6e39b04a: UInt16
    pass

@MetaClass
class TrophyData(BaseLoadoutData):
    mPerceptionBubbleRadius: float
    SkinMeshProperties: SkinMeshDataProperties
    AnimationGraphData: Link[AnimationGraphData]
    mVfxResourceResolver: Optional[ResourceResolver]
    mBracketTraKey: str
    pass

@MetaClass
class TrophyPedestalData(BaseLoadoutData):
    mJointName: str
    SkinMeshProperties: SkinMeshDataProperties
    AnimationGraphData: Link[AnimationGraphData]
    mTierTraKey: str
    pass

@MetaClassEmpty
class t_0x1650a4ce(MetaBase):
    pass

@MetaClassEmpty
class IDynamicMaterialDriver(MetaBase):
    pass

@MetaClassEmpty
class IDynamicMaterialFloatDriver(IDynamicMaterialDriver):
    pass

@MetaClass
class AbilityResourceDynamicMaterialFloatDriver(IDynamicMaterialFloatDriver):
    Slot: UInt8
    pass

@MetaClass
class AnimationFractionDynamicMaterialFloatDriver(IDynamicMaterialFloatDriver):
    mAnimationName: Hash
    pass

@MetaClass
class BuffCounterDynamicMaterialFloatDriver(IDynamicMaterialFloatDriver):
    mScriptName: str
    pass

@MetaClass
class DistanceToPlayerMaterialFloatDriver(IDynamicMaterialFloatDriver):
    MinDistance: float
    MaxDistance: float
    pass

@MetaClassEmpty
class IDynamicMaterialBoolDriver(IDynamicMaterialFloatDriver):
    pass

@MetaClass
class t_0x9bd21f30(IDynamicMaterialBoolDriver):
    mKeyName: str
    pass

@MetaClass
class t_0x1e6c47fe(IDynamicMaterialFloatDriver):
    mKeyName: str
    pass

@MetaClass
class t_0xd0116dc8(IDynamicMaterialBoolDriver):
    mKeyName: str
    pass

@MetaClass
class t_0xe856a498(IDynamicMaterialFloatDriver):
    mKeyName: str
    pass

@MetaClass
class HasBuffDynamicMaterialBoolDriver(IDynamicMaterialBoolDriver):
    mScriptName: str
    m_0xff80df7a: float
    pass

@MetaClass
class HasGearDynamicMaterialBoolDriver(IDynamicMaterialBoolDriver):
    mGearIndex: UInt8
    pass

@MetaClassEmpty
class HealthDynamicMaterialFloatDriver(IDynamicMaterialFloatDriver):
    pass

@MetaClass
class IsAnimationPlayingDynamicMaterialBoolDriver(IDynamicMaterialBoolDriver):
    mAnimationNames: list[Hash]
    pass

@MetaClassEmpty
class IsDeadDynamicMaterialBoolDriver(IDynamicMaterialBoolDriver):
    pass

@MetaClassEmpty
class IsEnemyDynamicMaterialBoolDriver(IDynamicMaterialBoolDriver):
    pass

@MetaClassEmpty
class IsInGrassDynamicMaterialBoolDriver(IDynamicMaterialBoolDriver):
    pass

@MetaClassEmpty
class t_0x0c953d7f(IDynamicMaterialBoolDriver):
    pass

@MetaClass
class LearnedSpellDynamicMaterialBoolDriver(IDynamicMaterialBoolDriver):
    mSlot: UInt8
    pass

@MetaClassEmpty
class t_0x1fbea063(IDynamicMaterialDriver):
    pass

@MetaClass
class UvScaleBiasFromAnimationDynamicMaterialDriver(IDynamicMaterialDriver):
    mSubMeshName: str
    m_0xdbad132e: UInt32
    pass

@MetaClassEmpty
class VelocityDynamicMaterialFloatDriver(IDynamicMaterialFloatDriver):
    pass

@MetaClassEmpty
class ParticleWadFileDescriptor(WadFileDescriptor):
    pass

@MetaClass
class EmblemPosition(MetaBase):
    mVertical: str
    mHorizontal: str
    pass

@MetaClass
class EmblemData(MetaBase):
    mShowOnLoadingScreen: bool
    mLoadingScreenScale: float
    mImagePath: str
    pass

@MetaClass
class EmblemSettings(MetaBase):
    mBottomFraction: float
    mDebugDrawEmblems: bool
    pass

@MetaClass
class GameModeAutoItemPurchasingConfig(MetaBase):
    m_0x19ef67a2: Int32
    m_0xe34f62d0: list[str]
    m_0xc8adfdbc: list[str]
    m_0x83f0cccd: list[str]
    m_0x14596d09: Hash
    pass

@MetaClass
class GameModeChampionList(MetaBase):
    mChampions: list[Hash]
    pass

@MetaClassEmpty
class GameModeConstant(MetaBase):
    pass

@MetaClass
class GameModeConstantFloat(GameModeConstant):
    mValue: float
    pass

@MetaClass
class GameModeConstantInteger(GameModeConstant):
    mValue: Int32
    pass

@MetaClass
class GameModeConstantBool(GameModeConstant):
    mValue: bool
    pass

@MetaClass
class GameModeConstantString(GameModeConstant):
    mValue: str
    pass

@MetaClass
class GameModeConstantStringVector(GameModeConstant):
    mValue: list[str]
    pass

@MetaClass
class GameModeConstantTraKey(GameModeConstant):
    mValue: str
    pass

@MetaClass
class GameModeConstantVector3f(GameModeConstant):
    mValue: Vec3
    pass

@MetaClass
class GameModeConstantFloatPerLevel(GameModeConstant):
    mValues: list[float]
    pass

@MetaClass
class GameModeConstantsGroup(MetaBase):
    mConstants: dict[Hash, Optional[GameModeConstant]]
    pass

@MetaClass
class GameModeConstants(MetaBase):
    mGroups: dict[Hash, GameModeConstantsGroup]
    pass

@MetaClass
class GameModeItemList(MetaBase):
    mItems: list[Hash]
    pass

@MetaClass
class GameModeMapData(MetaBase):
    mModeName: Hash
    mChampionLists: list[Link[GameModeChampionList]]
    ItemLists: list[Link[GameModeItemList]]
    mItemShopData: Link[ItemShopGameModeData]
    mRelativeColorization: bool
    AnnouncementsMapping: Link[AnnouncementMap]
    mNeutralTimersDisplay: Link[NeutralTimers]
    mCursorConfig: Hash
    mCursorConfigUpdate: Hash
    m_0x70b29c3d: list[Link[IHudLoadingScreenWidget]]
    mLoadingScreenBackground: str
    mHudScoreData: Hash
    mRenderStyle: Link[RenderStyleData]
    mFloatingTextOverride: Link[FloatingTextOverride]
    mStatsUiData: Link[GlobalStatsUiData]
    m_0x8bd9f7d8: list[Link[t_0x15502626]]
    mChampionIndicatorEnabled: bool
    ItemShopEnabled: bool
    mExperienceCurveData: Link[ExperienceCurveData]
    mExperienceModData: Link[ExperienceModData]
    mDeathTimes: Link[DeathTimes]
    mLoadScreenTipConfiguration: Link[LoadScreenTipConfiguration]
    mMapLocators: Link[MapLocatorArray]
    mPerkReplacements: PerkReplacementList
    mMissionBuffData: Link[MissionBuffData]
    mSurrenderSettings: Link[SurrenderData]
    m_0x6941e612: Link[GameModeAutoItemPurchasingConfig]
    m_0x882a6450: bool
    mScriptDataObjectLists: list[Link[ScriptDataObjectList]]
    mGameModeConstants: Link[GameModeConstants]
    mGameplayConfig: Link[GameplayConfig]
    m_0xf74c67bb: str
    pass

@MetaClass
class t_0x15502626(MetaBase):
    Spells: list[Hash]
    pass

@MetaClass
class GameMutatorExpansions(MetaBase):
    mExpandedMutator: str
    mMutators: list[str]
    pass

@MetaClassEmpty
class IGameCalculationPart(MetaBase):
    pass

@MetaClass
class EffectValueCalculationPart(IGameCalculationPart):
    mEffectIndex: Int32
    pass

@MetaClass
class NamedDataValueCalculationPart(IGameCalculationPart):
    mDataValue: Hash
    pass

@MetaClassEmpty
class CooldownMultiplierCalculationPart(IGameCalculationPart):
    pass

@MetaClass
class CustomReductionMultiplierCalculationPart(IGameCalculationPart):
    m_0x6e82b179: Optional[IGameCalculationPart]
    mMaximumReductionPercent: float
    pass

@MetaClass
class ProductOfSubPartsCalculationPart(IGameCalculationPart):
    mPart1: Optional[IGameCalculationPart]
    mPart2: Optional[IGameCalculationPart]
    pass

@MetaClass
class SumOfSubPartsCalculationPart(IGameCalculationPart):
    mSubparts: list[Optional[IGameCalculationPart]]
    pass

@MetaClass
class t_0x803dae4c(IGameCalculationPart):
    mCeiling: Optional[float]
    mFloor: Optional[float]
    mSubparts: list[Optional[IGameCalculationPart]]
    pass

@MetaClass
class NumberCalculationPart(IGameCalculationPart):
    mNumber: float
    pass

@MetaClass
class IGameCalculationPartWithStats(IGameCalculationPart):
    mStat: UInt8
    mStatFormula: UInt8
    pass

@MetaClass
class StatByCoefficientCalculationPart(IGameCalculationPartWithStats):
    mCoefficient: float
    pass

@MetaClass
class StatBySubPartCalculationPart(IGameCalculationPartWithStats):
    mSubpart: Optional[IGameCalculationPart]
    pass

@MetaClass
class StatByNamedDataValueCalculationPart(IGameCalculationPartWithStats):
    mDataValue: Hash
    pass

@MetaClass
class t_0x05abdfab(IGameCalculationPart):
    mStat: UInt8
    mStatFormula: UInt8
    mDataValue: Hash
    m_0xbfe6ad01: float
    pass

@MetaClass
class t_0xe9fb4d18(IGameCalculationPart):
    m_0x616627c4: Optional[IGameCalculationPart]
    m_0x465802ea: UInt8
    m_0x27833dcc: UInt8
    pass

@MetaClass
class SubPartScaledProportionalToStat(IGameCalculationPart):
    mSubpart: Optional[IGameCalculationPart]
    mRatio: float
    mStat: UInt8
    mStatFormula: UInt8
    mStyleTag: str
    m_0xa5749b52: str
    pass

@MetaClass
class AbilityResourceByCoefficientCalculationPart(IGameCalculationPart):
    mCoefficient: float
    mAbilityResource: UInt8
    mStatFormula: UInt8
    pass

@MetaClass
class IGameCalculationPartWithBuffCounter(IGameCalculationPart):
    mBuffName: Hash
    mIconKey: str
    mScalingTagKey: str
    pass

@MetaClass
class BuffCounterByCoefficientCalculationPart(IGameCalculationPartWithBuffCounter):
    mCoefficient: float
    pass

@MetaClass
class BuffCounterByNamedDataValueCalculationPart(IGameCalculationPartWithBuffCounter):
    mDataValue: Hash
    pass

@MetaClassEmpty
class IGameCalculationPartByCharLevel(IGameCalculationPart):
    pass

@MetaClass
class ByCharLevelInterpolationCalculationPart(IGameCalculationPartByCharLevel):
    mStartValue: float
    mEndValue: float
    m_0x7fe8e3b3: bool
    m_0xa331f6bf: bool
    pass

@MetaClass
class ByCharLevelBreakpointsCalculationPart(IGameCalculationPartByCharLevel):
    mLevel1Value: float
    m_0x02deb550: float
    mBreakpoints: list[Breakpoint]
    pass

@MetaClass
class Breakpoint(MetaBase):
    mLevel: UInt32
    m_0xd5fd07ed: float
    m_0x57fdc438: float
    pass

@MetaClass
class ByCharLevelFormulaCalculationPart(IGameCalculationPartByCharLevel):
    mValues: list[float]
    pass

@MetaClass
class t_0x663d5e00(IGameCalculationPart):
    Coefficient: float
    Epicness: UInt8
    pass

@MetaClass
class IGameCalculation(MetaBase):
    mMultiplier: Optional[IGameCalculationPart]
    m_0xcbcac618: UInt8
    m_0x37070a8d: UInt8
    m_0xe6eebb2f: UInt8
    TooltipOnly: bool
    pass

@MetaClass
class GameCalculation(IGameCalculation):
    mFormulaParts: list[Optional[IGameCalculationPart]]
    mDisplayAsPercent: bool
    mPrecision: Int32
    pass

@MetaClass
class GameCalculationModified(IGameCalculation):
    mOverrideSpellLevel: Optional[Int32]
    mModifiedGameCalculation: Hash
    pass

@MetaClass
class GameCalculationConditional(IGameCalculation):
    mDefaultGameCalculation: Hash
    mConditionalGameCalculation: Hash
    m_0xc0482365: Optional[ICastRequirement]
    pass

@MetaClass
class GameplayConfig(MetaBase):
    mSpellPostponeTimeoutSec: float
    mAutoAttackMinPreCastLockoutDeltaTimeSec: float
    mAutoAttackMinPostCastLockoutDeltaTimeSec: float
    mLethalityPercentGivenAtLevel0: float
    mLethalityScalesToLevel: Int32
    mLethalityScalesCapsAtLevel: Int32
    mLethalityRatioFromTarget: float
    mLethalityRatioFromAttacker: float
    AbilityHasteMax: float
    mCritTotalArmorPenPercent: float
    mCritBonusArmorPenPercent: float
    mCritGlobalDamageMultiplier: float
    mAdaptiveForceAbilityPowerScale: float
    mAdaptiveForceAttackDamageScale: float
    mMinionDeathDelay: float
    mMinionAutoLeeway: float
    mMinionAaHelperLimit: float
    mItemSellQueueTime: float
    mCcScoreMultipliers: CcScoreMultipliers
    mPerSlotCdrIsAdditive: bool
    mSummonerSpells: list[Hash]
    mLegacySummonerSpells: list[Hash]
    ItemsRolesPerRow: Hash
    m_0xa64802f2: Hash
    mBasicAttackCalculation: Optional[IGameCalculation]
    pass

@MetaClass
class EnchantmentGroup(MetaBase):
    mCanSidegrade: bool
    mEnchantments: list[Int32]
    mBaseItems: list[Int32]
    mItemIdRangeMinimum: Int32
    mItemIdRangeMaximum: Int32
    pass

@MetaClass
class ItemData(MetaBase):
    mRequiredChampion: str
    mRequiredAlly: str
    mRequiredSpellName: str
    mRequiredBuffCurrencyName: str
    mRequiredPurchaseIdentities: list[Hash]
    mDisabledDescriptionOverride: str
    mParentEnchantmentGroup: str
    mDeathRecapName: str
    mRequiredLevel: Int32
    ItemId: Int32
    MaxStack: Int32
    mItemGroups: list[Link[ItemGroup]]
    mItemAdviceAttributes: list[Link[ItemAdviceAttribute]]
    ItemVoGroup: Hash
    Price: Int32
    mRequiredBuffCurrencyCost: Int32
    mSidegradeCredit: float
    Consumed: bool
    UsableInStore: bool
    ConsumeOnAcquire: bool
    mItemCalloutPlayer: bool
    mItemCalloutSpectator: bool
    ClearUndoHistory: UInt8
    mCanBeSold: bool
    mHiddenFromOpponents: bool
    mIsEnchantment: bool
    SpecialRecipe: Int32
    Epicness: UInt8
    SecondaryEpicness: UInt8
    RecipeItemLinks: list[Link[ItemData]]
    RequiredItemLinks: list[Link[ItemData]]
    SidegradeItemLinks: list[Link[ItemData]]
    mItemModifiers: list[Link[ItemModifier]]
    mScripts: list[str]
    ParentEnchantmentLink: Link[ItemData]
    ParentItemLink: Link[ItemData]
    mFlatCooldownMod: float
    mPercentCooldownMod: float
    mAbilityHasteMod: float
    mFlatHpPoolMod: float
    mPercentHpPoolMod: float
    mFlatHpRegenMod: float
    mPercentHpRegenMod: float
    mPercentBaseHpRegenMod: float
    mPercentTenacityItemMod: float
    mPercentSlowResistMod: float
    mFlatMovementSpeedMod: float
    mPercentMovementSpeedMod: float
    mPercentMultiplicativeMovementSpeedMod: float
    mFlatArmorMod: float
    mPercentArmorMod: float
    mFlatArmorPenetrationMod: float
    mPercentArmorPenetrationMod: float
    mPercentBonusArmorPenetrationMod: float
    mFlatMagicPenetrationMod: float
    mPercentMagicPenetrationMod: float
    mPercentBonusMagicPenetrationMod: float
    mFlatSpellBlockMod: float
    mPercentSpellBlockMod: float
    mFlatDodgeMod: float
    mFlatCritChanceMod: float
    mFlatMissChanceMod: float
    mFlatCritDamageMod: float
    mPercentCritDamageMod: float
    mFlatPhysicalDamageMod: float
    mPercentPhysicalDamageMod: float
    mFlatMagicDamageMod: float
    mPercentMagicDamageMod: float
    mFlatPhysicalReduction: float
    mPercentPhysicalReduction: float
    mFlatMagicReduction: float
    mPercentMagicReduction: float
    mPercentExpBonus: float
    mFlatAttackRangeMod: float
    mPercentAttackRangeMod: float
    mFlatCastRangeMod: float
    mPercentCastRangeMod: float
    mPercentAttackSpeedMod: float
    mPercentMultiplicativeAttackSpeedMod: float
    mPercentHealingAmountMod: float
    mPercentLifeStealMod: float
    mPercentSpellVampMod: float
    PercentOmnivampMod: float
    PercentPhysicalVampMod: float
    mPercentSpellEffectivenessMod: float
    mFlatBubbleRadiusMod: float
    mPercentBubbleRadiusMod: float
    SellBackModifier: float
    mCooldownShowDisabledDuration: float
    FlatMpPoolMod: float
    PercentMpPoolMod: float
    FlatMpRegenMod: float
    PercentMpRegenMod: float
    PercentBaseMpRegenMod: float
    mItemDataBuild: ItemDataBuild
    mItemDataAvailability: ItemDataAvailability
    mCategories: list[str]
    mBuildDepth: Int32
    mDataValues: list[ItemDataValue]
    m_0xfb56608c: dict[Hash, t_0x61f8c41c]
    mItemCalculations: dict[Hash, Optional[IGameCalculation]]
    mItemAttributes: list[UInt8]
    m_0x224a3815: Int32
    m_0xc01bb6dd: UInt8
    m_0x51265c89: UInt8
    mItemDataClient: ItemDataClient
    mVfxResourceResolver: Optional[ResourceResolver]
    mDisplayName: str
    mEffectAmount: list[float]
    mEnchantmentEffectAmount: list[float]
    mEffectByLevelAmount: list[float]
    SpellName: str
    Clickable: bool
    mMajorActiveItem: bool
    pass

@MetaClass
class ItemDataValue(MetaBase):
    mName: str
    mValue: float
    pass

@MetaClass
class t_0x61f8c41c(MetaBase):
    m_0x06afef1b: list[ItemDataValue]
    pass

@MetaClass
class ItemDataAvailability(MetaBase):
    mInStore: bool
    mForceLoad: bool
    mHidefromAll: bool
    pass

@MetaClass
class ItemDataBuild(MetaBase):
    ItemLinks: list[Link[ItemData]]
    pass

@MetaClass
class ItemGroup(MetaBase):
    mItemGroupId: Hash
    mMaxGroupOwnable: Int32
    mInventorySlotMin: Int32
    mInventorySlotMax: Int32
    mPurchaseCooldown: float
    mCooldownExtendedByAmbientGoldStart: bool
    mItemModifiers: list[Link[ItemModifier]]
    pass

@MetaClass
class ItemModifier(MetaBase):
    mItemModifierId: Hash
    mModifiedItem: Link[ItemData]
    mModifiedGroup: Link[ItemGroup]
    mModifiedIfBuildsFromItem: Link[ItemData]
    mMinimumModifierInstancesToBeActive: Int32
    mMaximumModifierInstancesToBeActive: Int32
    mMaximumDeltasToStack: Int32
    mShowAsModifiedInUi: bool
    mModifierIsInheritedByOwnedParentItems: bool
    mAddedBuildFrom: list[Link[ItemData]]
    mRemovedBuildFrom: list[Link[ItemData]]
    mReplaceInsteadOfAddingBuildFrom: bool
    mIgnoreMaxGroupOwnable: bool
    mIgnoreSpecificMaxGroupOwnable: Hash
    mDeltaGoldCost: float
    mDeltaGoldCostPercent: float
    mDeltaBuffCurrencyCostPercent: float
    mDeltaRequiredLevel: Int32
    mDeltaBuffCurrencyCost: Int32
    mDeltaMaxStacks: Int32
    mVisualPriority: Int32
    InventoryIconToOverlay: str
    mDescriptionToAppend: str
    mDescriptionToPrepend: str
    mDescriptionToReplace: str
    mDynamicTooltipToAppend: str
    mDynamicTooltipToPrepend: str
    mDynamicTooltipToReplace: str
    mDisplayNameToAppend: str
    mDisplayNameToPrepend: str
    mDisplayNameToReplace: str
    mClickableToEnable: bool
    mMajorActiveItemToEnable: bool
    mSpellNameToReplace: str
    pass

@MetaClass
class ItemDataClient(MetaBase):
    mTooltipData: Optional[TooltipInstanceItem]
    mDescription: str
    mDynamicTooltip: str
    mShopTooltip: str
    ShopExtendedTooltip: str
    Epicness: UInt8
    EffectRadius: float
    mFloatVarsDecimals: list[Int32]
    InventoryIcon: str
    InventoryIconSmall: str
    InventoryIconLarge: str
    InventoryIconMaterial: Link[StaticMaterialDef]
    pass

@MetaClass
class ChampionItemRecommendations(MetaBase):
    m_0xcc35ff18: Hash
    mContextListLink: Hash
    m_0xad6d25a8: list[ItemCareyOverrideStartingItemSet]
    m_0x2d7fd821: list[Hash]
    pass

@MetaClass
class ItemRecommendationItemList(MetaBase):
    mItemList: list[UInt32]
    pass

@MetaClass
class ItemRecommendationContextList(MetaBase):
    mAllStartingItemIds: dict[UInt32, ItemRecommendationItemList]
    m_0xa109530e: dict[UInt32, ItemRecommendationItemList]
    mContexts: list[ItemRecommendationContext]
    pass

@MetaClass
class ItemRecommendationContext(MetaBase):
    mChampionId: UInt32
    mMapId: UInt32
    m_0x37b75f5c: Hash
    mPosition: Hash
    mIsDefaultPosition: bool
    mPopularItems: list[Hash]
    mStartingItemMatrix: ItemRecommendationMatrix
    mStartingItemBundles: list[ItemRecommendationItemList]
    mCompletedItemMatrix: ItemRecommendationMatrix
    pass

@MetaClass
class ItemRecommendationChoices(MetaBase):
    mChoices: list[UInt32]
    pass

@MetaClass
class ItemRecommendationMatrixRow(MetaBase):
    mChoicesMap: dict[str, ItemRecommendationChoices]
    pass

@MetaClass
class ItemRecommendationMatrix(MetaBase):
    Mrows: list[ItemRecommendationMatrixRow]
    pass

@MetaClass
class t_0x5a3bc52d(MetaBase):
    Items: list[Hash]
    m_0x50ef1a22: UInt32
    pass

@MetaClass
class ItemRecommendationCondition(MetaBase):
    mItem: Hash
    mDisplayLimit: UInt32
    mGroupId: UInt8
    pass

@MetaClass
class ItemRecommendationOverrideContext(MetaBase):
    mMapId: UInt32
    m_0x37b75f5c: Hash
    mPosition: Hash
    pass

@MetaClass
class ItemRecommendationOverrideStartingItemSet(MetaBase):
    mStartingItems: list[Hash]
    pass

@MetaClass
class ItemRecommendationOverride(MetaBase):
    mForceOverride: bool
    mOverrideContexts: list[ItemRecommendationOverrideContext]
    mStartingItemSets: list[ItemRecommendationOverrideStartingItemSet]
    mRecItemRanges: list[t_0x5a3bc52d]
    mCoreItems: list[Hash]
    mRecommendedItems: list[ItemRecommendationCondition]
    pass

@MetaClass
class ItemRecommendationOverrideSet(MetaBase):
    mOverrides: list[ItemRecommendationOverride]
    pass

@MetaClass
class ItemAdviceAttribute(MetaBase):
    mAttribute: str
    pass

@MetaClass
class ItemCareyOverrideStartingItemSet(MetaBase):
    mAttribute: Hash
    pass

@MetaClass
class ItemCareyOverrideStartingItemSetSet(MetaBase):
    m_0x6ca781cd: list[ItemCareyOverrideStartingItemSet]
    pass

@MetaClass
class ItemShopGameModeData(MetaBase):
    m_0xc561f8e9: list[Hash]
    m_0xc3b3430a: UInt32
    m_0x51a18bc3: Hash
    m_0x897c69b7: dict[Hash, Hash]
    RecItemsSwaps: dict[UInt32, UInt32]
    pass

@MetaClass
class CollectiblesEsportsTeamData(MetaBase):
    TeamId: UInt32
    ShortName: str
    FullName: str
    LeagueName: str
    pass

@MetaClass
class SummonerIconData(MetaBase):
    IconId: UInt32
    EsportsTeam: Link[CollectiblesEsportsTeamData]
    GameTexture: str
    m_0x50e5b6e1: bool
    EsportsEventMutator: str
    pass

@MetaClass
class LiveFeatureToggles(MetaBase):
    mLolToggles: LolFeatureToggles
    mGameplayToggles: GameplayFeatureToggles
    mEngineToggles: EngineFeatureToggles
    pass

@MetaClass
class LolFeatureToggles(MetaBase):
    PromoController: bool
    m_0xf2505841: bool
    m_0x6dbee4b7: bool
    m_0xa3820b10: bool
    ItemUndo: bool
    NewSpellScript: bool
    QueuedOrdersTriggerPreIssueOrder: bool
    EnableCustomPlayerScoreColoring: bool
    CloseOnEndGameAfterDelay: bool
    AbilityResetUi: bool
    CooldownSpellQueueing: bool
    m_0xa6cc4da4: bool
    UseNewAttackSpeed: bool
    m_0xa6000d17: bool
    m_0xed504579: bool
    UseNewFireBbEvents: bool
    m_0xd3323ebc: bool
    m_0x8cd3b1f9: bool
    m_0x3e3c2065: bool
    m_0x6f0ba2b0: bool
    m_0x59e03167: bool
    m_0xcc5e3f8d: bool
    m_0xf1125a78: bool
    m_0x768400a9: bool
    m_0x069b85d1: bool
    m_0x9b710bf6: bool
    m_0x68c9483d: bool
    m_0xc779da22: bool
    m_0x2f0e955a: bool
    m_0x8bab003a: bool
    m_0x85af0cb5: bool
    m_0x84fe7ccf: bool
    m_0x90e08cc7: bool
    m_0xc25a56fb: bool
    m_0x9cfc57ba: bool
    m_0x40bae5a8: bool
    m_0xde421b66: bool
    m_0x8dc6f20a: bool
    pass

@MetaClassEmpty
class GdsMapObjectExtraInfo(MetaBase):
    pass

@MetaClass
class GdsMapObjectAnimationInfo(GdsMapObjectExtraInfo):
    DefaultAnimation: str
    Looping: bool
    DestroyOnCompletion: bool
    Duration: float
    pass

@MetaClass
class GdsMapObjectLightingInfo(GdsMapObjectExtraInfo):
    Colors: list[Vec4]
    pass

@MetaClass
class GdsMapObjectBannerInfo(GdsMapObjectExtraInfo):
    BannerData: Link[EsportsBannerData]
    pass

@MetaClass
class MapPlaceable(MetaBase):
    Transform: Mtx44
    Name: str
    mVisibilityFlags: UInt8
    pass

@MetaClassEmpty
class GenericMapPlaceable(MapPlaceable):
    pass

@MetaClass
class GdsMapObject(GenericMapPlaceable):
    BoxMin: Vec3
    BoxMax: Vec3
    Type: UInt8
    IgnoreCollisionOnPlacement: bool
    EyeCandy: bool
    MapObjectSkinId: UInt32
    ExtraInfo: list[Optional[GdsMapObjectExtraInfo]]
    pass

@MetaClassEmpty
class LootOutputBase(MetaBase):
    pass

@MetaClass
class LootItemDetails(MetaBase):
    mStoreId: UInt32
    mRarity: UInt32
    mValue: UInt32
    pass

@MetaClass
class LootStatus(MetaBase):
    mTags: list[str]
    mImageTexturePath: str
    mActiveDate: str
    mInactiveDate: str
    mLifetimeMax: Int32
    mAutoRedeem: bool
    mActive: bool
    pass

@MetaClass
class LootItem(LootOutputBase):
    mInternalName: str
    mName: str
    mHoverDescription: str
    mAdminDescription: str
    mStatus: LootStatus
    mDetails: LootItemDetails
    pass

@MetaClass
class ClientStateCommonSettings(MetaBase):
    m_0x5b40f8fd: UInt32
    m_0x6a9d87e7: UInt32
    m_0xefe9214c: UInt32
    pass

@MetaClass
class IdentityInstance(MetaBase):
    mItemTexturePath: str
    pass

@MetaClass
class t_0x4d31ed46(MetaBase):
    mIdentityInstance: IdentityInstance
    mCatalogEntry: CatalogEntry
    pass

@MetaClass
class t_0x14aef50c(MetaBase):
    mInventoryType: str
    mOrder: UInt8
    mItemIds: list[Int32]
    mInventoryFilters: list[t_0x14aef50c]
    pass

@MetaClass
class t_0x9f59e92d(MetaBase):
    mName: str
    mOrder: UInt8
    mEnabled: bool
    mInventoryFilters: list[t_0x14aef50c]
    pass

@MetaClass
class Map(WadFileDescriptor):
    MapStringId: str
    BasedOnMap: Link[Map]
    CharacterLists: list[Link[MapCharacterList]]
    m_0x6744e6e3: UInt8
    m_0x9e019715: MapVisibilityFlagDefinitions
    NavigationGridOverlays: MapNavigationGridOverlays
    pass

@MetaClass
class MapAction(MetaBase):
    StartTime: float
    pass

@MetaClass
class t_0xaf23408c(MapAction):
    m_0x5c042946: list[str]
    m_0x15db0d85: str
    m_0x29a7efc6: float
    Shuffle: bool
    pass

@MetaClass
class t_0x8c0d80f5(MapAction):
    MapParticleName: list[str]
    Shuffle: bool
    pass

@MetaClass
class t_0x6cdbb71d(MapAction):
    TargetName: str
    Pathname: str
    Duration: float
    Velocity: float
    m_0x3ade3a5d: bool
    m_0xeefb990f: bool
    pass

@MetaClass
class MapActionPlayAnimation(MapAction):
    PropName: str
    AnimationName: str
    Looping: bool
    pass

@MetaClass
class MapActionPlaySoundAtLocation(MapAction):
    SoundEventName: str
    LocationName: str
    pass

@MetaClass
class t_0x49da656e(MapAction):
    PropName: str
    Key: str
    Value: float
    pass

@MetaClass
class t_0xced6ab09(MapAction):
    MapParticleName: list[str]
    Shown: bool
    pass

@MetaClassEmpty
class t_0xe1bb8efb(MapAction):
    pass

@MetaClass
class MapAlternateAsset(MetaBase):
    mGrassTintTextureName: str
    m_0x603134b8: str
    m_0x198716d9: str
    mParticleResourceResolver: Link[ResourceResolver]
    m_0x97472c4d: Hash
    pass

@MetaClass
class MapAlternateAssets(MetaBase):
    mAlternateAssets: list[MapAlternateAsset]
    pass

@MetaClass
class MapBehavior(GenericMapPlaceable):
    Cue: str
    Actions: list[Optional[MapAction]]
    m_0x077f9e08: float
    pass

@MetaClass
class MapCharacterList(MetaBase):
    Characters: list[Link[Character]]
    pass

@MetaClass
class MapLocatorArray(MetaBase):
    Locators: list[MapLocator]
    pass

@MetaClass
class MapNavigationGridOverlays(MetaBase):
    Overlays: dict[str, Link[MapNavigationGridOverlay]]
    pass

@MetaClass
class MapNavigationGridOverlay(MetaBase):
    NavGridFileName: str
    RegionsFilename: str
    pass

@MetaClass
class MapSkinColorizationPostEffect(MetaBase):
    mMultipliersRgb: Vec3
    mMultipliersSaturation: float
    pass

@MetaClass
class MapSkin(MetaBase):
    mMapContainerLink: str
    mMinimapBackgroundConfig: MinimapBackgroundConfig
    mAlternateAssets: MapAlternateAssets
    mMapObjectsCfg: str
    mNavigationMesh: str
    m_0x14f54bbd: Link[GameModeConstants]
    mWorldParticlesIni: str
    mColorizationPostEffect: Optional[MapSkinColorizationPostEffect]
    mGrassTintTexture: str
    m_0xb0e90e8e: str
    mObjectSkinFallbacks: dict[Hash, Int32]
    mResourceResolvers: list[Link[ResourceResolver]]
    pass

@MetaClass
class MapVisibilityFlagRange(MetaBase):
    MinIndex: UInt8
    MaxIndex: UInt8
    pass

@MetaClass
class MapVisibilityFlagDefinition(MetaBase):
    Name: Hash
    PublicName: str
    BitIndex: UInt8
    TransitionTime: float
    pass

@MetaClass
class MapVisibilityFlagDefinitions(MetaBase):
    FlagDefinitions: list[MapVisibilityFlagDefinition]
    FlagRange: MapVisibilityFlagRange
    m_0x822356e3: bool
    m_0x5ffc00df: bool
    pass

@MetaClass
class MinimapBackground(MetaBase):
    mTextureName: str
    mOrigin: Vec2
    mSize: Vec2
    pass

@MetaClass
class MinimapBackgroundConfig(MetaBase):
    mDefaultTextureName: str
    mCustomMinimapBackgrounds: dict[Hash, MinimapBackground]
    pass

@MetaClass
class MissionAsset(MetaBase):
    mInternalName: str
    mIconTexturePath: str
    m_0xf82efec6: bool
    pass

@MetaClass
class CheatPage(MetaBase):
    mCheats: list[Link[Cheat]]
    pass

@MetaClass
class CheatSet(MetaBase):
    mName: str
    mGameMutator: str
    mGameModeName: Hash
    mAssociatedChampion: Link[Champion]
    mCheatPages: list[CheatPage]
    mIsPlayerFacing: bool
    mUseIconsForButtons: bool
    mIsUiAlwaysShown: bool
    pass

@MetaClass
class CheatMenuUiData(MetaBase):
    mDisplayName: str
    mFloatingTextDisplayName: str
    mTooltipText: str
    mDynamicTooltipText: str
    mHotkey: str
    mHotkeys: list[str]
    mIsToggleCheat: bool
    pass

@MetaClass
class Cheat(MetaBase):
    mRecastFrequency: float
    mName: str
    mCheatMenuUiData: Optional[CheatMenuUiData]
    mIsPlayerFacing: bool
    pass

@MetaClass
class ScriptCheat(Cheat):
    mTarget: UInt32
    mScriptCallback: Hash
    pass

@MetaClass
class AddGoldCheat(Cheat):
    mTarget: UInt32
    mGoldAmount: float
    pass

@MetaClass
class MaxAllSkillsCheat(Cheat):
    mTarget: UInt32
    mOnlyOnePointEach: bool
    pass

@MetaClass
class AddExperienceCheat(Cheat):
    mTarget: UInt32
    mGiveMaxLevel: bool
    pass

@MetaClass
class ToggleBuffCheat(Cheat):
    mTarget: UInt32
    mBuffName: str
    UseTargetAsCaster: bool
    pass

@MetaClass
class AddHealthCheat(Cheat):
    mTarget: UInt32
    mAmount: float
    pass

@MetaClass
class AddParCheat(Cheat):
    mTarget: UInt32
    mAmount: float
    pass

@MetaClass
class ToggleRegenCheat(Cheat):
    mTarget: UInt32
    mToggleHp: bool
    mTogglePar: bool
    pass

@MetaClass
class ClearTargetCooldownCheat(Cheat):
    mTarget: UInt32
    pass

@MetaClass
class TimeMultiplierCheat(Cheat):
    mSpeedUp: bool
    mSpeedDown: bool
    pass

@MetaClass
class DamageUnitCheat(Cheat):
    mTarget: UInt32
    mDamageAmount: UInt32
    mPercentageOfAttack: float
    mDamageType: UInt32
    mHitResult: UInt32
    pass

@MetaClass
class ToggleBarracksCheat(Cheat):
    mKillExistingMinions: bool
    mKillWards: bool
    pass

@MetaClass
class ToggleTeamCheat(Cheat):
    mTarget: UInt32
    pass

@MetaClass
class SetRespawnTimerCheat(Cheat):
    mTarget: UInt32
    mTimerValue: float
    pass

@MetaClass
class ToggleInvulnerableCheat(Cheat):
    mTarget: UInt32
    pass

@MetaClassEmpty
class KillAllTurretsCheat(Cheat):
    pass

@MetaClass
class ForceSpawnNeutralCampsCheat(Cheat):
    mSpawnBaron: bool
    pass

@MetaClass
class ResetGoldCheat(Cheat):
    mTarget: UInt32
    pass

@MetaClassEmpty
class TogglePlantFastRespawnCheat(Cheat):
    pass

@MetaClassEmpty
class SwapChampionCheat(Cheat):
    pass

@MetaClassEmpty
class ToggleAfkDetectionCheat(Cheat):
    pass

@MetaClass
class PerkEffectAmountPerMode(MetaBase):
    mEffectAmountPerMode: dict[Hash, float]
    pass

@MetaClass
class PerkScriptData(MetaBase):
    mEffectAmount: dict[Hash, float]
    mEffectAmountGameMode: dict[Hash, PerkEffectAmountPerMode]
    mCalculations: dict[Hash, Optional[IGameCalculation]]
    pass

@MetaClass
class PerkScript(MetaBase):
    mSpellScriptName: str
    mSpellScript: Optional[LolSpellScript]
    mSpellScriptData: PerkScriptData
    pass

@MetaClass
class PerkBuff(MetaBase):
    mBuffScriptName: str
    mBuffSpellObject: SpellObject
    pass

@MetaClass
class BasePerk(MetaBase):
    mPerkId: UInt32
    mPerkName: str
    mDisplayNameLocalizationKey: str
    mTooltipNameLocalizationKey: str
    mPingTextLocalizationKey: str
    mShortDescLocalizationKey: str
    mLongDescLocalizationKey: str
    mEndOfGameStatDescriptions: list[str]
    mDisplayStatLocalizationKey: str
    mIconTextureName: str
    mEnabled: bool
    mStackable: bool
    mScript: Optional[PerkScript]
    mBuffs: list[Optional[PerkBuff]]
    mVfxResourceResolver: Optional[ResourceResolver]
    mCharacters: list[str]
    pass

@MetaClass
class PerkStyle(MetaBase):
    mPerkStyleId: UInt32
    mPerkStyleName: str
    mDisplayNameLocalizationKey: str
    mTooltipNameLocalizationKey: str
    mIconTextureName: str
    mDefaultPageLocalizationKey: str
    mPingTextLocalizationKey: str
    mEnabled: bool
    mIsAdvancedStyle: bool
    mAllowedSubStyles: list[UInt32]
    mSubStyleBonus: list[PerkSubStyleBonus]
    mSlots: list[PerkSlot]
    mSlotlinks: list[Link[PerkSlot]]
    mScript: Optional[PerkScript]
    mScriptAsSubStyle: Optional[PerkScript]
    mBuffs: list[Optional[PerkBuff]]
    mDefaultSplash: Optional[DefaultSplashedPerkStyle]
    mDefaultPerksWhenSplashed: list[Link[Perk]]
    m_0x0fa4e9a2: list[DefaultStatModPerkSet]
    mStyleVfxResourceResolver: Optional[ResourceResolver]
    mLcuAssetFileMap: dict[str, str]
    pass

@MetaClass
class PerkSlot(MetaBase):
    mSlotLabelKey: str
    mType: UInt32
    mPerks: list[Link[Perk]]
    pass

@MetaClass
class DefaultSplashedPerkStyle(MetaBase):
    mStyle: Link[PerkStyle]
    mPerk1: Link[Perk]
    mPerk2: Link[Perk]
    pass

@MetaClass
class DefaultStatModPerkSet(MetaBase):
    mStyleId: UInt32
    mPerks: list[Link[Perk]]
    pass

@MetaClass
class PerkSubStyleBonus(MetaBase):
    mStyleId: UInt32
    mPerk: Link[Perk]
    pass

@MetaClass
class SummonerSpellPerkReplacement(MetaBase):
    mSummonerSpellRequired: Hash
    m_0xd48a5ef1: Hash
    pass

@MetaClass
class SummonerSpellPerkReplacementList(MetaBase):
    mReplacements: list[Optional[SummonerSpellPerkReplacement]]
    pass

@MetaClass
class Perk(BasePerk):
    mSummonerPerkReplacements: SummonerSpellPerkReplacementList
    mMajorChangePatchVersion: str
    mDefault: bool
    pass

@MetaClass
class PerkReplacement(MetaBase):
    mReplaceTarget: Hash
    mReplaceWith: Hash
    pass

@MetaClass
class PerkReplacementList(MetaBase):
    mReplacements: list[Optional[PerkReplacement]]
    pass

@MetaClass
class PerkConfig(MetaBase):
    mBotOverrideSet: Link[OverridePerkSelectionSet]
    mPerkReplacements: PerkReplacementList
    m_0x108e746d: UInt32
    pass

@MetaClass
class OverridePerkSelectionSet(MetaBase):
    mStyle: Link[PerkStyle]
    mSubStyle: Link[PerkStyle]
    mPerks: list[Link[Perk]]
    pass

@MetaClass
class ToonInkingFilterParams(MetaBase):
    mPixelSize: float
    mMinVal: float
    mMaxVal: float
    mResultScale: float
    pass

@MetaClass
class RenderStyleData(MetaBase):
    mUnitFilterParamsInterior: ToonInkingFilterParams
    mUnitFilterParamsExterior: ToonInkingFilterParams
    mUnitStyleUseInking: bool
    pass

@MetaClassEmpty
class MaterialOverrideCallbackDynamicMaterial(MetaBase):
    pass

@MetaClass
class MouseOverEffectData(MetaBase):
    mAllyColor: Color
    mEnemyColor: Color
    mNeutralColor: Color
    mSelfColor: Color
    mInteractionTimes: list[float]
    mInteractionSizes: list[Int32]
    mMouseOverSize: Int32
    mMouseOverColorFactor: float
    mMouseOverBlurPassCount: UInt32
    mSelectedSize: Int32
    mSelectedColorFactor: float
    mSelectedBlurPassCount: UInt32
    mAvatarSize: Int32
    mAvatarColorFactor: float
    mAvatarColor: Color
    mAvatarBlurPassCount: UInt32
    mKillerSize: Int32
    mKillerColorFactor: float
    mKillerBlurPassCount: UInt32
    pass

@MetaClass
class FxSequence(MetaBase):
    Actions: list[Optional[IFxAction]]
    pass

@MetaClass
class FxTableEntry(MetaBase):
    Type: Link[t_0x245ba20b]
    Sequence: Link[FxSequence]
    pass

@MetaClass
class FxTable(MetaBase):
    Entries: list[FxTableEntry]
    pass

@MetaClass
class FxTarget(MetaBase):
    Type: UInt32
    Index: Int32
    pass

@MetaClass
class FxTiming(MetaBase):
    Anchor: UInt32
    Type: UInt32
    Offset: float
    pass

@MetaClass
class FxTransform(MetaBase):
    Type: UInt32
    Index: Int32
    AttachmentName: str
    pass

@MetaClass
class t_0x245ba20b(MetaBase):
    Name: str
    m_0xcec577d1: Hash
    pass

@MetaClass
class IFxAction(MetaBase):
    Start: FxTiming
    End: FxTiming
    pass

@MetaClass
class FxActionAnimate(IFxAction):
    AnimName: str
    TargetObject: FxTarget
    Loop: bool
    m_0xee7cd89a: bool
    PauseOnEnd: bool
    pass

@MetaClass
class t_0x55d03617(IFxAction):
    Position: FxTransform
    pass

@MetaClass
class t_0xda3ab4c4(IFxAction):
    Magnitude: float
    m_0xc4afd6f9: float
    FalloffRate: float
    Direction: Vec3
    pass

@MetaClass
class t_0xd082b191(IFxAction):
    Position: FxTransform
    Fov: float
    Yaw: float
    Pitch: float
    m_0x5a439ba5: float
    ZoomInTime: float
    ZoomOutTime: float
    ZoomInEase: UInt8
    ZoomOutEase: UInt8
    pass

@MetaClass
class t_0xa05a9472(IFxAction):
    Position: FxTransform
    Fov: float
    Yaw: float
    Pitch: float
    m_0x5a439ba5: float
    Follow: bool
    ZoomEase: UInt8
    pass

@MetaClass
class t_0x099cce3c(IFxAction):
    ZoomEase: UInt8
    pass

@MetaClassEmpty
class FxActionContinue(IFxAction):
    pass

@MetaClass
class FxActionMove(IFxAction):
    TargetObject: FxTarget
    Destination: FxTransform
    EasingType: UInt8
    OvershootDistance: float
    FaceVelocity: bool
    m_0xd935fe42: bool
    pass

@MetaClass
class FxActionMoveBase(IFxAction):
    TargetObject: FxTarget
    EasingType: UInt8
    OvershootDistance: float
    FaceVelocity: bool
    pass

@MetaClass
class FxActionMoveTo(FxActionMoveBase):
    Destination: FxTransform
    pass

@MetaClassEmpty
class FxActionMoveReset(FxActionMoveBase):
    pass

@MetaClass
class FxActionSfx(IFxAction):
    Position: FxTransform
    EventName: str
    pass

@MetaClass
class FxActionTimeDilate(IFxAction):
    TimeDilation: float
    Intime: float
    InEase: UInt8
    OutTime: float
    OutEase: UInt8
    pass

@MetaClass
class FxActionVfx(IFxAction):
    Follow: bool
    Position: FxTransform
    TargetPosition: FxTransform
    Particle: Link[VfxSystemDefinitionData]
    m_0x39d6e480: float
    FollowPath: bool
    PathTargetPosition: FxTransform
    SplineInfo: Optional[ISplineInfo]
    Scale: float
    pass

@MetaClass
class GameplayFeatureToggles(MetaBase):
    NewActorStuckPathfinding: bool
    FowCastRayAccurate: bool
    DisableSpellLevelMinimumProtections: bool
    IndividualItemVisibility: bool
    AfkDetection2: bool
    pass

@MetaClass
class ScriptDataObject(MetaBase):
    mName: str
    mConstants: dict[str, Optional[GameModeConstant]]
    m_0x9be36761: Link[GameModeConstantsGroup]
    pass

@MetaClass
class ScriptDataObjectList(MetaBase):
    mName: str
    mScriptDataObjects: list[Link[ScriptDataObject]]
    pass

@MetaClass
class ICastRequirement(MetaBase):
    mInvertResult: bool
    pass

@MetaClass
class HasAllSubRequirementsCastRequirement(ICastRequirement):
    mSubRequirements: list[Optional[ICastRequirement]]
    pass

@MetaClass
class HasNNearbyUnitsRequirement(ICastRequirement):
    mUnitsRequirements: list[Optional[ICastRequirement]]
    mUnitsRequired: UInt32
    mRange: float
    mDistanceType: UInt32
    pass

@MetaClass
class HasNNearbyVisibleUnitsRequirement(ICastRequirement):
    mUnitsRequirements: list[Optional[ICastRequirement]]
    mUnitsRequired: UInt32
    mRange: float
    mDistanceType: UInt32
    pass

@MetaClass
class HasTypeAndStatusFlags(ICastRequirement):
    mAffectsTypeFlags: UInt32
    mAffectsStatusFlags: UInt32
    pass

@MetaClass
class HasAtleastNSubRequirementsCastRequirement(ICastRequirement):
    mSuccessesRequired: UInt32
    mSubRequirements: list[Optional[ICastRequirement]]
    pass

@MetaClass
class HasUnitTagsCastRequirement(ICastRequirement):
    mUnitTags: ObjectTags
    pass

@MetaClassEmpty
class SameTeamCastRequirement(ICastRequirement):
    pass

@MetaClass
class HasBuffCastRequirement(ICastRequirement):
    mBuffName: Hash
    mFromAnyone: bool
    pass

@MetaClass
class AboveHealthPercentCastRequirement(ICastRequirement):
    mCurrentPercentHealth: float
    pass

@MetaClass
class AboveParPercentCastRequirement(ICastRequirement):
    mParType: UInt8
    mCurrentPercentPar: float
    pass

@MetaClass
class IsSpecifiedUnitCastRequirement(ICastRequirement):
    mUnit: Hash
    pass

@MetaClassEmpty
class t_0x10f4d0bf(ICastRequirement):
    pass

@MetaClassEmpty
class t_0xdc65ffe4(ICastRequirement):
    pass

@MetaClassEmpty
class ItemSlotHasChargesCastRequirement(ICastRequirement):
    pass

@MetaClass
class t_0x2e7c5eda(ICastRequirement):
    Level: UInt32
    pass

@MetaClass
class t_0x48284759(ICastRequirement):
    Distance: float
    pass

@MetaClass
class CcScoreMultipliers(MetaBase):
    Stun: float
    Taunt: float
    Fear: float
    Flee: float
    Suppression: float
    Knockup: float
    Knockback: float
    Polymorph: float
    Root: float
    Silence: float
    Charm: float
    Slow: float
    AttackSpeedSlow: float
    Blind: float
    Disarm: float
    Grounded: float
    Nearsight: float
    Drowsy: float
    Asleep: float
    pass

@MetaClass
class BuffData(MetaBase):
    mVfxSpawnConditions: list[Optional[VfxSpawnConditions]]
    mDescription: str
    mTooltipData: Optional[TooltipInstanceBuff]
    m_0x62e282aa: bool
    mShowDuration: bool
    m_0x00d019c1: bool
    mFloatVarsDecimals: list[Int32]
    mBuffAttributeFlag: UInt8
    pass

@MetaClass
class TeamBuffData(MetaBase):
    mBuffName: str
    mUiName: str
    m_0x9a53f442: bool
    pass

@MetaClass
class MissionBuffData(MetaBase):
    Dragon: TeamBuffData
    FireDrake: TeamBuffData
    AirDrake: TeamBuffData
    WaterDrake: TeamBuffData
    EarthDrake: TeamBuffData
    ElderDrake: TeamBuffData
    GameModeCustom1: TeamBuffData
    GameModeCustom2: TeamBuffData
    m_0x8dea39f8: TeamBuffData
    m_0x94ea44fd: TeamBuffData
    m_0x93ea436a: TeamBuffData
    m_0x92ea41d7: TeamBuffData
    m_0x91ea4044: TeamBuffData
    m_0x88ea3219: TeamBuffData
    m_0x87ea3086: TeamBuffData
    m_0xbbbe4f6a: TeamBuffData
    pass

@MetaClass
class BuffStackingTemplate(MetaBase):
    Name: str
    MaxStacks: Int32
    m_0xb36eae8c: Int32
    StacksExclusive: bool
    BuffAddType: UInt32
    pass

@MetaClass
class BuffStackingSettings(MetaBase):
    TemplateDefinition: list[BuffStackingTemplate]
    pass

@MetaClass
class VfxSpawnConditionData(MetaBase):
    mPersistentVfxs: list[EffectCreationData]
    pass

@MetaClassEmpty
class VfxDefaultSpawnConditionData(VfxSpawnConditionData):
    pass

@MetaClass
class HasBuffData(MetaBase):
    mBuffName: str
    mFromAnyone: bool
    mFromOwner: bool
    mFromAttacker: bool
    pass

@MetaClass
class HasBuffComparisonData(MetaBase):
    mBuffs: list[HasBuffData]
    mCompareOp: UInt8
    pass

@MetaClass
class HasBuffSpawnConditionData(VfxSpawnConditionData):
    mBuffComparisons: HasBuffComparisonData
    pass

@MetaClass
class IsSkinSpawnConditionData(VfxSpawnConditionData):
    mSkinId: UInt32
    pass

@MetaClassEmpty
class IsOwnerHeroConditionData(VfxSpawnConditionData):
    pass

@MetaClassEmpty
class IsOwnerAliveConditionData(VfxSpawnConditionData):
    pass

@MetaClass
class HasSpellRankSpawnConditionData(VfxSpawnConditionData):
    mSpellSlot: UInt32
    mSpellLevel: Int32
    pass

@MetaClass
class VfxSpawnConditions(MetaBase):
    mDefaultVfxData: VfxDefaultSpawnConditionData
    mConditionalVfxData: list[Optional[VfxSpawnConditionData]]
    pass

@MetaClassEmpty
class IVfxSpawnConditions(MetaBase):
    pass

@MetaClass
class AlwaysSpawnCondition(IVfxSpawnConditions):
    mDefaultVfxData: VfxDefaultSpawnConditionData
    pass

@MetaClass
class HasBuffNameSpawnConditions(IVfxSpawnConditions):
    mDefaultVfxData: VfxDefaultSpawnConditionData
    mConditions: list[HasBuffSpawnConditionData]
    pass

@MetaClass
class HasSkinIdSpawnConditions(IVfxSpawnConditions):
    mDefaultVfxData: VfxDefaultSpawnConditionData
    mConditions: list[IsSkinSpawnConditionData]
    pass

@MetaClass
class IsOwnerHeroSpawnConditions(IVfxSpawnConditions):
    mDefaultVfxData: VfxDefaultSpawnConditionData
    mConditions: list[IsOwnerHeroConditionData]
    pass

@MetaClass
class IsOwnerAliveSpawnConditions(IVfxSpawnConditions):
    mDefaultVfxData: VfxDefaultSpawnConditionData
    mConditions: list[IsOwnerAliveConditionData]
    pass

@MetaClass
class EffectCreationData(MetaBase):
    mBoneName: str
    mTargetBoneName: str
    mEffectKey: Hash
    mEffectName: str
    m_0xa03a9542: Hash
    m_0xfe758550: str
    mPlaySpeedModifier: float
    m_0x87596a93: UInt32
    m_0xc42cf88d: bool
    m_0xa45eda7b: bool
    mFaceTarget: bool
    m_0xfd1e1bb4: bool
    m_0x453384e6: bool
    m_0x62f57c79: bool
    pass

@MetaClass
class RatioConversion(MetaBase):
    mSourceStatType: UInt8
    mSourceStatOutput: UInt8
    mResultingStatType: UInt8
    mResultingStatOutput: UInt8
    m_0x9227ce44: float
    pass

@MetaClass
class t_0x4379a5b2(MetaBase):
    m_0x5c92b7f2: UInt8
    m_0xaca5b9b4: UInt8
    m_0x583da425: list[Optional[IGameCalculationPart]]
    pass

@MetaClass
class SpellModifier(MetaBase):
    mModifierId: Hash
    m_0xa9cc2bf6: UInt8
    m_0xa47f56d7: UInt8
    m_0x5b1192f5: UInt32
    m_0x441a3020: list[RatioConversion]
    m_0xddbea054: list[t_0x4379a5b2]
    pass

@MetaClass
class AbilityObject(MetaBase):
    mRootSpell: Link[SpellObject]
    mChildSpells: list[Link[SpellObject]]
    m_0x86ddaddb: bool
    mName: str
    mType: UInt8
    pass

@MetaClass
class SpellObject(MetaBase):
    mScriptName: str
    mSpell: Optional[SpellDataResource]
    mBuff: Optional[BuffData]
    mScript: Optional[LolSpellScript]
    pass

@MetaClass
class MissileSpecification(MetaBase):
    mMissileWidth: float
    MovementComponent: Optional[MissileMovementSpec]
    VisibilityComponent: Optional[MissileVisibilitySpec]
    HeightSolver: Optional[HeightSolverType]
    VerticalFacing: Optional[VerticalFacingType]
    MissileGroupSpawners: list[MissileGroupSpawnerSpec]
    Behaviors: list[Optional[MissileBehaviorSpec]]
    pass

@MetaClassEmpty
class MissileBehaviorSpec(MetaBase):
    pass

@MetaClass
class FixedDistanceIgnoringTerrain(MissileBehaviorSpec):
    mMaximumDistance: float
    mMinimumGapBetweenTerrainWalls: float
    mMaximumTerrainWallsToSkip: Optional[UInt32]
    ScanWidthOverride: Optional[float]
    mTargeterDefinition: Optional[TargeterDefinitionSkipTerrain]
    pass

@MetaClassEmpty
class ScaleByScaleSkinCoef(MissileBehaviorSpec):
    pass

@MetaClass
class WidthPerSecond(MissileBehaviorSpec):
    mWidthPerSecond: float
    pass

@MetaClass
class MissileTriggerSpec(MissileBehaviorSpec):
    mActions: list[Optional[MissileTriggeredActionSpec]]
    pass

@MetaClass
class TriggerOnMovementComplete(MissileTriggerSpec):
    mDelay: Int32
    pass

@MetaClass
class TriggerOnDelay(MissileTriggerSpec):
    mDelay: float
    pass

@MetaClass
class DelayStart(MissileBehaviorSpec):
    mDelayTime: float
    pass

@MetaClass
class t_0x0798277f(MissileBehaviorSpec):
    m_0x5e19cde2: float
    m_0x6bfae91c: UInt32
    m_0x754a85a6: UInt32
    pass

@MetaClassEmpty
class TriggerOnStart(MissileTriggerSpec):
    pass

@MetaClassEmpty
class TriggerOnHit(MissileTriggerSpec):
    pass

@MetaClass
class TriggerOnDistanceFromCaster(MissileTriggerSpec):
    mDistance: float
    pass

@MetaClass
class TriggerFromScript(MissileTriggerSpec):
    mTriggerName: str
    mDelay: float
    pass

@MetaClassEmpty
class MissileTriggeredActionSpec(MetaBase):
    pass

@MetaClassEmpty
class Cast(MissileTriggeredActionSpec):
    pass

@MetaClassEmpty
class Destroy(MissileTriggeredActionSpec):
    pass

@MetaClass
class ReturnToCaster(MissileTriggeredActionSpec):
    mPreserveSpeed: bool
    mOverrideSpec: Optional[MissileMovementSpec]
    pass

@MetaClassEmpty
class ClearAlreadyHitTracking(MissileTriggeredActionSpec):
    pass

@MetaClassEmpty
class CallOnMissileBounce(MissileTriggeredActionSpec):
    pass

@MetaClass
class ClearTargetAndKeepMoving(MissileTriggeredActionSpec):
    mOverrideHeightAugment: Optional[float]
    mOverrideRange: Optional[float]
    mOverrideMovement: Optional[MissileMovementSpec]
    pass

@MetaClass
class ChangeMissileSpeed(MissileTriggeredActionSpec):
    mSpeedChangeType: UInt32
    mSpeedValue: float
    pass

@MetaClass
class t_0x3cd8dbcd(MissileTriggeredActionSpec):
    m_0x37a74ce3: UInt32
    m_0x90292654: float
    pass

@MetaClass
class ChangeTurnRadius(MissileTriggeredActionSpec):
    m_0x84bb076a: list[float]
    pass

@MetaClass
class ChangeHeightSolver(MissileTriggeredActionSpec):
    mOverrideHeightSolver: Optional[HeightSolverType]
    pass

@MetaClassEmpty
class DestroyOnHit(MissileBehaviorSpec):
    pass

@MetaClass
class DestroyOnMovementComplete(MissileBehaviorSpec):
    mDelay: Int32
    pass

@MetaClassEmpty
class t_0xe357c116(MissileBehaviorSpec):
    pass

@MetaClassEmpty
class CastOnHit(MissileBehaviorSpec):
    pass

@MetaClassEmpty
class CastOnMovementComplete(MissileBehaviorSpec):
    pass

@MetaClass
class ReturnToCasterOnMovementComplete(MissileBehaviorSpec):
    mPreserveSpeed: bool
    mOverrideSpec: Optional[MissileMovementSpec]
    pass

@MetaClass
class MissileGroupSpawnerSpec(MetaBase):
    mChildMissileSpell: Link[SpellObject]
    pass

@MetaClassEmpty
class HeightSolverType(MetaBase):
    pass

@MetaClass
class GravityHeightSolver(HeightSolverType):
    mGravity: float
    pass

@MetaClass
class FollowTerrainHeightSolver(HeightSolverType):
    mHeightOffset: float
    mMaxSlope: float
    pass

@MetaClassEmpty
class BlendedLinearHeightSolver(HeightSolverType):
    pass

@MetaClass
class SinusoidalHeightSolver(HeightSolverType):
    mVerticalOffset: float
    mAmplitude: float
    mNumberOfPeriods: float
    pass

@MetaClass
class CurveTheDifferenceHeightSolver(HeightSolverType):
    mInitialTargetHeightOffset: float
    pass

@MetaClass
class MissileMovementSpec(MetaBase):
    mUseHeightOffsetAtEnd: bool
    mTracksTarget: bool
    m_0xaa44f99e: bool
    mTargetHeightAugment: float
    mOffsetInitialTargetHeight: float
    mTargetBoneName: str
    mStartDelay: float
    mStartBoneName: str
    m_0xa6cb1fa4: dict[UInt32, str]
    pass

@MetaClass
class CircleMovement(MissileMovementSpec):
    mRadialVelocity: float
    mAngularVelocity: float
    mLinearVelocity: float
    mLifetime: float
    pass

@MetaClass
class SyncCircleMovement(MissileMovementSpec):
    mAngularVelocity: float
    mLifetime: float
    m_0x2630302a: UInt8
    m_0x16d0a895: bool
    pass

@MetaClass
class NullMovement(MissileMovementSpec):
    mWaitForChildren: bool
    mDelayTime: float
    pass

@MetaClass
class AcceleratingMovement(MissileMovementSpec):
    mInferDirectionFromFacingIfNeeded: bool
    mProjectTargetToCastRange: bool
    mUseGroundHeightAtTarget: bool
    mAcceleration: float
    mMinSpeed: float
    mMaxSpeed: float
    mInitialSpeed: float
    pass

@MetaClassEmpty
class DecelToLocationMovement(AcceleratingMovement):
    pass

@MetaClass
class FixedTimeMovement(MissileMovementSpec):
    mInferDirectionFromFacingIfNeeded: bool
    mProjectTargetToCastRange: bool
    mUseGroundHeightAtTarget: bool
    mTravelTime: float
    pass

@MetaClass
class FixedSpeedMovement(MissileMovementSpec):
    mInferDirectionFromFacingIfNeeded: bool
    mProjectTargetToCastRange: bool
    mUseGroundHeightAtTarget: bool
    mSpeed: float
    pass

@MetaClass
class PhysicsMovement(MissileMovementSpec):
    mLifetime: float
    mInitialSpeed: float
    mDrag: float
    mWallSliding: bool
    m_0xca771747: float
    pass

@MetaClass
class TrackMouseMovement(MissileMovementSpec):
    mInferDirectionFromFacingIfNeeded: bool
    mProjectTargetToCastRange: bool
    mUseGroundHeightAtTarget: bool
    mAcceleration: float
    mMinSpeed: float
    mMaxSpeed: float
    mInitialSpeed: float
    m_0x84bb076a: list[float]
    m_0x604989cf: float
    pass

@MetaClass
class GenericSplineMovementSpec(MissileMovementSpec):
    mUseMissilePositionAsOrigin: bool
    mSplineInfo: Optional[ISplineInfo]
    pass

@MetaClass
class FixedTimeSplineMovement(GenericSplineMovementSpec):
    mTravelTime: float
    pass

@MetaClass
class FixedSpeedSplineMovement(GenericSplineMovementSpec):
    mSpeed: float
    pass

@MetaClass
class WallFollowMovement(MissileMovementSpec):
    mInferDirectionFromFacingIfNeeded: bool
    mProjectTargetToCastRange: bool
    mUseGroundHeightAtTarget: bool
    mSpeed: float
    mCounterClockwise: bool
    mWallOffset: float
    mWallLength: float
    mWallSearchRadius: float
    m_0xbcff2ee1: bool
    m_0x38872364: bool
    pass

@MetaClassEmpty
class VerticalFacingType(MetaBase):
    pass

@MetaClassEmpty
class VeritcalFacingMatchVelocity(VerticalFacingType):
    pass

@MetaClassEmpty
class VerticalFacingFaceTarget(VerticalFacingType):
    pass

@MetaClass
class MissileVisibilitySpec(MetaBase):
    mTargetControlsVisibility: bool
    mVisibleToOwnerTeamOnly: bool
    mPerceptionBubbleRadius: float
    m_0xbb639057: float
    pass

@MetaClassEmpty
class Defaultvisibility(MissileVisibilitySpec):
    pass

@MetaClass
class EnterFowVisibility(MissileVisibilitySpec):
    mMissileClientExitFowPrediction: bool
    mMissileClientWaitForTargetUpdateBeforeMissileShow: bool
    pass

@MetaClass
class MissileAttachedTargetingDefinition(MetaBase):
    mEndPositionType: UInt8
    mLineTextureName: str
    mLineTextureWidth: float
    mLineEndTextureName: str
    mLineEndTextureWidth: float
    mLineEndTextureHeight: float
    pass

@MetaClass
class AiSpellData(MetaBase):
    mSendAiEvent: bool
    mRadius: float
    mLifetime: float
    mRange: float
    mSpeed: float
    mEndOnly: bool
    mBlockLevel: UInt8
    pass

@MetaClass
class SpellEffectAmount(MetaBase):
    Value: list[float]
    pass

@MetaClass
class SpellDataValue(MetaBase):
    mName: str
    mValues: list[float]
    pass

@MetaClass
class SpellDataValueVector(MetaBase):
    SpellDataValues: list[SpellDataValue]
    pass

@MetaClass
class PlatformSpellInfo(MetaBase):
    mAvatarLevelRequired: Int32
    mSpellId: Int32
    mPlatformEnabled: bool
    mGameModes: list[str]
    pass

@MetaClass
class ISplineInfo(MetaBase):
    mStartPositionOffset: Vec3
    mUseMissilePositionAsOrigin: bool
    pass

@MetaClass
class HermiteSplineInfo(ISplineInfo):
    mControlPoint1: Vec3
    mControlPoint2: Vec3
    pass

@MetaClass
class OverrideAttackTimeData(MetaBase):
    m_0x20991541: Optional[IGameCalculation]
    mCastTimePercent: float
    m_0x278d2a22: bool
    pass

@MetaClass
class UseAutoattackCastTimeData(MetaBase):
    mAutoattackCastTimeCalculation: Optional[IGameCalculation]
    m_0x862fbe94: bool
    pass

@MetaClass
class SpellLockDeltaTimeData(MetaBase):
    mSpellLockDeltaTimeCalculation: Optional[IGameCalculation]
    pass

@MetaClass
class t_0x7a9e7d89(MetaBase):
    m_0x55205acb: float
    m_0x166d5141: list[Optional[ICastRequirement]]
    m_0x175e6650: list[Optional[ICastRequirement]]
    m_0xda83e690: bool
    mAffectsTypeOverride: UInt32
    mAffectsStatusOverride: UInt32
    pass

@MetaClass
class AlternateSpellAssets(MetaBase):
    mAnimationName: str
    mAnimationLoopName: str
    mAnimationWinddownName: str
    mAnimationLeadOutName: str
    mUseAnimatorFramerate: bool
    mHitEffectOrientType: UInt32
    mHaveHitEffect: bool
    mHaveHitBone: bool
    mHitBoneName: str
    mHitEffectKey: Hash
    mHitEffectName: str
    mHitEffectPlayerKey: Hash
    mHitEffectPlayerName: str
    mAfterEffectKey: Hash
    mAfterEffectName: str
    pass

@MetaClass
class SpellDataResource(MetaBase):
    Flags: UInt32
    mAffectsTypeFlags: UInt32
    mAffectsStatusFlags: UInt32
    mRequiredUnitTags: ObjectTags
    mExcludedUnitTags: ObjectTags
    mCastRequirementsCaster: list[Optional[ICastRequirement]]
    mCastRequirementsTarget: list[Optional[ICastRequirement]]
    m_0x7a9e7d89: list[t_0x7a9e7d89]
    mPlatformSpellInfo: PlatformSpellInfo
    mAlternateName: str
    mSpellTags: list[str]
    mEffectAmount: list[SpellEffectAmount]
    mDataValues: list[SpellDataValue]
    m_0xfb56608c: dict[Hash, SpellDataValueVector]
    mSpellCalculations: dict[Hash, Optional[IGameCalculation]]
    mCoefficient: float
    mCoefficient2: float
    mAlternateSpellAssets: list[AlternateSpellAssets]
    mAnimationName: str
    mAnimationLoopName: str
    mAnimationWinddownName: str
    mAnimationLeadOutName: str
    mImgIconName: list[str]
    mMinimapIconName: str
    mKeywordWhenAcquired: str
    mCastTime: float
    mChannelDuration: list[float]
    CooldownTime: list[float]
    DelayCastOffsetPercent: float
    DelayTotalTimePercent: float
    mPreCastLockoutDeltaTime: float
    mPreCastLockoutDeltaTimeData: Optional[SpellLockDeltaTimeData]
    mPostCastLockoutDeltaTime: float
    mPostCastLockoutDeltaTimeData: Optional[SpellLockDeltaTimeData]
    mStartCooldown: float
    mCastRangeGrowthMax: list[float]
    mCastRangeGrowthStartTime: list[float]
    mCastRangeGrowthDuration: list[float]
    mChargeUpdateInterval: float
    mCancelChargeOnRecastTime: float
    m_0x3d746f1f: UInt8
    m_0x1632f6fc: list[Optional[SpellPassiveData]]
    mCharacterPassiveBuffs: list[CharacterPassiveData]
    mMaxAmmo: list[Int32]
    mAmmoUsed: list[Int32]
    mAmmoRechargeTime: list[float]
    mIsDelayedByCastLocked: bool
    mAmmoNotAffectedByCdr: bool
    mCooldownNotAffectedByCdr: bool
    mAmmoCountHiddenInUi: bool
    mCostAlwaysShownInUi: bool
    m_0x9fb86dc4: bool
    CannotBeSuppressed: bool
    CanCastWhileDisabled: bool
    mCanTriggerChargeSpellWhileDisabled: bool
    CanCastOrQueueWhileCasting: bool
    CanOnlyCastWhileDisabled: bool
    mCantCancelWhileWindingUp: bool
    m_0x7e3432a0: bool
    mCantCancelWhileChanneling: bool
    CantCastWhileRooted: bool
    mChannelIsInterruptedByDisables: bool
    mChannelIsInterruptedByAttacking: bool
    mApplyAttackDamage: bool
    mApplyAttackEffect: bool
    mApplyMaterialOnHitSound: bool
    mDoesntBreakChannels: bool
    mBelongsToAvatar: bool
    mIsDisabledWhileDead: bool
    CanOnlyCastWhileDead: bool
    mCursorChangesInGrass: bool
    mCursorChangesInTerrain: bool
    mProjectTargetToCastRange: bool
    mSpellRevealsChampion: bool
    mUseMinimapTargeting: bool
    CastRangeUseBoundingBoxes: bool
    mMinimapIconRotation: bool
    mUseChargeChanneling: bool
    mCanMoveWhileChanneling: bool
    mDisableCastBar: bool
    mShowChannelBar: bool
    AlwaysSnapFacing: bool
    UseAnimatorFramerate: bool
    bHaveHitEffect: bool
    bHaveHitBone: bool
    bIsToggleSpell: bool
    mDoNotNeedToFaceTarget: bool
    mTurnSpeedScalar: float
    mNoWinddownIfCancelled: bool
    mIgnoreRangeCheck: bool
    mOrientRadiusTextureFromPlayer: bool
    mOverrideAttackTime: Optional[OverrideAttackTimeData]
    mUseAutoattackCastTimeData: Optional[UseAutoattackCastTimeData]
    mIgnoreAnimContinueUntilCastFrame: bool
    mHideRangeIndicatorWhenCasting: bool
    mUpdateRotationWhenCasting: bool
    mPingableWhileDisabled: bool
    mConsideredAsAutoAttack: bool
    mDoesNotConsumeMana: bool
    mDoesNotConsumeCooldown: bool
    mLockedSpellOriginationCastId: bool
    m_0x898fbad4: bool
    mMinimapIconDisplayFlag: UInt16
    CastRange: list[float]
    CastRangeDisplayOverride: list[float]
    CastRadius: list[float]
    CastRadiusSecondary: list[float]
    CastConeAngle: float
    CastConeDistance: float
    CastTargetAdditionalUnitsRadius: float
    LuaOnMissileUpdateDistanceInterval: float
    mMissileSpec: Optional[MissileSpecification]
    mCastType: UInt32
    CastFrame: float
    MissileSpeed: float
    mMissileEffectKey: Hash
    mMissileEffectName: str
    mMissileEffectPlayerKey: Hash
    mMissileEffectPlayerName: str
    mMissileEffectEnemyKey: Hash
    mMissileEffectEnemyName: str
    mLineWidth: float
    mLineDragLength: float
    mLookAtPolicy: UInt32
    mHitEffectOrientType: UInt32
    mHitBoneName: str
    mResourceResolvers: list[Link[ResourceResolver]]
    mHitEffectKey: Hash
    mHitEffectName: str
    mHitEffectPlayerKey: Hash
    mHitEffectPlayerName: str
    mAfterEffectKey: Hash
    mAfterEffectName: str
    mParticleStartOffset: Vec3
    mFloatVarsDecimals: list[Int32]
    Mana: list[float]
    ManaUiOverride: list[float]
    SelectionPriority: UInt32
    mVoEventCategory: str
    mAiData: AiSpellData
    mSpellCooldownOrSealedQueueThreshold: Optional[float]
    m_0x03f432a6: UInt8
    mClientData: SpellDataResourceClient
    m_0x00f7e5bc: bool
    m_0x39381720: bool
    m_0xa8eb09d1: bool
    m_0x24b763c2: bool
    mTargetingTypeData: Optional[TargetingTypeData]
    pass

@MetaClass
class SpellPassiveData(MetaBase):
    mBuff: Link[SpellObject]
    m_0x8692e24a: UInt32
    m_0x76b67bcc: bool
    m_0xcbdf3af2: bool
    m_0xf862632b: bool
    m_0x7aa0fed6: bool
    mDisplayFlags: UInt8
    pass

@MetaClass
class CustomTargeterDefinitions(MetaBase):
    mTargeterDefinitions: list[Optional[TargeterDefinition]]
    pass

@MetaClass
class SpellDataResourceClient(MetaBase):
    m_0x375656dd: Hash
    m_0x7d4a0e6e: Hash
    mTooltipData: Optional[TooltipInstanceSpell]
    mSpawningUiDefinition: Optional[SpawningUiDefinition]
    mTargeterDefinitions: list[Optional[TargeterDefinition]]
    mCustomTargeterDefinitions: dict[Hash, CustomTargeterDefinitions]
    mMissileTargeterDefinitions: list[Optional[MissileAttachedTargetingDefinition]]
    mLeftClickSpellAction: UInt32
    mRightClickSpellAction: UInt32
    pass

@MetaClass
class SpawningUiDefinition(MetaBase):
    BuffNameFilter: str
    MaxNumberOfUnits: Int32
    pass

@MetaClassEmpty
class Rscript(MetaBase):
    pass

@MetaClass
class LolSpellScript(Rscript):
    GlobalProperties: ScriptGlobalProperties
    Sequences: dict[Hash, ScriptSequence]
    CustomSequences: dict[str, ScriptSequence]
    PreloadData: LolSpellPreloadData
    pass

@MetaClassEmpty
class IScriptPreload(MetaBase):
    pass

@MetaClass
class ScriptPreloadCharacter(MetaBase):
    PreloadResourceName: str
    pass

@MetaClass
class ScriptPreloadSpell(MetaBase):
    PreloadResourceName: str
    pass

@MetaClass
class ScriptPreloadModule(MetaBase):
    PreloadResourceName: str
    pass

@MetaClass
class ScriptPreloadParticle(MetaBase):
    PreloadResourceName: str
    pass

@MetaClass
class LolSpellPreloadData(MetaBase):
    CharacterPreloads: list[Optional[ScriptPreloadCharacter]]
    SpellPreloads: list[Optional[ScriptPreloadSpell]]
    ModulePreloads: list[Optional[ScriptPreloadModule]]
    ParticlePreloads: list[Optional[ScriptPreloadParticle]]
    pass

@MetaClass
class ScriptGlobalProperties(MetaBase):
    OnPreDamagePriority: Int32
    DeathEventType: UInt32
    CastTime: float
    ChannelDuration: float
    BuffName: str
    BuffTextureName: str
    DisplayName: str
    AutoBuffActivateEffects: list[str]
    AutoBuffActivateAttachBoneNames: list[str]
    PersistsThroughDeath: bool
    NonDispellable: bool
    IsDeathRecapSource: bool
    IsItemToggled: bool
    SpellToggleSlot: UInt32
    SpellFxOverrideSkins: list[str]
    SpellVoOverrideSkins: list[str]
    PopupMessages: list[str]
    pass

@MetaClassEmpty
class ScriptTable(MetaBase):
    pass

@MetaClassEmpty
class InstanceVarsTable(ScriptTable):
    pass

@MetaClassEmpty
class CharacterVarsTable(ScriptTable):
    pass

@MetaClassEmpty
class NextBuffVarsTable(ScriptTable):
    pass

@MetaClassEmpty
class WorldVarsTable(ScriptTable):
    pass

@MetaClassEmpty
class AvatarVarsTable(ScriptTable):
    pass

@MetaClassEmpty
class NextSpellVarsTable(ScriptTable):
    pass

@MetaClassEmpty
class TempTable1Table(ScriptTable):
    pass

@MetaClassEmpty
class TempTable2Table(ScriptTable):
    pass

@MetaClassEmpty
class TempTable3Table(ScriptTable):
    pass

@MetaClassEmpty
class ILineIndicatorType(MetaBase):
    pass

@MetaClassEmpty
class IndicatorTypeLocal(ILineIndicatorType):
    pass

@MetaClass
class IndicatorTypeGlobal(ILineIndicatorType):
    mIsFloating: bool
    pass

@MetaClassEmpty
class ITargeterFadeBehavior(MetaBase):
    pass

@MetaClass
class FadeOverTimeBehavior(ITargeterFadeBehavior):
    mTimeStart: float
    mTimeEnd: float
    mStartAlpha: float
    mEndAlpha: float
    pass

@MetaClass
class FadeByMouseRangeBehavior(ITargeterFadeBehavior):
    m_0x76a72ad1: float
    m_0x65183440: float
    mStartAlpha: float
    mEndAlpha: float
    pass

@MetaClass
class FadeToExplicitValueBehavior(ITargeterFadeBehavior):
    mAlpha: float
    pass

@MetaClass
class t_0x29dfd7ad(MetaBase):
    m_0xaeebcbdd: float
    m_0xa8a2f6c7: float
    m_0x64e4f9f9: float
    pass

@MetaClass
class FloatPerSpellLevel(MetaBase):
    mPerLevelValues: list[float]
    mValueType: UInt32
    pass

@MetaClass
class DrawablePositionLocator(MetaBase):
    BasePosition: UInt32
    DistanceOffset: float
    AngleOffsetRadian: float
    OrientationType: UInt32
    pass

@MetaClass
class TargeterDefinition(MetaBase):
    mFadeBehavior: Optional[ITargeterFadeBehavior]
    pass

@MetaClass
class TargeterDefinitionAoe(TargeterDefinition):
    CenterLocator: DrawablePositionLocator
    TextureOrientation: UInt32
    IsConstrainedToRange: bool
    ConstraintPosLocator: DrawablePositionLocator
    ConstraintRange: FloatPerSpellLevel
    OverrideRadius: FloatPerSpellLevel
    m_0x2acbb00b: t_0x29dfd7ad
    TextureRadiusOverrideName: str
    pass

@MetaClass
class TargeterDefinitionArc(TargeterDefinition):
    StartLocator: DrawablePositionLocator
    EndLocator: DrawablePositionLocator
    IsClockwiseArc: bool
    IsConstrainedToRange: bool
    ConstraintRange: FloatPerSpellLevel
    OverrideRadius: FloatPerSpellLevel
    TextureArcOverrideName: str
    ThicknessOffset: float
    pass

@MetaClass
class TargeterDefinitionCone(TargeterDefinition):
    StartLocator: DrawablePositionLocator
    EndLocator: DrawablePositionLocator
    FallbackDirection: UInt32
    HasMaxGrowRange: bool
    ConeFollowsEnd: bool
    ConeAngleDegrees: Optional[float]
    ConeRange: Optional[float]
    RangeGrowthStartTime: FloatPerSpellLevel
    RangeGrowthDuration: FloatPerSpellLevel
    RangeGrowthMax: FloatPerSpellLevel
    TextureConeOverrideName: str
    TextureConeMaxGrowName: str
    pass

@MetaClass
class TargeterDefinitionLine(TargeterDefinition):
    IndicatorType: Optional[ILineIndicatorType]
    StartLocator: DrawablePositionLocator
    EndLocator: DrawablePositionLocator
    FallbackDirection: UInt32
    AlwaysDraw: bool
    HasMaxGrowRange: bool
    UseGlobalLineIndicator: bool
    LineStopsAtEndPosition: Optional[bool]
    MinimumDisplayedRange: float
    ArrowSize: float
    LineWidth: FloatPerSpellLevel
    OverrideBaseRange: FloatPerSpellLevel
    RangeGrowthStartTime: FloatPerSpellLevel
    RangeGrowthDuration: FloatPerSpellLevel
    RangeGrowthMax: FloatPerSpellLevel
    TextureBaseOverrideName: str
    TextureTargetOverrideName: str
    TextureBaseMaxGrowName: str
    TextureTargetMaxGrowName: str
    mAngleLineToEndpointHeight: bool
    mCenterArrowToEndPoint: bool
    FacingLine: bool
    MinAngleRangeFactor: float
    MaxAngleRangeFactor: float
    Fade: bool
    MinAngle: float
    MaxAngle: float
    FadeAngle: float
    pass

@MetaClass
class TargeterDefinitionMinimap(TargeterDefinition):
    CenterLocator: DrawablePositionLocator
    UseCasterBoundingBox: Optional[bool]
    OverrideBaseRange: FloatPerSpellLevel
    pass

@MetaClass
class TargeterDefinitionRange(TargeterDefinition):
    CenterLocator: DrawablePositionLocator
    TextureOrientation: UInt32
    HideWithLineIndicator: bool
    HasMaxGrowRange: bool
    UseCasterBoundingBox: Optional[bool]
    OverrideBaseRange: FloatPerSpellLevel
    RangeGrowthStartTime: FloatPerSpellLevel
    RangeGrowthDuration: FloatPerSpellLevel
    RangeGrowthMax: FloatPerSpellLevel
    TextureOverrideName: str
    TextureMaxGrowName: str
    pass

@MetaClass
class TargeterDefinitionWall(TargeterDefinition):
    CenterLocator: DrawablePositionLocator
    WallOrientation: UInt32
    WallRotation: float
    Thickness: FloatPerSpellLevel
    Length: FloatPerSpellLevel
    TextureWallOverrideName: str
    pass

@MetaClass
class TargeterDefinitionMultiAoe(TargeterDefinition):
    CenterLocator: DrawablePositionLocator
    OverrideAoeRadius: FloatPerSpellLevel
    OverrideMinCastRange: FloatPerSpellLevel
    OverrideMaxCastRange: FloatPerSpellLevel
    AngelOffsetRadian: float
    NumOfInnerAoe: UInt32
    LeftTextureName: str
    RightTextureName: str
    InnerTextureName: str
    pass

@MetaClass
class TargeterDefinitionSpline(TargeterDefinition):
    StartLocator: DrawablePositionLocator
    EndLocator: DrawablePositionLocator
    BaseTextureName: str
    FrontTextureName: str
    SplineWidth: FloatPerSpellLevel
    OverrideSpline: Optional[ISplineInfo]
    MinSegmentCount: UInt32
    MaxSegmentLength: float
    IsConstrainedToRange: bool
    ConstraintRange: FloatPerSpellLevel
    pass

@MetaClass
class TargeterDefinitionSkipTerrain(TargeterDefinition):
    mStartLocator: DrawablePositionLocator
    mEndLocator: DrawablePositionLocator
    mFallbackDirection: UInt32
    mBaseTextureName: str
    mTerrainTextureName: str
    mTargetTextureName: str
    mTargetTextureRadius: float
    pass

@MetaClassEmpty
class TargetingTypeData(MetaBase):
    pass

@MetaClassEmpty
class Self(TargetingTypeData):
    pass

@MetaClass
class Target(TargetingTypeData):
    m_0x6f92d6b3: bool
    pass

@MetaClassEmpty
class Area(TargetingTypeData):
    pass

@MetaClassEmpty
class Cone(TargetingTypeData):
    pass

@MetaClassEmpty
class SelfAoe(TargetingTypeData):
    pass

@MetaClassEmpty
class TargetOrLocation(TargetingTypeData):
    pass

@MetaClassEmpty
class Location(TargetingTypeData):
    pass

@MetaClassEmpty
class Direction(TargetingTypeData):
    pass

@MetaClassEmpty
class DragDirection(TargetingTypeData):
    pass

@MetaClassEmpty
class LineTargetToCaster(TargetingTypeData):
    pass

@MetaClassEmpty
class AreaClamped(TargetingTypeData):
    pass

@MetaClassEmpty
class LocationClamped(TargetingTypeData):
    pass

@MetaClassEmpty
class TerrainLocation(TargetingTypeData):
    pass

@MetaClass
class TerrainType(TargetingTypeData):
    mBrushCursor: CursorData
    mRiverCursor: CursorData
    mWallCursor: CursorData
    pass

@MetaClass
class StatFormulaData(MetaBase):
    StatComponents: dict[UInt8, float]
    pass

@MetaClass
class StatFormulaDataList(MetaBase):
    StatFormulas: dict[UInt8, StatFormulaData]
    pass

@MetaClass
class GameModeDefaultStats(MetaBase):
    DefaultCharacterStats: StatFormulaDataList
    pass

@MetaClassEmpty
class TftSurrenderCheat(Cheat):
    pass

@MetaClassEmpty
class TftChangeDamageSkinCheat(Cheat):
    pass

@MetaClassEmpty
class SkinnedMeshDataMaterialController(MetaBase):
    pass

@MetaClassEmpty
class TftItemMaterialController(SkinnedMeshDataMaterialController):
    pass

@MetaClass
class TftMapCharacterRecordData(MetaBase):
    Tier: UInt8
    pass

@MetaClass
class TftMapCharacterSkinData(MetaBase):
    SquareIconTexturePath: str
    pass

@MetaClass
class TftMapCharacterData(MetaBase):
    Name: str
    SkinData: list[TftMapCharacterSkinData]
    CharData: list[TftMapCharacterRecordData]
    pass

@MetaClass
class TftMapCharacterList(MetaBase):
    ListName: str
    Characters: list[TftMapCharacterData]
    pass

@MetaClass
class TftMapCharacterLists(MetaBase):
    MapName: str
    CharacterLists: list[TftMapCharacterList]
    pass

@MetaClass
class TftAnnouncementData(MetaBase):
    m_0x8b7d190d: Hash
    mIconPath: str
    mTitleTra: str
    mDelay: float
    mDuration: float
    pass

@MetaClass
class TftAttachmentSlotStyleData(MetaBase):
    mName: str
    mOverlayIconPath: str
    mSubtextTra: str
    pass

@MetaClass
class TftCharacterRecord(CharacterRecord):
    PortraitIcon: str
    Tier: UInt8
    mLinkedTraits: list[TftTraitContributionData]
    m_0x2cddddbb: UInt8
    m_0x8d30a918: UInt8
    mMoveInterval: float
    mMoveProximity: float
    mMoveRange: float
    mMoveHeight: float
    mInitialMana: float
    m_0x7cbc4762: float
    mShopData: Link[TftShopData]
    m_0x4e28a666: str
    m_0xd9439003: Vec3
    m_0x4a52410b: bool
    m_0xef57098f: bool
    m_0x1f16e793: bool
    m_0xe1562ee7: bool
    pass

@MetaClass
class TftDragData(MetaBase):
    mHoldToHover: bool
    mHoldToDrag: bool
    m_0x44ab329e: bool
    m_0xd1296e95: float
    m_0x6d90172b: float
    m_0x59129cbe: float
    m_0xe2567252: float
    mDragBlendTime: float
    mDragPickupHeight: float
    mDragPickupDuration: float
    mDragReleaseDuration: float
    mDragOvershootDuration: float
    mDragOvershootHeight: float
    mDragSoundEvent: str
    mDropSoundEvent: str
    pass

@MetaClass
class TftDropRates(MetaBase):
    mDropRatesByTier: list[float]
    pass

@MetaClass
class t_0xf260c3ae(MetaBase):
    mDropRatesByLevel: list[TftDropRates]
    pass

@MetaClass
class TftEffectAmount(MetaBase):
    Name: Hash
    Value: float
    FormatString: str
    pass

@MetaClass
class TftItemComposition(MetaBase):
    mComponents: list[Link[TftItemData]]
    pass

@MetaClass
class TftItemData(MetaBase):
    mId: Int32
    mName: str
    mBuffName: str
    mComposition: list[Link[TftItemData]]
    m_0xa3ac84d8: list[TftItemComposition]
    EffectAmounts: list[TftEffectAmount]
    m_0x6752c795: list[Link[TftTraitData]]
    mIsUnique: bool
    ItemTags: list[Hash]
    mDisplayNameTra: str
    mDescriptionNameTra: str
    mIconPath: str
    mColor: Optional[Color]
    m_0x91d75dff: Vec2
    mVfxSystem: Link[VfxSystemDefinitionData]
    m_0x6d8fceed: Int32
    pass

@MetaClass
class TftItemList(MetaBase):
    mItems: list[Link[TftItemData]]
    VfxResourceResolver: Link[ResourceResolver]
    pass

@MetaClass
class t_0x3604b3e3(MetaBase):
    m_0x79dafa57: UInt32
    m_0x0ae9687e: float
    pass

@MetaClass
class TftModeData(MetaBase):
    mDefaultSetData: Link[TftSetData]
    mDragData: TftDragData
    mMobileDragData: TftDragData
    m_0x3caeb7b4: float
    m_0x4a191241: Link[TftBotLoadoutConfiguration]
    mTftMapSkinDefault: Hash
    mTftDamageSkinDefault: Hash
    mDefaultTftCompanion: Hash
    mTutorialTftCompanion: Hash
    m_0xb75a7951: float
    m_0x12aaf1d8: list[Hash]
    m_0x0e13c7aa: list[t_0x3604b3e3]
    pass

@MetaClass
class TftGameVariationData(MetaBase):
    mName: str
    mStageIconPath: str
    mTooltipIconPath: str
    mTooltipDescriptionTra: str
    mTooltipTitleTra: str
    mAnnouncementData: Link[TftAnnouncementData]
    pass

@MetaClass
class TftNotificationData(MetaBase):
    mName: str
    mDurationSeconds: float
    mToplineTra: str
    mBottomlineTra: str
    mIconPath: str
    m_0x1e7fffb0: str
    m_0xde5be189: str
    m_0xa6874a6e: str
    pass

@MetaClass
class TftPhaseData(MetaBase):
    mEnabled: bool
    mDuration: float
    mDisplay: UInt32
    mLabel: str
    mAnnouncementData: Link[TftAnnouncementData]
    pass

@MetaClass
class TftRoundData(MetaBase):
    mName: str
    mDisplayNameTra: str
    mDescriptionTra: str
    mIconPath: str
    m_0xd20054c0: str
    m_0x304b0330: str
    m_0xf862cc05: str
    m_0xcb830e67: str
    mTftDamageSidewall: str
    m_0x4cb318cd: str
    mDefaultTooltipTra: str
    mStateTooltipsTra: dict[UInt32, str]
    mDraftArrival: TftPhaseData
    mDraft: TftPhaseData
    mDraftDeparture: TftPhaseData
    mPlanningArrival: TftPhaseData
    mPlanning: TftPhaseData
    mPlanningDeparture: TftPhaseData
    mCombatArrival: TftPhaseData
    mCombat: TftPhaseData
    mCombatDeparture: TftPhaseData
    mScriptData: dict[str, Optional[GameModeConstant]]
    pass

@MetaClass
class TftStageData(MetaBase):
    mRounds: list[Link[TftRoundData]]
    pass

@MetaClass
class TftSetData(MetaBase):
    TftGameType: UInt32
    Number: UInt32
    Mutator: str
    DebugCharacterLists: list[Link[MapCharacterList]]
    CharacterLists: list[Link[MapCharacterList]]
    ItemLists: list[Link[TftItemList]]
    m_0xf74504c0: list[Link[TftTraitList]]
    m_0x90183782: list[Link[t_0x369a22b9]]
    DropRateTables: dict[str, Link[t_0xf260c3ae]]
    UnitUpgrades: list[Link[TftUnitUpgradeData]]
    ScriptData: dict[str, Optional[GameModeConstant]]
    Stages: list[TftStageData]
    ScriptDataObjectLists: list[Link[ScriptDataObjectList]]
    VfxResourceResolver: Link[ResourceResolver]
    m_0x4e40838e: UInt32
    pass

@MetaClass
class TftShopData(MetaBase):
    mName: str
    mRarity: UInt8
    mDisplayNameTra: str
    mAbilityNameTra: str
    mDescriptionTra: str
    mPortraitIconPath: str
    mIconPath: str
    mMobileIconPath: str
    mMobileSmallIconPath: str
    pass

@MetaClass
class t_0x369a22b9(MetaBase):
    m_0x520398be: list[Link[TftShopData]]
    pass

@MetaClass
class TftStatData(MetaBase):
    mName: str
    mType: UInt32
    mContext: UInt32
    mLifetime: UInt32
    m_0x0f3a339c: Int32
    pass

@MetaClass
class TftStreak(MetaBase):
    mMinimumStreakLength: Optional[UInt32]
    mMaximumStreakLength: Optional[UInt32]
    mGoldRewardAmount: UInt32
    mStreakFormat: str
    pass

@MetaClass
class TftStreakData(MetaBase):
    m_0xc3f540ed: list[TftStreak]
    mLossStreaks: list[TftStreak]
    pass

@MetaClass
class TftTraitContributionData(MetaBase):
    TraitData: Link[TftTraitData]
    Amount: Int32
    m_0xa91037f5: bool
    pass

@MetaClass
class TftTraitSetData(MetaBase):
    mMinUnits: UInt32
    mMaxUnits: Optional[UInt32]
    m_0xa8c51db0: Optional[UInt32]
    mTeamToBuff: UInt8
    mTargetStrategy: UInt8
    mStyle: UInt8
    mBuffName: str
    mActivatedBuffName: str
    EffectAmounts: list[TftEffectAmount]
    pass

@MetaClass
class TftTraitData(MetaBase):
    mName: str
    mTraitSets: list[TftTraitSetData]
    mDisplayNameTra: str
    mUnitSectionTra: str
    mDescriptionNameTra: str
    mDisplayNameIcon: str
    mIconPath: str
    pass

@MetaClass
class TftTraitList(MetaBase):
    mTraits: list[Link[TftTraitData]]
    VfxResourceResolver: Link[ResourceResolver]
    pass

@MetaClass
class TftUnitUpgradeData(MetaBase):
    Name: str
    m_0xd6debdbe: UInt8
    pass

@MetaClass
class TftHudAnnouncementData(MetaBase):
    mSceneTransitionIn: HudMenuTransitionData
    mSceneTransitionOut: HudMenuTransitionData
    pass

@MetaClass
class TftHudCombatRecapData(MetaBase):
    mPanelTransition: HudMenuTransitionData
    m_0x4544719b: float
    pass

@MetaClass
class TftHudNotificationsData(MetaBase):
    mSceneTransitionIn: HudMenuTransitionData
    mSceneTransitionOut: HudMenuTransitionData
    pass

@MetaClass
class t_0xda3c6dc6(MetaBase):
    mSceneTransitionIn: HudMenuTransitionData
    mSceneTransitionOut: HudMenuTransitionData
    pass

@MetaClass
class TftHudScoreboardData(MetaBase):
    m_0x840f5062: float
    m_0x254c8137: float
    m_0xf504817a: float
    pass

@MetaClass
class TftHudStageData(MetaBase):
    m_0xa11246b8: float
    pass

@MetaClass
class TftHudUnitShopData(MetaBase):
    m_0x88606883: float
    m_0xc38c6ba9: float
    pass

@MetaClass
class TftHudMobileDownscaleData(MetaBase):
    m_0xd4d2ea52: float
    mDownscale: float
    pass

@MetaClass
class TftHudTunables(MetaBase):
    mAnnouncementData: TftHudAnnouncementData
    mCombatRecapData: TftHudCombatRecapData
    mNotificationsData: TftHudNotificationsData
    mScoreboardData: TftHudScoreboardData
    mStageData: TftHudStageData
    m_0x249fe588: HudMenuTransitionData
    mMobileDownscaleData: TftHudMobileDownscaleData
    mUnitShopData: TftHudUnitShopData
    mZoomTransitionData: t_0xda3c6dc6
    pass

@MetaClass
class t_0x2610e5a7(MetaBase):
    m_0xfa144e3e: Hash
    ItemIcon: Hash
    m_0x817805a3: Hash
    m_0x5cdf1384: Hash
    m_0xbdcceafd: Hash
    m_0x14541cac: Hash
    m_0xa768acad: Hash
    m_0x7af87ddd: Hash
    m_0x791b47a2: Hash
    m_0x30145a7e: Hash
    pass

@MetaClass
class ViewController(MetaBase):
    m_0xb79c86ae: Link[ViewController]
    pass

@MetaClass
class t_0x9e2b8a86(ViewController):
    m_0x41aa9616: UInt32
    m_0x143e4d96: UInt32
    m_0xeac10e8a: str
    m_0x8b76c33f: str
    m_0x073ce2a6: str
    m_0x3ad4379e: str
    m_0x8ff1b151: str
    m_0xf7ee4522: str
    m_0x4babd89d: Hash
    m_0xf5b8026a: Hash
    m_0x0c5c5ca0: Hash
    m_0xf2024d92: t_0x2610e5a7
    m_0x4d302530: Hash
    m_0x5b308567: Hash
    m_0x9dcf971d: Hash
    m_0xba1d038c: float
    m_0x75f9cc79: Hash
    pass

@MetaClass
class TftGameStartViewController(ViewController):
    m_0x81317ee6: Hash
    m_0xfc59b058: Hash
    m_0xf6a44ab6: Hash
    m_0x56b85896: float
    m_0x14713b68: float
    m_0x87f66219: float
    pass

@MetaClass
class t_0x1be092ec(MetaBase):
    Group: Hash
    m_0x1c6536a1: Hash
    m_0x5abac352: Hash
    m_0x7748a39f: Hash
    m_0x4f02b933: Hash
    PlusIcon: Hash
    m_0xcd880326: Hash
    m_0xc67f5ef5: Hash
    pass

@MetaClass
class t_0xb5e27400(MetaBase):
    Group: Hash
    m_0x05dd34f6: Hash
    m_0x2f0c1d34: Hash
    m_0x868e69a1: Hash
    m_0xecb8bd25: Hash
    pass

@MetaClass
class t_0x43c3d118(ViewController):
    m_0x38e9f9ec: Int32
    m_0x39e9fb7f: Int32
    m_0xa05cacaa: str
    m_0x1257d9a3: str
    m_0xaf939497: Hash
    m_0xe5e1d1d7: Hash
    m_0xa1a15b6f: Hash
    m_0x92831268: t_0xb5e27400
    m_0x0aad6573: t_0x1be092ec
    Scene: Hash
    pass

@MetaClass
class t_0x2781ed6b(MetaBase):
    TitleKey: str
    BodyKey: str
    pass

@MetaClass
class TftUnitShopViewController(ViewController):
    m_0xa0ae7cfa: Hash
    m_0xc43a3d1f: float
    ToggleShopButton: Hash
    LockButton: Hash
    BuyExpButton: Hash
    RerollButton: Hash
    InfoButton: Hash
    m_0x2781ed6b: dict[UInt32, t_0x2781ed6b]
    pass

@MetaClass
class ObjectTags(MetaBase):
    mTagList: str
    pass

@MetaClass
class NumberFormattingBehavior(MetaBase):
    m_0x6a015824: UInt32
    m_0x9892a348: bool
    m_0x35feae85: bool
    pass

@MetaClass
class NumberFormattingData(MetaBase):
    m_0x5b862d47: str
    m_0xd183213b: str
    m_0xb995fb1f: str
    m_0x40f5bd16: str
    m_0xedd8ea83: str
    m_0x31169dff: str
    m_0xe4f5bdce: str
    m_0x012de6ec: str
    m_0x70177bf1: str
    m_0xb0c63265: str
    m_0x89a709fb: str
    m_0xf3ee8811: str
    m_0xef853971: str
    m_0xfd7c73b7: str
    m_0xdd2fcd42: str
    m_0xc3310cda: str
    m_0x7a4d89bb: dict[Hash, Link[NumberFormattingBehavior]]
    pass

@MetaClass
class AnnouncementDefinitionData(MetaBase):
    Priority: UInt16
    CanBeMadeObsolete: bool
    MakeLowerPriorityEventsObsolete: bool
    Style: Link[AnnouncementStyleBasic]
    TextKey: str
    ChatMessageKey: str
    SoundKey: str
    SpectatorSoundKey: str
    CommonElements: Hash
    AlliedElements: Hash
    EnemyElements: Hash
    pass

@MetaClass
class AnnouncementDefinition(MetaBase):
    DefaultData: AnnouncementDefinitionData
    MutatorOverrides: dict[str, AnnouncementDefinitionData]
    pass

@MetaClassEmpty
class t_0x78387eb5(AnnouncementDefinition):
    pass

@MetaClass
class AnnouncementStyleBasic(MetaBase):
    TextField: Hash
    MinAnnouncementDuration: float
    m_0x3f43172e: HudMenuTransitionData
    m_0xcc99a2db: HudMenuTransitionData
    pass

@MetaClass
class t_0x48c9ff38(AnnouncementStyleBasic):
    SourceIcon: Link[AnnouncementIcon]
    pass

@MetaClass
class t_0xaa95a271(AnnouncementStyleBasic):
    LeftIcon: Link[AnnouncementIcon]
    RightIcon: Link[AnnouncementIcon]
    pass

@MetaClass
class AnnouncementIcon(MetaBase):
    m_0x108e8710: Hash
    m_0xc2e2a2df: Hash
    m_0x3e37c63b: Hash
    AlliedElementGroup: Hash
    EnemyElementGroup: Hash
    m_0xdd749512: Hash
    m_0xde7496a5: Hash
    m_0xdb7491ec: Hash
    m_0xdc74937f: Hash
    pass

@MetaClass
class AnnouncementMap(MetaBase):
    ParentList: Link[AnnouncementMap]
    m_0x81082e4b: str
    m_0x79175e85: Hash
    m_0xcf8c591b: Hash
    Announcements: dict[str, Link[AnnouncementDefinition]]
    pass

@MetaClass
class AnnouncementsViewController(ViewController):
    m_0x34b17566: Hash
    pass

@MetaClass
class InvalidDeviceViewController(ViewController):
    Scene: Hash
    pass

@MetaClassEmpty
class LoginViewController(ViewController):
    pass

@MetaClass
class PatchingViewController(ViewController):
    Scene: Hash
    BeginPatchingButtonDefinition: Hash
    OpenTeamPlannerButtonDefinition: Hash
    pass

@MetaClass
class SummonerNameCreateViewController(ViewController):
    m_0x2992fe27: HudMenuTransitionData
    m_0x4d302530: Hash
    SubmitButtonDefinition: Hash
    m_0x315b9a19: Hash
    pass

@MetaClass
class t_0x13a37f3e(MetaBase):
    Group: Hash
    Icon: Hash
    m_0xbde64e3e: Hash
    m_0x43b27471: Hash
    m_0x7d3ef18b: list[Hash]
    m_0x2de82d6a: list[Hash]
    m_0xcea0af0e: list[Hash]
    pass

@MetaClass
class t_0x60764292(MetaBase):
    Group: Hash
    m_0x43b27471: Hash
    m_0xe83ed618: Hash
    m_0x84f92b5a: Hash
    pass

@MetaClass
class TftTeamPlannerViewController(ViewController):
    m_0x6ee3bd2e: float
    ViewPaneDefinition: ViewPaneDefinition
    m_0x374d847e: t_0x13a37f3e
    m_0x160a8b77: Hash
    m_0xad64dc55: t_0x60764292
    m_0x387116c1: Hash
    ChampionButtonTemplate: Hash
    m_0x88ca9d2d: Hash
    CloseButton: Hash
    m_0xc6e9fbea: Hash
    ChampionsPerRow: UInt8
    TraitsPerRow: UInt8
    Scene: Hash
    m_0x807ef97f: Hash
    pass

@MetaClass
class ChatViewController(ViewController):
    DefaultWordWrapMargin: UInt8
    HideAfterSeconds: float
    ViewPaneDefinition: ViewPaneDefinition
    SceneChat: Hash
    m_0x8284ebb3: Hash
    m_0xbc8c4eed: Hash
    pass

@MetaClass
class VfxProbabilityTableDataGrande(ViewController):
    Scene: Hash
    Backdrop: Hash
    AuthoredWidth: float
    SourceResolutionWidth: float
    pass

@MetaClass
class t_0x75259ad3(ViewController):
    CloseButtonDefinition: Hash
    ConfirmButtonDefinition: Hash
    CancelButtonDefinition: Hash
    ContentScene: Hash
    ViewPaneDefinition: Optional[ViewPaneDefinition]
    pass

@MetaClass
class MessageBoxDialog(t_0x75259ad3):
    m_0x131c35c5: Hash
    m_0x070020ab: Hash
    m_0x31dff863: Hash
    m_0x006fd80c: Hash
    m_0xab91ba1f: Hash
    m_0x315b9a19: Hash
    m_0x2992fe27: HudMenuTransitionData
    m_0x985233b8: t_0x63394a54
    m_0x1347d194: t_0x63394a54
    pass

@MetaClass
class t_0x5ce1431e(MetaBase):
    Scene: Hash
    m_0xd36508cd: Hash
    pass

@MetaClass
class CursorData(MetaBase):
    mHotSpot: Vec2
    mTextureName: str
    mColorblindTextureName: str
    m_0xd240ce4f: str
    m_0xf6536c51: str
    pass

@MetaClass
class CursorDataTeamContext(MetaBase):
    mData: list[CursorData]
    pass

@MetaClass
class CursorDataCaptureCooldownContext(MetaBase):
    mData: list[CursorData]
    pass

@MetaClass
class CursorConfig(MetaBase):
    mSingleContextCursors: list[CursorData]
    mTeamContextCursors: list[CursorDataTeamContext]
    mHoverNotUseableCursor: CursorDataCaptureCooldownContext
    pass

@MetaClassEmpty
class t_0x8cb19eb5(ViewController):
    pass

@MetaClass
class HealthbarImageInfo(MetaBase):
    mTextureName: str
    mOffset: Vec2
    mTextureUvs: Vec4
    pass

@MetaClass
class UnitStatusData(MetaBase):
    LocType: UInt32
    AttackableUnitStatusType: UInt32
    StatusName: str
    TextColor: Optional[Color]
    ImageInfo: HealthbarImageInfo
    pass

@MetaClass
class UnitStatusPriorityList(MetaBase):
    mPrioritizedUnitStatusData: list[UnitStatusData]
    mMinimumDisplayTime: float
    pass

@MetaClass
class FloatTextIconData(MetaBase):
    mIconFileName: str
    mColor: Color
    mDisplaySize: Vec2
    mOffset: Vec2
    mAlignment: UInt32
    pass

@MetaClass
class FloatTextDisplayOverrides(MetaBase):
    Priority: Optional[Int32]
    MaxInstances: Optional[Int32]
    IsAnimated: Optional[bool]
    DisableHorizontalReverse: Optional[bool]
    DisableVerticalReverse: Optional[bool]
    MomentumFromHit: Optional[bool]
    FollowSource: Optional[bool]
    IgnoreCombineRules: Optional[bool]
    IgnoreQueue: Optional[bool]
    AlternateRightLeft: Optional[bool]
    CombinableCounterDisplay: Optional[bool]
    CombinableCounterCategory: Optional[Int32]
    OverwritePreviousNumber: Optional[bool]
    ExtendTimeOnNewDamage: Optional[float]
    MaxLifeTime: Optional[float]
    ColorOffsetR: Optional[Int32]
    ColorOffsetG: Optional[Int32]
    ColorOffsetB: Optional[Int32]
    Decay: Optional[float]
    DecayDelay: Optional[float]
    Scale: Optional[float]
    ShrinkTime: Optional[float]
    ShrinkScale: Optional[float]
    HangTime: Optional[float]
    RandomOffsetMinX: Optional[float]
    RandomOffsetMaxX: Optional[float]
    RandomOffsetMinY: Optional[float]
    RandomOffsetMaxY: Optional[float]
    StartOffsetX: Optional[float]
    StartOffsetY: Optional[float]
    RelativeOffsetMin: Optional[float]
    RelativeOffsetMax: Optional[float]
    MinXVelocity: Optional[float]
    MaxXVelocity: Optional[float]
    MinYVelocity: Optional[float]
    MaxYVelocity: Optional[float]
    ContinualForceX: Optional[float]
    ContinualForceY: Optional[float]
    GrowthXScalar: Optional[float]
    GrowthYScalar: Optional[float]
    pass

@MetaClass
class FloatingTextTunables(MetaBase):
    mAnimatedTextQueueDelay: float
    mIntervalInPix: float
    mScrollSpeed: float
    mMaxFloatingTextItems: UInt32
    mMinimumDynamicScale: float
    mMaximumDynamicScale: float
    mYResolutionBaseline: float
    m_0xccf713a7: float
    m_0xf56f095c: float
    mMinionComparisonMultiplier: float
    mLocalPlayerHealthComparison: float
    mComparisonByLevel: list[float]
    pass

@MetaClass
class FloatingTextDamageDisplayTypeList(MetaBase):
    Default: Link[FloatTextDisplayOverrides]
    Impact: Link[FloatTextDisplayOverrides]
    Zone: Link[FloatTextDisplayOverrides]
    Ult: Link[FloatTextDisplayOverrides]
    DotNoCombine: Link[FloatTextDisplayOverrides]
    Dot: Link[FloatTextDisplayOverrides]
    DotSlow: Link[FloatTextDisplayOverrides]
    Multistrike: Link[FloatTextDisplayOverrides]
    MultistrikeFast: Link[FloatTextDisplayOverrides]
    MultistrikeSlow: Link[FloatTextDisplayOverrides]
    PlayerMinion: Link[FloatTextDisplayOverrides]
    BarrackMinion: Link[FloatTextDisplayOverrides]
    Mini: Link[FloatTextDisplayOverrides]
    SelfTrueDamageCounter: Link[FloatTextDisplayOverrides]
    SelfPhysicalDamageCounter: Link[FloatTextDisplayOverrides]
    SelfMagicalDamageCounter: Link[FloatTextDisplayOverrides]
    pass

@MetaClass
class FloatTextFormattingData(MetaBase):
    mTypeName: Hash
    Decay: float
    mFontDescription: Link[GameFontDescription]
    ColorOffsetR: Int32
    ColorOffsetG: Int32
    ColorOffsetB: Int32
    CombinableNumberFormat: str
    CombinableNegativeNumberFormat: str
    Priority: Int32
    Height: float
    DecayDelay: float
    Disabled: bool
    IsAnimated: bool
    MomentumFromHit: bool
    FollowSource: bool
    DisableHorizontalReverse: bool
    DisableVerticalReverse: bool
    CombinableCounterDisplay: bool
    OverwritePreviousNumber: bool
    CombinableCounterCategory: Int32
    MinXVelocity: float
    MaxXVelocity: float
    MinYVelocity: float
    MaxYVelocity: float
    StartOffsetX: float
    StartOffsetY: float
    HangTime: float
    RandomStartOffsetMinX: float
    RandomStartOffsetMaxX: float
    RandomStartOffsetMinY: float
    RandomStartOffsetMaxY: float
    GrowthYScalar: float
    GrowthXScalar: float
    RelativeOffsetMin: float
    RelativeOffsetMax: float
    ContinualForceX: float
    ContinualForceY: float
    ContinualForceXBase: float
    ContinualForceYBase: float
    ShrinkTime: float
    Scale: float
    ExtendTimeOnNewDamage: float
    MaxLifeTime: float
    IgnoreQueue: bool
    AlternateRightLeft: bool
    IgnoreCombineRules: bool
    MaxInstances: Int32
    ShrinkScale: float
    RefreshExisting: bool
    AttachToHealthBar: bool
    OffsetByBoundingBox: bool
    HorizontalAlignment: UInt8
    VerticalAlignment: UInt8
    Icons: list[FloatTextIconData]
    pass

@MetaClass
class FloatingTextTypeList(MetaBase):
    Invulnerable: Link[FloatTextFormattingData]
    Special: Link[FloatTextFormattingData]
    Heal: Link[FloatTextFormattingData]
    ManaHeal: Link[FloatTextFormattingData]
    ManaDamage: Link[FloatTextFormattingData]
    Dodge: Link[FloatTextFormattingData]
    PhysicalDamageCritical: Link[FloatTextFormattingData]
    MagicalDamageCritical: Link[FloatTextFormattingData]
    TrueDamageCritical: Link[FloatTextFormattingData]
    Experience: Link[FloatTextFormattingData]
    Gold: Link[FloatTextFormattingData]
    Level: Link[FloatTextFormattingData]
    Disable: Link[FloatTextFormattingData]
    QuestReceived: Link[FloatTextFormattingData]
    QuestComplete: Link[FloatTextFormattingData]
    Score: Link[FloatTextFormattingData]
    PhysicalDamage: Link[FloatTextFormattingData]
    MagicalDamage: Link[FloatTextFormattingData]
    TrueDamage: Link[FloatTextFormattingData]
    EnemyPhysicalDamage: Link[FloatTextFormattingData]
    EnemyMagicalDamage: Link[FloatTextFormattingData]
    EnemyTrueDamage: Link[FloatTextFormattingData]
    EnemyPhysicalDamageCritical: Link[FloatTextFormattingData]
    EnemyMagicalDamageCritical: Link[FloatTextFormattingData]
    EnemyTrueDamageCritical: Link[FloatTextFormattingData]
    Countdown: Link[FloatTextFormattingData]
    Omw: Link[FloatTextFormattingData]
    Absorbed: Link[FloatTextFormattingData]
    Debug: Link[FloatTextFormattingData]
    PracticeToolTotal: Link[FloatTextFormattingData]
    PracticeToolLastHit: Link[FloatTextFormattingData]
    PracticeToolDps: Link[FloatTextFormattingData]
    ScoreDarkStar: Link[FloatTextFormattingData]
    ScoreProject0: Link[FloatTextFormattingData]
    ScoreProject1: Link[FloatTextFormattingData]
    ShieldBonusDamage: Link[FloatTextFormattingData]
    TftUnitLabel: Link[FloatTextFormattingData]
    pass

@MetaClass
class FloatingTextGlobalConfig(MetaBase):
    mTunables: FloatingTextTunables
    mDamageDisplayTypes: FloatingTextDamageDisplayTypeList
    mFloatingTextTypes: FloatingTextTypeList
    pass

@MetaClass
class FloatingTextOverride(MetaBase):
    OverriddenFloatingTextTypes: dict[UInt32, bool]
    pass

@MetaClass
class HudColorData(MetaBase):
    mSelfColor: Color
    mFriendlyColor: Color
    mEnemyColor: Color
    mNeutralColor: Color
    mOrderColor: Color
    mChaosColor: Color
    mJunglePlantColor: Color
    mFriendlyLaneMinionBarColor: Color
    mEnemyLaneMinionBarColor: Color
    mDeathFriendlyTeamColor: Color
    mDeathEnemyTeamColor: Color
    mDeathOrderColor: Color
    mDeathChaosColor: Color
    mInputChatColor: Color
    mShadowChatColor: Color
    mFriendlyChatColor: Color
    mAllChatColor: Color
    mEnemyChatColor: Color
    mNeutralChatColor: Color
    mPingChatColor: Color
    mTeamChatColor: Color
    mNetworkChatColor: Color
    mOrderChatColor: Color
    mChaosChatColor: Color
    mGoldChatColor: Color
    mTimestampChatColor: Color
    mWhisperColor: Color
    mPartyChatColor: Color
    mPlatformChatColor: Color
    mFeedbackChatColor: Color
    mItemCalloutBodyColor: Color
    mItemCalloutItemColor: Color
    mMarkedIndicatorColor: Color
    mSelectedIndicatorColor: Color
    mHighlightedIndicatorColor: Color
    mItemHotKeyEnabledColor: Color
    mItemHotKeyDisabledColor: Color
    mSpellHotKeyEnabledColor: Color
    mSpellHotKeyDisabledColor: Color
    mStatNormalColor: Color
    mStatBoostedColor: Color
    mLevelUpColor: Color
    mEvolutionColor: Color
    mSummonerNameDeadColor: Color
    mSummonerNameDefaultColor: Color
    mSummonerNameSelfColor: Color
    mClubTagFriendlyChatColor: Color
    mClubTagEnemyChatColor: Color
    mClubTagNeutralChatColor: Color
    mClubTagOrderChatColor: Color
    mClubTagChaosChatColor: Color
    mVoiceChatDefaultTextColor: Color
    mVoiceChatHoverTextColor: Color
    mVoiceChatHaloTextureColor: Color
    m_0x03ca4e54: Color
    m_0xdfd9f7a0: Color
    m_0xd614aa57: Color
    VoteEmptyColor: Color
    m_0x51c13ad7: Color
    VoteNocolor: Color
    m_0x3f68efb8: Color
    m_0xcd9cb6c5: Color
    m_0xc14d71dc: Color
    m_0x9487808b: Color
    m_0x0fc46842: Color
    m_0x3b64dfe3: Color
    m_0x672ccd56: Color
    m_0x9316f661: list[Color]
    m_0x30c22182: Color
    m_0xee9a2886: Color
    m_0xc09ccdd8: Color
    m_0x24eb55a3: Color
    m_0x2f02af61: Color
    m_0xca1d9872: Color
    pass

@MetaClass
class HudFeedbackDamageData(MetaBase):
    mPercentageDamageForFlash: float
    mOverTimeForFlashSeconds: float
    mMaxPercentageForMostReadHealth: float
    mFlashDuration: float
    mStartFlashAlpha: float
    mLowHealthFlashThresholdPercentage: float
    mLowHealthFlashDuration: float
    mLowHealthFlashOpacityStrength: float
    pass

@MetaClass
class TeamScoreMeterUiTunables(MetaBase):
    mSceneTransition: HudMenuTransitionData
    mTeamScoreMeterProperties: list[HudTeamScoreMeterProperties]
    mTeamScoreMeterMaxRoundsPerTeam: UInt32
    mAllowDynamicVisibility: bool
    mCountdownTimer: bool
    m_0xdff2794f: UInt8
    pass

@MetaClass
class HudTeamScoreMeterProperties(MetaBase):
    mTeamScoreMeterType: UInt8
    mShowScoreText: bool
    m_0x86864fbc: str
    m_0x6044a790: str
    pass

@MetaClass
class EncounterUiTunables(MetaBase):
    mSceneTransition: HudMenuTransitionData
    mProgressBarEaseRate: float
    mProgressMeterSuffix: str
    mTimerMeterSuffix: str
    mUnitBarFadeSpeed: float
    m_0x3fc8ecec: bool
    mProgressMeterHoverText: str
    mProgressMeterPingText: str
    mPipsHoverText: str
    pass

@MetaClass
class QuestUiTunables(MetaBase):
    mSceneTransition: HudMenuTransitionData
    pass

@MetaClass
class DragonUiTunables(MetaBase):
    mSlots: UInt8
    mDragonBaseNames: list[str]
    pass

@MetaClass
class HudGameModeScoreData(MetaBase):
    mTeamScoreElementTypes: list[UInt8]
    mIndividualScoreElementTypes: list[UInt8]
    mModeKeyName: str
    mTeamGameScorePingMessage: str
    mTeamScoreMeterUi: Optional[TeamScoreMeterUiTunables]
    mEncounterUi: Optional[EncounterUiTunables]
    mTeamFightUi: Optional[HudTeamFightData]
    mQuestUi: Optional[QuestUiTunables]
    mDragonUi: Optional[DragonUiTunables]
    mOptionalBins: list[HudOptionalBinData]
    pass

@MetaClass
class MinimapIconTextureData(MetaBase):
    mBase: str
    mColorblind: Optional[str]
    pass

@MetaClass
class MinimapIconColorData(MetaBase):
    mBase: Color
    mColorblind: Optional[Color]
    pass

@MetaClass
class MinimapIcon(MetaBase):
    mRelativeTeams: bool
    mSize: Vec2
    mMinScale: float
    mMaxScale: float
    mBaseTexture: MinimapIconTextureData
    mTeamTextures: dict[UInt8, MinimapIconTextureData]
    mBaseColor: MinimapIconColorData
    mTeamColors: dict[UInt8, MinimapIconColorData]
    pass

@MetaClass
class MinimapData(MetaBase):
    mIcons: dict[UInt8, MinimapIcon]
    mCustomIcons: dict[Hash, MinimapIcon]
    pass

@MetaClass
class HudOptionalBinData(MetaBase):
    mName: str
    mPriority: UInt32
    pass

@MetaClass
class HudTunables(MetaBase):
    mScaleSettings: HudScaleSettingsData
    mLevelUpTransitionData: HudLevelUpData
    mReplayData: HudReplayData
    mElementalSelectionAnimationData: HudElementalSectionUiData
    mEmotePopupData: HudEmotePopupData
    mGearSelectionData: HudGearSelectionUiData
    mRadailWheelData: HudRadialWheelData
    mCheatMenuData: HudCheatMenuData
    mPingData: HudPingData
    mGameScoreboardTransitionData: HudMenuTransitionData
    mReplayScoreboardTransitionData: HudMenuTransitionData
    mReplayGameStatsTransitionData: HudMenuTransitionData
    m_0x9cec9ff0: HudBannerData
    m_0x4e7d3049: HudAbilityPromptData
    mVoiceChatData: HudVoiceChatData
    mInputBoxData: HudInputBoxData
    mHealthBarData: HudHealthBarData
    mLoadingScreenData: HudLoadingScreenData
    mStatPanelStatStoneData: HudStatPanelStatStoneData
    mStatStoneData: HudStatStoneData
    mStatStoneDeathRecapData: HudStatStoneDeathRecapData
    StatStoneMilestoneData: HudStatStoneMilestoneData
    mEndOfGameData: HudEndOfGameData
    m_0x86402adf: HudMessageDisplayData
    m_0x48c75042: HudMessageDisplayData
    mHudSpellSlotResetFeedbackData: HudSpellSlotResetFeedbackData
    DamageDisplayData: HudDamageDisplayData
    FightRecapUiData: HudFightRecapUiData
    pass

@MetaClass
class HudScaleSettingsData(MetaBase):
    MaximumGlobalScale: float
    MinimumGlobalScale: float
    MaximumMinimapScale: float
    MinimumMinimapScale: float
    m_0x6b8896b6: float
    m_0xb565cf40: float
    MaximumPracticeToolScale: float
    MinimumPracticeToolScale: float
    MaximumChatScale: float
    MinimumChatScale: float
    pass

@MetaClass
class HudLevelUpData(MetaBase):
    MinAlpha: UInt8
    MaxAlpha: UInt8
    MaxOffset: float
    AnimTime: float
    Delay: float
    Overshoot: float
    Inertia: float
    PlayerBuffsOffset: float
    IdleSheenInterval: float
    pass

@MetaClass
class HudBannerData(MetaBase):
    TransitionTime: float
    TransitionMinAlpha: UInt8
    TransitionMaxAlpha: UInt8
    TransitionOffset: Vec2
    PulseOffset: Vec2
    PulseTime: float
    PulseDuration: float
    PulseInterval: float
    pass

@MetaClass
class HudAbilityPromptData(MetaBase):
    PulseStartColor: Color
    PulseEndColor: Color
    PulseOffset: Vec2
    PulseTime: float
    PulseInterval: float
    pass

@MetaClass
class HudMenuTransitionData(MetaBase):
    TransitionTime: float
    MinAlpha: UInt8
    MaxAlpha: UInt8
    EasingType: UInt8
    pass

@MetaClass
class HudElementalSectionUiData(MetaBase):
    AirColoration: Color
    FireColoration: Color
    EarthColoration: Color
    WaterColoration: Color
    DarkColoration: Color
    FairyColoration: Color
    IceColoration: Color
    LightColoration: Color
    MagmaColoration: Color
    StormColoration: Color
    MeterFilledButtonFadeInDelay: float
    FirstSelectionAnimationDelay: float
    SecondSelectionAnimationDelay: float
    GlowingRingCycleTime: float
    pass

@MetaClass
class HudEmotePopupData(MetaBase):
    mEmotePopupTransitionIntro: HudMenuTransitionData
    mEmotePopupTransitionOutro: HudMenuTransitionData
    mUiSound: str
    mEmotePopupDisplayTime: float
    m_0x728d935f: float
    m_0x07cd0d83: float
    m_0x75d54c28: float
    m_0xf680b7d9: float
    m_0x6bd76883: float
    mEmoteFloatEnabled: bool
    pass

@MetaClass
class HudGearSelectionUiData(MetaBase):
    mGearSelectionTransitionIntro: HudMenuTransitionData
    mGearSelectionTransitionOutro: HudMenuTransitionData
    SelectionButtonDelayTime: float
    TimerEnabled: bool
    TimerCountdownDuration: float
    TimerCountdownWarningStart: float
    pass

@MetaClass
class HudRadialWheelData(MetaBase):
    mRadialWheelUiTransitionData: HudMenuTransitionData
    mRadialWheelButtonTransitionIntro: HudMenuTransitionData
    mRadialWheelButtonTransitionOutro: HudMenuTransitionData
    ActivateWheelDelayTime: float
    pass

@MetaClass
class HudTeamFightOffScreenDifferentiationData(MetaBase):
    m_0x40e3864f: float
    m_0x3f035ddd: float
    m_0x23086737: UInt8
    pass

@MetaClass
class HudTeamFightData(MetaBase):
    mSceneTransition: HudMenuTransitionData
    mStyleFlags: UInt32
    m_0xa7620c86: Optional[HudTeamFightOffScreenDifferentiationData]
    pass

@MetaClass
class HudReplayData(MetaBase):
    MessageVisibleTime: float
    TeamFightData: HudTeamFightData
    pass

@MetaClass
class HudCheatMenuData(MetaBase):
    TooltipDelay: float
    GroupDividerGapSize: float
    GroupDividerIndex: UInt8
    pass

@MetaClass
class HudPingData(MetaBase):
    DistanceToNotTrollPingCorpses: float
    TimeToNotTrollPingCorpses: float
    pass

@MetaClass
class HudVoiceChatData(MetaBase):
    HighlightTimeoutSeconds: float
    pass

@MetaClass
class HudInputBoxData(MetaBase):
    InputTextLengthMax: UInt8
    CaretAlphaMax: float
    CaretBlinkTime: float
    MarkedOffsetY: float
    MarkedLineSizePx: float
    SelectedOffsetY: float
    SelectedLineSizePx: float
    m_0xbeabf2d8: float
    pass

@MetaClass
class HudHealthBarBurstData(MetaBase):
    BurstTimeWindow: float
    BurstTriggerPercent: float
    FlashTriggerPercent: float
    FlashDuration: float
    ShakeDuration: float
    ShakeBox: Vec2
    ShakeReferenceResolution: Vec2
    ShakeTriggerPercent: float
    ShakeFrequency: float
    FadeSpeed: float
    FadeAcceleration: float
    FadeHoldTime: float
    pass

@MetaClass
class HudHealthBarFadeData(MetaBase):
    FadeSpeed: float
    FadeAcceleration: float
    FadeHoldTime: float
    pass

@MetaClass
class HudHealthBarDefenseModifierData(MetaBase):
    DefenseUpPercent: float
    DefenseDownL1Percent: float
    DefenseDownL2Percent: float
    DefenseDownL3Percent: float
    pass

@MetaClass
class HudHealthBarBurstHealData(MetaBase):
    HealTimeWindow: float
    HealTriggerPercent: float
    HealFadeDuration: float
    pass

@MetaClass
class HudHealthBarDefenseIconData(MetaBase):
    EnlargeTime: float
    EnlargeSize: float
    SettleTime: float
    pass

@MetaClass
class MicroTicksPerTickData(MetaBase):
    MinHealth: float
    MicroTicksBetween: UInt32
    pass

@MetaClass
class HudHealthBarProgressiveTickData(MetaBase):
    MicroTickPerTickData: list[MicroTicksPerTickData]
    HealthPerTick: float
    pass

@MetaClass
class HudHealthBarData(MetaBase):
    BurstData: HudHealthBarBurstData
    TowerBurstData: HudHealthBarBurstData
    BurstHealData: HudHealthBarBurstHealData
    ChampionProgressiveTickData: HudHealthBarProgressiveTickData
    FadeData: HudHealthBarFadeData
    DefenseModifierData: HudHealthBarDefenseModifierData
    DefenseIconData: HudHealthBarDefenseIconData
    UntargetableAlpha: float
    ResurrectingAlpha: float
    pass

@MetaClass
class HudSpellSlotResetFeedbackData(MetaBase):
    SpellResetFlashFadeDuration: float
    SpellResetFlashScaleDownDuration: float
    SpellResetScaleMultiplier: float
    pass

@MetaClass
class HudLoadingScreenProgressBarData(MetaBase):
    m_0xe4a8e1a9: float
    m_0xd69543e7: float
    m_0x9f3d3433: float
    m_0xb550de8d: float
    pass

@MetaClass
class HudLoadingScreenData(MetaBase):
    mProgressBarData: HudLoadingScreenProgressBarData
    m_0x9d17e9e3: bool
    mLoadingSpinnerSpeed: float
    mLoadingSpinnerFrames: UInt8
    mLoadingSpinnerRows: UInt8
    pass

@MetaClass
class HudStatPanelStatStoneData(MetaBase):
    m_0xca84776a: float
    m_0xf675a6b7: float
    mAnimationDelayTime: float
    m_0x77d83159: HudMenuTransitionData
    m_0x4ae65dfa: HudMenuTransitionData
    mSlideTransitionIn: HudMenuTransitionData
    mSlideTransitionOut: HudMenuTransitionData
    pass

@MetaClass
class HudStatStoneData(MetaBase):
    m_0x2dd6b42e: str
    m_0x3c8fa9e9: str
    pass

@MetaClass
class HudStatStoneDeathRecapData(MetaBase):
    MinDisplayTime: float
    MaxDisplayTime: float
    DetailsTransitionData: HudMenuTransitionData
    DeathRecapTransitionIn: HudMenuTransitionData
    DeathRecapTransitionOut: HudMenuTransitionData
    pass

@MetaClass
class HudStatStoneMilestoneData(MetaBase):
    UiSound: str
    m_0xedf950c1: str
    m_0x4f7fe3a3: str
    m_0xbb713ae8: str
    MilestoneDisplayTime: float
    m_0xdd1c30ab: float
    MilestoneSelfIntroTime: float
    MilestoneOtherIntroTime: float
    PersonalBestIntroTime: float
    m_0x39fecf93: float
    m_0x0db4c4cf: UInt32
    m_0xa6d1b459: HudMenuTransitionData
    MilestoneTransitionIn: HudMenuTransitionData
    MilestoneTransitionOut: HudMenuTransitionData
    m_0x4ea59d14: bool
    pass

@MetaClass
class HudEndOfGameData(MetaBase):
    mVictoryTransitionIn: HudMenuTransitionData
    mDefeatTransitionIn: HudMenuTransitionData
    pass

@MetaClass
class HudMessageDisplayData(MetaBase):
    TransitionIn: HudMenuTransitionData
    MessageDuration: float
    MessageCount: UInt32
    pass

@MetaClass
class HudDamageDisplayData(MetaBase):
    m_0xdfcea7db: float
    pass

@MetaClass
class HudFightRecapUiData(MetaBase):
    mBasicAttackIconTextureName: str
    mUnknownDamageIconTextureName: str
    mItemDamageIconTextureName: str
    mRuneDamageIconTextureName: str
    pass

@MetaClass
class MinimapPingEffectDefinition(MetaBase):
    AlphaStart: UInt32
    AlphaFadeSpeed: float
    ScaleStart: float
    ScaleSpeed: float
    StartDelay: float
    Life: float
    OnDeathFadeSpeed: float
    RepeatCount: UInt32
    BlendWithAlpha: bool
    pass

@MetaClass
class TextureAndColorData(MetaBase):
    TextureFile: str
    color: Color
    ColorblindTextureFile: str
    ColorblindColor: Optional[Color]
    pass

@MetaClass
class MinimapPingEffectAndTextureData(MetaBase):
    mEnabled: bool
    mEffect: MinimapPingEffectDefinition
    mDefault: TextureAndColorData
    mOrder: Optional[TextureAndColorData]
    mChaos: Optional[TextureAndColorData]
    pass

@MetaClass
class MinimapPingTypeContainer(MetaBase):
    PingEffectList: list[MinimapPingEffectAndTextureData]
    pass

@MetaClass
class MinimapPingData(MetaBase):
    mOmwPingRangeCutoffs: dict[UInt8, float]
    mPings: list[MinimapPingTypeContainer]
    pass

@MetaClassEmpty
class ISecondaryResourceDisplayData(MetaBase):
    pass

@MetaClassEmpty
class SecondaryResourceDisplayFractional(ISecondaryResourceDisplayData):
    pass

@MetaClass
class LoadingScreenRankedProperties(MetaBase):
    mDescriptor: str
    mDivision: UInt8
    pass

@MetaClass
class LoadingScreenRankedData(MetaBase):
    mRankedData: dict[str, LoadingScreenRankedProperties]
    pass

@MetaClass
class ItemShopViewController(ViewController):
    DragRegion: Hash
    ResizeDragRegion: Hash
    MaximumShopScale: float
    MinimumShopScale: float
    pass

@MetaClass
class t_0xe0e70cfc(ViewController):
    Scene: Hash
    pass

@MetaClass
class t_0x4e4bbc2b(ViewController):
    Scene: Hash
    pass

@MetaClass
class NavHeaderViewController(ViewController):
    m_0x4a989cc9: Hash
    m_0x4e51b642: Hash
    m_0x93a118fb: Hash
    m_0x7b8e8695: Hash
    BackButton: Hash
    SocialButton: Hash
    NotificationsButton: Hash
    SettingsButton: Hash
    MissionsButton: Hash
    StarShardsButton: Hash
    pass

@MetaClass
class OptionsViewController(ViewController):
    ViewPaneDefinition: ViewPaneDefinition
    CloseButtonDefinition: Hash
    TabButtonDefinition: Hash
    Button1Definition: Hash
    Button2Definition: Hash
    Tabs: list[Link[OptionsTab]]
    m_0x5a46f90c: Hash
    LastItemPadding: Hash
    m_0x4d302530: Hash
    pass

@MetaClass
class QualitySetting(MetaBase):
    mName: str
    m_0x033eb38d: float
    mFrameCap: UInt32
    mEnvironmentQuality: UInt32
    m_0xa8d99737: UInt32
    mEffectsQuality: UInt32
    mShadowQuality: UInt32
    mFxAa: bool
    pass

@MetaClass
class IOptionItem(MetaBase):
    LiveUpdate: bool
    ShowOnPlatform: UInt8
    Filter: Optional[IOptionItemFilter]
    pass

@MetaClass
class IOptionTemplate(MetaBase):
    BoundsElement: Hash
    pass

@MetaClass
class OptionItemBorder(IOptionItem):
    Template: Hash
    Items: list[Optional[IOptionItem]]
    pass

@MetaClass
class OptionItemCheckbox(IOptionItem):
    Template: Hash
    LabelTraKey: str
    TooltipTraKey: str
    Option: UInt16
    Negate: bool
    pass

@MetaClass
class OptionItemColumns(IOptionItem):
    ItemsEither: list[Optional[IOptionItem]]
    ItemsLeft: list[Optional[IOptionItem]]
    ItemsRight: list[Optional[IOptionItem]]
    pass

@MetaClass
class OptionItemDropdownItem(MetaBase):
    TraKey: str
    Value: Int32
    pass

@MetaClass
class OptionItemDropdown(IOptionItem):
    Template: Hash
    LabelTraKey: str
    TooltipTraKey: str
    Option: UInt16
    Items: list[OptionItemDropdownItem]
    pass

@MetaClassEmpty
class IOptionItemFilter(MetaBase):
    pass

@MetaClass
class t_0x0a6743a7(IOptionItemFilter):
    Filters: list[Optional[IOptionItemFilter]]
    pass

@MetaClass
class t_0xcd391c99(IOptionItemFilter):
    ShowInLolGame: bool
    ShowInLolReplay: bool
    ShowInTftGame: bool
    ShowInTftReplay: bool
    pass

@MetaClass
class t_0x3e59e2ca(IOptionItemFilter):
    m_0x7b98ffdd: bool
    m_0x812748a2: bool
    m_0x37985b59: bool
    pass

@MetaClass
class t_0xd90e7018(IOptionItemFilter):
    Map: Hash
    pass

@MetaClass
class t_0xee4d1304(IOptionItemFilter):
    Mutator: str
    pass

@MetaClassEmpty
class t_0xf8026218(IOptionItemFilter):
    pass

@MetaClassEmpty
class t_0xa4941383(IOptionItemFilter):
    pass

@MetaClass
class t_0x00c58386(IOptionItemFilter):
    m_0xc77c4866: bool
    pass

@MetaClassEmpty
class t_0xa6a54243(IOptionItemFilter):
    pass

@MetaClass
class OptionItemGroup(IOptionItem):
    Template: Hash
    LabelTraKey: str
    ExpandedByDefault: bool
    Items: list[Optional[IOptionItem]]
    pass

@MetaClass
class OptionItemHotkeys(IOptionItem):
    Template: Hash
    pass

@MetaClass
class OptionItemLabel(IOptionItem):
    Template: Hash
    Label1TraKey: str
    Label2TraKey: str
    pass

@MetaClassEmpty
class OptionItemResolutionDropdown(OptionItemDropdown):
    pass

@MetaClass
class t_0x55212361(MetaBase):
    Column0LabelTraKey: str
    Column1LabelTraKey: str
    pass

@MetaClass
class t_0x518d5fc0(MetaBase):
    LabelTraKey: str
    EventName: str
    pass

@MetaClass
class OptionItemSecondaryHotkeys1Column(IOptionItem):
    Template: Hash
    Header: t_0x55212361
    Rows: list[t_0x518d5fc0]
    pass

@MetaClass
class t_0xea321356(MetaBase):
    Column0LabelTraKey: str
    Column1LabelTraKey: str
    Column2LabelTraKey: str
    pass

@MetaClass
class t_0x430dd10d(MetaBase):
    LabelTraKey: str
    EventName: str
    Filter: Optional[IOptionItemFilter]
    pass

@MetaClass
class OptionItemSecondaryHotkeys2Column(IOptionItem):
    Template: Hash
    Header: t_0xea321356
    Rows: list[t_0x430dd10d]
    pass

@MetaClass
class OptionItemSlider(IOptionItem):
    Template: Hash
    LabelTraKey: str
    TooltipTraKey: str
    pass

@MetaClass
class OptionItemSliderFloat(OptionItemSlider):
    Option: UInt16
    UpdateOnDrag: bool
    Scale: float
    pass

@MetaClassEmpty
class OptionItemSliderGraphicsQuality(OptionItemSlider):
    pass

@MetaClass
class OptionItemSliderInt(OptionItemSlider):
    Option: UInt16
    OptionScale: UInt32
    pass

@MetaClass
class OptionItemSliderVolume(OptionItemSliderFloat):
    MuteButtonTemplate: Hash
    MuteOption: UInt16
    pass

@MetaClassEmpty
class t_0xf5324e2a(OptionItemDropdown):
    pass

@MetaClass
class OptionsTab(MetaBase):
    TabNameTraKey: str
    ShowOn: UInt8
    m_0x9255c052: bool
    Filter: Optional[IOptionItemFilter]
    Items: list[Optional[IOptionItem]]
    pass

@MetaClass
class OptionTemplateBorder(IOptionTemplate):
    Border: Hash
    pass

@MetaClass
class OptionTemplateCheckbox(IOptionTemplate):
    ButtonDefinition: Hash
    LabelElement: Hash
    pass

@MetaClass
class OptionTemplateDropdown(IOptionTemplate):
    LabelElement: Hash
    ComboBoxDefinition: Hash
    pass

@MetaClass
class OptionTemplateGroup(IOptionTemplate):
    ExpandButtonDefinition: Hash
    LabelElement: Hash
    m_0xe76606d7: Hash
    m_0x999669b3: float
    pass

@MetaClass
class OptionTemplateHotkeysLabel(MetaBase):
    Label: Hash
    pass

@MetaClass
class OptionTemplateHotkeysKey(MetaBase):
    EventName: str
    EventNameTraKey: str
    Position: Hash
    pass

@MetaClass
class OptionTemplateHotkeys(IOptionTemplate):
    HotkeyButtonDefinition: Hash
    HotkeyButtonTextSmall: Hash
    HotkeyModifierText: Hash
    HotkeyQuickCastButtonDefinition: Hash
    CastAllButtonDefinition: Hash
    m_0x2f11f1cb: Hash
    m_0xa8e4f979: Hash
    Labels: list[OptionTemplateHotkeysLabel]
    Keys: list[OptionTemplateHotkeysKey]
    pass

@MetaClass
class OptionTemplateLabel(IOptionTemplate):
    Label1: Hash
    Label2: Hash
    pass

@MetaClass
class OptionTemplateMuteButton(IOptionTemplate):
    ButtonDefinition: Hash
    pass

@MetaClass
class t_0xceb70e5a(MetaBase):
    BackgroundElement: Hash
    TextElement: Hash
    pass

@MetaClass
class t_0x354988a8(MetaBase):
    ButtonDefinition: Hash
    pass

@MetaClass
class OptionTemplateSecondaryHotkeys1Column(IOptionTemplate):
    m_0x5b59b589: t_0xceb70e5a
    m_0x5a59b3f6: t_0xceb70e5a
    m_0xfd31cbcb: t_0xceb70e5a
    m_0x545758a8: t_0x354988a8
    pass

@MetaClass
class OptionTemplateSecondaryHotkeys2Column(IOptionTemplate):
    m_0x5b59b589: t_0xceb70e5a
    m_0x5a59b3f6: t_0xceb70e5a
    m_0x5959b263: t_0xceb70e5a
    m_0xfd31cbcb: t_0xceb70e5a
    m_0x545758a8: t_0x354988a8
    m_0x57575d61: t_0x354988a8
    pass

@MetaClass
class OptionTemplateSlider(IOptionTemplate):
    LabelElement: Hash
    ValueElement: Hash
    m_0x6a05258c: Hash
    pass

@MetaClass
class NamedIconData(MetaBase):
    Name: str
    Icon: Hash
    pass

@MetaClass
class PostGameViewController(ViewController):
    Scene: Hash
    RankIconData: list[NamedIconData]
    RankText: Hash
    CurrentExpText: Hash
    GainedExpText: Hash
    LostExpText: Hash
    PlacementTextRight: Hash
    ProvisionalTextRight: Hash
    BackgroundTexture: Hash
    CurrentPlayerHighlight: Hash
    GainedRatingText: Hash
    LostRatingText: Hash
    CurrentRatingText: Hash
    m_0x1abf4b19: Hash
    RatedIconData: list[NamedIconData]
    m_0x8ecd9248: Hash
    m_0xb726620c: Hash
    PlayAgainButtonDefinition: Hash
    QuitButtonDefinition: Hash
    m_0xb06a57fd: dict[str, str]
    pass

@MetaClass
class CelebrationViewController(ViewController):
    Scene: Hash
    m_0x615c3c29: float
    m_0x4fe75004: str
    m_0xc4ecb642: dict[str, str]
    pass

@MetaClass
class ModeSelectButtonData(MetaBase):
    QueueId: Int64
    ButtonDefinition: Hash
    pass

@MetaClass
class HomeViewController(ViewController):
    m_0xbbb37ef7: Hash
    SpecialOfferController: t_0xfbd72d16
    Scene: Hash
    ModeSelectCustomButtonData: list[ModeSelectButtonData]
    ModeSelectDefaultButtonData: Hash
    PlayGameButtonDefinition: Hash
    BattlepassButtonDefinition: Hash
    StoreButtonDefinition: Hash
    TeamPlannerButtonDefinition: Hash
    SpecialOfferButtonDefinition: Hash
    m_0x56f22512: Link[t_0x75259ad3]
    ThemeMusicStateGroup: str
    ThemeMusicState: str
    m_0xdc1d621e: float
    m_0x86a69e37: UInt8
    pass

@MetaClass
class ILoadoutFeatureDataBehavior(MetaBase):
    DisplayNameTraKey: str
    LoadoutType: UInt32
    m_0x4e2c59d6: Hash
    IllustrationIcon: Hash
    Region: Hash
    ButtonDefinition: Hash
    pass

@MetaClass
class LoadoutSelectViewController(ViewController):
    LoadoutsButtonData: list[ILoadoutFeatureDataBehavior]
    Scene: Hash
    pass

@MetaClass
class LoadoutViewController(ViewController):
    m_0x78407281: Hash
    m_0xd1abeb9d: Hash
    EquipButton: Hash
    GridItemButton: Hash
    CloseButton: Hash
    UpgradeButton: Hash
    m_0x91672418: Hash
    SoundOnActivate: str
    SoundOnDeActivate: str
    CompanionInfoPanel: LoadoutCompanionInfoPanel
    ArenaInfoPanel: LoadoutArenaSkinInfoPanel
    EmoteInfoPanel: LoadoutEmoteInfoPanel
    DamageSkinInfoPanel: LoadoutDamageSkinInfoPanel
    pass

@MetaClass
class LobbyViewController(ViewController):
    m_0x573e7831: Hash
    ReadyCheckAcceptButton: Hash
    ReadyCheckDeclineButton: Hash
    m_0xd5989aae: Hash
    LobbyCloseButton: Hash
    FriendInviteButton: Hash
    FriendEditButton: Hash
    LoadoutsButton: Hash
    m_0xbd29d956: dict[Int64, str]
    m_0x1a361782: str
    m_0xa38f5021: str
    m_0x72c4914b: str
    m_0xbf51f61a: str
    m_0x671c34c8: Link[t_0x75259ad3]
    m_0xb3e2f60e: Hash
    ThemeMusicStateGroup: str
    LobbyMusicState: str
    InQueueMusicState: str
    pass

@MetaClass
class LootTableDialogViewController(t_0x75259ad3):
    m_0xe8b4823e: Hash
    m_0x8f597852: Hash
    pass

@MetaClass
class MissionsPanelViewController(ViewController):
    Scene: Hash
    ViewPaneDefinition: ViewPaneDefinition
    m_0xfa7c8443: float
    m_0xec740d9e: UInt8
    pass

@MetaClass
class QueueDisplayData(MetaBase):
    QueueId: Int64
    m_0xce96bffc: Hash
    m_0xf221c7d2: Hash
    m_0x021eaf8b: Hash
    IllustrationIconElement: Hash
    DisplayNameTraKey: str
    pass

@MetaClass
class ModeSelectViewController(ViewController):
    Scene: Hash
    QueueDisplayData: list[QueueDisplayData]
    m_0x9e4be5ed: Hash
    PageLeftButtonDefinition: Hash
    PageRightButtonDefinition: Hash
    SoundOnActivate: str
    SoundOnDeActivate: str
    m_0x71378d8b: list[Hash]
    pass

@MetaClass
class NotificationsPanelViewController(ViewController):
    Scene: Hash
    ViewPaneDefinition: ViewPaneDefinition
    ClearAllButtonDefinition: Hash
    pass

@MetaClass
class t_0x6d8b7fba(MetaBase):
    m_0xdc4a41ff: Hash
    m_0x351de0c4: Hash
    m_0xfbd508b7: Hash
    m_0x3b5d2f94: Hash
    m_0xa67dbab3: Hash
    pass

@MetaClass
class PurchaseDialog(t_0x75259ad3):
    m_0x88f6a038: Hash
    m_0xb0dd6202: Hash
    m_0x909d5d3f: Hash
    m_0x25c805c3: Hash
    m_0x07061da5: Hash
    m_0x8dd1da54: Hash
    m_0x2e6d3c7e: Hash
    m_0xf42e1d1a: Hash
    m_0x3591028e: Hash
    m_0x67c3b51b: t_0x6d8b7fba
    m_0x49d6bd37: Hash
    m_0x2fbbd4d0: Hash
    m_0x2aa5cb5e: Hash
    m_0xe338a1da: Hash
    m_0x32cd31df: Hash
    PurchaseButton: Hash
    MoreInfoButton: Hash
    pass

@MetaClass
class t_0x39bbca88(t_0x75259ad3):
    ActionButtonDefinition: Hash
    m_0x523f1f5e: Hash
    m_0x44b4862a: Hash
    m_0xcd92a830: Hash
    m_0x4b932928: Hash
    m_0x4fa419b5: Hash
    m_0x738917db: Hash
    m_0x52662fad: Hash
    m_0xa8f48b28: Hash
    m_0x56ed0d27: Hash
    m_0xd5b6bcd3: Hash
    m_0x5c05f04d: Hash
    m_0x7d83e942: Hash
    pass

@MetaClass
class SocialPanelViewController(ViewController):
    Scene: Hash
    ViewPaneDefinition: ViewPaneDefinition
    AddFriendButtonDefinition: Hash
    InviteButtonDefinition: Hash
    FriendButtonDefinition: Hash
    pass

@MetaClass
class t_0xfbd72d16(MetaBase):
    m_0x4d31ed46: Link[t_0x4d31ed46]
    pass

@MetaClass
class StoreCategoryButtonDefinition(MetaBase):
    Category: UInt32
    ButtonDefinition: Hash
    pass

@MetaClass
class StoreViewController(ViewController):
    m_0x36a4c8ee: Hash
    m_0x9eae8cc2: Hash
    m_0xd2cc0cdf: Hash
    MainViewPaneDefinition: Optional[ViewPaneDefinition]
    StoreCategoryButtonDefinitions: list[StoreCategoryButtonDefinition]
    pass

@MetaClass
class TftBattlepassViewController(ViewController):
    m_0xcfd1aa4a: Hash
    UpgradePassButton: Hash
    LootTableButton: Hash
    m_0x59434c33: Hash
    ViewPaneDefinition: ViewPaneDefinition
    m_0xc034af02: float
    m_0x650b36b5: HudMenuTransitionData
    pass

@MetaClass
class ILoadoutInfoPanel(MetaBase):
    ViewPaneDefinition: ViewPaneDefinition
    pass

@MetaClassEmpty
class LoadoutArenaSkinInfoPanel(ILoadoutInfoPanel):
    pass

@MetaClass
class LoadoutCompanionInfoPanel(ILoadoutInfoPanel):
    UpgradeInfoText: Hash
    UpgradeErrorText: Hash
    TierButton: list[Hash]
    UpgradeTierButton: list[Hash]
    m_0x6a5635f2: Hash
    m_0x90dd73ef: Hash
    pass

@MetaClass
class LoadoutDamageSkinInfoPanel(ILoadoutInfoPanel):
    TierButton: list[Hash]
    pass

@MetaClass
class LoadoutEmoteInfoPanel(ILoadoutInfoPanel):
    EmoteWheelUpperButton: Hash
    EmoteWheelLeftButton: Hash
    EmoteWheelLowerButton: Hash
    EmoteWheelRightButton: Hash
    EmoteWheelCenterButton: Hash
    EmoteStartButton: Hash
    EmoteVictoryButton: Hash
    pass

@MetaClass
class t_0x759a8c58(t_0x75259ad3):
    UpgradeText: Hash
    ErrorText: Hash
    ItemIcon: Hash
    ItemFrame: Hash
    RarityFrameCommon: Hash
    RarityFrameEpic: Hash
    RarityFrameLegendary: Hash
    m_0xda8bcd33: Hash
    m_0x41ed38a6: Hash
    pass

@MetaClass
class NotificationSettings(MetaBase):
    DefaultSound: str
    m_0x89667868: dict[UInt8, str]
    pass

@MetaClass
class QuestDefinition(MetaBase):
    CategoryTitleText: str
    MaxViewableQuests: UInt32
    RecievedSoundPath: str
    CompletedSoundPath: str
    FailedSoundPath: str
    pass

@MetaClass
class t_0x46533086(MetaBase):
    PrimaryQuest: QuestDefinition
    SecondaryQuest: QuestDefinition
    ObjectiveQuest: QuestDefinition
    m_0x56647830: QuestDefinition
    m_0x6cee1705: QuestDefinition
    ScoreDisplayQuest: QuestDefinition
    pass

@MetaClass
class QuestTrackerViewController(ViewController):
    MessageDisplayData: HudMessageDisplayData
    m_0x062eab0b: UInt32
    m_0x18bae045: float
    m_0xdba6febb: float
    m_0x9fa3719e: float
    m_0x28f5e138: float
    m_0xa0ae36a8: float
    m_0xc67a95a4: float
    pass

@MetaClass
class t_0xe20be0be(ViewController):
    m_0x4d302530: Hash
    pass

@MetaClassEmpty
class t_0x320b890e(ViewController):
    pass

@MetaClass
class GeneralSettingsGroup(MetaBase):
    PromoteAccountButton: Hash
    SignOutButton: Hash
    RestorePurchaseButton: Hash
    pass

@MetaClass
class SettingsViewController(ViewController):
    GeneralSettings: GeneralSettingsGroup
    CloseButton: Hash
    TabButton: Hash
    SoundOnActivate: str
    SoundOnDeActivate: str
    pass

@MetaClass
class t_0x1fa3e21c(MetaBase):
    m_0xa2bc2cb5: Hash
    m_0x43b27471: Hash
    Icon: Hash
    Title: Hash
    Description: Hash
    pass

@MetaClass
class t_0x61a8deda(ViewController):
    Scene: Hash
    m_0xaf871a91: Hash
    m_0xdf85b25f: Hash
    m_0x1fa3e21c: t_0x1fa3e21c
    m_0x0b6200fc: float
    m_0x4a65c1a7: float
    m_0x017a5149: UInt8
    m_0xf75a1005: UInt32
    pass

@MetaClass
class SurrenderTypeData(MetaBase):
    VoteTimeout: float
    WindowLength: float
    StartTime: float
    PercentageRequired: float
    m_0x3f72f07a: float
    pass

@MetaClass
class SurrenderData(MetaBase):
    m_0x43f7599b: float
    m_0x0e98993c: float
    m_0xcc805103: float
    m_0x3afeacf3: float
    mTypeData: dict[UInt8, SurrenderTypeData]
    pass

@MetaClass
class LoadScreenTip(MetaBase):
    mId: UInt16
    mMinimumSummonerLevel: Optional[UInt32]
    mMaximumSummonerLevel: Optional[UInt32]
    mLocalizationKey: str
    mHeaderLocalizationKey: str
    pass

@MetaClass
class LoadScreenTipSet(MetaBase):
    mName: Hash
    mTips: list[Link[LoadScreenTip]]
    pass

@MetaClass
class LoadScreenTipConfiguration(MetaBase):
    mShowInCustomGames: bool
    mShowPbiTipsOnLoadingScreen: bool
    mPbiTipDurationOnLoadingScreen: float
    mDurationInGame: float
    pass

@MetaClass
class TooltipInstance(MetaBase):
    mObjectName: str
    mFormat: Link[TooltipFormat]
    mLocKeys: dict[str, str]
    mLists: dict[str, TooltipInstanceList]
    pass

@MetaClass
class TooltipInstanceSpell(TooltipInstance):
    EnableExtendedTooltip: bool
    pass

@MetaClass
class TooltipInstanceBuff(TooltipInstance):
    mEnableExtendedTooltip: bool
    pass

@MetaClassEmpty
class TooltipInstanceItem(TooltipInstance):
    pass

@MetaClass
class t_0x9e5aed77(MetaBase):
    m_0x571a97a3: Int32
    m_0x88a45101: Int32
    m_0x1a8b3cc8: Int32
    m_0xbb9129ab: Int32
    m_0xe2e4f9c2: Int32
    m_0x47bdbbe9: Int32
    pass

@MetaClass
class TooltipViewController(ViewController):
    DefaultAdjustments: t_0x9e5aed77
    m_0xf5fc1d3a: dict[str, t_0x9e5aed77]
    m_0x9e2fcad4: float
    m_0x750ad235: float
    pass

@MetaClass
class t_0xd9438618(MetaBase):
    m_0x799f2859: list[str]
    pass

@MetaClass
class t_0x7feb6200(MetaBase):
    m_0x71581e65: list[str]
    m_0x121b136b: list[Link[t_0xd9438618]]
    pass

@MetaClass
class VoiceChatViewController(ViewController):
    PanelSceneHandle: Hash
    SelfSlot: VoiceChatViewSelfSlot
    PlayerSlotData: t_0x86504cef
    PlayerGrid: Hash
    Backdrop: Hash
    ErrorText: Hash
    m_0x8c45eb46: Hash
    m_0x788862bd: Hash
    pass

@MetaClass
class t_0x86504cef(MetaBase):
    Group: Hash
    Portrait: Hash
    VolumeText: Hash
    Halo: Hash
    NameText: Hash
    VolumeSliderBar: Hash
    MuteButton: Hash
    pass

@MetaClass
class VoiceChatViewSelfSlot(MetaBase):
    Portrait: Hash
    Halo: Hash
    NameText: Hash
    MicVolumeText: Hash
    MicVolumeSliderBar: Hash
    MuteButton: Hash
    ConnectionButton: Hash
    pass

@MetaClass
class NeutralTimerSourceIconData(MetaBase):
    mTooltipName: str
    mIconName: str
    pass

@MetaClass
class NeutralTimerData(MetaBase):
    mTimerKeyName: str
    mTooltip: str
    mTooltipCampName: str
    mTooltipRespawn: str
    mTooltipChatNameOrder: str
    mTooltipChatNameChaos: str
    mSourceIcons: dict[Hash, NeutralTimerSourceIconData]
    pass

@MetaClass
class NeutralTimers(MetaBase):
    mSceneName: str
    m_0xee974cae: str
    mTimers: dict[Hash, NeutralTimerData]
    pass

@MetaClass
class CommonUiTunables(MetaBase):
    m_0x472b866d: float
    m_0xb3f4a621: UInt8
    pass

@MetaClass
class ViewPaneDefinition(MetaBase):
    m_0x6eac67fc: Hash
    DragRegionElement: Hash
    ScrollRegionElement: Hash
    ScissorRegionElement: Hash
    ScrollingScene: Hash
    ScrollDirection: UInt8
    ObjectPath: Hash
    pass

@MetaClass
class UiButtonState(MetaBase):
    DisplayElements: list[Link[BaseElementData]]
    TextElement: Link[TextElementData]
    pass

@MetaClass
class UiButtonDefinition(MetaBase):
    DefaultStateElements: UiButtonState
    InactiveStateElements: UiButtonState
    HoverStateElements: UiButtonState
    m_0xad0f8882: UiButtonState
    SelectedStateElements: UiButtonState
    SelectedHoverStateElements: UiButtonState
    SelectedClickedStateElements: UiButtonState
    HitRegionElement: Link[RegionElementData]
    ClickReleaseParticleElement: Link[ParticleSystemElementData]
    SoundEvents: Optional[t_0x209b0277]
    ActiveTooltipTraKey: str
    InactiveTooltipTraKey: str
    ObjectPath: Hash
    pass

@MetaClass
class UiButtonAdditionalState(MetaBase):
    DisplayElements: list[Link[BaseElementData]]
    pass

@MetaClass
class UiButtonAdditionalElements(MetaBase):
    DefaultStateElements: UiButtonAdditionalState
    InactiveStateElements: UiButtonAdditionalState
    HoverStateElements: UiButtonAdditionalState
    m_0xad0f8882: UiButtonAdditionalState
    SelectedStateElements: UiButtonAdditionalState
    SelectedHoverStateElements: UiButtonAdditionalState
    SelectedClickedStateElements: UiButtonAdditionalState
    pass

@MetaClass
class t_0x209b0277(MetaBase):
    RolloverEvent: str
    m_0x210ea29e: str
    MouseDownEvent: str
    m_0x0452034c: str
    MouseUpEvent: str
    m_0xb49ca145: str
    pass

@MetaClass
class t_0xe262e6be(MetaBase):
    OnSelectionEvent: str
    pass

@MetaClass
class UiComboBoxDefinition(MetaBase):
    ButtonDefinition: Hash
    m_0xb2a3be3c: Link[IconElementData]
    m_0x03487222: Link[IconElementData]
    m_0x9c4781a2: Link[IconElementData]
    m_0x21c9d879: Link[TextElementData]
    m_0x337b72d4: Link[RegionElementData]
    m_0x0eb2b67e: UInt8
    SoundEvents: Optional[t_0xe262e6be]
    ObjectPath: Hash
    m_0xcd0aaa2e: str
    pass

@MetaClass
class t_0xd149dd3f(MetaBase):
    FromSlotId: Int32
    ToSlotId: Int32
    pass

@MetaClass
class t_0xb35ad9d8(MetaBase):
    Items: list[Hash]
    ItemsPerRow: UInt32
    m_0xd8bea346: bool
    DefaultIndex: Int32
    SwapData: t_0xd149dd3f
    pass

@MetaClass
class t_0xd20000f6(MetaBase):
    SceneData: Hash
    PinButton: Hash
    m_0x434952b4: t_0xb35ad9d8
    pass

@MetaClass
class t_0xef05ba42(MetaBase):
    ItemIcon: Link[BaseElementData]
    FrameIcon: Link[BaseElementData]
    MythicFrameIcon: Link[BaseElementData]
    HoverFrameIcon: Link[BaseElementData]
    m_0x5b96b3bd: Link[BaseElementData]
    HoverIcon: Link[BaseElementData]
    SelectedIcon: Link[BaseElementData]
    UnpurchaseableOverlay: Link[BaseElementData]
    PurchasedOverlay: Link[BaseElementData]
    PopularIcon: Link[BaseElementData]
    LockedIcon: Link[BaseElementData]
    LockedHoverIcon: Link[BaseElementData]
    RecentlyChangedIcon: Link[BaseElementData]
    CostText: Link[BaseElementData]
    CostTextUnpurchaseable: Link[BaseElementData]
    CostTextSelected: Link[BaseElementData]
    NameText: Link[BaseElementData]
    HitRegion: Link[BaseElementData]
    OffsetRegion: Link[BaseElementData]
    SelectedVfx: Link[BaseElementData]
    m_0x987dd59e: Link[BaseElementData]
    MythicPurchaseableVfx: Link[BaseElementData]
    MythicPurchasedVfx: Link[BaseElementData]
    pass

@MetaClass
class t_0x9205b275(t_0xef05ba42):
    CardDefault: Link[BaseElementData]
    CardHoverMythic: Link[BaseElementData]
    CardHoverNonMythic: Link[BaseElementData]
    CardSelectedMythic: Link[BaseElementData]
    CardSelectedNonMythic: Link[BaseElementData]
    BriefText: Link[BaseElementData]
    BriefTextBackdrop: Link[BaseElementData]
    AdviceIconDefault: Link[BaseElementData]
    m_0x09c2a9d4: Link[BaseElementData]
    m_0xc68c22cf: Link[BaseElementData]
    AdviceLabel: Link[BaseElementData]
    AdviceCharIcon0: Link[BaseElementData]
    AdviceCharIcon1: Link[BaseElementData]
    CardHoverNonMythicVfx: Link[BaseElementData]
    CardHoverMythicVfx: Link[BaseElementData]
    CardRefreshMythicVfx: Link[BaseElementData]
    CardRefreshNonMythicVfx: Link[BaseElementData]
    CardSelectedMythicVfx: Link[BaseElementData]
    CardSelectedNonMythicVfx: Link[BaseElementData]
    AdviceEmptyIconDefault: Link[BaseElementData]
    m_0x59fbbd19: Link[BaseElementData]
    m_0x9566584e: Link[BaseElementData]
    AdviceEmptyText: Link[BaseElementData]
    AdviceEmptyTextHover: Link[BaseElementData]
    AdviceCharBorder0: Link[BaseElementData]
    AdviceCharBorderHover0: Link[BaseElementData]
    AdviceCharBorder1: Link[BaseElementData]
    AdviceCharBorderHover1: Link[BaseElementData]
    PlusIcon: Link[BaseElementData]
    BundleItemIcon: Link[BaseElementData]
    BundleStackText: Link[BaseElementData]
    BundleItemFrameIcon: Link[BaseElementData]
    BundleItemFrameHoverIcon: Link[BaseElementData]
    pass

@MetaClass
class t_0x38691790(MetaBase):
    m_0x837fcf93: list[UInt8]
    GroupName: str
    pass

@MetaClass
class StatFilterDefinition(MetaBase):
    ButtonDefinition: Hash
    MatchingCategories: list[Hash]
    pass

@MetaClass
class t_0x77595aa9(MetaBase):
    PhysicalDamage: StatFilterDefinition
    CriticalStrike: StatFilterDefinition
    AttackSpeed: StatFilterDefinition
    OnHit: StatFilterDefinition
    ArmorPenetration: StatFilterDefinition
    AbilityPower: StatFilterDefinition
    Mana: StatFilterDefinition
    MagicPenetration: StatFilterDefinition
    Health: StatFilterDefinition
    Armor: StatFilterDefinition
    MagicResist: StatFilterDefinition
    AbilityHaste: StatFilterDefinition
    MoveSpeed: StatFilterDefinition
    m_0xd628825f: StatFilterDefinition
    DisableStatFilters: StatFilterDefinition
    pass

@MetaClass
class HudItemShopData(MetaBase):
    TabButtonDefinition: Hash
    CloseButtonDefinition: Hash
    PurchaseButtonDefinition: Hash
    SellButtonDefinition: Hash
    UndoButtonDefinition: Hash
    m_0x616b3a84: Hash
    m_0x1ee195a0: Hash
    m_0xaa05f252: Hash
    m_0xdcf2bbe3: Hash
    m_0x6d532c7a: Hash
    m_0x655c70a4: Hash
    m_0xf1b77de6: Hash
    m_0xd2202861: Hash
    m_0x6ff1fabe: Hash
    m_0xa1f85097: Hash
    m_0x77595aa9: Hash
    m_0x71d17542: ViewPaneDefinition
    m_0x0ce14c25: ViewPaneDefinition
    m_0xb3e9d346: ViewPaneDefinition
    SearchViewPaneDefinition: ViewPaneDefinition
    AllItemsHeaderRegion: Hash
    AllItemsItemRegion: Hash
    ItemSetsHeaderRegion: Hash
    ItemSetsItemRegion: Hash
    AllItemsHeaderText: Hash
    m_0xf481f566: Hash
    m_0x4823f71d: Hash
    m_0x79a37750: list[t_0x38691790]
    BootsPanelDefinition: t_0xd20000f6
    ConsumablesPanelDefinition: t_0xd20000f6
    InventoryPanelDefinition: t_0xd20000f6
    m_0xe00be811: list[Hash]
    m_0x0f8310aa: float
    m_0x7df5b85f: float
    BuildsIntoIconDefinition: Hash
    BuildTreeIconDefinition: Hash
    QuickBuyIconDefinition: Hash
    InventoryIconDefinition: Hash
    AllItemsIconDefinition: Hash
    ItemSetsIconDefinition: Hash
    SearchIconDefinition: Hash
    m_0x494a4b42: Hash
    CommonlyBuiltIconDefinition: Hash
    m_0x5ab9b659: Hash
    m_0xf8e1342c: Hash
    m_0x69988db6: Hash
    m_0x7ba0c753: float
    ItemDetailsScene: Hash
    m_0xf48cf36f: Hash
    m_0xaa352f81: Hash
    m_0xd6f8b1fa: str
    pass

@MetaClass
class IHudLoadingScreenWidget(MetaBase):
    mSceneName: str
    pass

@MetaClass
class HudLoadingScreenCarouselData(MetaBase):
    Image: str
    mTipType: UInt8
    pass

@MetaClass
class HudLoadingScreenWidgetCarousel(IHudLoadingScreenWidget):
    m_0x7b1f4fc8: UInt8
    mCarouselData: Link[HudLoadingScreenCarouselData]
    pass

@MetaClassEmpty
class HudLoadingScreenWidgetClash(IHudLoadingScreenWidget):
    pass

@MetaClass
class HudLoadingScreenWidgetPing(IHudLoadingScreenWidget):
    mDebugPing: UInt32
    mPingThresholdGreen: UInt32
    mPingThresholdYellow: UInt32
    mPingThresholdOrange: UInt32
    mPingThresholdRed: UInt32
    pass

@MetaClass
class HudLoadingScreenWidgetPlayers(IHudLoadingScreenWidget):
    mCardConfig: PlayerCardWidgetConfig
    pass

@MetaClassEmpty
class HudLoadingScreenWidgetProgressBar(IHudLoadingScreenWidget):
    pass

@MetaClassEmpty
class HudLoadingScreenWidgetTutorial(IHudLoadingScreenWidget):
    pass

@MetaClass
class PlayerCardWidgetConfig(MetaBase):
    mTeamBased: bool
    mCardType: UInt8
    m_0x7b9b52c3: UInt32
    pass

@MetaClass
class t_0x97599ad3(MetaBase):
    m_0x634c549e: Hash
    m_0x299164e2: Hash
    pass

@MetaClass
class HudReplaySliderIconData(MetaBase):
    mType: Hash
    mTooltipStyle: UInt8
    mElementName: str
    mElementSpacer: float
    mElementAlphaDefault: float
    mElementAlphaSelected: float
    mElementAlphaUnselected: float
    mTooltipIconNames: list[str]
    pass

@MetaClass
class HudReplaySliderData(MetaBase):
    mIconDataPriorityList: list[HudReplaySliderIconData]
    mTooltipEventWindow: float
    pass

@MetaClassEmpty
class EsportsBannerMaterialController(SkinnedMeshDataMaterialController):
    pass

@MetaClassEmpty
class BaseRigPoseModifierData(MetaBase):
    pass

@MetaClass
class ConformToPathRigPoseModifierData(BaseRigPoseModifierData):
    mStartingJointName: Hash
    mEndingJointName: Hash
    mDefaultMaskName: Hash
    mMaxBoneAngle: float
    mDampingValue: float
    mVelMultiplier: float
    mFrequency: float
    pass

@MetaClassEmpty
class JointSnapRigPoseModifilerData(BaseRigPoseModifierData):
    pass

@MetaClassEmpty
class LockRootOrientationRigPoseModifierData(BaseRigPoseModifierData):
    pass

@MetaClassEmpty
class SyncedAnimationRigPoseModifierData(BaseRigPoseModifierData):
    pass

@MetaClass
class VertexAnimationRigPoseModifierData(BaseRigPoseModifierData):
    mMaxSpeed: float
    mStiffness: float
    mMass: float
    mDamping: float
    pass

@MetaClass
class AnimationGraphData(MetaBase):
    mUseCascadeBlend: bool
    mCascadeBlendValue: float
    mClipDataMap: dict[Hash, Optional[ClipBaseData]]
    mMaskDataMap: dict[Hash, MaskData]
    mTrackDataMap: dict[Hash, TrackData]
    mSyncGroupDataMap: dict[Hash, SyncGroupData]
    mBlendDataTable: dict[UInt64, Optional[BaseBlendData]]
    pass

@MetaClass
class AnimationResourceData(MetaBase):
    mAnimationFilePath: str
    pass

@MetaClass
class MaskData(MetaBase):
    mId: UInt32
    mWeightList: list[float]
    pass

@MetaClass
class Joint(MetaBase):
    mIndex: UInt16
    mFlags: UInt16
    mNameHash: UInt32
    mName: str
    mRadius: float
    mParentIndex: Int16
    pass

@MetaClass
class RigResource(MetaBase):
    mName: str
    mAssetName: str
    mFlags: UInt16
    mJointList: list[Joint]
    mShaderJointList: list[UInt16]
    pass

@MetaClass
class SyncGroupData(MetaBase):
    mType: UInt32
    pass

@MetaClass
class TrackData(MetaBase):
    mPriority: UInt8
    mBlendMode: UInt8
    mBlendWeight: float
    pass

@MetaClass
class UpdaterData(MetaBase):
    mInputType: UInt32
    mOutputType: UInt32
    mValueProcessorDataList: list[Optional[ValueProcessorData]]
    pass

@MetaClass
class UpdaterResourceData(MetaBase):
    mUpdaterDataList: list[UpdaterData]
    pass

@MetaClass
class ClipBaseData(MetaBase):
    mFlags: UInt32
    mAnimationInterruptionGroupNames: list[Hash]
    pass

@MetaClass
class BlendableClipData(ClipBaseData):
    mMaskDataName: Hash
    mTrackDataName: Hash
    mSyncGroupDataName: Hash
    mEventDataMap: dict[Hash, Optional[BaseEventData]]
    pass

@MetaClass
class AtomicClipData(BlendableClipData):
    mTickDuration: float
    mAnimationResourceData: AnimationResourceData
    mUpdaterResourceData: Optional[UpdaterResourceData]
    pass

@MetaClass
class ConditionBoolClipData(ClipBaseData):
    mUpdaterType: UInt32
    mChangeAnimationMidPlay: bool
    m_0x31db4e6a: bool
    m_0x92213dee: bool
    mChildAnimDelaySwitchTime: float
    mTrueConditionClipName: Hash
    mFalseConditionClipName: Hash
    pass

@MetaClass
class ConditionFloatPairData(MetaBase):
    mClipName: Hash
    mValue: float
    mHoldAnimationToHigher: float
    mHoldAnimationToLower: float
    pass

@MetaClass
class ConditionFloatClipData(ClipBaseData):
    mUpdaterType: UInt32
    mChangeAnimationMidPlay: bool
    m_0x31db4e6a: bool
    m_0xf88501b8: bool
    m_0x92213dee: bool
    mChildAnimDelaySwitchTime: float
    mConditionFloatPairDataList: list[ConditionFloatPairData]
    pass

@MetaClass
class ParallelClipData(ClipBaseData):
    mClipNameList: list[Hash]
    pass

@MetaClass
class ParametricPairData(MetaBase):
    mClipName: Hash
    mValue: float
    pass

@MetaClass
class ParametricClipData(BlendableClipData):
    mUpdaterType: UInt32
    mParametricPairDataList: list[ParametricPairData]
    pass

@MetaClass
class SelectorPairData(MetaBase):
    mClipName: Hash
    mProbability: float
    pass

@MetaClass
class SelectorClipData(ClipBaseData):
    mSelectorPairDataList: list[SelectorPairData]
    pass

@MetaClass
class SequencerClipData(ClipBaseData):
    mClipNameList: list[Hash]
    pass

@MetaClassEmpty
class BaseBlendData(MetaBase):
    pass

@MetaClass
class BaseEventData(MetaBase):
    mIsSelfOnly: bool
    mFireIfAnimationEndsEarly: bool
    mStartFrame: float
    mEndFrame: float
    mName: Hash
    pass

@MetaClass
class ConformToPathEventData(BaseEventData):
    mMaskDataName: Hash
    mBlendInTime: float
    mBlendOutTime: float
    pass

@MetaClass
class EnableLookAtEventData(BaseEventData):
    mEnableLookAt: bool
    mLockCurrentValues: bool
    pass

@MetaClass
class FaceCameraEventData(BaseEventData):
    m_0xb9cfc1ab: float
    BlendInTime: float
    BlendOutTime: float
    pass

@MetaClass
class FadeEventData(BaseEventData):
    mTimeToFade: float
    mTargetAlpha: float
    pass

@MetaClass
class IdleParticlesVisibilityEventData(BaseEventData):
    mShow: bool
    pass

@MetaClass
class JointSnapEventData(BaseEventData):
    mJointNameToOverride: Hash
    mJointNameToSnapTo: Hash
    pass

@MetaClassEmpty
class ValueProcessorData(MetaBase):
    pass

@MetaClass
class LinearTransformProcessorData(ValueProcessorData):
    mMultiplier: float
    mIncrement: float
    pass

@MetaClassEmpty
class LockRootOrientationEventData(BaseEventData):
    pass

@MetaClass
class ParticleEventDataPair(MetaBase):
    mBoneName: Hash
    mTargetBoneName: Hash
    pass

@MetaClass
class ParticleEventData(BaseEventData):
    mEffectKey: Hash
    mEnemyEffectKey: Hash
    mEffectName: str
    mParticleEventDataPairList: list[ParticleEventDataPair]
    mIsLoop: bool
    mIsKillEvent: bool
    mIsDetachable: bool
    mScalePlaySpeedWithAnimation: bool
    m_0xa3826203: bool
    pass

@MetaClass
class SoundEventData(BaseEventData):
    mSoundName: str
    mIsLoop: bool
    mIsKillEvent: bool
    m_0x067227d6: bool
    pass

@MetaClass
class StopAnimationEventData(BaseEventData):
    mStopAnimationName: Hash
    pass

@MetaClass
class SubmeshVisibilityEventData(BaseEventData):
    mShowSubmeshList: list[Hash]
    mHideSubmeshList: list[Hash]
    pass

@MetaClass
class SyncedAnimationEventData(BaseEventData):
    mLerpTime: float
    pass

@MetaClass
class TimeBlendData(BaseBlendData):
    mTime: float
    pass

@MetaClass
class TransitionClipBlendData(BaseBlendData):
    mClipName: Hash
    pass

@MetaClass
class EngineFeatureToggles(MetaBase):
    m_0x05fe6e49: bool
    m_0xcdbbc6e1: bool
    pass

@MetaClass
class t_0xc0c056f1(GenericMapPlaceable):
    PropName: str
    SkinId: UInt32
    PlayIdleAnimation: bool
    IdleAnimationName: str
    Quality: Int32
    IsClickable: bool
    EyeCandy: bool
    pass

@MetaClass
class MapAudio(GenericMapPlaceable):
    EventName: str
    AudioType: UInt32
    StartTime: float
    m_0xdf1b8a47: float
    m_0x518f49b9: float
    pass

@MetaClass
class MapCamera(MapPlaceable):
    m_0x6f3e4327: float
    m_0x563a1941: float
    Pitch: float
    Yaw: float
    FieldOfView: float
    pass

@MetaClassEmpty
class MapComponent(MetaBase):
    pass

@MetaClass
class MapContainer(MetaBase):
    MapPath: str
    Components: list[Optional[MapComponent]]
    BoundsMin: Vec2
    BoundsMax: Vec2
    LowestWalkableHeight: float
    m_0xf010defb: float
    Chunks: dict[Hash, Link[MapPlaceableContainer]]
    pass

@MetaClass
class MapContainsOtherMaps(MapComponent):
    MapContainerLocations: Link[MapPlaceableContainer]
    pass

@MetaClass
class LaneData(MetaBase):
    mNavigationPoints: list[str]
    mContainedRegions: list[str]
    pass

@MetaClass
class MapLaneComponent(MapComponent):
    mLanes: list[LaneData]
    pass

@MetaClassEmpty
class MapLocator(GenericMapPlaceable):
    pass

@MetaClass
class MapPathSegment(MetaBase):
    EndPosition: Vec3
    pass

@MetaClassEmpty
class MapPathLineSegment(MapPathSegment):
    pass

@MetaClass
class MapPathCurveSegment(MapPathSegment):
    ControlPoint1: Vec3
    ControlPoint2: Vec3
    pass

@MetaClass
class MapMotionPath(MapPlaceable):
    Segments: list[Optional[MapPathSegment]]
    pass

@MetaClass
class MapNavGrid(MapComponent):
    NavGridPath: str
    pass

@MetaClass
class MapPlaceableContainer(MetaBase):
    Items: dict[Hash, Optional[MapPlaceable]]
    pass

@MetaClass
class MapPrefabInstance(MapPlaceable):
    PrefabDefinition: Link[MapPlaceableContainer]
    pass

@MetaClass
class MapThemeMusic(MapComponent):
    LocalThemeMusic: str
    ThemeMusicTransitionEvent: str
    pass

@MetaClass
class RegionsThatAllowContent(MetaBase):
    mRegionList: list[Hash]
    pass

@MetaClass
class RegionSettings(MetaBase):
    mContentTypeAllowedSettings: dict[Hash, RegionsThatAllowContent]
    pass

@MetaClass
class FontLocaleType(MetaBase):
    LocaleName: str
    mFontFilePath: str
    FontFilePathBold: str
    FontFilePathItalics: str
    pass

@MetaClass
class FontResolution(MetaBase):
    ScreenHeight: UInt32
    FontSize: UInt32
    OutlineSize: UInt32
    ShadowDepthX: Int32
    ShadowDepthY: Int32
    pass

@MetaClass
class FontLocaleResolutions(MetaBase):
    LocaleName: str
    Resolutions: list[FontResolution]
    pass

@MetaClass
class FontType(MetaBase):
    LocaleTypes: list[FontLocaleType]
    pass

@MetaClass
class FontResolutionData(MetaBase):
    AutoScale: bool
    LocaleResolutions: list[FontLocaleResolutions]
    pass

@MetaClass
class GameFontDescription(MetaBase):
    Name: str
    TypeData: Link[FontType]
    ResolutionData: Link[FontResolutionData]
    color: Color
    OutlineColor: Color
    ShadowColor: Color
    GlowColor: Color
    m_0x3cc9ac15: Color
    ColorblindColor: Optional[Color]
    ColorblindOutlineColor: Optional[Color]
    ColorblindShadowColor: Optional[Color]
    ColorblindGlowColor: Optional[Color]
    m_0xc2008b7b: Optional[Color]
    FillTextureName: str
    pass

@MetaClass
class CssStyle(MetaBase):
    color: Optional[Color]
    Bold: Optional[bool]
    Italics: Optional[bool]
    Underline: Optional[bool]
    pass

@MetaClass
class CssIcon(MetaBase):
    Xy: Vec2
    Wh: Vec2
    m_0x81e208ef: float
    pass

@MetaClass
class CssSheet(MetaBase):
    Styles: dict[str, CssStyle]
    IconTexture: str
    Icons: dict[str, CssIcon]
    pass

@MetaClass
class TooltipFormat(MetaBase):
    mObjectName: str
    mInputLocKeysWithDefaults: dict[str, str]
    mListNames: list[str]
    mListTypeChoices: dict[str, str]
    mListStyles: dict[UInt32, str]
    mUsesListValues: bool
    mListValueSeparator: str
    mListGridPrefix: str
    mListGridPostfix: str
    mListGridSeparator: str
    mOutputStrings: dict[str, str]
    pass

@MetaClass
class TooltipInstanceListElement(MetaBase):
    Type: str
    TypeIndex: Int32
    Multiplier: float
    NameOverride: str
    Style: UInt32
    pass

@MetaClass
class TooltipInstanceList(MetaBase):
    LevelCount: UInt32
    Elements: list[TooltipInstanceListElement]
    pass

@MetaClass
class ValueFloat(MetaBase):
    ConstantValue: float
    Dynamics: Optional[VfxAnimatedFloatVariableData]
    pass

@MetaClassEmpty
class IntegratedValueFloat(ValueFloat):
    pass

@MetaClass
class ValueVector2(MetaBase):
    ConstantValue: Vec2
    Dynamics: Optional[VfxAnimatedVector2fVariableData]
    pass

@MetaClassEmpty
class IntegratedValueVector2(ValueVector2):
    pass

@MetaClass
class ValueVector3(MetaBase):
    ConstantValue: Vec3
    Dynamics: Optional[VfxAnimatedVector3fVariableData]
    pass

@MetaClassEmpty
class IntegratedValueVector3(ValueVector3):
    pass

@MetaClass
class ValueColor(MetaBase):
    ConstantValue: Vec4
    Dynamics: Optional[VfxAnimatedColorVariableData]
    pass

@MetaClass
class VfxAnimatedFloatVariableData(MetaBase):
    ProbabilityTables: list[Optional[VfxProbabilityTableData]]
    Times: list[float]
    Values: list[float]
    pass

@MetaClass
class VfxAnimatedVector2fVariableData(MetaBase):
    ProbabilityTables: list[Optional[VfxProbabilityTableData]]
    Times: list[float]
    Values: list[Vec2]
    pass

@MetaClass
class VfxAnimatedVector3fVariableData(MetaBase):
    ProbabilityTables: list[Optional[VfxProbabilityTableData]]
    Times: list[float]
    Values: list[Vec3]
    pass

@MetaClass
class VfxAnimatedColorVariableData(MetaBase):
    ProbabilityTables: list[Optional[VfxProbabilityTableData]]
    Times: list[float]
    Values: list[Vec4]
    pass

@MetaClass
class VfxSoftParticleDefinitionData(MetaBase):
    BeginIn: float
    BeginOut: float
    DeltaIn: float
    DeltaOut: float
    pass

@MetaClass
class FlexValueVector3(MetaBase):
    mFlexId: UInt32
    mValue: ValueVector3
    pass

@MetaClass
class FlexValueVector2(MetaBase):
    mFlexId: UInt32
    mValue: ValueVector2
    pass

@MetaClass
class FlexValueFloat(MetaBase):
    mFlexId: UInt32
    mValue: ValueFloat
    pass

@MetaClass
class FlexTypeFloat(MetaBase):
    mFlexId: UInt32
    mValue: float
    pass

@MetaClass
class ColorGraphMaterialDriver(IDynamicMaterialDriver):
    Driver: Optional[IDynamicMaterialFloatDriver]
    Colors: VfxAnimatedColorVariableData
    pass

@MetaClass
class VfxFieldAccelerationDefinitionData(MetaBase):
    IsLocalSpace: bool
    Acceleration: ValueVector3
    pass

@MetaClass
class VfxFieldAttractionDefinitionData(MetaBase):
    Position: ValueVector3
    Radius: ValueFloat
    Acceleration: ValueFloat
    pass

@MetaClass
class VfxFieldCollectionDefinitionData(MetaBase):
    FieldAccelerationDefinitions: list[VfxFieldAccelerationDefinitionData]
    FieldAttractionDefinitions: list[VfxFieldAttractionDefinitionData]
    FieldDragDefinitions: list[VfxFieldDragDefinitionData]
    FieldNoiseDefinitions: list[VfxFieldNoiseDefinitionData]
    FieldOrbitalDefinitions: list[VfxFieldOrbitalDefinitionData]
    pass

@MetaClass
class VfxFieldDragDefinitionData(MetaBase):
    Position: ValueVector3
    Radius: ValueFloat
    Strength: ValueFloat
    pass

@MetaClass
class VfxFieldNoiseDefinitionData(MetaBase):
    Position: ValueVector3
    Radius: ValueFloat
    Frequency: ValueFloat
    VelocityDelta: ValueFloat
    AxisFraction: Vec3
    pass

@MetaClass
class VfxFieldOrbitalDefinitionData(MetaBase):
    IsLocalSpace: bool
    Direction: ValueVector3
    pass

@MetaClass
class FloatGraphMaterialDriver(IDynamicMaterialDriver):
    Driver: Optional[IDynamicMaterialFloatDriver]
    Graph: VfxAnimatedFloatVariableData
    pass

@MetaClassEmpty
class IVfxMaterialDriver(MetaBase):
    pass

@MetaClass
class VfxMaterialOverrideDefinitionData(MetaBase):
    Priority: Int32
    SubMeshName: Optional[str]
    OverrideBlendMode: UInt32
    BaseTexture: str
    GlossTexture: str
    TransitionTexture: str
    TransitionSample: float
    TransitionSource: UInt32
    Material: Link[IMaterialDef]
    pass

@MetaClass
class VfxProbabilityTableData(MetaBase):
    KeyTimes: list[float]
    KeyValues: list[float]
    SingleValue: float
    pass

@MetaClass
class VfxSystemDefinitionData(IResource):
    MaterialOverrideDefinitions: list[VfxMaterialOverrideDefinitionData]
    ComplexEmitterDefinitionData: list[Optional[VfxEmitterDefinitionData]]
    SimpleEmitterDefinitionData: list[Optional[VfxEmitterDefinitionData]]
    VisibilityRadius: float
    ParticleName: str
    ParticlePath: str
    OverrideScaleCap: Optional[float]
    SoundOnCreateDefault: str
    VoiceOverOnCreateDefault: str
    SoundPersistentDefault: str
    VoiceOverPersistentDefault: str
    AssetCategory: str
    AudioParameterFlexId: Int32
    AudioParameterTimeScaledDuration: float
    DrawingLayer: UInt8
    Flags: UInt8
    BuildUpTime: float
    SelfIllumination: float
    AssetRemappingTable: list[VfxAssetRemap]
    SystemTranslation: Vec3
    SystemScale: Vec3
    HudLayerDimension: float
    HudLayerAspect: float
    HudAnchorPositionFromWorldProjection: bool
    ScaleDynamicallyWithAttachedBone: bool
    mEyeCandy: bool
    m_0xcf08f8e6: bool
    pass

@MetaClass
class VfxMigrationResources(MetaBase):
    ResourceMap: dict[Hash, Link[VfxSystemDefinitionData]]
    pass

@MetaClass
class VfxAssetRemap(MetaBase):
    Type: UInt32
    OldAsset: Hash
    NewAsset: str
    pass

@MetaClass
class VfxColorOverLifeMaterialDriver(IVfxMaterialDriver):
    Frequency: UInt8
    Colors: VfxAnimatedColorVariableData
    pass

@MetaClass
class VfxShape(MetaBase):
    BirthTranslation: ValueVector3
    EmitOffset: ValueVector3
    EmitRotationAngles: list[ValueFloat]
    EmitRotationAxes: list[Vec3]
    pass

@MetaClass
class VfxEmitterDefinitionData(MetaBase):
    EmitterName: str
    Disabled: bool
    DisableBackfaceCull: bool
    IsTexturePixelated: bool
    Material: Link[IMaterialDef]
    MaterialDrivers: dict[str, Optional[IVfxMaterialDriver]]
    RenderPhaseOverride: UInt8
    BlendMode: UInt8
    ColorblindVisibility: UInt8
    FieldCollectionDefinition: Optional[VfxFieldCollectionDefinitionData]
    MaterialOverrideDefinitions: list[VfxMaterialOverrideDefinitionData]
    SoftParticleParams: Optional[VfxSoftParticleDefinitionData]
    AlphaErosionDefinition: Optional[VfxAlphaErosionDefinitionData]
    PaletteDefinition: Optional[VfxPaletteDefinitionData]
    ReflectionDefinition: Optional[VfxReflectionDefinitionData]
    DistortionDefinition: Optional[VfxDistortionDefinitionData]
    EmissionSurfaceDefinition: Optional[VfxEmissionSurfaceData]
    Primitive: Optional[VfxPrimitiveBase]
    Pass: Int16
    MiscRenderFlags: UInt8
    MeshRenderFlags: UInt8
    ColorRenderFlags: UInt8
    StencilMode: UInt8
    StencilRef: UInt8
    AlphaRef: UInt8
    DepthBiasFactors: Vec2
    SliceTechniqueRange: float
    TexDiv: Vec2
    TexDivMult: Vec2
    Texture: str
    TextureMult: str
    ParticleColorTexture: str
    FalloffTexture: str
    TexAddressModeMult: UInt8
    UvMode: UInt8
    ColorLookUpTypeX: UInt8
    ColorLookUpTypeY: UInt8
    ColorLookUpScales: Vec2
    ColorLookUpOffsets: Vec2
    ModulationFactor: Vec4
    ScaleEmitOffsetByBoundObjectSize: float
    ScaleBirthScaleByBoundObjectSize: float
    ScaleEmitOffsetByBoundObjectHeight: float
    ScaleBirthScaleByBoundObjectHeight: float
    ScaleEmitOffsetByBoundObjectRadius: float
    ScaleBirthScaleByBoundObjectRadius: float
    KeywordsExcluded: list[str]
    KeywordsRequired: list[str]
    KeywordsIncluded: list[str]
    ExcludedAttachmentTypes: list[str]
    Importance: UInt8
    CensorPolicy: UInt8
    SpectatorPolicy: UInt8
    ParticleLingerType: UInt8
    ParticleLifetime: ValueFloat
    Lifetime: Optional[float]
    FlexParticleLifetime: Optional[FlexValueFloat]
    ParticleLinger: Optional[float]
    EmitterLinger: Optional[float]
    BirthVelocity: ValueVector3
    FlexBirthTranslation: Optional[FlexValueVector3]
    FlexBirthVelocity: Optional[FlexValueVector3]
    FlexScaleBirthScale: Optional[FlexTypeFloat]
    FlexBirthUvScrollRate: Optional[FlexValueVector2]
    FlexBirthUvScrollRateMult: Optional[FlexValueVector2]
    BirthColor: ValueColor
    BirthAcceleration: ValueVector3
    BirthRotationalAcceleration: ValueVector3
    BirthDrag: ValueVector3
    BirthOrbitalVelocity: ValueVector3
    BirthFrameRate: ValueFloat
    BirthUvoffset: ValueVector2
    BirthUvoffsetMult: ValueVector2
    FlexBirthUvoffset: Optional[FlexValueVector2]
    Rate: ValueFloat
    RateByVelocityFunction: ValueVector2
    MaximumRateByVelocity: Optional[float]
    FlexRate: Optional[FlexValueFloat]
    TimeBeforeFirstEmission: float
    m_0xcef2ba70: float
    TimeActiveDuringPeriod: Optional[float]
    Period: Optional[float]
    Shape: VfxShape
    FlexScaleEmitOffset: Optional[FlexTypeFloat]
    FlexOffset: Optional[FlexValueVector3]
    StartFrame: UInt16
    NumFrames: UInt16
    FrameRate: float
    SoundOnCreateName: str
    VoiceOverOnCreateName: str
    SoundPersistentName: str
    VoiceOverPersistentName: str
    CensorModulateValue: Vec4
    EmissionMeshName: str
    OffsetLifetimeScaling: Vec3
    OffsetLifeScalingSymmetryMode: UInt8
    EmitterUvScrollRate: Vec2
    EmitterUvScrollRateMult: Vec2
    TranslationOverride: Vec3
    RotationOverride: Vec3
    ScaleOverride: Vec3
    FlexInstanceScale: Optional[FlexTypeFloat]
    UvScrollAlphaMult: bool
    ParticleIsLocalOrientation: bool
    IsDirectionOriented: bool
    IsUniformScale: bool
    HasPostRotateOrientation: bool
    IsRandomStartFrame: bool
    IsRandomStartFrameMult: bool
    DoesCastShadow: bool
    IsRotationEnabled: bool
    UvScrollClamp: bool
    UvScrollClampMult: bool
    IsFollowingTerrain: bool
    IsGroundLayer: bool
    UseEmissionMeshNormalForBirth: bool
    UseNavmeshMask: bool
    m_0x676949a1: bool
    m_0x538effa4: bool
    IsSingleParticle: bool
    m_0xbd9b83c7: bool
    UseLingerRotation: bool
    IsLocalOrientation: bool
    UseLingerScale: bool
    HasFixedOrbit: bool
    LockedToEmitter: bool
    DoesLifetimeScale: bool
    DoesParticleLifetimeScale: bool
    UseLingerVelocity: bool
    UseLingerDrag: bool
    UseLingerAcceleration: bool
    UseLingerColor: bool
    m_0x51af37d2: bool
    ScaleUpFromOrigin: bool
    PostRotateOrientationAxis: Vec3
    BirthUvScrollRate: ValueVector2
    BirthUvScrollRateMult: ValueVector2
    BirthUvRotateRate: ValueFloat
    BirthUvRotateRateMult: ValueFloat
    UvRotation: ValueFloat
    ParticleUvScrollRate: IntegratedValueVector2
    ParticleUvScrollRateMult: IntegratedValueVector2
    ParticleUvRotateRate: IntegratedValueFloat
    ParticleUvRotateRateMult: IntegratedValueFloat
    DirectionVelocityScale: float
    DirectionVelocityMinScale: float
    UvParallaxScale: float
    Velocity: ValueVector3
    Acceleration: ValueVector3
    WorldAcceleration: IntegratedValueVector3
    color: ValueColor
    BindWeight: ValueFloat
    Drag: ValueVector3
    LingerVelocity: ValueVector3
    LingerAcceleration: ValueVector3
    LingerColor: ValueColor
    LingerDrag: ValueVector3
    ChildParticleSetDefinition: VfxChildParticleSetDefinitionData
    EmissionMeshScale: float
    TexAddressModeBase: UInt8
    FixedOrbitType: UInt8
    Orientation: UInt8
    ParticleBind: Vec2
    ScaleBias: Vec2
    BirthRotation0: ValueVector3
    BirthScale0: ValueVector3
    BirthRotationalVelocity0: ValueVector3
    FlexBirthRotationalVelocity0: Optional[FlexValueVector3]
    Scale0: ValueVector3
    Rotation0: IntegratedValueVector3
    UvScale: ValueVector2
    UvScaleMult: ValueVector2
    UvTransformCenter: Vec2
    UvTransformCenterMult: Vec2
    LingerRotation0: ValueVector3
    LingerScale0: ValueVector3
    BirthRotation1: ValueFloat
    BirthScale1: ValueFloat
    BirthRotationalVelocity1: ValueFloat
    FlexBirthRotationalVelocity1: Optional[FlexValueFloat]
    UvScrollRate1: Vec2
    Scale1: ValueFloat
    Rotation1: ValueFloat
    pass

@MetaClass
class VfxChildIdentifier(MetaBase):
    Effect: Link[VfxSystemDefinitionData]
    EffectKey: Hash
    EffectName: str
    pass

@MetaClass
class VfxChildParticleSetDefinitionData(MetaBase):
    ChildrenIdentifiers: list[VfxChildIdentifier]
    BoneToSpawnAt: list[str]
    ChildrenProbability: ValueFloat
    ChildEmitOnDeath: bool
    pass

@MetaClass
class VfxAlphaErosionDefinitionData(MetaBase):
    ErosionDriveCurve: ValueFloat
    ErosionDriveSource: UInt32
    UseLingerErosionDriveCurve: bool
    LingerErosionDriveCurve: ValueFloat
    ErosionFeatherIn: float
    ErosionFeatherOut: float
    ErosionSliceWidth: float
    ErosionMapName: str
    ErosionMapAddressMode: UInt8
    ErosionMapChannelMixer: ValueColor
    pass

@MetaClass
class VfxPaletteDefinitionData(MetaBase):
    PaletteTexture: str
    PaletteTextureAddressMode: UInt8
    PalleteSrcMixColor: ValueColor
    PaletteSelector: ValueVector3
    m_0x34d8fac6: ValueFloat
    m_0x44fd44cb: ValueFloat
    PaletteCount: Int32
    pass

@MetaClass
class VfxReflectionDefinitionData(MetaBase):
    ReflectionMapTexture: str
    ReflectionOpacityDirect: float
    ReflectionOpacityGlancing: float
    ReflectionFresnel: float
    ReflectionFresnelColor: Vec4
    Fresnel: float
    FresnelColor: Vec4
    pass

@MetaClass
class VfxDistortionDefinitionData(MetaBase):
    Distortion: float
    DistortionMode: UInt8
    NormalMapTexture: str
    pass

@MetaClass
class VfxProjectionDefinitionData(MetaBase):
    mYRange: float
    mFading: float
    pass

@MetaClass
class VfxTrailDefinitionData(MetaBase):
    mBirthTilingSize: ValueVector3
    mCutoff: float
    mMaxAddedPerFrame: Int32
    mSmoothingMode: UInt8
    mMode: UInt8
    pass

@MetaClass
class VfxBeamDefinitionData(MetaBase):
    mBirthTilingSize: ValueVector3
    mMode: UInt8
    mTrailMode: UInt8
    mSegments: Int32
    mLocalSpaceSourceOffset: Vec3
    mLocalSpaceTargetOffset: Vec3
    mIsColorBindedWithDistance: bool
    mAnimatedColorWithDistance: ValueColor
    pass

@MetaClass
class VfxEmissionSurfaceData(MetaBase):
    MeshName: str
    SkeletonName: str
    AnimationName: str
    MeshScale: float
    MaxJointWeights: UInt16
    UseAvatarPose: bool
    UseSurfaceNormalForBirthPhysics: bool
    pass

@MetaClass
class VfxMeshDefinitionData(MetaBase):
    mMeshName: str
    mMeshSkeletonName: str
    mSimpleMeshName: str
    mSubmeshesToDraw: list[Hash]
    mSubmeshesToDrawAlways: list[Hash]
    mLockMeshToAttachment: bool
    mAnimationName: str
    mAnimationVariants: list[str]
    pass

@MetaClassEmpty
class VfxPrimitiveBase(MetaBase):
    pass

@MetaClassEmpty
class VfxPrimitiveCameraQuad(VfxPrimitiveBase):
    pass

@MetaClassEmpty
class VfxPrimitiveArbitraryQuad(VfxPrimitiveBase):
    pass

@MetaClassEmpty
class VfxPrimitiveRay(VfxPrimitiveBase):
    pass

@MetaClass
class VfxPrimitiveProjectionBase(VfxPrimitiveBase):
    mProjection: VfxProjectionDefinitionData
    pass

@MetaClassEmpty
class VfxPrimitivePlanarProjection(VfxPrimitiveProjectionBase):
    pass

@MetaClass
class VfxPrimitiveTrailBase(VfxPrimitiveBase):
    mTrail: VfxTrailDefinitionData
    pass

@MetaClassEmpty
class VfxPrimitiveCameraTrail(VfxPrimitiveTrailBase):
    pass

@MetaClassEmpty
class VfxPrimitiveArbitraryTrail(VfxPrimitiveTrailBase):
    pass

@MetaClass
class VfxPrimitiveBeamBase(VfxPrimitiveBase):
    mBeam: VfxBeamDefinitionData
    pass

@MetaClassEmpty
class VfxPrimitiveCameraSegmentBeam(VfxPrimitiveBeamBase):
    pass

@MetaClassEmpty
class VfxPrimitiveArbitrarySegmentBeam(VfxPrimitiveBeamBase):
    pass

@MetaClass
class VfxPrimitiveMeshBase(VfxPrimitiveBase):
    mMesh: VfxMeshDefinitionData
    m_0xfbf6793f: bool
    m_0xea861daa: bool
    pass

@MetaClassEmpty
class VfxPrimitiveMesh(VfxPrimitiveMeshBase):
    pass

@MetaClassEmpty
class VfxPrimitiveAttachedMesh(VfxPrimitiveMeshBase):
    pass

@MetaClass
class VfxPrimitiveBeam(VfxPrimitiveBase):
    mBeam: VfxBeamDefinitionData
    mMesh: VfxMeshDefinitionData
    pass

@MetaClass
class VfxFloatOverLifeMaterialDriver(IVfxMaterialDriver):
    Frequency: UInt8
    Graph: VfxAnimatedFloatVariableData
    pass

@MetaClass
class VfxSineMaterialDriver(IVfxMaterialDriver):
    mFrequency: float
    mScale: float
    mBias: float
    pass

@MetaClass
class MapParticle(MapPlaceable):
    System: Link[VfxSystemDefinitionData]
    EyeCandy: bool
    Transitional: bool
    Quality: Int32
    VisibilityMode: UInt32
    ColorModulate: Vec4
    GroupName: str
    StartDisabled: bool
    pass

@MetaClass
class MapParticleGroups(MetaBase):
    Groups: list[str]
    pass

@MetaClass
class ColorChooserMaterialDriver(IDynamicMaterialDriver):
    mBoolDriver: Optional[IDynamicMaterialBoolDriver]
    mColorOn: Vec4
    mColorOff: Vec4
    pass

@MetaClass
class DelayedBoolMaterialDriver(IDynamicMaterialBoolDriver):
    mBoolDriver: Optional[IDynamicMaterialBoolDriver]
    mDelayOn: float
    mDelayOff: float
    pass

@MetaClass
class DynamicMaterialParameterDef(MetaBase):
    Name: str
    Driver: Optional[IDynamicMaterialDriver]
    Enabled: bool
    pass

@MetaClass
class DynamicMaterialTextureSwapOption(MetaBase):
    Driver: Optional[IDynamicMaterialBoolDriver]
    TextureName: str
    pass

@MetaClass
class DynamicMaterialTextureSwapDef(MetaBase):
    Name: str
    Options: list[DynamicMaterialTextureSwapOption]
    Enabled: bool
    pass

@MetaClass
class DynamicMaterialStaticSwitch(MetaBase):
    Name: str
    Driver: Optional[IDynamicMaterialBoolDriver]
    Enabled: bool
    pass

@MetaClass
class DynamicMaterialDef(MetaBase):
    m_0x5ed2db8d: bool
    Parameters: list[DynamicMaterialParameterDef]
    Textures: list[DynamicMaterialTextureSwapDef]
    StaticSwitch: Optional[DynamicMaterialStaticSwitch]
    pass

@MetaClass
class FixedDurationTriggeredBoolDriver(IDynamicMaterialBoolDriver):
    mBoolDriver: Optional[IDynamicMaterialBoolDriver]
    mCustomDuration: float
    pass

@MetaClass
class FloatComparisonMaterialDriver(IDynamicMaterialBoolDriver):
    mOperator: UInt32
    mValueA: Optional[IDynamicMaterialFloatDriver]
    mValueB: Optional[IDynamicMaterialFloatDriver]
    pass

@MetaClass
class FloatLiteralMaterialDriver(IDynamicMaterialFloatDriver):
    mValue: float
    pass

@MetaClass
class FloorFloatMaterialDriver(IDynamicMaterialFloatDriver):
    mDriver: Optional[IDynamicMaterialFloatDriver]
    pass

@MetaClass
class LerpMaterialDriver(IDynamicMaterialFloatDriver):
    mBoolDriver: Optional[IDynamicMaterialBoolDriver]
    mOnValue: float
    mOffValue: float
    mTurnOnTimeSec: float
    mTurnOffTimeSec: float
    m_0xa452be9f: bool
    pass

@MetaClass
class AllTrueMaterialDriver(IDynamicMaterialBoolDriver):
    mDrivers: list[Optional[IDynamicMaterialBoolDriver]]
    pass

@MetaClass
class OneTrueMaterialDriver(IDynamicMaterialBoolDriver):
    mDrivers: list[Optional[IDynamicMaterialBoolDriver]]
    pass

@MetaClass
class NotMaterialDriver(IDynamicMaterialBoolDriver):
    mDriver: Optional[IDynamicMaterialBoolDriver]
    pass

@MetaClass
class MaxMaterialDriver(IDynamicMaterialDriver):
    mDrivers: list[Optional[IDynamicMaterialDriver]]
    pass

@MetaClass
class MinMaterialDriver(IDynamicMaterialDriver):
    mDrivers: list[Optional[IDynamicMaterialDriver]]
    pass

@MetaClass
class RemapFloatMaterialDriver(IDynamicMaterialFloatDriver):
    mDriver: Optional[IDynamicMaterialFloatDriver]
    mMinValue: float
    mMaxValue: float
    mOutputMinValue: float
    mOutputMaxValue: float
    pass

@MetaClass
class SineMaterialDriver(IDynamicMaterialFloatDriver):
    mDriver: Optional[IDynamicMaterialFloatDriver]
    mFrequency: float
    mScale: float
    mBias: float
    pass

@MetaClass
class SpecificColorMaterialDriver(IDynamicMaterialDriver):
    mColor: Vec4
    pass

@MetaClass
class SwitchMaterialDriverElement(MetaBase):
    mCondition: Optional[IDynamicMaterialBoolDriver]
    mValue: Optional[IDynamicMaterialDriver]
    pass

@MetaClass
class SwitchMaterialDriver(IDynamicMaterialDriver):
    mElements: list[SwitchMaterialDriverElement]
    mDefaultValue: Optional[IDynamicMaterialDriver]
    pass

@MetaClass
class BlendingSwitchMaterialDriver(SwitchMaterialDriver):
    mBlendTime: float
    mOverrideBlendTimes: list[float]
    pass

@MetaClassEmpty
class TimeMaterialDriver(IDynamicMaterialFloatDriver):
    pass

@MetaClass
class IShaderDef(MetaBase):
    Parameters: list[ShaderPhysicalParameter]
    StaticSwitches: list[ShaderStaticSwitch]
    Textures: list[ShaderTexture]
    FeatureDefines: dict[str, str]
    FeatureMask: UInt32
    m_0x9bfe7d81: UInt32
    pass

@MetaClass
class CustomShaderDef(IShaderDef):
    ObjectPath: str
    pass

@MetaClass
class IdMappingEntry(MetaBase):
    Id: UInt16
    Count: UInt16
    pass

@MetaClass
class FixedShaderDef(IShaderDef):
    VertexShader: str
    PixelShader: str
    pass

@MetaClass
class HybridMaterialDefPreset(MetaBase):
    ShaderMacros: dict[str, str]
    DepthEnable: bool
    StencilEnable: bool
    BlendEnable: bool
    CullEnable: bool
    m_0xaab4104c: bool
    DepthCompareFunc: UInt8
    StencilCompareFunc: UInt8
    StencilReferenceVal: UInt32
    StencilMask: UInt32
    StencilFailOp: UInt8
    StencilPassDepthFailOp: UInt8
    StencilPassDepthPassOp: UInt8
    SrcColorBlendFactor: UInt8
    SrcAlphaBlendFactor: UInt8
    DstColorBlendFactor: UInt8
    DstAlphaBlendFactor: UInt8
    BlendEquation: UInt8
    WindingToCull: UInt8
    WriteMask: UInt8
    DepthOffsetSlope: float
    DepthOffsetBias: float
    pass

@MetaClass
class HybridMaterialDef(CustomShaderDef):
    Name: str
    Type: UInt32
    DataCollections: MaterialDataCollections
    Preset: Link[HybridMaterialDefPreset]
    ShaderMacros: dict[str, str]
    pass

@MetaClassEmpty
class IMaterialDef(MetaBase):
    pass

@MetaClass
class ShaderLogicalParameter(MetaBase):
    Name: str
    Fields: UInt32
    pass

@MetaClass
class ShaderPhysicalParameter(MetaBase):
    Name: str
    Data: Vec4
    LogicalParameters: list[ShaderLogicalParameter]
    pass

@MetaClass
class ShaderStaticSwitch(MetaBase):
    Name: str
    OnByDefault: bool
    pass

@MetaClass
class ShaderTexture(MetaBase):
    Name: str
    DefaultTexturePath: str
    pass

@MetaClass
class MaterialParameterData(MetaBase):
    Type: UInt8
    DefaultValue: Vec4
    pass

@MetaClass
class MaterialTextureData(MetaBase):
    DefaultTexturePath: str
    AddressU: UInt8
    AddressV: UInt8
    AddressW: UInt8
    FilterMin: UInt8
    FilterMip: UInt8
    FilterMag: UInt8
    pass

@MetaClass
class MaterialSwitchData(MetaBase):
    On: bool
    pass

@MetaClass
class MaterialParameterDataCollection(MetaBase):
    NextId: UInt16
    Entries: dict[str, IdMappingEntry]
    m_0xea57bf12: str
    Data: dict[UInt16, MaterialParameterData]
    pass

@MetaClass
class MaterialTextureDataCollection(MetaBase):
    NextId: UInt16
    Entries: dict[str, IdMappingEntry]
    m_0xea57bf12: str
    Data: dict[UInt16, MaterialTextureData]
    pass

@MetaClass
class MaterialSwitchDataCollection(MetaBase):
    NextId: UInt16
    Entries: dict[str, IdMappingEntry]
    m_0xea57bf12: str
    Data: dict[UInt16, MaterialSwitchData]
    pass

@MetaClass
class MaterialDataCollections(MetaBase):
    ParameterData: MaterialParameterDataCollection
    TextureData: MaterialTextureDataCollection
    SwitchData: MaterialSwitchDataCollection
    pass

@MetaClass
class MaterialInstanceParamDef(MetaBase):
    Value: Vec4
    pass

@MetaClass
class MaterialInstanceSwitchDef(MetaBase):
    On: bool
    pass

@MetaClass
class MaterialInstanceTextureDef(MetaBase):
    TexturePath: str
    UncensoredTextures: dict[Hash, str]
    pass

@MetaClass
class t_0xf7084b4a(MetaBase):
    Name: str
    ShaderMacros: dict[str, str]
    pass

@MetaClass
class MaterialInstanceDynamicParam(MetaBase):
    Enabled: bool
    Driver: Optional[IDynamicMaterialDriver]
    pass

@MetaClass
class MaterialInstanceDynamicSwitch(MetaBase):
    Enabled: bool
    Driver: Optional[IDynamicMaterialBoolDriver]
    pass

@MetaClass
class MaterialInstanceDynamicTexture(MetaBase):
    Enabled: bool
    Options: list[DynamicMaterialTextureSwapOption]
    pass

@MetaClass
class MaterialInstanceDef(IResource, IMaterialDef):
    Name: str
    BaseMaterial: Link[HybridMaterialDef]
    ChildTechniques: list[t_0xf7084b4a]
    ShaderMacros: dict[str, str]
    Params: dict[UInt16, MaterialInstanceParamDef]
    Switches: dict[UInt16, MaterialInstanceSwitchDef]
    Textures: dict[UInt16, MaterialInstanceTextureDef]
    DynamicParams: dict[UInt16, MaterialInstanceDynamicParam]
    DynamicTextures: dict[UInt16, MaterialInstanceDynamicTexture]
    DynamicSwitch: MaterialInstanceDynamicSwitch
    DynamicSwitchId: UInt16
    pass

@MetaClass
class StaticMaterialShaderParamDef(MetaBase):
    Name: str
    Value: Vec4
    pass

@MetaClass
class StaticMaterialSwitchDef(MetaBase):
    Name: str
    On: bool
    pass

@MetaClass
class StaticMaterialShaderSamplerDef(MetaBase):
    SamplerName: str
    TextureName: str
    UncensoredTextures: dict[Hash, str]
    AddressU: UInt32
    AddressV: UInt32
    AddressW: UInt32
    FilterMin: UInt32
    FilterMip: UInt32
    FilterMag: UInt32
    pass

@MetaClass
class StaticMaterialPassDef(MetaBase):
    Shader: Link[IShaderDef]
    ShaderMacros: dict[str, str]
    ParamValues: list[StaticMaterialShaderParamDef]
    DepthEnable: bool
    StencilEnable: bool
    BlendEnable: bool
    CullEnable: bool
    m_0xaab4104c: bool
    DepthCompareFunc: UInt32
    StencilCompareFunc: UInt32
    StencilReferenceVal: UInt32
    StencilMask: UInt32
    StencilFailOp: UInt32
    StencilPassDepthFailOp: UInt32
    StencilPassDepthPassOp: UInt32
    SrcColorBlendFactor: UInt32
    SrcAlphaBlendFactor: UInt32
    DstColorBlendFactor: UInt32
    DstAlphaBlendFactor: UInt32
    BlendEquation: UInt32
    WindingToCull: UInt32
    WriteMask: UInt32
    DepthOffsetSlope: float
    DepthOffsetBias: float
    pass

@MetaClass
class StaticMaterialTechniqueDef(MetaBase):
    Name: str
    Passes: list[StaticMaterialPassDef]
    pass

@MetaClass
class StaticMaterialChildTechniqueDef(MetaBase):
    Name: str
    ParentName: str
    ShaderMacros: dict[str, str]
    pass

@MetaClass
class StaticMaterialDef(IResource, IMaterialDef):
    Name: str
    Type: UInt32
    DefaultTechnique: str
    SamplerValues: list[StaticMaterialShaderSamplerDef]
    ParamValues: list[StaticMaterialShaderParamDef]
    Switches: list[StaticMaterialSwitchDef]
    ShaderMacros: dict[str, str]
    Techniques: list[StaticMaterialTechniqueDef]
    ChildTechniques: list[StaticMaterialChildTechniqueDef]
    DynamicMaterial: Optional[DynamicMaterialDef]
    pass

@MetaClass
class MapPerInstanceInfo(MetaBase):
    ShadowMapPath: str
    ShadowMapUvScaleAndBias: Vec4
    pass

@MetaClass
class MapBakeProperties(MapComponent):
    LightGridSize: UInt32
    m_0x22d24a9a: float
    LightGridCharacterFullBrightIntensity: float
    m_0xea4e5cc8: float
    m_0x2f3b5471: float
    LightGridFileName: str
    pass

@MetaClass
class MapCloudsLayer(MetaBase):
    Direction: Vec2
    Scale: float
    Speed: float
    pass

@MetaClassEmpty
class MapGraphicsFeature(MapComponent):
    pass

@MetaClass
class MapClouds(MapGraphicsFeature):
    CloudsTexturePath: str
    m_0x64847953: Vec4
    IsEyeCandy: bool
    Layers: list[MapCloudsLayer]
    pass

@MetaClass
class MapLightingV2(MapGraphicsFeature):
    m_0xee91017d: float
    m_0xc916a9fc: float
    pass

@MetaClass
class MapLightingVolume(MapPlaceable):
    SunColor: Vec4
    SunDirection: Vec3
    m_0xa04bd9bf: Optional[Vec3]
    m_0xd8851203: float
    m_0xba02f116: float
    SkyLightColor: Vec4
    HorizonColor: Vec4
    GroundColor: Vec4
    SkyLightScale: float
    LightMapColorScale: float
    FogEnabled: bool
    FogColor: Vec4
    FogAlternateColor: Vec4
    FogStartAndEnd: Vec2
    FogEmissiveRemap: float
    FogLowQualityModeEmissiveRemap: float
    pass

@MetaClass
class MapPointLight(MapPlaceable):
    Type: Link[MapPointLightType]
    RadiusScale: float
    IntensityScale: float
    OverrideCastStaticShadows: Optional[bool]
    OverrideUseSpecular: Optional[bool]
    pass

@MetaClass
class MapPointLightType(MetaBase):
    LightColor: Vec4
    FalloffColor: Vec4
    Radius: float
    CastStaticShadows: bool
    Specular: bool
    Impact: Int32
    pass

@MetaClass
class MapSunProperties(MapComponent):
    SunColor: Vec4
    SunDirection: Vec3
    m_0xa04bd9bf: Optional[Vec3]
    m_0xd8851203: float
    m_0xba02f116: float
    SkyLightColor: Vec4
    HorizonColor: Vec4
    GroundColor: Vec4
    SkyLightScale: float
    LightMapColorScale: float
    FogEnabled: bool
    FogColor: Vec4
    FogAlternateColor: Vec4
    FogStartAndEnd: Vec2
    FogEmissiveRemap: float
    FogLowQualityModeEmissiveRemap: float
    UseBloom: bool
    SurfaceAreaToShadowMapScale: float
    pass

@MetaClass
class MapTerrainPaint(MapGraphicsFeature):
    TerrainPaintTexturePath: str
    pass

@MetaClass
class ShData(MetaBase):
    BandData: list[Vec3]
    pass

@MetaClass
class SkinMeshDataProperties_MaterialOverride(MetaBase):
    Material: Link[IMaterialDef]
    Texture: str
    GlossTexture: str
    Submesh: str
    pass

@MetaClass
class SkinMeshDataProperties(MetaBase):
    Skeleton: str
    SimpleSkin: str
    Texture: str
    EmissiveTexture: str
    GlossTexture: str
    SkinScale: float
    SelfIllumination: float
    m_0xd62df07c: bool
    BrushAlphaOverride: float
    OverrideBoundingBox: Optional[Vec3]
    Material: Link[IMaterialDef]
    BoundingCylinderRadius: float
    BoundingCylinderHeight: float
    BoundingSphereRadius: Optional[float]
    FresnelColor: Color
    Fresnel: float
    UsesSkinVo: bool
    CastShadows: bool
    AllowCharacterInking: bool
    ReflectionMap: str
    ReflectionOpacityDirect: float
    ReflectionOpacityGlancing: float
    ReflectionFresnel: float
    ReflectionFresnelColor: Color
    InitialSubmeshToHide: str
    InitialSubmeshShadowsToHide: str
    InitialSubmeshMouseOversToHide: str
    SubmeshRenderOrder: str
    m_0x2543480a: bool
    RigPoseModifierData: list[Optional[BaseRigPoseModifierData]]
    MaterialOverride: list[SkinMeshDataProperties_MaterialOverride]
    MaterialController: Optional[SkinnedMeshDataMaterialController]
    pass

@MetaClassEmpty
class IResourceResolver(MetaBase):
    pass

@MetaClass
class BaseResourceResolver(IResourceResolver):
    ResourceMap: dict[Hash, Link[IResource]]
    pass

@MetaClassEmpty
class GlobalResourceResolver(BaseResourceResolver):
    pass

@MetaClassEmpty
class ResourceResolver(BaseResourceResolver):
    pass

@MetaClass
class IScriptBlock(MetaBase):
    IsDisabled: bool
    pass

@MetaClass
class SetVarInTableBlock(IScriptBlock):
    Dest: ScriptTableSet
    Value: Optional[IScriptValueGet]
    pass

@MetaClass
class ScriptCommentBlock(IScriptBlock):
    Sequence: ScriptSequence
    pass

@MetaClass
class ConcatenateStringsBlock(IScriptBlock):
    String1: Optional[IStringGet]
    String2: Optional[IStringGet]
    Result: StringTableSet
    pass

@MetaClass
class CreateCustomTableBlock(IScriptBlock):
    CustomTable: CustomTableSet
    pass

@MetaClass
class DestroyCustomTableBlock(IScriptBlock):
    CustomTable: CustomTableSet
    pass

@MetaClass
class SetKeyValueInCustomTableBlock(IScriptBlock):
    CustomTable: CustomTableGet
    Key: Optional[IScriptValueGet]
    Value: Optional[IScriptValueGet]
    pass

@MetaClass
class GetKeyValueInCustomTableBlock(IScriptBlock):
    CustomTable: CustomTableGet
    Key: Optional[IScriptValueGet]
    OutValue: ScriptTableSet
    pass

@MetaClass
class InsertIntoCustomTableBlock(IScriptBlock):
    CustomTable: CustomTableGet
    Index: Optional[IIntGet]
    Value: Optional[IScriptValueGet]
    OutIndex: IntTableSet
    pass

@MetaClass
class RemoveFromCustomTableBlock(IScriptBlock):
    CustomTable: CustomTableGet
    Key: Optional[IScriptValueGet]
    Index: Optional[IIntGet]
    pass

@MetaClass
class GetSizeOfCustomTableBlock(IScriptBlock):
    CustomTable: CustomTableGet
    OutSize: ScriptTableSet
    pass

@MetaClass
class ForEachInCustomTableBlock(IScriptBlock):
    CustomTable: CustomTableGet
    SortedByKeys: bool
    OutKey: ScriptTableSet
    OutValue: ScriptTableSet
    Sequence: ScriptSequence
    pass

@MetaClass
class CustomTableContainsValueBlock(IScriptBlock):
    CustomTable: CustomTableGet
    Value: Optional[IScriptValueGet]
    OutKey: ScriptTableSet
    OutWasFound: BoolTableSet
    pass

@MetaClass
class FunctionDefinition(MetaBase):
    InputParameters: list[Hash]
    OutputParameters: list[Hash]
    Sequence: ScriptSequence
    pass

@MetaClass
class CreateFunctionBlock(IScriptBlock):
    Function: FunctionTableSet
    FunctionDefinition: FunctionDefinition
    pass

@MetaClass
class IRunFunctionBlock(IScriptBlock):
    Function: FunctionTableGet
    InputParameters: list[Optional[IScriptValueGet]]
    OutputParameters: list[ScriptTableSet]
    pass

@MetaClass
class SwitchCase(MetaBase):
    Condition: Optional[IScriptCondition]
    Sequence: ScriptSequence
    IsDisabled: bool
    pass

@MetaClass
class SwitchScriptBlock(IScriptBlock):
    Cases: list[SwitchCase]
    pass

@MetaClassEmpty
class IScriptCondition(MetaBase):
    pass

@MetaClass
class TableValueExistsScriptCondition(IScriptCondition):
    TableValue: ScriptTableGet
    pass

@MetaClass
class RandomChanceScriptCondition(IScriptCondition):
    Chance: Optional[IFloatGet]
    pass

@MetaClass
class AndScriptCondition(IScriptCondition):
    Conditions: list[Optional[IScriptCondition]]
    pass

@MetaClass
class OrScriptCondition(IScriptCondition):
    Conditions: list[Optional[IScriptCondition]]
    pass

@MetaClass
class NotScriptCondition(IScriptCondition):
    Condition: Optional[IScriptCondition]
    pass

@MetaClass
class ComparisonScriptCondition(IScriptCondition):
    Value1: Optional[IScriptValueGet]
    Value2: Optional[IScriptValueGet]
    Operation: UInt32
    pass

@MetaClassEmpty
class IScriptSequence(Rscript):
    pass

@MetaClass
class ScriptSequence(IScriptSequence):
    Blocks: list[Optional[IScriptBlock]]
    pass

@MetaClassEmpty
class PassThroughParamsTable(ScriptTable):
    pass

@MetaClassEmpty
class IScriptValueGet(MetaBase):
    pass

@MetaClassEmpty
class IBoolGet(IScriptValueGet):
    pass

@MetaClass
class BoolGet(IBoolGet):
    Value: bool
    pass

@MetaClass
class BoolTableGet(IBoolGet):
    Table: Optional[ScriptTable]
    Var: Hash
    Default: Optional[bool]
    pass

@MetaClass
class CustomTableGet(IScriptValueGet):
    Table: Optional[ScriptTable]
    Var: Hash
    pass

@MetaClassEmpty
class IFloatGet(IScriptValueGet):
    pass

@MetaClass
class FloatGet(IFloatGet):
    Value: float
    pass

@MetaClass
class FloatTableGet(IFloatGet):
    Table: Optional[ScriptTable]
    Var: Hash
    Default: Optional[float]
    pass

@MetaClass
class FloatOffsetTableGet(IFloatGet):
    Table: Optional[ScriptTable]
    Var: Hash
    Offset: float
    pass

@MetaClassEmpty
class IFunctionGet(IScriptValueGet):
    pass

@MetaClass
class FunctionTableGet(IFunctionGet):
    Table: Optional[ScriptTable]
    Var: Hash
    pass

@MetaClassEmpty
class IIntGet(IScriptValueGet):
    pass

@MetaClass
class IntGet(IIntGet):
    Value: Int32
    pass

@MetaClass
class IntTableGet(IIntGet):
    Table: Optional[ScriptTable]
    Var: Hash
    Default: Optional[Int32]
    pass

@MetaClass
class IntOffsetTableGet(IIntGet):
    Table: Optional[ScriptTable]
    Var: Hash
    Offset: Int32
    pass

@MetaClass
class ScriptTableGet(IScriptValueGet):
    Table: Optional[ScriptTable]
    Var: Hash
    pass

@MetaClass
class ScriptTableSet(MetaBase):
    Table: Optional[ScriptTable]
    Var: Hash
    pass

@MetaClassEmpty
class IntTableSet(ScriptTableSet):
    pass

@MetaClassEmpty
class BoolTableSet(ScriptTableSet):
    pass

@MetaClassEmpty
class FloatTableSet(ScriptTableSet):
    pass

@MetaClassEmpty
class StringTableSet(ScriptTableSet):
    pass

@MetaClassEmpty
class VectorTableSet(ScriptTableSet):
    pass

@MetaClassEmpty
class FunctionTableSet(ScriptTableSet):
    pass

@MetaClassEmpty
class CustomTableSet(ScriptTableSet):
    pass

@MetaClassEmpty
class IStringGet(IScriptValueGet):
    pass

@MetaClass
class StringGet(IStringGet):
    Value: str
    pass

@MetaClass
class StringTableGet(IStringGet):
    Table: Optional[ScriptTable]
    Var: Hash
    Default: Optional[str]
    pass

@MetaClassEmpty
class IVectorGet(IScriptValueGet):
    pass

@MetaClass
class VectorGet(IVectorGet):
    Value: Vec3
    pass

@MetaClass
class VectorTableGet(IVectorGet):
    Table: Optional[ScriptTable]
    Var: Hash
    Default: Optional[Vec3]
    pass

@MetaClass
class t_0xd1951f45(MetaBase):
    TransitionTime: float
    StartAlpha: UInt8
    EndAlpha: UInt8
    EasingType: UInt8
    pass

@MetaClassEmpty
class t_0x8f1e6a22(t_0xd1951f45):
    pass

@MetaClass
class t_0x6ce97639(t_0xd1951f45):
    Edge: UInt8
    pass

@MetaClass
class SceneData(MetaBase):
    mName: str
    mParentScene: Link[SceneData]
    mLayer: UInt32
    SceneTransitionIn: Optional[t_0xd1951f45]
    SceneTransitionOut: Optional[t_0xd1951f45]
    mEnabled: bool
    mHealthBar: bool
    m_0x22413173: bool
    m_0xf80397ee: bool
    pass

@MetaClassEmpty
class AnchorBase(MetaBase):
    pass

@MetaClass
class AnchorSingle(AnchorBase):
    Anchor: Vec2
    pass

@MetaClass
class AnchorDouble(AnchorBase):
    AnchorLeft: Vec2
    AnchorRight: Vec2
    pass

@MetaClass
class AtlasDataBase(MetaBase):
    mTextureName: str
    mTextureSourceResolutionWidth: UInt32
    mTextureSourceResolutionHeight: UInt32
    pass

@MetaClass
class AtlasData(AtlasDataBase):
    mTextureUv: Vec4
    pass

@MetaClass
class t_0xb5d136db(AtlasDataBase):
    TextureUs: Vec4
    TextureVs: Vec2
    m_0x1b57cc27: Vec2
    pass

@MetaClass
class t_0xa3d11a85(AtlasDataBase):
    TextureUs: Vec2
    TextureVs: Vec4
    m_0x15ec9181: Vec2
    pass

@MetaClass
class t_0xab3d1567(AtlasDataBase):
    TextureUs: Vec4
    TextureVs: Vec4
    m_0x15ec9181: Vec2
    m_0x1b57cc27: Vec2
    pass

@MetaClass
class t_0x231dd1a2(MetaBase):
    mName: str
    mScene: Link[SceneData]
    pass

@MetaClass
class BaseElementData(t_0x231dd1a2):
    mEnabled: bool
    mKeepMaxScale: bool
    mFullscreen: bool
    mNoPixelSnappingX: bool
    mNoPixelSnappingY: bool
    m_0x258bae9a: bool
    mUseRectSourceResolutionAsFloor: bool
    StickyDrag: bool
    mDraggable: UInt32
    mLayer: UInt32
    mRectSourceResolutionWidth: UInt16
    mRectSourceResolutionHeight: UInt16
    mAnchors: Optional[AnchorBase]
    mRect: Vec4
    mHitTestPolygon: list[Vec2]
    pass

@MetaClassEmpty
class EffectElementData(BaseElementData):
    pass

@MetaClass
class EffectCooldownElementData(EffectElementData):
    mEffectColor0: Color
    mEffectColor1: Color
    pass

@MetaClass
class EffectCircleMaskCooldownElementData(EffectElementData):
    mEffectColor0: Color
    mEffectColor1: Color
    pass

@MetaClass
class EffectCooldownRadialElementData(EffectElementData):
    mFlipX: bool
    mFlipY: bool
    mPerPixelUvsX: bool
    mAtlas: Optional[AtlasData]
    mIsFill: bool
    pass

@MetaClass
class EffectArcFillElementData(EffectElementData):
    mFlipX: bool
    mFlipY: bool
    mPerPixelUvsX: bool
    mAtlas: Optional[AtlasData]
    pass

@MetaClass
class EffectAmmoElementData(EffectElementData):
    mEffectColor0: Color
    mEffectColor1: Color
    pass

@MetaClass
class EffectGlowElementData(EffectElementData):
    CycleTime: float
    BaseScale: float
    CycleBasedScaleAddition: float
    MinimumAlpha: float
    mFlipX: bool
    mFlipY: bool
    mPerPixelUvsX: bool
    mAtlas: Optional[AtlasData]
    pass

@MetaClass
class EffectAnimationElementData(EffectElementData):
    FramesPerSecond: float
    TotalNumberOfFrames: float
    NumberOfFramesPerRowInAtlas: float
    mFlipX: bool
    mFlipY: bool
    mPerPixelUvsX: bool
    mAtlas: Optional[AtlasData]
    mLooping: bool
    mFinishBehavior: UInt8
    pass

@MetaClass
class EffectFillPercentageElementData(EffectElementData):
    mFlipX: bool
    mFlipY: bool
    mPerPixelUvsX: bool
    mAtlas: Optional[AtlasData]
    pass

@MetaClass
class EffectDesaturateElementData(EffectElementData):
    MinimumSaturation: float
    MaximumSaturation: float
    mFlipX: bool
    mFlipY: bool
    mPerPixelUvsX: bool
    mAtlas: Optional[AtlasData]
    pass

@MetaClass
class EffectRotatingIconElementData(EffectElementData):
    mAtlas: Optional[AtlasData]
    pass

@MetaClass
class EffectGlowingRotatingIconElementData(EffectRotatingIconElementData):
    CycleTime: float
    m_0x054c178e: float
    pass

@MetaClassEmpty
class EffectAnimatedRotatingIconElementData(EffectAnimationElementData):
    pass

@MetaClass
class EffectLineElementData(EffectElementData):
    mAtlas: Optional[AtlasData]
    mThickness: float
    mRightSlicePercentage: float
    pass

@MetaClass
class EffectInstancedElementData(EffectElementData):
    mFlipX: bool
    mFlipY: bool
    mPerPixelUvsX: bool
    mAtlas: Optional[AtlasData]
    mAdditionalOffsets: list[Vec2]
    pass

@MetaClassEmpty
class EffectCircleMaskDesaturateElementData(EffectDesaturateElementData):
    pass

@MetaClass
class t_0xf6fd1c96(EffectElementData):
    mMaterial: Link[StaticMaterialDef]
    pass

@MetaClassEmpty
class IconElementDataExtension(MetaBase):
    pass

@MetaClass
class IconElementGradientExtension(IconElementDataExtension):
    mStartColor: Vec4
    mEndColor: Vec4
    mGradientDirection: UInt32
    m_0x4dff519d: Vec4
    mAlphaTexture: str
    pass

@MetaClass
class IconElementData(BaseElementData):
    mColor: Color
    mUseAlpha: bool
    mFlipX: bool
    mFlipY: bool
    mPerPixelUvsX: bool
    mAtlas: Optional[AtlasDataBase]
    mMaterial: Link[StaticMaterialDef]
    mExtension: Optional[IconElementDataExtension]
    pass

@MetaClass
class ParticleSystemElementData(BaseElementData):
    mVfxSystem: Link[VfxSystemDefinitionData]
    m_0xc47cf6c7: UInt32
    m_0x02824440: bool
    m_0x94b088ea: bool
    m_0x8ef629c9: bool
    pass

@MetaClassEmpty
class RegionElementData(BaseElementData):
    pass

@MetaClass
class ScissorRegionElementData(BaseElementData):
    m_0xaccc80b5: Link[SceneData]
    pass

@MetaClass
class TextElementData(BaseElementData):
    TraKey: str
    mFontDescription: Link[GameFontDescription]
    mTextAlignmentHorizontal: UInt8
    mTextAlignmentVertical: UInt8
    WrappingMode: UInt8
    IconScale: float
    m_0x7c0a8359: Link[CssSheet]
    pass

@MetaClass
class t_0x63394a54(MetaBase):
    DefaultStateElements: list[Hash]
    InactiveStateElements: list[Hash]
    HoverStateElements: list[Hash]
    m_0xad0f8882: list[Hash]
    SelectedStateElements: list[Hash]
    SelectedHoverStateElements: list[Hash]
    SelectedClickedStateElements: list[Hash]
    pass

@MetaClass
class t_0xfc2d67aa(MetaBase):
    RolloverEvent: str
    m_0x210ea29e: str
    MouseDownEvent: str
    m_0x0452034c: str
    MouseUpEvent: str
    m_0xb49ca145: str
    pass

@MetaClass
class t_0x6780c1c5(MetaBase):
    DisplayElements: list[Link[t_0x231dd1a2]]
    TextElement: Link[TextElementData]
    pass

@MetaClass
class t_0x89fa8d1c(t_0x231dd1a2):
    Elements: list[Link[t_0x231dd1a2]]
    pass

@MetaClass
class t_0x25e82b58(t_0x89fa8d1c):
    DefaultStateElements: t_0x6780c1c5
    InactiveStateElements: t_0x6780c1c5
    HoverStateElements: t_0x6780c1c5
    m_0xad0f8882: t_0x6780c1c5
    SelectedStateElements: t_0x6780c1c5
    SelectedHoverStateElements: t_0x6780c1c5
    SelectedClickedStateElements: t_0x6780c1c5
    HitRegionElement: Link[RegionElementData]
    ClickReleaseParticleElement: Link[ParticleSystemElementData]
    SoundEvents: Optional[t_0xfc2d67aa]
    ActiveTooltipTraKey: str
    InactiveTooltipTraKey: str
    IsActive: bool
    IsEnabled: bool
    IsSelected: bool
    pass

@MetaClass
class t_0x345c1c77(t_0x89fa8d1c):
    m_0x76ef64de: Link[IconElementData]
    pass

@MetaClass
class t_0xa51270e5(MetaBase):
    m_0xa1527ead: UInt8
    m_0xf00a885b: UInt8
    pass

@MetaClass
class t_0x26f2a088(t_0xa51270e5):
    m_0xbbd94716: UInt8
    pass

@MetaClass
class t_0xb277fa06(t_0xa51270e5):
    m_0xb49ed6f0: UInt8
    pass

@MetaClass
class t_0xd7d5f570(t_0xa51270e5):
    m_0x590bd78c: UInt8
    m_0xbbd94716: UInt8
    pass

@MetaClass
class t_0x89a3465f(t_0x89fa8d1c):
    Region: Link[RegionElementData]
    m_0xfa4c41a0: Optional[t_0xa51270e5]
    pass

@MetaClass
class t_0x560e6c39(MetaBase):
    m_0xd8073196: str
    m_0x8f1a336d: str
    m_0x73dbef7a: str
    pass

@MetaClass
class t_0xdf3bdc62(MetaBase):
    BarBackdrop: Link[IconElementData]
    BarFill: Link[IconElementData]
    SliderIcon: Link[IconElementData]
    pass

@MetaClass
class t_0x474f1541(t_0x89fa8d1c):
    DefaultState: t_0xdf3bdc62
    SliderClickedState: t_0xdf3bdc62
    m_0x05b9cbd0: t_0xdf3bdc62
    m_0xb4f0cbde: t_0xdf3bdc62
    BarHitRegion: Link[RegionElementData]
    SliderHitRegion: Link[RegionElementData]
    Direction: UInt8
    SoundEvents: Optional[t_0x560e6c39]
    pass

@MetaClass
class X3dSharedConstantDef(MetaBase):
    Name: str
    Type: UInt32
    Count: UInt32
    Register: Int32
    SetManually: bool
    PlatformMask: UInt32
    pass

@MetaClass
class X3dSharedConstantBufferDef(MetaBase):
    Name: str
    Type: UInt32
    Frequency: UInt32
    Constants: list[X3dSharedConstantDef]
    m_0xa87049bc: bool
    Register: Int32
    PlatformMask: UInt32
    pass

@MetaClass
class X3dSharedData(MetaBase):
    m_0xe595dd78: list[Link[X3dSharedConstantBufferDef]]
    Textures: list[X3dSharedTextureDef]
    pass

@MetaClass
class X3dSharedTextureDef(MetaBase):
    Name: str
    Type: UInt32
    Register: Int32
    PlatformMask: UInt32
    pass
