struct WardSkinDisabler { // 0x14
   // ctor: 0x004DF4F0
   // init: 0x004DF4A0
    bool DisableAllSkins; // 0x4
    vector_t<uint32_t> DisabledIds; // 0x8
};
struct IContextualAction: PropertyBase { // 0xC
   // ctor: 0x00400000
   // init: 0x00400000
    hash_t mHashedSituationTrigger; // 0x4
    uint32_t mMaxOccurences; // 0x8
};
struct ContextualActionPlayAnimation: IContextualAction { // 0x14
   // ctor: 0x00507E20
   // init: 0x005076D0
    hash_t mHashedAnimationName; // 0xC
    bool mPlayAsEmote; // 0x10
};
struct ContextualActionTriggerEvent: IContextualAction { // 0xC
   // ctor: 0x005084E0
   // init: 0x00507B80
};
struct ContextualActionPlayAudio: IContextualAction { // 0x50
   // ctor: 0x00400000
   // init: 0x00400000
    string_t mSelfEventName; // 0xC
    string_t mAllyEventName; // 0x18
    string_t mEnemyEventName; // 0x24
    string_t mSpectatorEventName; // 0x30
    bool mWaitForAnnouncerQueue; // 0x3C
    bool m_0x54CD5FCA; // 0x3D
    bool m_0xBEB655B5; // 0x3E
    string_t m_0x66A1C28B; // 0x40
    float_t mWaitTimeout; // 0x4C
};
struct ContextualActionPlayVo: ContextualActionPlayAudio { // 0x54
   // ctor: 0x005086A0
   // init: 0x005081C0
};
struct ContextualActionData: IResource { // 0x3C
   // ctor: 0x005086C0
   // init: 0x005084B0
    float_t mCooldown; // 0x8
    float_t m_0x9FD838B2; // 0xC
    unordered_map_t<hash_t, ContextualSituation> mSituations; // 0x10
    string_t mObjectPath; // 0x30
};
struct IContextualCondition: PropertyBase { // 0x4
   // ctor: 0x00400000
   // init: 0x00400000
};
struct ContextualConditionNegation: IContextualCondition { // 0x8
   // ctor: 0x00507C40
   // init: 0x00507850
    unique_ptr_t<IContextualCondition> mChildCondition; // 0x4
};
struct ContextualConditionItemId: IContextualCondition { // 0x10
   // ctor: 0x00508220
   // init: 0x00507990
    vector_t<hash_t> mItems; // 0x4
};
struct ContextualConditionMultikillSize: IContextualCondition { // 0x8
   // ctor: 0x00507930
   // init: 0x00508650
    uint8_t mMultikillSize; // 0x4
};
struct ContextualConditionKillCount: IContextualCondition { // 0x8
   // ctor: 0x005074B0
   // init: 0x00507FC0
    uint16_t mTotalKills; // 0x4
    uint8_t mCompareOp; // 0x6
};
struct ContextualConditionItemVoGroup: IContextualCondition { // 0x8
   // ctor: 0x005080F0
   // init: 0x00508410
    hash_t mItemVoGroupHash; // 0x4
};
struct ContextualConditionHasItemFromVoGroup: IContextualCondition { // 0x8
   // ctor: 0x00507440
   // init: 0x00507500
    hash_t mItemVoGroupHash; // 0x4
};
struct ContextualConditionLastBoughtItem: IContextualCondition { // 0x10
   // ctor: 0x00507810
   // init: 0x00507DE0
    hash_t mItem; // 0x4
};
struct ContextualConditionRuleCooldown: IContextualCondition { // 0x8
   // ctor: 0x00508840
   // init: 0x00507A40
    float_t mRuleCooldown; // 0x4
};
struct ContextualConditionChanceToPlay: IContextualCondition { // 0x8
   // ctor: 0x00507890
   // init: 0x00507750
    uint8_t mPercentChanceToPlay; // 0x4
};
struct ContextualConditionMoveDistance: IContextualCondition { // 0xC
   // ctor: 0x00507700
   // init: 0x00507F00
    float_t mDistance; // 0x4
    uint8_t mCompareOp; // 0x8
};
struct ContextualConditionCharacterLevel: IContextualCondition { // 0x8
   // ctor: 0x00507E00
   // init: 0x00507910
    uint8_t mCharacterLevel; // 0x4
    uint8_t mCompareOp; // 0x5
};
struct ContextualConditionTimeSinceStealthStateChange: IContextualCondition { // 0xC
   // ctor: 0x005073A0
   // init: 0x00507870
    uint8_t mStateToCheck; // 0x4
    uint8_t mCompareOp; // 0x5
    float_t mTimeThreshold; // 0x8
};
struct ContextualConditionMarkerName: IContextualCondition { // 0x10
   // ctor: 0x00507F50
   // init: 0x005083C0
    vector_t<string_t> mMarkerNames; // 0x4
};
struct ContextualConditionNeutralMinionMapSide: IContextualCondition { // 0x8
   // ctor: 0x00507E90
   // init: 0x005082E0
    uint8_t mTeamCompareOp; // 0x4
};
struct ContextualConditionNeutralMinionCampName: IContextualCondition { // 0x8
   // ctor: 0x00507340
   // init: 0x005078B0
    hash_t mCampName; // 0x4
};
struct ContextualConditionNeutralMinionCampIsAlive: IContextualCondition { // 0x8
   // ctor: 0x00508040
   // init: 0x00508540
    bool mCampIsAlive; // 0x4
};
struct ContextualConditionNeutralCampId: IContextualCondition { // 0x8
   // ctor: 0x005074E0
   // init: 0x005083E0
    uint8_t mCampId; // 0x4
};
struct ContextualConditionSituationHasRecentlyRun: IContextualCondition { // 0xC
   // ctor: 0x00507C60
   // init: 0x005076B0
    hash_t mSituationNameHash; // 0x4
    float_t mTime; // 0x8
};
struct ContextualConditionMapId: IContextualCondition { // 0x8
   // ctor: 0x005082C0
   // init: 0x005087F0
    uint32_t mMapIds; // 0x4
};
struct ContextualConditionObjectiveTakeByMyTeam: IContextualCondition { // 0x8
   // ctor: 0x005082A0
   // init: 0x005087A0
    uint32_t mTakenObjective; // 0x4
};
struct ContextualConditionMapRegionName: IContextualCondition { // 0x18
   // ctor: 0x00508590
   // init: 0x00508330
    uint8_t mRegionType; // 0x4
    string_t mRegionName; // 0xC
};
struct ContextualConditionTurretPosition: IContextualCondition { // 0x8
   // ctor: 0x00507BA0
   // init: 0x005081D0
    uint8_t mTurretPosition; // 0x4
};
struct ContextualConditionHasGold: IContextualCondition { // 0x8
   // ctor: 0x00507A20
   // init: 0x00507970
    float_t mGold; // 0x4
};
struct ContextualConditionCustomTimer: IContextualCondition { // 0x8
   // ctor: 0x00508380
   // init: 0x005081A0
    float_t mCustomTimer; // 0x4
};
struct ContextualConditionGameTimer: IContextualCondition { // 0xC
   // ctor: 0x005085E0
   // init: 0x005086E0
    float_t mGameTimeInMinutes; // 0x4
    uint8_t mCompareOp; // 0x8
};
struct ContextualConditionShopOpenCount: IContextualCondition { // 0x8
   // ctor: 0x00507D80
   // init: 0x00507D00
    uint32_t mShopOpenCount; // 0x4
};
struct ContextualConditionShopCloseCount: IContextualCondition { // 0x8
   // ctor: 0x005081E0
   // init: 0x00507950
    uint32_t mShopCloseCount; // 0x4
};
struct ContextualConditionItemPurchased: IContextualCondition { // 0x8
   // ctor: 0x00507320
   // init: 0x00507840
    bool mItemPurchased; // 0x4
};
struct ContextualConditionItemCanBePurchased: IContextualCondition { // 0x8
   // ctor: 0x00507AF0
   // init: 0x00508090
    bool mItemCanBePurchased; // 0x4
};
struct ContextualConditionItemPriceMinimum: IContextualCondition { // 0x8
   // ctor: 0x00507650
   // init: 0x00507630
    uint32_t mItemPriceMinimum; // 0x4
};
struct ContextualConditionOwnerTeamNetChampionKills: IContextualCondition { // 0x10
   // ctor: 0x00508430
   // init: 0x00507CE0
    int32_t mOwnerTeamNetKillAdvantage; // 0x4
    uint8_t mKillAdvantageCompareOp; // 0x8
    float_t mTimeFrameSeconds; // 0xC
};
struct ContextualConditionNearbyChampionCount: IContextualCondition { // 0x10
   // ctor: 0x00508810
   // init: 0x00508510
    uint8_t mTeamCompareOp; // 0x4
    uint32_t mCount; // 0x8
    uint8_t mCompareOp; // 0xC
};
struct ContextualConditionNumberOfCharactersNearTargetPos: IContextualCondition { // 0xC
   // ctor: 0x00507A90
   // init: 0x00507C90
    uint32_t mNumberOfCharacters; // 0x4
    uint8_t mTeamCompareOp; // 0x8
    uint8_t mCompareOp; // 0x9
};
struct ContextualConditionEnemyDeathsNearby: IContextualCondition { // 0x8
   // ctor: 0x005078D0
   // init: 0x00507E70
    uint32_t mEnemyDeaths; // 0x4
};
struct ContextualConditionTeammateDeathsNearby: IContextualCondition { // 0x8
   // ctor: 0x00507CC0
   // init: 0x00507DA0
    uint32_t mTeammateDeaths; // 0x4
};
struct ContextualConditionCharacter: IContextualCondition { // 0x14
   // ctor: 0x00507670
   // init: 0x00508270
    vector_t<unique_ptr_t<ICharacterSubcondition>> mChildConditions; // 0x4
    uint8_t mCharacterType; // 0x10
};
struct ContextualConditionAnyOtherHero: IContextualCondition { // 0x10
   // ctor: 0x00508060
   // init: 0x005087D0
    vector_t<unique_ptr_t<ICharacterSubcondition>> mChildConditions; // 0x4
};
struct ICharacterSubcondition: PropertyBase { // 0x4
   // ctor: 0x00400000
   // init: 0x00400000
};
struct ContextualConditionCharacterName: ICharacterSubcondition { // 0x10
   // ctor: 0x00508480
   // init: 0x005083A0
    vector_t<hash_t> mCharacters; // 0x4
};
struct ContextualConditionCharacterFormName: ICharacterSubcondition { // 0x10
   // ctor: 0x00508770
   // init: 0x00507BE0
    string_t mFormName; // 0x4
};
struct ContextualConditionCharacterSkinId: ICharacterSubcondition { // 0x10
   // ctor: 0x005075B0
   // init: 0x005073D0
    vector_t<int32_t> mSkinIds; // 0x4
};
struct ContextualConditionCharacterMetadata: ICharacterSubcondition { // 0x1C
   // ctor: 0x00508110
   // init: 0x00507F80
    string_t mCategory; // 0x4
    string_t mData; // 0x10
};
struct ContextualConditionCharacterUnitTags: ICharacterSubcondition { // 0x20
   // ctor: 0x005080A0
   // init: 0x00507460
    uint8_t mTagMode; // 0x4
    ObjectTags mUnitTags; // 0x8
};
struct ContextualConditionCharacterHealth: ICharacterSubcondition { // 0xC
   // ctor: 0x00507AC0
   // init: 0x00508700
    float_t mTargetHealth; // 0x4
    uint8_t mCompareOp; // 0x8
};
struct ContextualConditionIsAlly: ICharacterSubcondition { // 0x8
   // ctor: 0x005084C0
   // init: 0x00507E60
    bool mIsAlly; // 0x4
};
struct ContextualConditionCharacterPlayingEmote: ICharacterSubcondition { // 0x8
   // ctor: 0x00508660
   // init: 0x00507FE0
    uint8_t mEmoteId; // 0x4
};
struct ContextualConditionCharacterPlayingAnimation: ICharacterSubcondition { // 0x8
   // ctor: 0x00507F20
   // init: 0x00507730
    hash_t mAnimationNameHash; // 0x4
};
struct ContextualConditionCharacterDistance: ICharacterSubcondition { // 0xC
   // ctor: 0x005079B0
   // init: 0x00507610
    float_t mDistance; // 0x4
    uint8_t mCompareOp; // 0x8
    uint8_t mDistanceTarget; // 0x9
};
struct ContextualConditionCharacterInRangeForSyncedAnimation: ICharacterSubcondition { // 0x4
   // ctor: 0x00508250
   // init: 0x00508190
};
struct ContextualConditionCharacterHasTimeRemainingForAnimation: ICharacterSubcondition { // 0xC
   // ctor: 0x00508160
   // init: 0x005077C0
    hash_t mAnimationName; // 0x4
    float_t mMinRemainingTime; // 0x8
};
struct ContextualConditionCharacterIsCastingRecall: ICharacterSubcondition { // 0x4
   // ctor: 0x00507790
   // init: 0x00508630
};
struct ContextualConditionCharacterRole: ICharacterSubcondition { // 0x8
   // ctor: 0x00508610
   // init: 0x005085D0
    uint8_t mRole; // 0x4
};
struct ContextualConditionCharacterHasCac: ICharacterSubcondition { // 0x10
   // ctor: 0x00507C10
   // init: 0x00508460
    vector_t<hash_t> mCacs; // 0x4
};
struct IContextualConditionSpell: IContextualCondition { // 0x4
   // ctor: 0x00400000
   // init: 0x00400000
};
struct ContextualConditionSpell: IContextualCondition { // 0x14
   // ctor: 0x00508550
   // init: 0x00508720
    uint32_t mSpellSlot; // 0x4
    vector_t<unique_ptr_t<IContextualConditionSpell>> mChildConditions; // 0x8
};
struct ContextualConditionSpellName: IContextualConditionSpell { // 0x10
   // ctor: 0x00507B50
   // init: 0x00507D20
    hash_t mSpell; // 0x4
};
struct ContextualConditionSpellSlot: IContextualConditionSpell { // 0x8
   // ctor: 0x00507BC0
   // init: 0x00507DC0
    uint32_t mSpellSlot; // 0x4
};
struct ContextualConditionSpellLevel: IContextualConditionSpell { // 0x8
   // ctor: 0x005077E0
   // init: 0x00508200
    uint8_t mSpellLevel; // 0x4
    uint8_t mCompareOp; // 0x5
};
struct ContextualConditionSpellIsReady: IContextualConditionSpell { // 0x8
   // ctor: 0x00508680
   // init: 0x005087C0
    bool mSpellIsReady; // 0x4
};
struct IContextualConditionBuff: IContextualCondition { // 0x4
   // ctor: 0x00400000
   // init: 0x00400000
};
struct t_0x0418B95A: IContextualConditionBuff { // 0x14
   // ctor: 0x005075E0
   // init: 0x00507550
    hash_t mBuff; // 0x4
    uint8_t m_0x11206E1A; // 0x10
};
struct t_0xB8D75E45: IContextualConditionBuff { // 0x14
   // ctor: 0x00507760
   // init: 0x00508750
    hash_t mBuff; // 0x4
    uint8_t m_0x11206E1A; // 0x10
};
struct ContextualRule { // 0x28
   // ctor: 0x005073F0
   // init: 0x00507360
    uint32_t mConditionRelationship; // 0x0
    vector_t<unique_ptr_t<IContextualCondition>> mConditions; // 0x4
    unique_ptr_t<ContextualActionPlayAudio> mAudioAction; // 0x10
    unique_ptr_t<ContextualActionPlayAnimation> mAnimationAction; // 0x14
    unique_ptr_t<ContextualActionTriggerEvent> mTriggerEventAction; // 0x18
    optional_t<uint32_t> mPriority; // 0x1C
    bool m_0x68FEE3C4; // 0x20
};
struct ContextualSituation { // 0x1C
   // ctor: 0x005079E0
   // init: 0x00507D40
    vector_t<ContextualRule> mRules; // 0x8
    bool mChooseRandomValidRule; // 0x14
    float_t mCoolDownTime; // 0x18
};
struct DamageSourceTemplate { // 0x20
   // ctor: 0x00507EB0
   // init: 0x00507B10
    string_t Name; // 0x0
    uint32_t DamageProperties; // 0xC
    vector_t<string_t> DamageTags; // 0x10
};
struct DamageSourceSettings { // 0x40
   // ctor: 0x00508360
   // init: 0x00508530
    vector_t<string_t> DamageTagDefinition; // 0x0
    vector_t<DamageSourceTemplate> TemplateDefinition; // 0xC
};
struct DeathTimesScalingPoint { // 0x8
   // ctor: 0x00522060
   // init: 0x00521FF0
    uint32_t mStartTime; // 0x0
    float_t mPercentIncrease; // 0x4
};
struct DeathTimes { // 0x2C
   // ctor: 0x00521FE0
   // init: 0x00522010
    vector_t<float_t> mTimeDeadPerLevel; // 0x0
    uint32_t mScalingStartTime; // 0xC
    uint32_t mScalingIncrementTime; // 0x10
    float_t mScalingPercentIncrease; // 0x14
    float_t mScalingPercentCap; // 0x18
    vector_t<DeathTimesScalingPoint> mScalingPoints; // 0x1C
    bool mAllowRespawnMods; // 0x28
    bool mStartDeathTimerForZombies; // 0x29
};
struct AbilityResourceStateColorOptions { // 0x8
   // ctor: 0x005A1A60
   // init: 0x005A1B40
    color_t Color; // 0x0
    color_t FadeColor; // 0x4
};
struct AbilityResourceStateData { // 0x20
   // ctor: 0x005A1CE0
   // init: 0x005A1C60
    unique_ptr_t<AbilityResourceStateColorOptions> DefaultPalette; // 0x0
    unique_ptr_t<AbilityResourceStateColorOptions> ColorblindPalette; // 0x4
    string_t TextureSuffix; // 0x8
    string_t AnimationSuffix; // 0x14
};
struct AbilityResourceThresholdIndicatorRange { // 0x8
   // ctor: 0x00522060
   // init: 0x00521FF0
    float_t RangeStart; // 0x0
    float_t RangeEnd; // 0x4
};
struct AbilityResourceTypeData { // 0x1C
   // ctor: 0x005A1D30
   // init: 0x005A1AF0
    vector_t<AbilityResourceStateData> States; // 0x0
    bool ShowAbilityResource; // 0xC
    bool ShowRegen; // 0xD
    vector_t<AbilityResourceThresholdIndicatorRange> ThresholdIndicatorRanges; // 0x10
};
struct AbilityResourceTypeConfig { // 0x1A8
   // ctor: 0x005A1D80
   // init: 0x005A1CB0
    AbilityResourceTypeData Mana; // 0x4
    AbilityResourceTypeData Energy; // 0x20
    AbilityResourceTypeData None; // 0x3C
    AbilityResourceTypeData Shield; // 0x58
    AbilityResourceTypeData BattleFury; // 0x74
    AbilityResourceTypeData DragonFury; // 0x90
    AbilityResourceTypeData Rage; // 0xAC
    AbilityResourceTypeData Heat; // 0xC8
    AbilityResourceTypeData PrimalFury; // 0xE4
    AbilityResourceTypeData Ferocity; // 0x100
    AbilityResourceTypeData Bloodwell; // 0x11C
    AbilityResourceTypeData Wind; // 0x138
    AbilityResourceTypeData Ammo; // 0x154
    AbilityResourceTypeData Moonlight; // 0x170
    AbilityResourceTypeData Other; // 0x18C
};
struct EvolutionDescription: PropertyBase { // 0x74
   // ctor: 0x005A1C30
   // init: 0x005A1E40
    uint32_t mFlags; // 0x4
    string_t mTitle; // 0x8
    array_t<string_t, 4> mTooltips; // 0x14
    array_t<string_t, 4> mIconNames; // 0x44
};
struct ExperienceCurveData { // 0x30
   // ctor: 0x005A1A40
   // init: 0x005A19D0
    vector_t<float_t> mExperienceRequiredPerLevel; // 0x0
    vector_t<float_t> mExperienceGrantedForKillPerLevel; // 0xC
    vector_t<float_t> m_0x9980FA2E; // 0x18
    float_t mBaseExperienceMultiplier; // 0x24
    float_t mLevelDifferenceExperienceMultiplier; // 0x28
    float_t mMinimumExperienceMultiplier; // 0x2C
};
struct ExperienceModData { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    vector_t<float_t> mPlayerMinionSplitXp; // 0x0
};
struct StatUiData { // 0x34
   // ctor: 0x005A1A90
   // init: 0x005A1BB0
    string_t mName; // 0x0
    string_t mAbbreviation; // 0xC
    uint8_t mDisplayType; // 0x18
    string_t mIconKey; // 0x1C
    string_t mScalingTagKey; // 0x28
};
struct GlobalStatsUiData { // 0x118
   // ctor: 0x005A1AC0
   // init: 0x005A1A30
    map_t<uint8_t, StatUiData> mStatUiData; // 0x0
    string_t BaseOutputIconModifier; // 0xC
    string_t BonusOutputIconModifier; // 0x18
    string_t mNumberStyle; // 0x24
    string_t mNumberStylePercent; // 0x30
    string_t mNumberStyleBonus; // 0x3C
    string_t mNumberStyleBonusPercent; // 0x48
    string_t FormulaPartStyleBonus; // 0x54
    string_t FormulaPartStyleBonusPercent; // 0x60
    string_t FormulaPartStyle; // 0x6C
    string_t FormulaPartStylePercent; // 0x78
    string_t FormulaPartRangeStyleBonus; // 0x84
    string_t FormulaPartRangeStyleBonusPercent; // 0x90
    string_t FormulaPartRangeStyle; // 0x9C
    string_t FormulaPartRangeStylePercent; // 0xA8
    string_t mNumberStyleTotalAndCoefficient; // 0xB4
    string_t mNumberStyleTotalAndCoefficientPercent; // 0xC0
    string_t NumberStyleTotalAndScalingIcons; // 0xCC
    string_t NumberStyleTotalAndFormula; // 0xD8
    string_t mManaIconKey; // 0xE4
    string_t mManaScalingTagKey; // 0xF0
    string_t m_0x2FA6C4B0; // 0xFC
    string_t m_0x4AC09EEF; // 0x108
    uint8_t m_0xF04C21CD; // 0x114
    uint8_t m_0xA844CACA; // 0x115
    uint8_t m_0x97343C80; // 0x116
};
struct CameraTrapezoid { // 0x10
   // ctor: 0x005CA800
   // init: 0x005CA650
    float_t m_0x9811EB50; // 0x0
    float_t m_0x82CB6669; // 0x4
    float_t mMaxXTop; // 0x8
    float_t mMaxXBottom; // 0xC
};
struct CameraConfig { // 0x6C
   // ctor: 0x005CA980
   // init: 0x005CA2F0
    CameraTrapezoid m_0x0671C887; // 0x0
    float_t mAccelerationTimeMouse; // 0x10
    float_t mDecelerationTimeMouse; // 0x14
    float_t mAccelerationTimeKeyboard; // 0x18
    float_t mDecelerationTimeKeyboard; // 0x1C
    float_t mTopdownZoom; // 0x20
    float_t mZoomMinDistance; // 0x24
    float_t mZoomMaxDistance; // 0x28
    float_t mZoomEaseTime; // 0x2C
    float_t mZoomMinSpeed; // 0x30
    float_t mLockedCameraEasingDistance; // 0x34
    float_t mDragScale; // 0x38
    float_t mDragMomentumDecay; // 0x3C
    float_t mDragMomentumRecencyWeight; // 0x40
    float_t mTransitionDurationIntoCinematicMode; // 0x44
    CameraTrapezoid m_0x71C9323A; // 0x48
    CameraTrapezoid m_0xF7617555; // 0x58
    float_t m_0x383F51A8; // 0x68
};
struct MapAudioDataProperties { // 0x1C
   // ctor: 0x005CA930
   // init: 0x005CA6F0
    link_ptr_t<MapAudioDataProperties> BaseData; // 0x0
    vector_t<BankUnit> BankUnits; // 0x4
    vector_t<link_ptr_t<FeatureAudioDataProperties>> Features; // 0x10
};
struct ClientStateAudioDataProperties { // 0x18
   // ctor: 0x005CA580
   // init: 0x005CA210
    vector_t<string_t> BankPaths; // 0x0
    string_t ThemeMusic; // 0xC
};
struct FeatureAudioDataProperties { // 0xA4
   // ctor: 0x005CA290
   // init: 0x005CA4A0
    vector_t<BankUnit> BankUnits; // 0x0
    MusicAudioDataProperties Music; // 0xC
    hash_t Feature; // 0xA0
};
struct BankUnit { // 0x28
   // ctor: 0x005CA490
   // init: 0x005CA240
    string_t Name; // 0x0
    vector_t<string_t> BankPath; // 0xC
    vector_t<string_t> Events; // 0x18
    bool Asynchrone; // 0x24
    bool VoiceOver; // 0x25
};
struct AudioTagListProperties { // 0x18
   // ctor: 0x005CA580
   // init: 0x005CA210
    vector_t<string_t> Tags; // 0x0
    string_t Key; // 0xC
};
struct AudioSystemDataProperties { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    vector_t<AudioTagListProperties> SystemTagEventList; // 0x0
};
struct AudioStatusEvents { // 0x24
   // ctor: 0x005CA9E0
   // init: 0x005CA8E0
    string_t RtpcName; // 0x0
    string_t StartEvent; // 0xC
    string_t StopEvent; // 0x18
};
struct GlobalAudioDataProperties { // 0x1C
   // ctor: 0x005CA4D0
   // init: 0x005CA5C0
    map_t<hash_t, link_ptr_t<AudioSystemDataProperties>> Systems; // 0x0
    float_t CooldownVoiceOver; // 0xC
    map_t<uint8_t, AudioStatusEvents> LocalPlayerStatusEvents; // 0x10
    uint32_t m_0x103E4044; // 0x18
};
struct MusicAudioDataProperties { // 0x94
   // ctor: 0x005CA470
   // init: 0x005CA200
    string_t ThemeMusicId; // 0x0
    string_t ThemeMusicTransitionId; // 0xC
    string_t LegacyThemeMusicId; // 0x18
    string_t LegacyThemeMusicTransitionId; // 0x24
    string_t VictoryMusicId; // 0x30
    string_t DefeatMusicId; // 0x3C
    string_t VictoryBannerSound; // 0x48
    string_t DefeatBannerSound; // 0x54
    string_t AmbientEvent; // 0x60
    string_t ReverbPreset; // 0x6C
    string_t GameStartEvent; // 0x78
    string_t GameQuitEvent; // 0x84
};
struct EvoSettings { // 0x10
   // ctor: 0x005CA9F0
   // init: 0x005CA860
    bool mEnableChatVo; // 0x0
    bool mEnableAnnouncerVoReplacement; // 0x1
    int32_t mChatVoThrottleCounterThreshold; // 0x4
    float_t mChatVoThrottleCounterDecayTime; // 0x8
    float_t mPingVoThrottleThreshold; // 0xC
};
struct ICatalogEntryOwner { // 0x4
   // ctor: 0x00400000
   // init: 0x00400000
};
struct CatalogEntry: PropertyBase { // 0x20
   // ctor: 0x00607CF0
   // init: 0x006085A0
    string_t ContentId; // 0x4
    uint32_t ItemId; // 0x10
    string_t OfferId; // 0x14
};
struct CensoredImage { // 0x18
   // ctor: 0x006086D0
   // init: 0x00608E10
    string_t Image; // 0x0
    map_t<hash_t, string_t> UncensoredImages; // 0xC
};
struct Champion: WadFileDescriptor { // 0x6C
   // ctor: 0x00608B70
   // init: 0x00608E80
    string_t Name; // 0x4
    vector_t<hash_t> StatStoneSets; // 0x10
    ChampionItemRecommendations mChampionItemRecommendations; // 0x1C
    vector_t<link_ptr_t<Character>> AdditionalCharacters; // 0x4C
    int8_t FixedLoadScreenPosition; // 0x64
    uint32_t m_0xC7D8A053; // 0x68
};
struct Character: PropertyBase { // 0x10
   // ctor: 0x00609140
   // init: 0x00608710
    string_t Name; // 0x4
};
struct SkinCharacterDataProperties_CharacterIdleEffect { // 0x38
   // ctor: 0x00609030
   // init: 0x00608760
    hash_t EffectKey; // 0x0
    string_t EffectName; // 0x4
    point3D_t Position; // 0x10
    string_t BoneName; // 0x1C
    string_t TargetBoneName; // 0x28
};
struct SkinCharacterMetaDataProperties_SpawningSkinOffset { // 0x10
   // ctor: 0x00607F40
   // init: 0x00608200
    string_t Tag; // 0x0
    int32_t Offset; // 0xC
};
struct EsportTeamEntry { // 0x24
   // ctor: 0x005CA9E0
   // init: 0x005CA8E0
    string_t TeamName; // 0x0
    string_t LeagueName; // 0xC
    string_t TextureName; // 0x18
};
struct EsportLeagueEntry { // 0x18
   // ctor: 0x00608150
   // init: 0x00607E90
    string_t LeagueName; // 0x0
    string_t TextureName; // 0xC
};
struct SkinCharacterMetaDataProperties { // 0x3C
   // ctor: 0x00608940
   // init: 0x00608EE0
    bool EsportCharacter; // 0x0
    vector_t<EsportTeamEntry> EsportTeamTable; // 0x4
    vector_t<EsportLeagueEntry> EsportLeagueTable; // 0x10
    bool SkinBasedRelativeColorScheme; // 0x1C
    vector_t<int32_t> RelativeColorSwapTable; // 0x20
    vector_t<SkinCharacterMetaDataProperties_SpawningSkinOffset> SpawningSkinOffsets; // 0x2C
    bool UseGdsBinaries; // 0x38
};
struct SkinAudioProperties { // 0x18
   // ctor: 0x00608900
   // init: 0x00608F30
    vector_t<string_t> TagEventList; // 0x0
    vector_t<BankUnit> BankUnits; // 0xC
};
struct SkinAnimationProperties { // 0x4
   // ctor: 0x006083C0
   // init: 0x00607F30
    link_ptr_t<AnimationGraphData> AnimationGraphData; // 0x0
};
struct SkinEmblem { // 0x8
   // ctor: 0x00608EC0
   // init: 0x00608BC0
    link_ptr_t<EmblemData> mEmblemData; // 0x0
    uint32_t mLoadingScreenAnchor; // 0x4
};
struct SkinSummonerEmoteLoadout { // 0x50
   // ctor: 0x006089B0
   // init: 0x00608AE0
    array_t<link_ptr_t<SummonerEmote>, 10> mEmotes; // 0x0
};
struct SkinCharacterDataProperties { // 0x334
   // ctor: 0x00608A40
   // init: 0x00608B10
    uint32_t SkinClassification; // 0xC
    string_t ChampionSkinName; // 0x10
    uint32_t AttributeFlags; // 0x1C
    int32_t SkinParent; // 0x20
    string_t MetaDataTags; // 0x24
    hash_t EmoteLoadout; // 0x30
    SkinUpgradeData SkinUpgradeData; // 0x3C
    string_t EndOfGameAlias; // 0x48
    string_t m_0x4678B8F7; // 0x54
    CensoredImage Loadscreen; // 0x60
    CensoredImage LoadscreenVintage; // 0x78
    SkinAudioProperties SkinAudioProperties; // 0x90
    SkinAnimationProperties SkinAnimationProperties; // 0xA8
    SkinMeshDataProperties SkinMeshProperties; // 0xAC
    string_t ArmorMaterial; // 0x1A4
    vector_t<string_t> ThemeMusic; // 0x1B0
    bool m_0x0592970C; // 0x1BC
    string_t HudMuteEvent; // 0x1C0
    string_t HudUnmuteEvent; // 0x1CC
    vector_t<string_t> DefaultAnimations; // 0x1E4
    vector_t<SkinCharacterDataProperties_CharacterIdleEffect> IdleParticlesEffects; // 0x1F0
    string_t ParticleOverride_ChampionKillDeathParticle; // 0x1FC
    string_t ParticleOverride_DeathParticle; // 0x208
    string_t mSpawnParticleName; // 0x214
    vector_t<string_t> ExtraCharacterPreloads; // 0x220
    CharacterHealthBarDataRecord HealthBarData; // 0x22C
    vector_t<SkinEmblem> mEmblems; // 0x24C
    string_t VoiceOverOverride; // 0x258
    bool SkipVoOverride; // 0x264
    string_t IconAvatar; // 0x268
    optional_t<float_t> IconCircleScale; // 0x274
    optional_t<string_t> IconCircle; // 0x278
    optional_t<string_t> IconSquare; // 0x288
    vector_t<string_t> AlternateIconsCircle; // 0x298
    vector_t<string_t> AlternateIconsSquare; // 0x2A4
    map_t<hash_t, string_t> UncensoredIconCircles; // 0x2B0
    map_t<hash_t, string_t> UncensoredIconSquares; // 0x2BC
    unique_ptr_t<ISecondaryResourceDisplayData> SecondaryResourceHudDisplayData; // 0x2C8
    link_ptr_t<ContextualActionData> mContextualActionData; // 0x2E8
    string_t EmoteBuffbone; // 0x2EC
    float_t EmoteYOffset; // 0x2FC
    string_t GodrayFxBone; // 0x300
    link_ptr_t<ResourceResolver> mResourceResolver; // 0x310
    vector_t<link_ptr_t<ResourceResolver>> mAdditionalResourceResolvers; // 0x314
    HudOptionalBinData mOptionalBin; // 0x320
    uint32_t m_0x25F9AA72; // 0x330
};
struct SkinFilterData: PropertyBase { // 0x18
   // ctor: 0x00608BE0
   // init: 0x00608060
    uint32_t FilterType; // 0x4
    bool m_0xC176D167; // 0x8
    vector_t<uint32_t> SkinIds; // 0xC
};
struct CharacterPassiveData: PropertyBase { // 0x2C
   // ctor: 0x00609020
   // init: 0x00608960
    link_ptr_t<SpellObject> m_0xBD3C31E4; // 0x4
    vector_t<link_ptr_t<SpellObject>> mComponentBuffs; // 0x8
    vector_t<link_ptr_t<SpellObject>> mChildSpells; // 0x14
    uint8_t mDisplayFlags; // 0x20
    unique_ptr_t<SkinFilterData> SkinFilter; // 0x24
    bool m_0x6346A946; // 0x28
};
struct GlobalPerLevelStatsFactor { // 0x1C
   // ctor: 0x00607FB0
   // init: 0x00608000
    vector_t<float_t> mPerLevelStatsFactor; // 0x4
};
struct OverrideAutoAttackCastTimeData: PropertyBase { // 0x8
   // ctor: 0x00607DB0
   // init: 0x00608630
    unique_ptr_t<IGameCalculation> mOverrideAutoattackCastTimeCalculation; // 0x4
};
struct CharacterRecord: PropertyBase { // 0x8B0
   // ctor: 0x00608FF0
   // init: 0x00608AD0
    string_t mCharacterName; // 0x20
    string_t mFallbackCharacterName; // 0x2C
    uint32_t Flags; // 0x38
    uint32_t MinionFlags; // 0x3C
    string_t AssetCategory; // 0x40
    vector_t<hash_t> PurchaseIdentities; // 0x4C
    vector_t<hash_t> mClientSideItemInventory; // 0x58
    link_ptr_t<PerkStyle> mPreferredPerkStyle; // 0x64
    PerkReplacementList mPerkReplacements; // 0x68
    float_t BaseHp; // 0x74
    float_t HpPerLevel; // 0x78
    float_t BaseStaticHpRegen; // 0x7C
    float_t BaseFactorHpRegen; // 0x80
    float_t HpRegenPerLevel; // 0x84
    float_t HealthBarHeight; // 0x88
    bool HealthBarFullParallax; // 0x8C
    string_t SelfChampSpecificHealthSuffix; // 0x90
    string_t SelfCbChampSpecificHealthSuffix; // 0x9C
    string_t AllyChampSpecificHealthSuffix; // 0xA8
    string_t EnemyChampSpecificHealthSuffix; // 0xB4
    bool HighlightHealthbarIcons; // 0xC0
    AbilityResourceSlotInfo PrimaryAbilityResource; // 0xC4
    AbilityResourceSlotInfo SecondaryAbilityResource; // 0x12C
    float_t BaseDamage; // 0x194
    float_t DamagePerLevel; // 0x198
    float_t BaseArmor; // 0x19C
    float_t ArmorPerLevel; // 0x1A0
    float_t BaseSpellBlock; // 0x1A4
    float_t SpellBlockPerLevel; // 0x1A8
    float_t BaseDodge; // 0x1AC
    float_t DodgePerLevel; // 0x1B0
    float_t BaseMissChance; // 0x1B4
    float_t BaseCritChance; // 0x1B8
    float_t CritPerLevel; // 0x1BC
    float_t CritDamageMultiplier; // 0x1C0
    float_t BaseMoveSpeed; // 0x1C4
    float_t m_0xCB4451D3; // 0x1C8
    float_t AttackRange; // 0x1CC
    float_t AttackSpeed; // 0x1D0
    float_t AttackSpeedRatio; // 0x1D4
    float_t AttackSpeedPerLevel; // 0x1D8
    float_t AbilityPowerIncPerLevel; // 0x1DC
    float_t mAdaptiveForceToAbilityPowerWeight; // 0x1E0
    AttackSlotData BasicAttack; // 0x274
    vector_t<AttackSlotData> ExtraAttacks; // 0x29C
    vector_t<AttackSlotData> CritAttacks; // 0x2A8
    float_t AcquisitionRange; // 0x2B4
    optional_t<float_t> WakeUpRange; // 0x2B8
    optional_t<float_t> FirstAcquisitionRange; // 0x2C0
    float_t AttackAutoInterruptPercent; // 0x2C8
    float_t TowerTargetingPriorityBoost; // 0x2CC
    float_t GoldGivenOnDeath; // 0x2D0
    float_t ExpGivenOnDeath; // 0x2D4
    float_t GoldRadius; // 0x2D8
    float_t ExperienceRadius; // 0x2DC
    float_t DeathEventListeningRadius; // 0x2E0
    float_t LocalGoldGivenOnDeath; // 0x2E4
    float_t LocalExpGivenOnDeath; // 0x2E8
    bool LocalGoldSplitWithLastHitter; // 0x2EC
    float_t GlobalGoldGivenOnDeath; // 0x2F0
    float_t GlobalExpGivenOnDeath; // 0x2F4
    optional_t<float_t> PerceptionBubbleRadius; // 0x2F8
    optional_t<point3D_t> PerceptionBoundingBoxSize; // 0x300
    float_t Significance; // 0x30C
    float_t UntargetableSpawnTime; // 0x310
    float_t AbilityPower; // 0x314
    float_t DeathTime; // 0x318
    float_t OccludedUnitSelectableDistance; // 0x31C
    string_t CriticalAttack; // 0x320
    string_t PassiveName; // 0x32C
    string_t PassiveLuaName; // 0x338
    string_t PassiveToolTip; // 0x344
    string_t PassiveSpell; // 0x350
    float_t PassiveRange; // 0x35C
    string_t Passive1IconName; // 0x360
    float_t HitFxScale; // 0x36C
    float_t SelectionHeight; // 0x448
    float_t SelectionRadius; // 0x44C
    float_t PathfindingCollisionRadius; // 0x450
    optional_t<float_t> OverrideGameplayCollisionRadius; // 0x454
    array_t<SpellLevelUpInfo, 4> SpellLevelUpInfo; // 0x458
    vector_t<RecSpellRankUpInfo> RecSpellRankUpInfo; // 0x488
    string_t ParName; // 0x494
    string_t FriendlyTooltip; // 0x4A0
    string_t EnemyTooltip; // 0x4AC
    string_t Name; // 0x4B8
    float_t OutlineBboxExpansion; // 0x4C4
    bool mUseCcAnimations; // 0x4C8
    string_t JointForAnimAdjustedSelection; // 0x4CC
    vector_t<string_t> WeaponMaterials; // 0x4DC
    string_t CharAudioNameOverride; // 0x4E8
    string_t MinimapIconOverride; // 0x4F4
    string_t HoverIndicatorTextureName; // 0x500
    string_t HoverLineIndicatorBaseTextureName; // 0x50C
    string_t HoverLineIndicatorTargetTextureName; // 0x518
    float_t HoverLineIndicatorWidth; // 0x524
    float_t HoverIndicatorRadius; // 0x528
    float_t HoverLineIndicatorWidthMinimap; // 0x52C
    float_t HoverIndicatorRadiusMinimap; // 0x530
    bool HoverIndicatorRotateToPlayer; // 0x534
    string_t HoverIndicatorMinimapOverride; // 0x538
    float_t AreaIndicatorRadius; // 0x544
    float_t AreaIndicatorMinRadius; // 0x548
    float_t AreaIndicatorMaxDistance; // 0x54C
    float_t AreaIndicatorTargetDistance; // 0x550
    float_t AreaIndicatorMinDistance; // 0x554
    float_t AreaIndicatorTextureSize; // 0x558
    string_t AreaIndicatorTextureName; // 0x55C
    string_t SilhouetteAttachmentAnim; // 0x568
    unique_ptr_t<TargetLaserComponentEffects> TargetLaserEffects; // 0x574
    unique_ptr_t<TargetLaserComponentEffects> DisabledTargetLaserEffects; // 0x578
    unique_ptr_t<EvolutionDescription> EvolutionData; // 0x57C
    UseableData UseableData; // 0x580
    bool RecordAsWard; // 0x5A0
    float_t MinionScoreValue; // 0x5A4
    bool UseRiotRelationships; // 0x5A8
    string_t UnitTagsString; // 0x5B4
    uint32_t FriendlyUxOverrideTeam; // 0x5D8
    string_t FriendlyUxOverrideIncludeTagsString; // 0x5DC
    string_t FriendlyUxOverrideExcludeTagsString; // 0x5E8
    ToolEducationData mEducationToolData; // 0x628
    array_t<int32_t, 4> mAbilitySlotCc; // 0x630
    CharacterToolData CharacterToolData; // 0x640
    bool PlatformEnabled; // 0x658
    float_t MovingTowardEnemyActivationAngle; // 0x65C
    vector_t<link_ptr_t<AbilityObject>> mAbilities; // 0x660
    uint32_t OnKillEvent; // 0x66C
    uint32_t OnKillEventSteal; // 0x670
    uint32_t OnKillEventForSpectator; // 0x674
    map_t<hash_t, unique_ptr_t<IGameCalculation>> mCharacterCalculations; // 0x678
    link_ptr_t<SpellObject> mCharacterPassiveSpell; // 0x684
    vector_t<CharacterPassiveData> mCharacterPassiveBuffs; // 0x688
    array_t<string_t, 4> SpellNames; // 0x76C
    array_t<string_t, 16> ExtraSpells; // 0x79C
    StatFormulaDataList mDefaultStatOverrides; // 0x8A0
};
struct AbilityResourceSlotInfo { // 0x68
   // ctor: 0x00607C60
   // init: 0x00607E70
    uint8_t ArType; // 0x0
    float_t ArBase; // 0x4
    float_t ArPerLevel; // 0x8
    float_t ArBaseStaticRegen; // 0xC
    float_t ArBaseFactorRegen; // 0x10
    float_t ArRegenPerLevel; // 0x14
    float_t ArIncrements; // 0x18
    int32_t ArMaxSegments; // 0x1C
    bool ArHasRegenText; // 0x20
    bool ArAllowMaxValueToBeOverridden; // 0x21
    bool ArContributesToHealthValues; // 0x22
    bool ArPreventRegenWhileAtZero; // 0x23
    bool ArDisplayAsPips; // 0x24
    bool ArIsShown; // 0x25
    bool ArIsShownOnlyOnLocalPlayer; // 0x26
    string_t ArOverrideSmallPipName; // 0x28
    string_t arOverrideMediumPipName; // 0x34
    string_t ArOverrideLargePipName; // 0x40
    string_t ArOverrideEmptyPipName; // 0x4C
    string_t ArOverrideSpacerName; // 0x58
    bool ArNegativeSpacer; // 0x64
    bool m_0xA9D3A87C; // 0x65
    bool m_0x5CA738C0; // 0x66
};
struct AttackSlotData { // 0x28
   // ctor: 0x00607E30
   // init: 0x006080D0
    optional_t<float_t> mAttackTotalTime; // 0x0
    optional_t<float_t> mAttackCastTime; // 0x4
    optional_t<float_t> mAttackDelayCastOffsetPercent; // 0x8
    optional_t<float_t> mAttackDelayCastOffsetPercentAttackSpeedRatio; // 0xC
    optional_t<float_t> mAttackProbability; // 0x10
    optional_t<string_t> mAttackName; // 0x14
    unique_ptr_t<OverrideAutoAttackCastTimeData> mOverrideAutoattackCastTime; // 0x24
};
struct TargetLaserComponentEffects: PropertyBase { // 0xAC
   // ctor: 0x00608780
   // init: 0x00608530
    SkinCharacterDataProperties_CharacterIdleEffect BeamEffectDefinition; // 0x4
    SkinCharacterDataProperties_CharacterIdleEffect TowerTargetingEffectDefinition; // 0x3C
    SkinCharacterDataProperties_CharacterIdleEffect ChampTargetingEffectDefinition; // 0x74
};
struct ToolEducationData { // 0x8
   // ctor: 0x00522060
   // init: 0x00521FF0
    int32_t FirstItem; // 0x0
    int32_t SkillOrder; // 0x4
};
struct CharacterToolData { // 0x18
   // ctor: 0x00608150
   // init: 0x00607E90
    string_t SearchTags; // 0x0
    string_t SearchTagsSecondary; // 0xC
};
struct Companion: Character { // 0x10
   // ctor: 0x006084D0
   // init: 0x00608F80
};
struct InteractionData { // 0x10
   // ctor: 0x00608C30
   // init: 0x00608E90
    string_t IdleAnim; // 0x0
    bool ShouldRandomizeIdleAnimPhase; // 0xC
};
struct ISpellRankUpRequirement: PropertyBase { // 0x4
   // ctor: 0x00400000
   // init: 0x00400000
};
struct HasSkillPointRequirement: ISpellRankUpRequirement { // 0x4
   // ctor: 0x006082A0
   // init: 0x00608FE0
};
struct CharacterLevelRequirement: ISpellRankUpRequirement { // 0x8
   // ctor: 0x00608D80
   // init: 0x006083F0
    uint32_t mLevel; // 0x4
};
struct HasBuffRequirement: ISpellRankUpRequirement { // 0xC
   // ctor: 0x00608120
   // init: 0x006083A0
    hash_t mBuffName; // 0x4
    bool mFromAnyone; // 0x8
};
struct SpellRankUpRequirements { // 0xC
   // ctor: 0x00608560
   // init: 0x006090F0
    vector_t<unique_ptr_t<ISpellRankUpRequirement>> mRequirements; // 0x0
};
struct SpellLevelUpInfo { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    vector_t<SpellRankUpRequirements> mRequirements; // 0x0
};
struct RecSpellRankUpInfo { // 0x10
   // ctor: 0x00608B90
   // init: 0x006081A0
    array_t<uint8_t, 4> mDefaultPriority; // 0x0
    vector_t<uint8_t> mEarlyLevelOverrides; // 0x4
};
struct UseableData { // 0x20
   // ctor: 0x00608350
   // init: 0x00608640
    uint32_t Flags; // 0x0
    string_t UseHeroSpellName; // 0x4
    string_t UseSpellName; // 0x10
    int32_t UseCooldownSpellSlot; // 0x1C
};
struct CharacterHealthBarDataRecord { // 0x20
   // ctor: 0x00608470
   // init: 0x006090A0
    float_t HpPerTick; // 0x0
    string_t AttachToBone; // 0x4
    uint8_t UnitHealthBarStyle; // 0x14
    bool ShowWhileUntargetable; // 0x15
    bool m_0x9C5124C0; // 0x16
    uint32_t m_0xE784DD2F; // 0x18
    bool m_0x66A7D70A; // 0x1C
    bool m_0x8BDCFA04; // 0x1D
    bool m_0x7F0B706E; // 0x1E
};
struct SponsoredBanner { // 0x10
   // ctor: 0x00608CA0
   // init: 0x00608C60
    link_ptr_t<EsportsBannerData> Banner; // 0x0
    file_t SponsorTexturePath; // 0x8
};
struct EsportsBannerConfiguration { // 0x40
   // ctor: 0x006087C0
   // init: 0x006083E0
    string_t Name; // 0x0
    vector_t<SponsoredBanner> IndividualBannerOverrides; // 0xC
    hash_t EsportsTeam; // 0x18
    link_ptr_t<GameMutatorExpansions> EventMutator; // 0x24
    string_t LeagueName; // 0x28
    file_t TexturePath; // 0x38
};
struct EsportsBannerData { // 0x10
   // ctor: 0x00607F40
   // init: 0x00608200
    string_t BannerName; // 0x0
    uint32_t Team; // 0xC
};
struct EsportsData { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    vector_t<string_t> Leagues; // 0x0
};
struct ClashLogo { // 0x14
   // ctor: 0x00609100
   // init: 0x00608DA0
    uint32_t mClashLogoId; // 0x0
    uint32_t mClashLogoColorId; // 0x4
    string_t mLogoPath; // 0x8
};
struct EsportsBannerOptions { // 0x20
   // ctor: 0x00608A80
   // init: 0x00608DD0
    string_t SubMeshName; // 0x0
    file_t DefaultTexturePath; // 0x10
    bool IsSpectatorOnly; // 0x19
    link_ptr_t<IMaterialDef> DefaultBlankMaterial; // 0x1C
};
struct MasteryBadgeData { // 0x20
   // ctor: 0x006082E0
   // init: 0x00609060
    hash_t mName; // 0x0
    string_t mParticleName; // 0x4
    float_t mRenderScale; // 0x10
    float_t mVerticalOffset; // 0x14
    int32_t mSummonerIconId; // 0x18
    uint32_t mMasteryLevel; // 0x1C
};
struct MasteryBadgeConfig { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    vector_t<MasteryBadgeData> mBadges; // 0x0
};
struct MasteryData { // 0x24
   // ctor: 0x005CA9E0
   // init: 0x005CA8E0
    string_t Texture; // 0x0
    string_t LevelTraKey; // 0xC
    string_t DetailsTraKey; // 0x18
};
struct ChampionMasteryMap { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    map_t<int32_t, link_ptr_t<MasteryData>> MasteryData; // 0x0
};
struct BaseLoadoutData: PropertyBase, ICatalogEntryOwner { // 0x4C
   // ctor: 0x00400000
   // init: 0x00400000
    CatalogEntry CatalogEntry; // 0x8
    string_t mNameTraKey; // 0x28
    string_t mDescriptionTraKey; // 0x34
};
struct LoadoutFeatureData { // 0x4C
   // ctor: 0x00607DD0
   // init: 0x00608CF0
    uint32_t mFeature; // 0x0
    optional_t<string_t> mMutator; // 0x4
    optional_t<string_t> mBinaryFile; // 0x14
    string_t mLoadoutCategory; // 0x24
    vector_t<string_t> mLoadoutProperties; // 0x30
    map_t<string_t, string_t> mGdsObjectPathTemplates; // 0x3C
    bool mLoadFromContentIds; // 0x48
};
struct RecallDecalData { // 0x34
   // ctor: 0x00608610
   // init: 0x00609050
    string_t EffectFile; // 0x0
    string_t ArrivalEffectFile; // 0xC
    string_t EmpoweredEffectFile; // 0x18
    string_t EmpoweredArrivalFile; // 0x24
    uint32_t RecallDecalId; // 0x30
};
struct GearSkinUpgrade: PropertyBase { // 0x14
   // ctor: 0x0062B440
   // init: 0x0062B9B0
    unique_ptr_t<GearData> mGearData; // 0x4
    string_t m_0x358D080B; // 0x8
};
struct SkinUpgradeData { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    vector_t<link_ptr_t<GearSkinUpgrade>> mGearSkinUpgrades; // 0x0
};
struct TftCompanionBucket { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    vector_t<hash_t> Companions; // 0x0
};
struct TftBotLoadoutConfiguration { // 0x24
   // ctor: 0x0062BB70
   // init: 0x0062BBC0
    vector_t<TftCompanionBucket> m_0xEFFBC65C; // 0x0
    vector_t<hash_t> MapSkins; // 0xC
};
struct BannerFlagData { // 0xFC
   // ctor: 0x0062AFA0
   // init: 0x0062B3D0
    SkinMeshDataProperties SkinMeshProperties; // 0x0
    link_ptr_t<AnimationGraphData> AnimationGraphData; // 0xF8
};
struct BannerFrameData { // 0xFC
   // ctor: 0x0062AE70
   // init: 0x0062B380
    link_ptr_t<AnimationGraphData> AnimationGraphData; // 0x0
    SkinMeshDataProperties SkinMeshProperties; // 0x4
};
struct CompanionData: BaseLoadoutData { // 0xB0
   // ctor: 0x0062AFE0
   // init: 0x0062B870
    uint32_t Rarity; // 0x4C
    hash_t mCharacter; // 0x50
    uint32_t mSkinId; // 0x5C
    uint32_t Level; // 0x60
    bool mDisabled; // 0x64
    string_t SpeciesLink; // 0x68
    string_t mStandaloneCircleIcon; // 0x74
    string_t mStandaloneLoadoutsIcon; // 0x80
    string_t mStandaloneLoadoutsLargeIcon; // 0x8C
    string_t mLoadScreen; // 0x98
};
struct CompanionSpeciesData { // 0x10
   // ctor: 0x00607F40
   // init: 0x00608200
    string_t mSpeciesName; // 0x0
    uint32_t mSpeciesId; // 0xC
};
struct SummonerEmote { // 0x40
   // ctor: 0x0062B300
   // init: 0x0062AED0
    uint32_t SummonerEmoteId; // 0x0
    link_ptr_t<VfxSystemDefinitionData> VfxSystem; // 0x4
    string_t AnnouncementIcon; // 0x8
    string_t SelectionIcon; // 0x14
    float_t RenderScale; // 0x20
    float_t VerticalOffset; // 0x24
    string_t VisibleSelectionName; // 0x28
};
struct SummonerEmoteSettings { // 0x8
   // ctor: 0x00522060
   // init: 0x00521FF0
    link_ptr_t<SummonerEmote> mFirstBlood; // 0x0
    link_ptr_t<SummonerEmote> mAce; // 0x4
};
struct GearData: PropertyBase { // 0x140
   // ctor: 0x0062B070
   // init: 0x0062B100
    SkinMeshDataProperties SkinMeshProperties; // 0x4
    link_ptr_t<AnimationGraphData> AnimationGraphData; // 0xFC
    unique_ptr_t<ResourceResolver> mVfxResourceResolver; // 0x100
    string_t mEquipAnimation; // 0x104
    string_t mSelfOnlyPortraitIcon; // 0x110
    string_t mPortraitIcon; // 0x11C
    vector_t<hash_t> m_0xB6C044FB; // 0x128
    vector_t<hash_t> m_0x21B6167E; // 0x134
};
struct ModeProgressionRewardData: BaseLoadoutData { // 0x68
   // ctor: 0x0062AE60
   // init: 0x0062B1B0
    string_t mBuffName; // 0x4C
    vector_t<string_t> mCharacters; // 0x58
    unique_ptr_t<ResourceResolver> mVfxResourceResolver; // 0x64
};
struct RegaliaData: BaseLoadoutData { // 0x5C
   // ctor: 0x0062B540
   // init: 0x0062B6A0
    string_t Texture; // 0x4C
};
struct RegaliaLookup { // 0x30
   // ctor: 0x0062B7D0
   // init: 0x0062AEE0
    string_t Tier; // 0x0
    link_ptr_t<RegaliaData> RegaliaCrest; // 0xC
    link_ptr_t<RegaliaData> RegaliaCrown1; // 0x10
    link_ptr_t<RegaliaData> RegaliaCrown2; // 0x14
    link_ptr_t<RegaliaData> RegaliaCrown3; // 0x18
    link_ptr_t<RegaliaData> RegaliaCrown4; // 0x1C
    link_ptr_t<RegaliaData> RegaliaTrim; // 0x20
    link_ptr_t<RegaliaData> RegaliaSplit1; // 0x24
    link_ptr_t<RegaliaData> RegaliaSplit2; // 0x28
    link_ptr_t<RegaliaData> RegaliaSplit3; // 0x2C
};
struct RegaliaRankedCrestEntry { // 0x1C
   // ctor: 0x005CA930
   // init: 0x005CA6F0
    link_ptr_t<RegaliaData> Base; // 0x0
    map_t<int32_t, link_ptr_t<RegaliaData>> m_0xFBB20410; // 0x4
    map_t<int32_t, link_ptr_t<RegaliaData>> m_0xAF2E170A; // 0x10
};
struct RegaliaRankedCrestMap { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    map_t<string_t, RegaliaRankedCrestEntry> m_0x723D6F91; // 0x0
};
struct RegaliaPrestigeCrestList { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    vector_t<link_ptr_t<RegaliaData>> PrestigeCrests; // 0x0
};
struct RegaliaRankedBannerMap { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    map_t<string_t, link_ptr_t<RegaliaData>> m_0xC5B8B568; // 0x0
};
struct t_0x2BA8FC33 { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    map_t<string_t, RegaliaData> m_0x5B1FD3C2; // 0x0
};
struct StatStoneEventToTrack { // 0x10
   // ctor: 0x0062B8E0
   // init: 0x0062B5A0
    uint32_t EventToTrack; // 0x0
    vector_t<unique_ptr_t<IStatStoneLogicDriver>> StatFilters; // 0x4
};
struct StatStoneData: BaseLoadoutData { // 0x84
   // ctor: 0x0062B990
   // init: 0x0062B590
    vector_t<StatStoneEventToTrack> EventsToTrack; // 0x4C
    link_ptr_t<StatStoneCategory> Category; // 0x58
    uint32_t m_0xFB2A56EF; // 0x5C
    uint32_t m_0x286FC9C3; // 0x60
    vector_t<uint64_t> Milestones; // 0x64
    bool EpicStatStone; // 0x70
    bool TriggeredFromScript; // 0x71
    bool IsRetired; // 0x72
    uint8_t TrackingType; // 0x73
    string_t StoneName; // 0x74
    bool m_0x92BD18AB; // 0x80
};
struct IStatStoneLogicDriver: PropertyBase { // 0x4
   // ctor: 0x00400000
   // init: 0x00400000
};
struct TargetHasUnitTagFilter: IStatStoneLogicDriver { // 0x20
   // ctor: 0x0062BAB0
   // init: 0x0062AEA0
    ObjectTags UnitTags; // 0x8
};
struct TrueDamageGivenFilter: IStatStoneLogicDriver { // 0x4
   // ctor: 0x0062BA80
   // init: 0x0062B600
};
struct CrowdControlFilter: IStatStoneLogicDriver { // 0x14
   // ctor: 0x0062AD20
   // init: 0x0062B220
    vector_t<uint8_t> m_0x20CF84AC; // 0x4
    bool TrackDuration; // 0x10
};
struct TargetHasBuffFilter: IStatStoneLogicDriver { // 0x10
   // ctor: 0x0062B040
   // init: 0x0062BB20
    vector_t<uint8_t> ValidBuffs; // 0x4
};
struct SourceTypeFilter: IStatStoneLogicDriver { // 0x8
   // ctor: 0x0062B410
   // init: 0x0062B3F0
    bool m_0x47BAC313; // 0x4
    bool m_0x1E3FCD64; // 0x5
    bool m_0xD5E57340; // 0x6
};
struct TargetTypeFilter: IStatStoneLogicDriver { // 0x8
   // ctor: 0x0062B4B0
   // init: 0x0062B850
    bool m_0x47BAC313; // 0x4
    bool m_0x1E3FCD64; // 0x5
    bool m_0xD5E57340; // 0x6
};
struct TargetTeamFilter: IStatStoneLogicDriver { // 0x8
   // ctor: 0x0062B8A0
   // init: 0x0062BA20
    bool Ally; // 0x4
    bool Enemy; // 0x5
    bool Self; // 0x6
};
struct SourceLessThanHealthPercentageFilter: IStatStoneLogicDriver { // 0x8
   // ctor: 0x0062AF80
   // init: 0x0062B880
    float_t HealthPercentage; // 0x4
};
struct AssistCountFilter: IStatStoneLogicDriver { // 0x8
   // ctor: 0x0062B740
   // init: 0x0062BAA0
    uint8_t AssistCount; // 0x4
};
struct MultiKillLogic: IStatStoneLogicDriver { // 0x4
   // ctor: 0x0062BB00
   // init: 0x0062AF70
};
struct DamageShieldedLogic: IStatStoneLogicDriver { // 0xC
   // ctor: 0x0062B820
   // init: 0x0062B910
    bool m_0xA1E033BE; // 0x4
    bool m_0x7944553A; // 0x5
    bool m_0x2AD527A6; // 0x6
    bool m_0x621E14DB; // 0x7
    bool m_0x60B7C1B6; // 0x8
    bool m_0xCBC2F8BA; // 0x9
    bool m_0x2EFB9D27; // 0xA
    bool m_0x1701CA0A; // 0xB
};
struct GoldSourceFilter: IStatStoneLogicDriver { // 0x8
   // ctor: 0x0062ACF0
   // init: 0x0062B110
    uint8_t ValidGoldSource; // 0x4
};
struct KillingSpreeFilter: IStatStoneLogicDriver { // 0x8
   // ctor: 0x0062B5C0
   // init: 0x0062B020
    int32_t KillingSpreeCount; // 0x4
};
struct NeutralMinionCampClearedLogic: IStatStoneLogicDriver { // 0x4
   // ctor: 0x0062BA60
   // init: 0x0062B180
};
struct TurretFirstBloodLogic: IStatStoneLogicDriver { // 0x4
   // ctor: 0x0062B190
   // init: 0x0062B760
};
struct StatStoneSet: PropertyBase, ICatalogEntryOwner { // 0x40
   // ctor: 0x0062B960
   // init: 0x0062AFD0
    string_t Name; // 0x8
    CatalogEntry CatalogEntry; // 0x14
    vector_t<link_ptr_t<StatStoneData>> StatStones; // 0x34
};
struct StatStoneCategory { // 0x44
   // ctor: 0x0062B160
   // init: 0x0062AD10
    string_t GameIconUnlit; // 0x0
    string_t GameIconLit; // 0xC
    string_t GameIconFull; // 0x18
    string_t GameIconMini; // 0x24
    color_t CategoryColor; // 0x30
};
struct t_0xEAD1B379 { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    map_t<uint32_t, link_ptr_t<VfxSystemDefinitionData>> m_0xFB403EDA; // 0x0
};
struct t_0x32BE2466 { // 0x10
   // ctor: 0x0062BB40
   // init: 0x0062B9E0
    map_t<uint32_t, link_ptr_t<t_0xEAD1B379>> m_0x1A28D722; // 0x4
};
struct TftDamageSkin: BaseLoadoutData { // 0xB8
   // ctor: 0x0062B5E0
   // init: 0x0062B3C0
    string_t StandaloneLoadoutsIcon; // 0x4C
    string_t StandaloneLoadoutsLargeIcon; // 0x58
    link_ptr_t<ResourceResolver> VfxResourceResolver; // 0x6C
    vector_t<string_t> AudioBankPaths; // 0x70
    string_t mName; // 0x80
    uint32_t Rarity; // 0x8C
    string_t DamageBuffName; // 0x90
    uint32_t SkinId; // 0x9C
    uint32_t Level; // 0xA0
    bool Disabled; // 0xA4
    float_t m_0x7ED5B4A7; // 0xA8
    vector_t<TftDamageSkinDescriptor> m_0x31AF5DC6; // 0xAC
};
struct TftDamageSkinDescriptor { // 0x1C
   // ctor: 0x0062B780
   // init: 0x0062B4E0
    uint32_t EffectType; // 0x0
    string_t EffectKey; // 0x4
    uint32_t AttachedToBone; // 0x10
    float_t EffectDelay; // 0x14
    uint32_t m_0x9D0CCA5B; // 0x18
};
struct TftMapGroupData { // 0x10
   // ctor: 0x00607F40
   // init: 0x00608200
    string_t mName; // 0x0
    uint32_t mId; // 0xC
};
struct TftMapSkin: BaseLoadoutData { // 0xA8
   // ctor: 0x0062B140
   // init: 0x0062B530
    string_t StandaloneLoadoutsIcon; // 0x4C
    string_t StandaloneLoadoutsLargeIcon; // 0x58
    string_t GroupLink; // 0x64
    uint32_t Rarity; // 0x78
    vector_t<string_t> AudioBankPaths; // 0x7C
    vector_t<hash_t> Characters; // 0x8C
    string_t MapContainer; // 0x98
    uint16_t m_0xAFC467EB; // 0xA4
    uint16_t m_0x6E39B04A; // 0xA6
};
struct TrophyData: BaseLoadoutData { // 0x15C
   // ctor: 0x0062B480
   // init: 0x0062ACD0
    float_t mPerceptionBubbleRadius; // 0x4C
    SkinMeshDataProperties SkinMeshProperties; // 0x50
    link_ptr_t<AnimationGraphData> AnimationGraphData; // 0x148
    unique_ptr_t<ResourceResolver> mVfxResourceResolver; // 0x14C
    string_t mBracketTraKey; // 0x150
};
struct TrophyPedestalData: BaseLoadoutData { // 0x160
   // ctor: 0x0062B120
   // init: 0x0062B4A0
    string_t mJointName; // 0x4C
    SkinMeshDataProperties SkinMeshProperties; // 0x58
    link_ptr_t<AnimationGraphData> AnimationGraphData; // 0x150
    string_t mTierTraKey; // 0x154
};
struct t_0x1650A4CE { // 0x4
   // ctor: 0x00400000
   // init: 0x00400000
};
struct AbilityResourceDynamicMaterialFloatDriver: IDynamicMaterialFloatDriver { // 0x8
   // ctor: 0x00640FB0
   // init: 0x00641320
    uint8_t Slot; // 0x4
};
struct AnimationFractionDynamicMaterialFloatDriver: IDynamicMaterialFloatDriver { // 0x8
   // ctor: 0x00641300
   // init: 0x00640E90
    hash_t mAnimationName; // 0x4
};
struct BuffCounterDynamicMaterialFloatDriver: IDynamicMaterialFloatDriver { // 0x14
   // ctor: 0x00640E20
   // init: 0x00641220
    string_t mScriptName; // 0x4
};
struct DistanceToPlayerMaterialFloatDriver: IDynamicMaterialFloatDriver { // 0xC
   // ctor: 0x00641380
   // init: 0x00641150
    float_t MinDistance; // 0x4
    float_t MaxDistance; // 0x8
};
struct t_0x9BD21F30: IDynamicMaterialBoolDriver { // 0x14
   // ctor: 0x006412B0
   // init: 0x00640F40
    string_t mKeyName; // 0x4
};
struct t_0x1E6C47FE: IDynamicMaterialFloatDriver { // 0x14
   // ctor: 0x006411E0
   // init: 0x006411B0
    string_t mKeyName; // 0x4
};
struct t_0xD0116DC8: IDynamicMaterialBoolDriver { // 0x10
   // ctor: 0x00640D90
   // init: 0x00641080
    string_t mKeyName; // 0x4
};
struct t_0xE856A498: IDynamicMaterialFloatDriver { // 0x10
   // ctor: 0x00640F80
   // init: 0x00640ED0
    string_t mKeyName; // 0x4
};
struct HasBuffDynamicMaterialBoolDriver: IDynamicMaterialBoolDriver { // 0x18
   // ctor: 0x006410B0
   // init: 0x006413B0
    string_t mScriptName; // 0x4
    float_t m_0xFF80DF7A; // 0x10
};
struct HasGearDynamicMaterialBoolDriver: IDynamicMaterialBoolDriver { // 0x8
   // ctor: 0x00641120
   // init: 0x00640F20
    uint8_t mGearIndex; // 0x4
};
struct HealthDynamicMaterialFloatDriver: IDynamicMaterialFloatDriver { // 0x4
   // ctor: 0x00640EB0
   // init: 0x00641330
};
struct IsAnimationPlayingDynamicMaterialBoolDriver: IDynamicMaterialBoolDriver { // 0x10
   // ctor: 0x00640D40
   // init: 0x00641280
    vector_t<hash_t> mAnimationNames; // 0x4
};
struct IsDeadDynamicMaterialBoolDriver: IDynamicMaterialBoolDriver { // 0x4
   // ctor: 0x00641050
   // init: 0x00641340
};
struct IsEnemyDynamicMaterialBoolDriver: IDynamicMaterialBoolDriver { // 0x4
   // ctor: 0x00640DF0
   // init: 0x00641100
};
struct IsInGrassDynamicMaterialBoolDriver: IDynamicMaterialBoolDriver { // 0x4
   // ctor: 0x00640D10
   // init: 0x00640F00
};
struct t_0x0C953D7F: IDynamicMaterialBoolDriver { // 0x4
   // ctor: 0x00641000
   // init: 0x00640E70
};
struct LearnedSpellDynamicMaterialBoolDriver: IDynamicMaterialBoolDriver { // 0x8
   // ctor: 0x00640FD0
   // init: 0x00641030
    uint8_t mSlot; // 0x4
};
struct t_0x1FBEA063: IDynamicMaterialDriver { // 0x4
   // ctor: 0x00640DD0
   // init: 0x00640E60
};
struct UvScaleBiasFromAnimationDynamicMaterialDriver: IDynamicMaterialDriver { // 0x14
   // ctor: 0x00641170
   // init: 0x00641250
    string_t mSubMeshName; // 0x4
    uint32_t m_0xDBAD132E; // 0x10
};
struct VelocityDynamicMaterialFloatDriver: IDynamicMaterialFloatDriver { // 0x4
   // ctor: 0x00641360
   // init: 0x00640D80
};
struct ParticleWadFileDescriptor: WadFileDescriptor { // 0x4
   // ctor: 0x00643970
   // init: 0x00643AC0
};
struct EmblemPosition { // 0x18
   // ctor: 0x00608150
   // init: 0x00607E90
    string_t mVertical; // 0x0
    string_t mHorizontal; // 0xC
};
struct EmblemData { // 0x14
   // ctor: 0x00643900
   // init: 0x00643CD0
    bool mShowOnLoadingScreen; // 0x0
    float_t mLoadingScreenScale; // 0x4
    string_t mImagePath; // 0x8
};
struct EmblemSettings { // 0xC
   // ctor: 0x00643C00
   // init: 0x00643BD0
    float_t mBottomFraction; // 0x4
    bool mDebugDrawEmblems; // 0x8
};
struct GameModeAutoItemPurchasingConfig { // 0x34
   // ctor: 0x006438C0
   // init: 0x00643D00
    int32_t m_0x19EF67A2; // 0x0
    vector_t<string_t> m_0xE34F62D0; // 0x4
    vector_t<string_t> m_0xC8ADFDBC; // 0x10
    vector_t<string_t> m_0x83F0CCCD; // 0x1C
    hash_t m_0x14596D09; // 0x28
};
struct GameModeChampionList { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    vector_t<hash_t> mChampions; // 0x0
};
struct GameModeConstant: PropertyBase { // 0x4
   // ctor: 0x00400000
   // init: 0x00400000
};
struct GameModeConstantFloat: GameModeConstant { // 0x8
   // ctor: 0x006438E0
   // init: 0x00643C30
    float_t mValue; // 0x4
};
struct GameModeConstantInteger: GameModeConstant { // 0x8
   // ctor: 0x00643E30
   // init: 0x00643D60
    int32_t mValue; // 0x4
};
struct GameModeConstantBool: GameModeConstant { // 0x8
   // ctor: 0x00643DB0
   // init: 0x00643E20
    bool mValue; // 0x4
};
struct GameModeConstantString: GameModeConstant { // 0x10
   // ctor: 0x00643C50
   // init: 0x00643D80
    string_t mValue; // 0x4
};
struct GameModeConstantStringVector: GameModeConstant { // 0x10
   // ctor: 0x006439B0
   // init: 0x00643B80
    vector_t<string_t> mValue; // 0x4
};
struct GameModeConstantTraKey: GameModeConstant { // 0x10
   // ctor: 0x00643A20
   // init: 0x00643940
    string_t mValue; // 0x4
};
struct GameModeConstantVector3f: GameModeConstant { // 0x10
   // ctor: 0x00643BA0
   // init: 0x00643B30
    point3D_t mValue; // 0x4
};
struct GameModeConstantFloatPerLevel: GameModeConstant { // 0x10
   // ctor: 0x006439E0
   // init: 0x00643B10
    vector_t<float_t> mValues; // 0x4
};
struct GameModeConstantsGroup { // 0x20
   // ctor: 0x00643E00
   // init: 0x00643BF0
    unordered_map_t<hash_t, unique_ptr_t<GameModeConstant>> mConstants; // 0x0
};
struct GameModeConstants { // 0x20
   // ctor: 0x00643CB0
   // init: 0x00643AE0
    unordered_map_t<hash_t, GameModeConstantsGroup> mGroups; // 0x0
};
struct GameModeItemList { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    vector_t<hash_t> mItems; // 0x0
};
struct GameModeMapData { // 0xF8
   // ctor: 0x00643DD0
   // init: 0x00643A10
    hash_t mModeName; // 0x4
    vector_t<link_ptr_t<GameModeChampionList>> mChampionLists; // 0x8
    vector_t<link_ptr_t<GameModeItemList>> ItemLists; // 0x14
    link_ptr_t<ItemShopGameModeData> mItemShopData; // 0x20
    bool mRelativeColorization; // 0x24
    link_ptr_t<AnnouncementMap> AnnouncementsMapping; // 0x28
    link_ptr_t<NeutralTimers> mNeutralTimersDisplay; // 0x2C
    hash_t mCursorConfig; // 0x30
    hash_t mCursorConfigUpdate; // 0x3C
    vector_t<link_ptr_t<IHudLoadingScreenWidget>> m_0x70B29C3D; // 0x48
    string_t mLoadingScreenBackground; // 0x54
    hash_t mHudScoreData; // 0x60
    link_ptr_t<RenderStyleData> mRenderStyle; // 0x6C
    link_ptr_t<FloatingTextOverride> mFloatingTextOverride; // 0x70
    link_ptr_t<GlobalStatsUiData> mStatsUiData; // 0x74
    vector_t<link_ptr_t<t_0x15502626>> m_0x8BD9F7D8; // 0x78
    bool mChampionIndicatorEnabled; // 0x84
    bool ItemShopEnabled; // 0x85
    link_ptr_t<ExperienceCurveData> mExperienceCurveData; // 0x88
    link_ptr_t<ExperienceModData> mExperienceModData; // 0x8C
    link_ptr_t<DeathTimes> mDeathTimes; // 0x90
    link_ptr_t<LoadScreenTipConfiguration> mLoadScreenTipConfiguration; // 0x94
    link_ptr_t<MapLocatorArray> mMapLocators; // 0x98
    PerkReplacementList mPerkReplacements; // 0x9C
    link_ptr_t<MissionBuffData> mMissionBuffData; // 0xA8
    link_ptr_t<SurrenderData> mSurrenderSettings; // 0xAC
    link_ptr_t<GameModeAutoItemPurchasingConfig> m_0x6941E612; // 0xB0
    bool m_0x882A6450; // 0xB4
    vector_t<link_ptr_t<ScriptDataObjectList>> mScriptDataObjectLists; // 0xB8
    link_ptr_t<GameModeConstants> mGameModeConstants; // 0xC4
    link_ptr_t<GameplayConfig> mGameplayConfig; // 0xE8
    string_t m_0xF74C67BB; // 0xEC
};
struct t_0x15502626 { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    vector_t<hash_t> Spells; // 0x0
};
struct GameMutatorExpansions { // 0x18
   // ctor: 0x006086D0
   // init: 0x00608E10
    string_t mExpandedMutator; // 0x0
    vector_t<string_t> mMutators; // 0xC
};
struct IGameCalculationPart: PropertyBase { // 0x4
   // ctor: 0x00400000
   // init: 0x00400000
};
struct EffectValueCalculationPart: IGameCalculationPart { // 0x8
   // ctor: 0x006639F0
   // init: 0x00663240
    int32_t mEffectIndex; // 0x4
};
struct NamedDataValueCalculationPart: IGameCalculationPart { // 0x8
   // ctor: 0x00663770
   // init: 0x006631A0
    hash_t mDataValue; // 0x4
};
struct CooldownMultiplierCalculationPart: IGameCalculationPart { // 0x4
   // ctor: 0x00663630
   // init: 0x006632F0
};
struct CustomReductionMultiplierCalculationPart: IGameCalculationPart { // 0xC
   // ctor: 0x006638C0
   // init: 0x00663180
    unique_ptr_t<IGameCalculationPart> m_0x6E82B179; // 0x4
    float_t mMaximumReductionPercent; // 0x8
};
struct ProductOfSubPartsCalculationPart: IGameCalculationPart { // 0xC
   // ctor: 0x00663510
   // init: 0x006635D0
    unique_ptr_t<IGameCalculationPart> mPart1; // 0x4
    unique_ptr_t<IGameCalculationPart> mPart2; // 0x8
};
struct SumOfSubPartsCalculationPart: IGameCalculationPart { // 0x10
   // ctor: 0x00663120
   // init: 0x00663280
    vector_t<unique_ptr_t<IGameCalculationPart>> mSubparts; // 0x4
};
struct t_0x803DAE4C: IGameCalculationPart { // 0x18
   // ctor: 0x006633E0
   // init: 0x006632C0
    optional_t<float_t> mCeiling; // 0x4
    optional_t<float_t> mFloor; // 0x8
    vector_t<unique_ptr_t<IGameCalculationPart>> mSubparts; // 0xC
};
struct NumberCalculationPart: IGameCalculationPart { // 0x8
   // ctor: 0x00663330
   // init: 0x00663370
    float_t mNumber; // 0x4
};
struct IGameCalculationPartWithStats: IGameCalculationPart { // 0x8
   // ctor: 0x00400000
   // init: 0x00400000
    uint8_t mStat; // 0x4
    uint8_t mStatFormula; // 0x5
};
struct StatByCoefficientCalculationPart: IGameCalculationPartWithStats { // 0xC
   // ctor: 0x006630F0
   // init: 0x00663260
    float_t mCoefficient; // 0x8
};
struct StatBySubPartCalculationPart: IGameCalculationPartWithStats { // 0xC
   // ctor: 0x00663890
   // init: 0x00663970
    unique_ptr_t<IGameCalculationPart> mSubpart; // 0x8
};
struct StatByNamedDataValueCalculationPart: IGameCalculationPartWithStats { // 0xC
   // ctor: 0x00663600
   // init: 0x006630B0
    hash_t mDataValue; // 0x8
};
struct t_0x05ABDFAB: IGameCalculationPart { // 0x10
   // ctor: 0x006636A0
   // init: 0x00663810
    uint8_t mStat; // 0x4
    uint8_t mStatFormula; // 0x5
    hash_t mDataValue; // 0x8
    float_t m_0xBFE6AD01; // 0xC
};
struct t_0xE9FB4D18: IGameCalculationPart { // 0xC
   // ctor: 0x00663920
   // init: 0x006630D0
    unique_ptr_t<IGameCalculationPart> m_0x616627C4; // 0x4
    uint8_t m_0x465802EA; // 0x8
    uint8_t m_0x27833DCC; // 0x9
};
struct SubPartScaledProportionalToStat: IGameCalculationPart { // 0x28
   // ctor: 0x00663500
   // init: 0x00663390
    unique_ptr_t<IGameCalculationPart> mSubpart; // 0x4
    float_t mRatio; // 0x8
    uint8_t mStat; // 0xC
    uint8_t mStatFormula; // 0xD
    string_t mStyleTag; // 0x10
    string_t m_0xA5749B52; // 0x1C
};
struct AbilityResourceByCoefficientCalculationPart: IGameCalculationPart { // 0xC
   // ctor: 0x006631C0
   // init: 0x00663990
    float_t mCoefficient; // 0x4
    uint8_t mAbilityResource; // 0x8
    uint8_t mStatFormula; // 0x9
};
struct IGameCalculationPartWithBuffCounter: IGameCalculationPart { // 0x20
   // ctor: 0x00400000
   // init: 0x00400000
    hash_t mBuffName; // 0x4
    string_t mIconKey; // 0x8
    string_t mScalingTagKey; // 0x14
};
struct BuffCounterByCoefficientCalculationPart: IGameCalculationPartWithBuffCounter { // 0x24
   // ctor: 0x006635F0
   // init: 0x00663650
    float_t mCoefficient; // 0x20
};
struct BuffCounterByNamedDataValueCalculationPart: IGameCalculationPartWithBuffCounter { // 0x24
   // ctor: 0x006630A0
   // init: 0x00663540
    hash_t mDataValue; // 0x20
};
struct IGameCalculationPartByCharLevel: IGameCalculationPart { // 0x4
   // ctor: 0x00400000
   // init: 0x00400000
};
struct ByCharLevelInterpolationCalculationPart: IGameCalculationPartByCharLevel { // 0x10
   // ctor: 0x006638F0
   // init: 0x00663950
    float_t mStartValue; // 0x4
    float_t mEndValue; // 0x8
    bool m_0x7FE8E3B3; // 0xC
    bool m_0xA331F6BF; // 0xD
};
struct ByCharLevelBreakpointsCalculationPart: IGameCalculationPartByCharLevel { // 0x18
   // ctor: 0x006636D0
   // init: 0x00663430
    float_t mLevel1Value; // 0x4
    float_t m_0x02DEB550; // 0x8
    vector_t<Breakpoint> mBreakpoints; // 0xC
};
struct Breakpoint { // 0xC
   // ctor: 0x006634D0
   // init: 0x006632A0
    uint32_t mLevel; // 0x0
    float_t m_0xD5FD07ED; // 0x4
    float_t m_0x57FDC438; // 0x8
};
struct ByCharLevelFormulaCalculationPart: IGameCalculationPartByCharLevel { // 0x80
   // ctor: 0x006631F0
   // init: 0x00663870
    array_t<float_t, 31> mValues; // 0x4
};
struct t_0x663D5E00: IGameCalculationPart { // 0xC
   // ctor: 0x00663790
   // init: 0x00663310
    float_t Coefficient; // 0x4
    uint8_t Epicness; // 0x8
};
struct IGameCalculation: PropertyBase { // 0xC
   // ctor: 0x00400000
   // init: 0x00400000
    unique_ptr_t<IGameCalculationPart> mMultiplier; // 0x4
    uint8_t m_0xCBCAC618; // 0x8
    uint8_t m_0x37070A8D; // 0x9
    uint8_t m_0xE6EEBB2F; // 0xA
    bool TooltipOnly; // 0xB
};
struct GameCalculation: IGameCalculation { // 0x20
   // ctor: 0x006637C0
   // init: 0x00663590
    vector_t<unique_ptr_t<IGameCalculationPart>> mFormulaParts; // 0xC
    bool mDisplayAsPercent; // 0x18
    int32_t mPrecision; // 0x1C
};
struct GameCalculationModified: IGameCalculation { // 0x14
   // ctor: 0x00663830
   // init: 0x00663150
    optional_t<int32_t> mOverrideSpellLevel; // 0xC
    hash_t mModifiedGameCalculation; // 0x10
};
struct GameCalculationConditional: IGameCalculation { // 0x18
   // ctor: 0x006639B0
   // init: 0x006634A0
    hash_t mDefaultGameCalculation; // 0xC
    hash_t mConditionalGameCalculation; // 0x10
    unique_ptr_t<ICastRequirement> m_0xC0482365; // 0x14
};
struct GameplayConfig { // 0xD0
   // ctor: 0x00663350
   // init: 0x00663230
    float_t mSpellPostponeTimeoutSec; // 0x4
    float_t mAutoAttackMinPreCastLockoutDeltaTimeSec; // 0x8
    float_t mAutoAttackMinPostCastLockoutDeltaTimeSec; // 0xC
    float_t mLethalityPercentGivenAtLevel0; // 0x10
    int32_t mLethalityScalesToLevel; // 0x14
    int32_t mLethalityScalesCapsAtLevel; // 0x18
    float_t mLethalityRatioFromTarget; // 0x1C
    float_t mLethalityRatioFromAttacker; // 0x20
    float_t AbilityHasteMax; // 0x24
    float_t mCritTotalArmorPenPercent; // 0x28
    float_t mCritBonusArmorPenPercent; // 0x2C
    float_t mCritGlobalDamageMultiplier; // 0x30
    float_t mAdaptiveForceAbilityPowerScale; // 0x34
    float_t mAdaptiveForceAttackDamageScale; // 0x38
    float_t mMinionDeathDelay; // 0x3C
    float_t mMinionAutoLeeway; // 0x40
    float_t mMinionAaHelperLimit; // 0x44
    float_t mItemSellQueueTime; // 0x48
    CcScoreMultipliers mCcScoreMultipliers; // 0x4C
    bool mPerSlotCdrIsAdditive; // 0x98
    vector_t<hash_t> mSummonerSpells; // 0x9C
    vector_t<hash_t> mLegacySummonerSpells; // 0xA8
    hash_t ItemsRolesPerRow; // 0xB4
    hash_t m_0xA64802F2; // 0xC0
    unique_ptr_t<IGameCalculation> mBasicAttackCalculation; // 0xCC
};
struct EnchantmentGroup { // 0x24
   // ctor: 0x0067C870
   // init: 0x0067C620
    bool mCanSidegrade; // 0x0
    vector_t<int32_t> mEnchantments; // 0x4
    vector_t<int32_t> mBaseItems; // 0x10
    int32_t mItemIdRangeMinimum; // 0x1C
    int32_t mItemIdRangeMaximum; // 0x20
};
struct ItemData { // 0x4EC
   // ctor: 0x0067C710
   // init: 0x0067CA60
    string_t mRequiredChampion; // 0x4
    string_t mRequiredAlly; // 0x10
    string_t mRequiredSpellName; // 0x1C
    string_t mRequiredBuffCurrencyName; // 0x28
    vector_t<hash_t> mRequiredPurchaseIdentities; // 0x34
    string_t mDisabledDescriptionOverride; // 0x40
    string_t mParentEnchantmentGroup; // 0x4C
    string_t mDeathRecapName; // 0x58
    int32_t mRequiredLevel; // 0x64
    int32_t ItemId; // 0x68
    int32_t MaxStack; // 0x6C
    vector_t<link_ptr_t<ItemGroup>> mItemGroups; // 0x70
    vector_t<link_ptr_t<ItemAdviceAttribute>> mItemAdviceAttributes; // 0x7C
    hash_t ItemVoGroup; // 0x88
    int32_t Price; // 0x8C
    int32_t mRequiredBuffCurrencyCost; // 0x90
    float_t mSidegradeCredit; // 0x94
    bool Consumed; // 0x98
    bool UsableInStore; // 0x99
    bool ConsumeOnAcquire; // 0x9A
    bool mItemCalloutPlayer; // 0x9B
    bool mItemCalloutSpectator; // 0x9C
    uint8_t ClearUndoHistory; // 0x9D
    bool mCanBeSold; // 0x9E
    bool mHiddenFromOpponents; // 0x9F
    bool mIsEnchantment; // 0xA0
    int32_t SpecialRecipe; // 0xA4
    uint8_t Epicness; // 0xA8
    uint8_t SecondaryEpicness; // 0xA9
    vector_t<link_ptr_t<ItemData>> RecipeItemLinks; // 0xAC
    vector_t<link_ptr_t<ItemData>> RequiredItemLinks; // 0xB8
    vector_t<link_ptr_t<ItemData>> SidegradeItemLinks; // 0xC4
    vector_t<link_ptr_t<ItemModifier>> mItemModifiers; // 0xD0
    vector_t<string_t> mScripts; // 0xDC
    link_ptr_t<ItemData> ParentEnchantmentLink; // 0xE8
    link_ptr_t<ItemData> ParentItemLink; // 0xEC
    float_t mFlatCooldownMod; // 0xF0
    float_t mPercentCooldownMod; // 0xF4
    float_t mAbilityHasteMod; // 0xF8
    float_t mFlatHpPoolMod; // 0xFC
    float_t mPercentHpPoolMod; // 0x100
    float_t mFlatHpRegenMod; // 0x104
    float_t mPercentHpRegenMod; // 0x108
    float_t mPercentBaseHpRegenMod; // 0x10C
    float_t mPercentTenacityItemMod; // 0x110
    float_t mPercentSlowResistMod; // 0x124
    float_t mFlatMovementSpeedMod; // 0x128
    float_t mPercentMovementSpeedMod; // 0x12C
    float_t mPercentMultiplicativeMovementSpeedMod; // 0x130
    float_t mFlatArmorMod; // 0x134
    float_t mPercentArmorMod; // 0x138
    float_t mFlatArmorPenetrationMod; // 0x13C
    float_t mPercentArmorPenetrationMod; // 0x140
    float_t mPercentBonusArmorPenetrationMod; // 0x144
    float_t mFlatMagicPenetrationMod; // 0x148
    float_t mPercentMagicPenetrationMod; // 0x14C
    float_t mPercentBonusMagicPenetrationMod; // 0x150
    float_t mFlatSpellBlockMod; // 0x154
    float_t mPercentSpellBlockMod; // 0x158
    float_t mFlatDodgeMod; // 0x15C
    float_t mFlatCritChanceMod; // 0x160
    float_t mFlatMissChanceMod; // 0x164
    float_t mFlatCritDamageMod; // 0x168
    float_t mPercentCritDamageMod; // 0x16C
    float_t mFlatPhysicalDamageMod; // 0x170
    float_t mPercentPhysicalDamageMod; // 0x174
    float_t mFlatMagicDamageMod; // 0x178
    float_t mPercentMagicDamageMod; // 0x17C
    float_t mFlatPhysicalReduction; // 0x180
    float_t mPercentPhysicalReduction; // 0x184
    float_t mFlatMagicReduction; // 0x188
    float_t mPercentMagicReduction; // 0x18C
    float_t mPercentExpBonus; // 0x190
    float_t mFlatAttackRangeMod; // 0x194
    float_t mPercentAttackRangeMod; // 0x198
    float_t mFlatCastRangeMod; // 0x19C
    float_t mPercentCastRangeMod; // 0x1A0
    float_t mPercentAttackSpeedMod; // 0x1A4
    float_t mPercentMultiplicativeAttackSpeedMod; // 0x1A8
    float_t mPercentHealingAmountMod; // 0x1AC
    float_t mPercentLifeStealMod; // 0x1B0
    float_t mPercentSpellVampMod; // 0x1B4
    float_t PercentOmnivampMod; // 0x1B8
    float_t PercentPhysicalVampMod; // 0x1BC
    float_t mPercentSpellEffectivenessMod; // 0x1C0
    float_t mFlatBubbleRadiusMod; // 0x1C4
    float_t mPercentBubbleRadiusMod; // 0x1C8
    float_t SellBackModifier; // 0x1CC
    float_t mCooldownShowDisabledDuration; // 0x1D0
    float_t FlatMpPoolMod; // 0x1D4
    float_t PercentMpPoolMod; // 0x1D8
    float_t FlatMpRegenMod; // 0x1DC
    float_t PercentMpRegenMod; // 0x1E0
    float_t PercentBaseMpRegenMod; // 0x1E4
    ItemDataBuild mItemDataBuild; // 0x378
    ItemDataAvailability mItemDataAvailability; // 0x384
    vector_t<string_t> mCategories; // 0x388
    int32_t mBuildDepth; // 0x394
    vector_t<ItemDataValue> mDataValues; // 0x398
    map_t<hash_t, t_0x61F8C41C> m_0xFB56608C; // 0x3A4
    map_t<hash_t, unique_ptr_t<IGameCalculation>> mItemCalculations; // 0x3B0
    vector_t<uint8_t> mItemAttributes; // 0x3BC
    int32_t m_0x224A3815; // 0x3C8
    uint8_t m_0xC01BB6DD; // 0x3CC
    uint8_t m_0x51265C89; // 0x3CD
    ItemDataClient mItemDataClient; // 0x3D0
    unique_ptr_t<ResourceResolver> mVfxResourceResolver; // 0x478
    string_t mDisplayName; // 0x47C
    vector_t<float_t> mEffectAmount; // 0x488
    vector_t<float_t> mEnchantmentEffectAmount; // 0x494
    vector_t<float_t> mEffectByLevelAmount; // 0x4A0
    string_t SpellName; // 0x4B0
    bool Clickable; // 0x4BC
    bool mMajorActiveItem; // 0x4BD
};
struct ItemDataValue: PropertyBase { // 0x18
   // ctor: 0x0067C970
   // init: 0x0067C730
    string_t mName; // 0x4
    float_t mValue; // 0x10
};
struct t_0x61F8C41C { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    vector_t<ItemDataValue> m_0x06AFEF1B; // 0x0
};
struct ItemDataAvailability { // 0x3
   // ctor: 0x0067CB70
   // init: 0x0067C9B0
    bool mInStore; // 0x0
    bool mForceLoad; // 0x1
    bool mHidefromAll; // 0x2
};
struct ItemDataBuild { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    vector_t<link_ptr_t<ItemData>> ItemLinks; // 0x0
};
struct ItemGroup { // 0x30
   // ctor: 0x0067CDE0
   // init: 0x0067CAF0
    hash_t mItemGroupId; // 0x0
    int32_t mMaxGroupOwnable; // 0x4
    int32_t mInventorySlotMin; // 0x8
    int32_t mInventorySlotMax; // 0xC
    float_t mPurchaseCooldown; // 0x10
    bool mCooldownExtendedByAmbientGoldStart; // 0x14
    vector_t<link_ptr_t<ItemModifier>> mItemModifiers; // 0x18
};
struct ItemModifier { // 0xF0
   // ctor: 0x0067C780
   // init: 0x0067C800
    hash_t mItemModifierId; // 0x0
    link_ptr_t<ItemData> mModifiedItem; // 0x4
    link_ptr_t<ItemGroup> mModifiedGroup; // 0x8
    link_ptr_t<ItemData> mModifiedIfBuildsFromItem; // 0xC
    int32_t mMinimumModifierInstancesToBeActive; // 0x10
    int32_t mMaximumModifierInstancesToBeActive; // 0x14
    int32_t mMaximumDeltasToStack; // 0x18
    bool mShowAsModifiedInUi; // 0x1C
    bool mModifierIsInheritedByOwnedParentItems; // 0x1D
    vector_t<link_ptr_t<ItemData>> mAddedBuildFrom; // 0x20
    vector_t<link_ptr_t<ItemData>> mRemovedBuildFrom; // 0x2C
    bool mReplaceInsteadOfAddingBuildFrom; // 0x38
    bool mIgnoreMaxGroupOwnable; // 0x39
    hash_t mIgnoreSpecificMaxGroupOwnable; // 0x3C
    float_t mDeltaGoldCost; // 0x48
    float_t mDeltaGoldCostPercent; // 0x4C
    float_t mDeltaBuffCurrencyCostPercent; // 0x50
    int32_t mDeltaRequiredLevel; // 0x54
    int32_t mDeltaBuffCurrencyCost; // 0x58
    int32_t mDeltaMaxStacks; // 0x5C
    int32_t mVisualPriority; // 0x60
    string_t InventoryIconToOverlay; // 0x64
    string_t mDescriptionToAppend; // 0x70
    string_t mDescriptionToPrepend; // 0x7C
    string_t mDescriptionToReplace; // 0x88
    string_t mDynamicTooltipToAppend; // 0x94
    string_t mDynamicTooltipToPrepend; // 0xA0
    string_t mDynamicTooltipToReplace; // 0xAC
    string_t mDisplayNameToAppend; // 0xB8
    string_t mDisplayNameToPrepend; // 0xC4
    string_t mDisplayNameToReplace; // 0xD0
    bool mClickableToEnable; // 0xDC
    bool mMajorActiveItemToEnable; // 0xDD
    string_t mSpellNameToReplace; // 0xE0
};
struct ItemDataClient { // 0xA8
   // ctor: 0x0067CB90
   // init: 0x0067CF00
    unique_ptr_t<TooltipInstanceItem> mTooltipData; // 0x4
    string_t mDescription; // 0x8
    string_t mDynamicTooltip; // 0x14
    string_t mShopTooltip; // 0x20
    string_t ShopExtendedTooltip; // 0x2C
    uint8_t Epicness; // 0x38
    float_t EffectRadius; // 0x3C
    array_t<int32_t, 16> mFloatVarsDecimals; // 0x40
    string_t InventoryIcon; // 0x80
    string_t InventoryIconSmall; // 0x8C
    string_t InventoryIconLarge; // 0x98
    link_ptr_t<StaticMaterialDef> InventoryIconMaterial; // 0xA4
};
struct ChampionItemRecommendations { // 0x30
   // ctor: 0x0067CCD0
   // init: 0x0067CA00
    hash_t m_0xCC35FF18; // 0x0
    hash_t mContextListLink; // 0xC
    vector_t<ItemCareyOverrideStartingItemSet> m_0xAD6D25A8; // 0x18
    vector_t<hash_t> m_0x2D7FD821; // 0x24
};
struct ItemRecommendationItemList { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    vector_t<uint32_t> mItemList; // 0x0
};
struct ItemRecommendationContextList { // 0x4C
   // ctor: 0x0067C4E0
   // init: 0x0067C910
    unordered_map_t<uint32_t, ItemRecommendationItemList> mAllStartingItemIds; // 0x0
    unordered_map_t<uint32_t, ItemRecommendationItemList> m_0xA109530E; // 0x20
    vector_t<ItemRecommendationContext> mContexts; // 0x40
};
struct ItemRecommendationContext { // 0x1B8
   // ctor: 0x0067C660
   // init: 0x0067C5D0
    uint32_t mChampionId; // 0x0
    uint32_t mMapId; // 0x4
    hash_t m_0x37B75F5C; // 0x8
    hash_t mPosition; // 0xC
    bool mIsDefaultPosition; // 0x10
    vector_t<hash_t> mPopularItems; // 0x14
    ItemRecommendationMatrix mStartingItemMatrix; // 0x20
    vector_t<ItemRecommendationItemList> mStartingItemBundles; // 0xE0
    ItemRecommendationMatrix mCompletedItemMatrix; // 0xF8
};
struct ItemRecommendationChoices { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    vector_t<uint32_t> mChoices; // 0x0
};
struct ItemRecommendationMatrixRow { // 0x20
   // ctor: 0x0067CD30
   // init: 0x0067C690
    unordered_map_t<string_t, ItemRecommendationChoices> mChoicesMap; // 0x0
};
struct ItemRecommendationMatrix { // 0xC0
   // ctor: 0x0067CAB0
   // init: 0x0067C840
    array_t<ItemRecommendationMatrixRow, 6> Mrows; // 0x0
};
struct t_0x5A3BC52D { // 0x10
   // ctor: 0x0067CBB0
   // init: 0x0067CD60
    vector_t<hash_t> Items; // 0x0
    uint32_t m_0x50EF1A22; // 0xC
};
struct ItemRecommendationCondition { // 0x14
   // ctor: 0x0067C810
   // init: 0x0067C8E0
    hash_t mItem; // 0x0
    uint32_t mDisplayLimit; // 0xC
    uint8_t mGroupId; // 0x10
};
struct ItemRecommendationOverrideContext { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    uint32_t mMapId; // 0x0
    hash_t m_0x37B75F5C; // 0x4
    hash_t mPosition; // 0x8
};
struct ItemRecommendationOverrideStartingItemSet { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    vector_t<hash_t> mStartingItems; // 0x0
};
struct ItemRecommendationOverride { // 0x40
   // ctor: 0x0067CEB0
   // init: 0x0067C540
    bool mForceOverride; // 0x0
    vector_t<ItemRecommendationOverrideContext> mOverrideContexts; // 0x4
    vector_t<ItemRecommendationOverrideStartingItemSet> mStartingItemSets; // 0x10
    vector_t<t_0x5A3BC52D> mRecItemRanges; // 0x1C
    vector_t<hash_t> mCoreItems; // 0x28
    vector_t<ItemRecommendationCondition> mRecommendedItems; // 0x34
};
struct ItemRecommendationOverrideSet { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    vector_t<ItemRecommendationOverride> mOverrides; // 0x0
};
struct ItemAdviceAttribute { // 0xC
   // ctor: 0x0067CE10
   // init: 0x0067CB50
    string_t mAttribute; // 0x0
};
struct ItemCareyOverrideStartingItemSet { // 0xC
   // ctor: 0x0067CC30
   // init: 0x0067C8D0
    hash_t mAttribute; // 0x0
};
struct ItemCareyOverrideStartingItemSetSet { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    vector_t<ItemCareyOverrideStartingItemSet> m_0x6CA781CD; // 0x0
};
struct ItemShopGameModeData { // 0x2C
   // ctor: 0x0067CAA0
   // init: 0x0067CC50
    vector_t<hash_t> m_0xC561F8E9; // 0x0
    uint32_t m_0xC3B3430A; // 0xC
    hash_t m_0x51A18BC3; // 0x10
    map_t<hash_t, hash_t> m_0x897C69B7; // 0x14
    map_t<uint32_t, uint32_t> RecItemsSwaps; // 0x20
};
struct CollectiblesEsportsTeamData { // 0x28
   // ctor: 0x006A2E50
   // init: 0x006A2D60
    uint32_t TeamId; // 0x0
    string_t ShortName; // 0x4
    string_t FullName; // 0x10
    string_t LeagueName; // 0x1C
};
struct SummonerIconData { // 0x24
   // ctor: 0x006A2DF0
   // init: 0x006A2EE0
    uint32_t IconId; // 0x0
    link_ptr_t<CollectiblesEsportsTeamData> EsportsTeam; // 0x4
    string_t GameTexture; // 0x8
    bool m_0x50E5B6E1; // 0x14
    string_t EsportsEventMutator; // 0x18
};
struct LiveFeatureToggles { // 0x44
   // ctor: 0x006B8990
   // init: 0x006B8A80
    LolFeatureToggles mLolToggles; // 0x4
    GameplayFeatureToggles mGameplayToggles; // 0x30
    EngineFeatureToggles mEngineToggles; // 0x3C
};
struct LolFeatureToggles { // 0x2C
   // ctor: 0x006B8AD0
   // init: 0x006B8BB0
    bool PromoController; // 0x4
    bool m_0xF2505841; // 0x5
    bool m_0x6DBEE4B7; // 0x6
    bool m_0xA3820B10; // 0x7
    bool ItemUndo; // 0x8
    bool NewSpellScript; // 0x9
    bool QueuedOrdersTriggerPreIssueOrder; // 0xA
    bool EnableCustomPlayerScoreColoring; // 0xB
    bool CloseOnEndGameAfterDelay; // 0xC
    bool AbilityResetUi; // 0xD
    bool CooldownSpellQueueing; // 0xE
    bool m_0xA6CC4DA4; // 0xF
    bool UseNewAttackSpeed; // 0x10
    bool m_0xA6000D17; // 0x11
    bool m_0xED504579; // 0x12
    bool UseNewFireBbEvents; // 0x13
    bool m_0xD3323EBC; // 0x14
    bool m_0x8CD3B1F9; // 0x15
    bool m_0x3E3C2065; // 0x16
    bool m_0x6F0BA2B0; // 0x17
    bool m_0x59E03167; // 0x18
    bool m_0xCC5E3F8D; // 0x19
    bool m_0xF1125A78; // 0x1A
    bool m_0x768400A9; // 0x1B
    bool m_0x069B85D1; // 0x1C
    bool m_0x9B710BF6; // 0x1D
    bool m_0x68C9483D; // 0x1E
    bool m_0xC779DA22; // 0x1F
    bool m_0x2F0E955A; // 0x20
    bool m_0x8BAB003A; // 0x21
    bool m_0x85AF0CB5; // 0x22
    bool m_0x84FE7CCF; // 0x23
    bool m_0x90E08CC7; // 0x24
    bool m_0xC25A56FB; // 0x25
    bool m_0x9CFC57BA; // 0x26
    bool m_0x40BAE5A8; // 0x27
    bool m_0xDE421B66; // 0x28
    bool m_0x8DC6F20A; // 0x29
};
struct GdsMapObjectExtraInfo: PropertyBase { // 0x4
   // ctor: 0x00400000
   // init: 0x00400000
};
struct GdsMapObjectAnimationInfo: GdsMapObjectExtraInfo { // 0x18
   // ctor: 0x006B8A90
   // init: 0x006B8A00
    string_t DefaultAnimation; // 0x4
    bool Looping; // 0x10
    bool DestroyOnCompletion; // 0x11
    float_t Duration; // 0x14
};
struct GdsMapObjectLightingInfo: GdsMapObjectExtraInfo { // 0x64
   // ctor: 0x006B8B70
   // init: 0x006B8B00
    array_t<point4D_t, 6> Colors; // 0x4
};
struct GdsMapObjectBannerInfo: GdsMapObjectExtraInfo { // 0x8
   // ctor: 0x006B8C60
   // init: 0x006B8B50
    link_ptr_t<EsportsBannerData> BannerData; // 0x4
};
struct GdsMapObject: GenericMapPlaceable { // 0x84
   // ctor: 0x006B8B90
   // init: 0x006B8C00
    point3D_t BoxMin; // 0x58
    point3D_t BoxMax; // 0x64
    uint8_t Type; // 0x70
    bool IgnoreCollisionOnPlacement; // 0x71
    bool EyeCandy; // 0x72
    uint32_t MapObjectSkinId; // 0x74
    vector_t<unique_ptr_t<GdsMapObjectExtraInfo>> ExtraInfo; // 0x78
};
struct LootOutputBase: PropertyBase { // 0x4
   // ctor: 0x00400000
   // init: 0x00400000
};
struct LootItemDetails { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    uint32_t mStoreId; // 0x0
    uint32_t mRarity; // 0x4
    uint32_t mValue; // 0x8
};
struct LootStatus { // 0x3C
   // ctor: 0x006B8C40
   // init: 0x006B8980
    vector_t<string_t> mTags; // 0x0
    string_t mImageTexturePath; // 0xC
    string_t mActiveDate; // 0x18
    string_t mInactiveDate; // 0x24
    int32_t mLifetimeMax; // 0x30
    bool mAutoRedeem; // 0x34
    bool mActive; // 0x35
};
struct LootItem: LootOutputBase { // 0x7C
   // ctor: 0x006B8AE0
   // init: 0x006B89C0
    string_t mInternalName; // 0x4
    string_t mName; // 0x10
    string_t mHoverDescription; // 0x1C
    string_t mAdminDescription; // 0x28
    LootStatus mStatus; // 0x34
    LootItemDetails mDetails; // 0x70
};
struct ClientStateCommonSettings { // 0x10
   // ctor: 0x006B8C10
   // init: 0x006B89D0
    uint32_t m_0x5B40F8FD; // 0x4
    uint32_t m_0x6A9D87E7; // 0x8
    uint32_t m_0xEFE9214C; // 0xC
};
struct IdentityInstance: PropertyBase { // 0x2C
   // ctor: 0x006E85A0
   // init: 0x006E8070
    string_t mItemTexturePath; // 0x1C
};
struct t_0x4D31ED46: PropertyBase { // 0x50
   // ctor: 0x006E8290
   // init: 0x006E8300
    IdentityInstance mIdentityInstance; // 0x4
    CatalogEntry mCatalogEntry; // 0x30
};
struct t_0x14AEF50C: PropertyBase { // 0x2C
   // ctor: 0x006E8490
   // init: 0x006E8230
    string_t mInventoryType; // 0x4
    uint8_t mOrder; // 0x10
    vector_t<int32_t> mItemIds; // 0x14
    vector_t<t_0x14AEF50C> mInventoryFilters; // 0x20
};
struct t_0x9F59E92D: PropertyBase { // 0x20
   // ctor: 0x006E8390
   // init: 0x006E86C0
    string_t mName; // 0x4
    uint8_t mOrder; // 0x10
    bool mEnabled; // 0x11
    vector_t<t_0x14AEF50C> mInventoryFilters; // 0x14
};
struct Map: WadFileDescriptor { // 0x4C
   // ctor: 0x006E8160
   // init: 0x006E82B0
    string_t MapStringId; // 0x4
    link_ptr_t<Map> BasedOnMap; // 0x10
    vector_t<link_ptr_t<MapCharacterList>> CharacterLists; // 0x14
    uint8_t m_0x6744E6E3; // 0x20
    MapVisibilityFlagDefinitions m_0x9E019715; // 0x24
    MapNavigationGridOverlays NavigationGridOverlays; // 0x40
};
struct MapAction: PropertyBase { // 0x10
   // ctor: 0x00400000
   // init: 0x00400000
    float_t StartTime; // 0x4
};
struct t_0xAF23408C: MapAction { // 0x44
   // ctor: 0x006E81B0
   // init: 0x006E8280
    vector_t<string_t> m_0x5C042946; // 0x24
    string_t m_0x15DB0D85; // 0x30
    float_t m_0x29A7EFC6; // 0x3C
    bool Shuffle; // 0x40
};
struct t_0x8C0D80F5: MapAction { // 0x34
   // ctor: 0x006E8780
   // init: 0x006E85B0
    vector_t<string_t> MapParticleName; // 0x24
    bool Shuffle; // 0x30
};
struct t_0x6CDBB71D: MapAction { // 0x44
   // ctor: 0x006E8190
   // init: 0x006E8540
    string_t TargetName; // 0x10
    string_t Pathname; // 0x1C
    float_t Duration; // 0x28
    float_t Velocity; // 0x2C
    bool m_0x3ADE3A5D; // 0x30
    bool m_0xEEFB990F; // 0x31
};
struct MapActionPlayAnimation: MapAction { // 0x30
   // ctor: 0x006E8730
   // init: 0x006E8630
    string_t PropName; // 0x10
    string_t AnimationName; // 0x1C
    bool Looping; // 0x28
};
struct MapActionPlaySoundAtLocation: MapAction { // 0x28
   // ctor: 0x006E8180
   // init: 0x006E8110
    string_t SoundEventName; // 0x10
    string_t LocationName; // 0x1C
};
struct t_0x49DA656E: MapAction { // 0x2C
   // ctor: 0x006E8750
   // init: 0x006E81D0
    string_t PropName; // 0x10
    string_t Key; // 0x1C
    float_t Value; // 0x28
};
struct t_0xCED6AB09: MapAction { // 0x20
   // ctor: 0x006E83F0
   // init: 0x006E8550
    vector_t<string_t> MapParticleName; // 0x10
    bool Shown; // 0x1C
};
struct t_0xE1BB8EFB: MapAction { // 0x10
   // ctor: 0x006E8690
   // init: 0x006E87A0
};
struct MapAlternateAsset { // 0x40
   // ctor: 0x006E8030
   // init: 0x006E8440
    string_t mGrassTintTextureName; // 0x0
    string_t m_0x603134B8; // 0xC
    string_t m_0x198716D9; // 0x18
    link_ptr_t<ResourceResolver> mParticleResourceResolver; // 0x24
    hash_t m_0x97472C4D; // 0x28
};
struct MapAlternateAssets { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    vector_t<MapAlternateAsset> mAlternateAssets; // 0x0
};
struct MapBehavior: GenericMapPlaceable { // 0x94
   // ctor: 0x006E8870
   // init: 0x006E8310
    string_t Cue; // 0x58
    vector_t<unique_ptr_t<MapAction>> Actions; // 0x64
    float_t m_0x077F9E08; // 0x78
};
struct MapCharacterList { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    vector_t<link_ptr_t<Character>> Characters; // 0x0
};
struct MapLocatorArray { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    vector_t<MapLocator> Locators; // 0x0
};
struct MapNavigationGridOverlays { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    map_t<string_t, link_ptr_t<MapNavigationGridOverlay>> Overlays; // 0x0
};
struct MapNavigationGridOverlay: PropertyBase { // 0x1C
   // ctor: 0x006E84D0
   // init: 0x006E8810
    string_t NavGridFileName; // 0x4
    string_t RegionsFilename; // 0x10
};
struct MapSkinColorizationPostEffect { // 0x10
   // ctor: 0x006E7FE0
   // init: 0x006E8050
    point3D_t mMultipliersRgb; // 0x0
    float_t mMultipliersSaturation; // 0xC
};
struct MapSkin { // 0xD0
   // ctor: 0x006E80D0
   // init: 0x006E8590
    string_t mMapContainerLink; // 0x0
    MinimapBackgroundConfig mMinimapBackgroundConfig; // 0xC
    MapAlternateAssets mAlternateAssets; // 0x3C
    string_t mMapObjectsCfg; // 0x48
    string_t mNavigationMesh; // 0x54
    link_ptr_t<GameModeConstants> m_0x14F54BBD; // 0x68
    string_t mWorldParticlesIni; // 0x6C
    unique_ptr_t<MapSkinColorizationPostEffect> mColorizationPostEffect; // 0x78
    string_t mGrassTintTexture; // 0x7C
    string_t m_0xB0E90E8E; // 0x88
    unordered_map_t<hash_t, int32_t> mObjectSkinFallbacks; // 0x94
    vector_t<link_ptr_t<ResourceResolver>> mResourceResolvers; // 0xB4
};
struct MapVisibilityFlagRange: PropertyBase { // 0x8
   // ctor: 0x006E7F40
   // init: 0x006E8010
    uint8_t MinIndex; // 0x4
    uint8_t MaxIndex; // 0x5
};
struct MapVisibilityFlagDefinition: PropertyBase { // 0x1C
   // ctor: 0x006E87C0
   // init: 0x006E8450
    hash_t Name; // 0x4
    string_t PublicName; // 0x8
    uint8_t BitIndex; // 0x14
    float_t TransitionTime; // 0x18
};
struct MapVisibilityFlagDefinitions: PropertyBase { // 0x1C
   // ctor: 0x006E7F60
   // init: 0x006E7FA0
    vector_t<MapVisibilityFlagDefinition> FlagDefinitions; // 0x4
    MapVisibilityFlagRange FlagRange; // 0x10
    bool m_0x822356E3; // 0x18
    bool m_0x5FFC00DF; // 0x19
};
struct MinimapBackground { // 0x20
   // ctor: 0x00507EB0
   // init: 0x00507B10
    string_t mTextureName; // 0x0
    point2D_t mOrigin; // 0xC
    point2D_t mSize; // 0x14
};
struct MinimapBackgroundConfig { // 0x30
   // ctor: 0x006E8890
   // init: 0x006E8520
    string_t mDefaultTextureName; // 0x4
    unordered_map_t<hash_t, MinimapBackground> mCustomMinimapBackgrounds; // 0x10
};
struct MissionAsset { // 0x20
   // ctor: 0x00711670
   // init: 0x00711A40
    string_t mInternalName; // 0x0
    string_t mIconTexturePath; // 0xC
    bool m_0xF82EFEC6; // 0x18
};
struct CheatPage { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    vector_t<link_ptr_t<Cheat>> mCheats; // 0x0
};
struct CheatSet { // 0x3C
   // ctor: 0x00711A20
   // init: 0x00711730
    string_t mName; // 0x0
    string_t mGameMutator; // 0xC
    hash_t mGameModeName; // 0x18
    link_ptr_t<Champion> mAssociatedChampion; // 0x1C
    vector_t<CheatPage> mCheatPages; // 0x2C
    bool mIsPlayerFacing; // 0x38
    bool mUseIconsForButtons; // 0x39
    bool mIsUiAlwaysShown; // 0x3A
};
struct CheatMenuUiData { // 0x4C
   // ctor: 0x00711740
   // init: 0x00711530
    string_t mDisplayName; // 0x0
    string_t mFloatingTextDisplayName; // 0xC
    string_t mTooltipText; // 0x18
    string_t mDynamicTooltipText; // 0x24
    string_t mHotkey; // 0x30
    vector_t<string_t> mHotkeys; // 0x3C
    bool mIsToggleCheat; // 0x48
};
struct Cheat: PropertyBase { // 0x40
   // ctor: 0x00711890
   // init: 0x007118B0
    float_t mRecastFrequency; // 0xC
    string_t mName; // 0x14
    unique_ptr_t<CheatMenuUiData> mCheatMenuUiData; // 0x20
    bool mIsPlayerFacing; // 0x24
};
struct ScriptCheat: Cheat { // 0x48
   // ctor: 0x00711BE0
   // init: 0x00711A80
    uint32_t mTarget; // 0x40
    hash_t mScriptCallback; // 0x44
};
struct AddGoldCheat: Cheat { // 0x48
   // ctor: 0x00711E30
   // init: 0x00711950
    uint32_t mTarget; // 0x40
    float_t mGoldAmount; // 0x44
};
struct MaxAllSkillsCheat: Cheat { // 0x48
   // ctor: 0x00711DF0
   // init: 0x00711E70
    uint32_t mTarget; // 0x40
    bool mOnlyOnePointEach; // 0x44
};
struct AddExperienceCheat: Cheat { // 0x48
   // ctor: 0x00711540
   // init: 0x00711420
    uint32_t mTarget; // 0x40
    bool mGiveMaxLevel; // 0x44
};
struct ToggleBuffCheat: Cheat { // 0x54
   // ctor: 0x00711C90
   // init: 0x007118F0
    uint32_t mTarget; // 0x40
    string_t mBuffName; // 0x44
    bool UseTargetAsCaster; // 0x50
};
struct AddHealthCheat: Cheat { // 0x48
   // ctor: 0x00711F30
   // init: 0x00711EC0
    uint32_t mTarget; // 0x40
    float_t mAmount; // 0x44
};
struct AddParCheat: Cheat { // 0x48
   // ctor: 0x00711BA0
   // init: 0x00711580
    uint32_t mTarget; // 0x40
    float_t mAmount; // 0x44
};
struct ToggleRegenCheat: Cheat { // 0x48
   // ctor: 0x00711630
   // init: 0x00711470
    uint32_t mTarget; // 0x40
    bool mToggleHp; // 0x44
    bool mTogglePar; // 0x45
};
struct ClearTargetCooldownCheat: Cheat { // 0x44
   // ctor: 0x00711F70
   // init: 0x00711770
    uint32_t mTarget; // 0x40
};
struct TimeMultiplierCheat: Cheat { // 0x44
   // ctor: 0x00711C20
   // init: 0x00711AE0
    bool mSpeedUp; // 0x40
    bool mSpeedDown; // 0x41
};
struct DamageUnitCheat: Cheat { // 0x5C
   // ctor: 0x00711930
   // init: 0x007115E0
    uint32_t mTarget; // 0x40
    uint32_t mDamageAmount; // 0x4C
    float_t mPercentageOfAttack; // 0x50
    uint32_t mDamageType; // 0x54
    uint32_t mHitResult; // 0x58
};
struct ToggleBarracksCheat: Cheat { // 0x44
   // ctor: 0x007114C0
   // init: 0x00711500
    bool mKillExistingMinions; // 0x40
    bool mKillWards; // 0x41
};
struct ToggleTeamCheat: Cheat { // 0x44
   // ctor: 0x00711D30
   // init: 0x007118C0
    uint32_t mTarget; // 0x40
};
struct SetRespawnTimerCheat: Cheat { // 0x48
   // ctor: 0x00711EF0
   // init: 0x00711D90
    uint32_t mTarget; // 0x40
    float_t mTimerValue; // 0x44
};
struct ToggleInvulnerableCheat: Cheat { // 0x44
   // ctor: 0x007117E0
   // init: 0x00712000
    uint32_t mTarget; // 0x40
};
struct KillAllTurretsCheat: Cheat { // 0x40
   // ctor: 0x00711860
   // init: 0x00711450
};
struct ForceSpawnNeutralCampsCheat: Cheat { // 0x44
   // ctor: 0x007116C0
   // init: 0x007115C0
    bool mSpawnBaron; // 0x40
};
struct ResetGoldCheat: Cheat { // 0x44
   // ctor: 0x007117A0
   // init: 0x00712030
    uint32_t mTarget; // 0x40
};
struct TogglePlantFastRespawnCheat: Cheat { // 0x40
   // ctor: 0x00711AB0
   // init: 0x00711B40
};
struct SwapChampionCheat: Cheat { // 0x44
   // ctor: 0x00711B60
   // init: 0x00711C60
};
struct ToggleAfkDetectionCheat: Cheat { // 0x40
   // ctor: 0x00711DC0
   // init: 0x00711D70
};
struct PerkEffectAmountPerMode { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    map_t<hash_t, float_t> mEffectAmountPerMode; // 0x0
};
struct PerkScriptData { // 0x28
   // ctor: 0x00711760
   // init: 0x007119D0
    map_t<hash_t, float_t> mEffectAmount; // 0x4
    map_t<hash_t, PerkEffectAmountPerMode> mEffectAmountGameMode; // 0x10
    map_t<hash_t, unique_ptr_t<IGameCalculation>> mCalculations; // 0x1C
};
struct PerkScript { // 0x40
   // ctor: 0x007114A0
   // init: 0x00711EA0
    string_t mSpellScriptName; // 0x0
    unique_ptr_t<LolSpellScript> mSpellScript; // 0xC
    PerkScriptData mSpellScriptData; // 0x10
};
struct PerkBuff { // 0x28
   // ctor: 0x00711820
   // init: 0x007119A0
    string_t mBuffScriptName; // 0x0
    SpellObject mBuffSpellObject; // 0xC
};
struct BasePerk: PropertyBase { // 0xA0
   // ctor: 0x00400000
   // init: 0x00400000
    uint32_t mPerkId; // 0x4
    string_t mPerkName; // 0x8
    string_t mDisplayNameLocalizationKey; // 0x14
    string_t mTooltipNameLocalizationKey; // 0x20
    string_t mPingTextLocalizationKey; // 0x2C
    string_t mShortDescLocalizationKey; // 0x38
    string_t mLongDescLocalizationKey; // 0x44
    vector_t<string_t> mEndOfGameStatDescriptions; // 0x50
    string_t mDisplayStatLocalizationKey; // 0x5C
    string_t mIconTextureName; // 0x68
    bool mEnabled; // 0x74
    bool mStackable; // 0x75
    unique_ptr_t<PerkScript> mScript; // 0x78
    vector_t<unique_ptr_t<PerkBuff>> mBuffs; // 0x7C
    unique_ptr_t<ResourceResolver> mVfxResourceResolver; // 0x88
    vector_t<string_t> mCharacters; // 0x8C
};
struct PerkStyle { // 0xC8
   // ctor: 0x0073BAE0
   // init: 0x0073B990
    uint32_t mPerkStyleId; // 0x0
    string_t mPerkStyleName; // 0x4
    string_t mDisplayNameLocalizationKey; // 0x10
    string_t mTooltipNameLocalizationKey; // 0x1C
    string_t mIconTextureName; // 0x28
    string_t mDefaultPageLocalizationKey; // 0x34
    string_t mPingTextLocalizationKey; // 0x40
    bool mEnabled; // 0x4C
    bool mIsAdvancedStyle; // 0x4D
    vector_t<uint32_t> mAllowedSubStyles; // 0x50
    vector_t<PerkSubStyleBonus> mSubStyleBonus; // 0x5C
    vector_t<PerkSlot> mSlots; // 0x68
    vector_t<link_ptr_t<PerkSlot>> mSlotlinks; // 0x74
    unique_ptr_t<PerkScript> mScript; // 0x80
    unique_ptr_t<PerkScript> mScriptAsSubStyle; // 0x84
    vector_t<unique_ptr_t<PerkBuff>> mBuffs; // 0x88
    unique_ptr_t<DefaultSplashedPerkStyle> mDefaultSplash; // 0x94
    vector_t<link_ptr_t<Perk>> mDefaultPerksWhenSplashed; // 0x98
    vector_t<DefaultStatModPerkSet> m_0x0FA4E9A2; // 0xA4
    unique_ptr_t<ResourceResolver> mStyleVfxResourceResolver; // 0xB4
    map_t<string_t, string_t> mLcuAssetFileMap; // 0xB8
};
struct PerkSlot { // 0x1C
   // ctor: 0x0073BBA0
   // init: 0x0073BB60
    string_t mSlotLabelKey; // 0x0
    uint32_t mType; // 0xC
    vector_t<link_ptr_t<Perk>> mPerks; // 0x10
};
struct DefaultSplashedPerkStyle { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    link_ptr_t<PerkStyle> mStyle; // 0x0
    link_ptr_t<Perk> mPerk1; // 0x4
    link_ptr_t<Perk> mPerk2; // 0x8
};
struct DefaultStatModPerkSet { // 0x10
   // ctor: 0x005CA800
   // init: 0x005CA650
    uint32_t mStyleId; // 0x0
    vector_t<link_ptr_t<Perk>> mPerks; // 0x4
};
struct PerkSubStyleBonus { // 0x8
   // ctor: 0x00522060
   // init: 0x00521FF0
    uint32_t mStyleId; // 0x0
    link_ptr_t<Perk> mPerk; // 0x4
};
struct SummonerSpellPerkReplacement { // 0x18
   // ctor: 0x0073B880
   // init: 0x0073BA80
    hash_t mSummonerSpellRequired; // 0x0
    hash_t m_0xD48A5EF1; // 0xC
};
struct SummonerSpellPerkReplacementList { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    vector_t<unique_ptr_t<SummonerSpellPerkReplacement>> mReplacements; // 0x0
};
struct Perk: BasePerk { // 0xBC
   // ctor: 0x0073BA20
   // init: 0x0073BB20
    SummonerSpellPerkReplacementList mSummonerPerkReplacements; // 0xA0
    string_t mMajorChangePatchVersion; // 0xAC
    bool mDefault; // 0xB8
};
struct PerkReplacement { // 0x18
   // ctor: 0x0073B880
   // init: 0x0073BA80
    hash_t mReplaceTarget; // 0x0
    hash_t mReplaceWith; // 0xC
};
struct PerkReplacementList { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    vector_t<unique_ptr_t<PerkReplacement>> mReplacements; // 0x0
};
struct PerkConfig { // 0x14
   // ctor: 0x0073B920
   // init: 0x0073B8F0
    link_ptr_t<OverridePerkSelectionSet> mBotOverrideSet; // 0x0
    PerkReplacementList mPerkReplacements; // 0x4
    uint32_t m_0x108E746D; // 0x10
};
struct OverridePerkSelectionSet { // 0x14
   // ctor: 0x0073B920
   // init: 0x0073B8F0
    link_ptr_t<PerkStyle> mStyle; // 0x0
    link_ptr_t<PerkStyle> mSubStyle; // 0x4
    vector_t<link_ptr_t<Perk>> mPerks; // 0x8
};
struct ToonInkingFilterParams { // 0x10
   // ctor: 0x005CA800
   // init: 0x005CA650
    float_t mPixelSize; // 0x0
    float_t mMinVal; // 0x4
    float_t mMaxVal; // 0x8
    float_t mResultScale; // 0xC
};
struct RenderStyleData { // 0x24
   // ctor: 0x0075D1F0
   // init: 0x0075D240
    ToonInkingFilterParams mUnitFilterParamsInterior; // 0x0
    ToonInkingFilterParams mUnitFilterParamsExterior; // 0x10
    bool mUnitStyleUseInking; // 0x20
};
struct MaterialOverrideCallbackDynamicMaterial: PropertyBase { // 0x1C
   // ctor: 0x0075D420
   // init: 0x0075D330
};
struct MouseOverEffectData { // 0x6C
   // ctor: 0x0075CEE0
   // init: 0x0075D0B0
    color_t mAllyColor; // 0x0
    color_t mEnemyColor; // 0x4
    color_t mNeutralColor; // 0x8
    color_t mSelfColor; // 0xC
    array_t<float_t, 4> mInteractionTimes; // 0x10
    array_t<int32_t, 4> mInteractionSizes; // 0x20
    int32_t mMouseOverSize; // 0x34
    float_t mMouseOverColorFactor; // 0x38
    uint32_t mMouseOverBlurPassCount; // 0x3C
    int32_t mSelectedSize; // 0x44
    float_t mSelectedColorFactor; // 0x48
    uint32_t mSelectedBlurPassCount; // 0x4C
    int32_t mAvatarSize; // 0x50
    float_t mAvatarColorFactor; // 0x54
    color_t mAvatarColor; // 0x58
    uint32_t mAvatarBlurPassCount; // 0x5C
    int32_t mKillerSize; // 0x60
    float_t mKillerColorFactor; // 0x64
    uint32_t mKillerBlurPassCount; // 0x68
};
struct FxSequence: PropertyBase { // 0x34
   // ctor: 0x0075CFE0
   // init: 0x0075CF80
    vector_t<unique_ptr_t<IFxAction>> Actions; // 0x4
};
struct FxTableEntry: PropertyBase { // 0xC
   // ctor: 0x0075D160
   // init: 0x0075D3A0
    link_ptr_t<t_0x245BA20B> Type; // 0x4
    link_ptr_t<FxSequence> Sequence; // 0x8
};
struct FxTable: PropertyBase { // 0x10
   // ctor: 0x0075D130
   // init: 0x0075D110
    vector_t<FxTableEntry> Entries; // 0x4
};
struct FxTarget: PropertyBase { // 0xC
   // ctor: 0x0075CEB0
   // init: 0x0075CF00
    uint32_t Type; // 0x4
    int32_t Index; // 0x8
};
struct FxTiming: PropertyBase { // 0x18
   // ctor: 0x0075CE30
   // init: 0x0075D3C0
    uint32_t Anchor; // 0x4
    uint32_t Type; // 0x8
    float_t Offset; // 0xC
};
struct FxTransform: PropertyBase { // 0x18
   // ctor: 0x0075D2B0
   // init: 0x0075D080
    uint32_t Type; // 0x4
    int32_t Index; // 0x8
    string_t AttachmentName; // 0xC
};
struct t_0x245BA20B: PropertyBase { // 0x14
   // ctor: 0x0075CE70
   // init: 0x0075D300
    string_t Name; // 0x4
    hash_t m_0xCEC577D1; // 0x10
};
struct FxActionAnimate: IFxAction { // 0x54
   // ctor: 0x0075D000
   // init: 0x0075D010
    string_t AnimName; // 0x38
    FxTarget TargetObject; // 0x44
    bool Loop; // 0x50
    bool m_0xEE7CD89A; // 0x51
    bool PauseOnEnd; // 0x52
};
struct t_0x55D03617: IFxAction { // 0x50
   // ctor: 0x0075D190
   // init: 0x0075CFA0
    FxTransform Position; // 0x38
};
struct t_0xDA3AB4C4: IFxAction { // 0x50
   // ctor: 0x0075D0C0
   // init: 0x0075CF40
    float_t Magnitude; // 0x38
    float_t m_0xC4AFD6F9; // 0x3C
    float_t FalloffRate; // 0x40
    point3D_t Direction; // 0x44
};
struct t_0xD082B191: IFxAction { // 0x6C
   // ctor: 0x0075D480
   // init: 0x0075D2F0
    FxTransform Position; // 0x38
    float_t Fov; // 0x50
    float_t Yaw; // 0x54
    float_t Pitch; // 0x58
    float_t m_0x5A439BA5; // 0x5C
    float_t ZoomInTime; // 0x60
    float_t ZoomOutTime; // 0x64
    uint8_t ZoomInEase; // 0x68
    uint8_t ZoomOutEase; // 0x69
};
struct t_0xA05A9472: IFxAction { // 0x64
   // ctor: 0x0075D380
   // init: 0x0075CF90
    FxTransform Position; // 0x38
    float_t Fov; // 0x50
    float_t Yaw; // 0x54
    float_t Pitch; // 0x58
    float_t m_0x5A439BA5; // 0x5C
    bool Follow; // 0x60
    uint8_t ZoomEase; // 0x61
};
struct t_0x099CCE3C: IFxAction { // 0x3C
   // ctor: 0x0075D280
   // init: 0x0075D060
    uint8_t ZoomEase; // 0x38
};
struct FxActionContinue: IFxAction { // 0x38
   // ctor: 0x007818F0
   // init: 0x00781580
};
struct FxActionMove: IFxAction { // 0x80
   // ctor: 0x00781540
   // init: 0x00781720
    FxTarget TargetObject; // 0x38
    FxTransform Destination; // 0x44
    uint8_t EasingType; // 0x5C
    float_t OvershootDistance; // 0x60
    bool FaceVelocity; // 0x64
    bool m_0xD935FE42; // 0x65
};
struct FxActionMoveBase: IFxAction { // 0x68
   // ctor: 0x00400000
   // init: 0x00400000
    FxTarget TargetObject; // 0x38
    uint8_t EasingType; // 0x44
    float_t OvershootDistance; // 0x48
    bool FaceVelocity; // 0x4C
};
struct FxActionMoveTo: FxActionMoveBase { // 0x80
   // ctor: 0x00781840
   // init: 0x007816D0
    FxTransform Destination; // 0x68
};
struct FxActionMoveReset: FxActionMoveBase { // 0x68
   // ctor: 0x007814F0
   // init: 0x00781870
};
struct FxActionSfx: IFxAction { // 0x5C
   // ctor: 0x00781610
   // init: 0x00781630
    FxTransform Position; // 0x38
    string_t EventName; // 0x50
};
struct FxActionTimeDilate: IFxAction { // 0x50
   // ctor: 0x007817F0
   // init: 0x007818B0
    float_t TimeDilation; // 0x3C
    float_t Intime; // 0x40
    uint8_t InEase; // 0x44
    float_t OutTime; // 0x48
    uint8_t OutEase; // 0x4C
};
struct FxActionVfx: IFxAction { // 0x178
   // ctor: 0x007816E0
   // init: 0x00781700
    bool Follow; // 0x38
    FxTransform Position; // 0x3C
    FxTransform TargetPosition; // 0x54
    link_ptr_t<VfxSystemDefinitionData> Particle; // 0x6C
    float_t m_0x39D6E480; // 0x70
    bool FollowPath; // 0x7C
    FxTransform PathTargetPosition; // 0x80
    unique_ptr_t<ISplineInfo> SplineInfo; // 0x98
    float_t Scale; // 0x9C
};
struct IFxAction: PropertyBase { // 0x38
   // ctor: 0x00400000
   // init: 0x00400000
    FxTiming Start; // 0x4
    FxTiming End; // 0x1C
};
struct GameplayFeatureToggles { // 0xC
   // ctor: 0x007817C0
   // init: 0x00781730
    bool NewActorStuckPathfinding; // 0x4
    bool FowCastRayAccurate; // 0x5
    bool DisableSpellLevelMinimumProtections; // 0x6
    bool IndividualItemVisibility; // 0x7
    bool AfkDetection2; // 0x8
};
struct ScriptDataObject { // 0x40
   // ctor: 0x00781560
   // init: 0x00781600
    string_t mName; // 0x0
    unordered_map_t<string_t, unique_ptr_t<GameModeConstant>> mConstants; // 0x1C
    link_ptr_t<GameModeConstantsGroup> m_0x9BE36761; // 0x3C
};
struct ScriptDataObjectList { // 0x1C
   // ctor: 0x007815B0
   // init: 0x00781690
    string_t mName; // 0x0
    vector_t<link_ptr_t<ScriptDataObject>> mScriptDataObjects; // 0x10
};
struct ICastRequirement: PropertyBase { // 0x8
   // ctor: 0x00400000
   // init: 0x00400000
    bool mInvertResult; // 0x4
};
struct HasAllSubRequirementsCastRequirement: ICastRequirement { // 0x14
   // ctor: 0x00815B30
   // init: 0x00815AA0
    vector_t<unique_ptr_t<ICastRequirement>> mSubRequirements; // 0x8
};
struct HasNNearbyUnitsRequirement: ICastRequirement { // 0x20
   // ctor: 0x00815BA0
   // init: 0x00816510
    vector_t<unique_ptr_t<ICastRequirement>> mUnitsRequirements; // 0x8
    uint32_t mUnitsRequired; // 0x14
    float_t mRange; // 0x18
    uint32_t mDistanceType; // 0x1C
};
struct HasNNearbyVisibleUnitsRequirement: ICastRequirement { // 0x20
   // ctor: 0x00816410
   // init: 0x008166C0
    vector_t<unique_ptr_t<ICastRequirement>> mUnitsRequirements; // 0x8
    uint32_t mUnitsRequired; // 0x14
    float_t mRange; // 0x18
    uint32_t mDistanceType; // 0x1C
};
struct HasTypeAndStatusFlags: ICastRequirement { // 0x10
   // ctor: 0x00815C70
   // init: 0x00815E40
    uint32_t mAffectsTypeFlags; // 0x8
    uint32_t mAffectsStatusFlags; // 0xC
};
struct HasAtleastNSubRequirementsCastRequirement: ICastRequirement { // 0x18
   // ctor: 0x00816830
   // init: 0x008161A0
    uint32_t mSuccessesRequired; // 0x8
    vector_t<unique_ptr_t<ICastRequirement>> mSubRequirements; // 0xC
};
struct HasUnitTagsCastRequirement: ICastRequirement { // 0x20
   // ctor: 0x008165E0
   // init: 0x00816490
    ObjectTags mUnitTags; // 0x8
};
struct SameTeamCastRequirement: ICastRequirement { // 0x8
   // ctor: 0x00815D60
   // init: 0x00816020
};
struct HasBuffCastRequirement: ICastRequirement { // 0x10
   // ctor: 0x008163E0
   // init: 0x008169D0
    hash_t mBuffName; // 0x8
    bool mFromAnyone; // 0xC
};
struct AboveHealthPercentCastRequirement: ICastRequirement { // 0xC
   // ctor: 0x00816080
   // init: 0x008163C0
    float_t mCurrentPercentHealth; // 0x8
};
struct AboveParPercentCastRequirement: ICastRequirement { // 0x10
   // ctor: 0x00815950
   // init: 0x00815E00
    uint8_t mParType; // 0x8
    float_t mCurrentPercentPar; // 0xC
};
struct IsSpecifiedUnitCastRequirement: ICastRequirement { // 0x14
   // ctor: 0x00816260
   // init: 0x008157D0
    hash_t mUnit; // 0x8
};
struct t_0x10F4D0BF: ICastRequirement { // 0x8
   // ctor: 0x008161D0
   // init: 0x008158C0
};
struct t_0xDC65FFE4: ICastRequirement { // 0x8
   // ctor: 0x00816000
   // init: 0x00815E60
};
struct ItemSlotHasChargesCastRequirement: ICastRequirement { // 0x8
   // ctor: 0x00816700
   // init: 0x008165D0
};
struct t_0x2E7C5EDA: ICastRequirement { // 0xC
   // ctor: 0x00816220
   // init: 0x00816180
    uint32_t Level; // 0x8
};
struct t_0x48284759: ICastRequirement { // 0xC
   // ctor: 0x00815AD0
   // init: 0x00816300
    float_t Distance; // 0x8
};
struct CcScoreMultipliers { // 0x4C
   // ctor: 0x00815DB0
   // init: 0x00816390
    float_t Stun; // 0x0
    float_t Taunt; // 0x4
    float_t Fear; // 0x8
    float_t Flee; // 0xC
    float_t Suppression; // 0x10
    float_t Knockup; // 0x14
    float_t Knockback; // 0x18
    float_t Polymorph; // 0x1C
    float_t Root; // 0x20
    float_t Silence; // 0x24
    float_t Charm; // 0x28
    float_t Slow; // 0x2C
    float_t AttackSpeedSlow; // 0x30
    float_t Blind; // 0x34
    float_t Disarm; // 0x38
    float_t Grounded; // 0x3C
    float_t Nearsight; // 0x40
    float_t Drowsy; // 0x44
    float_t Asleep; // 0x48
};
struct BuffData { // 0x70
   // ctor: 0x008169B0
   // init: 0x00816250
    vector_t<unique_ptr_t<VfxSpawnConditions>> mVfxSpawnConditions; // 0x0
    string_t mDescription; // 0x18
    unique_ptr_t<TooltipInstanceBuff> mTooltipData; // 0x24
    bool m_0x62E282AA; // 0x28
    bool mShowDuration; // 0x29
    bool m_0x00D019C1; // 0x2A
    array_t<int32_t, 16> mFloatVarsDecimals; // 0x2C
    uint8_t mBuffAttributeFlag; // 0x6C
};
struct TeamBuffData { // 0x1C
   // ctor: 0x00816030
   // init: 0x00815CE0
    string_t mBuffName; // 0x0
    string_t mUiName; // 0xC
    bool m_0x9A53F442; // 0x18
};
struct MissionBuffData { // 0x1C0
   // ctor: 0x00816760
   // init: 0x00815D80
    TeamBuffData Dragon; // 0x0
    TeamBuffData FireDrake; // 0x1C
    TeamBuffData AirDrake; // 0x38
    TeamBuffData WaterDrake; // 0x54
    TeamBuffData EarthDrake; // 0x70
    TeamBuffData ElderDrake; // 0x8C
    TeamBuffData GameModeCustom1; // 0xA8
    TeamBuffData GameModeCustom2; // 0xC4
    TeamBuffData m_0x8DEA39F8; // 0xE0
    TeamBuffData m_0x94EA44FD; // 0xFC
    TeamBuffData m_0x93EA436A; // 0x118
    TeamBuffData m_0x92EA41D7; // 0x134
    TeamBuffData m_0x91EA4044; // 0x150
    TeamBuffData m_0x88EA3219; // 0x16C
    TeamBuffData m_0x87EA3086; // 0x188
    TeamBuffData m_0xBBBE4F6A; // 0x1A4
};
struct BuffStackingTemplate { // 0x1C
   // ctor: 0x00815E70
   // init: 0x00816140
    string_t Name; // 0x0
    int32_t MaxStacks; // 0xC
    int32_t m_0xB36EAE8C; // 0x10
    bool StacksExclusive; // 0x14
    uint32_t BuffAddType; // 0x18
};
struct BuffStackingSettings { // 0x10
   // ctor: 0x00815B00
   // init: 0x008157F0
    vector_t<BuffStackingTemplate> TemplateDefinition; // 0x4
};
struct VfxSpawnConditionData: PropertyBase { // 0x10
   // ctor: 0x00400000
   // init: 0x00400000
    vector_t<EffectCreationData> mPersistentVfxs; // 0x4
};
struct VfxDefaultSpawnConditionData: VfxSpawnConditionData { // 0x10
   // ctor: 0x00815F10
   // init: 0x00815D40
};
struct HasBuffData { // 0x10
   // ctor: 0x00816780
   // init: 0x008168C0
    string_t mBuffName; // 0x0
    bool mFromAnyone; // 0xC
    bool mFromOwner; // 0xD
    bool mFromAttacker; // 0xE
};
struct HasBuffComparisonData { // 0x10
   // ctor: 0x00815920
   // init: 0x00815810
    vector_t<HasBuffData> mBuffs; // 0x0
    uint8_t mCompareOp; // 0xC
};
struct HasBuffSpawnConditionData: VfxSpawnConditionData { // 0x20
   // ctor: 0x00815A50
   // init: 0x00816320
    HasBuffComparisonData mBuffComparisons; // 0x10
};
struct IsSkinSpawnConditionData: VfxSpawnConditionData { // 0x14
   // ctor: 0x00815C30
   // init: 0x008161F0
    uint32_t mSkinId; // 0x10
};
struct IsOwnerHeroConditionData: VfxSpawnConditionData { // 0x10
   // ctor: 0x00815F40
   // init: 0x00815980
};
struct IsOwnerAliveConditionData: VfxSpawnConditionData { // 0x10
   // ctor: 0x00816360
   // init: 0x00816680
};
struct HasSpellRankSpawnConditionData: VfxSpawnConditionData { // 0x18
   // ctor: 0x008160B0
   // init: 0x00815DD0
    uint32_t mSpellSlot; // 0x10
    int32_t mSpellLevel; // 0x14
};
struct VfxSpawnConditions: PropertyBase { // 0x20
   // ctor: 0x00815EC0
   // init: 0x00815830
    VfxDefaultSpawnConditionData mDefaultVfxData; // 0x4
    vector_t<unique_ptr_t<VfxSpawnConditionData>> mConditionalVfxData; // 0x14
};
struct IVfxSpawnConditions: PropertyBase { // 0x14
   // ctor: 0x00400000
   // init: 0x00400000
};
struct AlwaysSpawnCondition: IVfxSpawnConditions { // 0x14
   // ctor: 0x008162C0
   // init: 0x008167C0
    VfxDefaultSpawnConditionData mDefaultVfxData; // 0x4
};
struct HasBuffNameSpawnConditions: IVfxSpawnConditions { // 0x20
   // ctor: 0x008158D0
   // init: 0x008168F0
    VfxDefaultSpawnConditionData mDefaultVfxData; // 0x4
    vector_t<HasBuffSpawnConditionData> mConditions; // 0x14
};
struct HasSkinIdSpawnConditions: IVfxSpawnConditions { // 0x20
   // ctor: 0x00816930
   // init: 0x00815CA0
    VfxDefaultSpawnConditionData mDefaultVfxData; // 0x4
    vector_t<IsSkinSpawnConditionData> mConditions; // 0x14
};
struct IsOwnerHeroSpawnConditions: IVfxSpawnConditions { // 0x20
   // ctor: 0x008160F0
   // init: 0x00815BF0
    VfxDefaultSpawnConditionData mDefaultVfxData; // 0x4
    vector_t<IsOwnerHeroConditionData> mConditions; // 0x14
};
struct IsOwnerAliveSpawnConditions: IVfxSpawnConditions { // 0x20
   // ctor: 0x00815FB0
   // init: 0x00816720
    VfxDefaultSpawnConditionData mDefaultVfxData; // 0x4
    vector_t<IsOwnerAliveConditionData> mConditions; // 0x14
};
struct EffectCreationData { // 0x48
   // ctor: 0x00816460
   // init: 0x00816480
    string_t mBoneName; // 0x0
    string_t mTargetBoneName; // 0xC
    hash_t mEffectKey; // 0x18
    string_t mEffectName; // 0x1C
    hash_t m_0xA03A9542; // 0x28
    string_t m_0xFE758550; // 0x2C
    float_t mPlaySpeedModifier; // 0x38
    uint32_t m_0x87596A93; // 0x3C
    bool m_0xC42CF88D; // 0x41
    bool m_0xA45EDA7B; // 0x42
    bool mFaceTarget; // 0x43
    bool m_0xFD1E1BB4; // 0x44
    bool m_0x453384E6; // 0x45
    bool m_0x62F57C79; // 0x46
};
struct RatioConversion { // 0x8
   // ctor: 0x00815E20
   // init: 0x008159A0
    uint8_t mSourceStatType; // 0x0
    uint8_t mSourceStatOutput; // 0x1
    uint8_t mResultingStatType; // 0x2
    uint8_t mResultingStatOutput; // 0x3
    float_t m_0x9227CE44; // 0x4
};
struct t_0x4379A5B2 { // 0x10
   // ctor: 0x00816980
   // init: 0x008169F0
    uint8_t m_0x5C92B7F2; // 0x0
    uint8_t m_0xACA5B9B4; // 0x1
    vector_t<unique_ptr_t<IGameCalculationPart>> m_0x583DA425; // 0x4
};
struct SpellModifier { // 0x24
   // ctor: 0x00816550
   // init: 0x00816870
    hash_t mModifierId; // 0x0
    uint8_t m_0xA9CC2BF6; // 0x4
    uint8_t m_0xA47F56D7; // 0x5
    uint32_t m_0x5B1192F5; // 0x8
    vector_t<RatioConversion> m_0x441A3020; // 0xC
    vector_t<t_0x4379A5B2> m_0xDDBEA054; // 0x18
};
struct AbilityObject { // 0x24
   // ctor: 0x008B3920
   // init: 0x008B3810
    link_ptr_t<SpellObject> mRootSpell; // 0x0
    vector_t<link_ptr_t<SpellObject>> mChildSpells; // 0x4
    bool m_0x86DDADDB; // 0x10
    string_t mName; // 0x14
    uint8_t mType; // 0x20
};
struct SpellObject { // 0x1C
   // ctor: 0x007815B0
   // init: 0x00781690
    string_t mScriptName; // 0x0
    unique_ptr_t<SpellDataResource> mSpell; // 0x10
    unique_ptr_t<BuffData> mBuff; // 0x14
    unique_ptr_t<LolSpellScript> mScript; // 0x18
};
struct MissileSpecification: PropertyBase { // 0x30
   // ctor: 0x008B3D30
   // init: 0x008B3A70
    float_t mMissileWidth; // 0x4
    unique_ptr_t<MissileMovementSpec> MovementComponent; // 0x8
    unique_ptr_t<MissileVisibilitySpec> VisibilityComponent; // 0xC
    unique_ptr_t<HeightSolverType> HeightSolver; // 0x10
    unique_ptr_t<VerticalFacingType> VerticalFacing; // 0x14
    vector_t<MissileGroupSpawnerSpec> MissileGroupSpawners; // 0x18
    vector_t<unique_ptr_t<MissileBehaviorSpec>> Behaviors; // 0x24
};
struct MissileBehaviorSpec: PropertyBase { // 0x4
   // ctor: 0x00400000
   // init: 0x00400000
};
struct FixedDistanceIgnoringTerrain: MissileBehaviorSpec { // 0x18
   // ctor: 0x008B4030
   // init: 0x008B3FE0
    float_t mMaximumDistance; // 0x4
    float_t mMinimumGapBetweenTerrainWalls; // 0x8
    optional_t<uint32_t> mMaximumTerrainWallsToSkip; // 0xC
    optional_t<float_t> ScanWidthOverride; // 0x10
    unique_ptr_t<TargeterDefinitionSkipTerrain> mTargeterDefinition; // 0x14
};
struct ScaleByScaleSkinCoef: MissileBehaviorSpec { // 0x4
   // ctor: 0x008B4680
   // init: 0x008B3E40
};
struct WidthPerSecond: MissileBehaviorSpec { // 0x8
   // ctor: 0x008B3F20
   // init: 0x008B48B0
    float_t mWidthPerSecond; // 0x4
};
struct MissileTriggerSpec: MissileBehaviorSpec { // 0x10
   // ctor: 0x00400000
   // init: 0x00400000
    vector_t<unique_ptr_t<MissileTriggeredActionSpec>> mActions; // 0x4
};
struct TriggerOnMovementComplete: MissileTriggerSpec { // 0x14
   // ctor: 0x008B47D0
   // init: 0x008B3C60
    int32_t mDelay; // 0x10
};
struct TriggerOnDelay: MissileTriggerSpec { // 0x14
   // ctor: 0x008B4230
   // init: 0x008B4390
    float_t mDelay; // 0x10
};
struct DelayStart: MissileBehaviorSpec { // 0x8
   // ctor: 0x008B4720
   // init: 0x008B3D60
    float_t mDelayTime; // 0x4
};
struct t_0x0798277F: MissileBehaviorSpec { // 0x10
   // ctor: 0x008B3A40
   // init: 0x008B42E0
    float_t m_0x5E19CDE2; // 0x4
    uint32_t m_0x6BFAE91C; // 0x8
    uint32_t m_0x754A85A6; // 0xC
};
struct TriggerOnStart: MissileTriggerSpec { // 0x10
   // ctor: 0x008B4810
   // init: 0x008B4140
};
struct TriggerOnHit: MissileTriggerSpec { // 0x10
   // ctor: 0x008B3EB0
   // init: 0x008B44A0
};
struct TriggerOnDistanceFromCaster: MissileTriggerSpec { // 0x14
   // ctor: 0x008B48D0
   // init: 0x008B3CB0
    float_t mDistance; // 0x10
};
struct TriggerFromScript: MissileTriggerSpec { // 0x20
   // ctor: 0x008B3AB0
   // init: 0x008B3D80
    string_t mTriggerName; // 0x10
    float_t mDelay; // 0x1C
};
struct MissileTriggeredActionSpec: PropertyBase { // 0x4
   // ctor: 0x00400000
   // init: 0x00400000
};
struct Cast: MissileTriggeredActionSpec { // 0x4
   // ctor: 0x008B3F40
   // init: 0x008B47B0
};
struct Destroy: MissileTriggeredActionSpec { // 0x4
   // ctor: 0x008B40F0
   // init: 0x008B42D0
};
struct ReturnToCaster: MissileTriggeredActionSpec { // 0xC
   // ctor: 0x008B37A0
   // init: 0x008B37F0
    bool mPreserveSpeed; // 0x4
    unique_ptr_t<MissileMovementSpec> mOverrideSpec; // 0x8
};
struct ClearAlreadyHitTracking: MissileTriggeredActionSpec { // 0x4
   // ctor: 0x008B45A0
   // init: 0x008B4520
};
struct CallOnMissileBounce: MissileTriggeredActionSpec { // 0x4
   // ctor: 0x008B4480
   // init: 0x008B4770
};
struct ClearTargetAndKeepMoving: MissileTriggeredActionSpec { // 0x10
   // ctor: 0x008B4780
   // init: 0x008B3C40
    optional_t<float_t> mOverrideHeightAugment; // 0x4
    optional_t<float_t> mOverrideRange; // 0x8
    unique_ptr_t<MissileMovementSpec> mOverrideMovement; // 0xC
};
struct ChangeMissileSpeed: MissileTriggeredActionSpec { // 0xC
   // ctor: 0x008B4450
   // init: 0x008B3C90
    uint32_t mSpeedChangeType; // 0x4
    float_t mSpeedValue; // 0x8
};
struct t_0x3CD8DBCD: MissileTriggeredActionSpec { // 0xC
   // ctor: 0x008B4420
   // init: 0x008B43E0
    uint32_t m_0x37A74CE3; // 0x4
    float_t m_0x90292654; // 0x8
};
struct ChangeTurnRadius: MissileTriggeredActionSpec { // 0x20
   // ctor: 0x008B4530
   // init: 0x008B43C0
    array_t<float_t, 7> m_0x84BB076A; // 0x4
};
struct ChangeHeightSolver: MissileTriggeredActionSpec { // 0x8
   // ctor: 0x008B44C0
   // init: 0x008B3EE0
    unique_ptr_t<HeightSolverType> mOverrideHeightSolver; // 0x4
};
struct DestroyOnHit: MissileBehaviorSpec { // 0x4
   // ctor: 0x008B4740
   // init: 0x008B45F0
};
struct DestroyOnMovementComplete: MissileBehaviorSpec { // 0x8
   // ctor: 0x008B3F00
   // init: 0x008B3FC0
    int32_t mDelay; // 0x4
};
struct t_0xE357C116: MissileBehaviorSpec { // 0x4
   // ctor: 0x008B3BB0
   // init: 0x008B47C0
};
struct CastOnHit: MissileBehaviorSpec { // 0x4
   // ctor: 0x008B3F70
   // init: 0x008B3F60
};
struct CastOnMovementComplete: MissileBehaviorSpec { // 0x4
   // ctor: 0x008B4160
   // init: 0x008B4760
};
struct ReturnToCasterOnMovementComplete: MissileBehaviorSpec { // 0xC
   // ctor: 0x008B3770
   // init: 0x008B3B50
    bool mPreserveSpeed; // 0x4
    unique_ptr_t<MissileMovementSpec> mOverrideSpec; // 0x8
};
struct MissileGroupSpawnerSpec: PropertyBase { // 0x8
   // ctor: 0x008B4400
   // init: 0x008B3E50
    link_ptr_t<SpellObject> mChildMissileSpell; // 0x4
};
struct HeightSolverType: PropertyBase { // 0x4
   // ctor: 0x00400000
   // init: 0x00400000
};
struct GravityHeightSolver: HeightSolverType { // 0x8
   // ctor: 0x008B3E20
   // init: 0x008B3B00
    float_t mGravity; // 0x4
};
struct FollowTerrainHeightSolver: HeightSolverType { // 0xC
   // ctor: 0x008B4110
   // init: 0x008B4010
    float_t mHeightOffset; // 0x4
    float_t mMaxSlope; // 0x8
};
struct BlendedLinearHeightSolver: HeightSolverType { // 0x4
   // ctor: 0x008B3DC0
   // init: 0x008B4670
};
struct SinusoidalHeightSolver: HeightSolverType { // 0x10
   // ctor: 0x008B38F0
   // init: 0x008B37D0
    float_t mVerticalOffset; // 0x4
    float_t mAmplitude; // 0x8
    float_t mNumberOfPeriods; // 0xC
};
struct CurveTheDifferenceHeightSolver: HeightSolverType { // 0x8
   // ctor: 0x008B3F90
   // init: 0x008B4270
    float_t mInitialTargetHeightOffset; // 0x4
};
struct MissileMovementSpec: PropertyBase { // 0x34
   // ctor: 0x00400000
   // init: 0x00400000
    bool mUseHeightOffsetAtEnd; // 0x4
    bool mTracksTarget; // 0x5
    bool m_0xAA44F99E; // 0x6
    float_t mTargetHeightAugment; // 0x8
    float_t mOffsetInitialTargetHeight; // 0xC
    string_t mTargetBoneName; // 0x10
    float_t mStartDelay; // 0x1C
    string_t mStartBoneName; // 0x20
    map_t<uint32_t, string_t> m_0xA6CB1FA4; // 0x2C
};
struct CircleMovement: MissileMovementSpec { // 0x44
   // ctor: 0x008B3BD0
   // init: 0x008B4560
    float_t mRadialVelocity; // 0x34
    float_t mAngularVelocity; // 0x38
    float_t mLinearVelocity; // 0x3C
    float_t mLifetime; // 0x40
};
struct SyncCircleMovement: MissileMovementSpec { // 0x40
   // ctor: 0x008B46C0
   // init: 0x008B4600
    float_t mAngularVelocity; // 0x34
    float_t mLifetime; // 0x38
    uint8_t m_0x2630302A; // 0x3C
    bool m_0x16D0A895; // 0x3D
};
struct NullMovement: MissileMovementSpec { // 0x3C
   // ctor: 0x008B39C0
   // init: 0x008B4700
    bool mWaitForChildren; // 0x34
    float_t mDelayTime; // 0x38
};
struct AcceleratingMovement: MissileMovementSpec { // 0x48
   // ctor: 0x008B4330
   // init: 0x008B3E70
    bool mInferDirectionFromFacingIfNeeded; // 0x34
    bool mProjectTargetToCastRange; // 0x35
    bool mUseGroundHeightAtTarget; // 0x36
    float_t mAcceleration; // 0x38
    float_t mMinSpeed; // 0x3C
    float_t mMaxSpeed; // 0x40
    float_t mInitialSpeed; // 0x44
};
struct DecelToLocationMovement: AcceleratingMovement { // 0x48
   // ctor: 0x008B3CE0
   // init: 0x008B44E0
};
struct FixedTimeMovement: MissileMovementSpec { // 0x3C
   // ctor: 0x008B3B70
   // init: 0x008B3B20
    bool mInferDirectionFromFacingIfNeeded; // 0x34
    bool mProjectTargetToCastRange; // 0x35
    bool mUseGroundHeightAtTarget; // 0x36
    float_t mTravelTime; // 0x38
};
struct FixedSpeedMovement: MissileMovementSpec { // 0x3C
   // ctor: 0x008B4290
   // init: 0x008B4070
    bool mInferDirectionFromFacingIfNeeded; // 0x34
    bool mProjectTargetToCastRange; // 0x35
    bool mUseGroundHeightAtTarget; // 0x36
    float_t mSpeed; // 0x38
};
struct PhysicsMovement: MissileMovementSpec { // 0x4C
   // ctor: 0x008B38A0
   // init: 0x008B4630
    float_t mLifetime; // 0x38
    float_t mInitialSpeed; // 0x3C
    float_t mDrag; // 0x40
    bool mWallSliding; // 0x44
    float_t m_0xCA771747; // 0x48
};
struct TrackMouseMovement: MissileMovementSpec { // 0x68
   // ctor: 0x008B4890
   // init: 0x008B41C0
    bool mInferDirectionFromFacingIfNeeded; // 0x34
    bool mProjectTargetToCastRange; // 0x35
    bool mUseGroundHeightAtTarget; // 0x36
    float_t mAcceleration; // 0x38
    float_t mMinSpeed; // 0x3C
    float_t mMaxSpeed; // 0x40
    float_t mInitialSpeed; // 0x44
    array_t<float_t, 7> m_0x84BB076A; // 0x48
    float_t m_0x604989CF; // 0x64
};
struct GenericSplineMovementSpec: MissileMovementSpec { // 0x40
   // ctor: 0x00400000
   // init: 0x00400000
    bool mUseMissilePositionAsOrigin; // 0x34
    unique_ptr_t<ISplineInfo> mSplineInfo; // 0x38
};
struct FixedTimeSplineMovement: GenericSplineMovementSpec { // 0x44
   // ctor: 0x008B3980
   // init: 0x008B45C0
    float_t mTravelTime; // 0x40
};
struct FixedSpeedSplineMovement: GenericSplineMovementSpec { // 0x44
   // ctor: 0x008B4180
   // init: 0x008B4910
    float_t mSpeed; // 0x40
};
struct WallFollowMovement: MissileMovementSpec { // 0x50
   // ctor: 0x008B3AA0
   // init: 0x008B4840
    bool mInferDirectionFromFacingIfNeeded; // 0x34
    bool mProjectTargetToCastRange; // 0x35
    bool mUseGroundHeightAtTarget; // 0x36
    float_t mSpeed; // 0x38
    bool mCounterClockwise; // 0x3C
    float_t mWallOffset; // 0x40
    float_t mWallLength; // 0x44
    float_t mWallSearchRadius; // 0x48
    bool m_0xBCFF2EE1; // 0x4C
    bool m_0x38872364; // 0x4D
};
struct VerticalFacingType: PropertyBase { // 0x4
   // ctor: 0x00400000
   // init: 0x00400000
};
struct VeritcalFacingMatchVelocity: VerticalFacingType { // 0x4
   // ctor: 0x008B46A0
   // init: 0x008B4380
};
struct VerticalFacingFaceTarget: VerticalFacingType { // 0x4
   // ctor: 0x008B3A80
   // init: 0x008B4220
};
struct MissileVisibilitySpec: PropertyBase { // 0x10
   // ctor: 0x00400000
   // init: 0x00400000
    bool mTargetControlsVisibility; // 0x4
    bool mVisibleToOwnerTeamOnly; // 0x5
    float_t mPerceptionBubbleRadius; // 0x8
    float_t m_0xBB639057; // 0xC
};
struct Defaultvisibility: MissileVisibilitySpec { // 0x10
   // ctor: 0x008B3A00
   // init: 0x008B40D0
};
struct EnterFowVisibility: MissileVisibilitySpec { // 0x14
   // ctor: 0x008B3DE0
   // init: 0x008B4300
    bool mMissileClientExitFowPrediction; // 0x10
    bool mMissileClientWaitForTargetUpdateBeforeMissileShow; // 0x11
};
struct MissileAttachedTargetingDefinition: PropertyBase { // 0x2C
   // ctor: 0x008B3D50
   // init: 0x008B3850
    uint8_t mEndPositionType; // 0x4
    string_t mLineTextureName; // 0x8
    float_t mLineTextureWidth; // 0x14
    string_t mLineEndTextureName; // 0x18
    float_t mLineEndTextureWidth; // 0x24
    float_t mLineEndTextureHeight; // 0x28
};
struct AiSpellData { // 0x18
   // ctor: 0x008CE180
   // init: 0x008CDD10
    bool mSendAiEvent; // 0x0
    float_t mRadius; // 0x4
    float_t mLifetime; // 0x8
    float_t mRange; // 0xC
    float_t mSpeed; // 0x10
    bool mEndOnly; // 0x14
    uint8_t mBlockLevel; // 0x15
};
struct SpellEffectAmount { // 0x1C
   // ctor: 0x008CDD40
   // init: 0x008CD9F0
    array_t<float_t, 7> Value; // 0x0
};
struct SpellDataValue: PropertyBase { // 0x30
   // ctor: 0x008CE2B0
   // init: 0x008CE410
    string_t mName; // 0x4
    array_t<float_t, 7> mValues; // 0x10
};
struct SpellDataValueVector { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    vector_t<SpellDataValue> SpellDataValues; // 0x0
};
struct PlatformSpellInfo { // 0x18
   // ctor: 0x008CDB50
   // init: 0x008CDD90
    int32_t mAvatarLevelRequired; // 0x0
    int32_t mSpellId; // 0x4
    bool mPlatformEnabled; // 0x8
    vector_t<string_t> mGameModes; // 0xC
};
struct ISplineInfo: PropertyBase { // 0x14
   // ctor: 0x00400000
   // init: 0x00400000
    point3D_t mStartPositionOffset; // 0x4
    bool mUseMissilePositionAsOrigin; // 0x10
};
struct HermiteSplineInfo: ISplineInfo { // 0x2C
   // ctor: 0x008CE1C0
   // init: 0x008CDE80
    point3D_t mControlPoint1; // 0x14
    point3D_t mControlPoint2; // 0x20
};
struct OverrideAttackTimeData: PropertyBase { // 0x10
   // ctor: 0x008CD9D0
   // init: 0x008CDA90
    unique_ptr_t<IGameCalculation> m_0x20991541; // 0x4
    float_t mCastTimePercent; // 0x8
    bool m_0x278D2A22; // 0xC
};
struct UseAutoattackCastTimeData: PropertyBase { // 0xC
   // ctor: 0x008CDB20
   // init: 0x008CDA80
    unique_ptr_t<IGameCalculation> mAutoattackCastTimeCalculation; // 0x4
    bool m_0x862FBE94; // 0x8
};
struct SpellLockDeltaTimeData: PropertyBase { // 0x8
   // ctor: 0x008CE130
   // init: 0x008CDAC0
    unique_ptr_t<IGameCalculation> mSpellLockDeltaTimeCalculation; // 0x4
};
struct t_0x7A9E7D89: PropertyBase { // 0x2C
   // ctor: 0x008CDB40
   // init: 0x008CDAD0
    float_t m_0x55205ACB; // 0x4
    vector_t<unique_ptr_t<ICastRequirement>> m_0x166D5141; // 0x8
    vector_t<unique_ptr_t<ICastRequirement>> m_0x175E6650; // 0x14
    bool m_0xDA83E690; // 0x20
    uint32_t mAffectsTypeOverride; // 0x24
    uint32_t mAffectsStatusOverride; // 0x28
};
struct AlternateSpellAssets: PropertyBase { // 0x7C
   // ctor: 0x008CDC70
   // init: 0x008CDFC0
    string_t mAnimationName; // 0x4
    string_t mAnimationLoopName; // 0x10
    string_t mAnimationWinddownName; // 0x1C
    string_t mAnimationLeadOutName; // 0x28
    bool mUseAnimatorFramerate; // 0x34
    uint32_t mHitEffectOrientType; // 0x38
    bool mHaveHitEffect; // 0x3C
    bool mHaveHitBone; // 0x3D
    string_t mHitBoneName; // 0x40
    hash_t mHitEffectKey; // 0x4C
    string_t mHitEffectName; // 0x50
    hash_t mHitEffectPlayerKey; // 0x5C
    string_t mHitEffectPlayerName; // 0x60
    hash_t mAfterEffectKey; // 0x6C
    string_t mAfterEffectName; // 0x70
};
struct SpellDataResource: PropertyBase { // 0x600
   // ctor: 0x008CE1D0
   // init: 0x008CE230
    uint32_t Flags; // 0x8
    uint32_t mAffectsTypeFlags; // 0xC
    uint32_t mAffectsStatusFlags; // 0x10
    ObjectTags mRequiredUnitTags; // 0x18
    ObjectTags mExcludedUnitTags; // 0x30
    vector_t<unique_ptr_t<ICastRequirement>> mCastRequirementsCaster; // 0x48
    vector_t<unique_ptr_t<ICastRequirement>> mCastRequirementsTarget; // 0x54
    vector_t<t_0x7A9E7D89> m_0x7A9E7D89; // 0x60
    PlatformSpellInfo mPlatformSpellInfo; // 0x78
    string_t mAlternateName; // 0x90
    vector_t<string_t> mSpellTags; // 0xA8
    array_t<SpellEffectAmount, 10> mEffectAmount; // 0xB4
    vector_t<SpellDataValue> mDataValues; // 0x1CC
    map_t<hash_t, SpellDataValueVector> m_0xFB56608C; // 0x1D8
    map_t<hash_t, unique_ptr_t<IGameCalculation>> mSpellCalculations; // 0x1E4
    float_t mCoefficient; // 0x1F0
    float_t mCoefficient2; // 0x1F4
    vector_t<AlternateSpellAssets> mAlternateSpellAssets; // 0x1F8
    string_t mAnimationName; // 0x204
    string_t mAnimationLoopName; // 0x210
    string_t mAnimationWinddownName; // 0x21C
    string_t mAnimationLeadOutName; // 0x228
    vector_t<string_t> mImgIconName; // 0x234
    string_t mMinimapIconName; // 0x240
    string_t mKeywordWhenAcquired; // 0x24C
    float_t mCastTime; // 0x258
    array_t<float_t, 7> mChannelDuration; // 0x25C
    array_t<float_t, 7> CooldownTime; // 0x27C
    float_t DelayCastOffsetPercent; // 0x298
    float_t DelayTotalTimePercent; // 0x29C
    float_t mPreCastLockoutDeltaTime; // 0x2A0
    unique_ptr_t<SpellLockDeltaTimeData> mPreCastLockoutDeltaTimeData; // 0x2A4
    float_t mPostCastLockoutDeltaTime; // 0x2A8
    unique_ptr_t<SpellLockDeltaTimeData> mPostCastLockoutDeltaTimeData; // 0x2AC
    float_t mStartCooldown; // 0x2B0
    array_t<float_t, 7> mCastRangeGrowthMax; // 0x2B4
    array_t<float_t, 7> mCastRangeGrowthStartTime; // 0x2D0
    array_t<float_t, 7> mCastRangeGrowthDuration; // 0x2EC
    float_t mChargeUpdateInterval; // 0x308
    float_t mCancelChargeOnRecastTime; // 0x30C
    uint8_t m_0x3D746F1F; // 0x310
    vector_t<unique_ptr_t<SpellPassiveData>> m_0x1632F6FC; // 0x314
    vector_t<CharacterPassiveData> mCharacterPassiveBuffs; // 0x320
    array_t<int32_t, 7> mMaxAmmo; // 0x32C
    array_t<int32_t, 7> mAmmoUsed; // 0x348
    array_t<float_t, 7> mAmmoRechargeTime; // 0x364
    bool mIsDelayedByCastLocked; // 0x380
    bool mAmmoNotAffectedByCdr; // 0x381
    bool mCooldownNotAffectedByCdr; // 0x382
    bool mAmmoCountHiddenInUi; // 0x383
    bool mCostAlwaysShownInUi; // 0x384
    bool m_0x9FB86DC4; // 0x385
    bool CannotBeSuppressed; // 0x386
    bool CanCastWhileDisabled; // 0x387
    bool mCanTriggerChargeSpellWhileDisabled; // 0x388
    bool CanCastOrQueueWhileCasting; // 0x389
    bool CanOnlyCastWhileDisabled; // 0x38A
    bool mCantCancelWhileWindingUp; // 0x38B
    bool m_0x7E3432A0; // 0x38C
    bool mCantCancelWhileChanneling; // 0x38D
    bool CantCastWhileRooted; // 0x38E
    bool mChannelIsInterruptedByDisables; // 0x38F
    bool mChannelIsInterruptedByAttacking; // 0x390
    bool mApplyAttackDamage; // 0x391
    bool mApplyAttackEffect; // 0x392
    bool mApplyMaterialOnHitSound; // 0x393
    bool mDoesntBreakChannels; // 0x394
    bool mBelongsToAvatar; // 0x395
    bool mIsDisabledWhileDead; // 0x396
    bool CanOnlyCastWhileDead; // 0x397
    bool mCursorChangesInGrass; // 0x398
    bool mCursorChangesInTerrain; // 0x399
    bool mProjectTargetToCastRange; // 0x39A
    bool mSpellRevealsChampion; // 0x39B
    bool mUseMinimapTargeting; // 0x39C
    bool CastRangeUseBoundingBoxes; // 0x39D
    bool mMinimapIconRotation; // 0x39E
    bool mUseChargeChanneling; // 0x39F
    bool mCanMoveWhileChanneling; // 0x3A0
    bool mDisableCastBar; // 0x3A1
    bool mShowChannelBar; // 0x3A2
    bool AlwaysSnapFacing; // 0x3A3
    bool UseAnimatorFramerate; // 0x3A4
    bool bHaveHitEffect; // 0x3A5
    bool bHaveHitBone; // 0x3A6
    bool bIsToggleSpell; // 0x3A7
    bool mDoNotNeedToFaceTarget; // 0x3A8
    float_t mTurnSpeedScalar; // 0x3AC
    bool mNoWinddownIfCancelled; // 0x3B0
    bool mIgnoreRangeCheck; // 0x3B1
    bool mOrientRadiusTextureFromPlayer; // 0x3B2
    unique_ptr_t<OverrideAttackTimeData> mOverrideAttackTime; // 0x3B4
    unique_ptr_t<UseAutoattackCastTimeData> mUseAutoattackCastTimeData; // 0x3B8
    bool mIgnoreAnimContinueUntilCastFrame; // 0x3BC
    bool mHideRangeIndicatorWhenCasting; // 0x3BD
    bool mUpdateRotationWhenCasting; // 0x3BE
    bool mPingableWhileDisabled; // 0x3BF
    bool mConsideredAsAutoAttack; // 0x3C0
    bool mDoesNotConsumeMana; // 0x3C1
    bool mDoesNotConsumeCooldown; // 0x3C2
    bool mLockedSpellOriginationCastId; // 0x3C3
    bool m_0x898FBAD4; // 0x3C4
    uint16_t mMinimapIconDisplayFlag; // 0x3C6
    array_t<float_t, 7> CastRange; // 0x3C8
    array_t<float_t, 7> CastRangeDisplayOverride; // 0x3E4
    array_t<float_t, 7> CastRadius; // 0x400
    array_t<float_t, 7> CastRadiusSecondary; // 0x41C
    float_t CastConeAngle; // 0x438
    float_t CastConeDistance; // 0x43C
    float_t CastTargetAdditionalUnitsRadius; // 0x440
    float_t LuaOnMissileUpdateDistanceInterval; // 0x444
    unique_ptr_t<MissileSpecification> mMissileSpec; // 0x448
    uint32_t mCastType; // 0x44C
    float_t CastFrame; // 0x450
    float_t MissileSpeed; // 0x454
    hash_t mMissileEffectKey; // 0x458
    string_t mMissileEffectName; // 0x45C
    hash_t mMissileEffectPlayerKey; // 0x468
    string_t mMissileEffectPlayerName; // 0x46C
    hash_t mMissileEffectEnemyKey; // 0x478
    string_t mMissileEffectEnemyName; // 0x47C
    float_t mLineWidth; // 0x488
    float_t mLineDragLength; // 0x48C
    uint32_t mLookAtPolicy; // 0x490
    uint32_t mHitEffectOrientType; // 0x494
    string_t mHitBoneName; // 0x498
    vector_t<link_ptr_t<ResourceResolver>> mResourceResolvers; // 0x4A4
    hash_t mHitEffectKey; // 0x4B0
    string_t mHitEffectName; // 0x4B4
    hash_t mHitEffectPlayerKey; // 0x4C0
    string_t mHitEffectPlayerName; // 0x4C4
    hash_t mAfterEffectKey; // 0x4D0
    string_t mAfterEffectName; // 0x4D4
    point3D_t mParticleStartOffset; // 0x4E0
    array_t<int32_t, 16> mFloatVarsDecimals; // 0x4EC
    array_t<float_t, 6> Mana; // 0x52C
    array_t<float_t, 6> ManaUiOverride; // 0x544
    uint32_t SelectionPriority; // 0x55C
    string_t mVoEventCategory; // 0x560
    AiSpellData mAiData; // 0x56C
    optional_t<float_t> mSpellCooldownOrSealedQueueThreshold; // 0x584
    uint8_t m_0x03F432A6; // 0x588
    SpellDataResourceClient mClientData; // 0x58C
    bool m_0x00F7E5BC; // 0x5EC
    bool m_0x39381720; // 0x5ED
    bool m_0xA8EB09D1; // 0x5EE
    bool m_0x24B763C2; // 0x5EF
    unique_ptr_t<TargetingTypeData> mTargetingTypeData; // 0x5F0
};
struct SpellPassiveData: PropertyBase { // 0x14
   // ctor: 0x008CDC30
   // init: 0x008CDA10
    link_ptr_t<SpellObject> mBuff; // 0x4
    uint32_t m_0x8692E24A; // 0x8
    bool m_0x76B67BCC; // 0xC
    bool m_0xCBDF3AF2; // 0xD
    bool m_0xF862632B; // 0xE
    bool m_0x7AA0FED6; // 0xF
    uint8_t mDisplayFlags; // 0x10
};
struct CustomTargeterDefinitions { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    vector_t<unique_ptr_t<TargeterDefinition>> mTargeterDefinitions; // 0x0
};
struct SpellDataResourceClient { // 0x60
   // ctor: 0x008CE090
   // init: 0x008CE0F0
    hash_t m_0x375656DD; // 0x0
    hash_t m_0x7D4A0E6E; // 0xC
    unique_ptr_t<TooltipInstanceSpell> mTooltipData; // 0x18
    unique_ptr_t<SpawningUiDefinition> mSpawningUiDefinition; // 0x1C
    vector_t<unique_ptr_t<TargeterDefinition>> mTargeterDefinitions; // 0x20
    unordered_map_t<hash_t, CustomTargeterDefinitions> mCustomTargeterDefinitions; // 0x2C
    vector_t<unique_ptr_t<MissileAttachedTargetingDefinition>> mMissileTargeterDefinitions; // 0x4C
    uint32_t mLeftClickSpellAction; // 0x58
    uint32_t mRightClickSpellAction; // 0x5C
};
struct SpawningUiDefinition: PropertyBase { // 0x14
   // ctor: 0x008CE1F0
   // init: 0x008CE260
    string_t BuffNameFilter; // 0x4
    int32_t MaxNumberOfUnits; // 0x10
};
struct LolSpellScript: Rscript { // 0xC8
   // ctor: 0x008CDD70
   // init: 0x008CE0B0
    ScriptGlobalProperties GlobalProperties; // 0x4
    map_t<hash_t, ScriptSequence> Sequences; // 0x80
    map_t<string_t, ScriptSequence> CustomSequences; // 0x8C
    LolSpellPreloadData PreloadData; // 0x98
};
struct IScriptPreload: PropertyBase { // 0x10
   // ctor: 0x00400000
   // init: 0x00400000
};
struct ScriptPreloadCharacter: PropertyBase { // 0x10
   // ctor: 0x008CDBB0
   // init: 0x008CE150
    string_t PreloadResourceName; // 0x4
};
struct ScriptPreloadSpell: PropertyBase { // 0x10
   // ctor: 0x008CDFE0
   // init: 0x008CDC90
    string_t PreloadResourceName; // 0x4
};
struct ScriptPreloadModule: PropertyBase { // 0x10
   // ctor: 0x008CDF30
   // init: 0x008CE020
    string_t PreloadResourceName; // 0x4
};
struct ScriptPreloadParticle: PropertyBase { // 0x10
   // ctor: 0x008CE380
   // init: 0x008CE3C0
    string_t PreloadResourceName; // 0x4
};
struct LolSpellPreloadData { // 0x30
   // ctor: 0x008CDE60
   // init: 0x008CDED0
    vector_t<unique_ptr_t<ScriptPreloadCharacter>> CharacterPreloads; // 0x0
    vector_t<unique_ptr_t<ScriptPreloadSpell>> SpellPreloads; // 0xC
    vector_t<unique_ptr_t<ScriptPreloadModule>> ModulePreloads; // 0x18
    vector_t<unique_ptr_t<ScriptPreloadParticle>> ParticlePreloads; // 0x24
};
struct ScriptGlobalProperties { // 0x7C
   // ctor: 0x008CDE10
   // init: 0x008CDF80
    int32_t OnPreDamagePriority; // 0x4
    uint32_t DeathEventType; // 0x8
    float_t CastTime; // 0xC
    float_t ChannelDuration; // 0x10
    string_t BuffName; // 0x14
    string_t BuffTextureName; // 0x20
    string_t DisplayName; // 0x2C
    vector_t<string_t> AutoBuffActivateEffects; // 0x38
    vector_t<string_t> AutoBuffActivateAttachBoneNames; // 0x44
    bool PersistsThroughDeath; // 0x50
    bool NonDispellable; // 0x51
    bool IsDeathRecapSource; // 0x52
    bool IsItemToggled; // 0x53
    uint32_t SpellToggleSlot; // 0x54
    vector_t<string_t> SpellFxOverrideSkins; // 0x58
    vector_t<string_t> SpellVoOverrideSkins; // 0x64
    vector_t<string_t> PopupMessages; // 0x70
};
struct InstanceVarsTable: ScriptTable { // 0x4
   // ctor: 0x008CE360
   // init: 0x008CDCC0
};
struct CharacterVarsTable: ScriptTable { // 0x4
   // ctor: 0x008CDB90
   // init: 0x008CE0D0
};
struct NextBuffVarsTable: ScriptTable { // 0x4
   // ctor: 0x008CDFA0
   // init: 0x008CDE50
};
struct WorldVarsTable: ScriptTable { // 0x4
   // ctor: 0x008CDAA0
   // init: 0x008CDF90
};
struct AvatarVarsTable: ScriptTable { // 0x4
   // ctor: 0x008CDE30
   // init: 0x008CE120
};
struct NextSpellVarsTable: ScriptTable { // 0x4
   // ctor: 0x008CE340
   // init: 0x008CE240
};
struct TempTable1Table: ScriptTable { // 0x4
   // ctor: 0x008CDCF0
   // init: 0x008CE250
};
struct TempTable2Table: ScriptTable { // 0x4
   // ctor: 0x008CDCD0
   // init: 0x008CE0E0
};
struct TempTable3Table: ScriptTable { // 0x4
   // ctor: 0x008CE3F0
   // init: 0x008CDF70
};
struct ILineIndicatorType: PropertyBase { // 0x4
   // ctor: 0x00400000
   // init: 0x00400000
};
struct IndicatorTypeLocal: ILineIndicatorType { // 0x4
   // ctor: 0x008CE290
   // init: 0x008CDC20
};
struct IndicatorTypeGlobal: ILineIndicatorType { // 0x8
   // ctor: 0x008CE100
   // init: 0x008CDA70
    bool mIsFloating; // 0x4
};
struct ITargeterFadeBehavior: PropertyBase { // 0x4
   // ctor: 0x00400000
   // init: 0x00400000
};
struct FadeOverTimeBehavior: ITargeterFadeBehavior { // 0x14
   // ctor: 0x008EFCB0
   // init: 0x008EFAC0
    float_t mTimeStart; // 0x4
    float_t mTimeEnd; // 0x8
    float_t mStartAlpha; // 0xC
    float_t mEndAlpha; // 0x10
};
struct FadeByMouseRangeBehavior: ITargeterFadeBehavior { // 0x14
   // ctor: 0x008EFD90
   // init: 0x008EFBF0
    float_t m_0x76A72AD1; // 0x4
    float_t m_0x65183440; // 0x8
    float_t mStartAlpha; // 0xC
    float_t mEndAlpha; // 0x10
};
struct FadeToExplicitValueBehavior: ITargeterFadeBehavior { // 0x8
   // ctor: 0x008EFED0
   // init: 0x008EFFE0
    float_t mAlpha; // 0x4
};
struct t_0x29DFD7AD { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    float_t m_0xAEEBCBDD; // 0x0
    float_t m_0xA8A2F6C7; // 0x4
    float_t m_0x64E4F9F9; // 0x8
};
struct FloatPerSpellLevel { // 0x1C
   // ctor: 0x008EFC50
   // init: 0x008F00A0
    array_t<float_t, 6> mPerLevelValues; // 0x0
    uint32_t mValueType; // 0x18
};
struct DrawablePositionLocator { // 0x10
   // ctor: 0x005CA800
   // init: 0x005CA650
    uint32_t BasePosition; // 0x0
    float_t DistanceOffset; // 0x4
    float_t AngleOffsetRadian; // 0x8
    uint32_t OrientationType; // 0xC
};
struct TargeterDefinition: PropertyBase { // 0x18
   // ctor: 0x00400000
   // init: 0x00400000
    unique_ptr_t<ITargeterFadeBehavior> mFadeBehavior; // 0x14
};
struct TargeterDefinitionAoe: TargeterDefinition { // 0x90
   // ctor: 0x008EFBC0
   // init: 0x008EFDD0
    DrawablePositionLocator CenterLocator; // 0x18
    uint32_t TextureOrientation; // 0x28
    bool IsConstrainedToRange; // 0x2C
    DrawablePositionLocator ConstraintPosLocator; // 0x30
    FloatPerSpellLevel ConstraintRange; // 0x40
    FloatPerSpellLevel OverrideRadius; // 0x5C
    t_0x29DFD7AD m_0x2ACBB00B; // 0x78
    string_t TextureRadiusOverrideName; // 0x84
};
struct TargeterDefinitionArc: TargeterDefinition { // 0x84
   // ctor: 0x008EFF10
   // init: 0x008EFD00
    DrawablePositionLocator StartLocator; // 0x18
    DrawablePositionLocator EndLocator; // 0x28
    bool IsClockwiseArc; // 0x38
    bool IsConstrainedToRange; // 0x39
    FloatPerSpellLevel ConstraintRange; // 0x3C
    FloatPerSpellLevel OverrideRadius; // 0x58
    string_t TextureArcOverrideName; // 0x74
    float_t ThicknessOffset; // 0x80
};
struct TargeterDefinitionCone: TargeterDefinition { // 0xB4
   // ctor: 0x008EFA70
   // init: 0x008EFA90
    DrawablePositionLocator StartLocator; // 0x18
    DrawablePositionLocator EndLocator; // 0x28
    uint32_t FallbackDirection; // 0x38
    bool HasMaxGrowRange; // 0x3C
    bool ConeFollowsEnd; // 0x3D
    optional_t<float_t> ConeAngleDegrees; // 0x40
    optional_t<float_t> ConeRange; // 0x44
    FloatPerSpellLevel RangeGrowthStartTime; // 0x48
    FloatPerSpellLevel RangeGrowthDuration; // 0x64
    FloatPerSpellLevel RangeGrowthMax; // 0x80
    string_t TextureConeOverrideName; // 0x9C
    string_t TextureConeMaxGrowName; // 0xA8
};
struct TargeterDefinitionLine: TargeterDefinition { // 0x134
   // ctor: 0x008EFAF0
   // init: 0x008EFF00
    unique_ptr_t<ILineIndicatorType> IndicatorType; // 0x18
    DrawablePositionLocator StartLocator; // 0x1C
    DrawablePositionLocator EndLocator; // 0x2C
    uint32_t FallbackDirection; // 0x3C
    bool AlwaysDraw; // 0x40
    bool HasMaxGrowRange; // 0x41
    bool UseGlobalLineIndicator; // 0x42
    optional_t<bool> LineStopsAtEndPosition; // 0x43
    float_t MinimumDisplayedRange; // 0x44
    float_t ArrowSize; // 0x48
    FloatPerSpellLevel LineWidth; // 0x4C
    FloatPerSpellLevel OverrideBaseRange; // 0x68
    FloatPerSpellLevel RangeGrowthStartTime; // 0x84
    FloatPerSpellLevel RangeGrowthDuration; // 0xA0
    FloatPerSpellLevel RangeGrowthMax; // 0xBC
    string_t TextureBaseOverrideName; // 0xD8
    string_t TextureTargetOverrideName; // 0xE4
    string_t TextureBaseMaxGrowName; // 0xF0
    string_t TextureTargetMaxGrowName; // 0xFC
    bool mAngleLineToEndpointHeight; // 0x108
    bool mCenterArrowToEndPoint; // 0x109
    bool FacingLine; // 0x10A
    float_t MinAngleRangeFactor; // 0x114
    float_t MaxAngleRangeFactor; // 0x118
    bool Fade; // 0x11C
    float_t MinAngle; // 0x128
    float_t MaxAngle; // 0x12C
    float_t FadeAngle; // 0x130
};
struct TargeterDefinitionMinimap: TargeterDefinition { // 0x48
   // ctor: 0x008EFA00
   // init: 0x008EFE90
    DrawablePositionLocator CenterLocator; // 0x18
    optional_t<bool> UseCasterBoundingBox; // 0x28
    FloatPerSpellLevel OverrideBaseRange; // 0x2C
};
struct TargeterDefinitionRange: TargeterDefinition { // 0xB8
   // ctor: 0x008EFE70
   // init: 0x008EFF80
    DrawablePositionLocator CenterLocator; // 0x18
    uint32_t TextureOrientation; // 0x28
    bool HideWithLineIndicator; // 0x2C
    bool HasMaxGrowRange; // 0x2D
    optional_t<bool> UseCasterBoundingBox; // 0x2E
    FloatPerSpellLevel OverrideBaseRange; // 0x30
    FloatPerSpellLevel RangeGrowthStartTime; // 0x4C
    FloatPerSpellLevel RangeGrowthDuration; // 0x68
    FloatPerSpellLevel RangeGrowthMax; // 0x84
    string_t TextureOverrideName; // 0xA0
    string_t TextureMaxGrowName; // 0xAC
};
struct TargeterDefinitionWall: TargeterDefinition { // 0x74
   // ctor: 0x008EFA30
   // init: 0x008EFE60
    DrawablePositionLocator CenterLocator; // 0x18
    uint32_t WallOrientation; // 0x28
    float_t WallRotation; // 0x2C
    FloatPerSpellLevel Thickness; // 0x30
    FloatPerSpellLevel Length; // 0x4C
    string_t TextureWallOverrideName; // 0x68
};
struct TargeterDefinitionMultiAoe: TargeterDefinition { // 0xA8
   // ctor: 0x008EFD70
   // init: 0x008EFEF0
    DrawablePositionLocator CenterLocator; // 0x18
    FloatPerSpellLevel OverrideAoeRadius; // 0x28
    FloatPerSpellLevel OverrideMinCastRange; // 0x44
    FloatPerSpellLevel OverrideMaxCastRange; // 0x60
    float_t AngelOffsetRadian; // 0x7C
    uint32_t NumOfInnerAoe; // 0x80
    string_t LeftTextureName; // 0x84
    string_t RightTextureName; // 0x90
    string_t InnerTextureName; // 0x9C
};
struct TargeterDefinitionSpline: TargeterDefinition { // 0x98
   // ctor: 0x008EFB30
   // init: 0x008EFFD0
    DrawablePositionLocator StartLocator; // 0x18
    DrawablePositionLocator EndLocator; // 0x28
    string_t BaseTextureName; // 0x38
    string_t FrontTextureName; // 0x44
    FloatPerSpellLevel SplineWidth; // 0x50
    unique_ptr_t<ISplineInfo> OverrideSpline; // 0x6C
    uint32_t MinSegmentCount; // 0x70
    float_t MaxSegmentLength; // 0x74
    bool IsConstrainedToRange; // 0x78
    FloatPerSpellLevel ConstraintRange; // 0x7C
};
struct TargeterDefinitionSkipTerrain: TargeterDefinition { // 0x64
   // ctor: 0x008EFA50
   // init: 0x008EFD10
    DrawablePositionLocator mStartLocator; // 0x18
    DrawablePositionLocator mEndLocator; // 0x28
    uint32_t mFallbackDirection; // 0x38
    string_t mBaseTextureName; // 0x3C
    string_t mTerrainTextureName; // 0x48
    string_t mTargetTextureName; // 0x54
    float_t mTargetTextureRadius; // 0x60
};
struct TargetingTypeData: PropertyBase { // 0x4
   // ctor: 0x00400000
   // init: 0x00400000
};
struct Self: TargetingTypeData { // 0x4
   // ctor: 0x008EFB10
   // init: 0x008EFF60
};
struct Target: TargetingTypeData { // 0x8
   // ctor: 0x008EFD20
   // init: 0x008EFC80
    bool m_0x6F92D6B3; // 0x4
};
struct Area: TargetingTypeData { // 0x4
   // ctor: 0x008EFD50
   // init: 0x008EFD40
};
struct Cone: TargetingTypeData { // 0x4
   // ctor: 0x008F0040
   // init: 0x008EFFC0
};
struct SelfAoe: TargetingTypeData { // 0x4
   // ctor: 0x008F0060
   // init: 0x008EFA20
};
struct TargetOrLocation: TargetingTypeData { // 0x4
   // ctor: 0x008EFC90
   // init: 0x008F0000
};
struct Location: TargetingTypeData { // 0x4
   // ctor: 0x008EF9E0
   // init: 0x008EFC40
};
struct Direction: TargetingTypeData { // 0x4
   // ctor: 0x008EFC20
   // init: 0x008EFF50
};
struct DragDirection: TargetingTypeData { // 0x4
   // ctor: 0x008EFB50
   // init: 0x008EFBE0
};
struct LineTargetToCaster: TargetingTypeData { // 0x4
   // ctor: 0x008EFBA0
   // init: 0x008EFCF0
};
struct AreaClamped: TargetingTypeData { // 0x4
   // ctor: 0x008EFDE0
   // init: 0x008EFF70
};
struct LocationClamped: TargetingTypeData { // 0x4
   // ctor: 0x008EFF90
   // init: 0x008EFFB0
};
struct TerrainLocation: TargetingTypeData { // 0x4
   // ctor: 0x008F0080
   // init: 0x008EFAA0
};
struct TerrainType: TargetingTypeData { // 0xAC
   // ctor: 0x008EFE00
   // init: 0x008F0010
    CursorData mBrushCursor; // 0x4
    CursorData mRiverCursor; // 0x3C
    CursorData mWallCursor; // 0x74
};
struct StatFormulaData { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    map_t<uint8_t, float_t> StatComponents; // 0x0
};
struct StatFormulaDataList { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    map_t<uint8_t, StatFormulaData> StatFormulas; // 0x0
};
struct GameModeDefaultStats { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    StatFormulaDataList DefaultCharacterStats; // 0x0
};
struct TftSurrenderCheat: Cheat { // 0x40
   // ctor: 0x008EFEA0
   // init: 0x008EFF30
};
struct TftChangeDamageSkinCheat: Cheat { // 0x44
   // ctor: 0x008F00C0
   // init: 0x008EFB70
};
struct TftItemMaterialController: SkinnedMeshDataMaterialController { // 0x4
   // ctor: 0x0090B8D0
   // init: 0x0090BA20
};
struct TftMapCharacterRecordData { // 0x1
   // ctor: 0x0090B760
   // init: 0x0090B7D0
    uint8_t Tier; // 0x0
};
struct TftMapCharacterSkinData { // 0xC
   // ctor: 0x0067CE10
   // init: 0x0067CB50
    string_t SquareIconTexturePath; // 0x0
};
struct TftMapCharacterData { // 0x24
   // ctor: 0x0090B650
   // init: 0x0090C070
    string_t Name; // 0x0
    vector_t<TftMapCharacterSkinData> SkinData; // 0xC
    vector_t<TftMapCharacterRecordData> CharData; // 0x18
};
struct TftMapCharacterList { // 0x18
   // ctor: 0x006086D0
   // init: 0x00608E10
    string_t ListName; // 0x0
    vector_t<TftMapCharacterData> Characters; // 0xC
};
struct TftMapCharacterLists { // 0x18
   // ctor: 0x006086D0
   // init: 0x00608E10
    string_t MapName; // 0x0
    vector_t<TftMapCharacterList> CharacterLists; // 0xC
};
struct TftAnnouncementData: PropertyBase { // 0x2C
   // ctor: 0x0090B5A0
   // init: 0x0090B5B0
    hash_t m_0x8B7D190D; // 0x4
    string_t mIconPath; // 0x8
    string_t mTitleTra; // 0x14
    float_t mDelay; // 0x24
    float_t mDuration; // 0x28
};
struct TftAttachmentSlotStyleData: PropertyBase { // 0x30
   // ctor: 0x0090B980
   // init: 0x0090BFA0
    string_t mName; // 0x4
    string_t mOverlayIconPath; // 0x14
    string_t mSubtextTra; // 0x20
};
struct TftCharacterRecord: CharacterRecord { // 0x918
   // ctor: 0x0090BB30
   // init: 0x0090B3F0
    string_t PortraitIcon; // 0x8B0
    uint8_t Tier; // 0x8C0
    vector_t<TftTraitContributionData> mLinkedTraits; // 0x8C8
    uint8_t m_0x2CDDDDBB; // 0x8D4
    uint8_t m_0x8D30A918; // 0x8D5
    float_t mMoveInterval; // 0x8D8
    float_t mMoveProximity; // 0x8DC
    float_t mMoveRange; // 0x8E0
    float_t mMoveHeight; // 0x8E4
    float_t mInitialMana; // 0x8E8
    float_t m_0x7CBC4762; // 0x8EC
    link_ptr_t<TftShopData> mShopData; // 0x8F0
    string_t m_0x4E28A666; // 0x8F4
    point3D_t m_0xD9439003; // 0x904
    bool m_0x4A52410B; // 0x910
    bool m_0xEF57098F; // 0x911
    bool m_0x1F16E793; // 0x912
    bool m_0xE1562EE7; // 0x913
};
struct TftDragData: PropertyBase { // 0x48
   // ctor: 0x0090C0C0
   // init: 0x0090BE90
    bool mHoldToHover; // 0x4
    bool mHoldToDrag; // 0x5
    bool m_0x44AB329E; // 0x6
    float_t m_0xD1296E95; // 0x8
    float_t m_0x6D90172B; // 0xC
    float_t m_0x59129CBE; // 0x10
    float_t m_0xE2567252; // 0x14
    float_t mDragBlendTime; // 0x18
    float_t mDragPickupHeight; // 0x1C
    float_t mDragPickupDuration; // 0x20
    float_t mDragReleaseDuration; // 0x24
    float_t mDragOvershootDuration; // 0x28
    float_t mDragOvershootHeight; // 0x2C
    string_t mDragSoundEvent; // 0x30
    string_t mDropSoundEvent; // 0x3C
};
struct TftDropRates: PropertyBase { // 0x18
   // ctor: 0x0090BD20
   // init: 0x0090BAA0
    array_t<float_t, 5> mDropRatesByTier; // 0x4
};
struct t_0xF260C3AE: PropertyBase { // 0x10
   // ctor: 0x0090BC30
   // init: 0x0090BB10
    vector_t<TftDropRates> mDropRatesByLevel; // 0x4
};
struct TftEffectAmount { // 0x14
   // ctor: 0x00609100
   // init: 0x00608DA0
    hash_t Name; // 0x0
    float_t Value; // 0x4
    string_t FormatString; // 0x8
};
struct TftItemComposition: PropertyBase { // 0x10
   // ctor: 0x0090B400
   // init: 0x0090B800
    vector_t<link_ptr_t<TftItemData>> mComponents; // 0x4
};
struct TftItemData: PropertyBase { // 0xA8
   // ctor: 0x0090B430
   // init: 0x0090BD10
    int32_t mId; // 0x8
    string_t mName; // 0xC
    string_t mBuffName; // 0x18
    vector_t<link_ptr_t<TftItemData>> mComposition; // 0x28
    vector_t<TftItemComposition> m_0xA3AC84D8; // 0x34
    vector_t<TftEffectAmount> EffectAmounts; // 0x40
    vector_t<link_ptr_t<TftTraitData>> m_0x6752C795; // 0x4C
    bool mIsUnique; // 0x59
    vector_t<hash_t> ItemTags; // 0x5C
    string_t mDisplayNameTra; // 0x68
    string_t mDescriptionNameTra; // 0x74
    string_t mIconPath; // 0x80
    optional_t<color_t> mColor; // 0x90
    point2D_t m_0x91D75DFF; // 0x98
    link_ptr_t<VfxSystemDefinitionData> mVfxSystem; // 0xA0
    int32_t m_0x6D8FCEED; // 0xA4
};
struct TftItemList { // 0x10
   // ctor: 0x005CA800
   // init: 0x005CA650
    vector_t<link_ptr_t<TftItemData>> mItems; // 0x0
    link_ptr_t<ResourceResolver> VfxResourceResolver; // 0xC
};
struct t_0x3604B3E3: PropertyBase { // 0xC
   // ctor: 0x0090BEA0
   // init: 0x0090BF60
    uint32_t m_0x79DAFA57; // 0x4
    float_t m_0x0AE9687E; // 0x8
};
struct TftModeData: PropertyBase { // 0xEC
   // ctor: 0x0090BAE0
   // init: 0x0090BBE0
    link_ptr_t<TftSetData> mDefaultSetData; // 0x4
    TftDragData mDragData; // 0x8
    TftDragData mMobileDragData; // 0x50
    float_t m_0x3CAEB7B4; // 0x98
    link_ptr_t<TftBotLoadoutConfiguration> m_0x4A191241; // 0x9C
    hash_t mTftMapSkinDefault; // 0xA0
    hash_t mTftDamageSkinDefault; // 0xAC
    hash_t mDefaultTftCompanion; // 0xB8
    hash_t mTutorialTftCompanion; // 0xC4
    float_t m_0xB75A7951; // 0xD0
    vector_t<hash_t> m_0x12AAF1D8; // 0xD4
    vector_t<t_0x3604B3E3> m_0x0E13C7AA; // 0xE0
};
struct TftGameVariationData: PropertyBase { // 0x50
   // ctor: 0x0090BBF0
   // init: 0x0090BD80
    string_t mName; // 0x4
    string_t mStageIconPath; // 0x14
    string_t mTooltipIconPath; // 0x20
    string_t mTooltipDescriptionTra; // 0x30
    string_t mTooltipTitleTra; // 0x3C
    link_ptr_t<TftAnnouncementData> mAnnouncementData; // 0x48
};
struct TftNotificationData: PropertyBase { // 0x70
   // ctor: 0x0090C030
   // init: 0x0090B4E0
    string_t mName; // 0x4
    float_t mDurationSeconds; // 0x14
    string_t mToplineTra; // 0x18
    string_t mBottomlineTra; // 0x24
    string_t mIconPath; // 0x30
    string_t m_0x1E7FFFB0; // 0x3C
    string_t m_0xDE5BE189; // 0x48
    string_t m_0xA6874A6E; // 0x54
};
struct TftPhaseData: PropertyBase { // 0x24
   // ctor: 0x0090BD90
   // init: 0x0090B780
    bool mEnabled; // 0x8
    float_t mDuration; // 0xC
    uint32_t mDisplay; // 0x10
    string_t mLabel; // 0x14
    link_ptr_t<TftAnnouncementData> mAnnouncementData; // 0x20
};
struct TftRoundData: PropertyBase { // 0x200
   // ctor: 0x0090B610
   // init: 0x0090BD00
    string_t mName; // 0x4
    string_t mDisplayNameTra; // 0x14
    string_t mDescriptionTra; // 0x20
    string_t mIconPath; // 0x2C
    string_t m_0xD20054C0; // 0x3C
    string_t m_0x304B0330; // 0x4C
    string_t m_0xF862CC05; // 0x5C
    string_t m_0xCB830E67; // 0x6C
    string_t mTftDamageSidewall; // 0x7C
    string_t m_0x4CB318CD; // 0x8C
    string_t mDefaultTooltipTra; // 0x9C
    map_t<uint32_t, string_t> mStateTooltipsTra; // 0xA8
    TftPhaseData mDraftArrival; // 0xB0
    TftPhaseData mDraft; // 0xD4
    TftPhaseData mDraftDeparture; // 0xF8
    TftPhaseData mPlanningArrival; // 0x11C
    TftPhaseData mPlanning; // 0x140
    TftPhaseData mPlanningDeparture; // 0x164
    TftPhaseData mCombatArrival; // 0x188
    TftPhaseData mCombat; // 0x1AC
    TftPhaseData mCombatDeparture; // 0x1D0
    map_t<string_t, unique_ptr_t<GameModeConstant>> mScriptData; // 0x1F4
};
struct TftStageData: PropertyBase { // 0x10
   // ctor: 0x0090B8A0
   // init: 0x0090B4C0
    vector_t<link_ptr_t<TftRoundData>> mRounds; // 0x4
};
struct TftSetData: PropertyBase { // 0x98
   // ctor: 0x0090C050
   // init: 0x0090C020
    uint32_t TftGameType; // 0x4
    uint32_t Number; // 0x8
    string_t Mutator; // 0xC
    vector_t<link_ptr_t<MapCharacterList>> DebugCharacterLists; // 0x18
    vector_t<link_ptr_t<MapCharacterList>> CharacterLists; // 0x24
    vector_t<link_ptr_t<TftItemList>> ItemLists; // 0x30
    vector_t<link_ptr_t<TftTraitList>> m_0xF74504C0; // 0x3C
    vector_t<link_ptr_t<t_0x369A22B9>> m_0x90183782; // 0x48
    map_t<string_t, link_ptr_t<t_0xF260C3AE>> DropRateTables; // 0x54
    vector_t<link_ptr_t<TftUnitUpgradeData>> UnitUpgrades; // 0x60
    map_t<string_t, unique_ptr_t<GameModeConstant>> ScriptData; // 0x6C
    vector_t<TftStageData> Stages; // 0x78
    vector_t<link_ptr_t<ScriptDataObjectList>> ScriptDataObjectLists; // 0x84
    link_ptr_t<ResourceResolver> VfxResourceResolver; // 0x90
    uint32_t m_0x4E40838E; // 0x94
};
struct TftShopData: PropertyBase { // 0x74
   // ctor: 0x0090BCE0
   // init: 0x0090C0E0
    string_t mName; // 0x4
    uint8_t mRarity; // 0x14
    string_t mDisplayNameTra; // 0x18
    string_t mAbilityNameTra; // 0x24
    string_t mDescriptionTra; // 0x30
    string_t mPortraitIconPath; // 0x3C
    string_t mIconPath; // 0x48
    string_t mMobileIconPath; // 0x54
    string_t mMobileSmallIconPath; // 0x60
};
struct t_0x369A22B9 { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    vector_t<link_ptr_t<TftShopData>> m_0x520398BE; // 0x0
};
struct TftStatData: PropertyBase { // 0x30
   // ctor: 0x0090BA00
   // init: 0x0090B900
    string_t mName; // 0x4
    uint32_t mType; // 0x1C
    uint32_t mContext; // 0x20
    uint32_t mLifetime; // 0x24
    int32_t m_0x0F3A339C; // 0x28
};
struct TftStreak { // 0x18
   // ctor: 0x005CA580
   // init: 0x005CA210
    optional_t<uint32_t> mMinimumStreakLength; // 0x0
    optional_t<uint32_t> mMaximumStreakLength; // 0x4
    uint32_t mGoldRewardAmount; // 0x8
    string_t mStreakFormat; // 0xC
};
struct TftStreakData: PropertyBase { // 0x1C
   // ctor: 0x0090BE40
   // init: 0x0090BA60
    vector_t<TftStreak> m_0xC3F540ED; // 0x4
    vector_t<TftStreak> mLossStreaks; // 0x10
};
struct TftTraitContributionData { // 0x10
   // ctor: 0x0090BF00
   // init: 0x0090B6B0
    link_ptr_t<TftTraitData> TraitData; // 0x4
    int32_t Amount; // 0x8
    bool m_0xA91037F5; // 0xC
};
struct TftTraitSetData { // 0x3C
   // ctor: 0x0090B4A0
   // init: 0x0090BA40
    uint32_t mMinUnits; // 0x0
    optional_t<uint32_t> mMaxUnits; // 0x4
    optional_t<uint32_t> m_0xA8C51DB0; // 0x8
    uint8_t mTeamToBuff; // 0xC
    uint8_t mTargetStrategy; // 0xD
    uint8_t mStyle; // 0xE
    string_t mBuffName; // 0x18
    string_t mActivatedBuffName; // 0x24
    vector_t<TftEffectAmount> EffectAmounts; // 0x30
};
struct TftTraitData: PropertyBase { // 0x60
   // ctor: 0x0090B3D0
   // init: 0x0090BA50
    string_t mName; // 0x4
    vector_t<TftTraitSetData> mTraitSets; // 0x14
    string_t mDisplayNameTra; // 0x20
    string_t mUnitSectionTra; // 0x2C
    string_t mDescriptionNameTra; // 0x38
    string_t mDisplayNameIcon; // 0x44
    string_t mIconPath; // 0x50
};
struct TftTraitList { // 0x10
   // ctor: 0x005CA800
   // init: 0x005CA650
    vector_t<link_ptr_t<TftTraitData>> mTraits; // 0x0
    link_ptr_t<ResourceResolver> VfxResourceResolver; // 0xC
};
struct TftUnitUpgradeData: PropertyBase { // 0x14
   // ctor: 0x0090B710
   // init: 0x0090B570
    string_t Name; // 0x4
    uint8_t m_0xD6DEBDBE; // 0x10
};
struct TftHudAnnouncementData { // 0x10
   // ctor: 0x0090B390
   // init: 0x0090BCB0
    HudMenuTransitionData mSceneTransitionIn; // 0x0
    HudMenuTransitionData mSceneTransitionOut; // 0x8
};
struct TftHudCombatRecapData { // 0xC
   // ctor: 0x0090B470
   // init: 0x0090B6D0
    HudMenuTransitionData mPanelTransition; // 0x0
    float_t m_0x4544719B; // 0x8
};
struct TftHudNotificationsData { // 0x10
   // ctor: 0x0090B390
   // init: 0x0090BCB0
    HudMenuTransitionData mSceneTransitionIn; // 0x0
    HudMenuTransitionData mSceneTransitionOut; // 0x8
};
struct t_0xDA3C6DC6 { // 0x10
   // ctor: 0x0090B390
   // init: 0x0090BCB0
    HudMenuTransitionData mSceneTransitionIn; // 0x0
    HudMenuTransitionData mSceneTransitionOut; // 0x8
};
struct TftHudScoreboardData { // 0xC
   // ctor: 0x0090BED0
   // init: 0x0090B9A0
    float_t m_0x840F5062; // 0x0
    float_t m_0x254C8137; // 0x4
    float_t m_0xF504817A; // 0x8
};
struct TftHudStageData { // 0x4
   // ctor: 0x0090B630
   // init: 0x0090BE10
    float_t m_0xA11246B8; // 0x0
};
struct TftHudUnitShopData { // 0x8
   // ctor: 0x0090B9C0
   // init: 0x0090B860
    float_t m_0x88606883; // 0x0
    float_t m_0xC38C6BA9; // 0x4
};
struct TftHudMobileDownscaleData { // 0x8
   // ctor: 0x0090B6F0
   // init: 0x0090B840
    float_t m_0xD4D2EA52; // 0x0
    float_t mDownscale; // 0x4
};
struct TftHudTunables { // 0x68
   // ctor: 0x0090C000
   // init: 0x0090B970
    TftHudAnnouncementData mAnnouncementData; // 0x4
    TftHudCombatRecapData mCombatRecapData; // 0x14
    TftHudNotificationsData mNotificationsData; // 0x20
    TftHudScoreboardData mScoreboardData; // 0x30
    TftHudStageData mStageData; // 0x3C
    HudMenuTransitionData m_0x249FE588; // 0x40
    TftHudMobileDownscaleData mMobileDownscaleData; // 0x48
    TftHudUnitShopData mUnitShopData; // 0x50
    t_0xDA3C6DC6 mZoomTransitionData; // 0x58
};
struct t_0x2610E5A7 { // 0xF0
   // ctor: 0x0090B450
   // init: 0x0090BE20
    hash_t m_0xFA144E3E; // 0x0
    hash_t ItemIcon; // 0x18
    hash_t m_0x817805A3; // 0x30
    hash_t m_0x5CDF1384; // 0x48
    hash_t m_0xBDCCEAFD; // 0x60
    hash_t m_0x14541CAC; // 0x78
    hash_t m_0xA768ACAD; // 0x90
    hash_t m_0x7AF87DDD; // 0xA8
    hash_t m_0x791B47A2; // 0xC0
    hash_t m_0x30145A7E; // 0xD8
};
struct t_0x9E2B8A86: ViewController { // 0x234
   // ctor: 0x0090BC10
   // init: 0x0090BB00
    uint32_t m_0x41AA9616; // 0x24
    uint32_t m_0x143E4D96; // 0x28
    string_t m_0xEAC10E8A; // 0x2C
    string_t m_0x8B76C33F; // 0x38
    string_t m_0x073CE2A6; // 0x44
    string_t m_0x3AD4379E; // 0x50
    string_t m_0x8FF1B151; // 0x5C
    string_t m_0xF7EE4522; // 0x68
    hash_t m_0x4BABD89D; // 0x74
    hash_t m_0xF5B8026A; // 0x8C
    hash_t m_0x0C5C5CA0; // 0xA4
    t_0x2610E5A7 m_0xF2024D92; // 0xBC
    hash_t m_0x4D302530; // 0x1AC
    hash_t m_0x5B308567; // 0x1BC
    hash_t m_0x9DCF971D; // 0x1CC
    float_t m_0xBA1D038C; // 0x1E4
    hash_t m_0x75F9CC79; // 0x1E8
};
struct TftGameStartViewController: ViewController { // 0x74
   // ctor: 0x0090BB50
   // init: 0x0090BE30
    hash_t m_0x81317EE6; // 0x28
    hash_t m_0xFC59B058; // 0x40
    hash_t m_0xF6A44AB6; // 0x58
    float_t m_0x56B85896; // 0x68
    float_t m_0x14713B68; // 0x6C
    float_t m_0x87F66219; // 0x70
};
struct t_0x1BE092EC { // 0xC0
   // ctor: 0x00932BB0
   // init: 0x00932820
    hash_t Group; // 0x0
    hash_t m_0x1C6536A1; // 0x18
    hash_t m_0x5ABAC352; // 0x30
    hash_t m_0x7748A39F; // 0x48
    hash_t m_0x4F02B933; // 0x60
    hash_t PlusIcon; // 0x78
    hash_t m_0xCD880326; // 0x90
    hash_t m_0xC67F5EF5; // 0xA8
};
struct t_0xB5E27400 { // 0x78
   // ctor: 0x00933120
   // init: 0x00932F60
    hash_t Group; // 0x0
    hash_t m_0x05DD34F6; // 0x18
    hash_t m_0x2F0C1D34; // 0x30
    hash_t m_0x868E69A1; // 0x48
    hash_t m_0xECB8BD25; // 0x60
};
struct t_0x43C3D118: ViewController { // 0x1F4
   // ctor: 0x00932A60
   // init: 0x00932C80
    int32_t m_0x38E9F9EC; // 0x24
    int32_t m_0x39E9FB7F; // 0x28
    string_t m_0xA05CACAA; // 0x2C
    string_t m_0x1257D9A3; // 0x38
    hash_t m_0xAF939497; // 0x44
    hash_t m_0xE5E1D1D7; // 0x5C
    hash_t m_0xA1A15B6F; // 0x74
    t_0xB5E27400 m_0x92831268; // 0x8C
    t_0x1BE092EC m_0x0AAD6573; // 0x104
    hash_t Scene; // 0x1C4
};
struct t_0x2781ED6B { // 0x18
   // ctor: 0x00608150
   // init: 0x00607E90
    string_t TitleKey; // 0x0
    string_t BodyKey; // 0xC
};
struct TftUnitShopViewController: ViewController { // 0x2A0
   // ctor: 0x00932E80
   // init: 0x009329C0
    hash_t m_0xA0AE7CFA; // 0x110
    float_t m_0xC43A3D1F; // 0x14C
    hash_t ToggleShopButton; // 0x15C
    hash_t LockButton; // 0x19C
    hash_t BuyExpButton; // 0x1E0
    hash_t RerollButton; // 0x210
    hash_t InfoButton; // 0x240
    map_t<uint32_t, t_0x2781ED6B> m_0x2781ED6B; // 0x294
};
struct ObjectTags { // 0x18
   // ctor: 0x00932E40
   // init: 0x00608DA0
    string_t mTagList; // 0x8
};
struct NumberFormattingBehavior { // 0x8
   // ctor: 0x00933030
   // init: 0x00932AE0
    uint32_t m_0x6A015824; // 0x0
    bool m_0x9892A348; // 0x4
    bool m_0x35FEAE85; // 0x5
};
struct NumberFormattingData { // 0xCC
   // ctor: 0x00932C90
   // init: 0x00932DF0
    string_t m_0x5B862D47; // 0x0
    string_t m_0xD183213B; // 0xC
    string_t m_0xB995FB1F; // 0x18
    string_t m_0x40F5BD16; // 0x24
    string_t m_0xEDD8EA83; // 0x30
    string_t m_0x31169DFF; // 0x3C
    string_t m_0xE4F5BDCE; // 0x48
    string_t m_0x012DE6EC; // 0x54
    string_t m_0x70177BF1; // 0x60
    string_t m_0xB0C63265; // 0x6C
    string_t m_0x89A709FB; // 0x78
    string_t m_0xF3EE8811; // 0x84
    string_t m_0xEF853971; // 0x90
    string_t m_0xFD7C73B7; // 0x9C
    string_t m_0xDD2FCD42; // 0xA8
    string_t m_0xC3310CDA; // 0xB4
    map_t<hash_t, link_ptr_t<NumberFormattingBehavior>> m_0x7A4D89BB; // 0xC0
};
struct AnnouncementDefinitionData { // 0x80
   // ctor: 0x00932EC0
   // init: 0x00932C00
    uint16_t Priority; // 0x0
    bool CanBeMadeObsolete; // 0x2
    bool MakeLowerPriorityEventsObsolete; // 0x3
    link_ptr_t<AnnouncementStyleBasic> Style; // 0x4
    string_t TextKey; // 0x8
    string_t ChatMessageKey; // 0x14
    string_t SoundKey; // 0x20
    string_t SpectatorSoundKey; // 0x2C
    hash_t CommonElements; // 0x38
    hash_t AlliedElements; // 0x50
    hash_t EnemyElements; // 0x68
};
struct AnnouncementDefinition { // 0x8C
   // ctor: 0x00932A80
   // init: 0x00932C20
    AnnouncementDefinitionData DefaultData; // 0x0
    map_t<string_t, AnnouncementDefinitionData> MutatorOverrides; // 0x80
};
struct t_0x78387EB5: AnnouncementDefinition { // 0x8C
   // ctor: 0x00932A80
   // init: 0x00932C20
};
struct AnnouncementStyleBasic { // 0x30
   // ctor: 0x009330B0
   // init: 0x00933140
    hash_t TextField; // 0x4
    float_t MinAnnouncementDuration; // 0x1C
    HudMenuTransitionData m_0x3F43172E; // 0x20
    HudMenuTransitionData m_0xCC99A2DB; // 0x28
};
struct t_0x48C9FF38: AnnouncementStyleBasic { // 0x34
   // ctor: 0x00932E20
   // init: 0x00932810
    link_ptr_t<AnnouncementIcon> SourceIcon; // 0x30
};
struct t_0xAA95A271: AnnouncementStyleBasic { // 0x38
   // ctor: 0x00932EA0
   // init: 0x00932F70
    link_ptr_t<AnnouncementIcon> LeftIcon; // 0x30
    link_ptr_t<AnnouncementIcon> RightIcon; // 0x34
};
struct AnnouncementIcon { // 0xD8
   // ctor: 0x00932920
   // init: 0x00932C10
    hash_t m_0x108E8710; // 0x0
    hash_t m_0xC2E2A2DF; // 0x18
    hash_t m_0x3E37C63B; // 0x30
    hash_t AlliedElementGroup; // 0x48
    hash_t EnemyElementGroup; // 0x60
    hash_t m_0xDD749512; // 0x78
    hash_t m_0xDE7496A5; // 0x90
    hash_t m_0xDB7491EC; // 0xA8
    hash_t m_0xDC74937F; // 0xC0
};
struct AnnouncementMap { // 0x48
   // ctor: 0x00932740
   // init: 0x00932A50
    link_ptr_t<AnnouncementMap> ParentList; // 0x0
    string_t m_0x81082E4B; // 0x4
    hash_t m_0x79175E85; // 0x10
    hash_t m_0xCF8C591B; // 0x28
    map_t<string_t, link_ptr_t<AnnouncementDefinition>> Announcements; // 0x40
};
struct AnnouncementsViewController: ViewController { // 0x4C
   // ctor: 0x00932FC0
   // init: 0x00932760
    hash_t m_0x34B17566; // 0x18
};
struct InvalidDeviceViewController: ViewController { // 0x2C
   // ctor: 0x00932B00
   // init: 0x00932F80
    hash_t Scene; // 0x18
};
struct LoginViewController: ViewController { // 0x1B0
   // ctor: 0x00932FF0
   // init: 0x00932DE0
};
struct PatchingViewController: ViewController { // 0x198
   // ctor: 0x00932F20
   // init: 0x00932F10
    hash_t Scene; // 0x1C
    hash_t BeginPatchingButtonDefinition; // 0x168
    hash_t OpenTeamPlannerButtonDefinition; // 0x174
};
struct SummonerNameCreateViewController: ViewController { // 0x10C
   // ctor: 0x009328C0
   // init: 0x00932FE0
    HudMenuTransitionData m_0x2992FE27; // 0x24
    hash_t m_0x4D302530; // 0x2C
    hash_t SubmitButtonDefinition; // 0x54
    hash_t m_0x315B9A19; // 0x64
};
struct t_0x13A37F3E { // 0x168
   // ctor: 0x009328E0
   // init: 0x009327C0
    hash_t Group; // 0x0
    hash_t Icon; // 0x18
    hash_t m_0xBDE64E3E; // 0x30
    hash_t m_0x43B27471; // 0x48
    array_t<hash_t, 3> m_0x7D3EF18B; // 0x60
    array_t<hash_t, 3> m_0x2DE82D6A; // 0xA8
    array_t<hash_t, 5> m_0xCEA0AF0E; // 0xF0
};
struct t_0x60764292 { // 0x60
   // ctor: 0x00932900
   // init: 0x00932730
    hash_t Group; // 0x0
    hash_t m_0x43B27471; // 0x18
    hash_t m_0xE83ED618; // 0x30
    hash_t m_0x84F92B5A; // 0x48
};
struct TftTeamPlannerViewController: ViewController { // 0x3F4
   // ctor: 0x00932F40
   // init: 0x00932BA0
    float_t m_0x6EE3BD2E; // 0x20
    ViewPaneDefinition ViewPaneDefinition; // 0x24
    t_0x13A37F3E m_0x374D847E; // 0x9C
    hash_t m_0x160A8B77; // 0x204
    t_0x60764292 m_0xAD64DC55; // 0x21C
    hash_t m_0x387116C1; // 0x27C
    hash_t ChampionButtonTemplate; // 0x294
    hash_t m_0x88CA9D2D; // 0x2A0
    hash_t CloseButton; // 0x2B8
    hash_t m_0xC6E9FBEA; // 0x2D0
    uint8_t ChampionsPerRow; // 0x2E8
    uint8_t TraitsPerRow; // 0x2E9
    hash_t Scene; // 0x2EC
    hash_t m_0x807EF97F; // 0x38C
};
struct ChatViewController: ViewController { // 0x728
   // ctor: 0x00932D60
   // init: 0x009327B0
    uint8_t DefaultWordWrapMargin; // 0x30
    float_t HideAfterSeconds; // 0x34
    ViewPaneDefinition ViewPaneDefinition; // 0x38
    hash_t SceneChat; // 0x5B4
    hash_t m_0x8284EBB3; // 0x5C4
    hash_t m_0xBC8C4EED; // 0x5D4
};
struct VfxProbabilityTableDataGrande: ViewController { // 0x1D8
   // ctor: 0x009327F0
   // init: 0x00932A40
    hash_t Scene; // 0x1C
    hash_t Backdrop; // 0x2C
    float_t AuthoredWidth; // 0x1BC
    float_t SourceResolutionWidth; // 0x1C0
};
struct MessageBoxDialog: t_0x75259AD3 { // 0x280
   // ctor: 0x0096FEF0
   // init: 0x0096FC70
    hash_t m_0x131C35C5; // 0xDC
    hash_t m_0x070020AB; // 0xF4
    hash_t m_0x31DFF863; // 0x10C
    hash_t m_0x006FD80C; // 0x124
    hash_t m_0xAB91BA1F; // 0x13C
    hash_t m_0x315B9A19; // 0x14C
    HudMenuTransitionData m_0x2992FE27; // 0x1C4
    t_0x63394A54 m_0x985233B8; // 0x1CC
    t_0x63394A54 m_0x1347D194; // 0x220
};
struct t_0x75259AD3: ViewController { // 0x7C
   // ctor: 0x0096FBE0
   // init: 0x0096F570
    hash_t CloseButtonDefinition; // 0x20
    hash_t ConfirmButtonDefinition; // 0x38
    hash_t CancelButtonDefinition; // 0x50
    hash_t ContentScene; // 0x68
    unique_ptr_t<ViewPaneDefinition> ViewPaneDefinition; // 0x78
};
struct t_0x5CE1431E { // 0x5C
   // ctor: 0x0096F5F0
   // init: 0x0096F110
    hash_t Scene; // 0x34
    hash_t m_0xD36508CD; // 0x44
};
struct CursorData { // 0x38
   // ctor: 0x0096F2E0
   // init: 0x0096FDE0
    point2D_t mHotSpot; // 0x0
    string_t mTextureName; // 0x8
    string_t mColorblindTextureName; // 0x14
    string_t m_0xD240CE4F; // 0x20
    string_t m_0xF6536C51; // 0x2C
};
struct CursorDataTeamContext { // 0xA8
   // ctor: 0x0096FBC0
   // init: 0x0096FC90
    array_t<CursorData, 3> mData; // 0x0
};
struct CursorDataCaptureCooldownContext { // 0x188
   // ctor: 0x0096F870
   // init: 0x0096F5D0
    array_t<CursorData, 7> mData; // 0x0
};
struct CursorConfig { // 0x5D0
   // ctor: 0x0096F980
   // init: 0x0096FD60
    array_t<CursorData, 10> mSingleContextCursors; // 0x20
    array_t<CursorDataTeamContext, 3> mTeamContextCursors; // 0x250
    CursorDataCaptureCooldownContext mHoverNotUseableCursor; // 0x448
};
struct t_0x8CB19EB5: ViewController { // 0x60
   // ctor: 0x0096FF10
   // init: 0x0096F360
};
struct HealthbarImageInfo { // 0x78
   // ctor: 0x0096F3D0
   // init: 0x0096F010
    string_t mTextureName; // 0x0
    point2D_t mOffset; // 0xC
    point4D_t mTextureUvs; // 0x14
};
struct UnitStatusData { // 0x98
   // ctor: 0x0096F2C0
   // init: 0x0096FA30
    uint32_t LocType; // 0x0
    uint32_t AttackableUnitStatusType; // 0x4
    string_t StatusName; // 0xC
    optional_t<color_t> TextColor; // 0x18
    HealthbarImageInfo ImageInfo; // 0x20
};
struct UnitStatusPriorityList { // 0x10
   // ctor: 0x0096FB40
   // init: 0x0096F610
    vector_t<UnitStatusData> mPrioritizedUnitStatusData; // 0x0
    float_t mMinimumDisplayTime; // 0xC
};
struct FloatTextIconData { // 0x24
   // ctor: 0x0096F1B0
   // init: 0x0096F9E0
    string_t mIconFileName; // 0x0
    color_t mColor; // 0xC
    point2D_t mDisplaySize; // 0x10
    point2D_t mOffset; // 0x18
    uint32_t mAlignment; // 0x20
};
struct FloatTextDisplayOverrides { // 0x88
   // ctor: 0x0096FC00
   // init: 0x0096FD40
    optional_t<int32_t> Priority; // 0x0
    optional_t<int32_t> MaxInstances; // 0x4
    optional_t<bool> IsAnimated; // 0x8
    optional_t<bool> DisableHorizontalReverse; // 0x9
    optional_t<bool> DisableVerticalReverse; // 0xA
    optional_t<bool> MomentumFromHit; // 0xB
    optional_t<bool> FollowSource; // 0xC
    optional_t<bool> IgnoreCombineRules; // 0xD
    optional_t<bool> IgnoreQueue; // 0xE
    optional_t<bool> AlternateRightLeft; // 0xF
    optional_t<bool> CombinableCounterDisplay; // 0x10
    optional_t<int32_t> CombinableCounterCategory; // 0x14
    optional_t<bool> OverwritePreviousNumber; // 0x18
    optional_t<float_t> ExtendTimeOnNewDamage; // 0x1C
    optional_t<float_t> MaxLifeTime; // 0x20
    optional_t<int32_t> ColorOffsetR; // 0x24
    optional_t<int32_t> ColorOffsetG; // 0x28
    optional_t<int32_t> ColorOffsetB; // 0x2C
    optional_t<float_t> Decay; // 0x30
    optional_t<float_t> DecayDelay; // 0x34
    optional_t<float_t> Scale; // 0x38
    optional_t<float_t> ShrinkTime; // 0x3C
    optional_t<float_t> ShrinkScale; // 0x40
    optional_t<float_t> HangTime; // 0x44
    optional_t<float_t> RandomOffsetMinX; // 0x48
    optional_t<float_t> RandomOffsetMaxX; // 0x4C
    optional_t<float_t> RandomOffsetMinY; // 0x50
    optional_t<float_t> RandomOffsetMaxY; // 0x54
    optional_t<float_t> StartOffsetX; // 0x58
    optional_t<float_t> StartOffsetY; // 0x5C
    optional_t<float_t> RelativeOffsetMin; // 0x60
    optional_t<float_t> RelativeOffsetMax; // 0x64
    optional_t<float_t> MinXVelocity; // 0x68
    optional_t<float_t> MaxXVelocity; // 0x6C
    optional_t<float_t> MinYVelocity; // 0x70
    optional_t<float_t> MaxYVelocity; // 0x74
    optional_t<float_t> ContinualForceX; // 0x78
    optional_t<float_t> ContinualForceY; // 0x7C
    optional_t<float_t> GrowthXScalar; // 0x80
    optional_t<float_t> GrowthYScalar; // 0x84
};
struct FloatingTextTunables { // 0x38
   // ctor: 0x0096FF30
   // init: 0x0096F370
    float_t mAnimatedTextQueueDelay; // 0x0
    float_t mIntervalInPix; // 0x4
    float_t mScrollSpeed; // 0x8
    uint32_t mMaxFloatingTextItems; // 0xC
    float_t mMinimumDynamicScale; // 0x10
    float_t mMaximumDynamicScale; // 0x14
    float_t mYResolutionBaseline; // 0x18
    float_t m_0xCCF713A7; // 0x1C
    float_t m_0xF56F095C; // 0x20
    float_t mMinionComparisonMultiplier; // 0x24
    float_t mLocalPlayerHealthComparison; // 0x28
    vector_t<float_t> mComparisonByLevel; // 0x2C
};
struct FloatingTextDamageDisplayTypeList { // 0x44
   // ctor: 0x0096F490
   // init: 0x0096FCA0
    link_ptr_t<FloatTextDisplayOverrides> Default; // 0x0
    link_ptr_t<FloatTextDisplayOverrides> Impact; // 0x4
    link_ptr_t<FloatTextDisplayOverrides> Zone; // 0x8
    link_ptr_t<FloatTextDisplayOverrides> Ult; // 0xC
    link_ptr_t<FloatTextDisplayOverrides> DotNoCombine; // 0x10
    link_ptr_t<FloatTextDisplayOverrides> Dot; // 0x14
    link_ptr_t<FloatTextDisplayOverrides> DotSlow; // 0x18
    link_ptr_t<FloatTextDisplayOverrides> Multistrike; // 0x1C
    link_ptr_t<FloatTextDisplayOverrides> MultistrikeFast; // 0x20
    link_ptr_t<FloatTextDisplayOverrides> MultistrikeSlow; // 0x24
    link_ptr_t<FloatTextDisplayOverrides> PlayerMinion; // 0x28
    link_ptr_t<FloatTextDisplayOverrides> BarrackMinion; // 0x2C
    link_ptr_t<FloatTextDisplayOverrides> Mini; // 0x30
    link_ptr_t<FloatTextDisplayOverrides> SelfTrueDamageCounter; // 0x34
    link_ptr_t<FloatTextDisplayOverrides> SelfPhysicalDamageCounter; // 0x38
    link_ptr_t<FloatTextDisplayOverrides> SelfMagicalDamageCounter; // 0x3C
};
struct FloatTextFormattingData { // 0xE8
   // ctor: 0x0096F850
   // init: 0x0096F230
    hash_t mTypeName; // 0x0
    float_t Decay; // 0xC
    link_ptr_t<GameFontDescription> mFontDescription; // 0x10
    int32_t ColorOffsetR; // 0x20
    int32_t ColorOffsetG; // 0x24
    int32_t ColorOffsetB; // 0x28
    string_t CombinableNumberFormat; // 0x34
    string_t CombinableNegativeNumberFormat; // 0x40
    int32_t Priority; // 0x4C
    float_t Height; // 0x50
    float_t DecayDelay; // 0x54
    bool Disabled; // 0x59
    bool IsAnimated; // 0x5A
    bool MomentumFromHit; // 0x5B
    bool FollowSource; // 0x5C
    bool DisableHorizontalReverse; // 0x5D
    bool DisableVerticalReverse; // 0x5E
    bool CombinableCounterDisplay; // 0x5F
    bool OverwritePreviousNumber; // 0x60
    int32_t CombinableCounterCategory; // 0x64
    float_t MinXVelocity; // 0x68
    float_t MaxXVelocity; // 0x6C
    float_t MinYVelocity; // 0x70
    float_t MaxYVelocity; // 0x74
    float_t StartOffsetX; // 0x78
    float_t StartOffsetY; // 0x7C
    float_t HangTime; // 0x80
    float_t RandomStartOffsetMinX; // 0x88
    float_t RandomStartOffsetMaxX; // 0x8C
    float_t RandomStartOffsetMinY; // 0x90
    float_t RandomStartOffsetMaxY; // 0x94
    float_t GrowthYScalar; // 0x98
    float_t GrowthXScalar; // 0x9C
    float_t RelativeOffsetMin; // 0xA0
    float_t RelativeOffsetMax; // 0xA4
    float_t ContinualForceX; // 0xA8
    float_t ContinualForceY; // 0xAC
    float_t ContinualForceXBase; // 0xB0
    float_t ContinualForceYBase; // 0xB4
    float_t ShrinkTime; // 0xB8
    float_t Scale; // 0xBC
    float_t ExtendTimeOnNewDamage; // 0xC0
    float_t MaxLifeTime; // 0xC4
    bool IgnoreQueue; // 0xC8
    bool AlternateRightLeft; // 0xC9
    bool IgnoreCombineRules; // 0xCA
    int32_t MaxInstances; // 0xCC
    float_t ShrinkScale; // 0xD0
    bool RefreshExisting; // 0xD4
    bool AttachToHealthBar; // 0xD5
    bool OffsetByBoundingBox; // 0xD6
    uint8_t HorizontalAlignment; // 0xD7
    uint8_t VerticalAlignment; // 0xD8
    vector_t<FloatTextIconData> Icons; // 0xDC
};
struct FloatingTextTypeList { // 0x94
   // ctor: 0x0096FB70
   // init: 0x0096F6F0
    link_ptr_t<FloatTextFormattingData> Invulnerable; // 0x0
    link_ptr_t<FloatTextFormattingData> Special; // 0x4
    link_ptr_t<FloatTextFormattingData> Heal; // 0x8
    link_ptr_t<FloatTextFormattingData> ManaHeal; // 0xC
    link_ptr_t<FloatTextFormattingData> ManaDamage; // 0x10
    link_ptr_t<FloatTextFormattingData> Dodge; // 0x14
    link_ptr_t<FloatTextFormattingData> PhysicalDamageCritical; // 0x18
    link_ptr_t<FloatTextFormattingData> MagicalDamageCritical; // 0x1C
    link_ptr_t<FloatTextFormattingData> TrueDamageCritical; // 0x20
    link_ptr_t<FloatTextFormattingData> Experience; // 0x24
    link_ptr_t<FloatTextFormattingData> Gold; // 0x28
    link_ptr_t<FloatTextFormattingData> Level; // 0x2C
    link_ptr_t<FloatTextFormattingData> Disable; // 0x30
    link_ptr_t<FloatTextFormattingData> QuestReceived; // 0x34
    link_ptr_t<FloatTextFormattingData> QuestComplete; // 0x38
    link_ptr_t<FloatTextFormattingData> Score; // 0x3C
    link_ptr_t<FloatTextFormattingData> PhysicalDamage; // 0x40
    link_ptr_t<FloatTextFormattingData> MagicalDamage; // 0x44
    link_ptr_t<FloatTextFormattingData> TrueDamage; // 0x48
    link_ptr_t<FloatTextFormattingData> EnemyPhysicalDamage; // 0x4C
    link_ptr_t<FloatTextFormattingData> EnemyMagicalDamage; // 0x50
    link_ptr_t<FloatTextFormattingData> EnemyTrueDamage; // 0x54
    link_ptr_t<FloatTextFormattingData> EnemyPhysicalDamageCritical; // 0x58
    link_ptr_t<FloatTextFormattingData> EnemyMagicalDamageCritical; // 0x5C
    link_ptr_t<FloatTextFormattingData> EnemyTrueDamageCritical; // 0x60
    link_ptr_t<FloatTextFormattingData> Countdown; // 0x64
    link_ptr_t<FloatTextFormattingData> Omw; // 0x68
    link_ptr_t<FloatTextFormattingData> Absorbed; // 0x6C
    link_ptr_t<FloatTextFormattingData> Debug; // 0x70
    link_ptr_t<FloatTextFormattingData> PracticeToolTotal; // 0x74
    link_ptr_t<FloatTextFormattingData> PracticeToolLastHit; // 0x78
    link_ptr_t<FloatTextFormattingData> PracticeToolDps; // 0x7C
    link_ptr_t<FloatTextFormattingData> ScoreDarkStar; // 0x80
    link_ptr_t<FloatTextFormattingData> ScoreProject0; // 0x84
    link_ptr_t<FloatTextFormattingData> ScoreProject1; // 0x88
    link_ptr_t<FloatTextFormattingData> ShieldBonusDamage; // 0x8C
    link_ptr_t<FloatTextFormattingData> TftUnitLabel; // 0x90
};
struct FloatingTextGlobalConfig { // 0x110
   // ctor: 0x0096FE90
   // init: 0x0096FD50
    FloatingTextTunables mTunables; // 0x0
    FloatingTextDamageDisplayTypeList mDamageDisplayTypes; // 0x38
    FloatingTextTypeList mFloatingTextTypes; // 0x7C
};
struct FloatingTextOverride { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    map_t<uint32_t, bool> OverriddenFloatingTextTypes; // 0x0
};
struct HudColorData { // 0x13C
   // ctor: 0x0096FDA0
   // init: 0x0096FC60
    color_t mSelfColor; // 0x0
    color_t mFriendlyColor; // 0x4
    color_t mEnemyColor; // 0x8
    color_t mNeutralColor; // 0xC
    color_t mOrderColor; // 0x10
    color_t mChaosColor; // 0x14
    color_t mJunglePlantColor; // 0x18
    color_t mFriendlyLaneMinionBarColor; // 0x1C
    color_t mEnemyLaneMinionBarColor; // 0x20
    color_t mDeathFriendlyTeamColor; // 0x24
    color_t mDeathEnemyTeamColor; // 0x28
    color_t mDeathOrderColor; // 0x2C
    color_t mDeathChaosColor; // 0x30
    color_t mInputChatColor; // 0x34
    color_t mShadowChatColor; // 0x38
    color_t mFriendlyChatColor; // 0x3C
    color_t mAllChatColor; // 0x40
    color_t mEnemyChatColor; // 0x44
    color_t mNeutralChatColor; // 0x48
    color_t mPingChatColor; // 0x4C
    color_t mTeamChatColor; // 0x50
    color_t mNetworkChatColor; // 0x54
    color_t mOrderChatColor; // 0x58
    color_t mChaosChatColor; // 0x5C
    color_t mGoldChatColor; // 0x60
    color_t mTimestampChatColor; // 0x64
    color_t mWhisperColor; // 0x68
    color_t mPartyChatColor; // 0x6C
    color_t mPlatformChatColor; // 0x70
    color_t mFeedbackChatColor; // 0x74
    color_t mItemCalloutBodyColor; // 0x78
    color_t mItemCalloutItemColor; // 0x7C
    color_t mMarkedIndicatorColor; // 0x80
    color_t mSelectedIndicatorColor; // 0x84
    color_t mHighlightedIndicatorColor; // 0x88
    color_t mItemHotKeyEnabledColor; // 0x8C
    color_t mItemHotKeyDisabledColor; // 0x90
    color_t mSpellHotKeyEnabledColor; // 0x94
    color_t mSpellHotKeyDisabledColor; // 0x98
    color_t mStatNormalColor; // 0x9C
    color_t mStatBoostedColor; // 0xA0
    color_t mLevelUpColor; // 0xA4
    color_t mEvolutionColor; // 0xA8
    color_t mSummonerNameDeadColor; // 0xAC
    color_t mSummonerNameDefaultColor; // 0xB0
    color_t mSummonerNameSelfColor; // 0xB4
    color_t mClubTagFriendlyChatColor; // 0xB8
    color_t mClubTagEnemyChatColor; // 0xBC
    color_t mClubTagNeutralChatColor; // 0xC0
    color_t mClubTagOrderChatColor; // 0xC4
    color_t mClubTagChaosChatColor; // 0xC8
    color_t mVoiceChatDefaultTextColor; // 0xCC
    color_t mVoiceChatHoverTextColor; // 0xD0
    color_t mVoiceChatHaloTextureColor; // 0xD4
    color_t m_0x03CA4E54; // 0xD8
    color_t m_0xDFD9F7A0; // 0xDC
    color_t m_0xD614AA57; // 0xE0
    color_t VoteEmptyColor; // 0xE4
    color_t m_0x51C13AD7; // 0xE8
    color_t VoteNocolor; // 0xEC
    color_t m_0x3F68EFB8; // 0xF0
    color_t m_0xCD9CB6C5; // 0xF4
    color_t m_0xC14D71DC; // 0xF8
    color_t m_0x9487808B; // 0xFC
    color_t m_0x0FC46842; // 0x100
    color_t m_0x3B64DFE3; // 0x104
    color_t m_0x672CCD56; // 0x108
    array_t<color_t, 5> m_0x9316F661; // 0x10C
    color_t m_0x30C22182; // 0x120
    color_t m_0xEE9A2886; // 0x124
    color_t m_0xC09CCDD8; // 0x128
    color_t m_0x24EB55A3; // 0x12C
    color_t m_0x2F02AF61; // 0x130
    color_t m_0xCA1D9872; // 0x134
};
struct HudFeedbackDamageData { // 0x20
   // ctor: 0x0096FA80
   // init: 0x00970010
    float_t mPercentageDamageForFlash; // 0x0
    float_t mOverTimeForFlashSeconds; // 0x4
    float_t mMaxPercentageForMostReadHealth; // 0x8
    float_t mFlashDuration; // 0xC
    float_t mStartFlashAlpha; // 0x10
    float_t mLowHealthFlashThresholdPercentage; // 0x14
    float_t mLowHealthFlashDuration; // 0x18
    float_t mLowHealthFlashOpacityStrength; // 0x1C
};
struct TeamScoreMeterUiTunables { // 0x48
   // ctor: 0x0096FB10
   // init: 0x0096F730
    HudMenuTransitionData mSceneTransition; // 0x0
    array_t<HudTeamScoreMeterProperties, 2> mTeamScoreMeterProperties; // 0x8
    uint32_t mTeamScoreMeterMaxRoundsPerTeam; // 0x40
    bool mAllowDynamicVisibility; // 0x44
    bool mCountdownTimer; // 0x45
    uint8_t m_0xDFF2794F; // 0x46
};
struct HudTeamScoreMeterProperties { // 0x1C
   // ctor: 0x0096F150
   // init: 0x0096F300
    uint8_t mTeamScoreMeterType; // 0x0
    bool mShowScoreText; // 0x1
    string_t m_0x86864FBC; // 0x4
    string_t m_0x6044A790; // 0x10
};
struct EncounterUiTunables { // 0x50
   // ctor: 0x0096FD80
   // init: 0x0096FDF0
    HudMenuTransitionData mSceneTransition; // 0x0
    float_t mProgressBarEaseRate; // 0x8
    string_t mProgressMeterSuffix; // 0xC
    string_t mTimerMeterSuffix; // 0x18
    float_t mUnitBarFadeSpeed; // 0x24
    bool m_0x3FC8ECEC; // 0x28
    string_t mProgressMeterHoverText; // 0x2C
    string_t mProgressMeterPingText; // 0x38
    string_t mPipsHoverText; // 0x44
};
struct QuestUiTunables { // 0x8
   // ctor: 0x0096F120
   // init: 0x0096F340
    HudMenuTransitionData mSceneTransition; // 0x0
};
struct DragonUiTunables { // 0x10
   // ctor: 0x0096F6C0
   // init: 0x0096F6A0
    uint8_t mSlots; // 0x0
    vector_t<string_t> mDragonBaseNames; // 0x4
};
struct HudGameModeScoreData { // 0x50
   // ctor: 0x0096F4F0
   // init: 0x0096F820
    vector_t<uint8_t> mTeamScoreElementTypes; // 0x0
    vector_t<uint8_t> mIndividualScoreElementTypes; // 0xC
    string_t mModeKeyName; // 0x18
    string_t mTeamGameScorePingMessage; // 0x24
    unique_ptr_t<TeamScoreMeterUiTunables> mTeamScoreMeterUi; // 0x30
    unique_ptr_t<EncounterUiTunables> mEncounterUi; // 0x34
    unique_ptr_t<HudTeamFightData> mTeamFightUi; // 0x38
    unique_ptr_t<QuestUiTunables> mQuestUi; // 0x3C
    unique_ptr_t<DragonUiTunables> mDragonUi; // 0x40
    vector_t<HudOptionalBinData> mOptionalBins; // 0x44
};
struct MinimapIconTextureData { // 0x24
   // ctor: 0x0096FF50
   // init: 0x0096F060
    string_t mBase; // 0x0
    optional_t<string_t> mColorblind; // 0xC
};
struct MinimapIconColorData { // 0xC
   // ctor: 0x0096F3A0
   // init: 0x0096FA40
    color_t mBase; // 0x0
    optional_t<color_t> mColorblind; // 0x4
};
struct MinimapIcon { // 0x5C
   // ctor: 0x0096FDC0
   // init: 0x0096F4C0
    bool mRelativeTeams; // 0x0
    point2D_t mSize; // 0x4
    float_t mMinScale; // 0xC
    float_t mMaxScale; // 0x10
    MinimapIconTextureData mBaseTexture; // 0x14
    map_t<uint8_t, MinimapIconTextureData> mTeamTextures; // 0x38
    MinimapIconColorData mBaseColor; // 0x44
    map_t<uint8_t, MinimapIconColorData> mTeamColors; // 0x50
};
struct MinimapData { // 0x70
   // ctor: 0x0096F840
   // init: 0x0096F580
    map_t<uint8_t, MinimapIcon> mIcons; // 0x5C
    map_t<hash_t, MinimapIcon> mCustomIcons; // 0x68
};
struct HudOptionalBinData { // 0x10
   // ctor: 0x00607F40
   // init: 0x00608200
    string_t mName; // 0x0
    uint32_t mPriority; // 0xC
};
struct HudTunables { // 0x3C8
   // ctor: 0x009AEDC0
   // init: 0x009AE0A0
    HudScaleSettingsData mScaleSettings; // 0x4
    HudLevelUpData mLevelUpTransitionData; // 0x2C
    HudReplayData mReplayData; // 0x4C
    HudElementalSectionUiData mElementalSelectionAnimationData; // 0x60
    HudEmotePopupData mEmotePopupData; // 0x98
    HudGearSelectionUiData mGearSelectionData; // 0xD0
    HudRadialWheelData mRadailWheelData; // 0xF0
    HudCheatMenuData mCheatMenuData; // 0x10C
    HudPingData mPingData; // 0x118
    HudMenuTransitionData mGameScoreboardTransitionData; // 0x120
    HudMenuTransitionData mReplayScoreboardTransitionData; // 0x128
    HudMenuTransitionData mReplayGameStatsTransitionData; // 0x134
    HudBannerData m_0x9CEC9FF0; // 0x13C
    HudAbilityPromptData m_0x4E7D3049; // 0x160
    HudVoiceChatData mVoiceChatData; // 0x178
    HudInputBoxData mInputBoxData; // 0x17C
    HudHealthBarData mHealthBarData; // 0x19C
    HudLoadingScreenData mLoadingScreenData; // 0x258
    HudStatPanelStatStoneData mStatPanelStatStoneData; // 0x274
    HudStatStoneData mStatStoneData; // 0x2A0
    HudStatStoneDeathRecapData mStatStoneDeathRecapData; // 0x2C0
    HudStatStoneMilestoneData StatStoneMilestoneData; // 0x2E0
    HudEndOfGameData mEndOfGameData; // 0x348
    HudMessageDisplayData m_0x86402ADF; // 0x358
    HudMessageDisplayData m_0x48C75042; // 0x368
    HudSpellSlotResetFeedbackData mHudSpellSlotResetFeedbackData; // 0x378
    HudDamageDisplayData DamageDisplayData; // 0x384
    HudFightRecapUiData FightRecapUiData; // 0x388
};
struct HudScaleSettingsData { // 0x28
   // ctor: 0x009AF2C0
   // init: 0x009AFBA0
    float_t MaximumGlobalScale; // 0x0
    float_t MinimumGlobalScale; // 0x4
    float_t MaximumMinimapScale; // 0x8
    float_t MinimumMinimapScale; // 0xC
    float_t m_0x6B8896B6; // 0x10
    float_t m_0xB565CF40; // 0x14
    float_t MaximumPracticeToolScale; // 0x18
    float_t MinimumPracticeToolScale; // 0x1C
    float_t MaximumChatScale; // 0x20
    float_t MinimumChatScale; // 0x24
};
struct HudLevelUpData { // 0x20
   // ctor: 0x009AF8B0
   // init: 0x009AEF00
    uint8_t MinAlpha; // 0x0
    uint8_t MaxAlpha; // 0x1
    float_t MaxOffset; // 0x4
    float_t AnimTime; // 0x8
    float_t Delay; // 0xC
    float_t Overshoot; // 0x10
    float_t Inertia; // 0x14
    float_t PlayerBuffsOffset; // 0x18
    float_t IdleSheenInterval; // 0x1C
};
struct HudBannerData { // 0x24
   // ctor: 0x009AF740
   // init: 0x009AF9E0
    float_t TransitionTime; // 0x0
    uint8_t TransitionMinAlpha; // 0x4
    uint8_t TransitionMaxAlpha; // 0x5
    point2D_t TransitionOffset; // 0x8
    point2D_t PulseOffset; // 0x10
    float_t PulseTime; // 0x18
    float_t PulseDuration; // 0x1C
    float_t PulseInterval; // 0x20
};
struct HudAbilityPromptData { // 0x18
   // ctor: 0x009AF3D0
   // init: 0x009AE920
    color_t PulseStartColor; // 0x0
    color_t PulseEndColor; // 0x4
    point2D_t PulseOffset; // 0x8
    float_t PulseTime; // 0x10
    float_t PulseInterval; // 0x14
};
struct HudMenuTransitionData { // 0x8
   // ctor: 0x0096F120
   // init: 0x0096F340
    float_t TransitionTime; // 0x0
    uint8_t MinAlpha; // 0x4
    uint8_t MaxAlpha; // 0x5
    uint8_t EasingType; // 0x6
};
struct HudElementalSectionUiData { // 0x38
   // ctor: 0x009AE960
   // init: 0x009AEE30
    color_t AirColoration; // 0x0
    color_t FireColoration; // 0x4
    color_t EarthColoration; // 0x8
    color_t WaterColoration; // 0xC
    color_t DarkColoration; // 0x10
    color_t FairyColoration; // 0x14
    color_t IceColoration; // 0x18
    color_t LightColoration; // 0x1C
    color_t MagmaColoration; // 0x20
    color_t StormColoration; // 0x24
    float_t MeterFilledButtonFadeInDelay; // 0x28
    float_t FirstSelectionAnimationDelay; // 0x2C
    float_t SecondSelectionAnimationDelay; // 0x30
    float_t GlowingRingCycleTime; // 0x34
};
struct HudEmotePopupData { // 0x38
   // ctor: 0x009AF910
   // init: 0x009AE280
    HudMenuTransitionData mEmotePopupTransitionIntro; // 0x0
    HudMenuTransitionData mEmotePopupTransitionOutro; // 0x8
    string_t mUiSound; // 0x10
    float_t mEmotePopupDisplayTime; // 0x1C
    float_t m_0x728D935F; // 0x20
    float_t m_0x07CD0D83; // 0x24
    float_t m_0x75D54C28; // 0x28
    float_t m_0xF680B7D9; // 0x2C
    float_t m_0x6BD76883; // 0x30
    bool mEmoteFloatEnabled; // 0x34
};
struct HudGearSelectionUiData { // 0x20
   // ctor: 0x009AFB40
   // init: 0x009AD400
    HudMenuTransitionData mGearSelectionTransitionIntro; // 0x0
    HudMenuTransitionData mGearSelectionTransitionOutro; // 0x8
    float_t SelectionButtonDelayTime; // 0x10
    bool TimerEnabled; // 0x14
    float_t TimerCountdownDuration; // 0x18
    float_t TimerCountdownWarningStart; // 0x1C
};
struct HudRadialWheelData { // 0x1C
   // ctor: 0x009AD7E0
   // init: 0x009ADA20
    HudMenuTransitionData mRadialWheelUiTransitionData; // 0x0
    HudMenuTransitionData mRadialWheelButtonTransitionIntro; // 0x8
    HudMenuTransitionData mRadialWheelButtonTransitionOutro; // 0x10
    float_t ActivateWheelDelayTime; // 0x18
};
struct HudTeamFightOffScreenDifferentiationData { // 0xC
   // ctor: 0x009AEFE0
   // init: 0x009AEC80
    float_t m_0x40E3864F; // 0x0
    float_t m_0x3F035DDD; // 0x4
    uint8_t m_0x23086737; // 0x8
};
struct HudTeamFightData { // 0x10
   // ctor: 0x009AE380
   // init: 0x009AE6D0
    HudMenuTransitionData mSceneTransition; // 0x0
    uint32_t mStyleFlags; // 0x8
    unique_ptr_t<HudTeamFightOffScreenDifferentiationData> m_0xA7620C86; // 0xC
};
struct HudReplayData { // 0x14
   // ctor: 0x009AD340
   // init: 0x009AF930
    float_t MessageVisibleTime; // 0x0
    HudTeamFightData TeamFightData; // 0x4
};
struct HudCheatMenuData { // 0xC
   // ctor: 0x009AEDE0
   // init: 0x009AD440
    float_t TooltipDelay; // 0x0
    float_t GroupDividerGapSize; // 0x4
    uint8_t GroupDividerIndex; // 0x8
};
struct HudPingData { // 0x8
   // ctor: 0x009AE5E0
   // init: 0x009AF700
    float_t DistanceToNotTrollPingCorpses; // 0x0
    float_t TimeToNotTrollPingCorpses; // 0x4
};
struct HudVoiceChatData { // 0x4
   // ctor: 0x009AD3E0
   // init: 0x009ADFA0
    float_t HighlightTimeoutSeconds; // 0x0
};
struct HudInputBoxData { // 0x20
   // ctor: 0x009AE980
   // init: 0x009AD6F0
    uint8_t InputTextLengthMax; // 0x0
    float_t CaretAlphaMax; // 0x4
    float_t CaretBlinkTime; // 0x8
    float_t MarkedOffsetY; // 0xC
    float_t MarkedLineSizePx; // 0x10
    float_t SelectedOffsetY; // 0x14
    float_t SelectedLineSizePx; // 0x18
    float_t m_0xBEABF2D8; // 0x1C
};
struct HudHealthBarBurstData { // 0x38
   // ctor: 0x009AE690
   // init: 0x009AF430
    float_t BurstTimeWindow; // 0x0
    float_t BurstTriggerPercent; // 0x4
    float_t FlashTriggerPercent; // 0x8
    float_t FlashDuration; // 0xC
    float_t ShakeDuration; // 0x10
    point2D_t ShakeBox; // 0x14
    point2D_t ShakeReferenceResolution; // 0x1C
    float_t ShakeTriggerPercent; // 0x24
    float_t ShakeFrequency; // 0x28
    float_t FadeSpeed; // 0x2C
    float_t FadeAcceleration; // 0x30
    float_t FadeHoldTime; // 0x34
};
struct HudHealthBarFadeData { // 0xC
   // ctor: 0x009ADA90
   // init: 0x009AE6B0
    float_t FadeSpeed; // 0x0
    float_t FadeAcceleration; // 0x4
    float_t FadeHoldTime; // 0x8
};
struct HudHealthBarDefenseModifierData { // 0x10
   // ctor: 0x009AFAC0
   // init: 0x009AE700
    float_t DefenseUpPercent; // 0x0
    float_t DefenseDownL1Percent; // 0x4
    float_t DefenseDownL2Percent; // 0x8
    float_t DefenseDownL3Percent; // 0xC
};
struct HudHealthBarBurstHealData { // 0xC
   // ctor: 0x009AF4A0
   // init: 0x009AE430
    float_t HealTimeWindow; // 0x0
    float_t HealTriggerPercent; // 0x4
    float_t HealFadeDuration; // 0x8
};
struct HudHealthBarDefenseIconData { // 0xC
   // ctor: 0x009AF3A0
   // init: 0x009AF010
    float_t EnlargeTime; // 0x0
    float_t EnlargeSize; // 0x4
    float_t SettleTime; // 0x8
};
struct MicroTicksPerTickData { // 0x8
   // ctor: 0x009AE100
   // init: 0x009AF380
    float_t MinHealth; // 0x0
    uint32_t MicroTicksBetween; // 0x4
};
struct HudHealthBarProgressiveTickData { // 0x10
   // ctor: 0x009AD2D0
   // init: 0x009AEDA0
    vector_t<MicroTicksPerTickData> MicroTickPerTickData; // 0x0
    float_t HealthPerTick; // 0xC
};
struct HudHealthBarData { // 0xBC
   // ctor: 0x009ADB40
   // init: 0x009ADC10
    HudHealthBarBurstData BurstData; // 0x0
    HudHealthBarBurstData TowerBurstData; // 0x38
    HudHealthBarBurstHealData BurstHealData; // 0x70
    HudHealthBarProgressiveTickData ChampionProgressiveTickData; // 0x7C
    HudHealthBarFadeData FadeData; // 0x8C
    HudHealthBarDefenseModifierData DefenseModifierData; // 0x98
    HudHealthBarDefenseIconData DefenseIconData; // 0xA8
    float_t UntargetableAlpha; // 0xB4
    float_t ResurrectingAlpha; // 0xB8
};
struct HudSpellSlotResetFeedbackData { // 0xC
   // ctor: 0x009AD300
   // init: 0x009AD460
    float_t SpellResetFlashFadeDuration; // 0x0
    float_t SpellResetFlashScaleDownDuration; // 0x4
    float_t SpellResetScaleMultiplier; // 0x8
};
struct HudLoadingScreenProgressBarData { // 0x10
   // ctor: 0x009AF860
   // init: 0x009AE800
    float_t m_0xE4A8E1A9; // 0x0
    float_t m_0xD69543E7; // 0x4
    float_t m_0x9F3D3433; // 0x8
    float_t m_0xB550DE8D; // 0xC
};
struct HudLoadingScreenData { // 0x1C
   // ctor: 0x009AF340
   // init: 0x009AFC60
    HudLoadingScreenProgressBarData mProgressBarData; // 0x0
    bool m_0x9D17E9E3; // 0x10
    float_t mLoadingSpinnerSpeed; // 0x14
    uint8_t mLoadingSpinnerFrames; // 0x18
    uint8_t mLoadingSpinnerRows; // 0x19
};
struct HudStatPanelStatStoneData { // 0x2C
   // ctor: 0x009AD550
   // init: 0x009AF5E0
    float_t m_0xCA84776A; // 0x0
    float_t m_0xF675A6B7; // 0x4
    float_t mAnimationDelayTime; // 0x8
    HudMenuTransitionData m_0x77D83159; // 0xC
    HudMenuTransitionData m_0x4AE65DFA; // 0x14
    HudMenuTransitionData mSlideTransitionIn; // 0x1C
    HudMenuTransitionData mSlideTransitionOut; // 0x24
};
struct HudStatStoneData { // 0x20
   // ctor: 0x009AF990
   // init: 0x009AD7A0
    string_t m_0x2DD6B42E; // 0x0
    string_t m_0x3C8FA9E9; // 0xC
};
struct HudStatStoneDeathRecapData { // 0x20
   // ctor: 0x009AEEA0
   // init: 0x009ADD90
    float_t MinDisplayTime; // 0x0
    float_t MaxDisplayTime; // 0x4
    HudMenuTransitionData DetailsTransitionData; // 0x8
    HudMenuTransitionData DeathRecapTransitionIn; // 0x10
    HudMenuTransitionData DeathRecapTransitionOut; // 0x18
};
struct HudStatStoneMilestoneData { // 0x68
   // ctor: 0x009AE300
   // init: 0x009AE0C0
    string_t UiSound; // 0x0
    string_t m_0xEDF950C1; // 0xC
    string_t m_0x4F7FE3A3; // 0x18
    string_t m_0xBB713AE8; // 0x24
    float_t MilestoneDisplayTime; // 0x30
    float_t m_0xDD1C30AB; // 0x34
    float_t MilestoneSelfIntroTime; // 0x38
    float_t MilestoneOtherIntroTime; // 0x3C
    float_t PersonalBestIntroTime; // 0x40
    float_t m_0x39FECF93; // 0x44
    uint32_t m_0x0DB4C4CF; // 0x48
    HudMenuTransitionData m_0xA6D1B459; // 0x4C
    HudMenuTransitionData MilestoneTransitionIn; // 0x54
    HudMenuTransitionData MilestoneTransitionOut; // 0x5C
    bool m_0x4EA59D14; // 0x64
};
struct HudEndOfGameData { // 0x10
   // ctor: 0x0090B390
   // init: 0x0090BCB0
    HudMenuTransitionData mVictoryTransitionIn; // 0x0
    HudMenuTransitionData mDefeatTransitionIn; // 0x8
};
struct HudMessageDisplayData { // 0x10
   // ctor: 0x009AE3D0
   // init: 0x009AE9D0
    HudMenuTransitionData TransitionIn; // 0x0
    float_t MessageDuration; // 0x8
    uint32_t MessageCount; // 0xC
};
struct HudDamageDisplayData { // 0x4
   // ctor: 0x006083C0
   // init: 0x00607F30
    float_t m_0xDFCEA7DB; // 0x0
};
struct HudFightRecapUiData { // 0x40
   // ctor: 0x009AF2F0
   // init: 0x009AF530
    string_t mBasicAttackIconTextureName; // 0x0
    string_t mUnknownDamageIconTextureName; // 0xC
    string_t mItemDamageIconTextureName; // 0x18
    string_t mRuneDamageIconTextureName; // 0x24
};
struct MinimapPingEffectDefinition { // 0x24
   // ctor: 0x009AF040
   // init: 0x009AE830
    uint32_t AlphaStart; // 0x0
    float_t AlphaFadeSpeed; // 0x4
    float_t ScaleStart; // 0x8
    float_t ScaleSpeed; // 0xC
    float_t StartDelay; // 0x10
    float_t Life; // 0x14
    float_t OnDeathFadeSpeed; // 0x18
    uint32_t RepeatCount; // 0x1C
    bool BlendWithAlpha; // 0x20
};
struct TextureAndColorData { // 0x28
   // ctor: 0x009AF980
   // init: 0x009AEC10
    string_t TextureFile; // 0x0
    color_t Color; // 0xC
    string_t ColorblindTextureFile; // 0x10
    optional_t<color_t> ColorblindColor; // 0x1C
};
struct MinimapPingEffectAndTextureData { // 0x58
   // ctor: 0x009ADEB0
   // init: 0x009AF420
    bool mEnabled; // 0x0
    MinimapPingEffectDefinition mEffect; // 0x4
    TextureAndColorData mDefault; // 0x28
    unique_ptr_t<TextureAndColorData> mOrder; // 0x50
    unique_ptr_t<TextureAndColorData> mChaos; // 0x54
};
struct MinimapPingTypeContainer { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    vector_t<MinimapPingEffectAndTextureData> PingEffectList; // 0x0
};
struct MinimapPingData { // 0x1C
   // ctor: 0x009AD4D0
   // init: 0x009AE520
    map_t<uint8_t, float_t> mOmwPingRangeCutoffs; // 0x4
    vector_t<MinimapPingTypeContainer> mPings; // 0x10
};
struct ISecondaryResourceDisplayData: PropertyBase { // 0x4
   // ctor: 0x00400000
   // init: 0x00400000
};
struct SecondaryResourceDisplayFractional: ISecondaryResourceDisplayData { // 0x4
   // ctor: 0x009AF480
   // init: 0x009AEC60
};
struct LoadingScreenRankedProperties { // 0x10
   // ctor: 0x009AD940
   // init: 0x009AE640
    string_t mDescriptor; // 0x0
    uint8_t mDivision; // 0xC
};
struct LoadingScreenRankedData { // 0x1C
   // ctor: 0x009ADFF0
   // init: 0x009AD680
    map_t<string_t, LoadingScreenRankedProperties> mRankedData; // 0x10
};
struct ItemShopViewController: ViewController { // 0x250
   // ctor: 0x009ADF20
   // init: 0x009AF440
    hash_t DragRegion; // 0x88
    hash_t ResizeDragRegion; // 0xA0
    float_t MaximumShopScale; // 0x230
    float_t MinimumShopScale; // 0x234
};
struct t_0xE0E70CFC: ViewController { // 0x4C
   // ctor: 0x009AF5A0
   // init: 0x009AF6E0
    hash_t Scene; // 0x24
};
struct t_0x4E4BBC2B: ViewController { // 0x3C
   // ctor: 0x009AD5E0
   // init: 0x009AF4D0
    hash_t Scene; // 0x18
};
struct NavHeaderViewController: ViewController { // 0x174
   // ctor: 0x009AEA10
   // init: 0x009AE600
    hash_t m_0x4A989CC9; // 0x3C
    hash_t m_0x4E51B642; // 0x4C
    hash_t m_0x93A118FB; // 0xE4
    hash_t m_0x7B8E8695; // 0xFC
    hash_t BackButton; // 0x12C
    hash_t SocialButton; // 0x138
    hash_t NotificationsButton; // 0x144
    hash_t SettingsButton; // 0x150
    hash_t MissionsButton; // 0x15C
    hash_t StarShardsButton; // 0x168
};
struct OptionsViewController: ViewController { // 0x1A4
   // ctor: 0x009AE740
   // init: 0x009AFBF0
    ViewPaneDefinition ViewPaneDefinition; // 0x1C
    hash_t CloseButtonDefinition; // 0x94
    hash_t TabButtonDefinition; // 0xAC
    hash_t Button1Definition; // 0xC4
    hash_t Button2Definition; // 0xDC
    vector_t<link_ptr_t<OptionsTab>> Tabs; // 0xF4
    hash_t m_0x5A46F90C; // 0x100
    hash_t LastItemPadding; // 0x118
    hash_t m_0x4D302530; // 0x140
};
struct QualitySetting { // 0x28
   // ctor: 0x009AEC70
   // init: 0x009AE8A0
    string_t mName; // 0x0
    float_t m_0x033EB38D; // 0xC
    uint32_t mFrameCap; // 0x10
    uint32_t mEnvironmentQuality; // 0x14
    uint32_t m_0xA8D99737; // 0x18
    uint32_t mEffectsQuality; // 0x1C
    uint32_t mShadowQuality; // 0x20
    bool mFxAa; // 0x24
};
struct IOptionItem: PropertyBase { // 0x20
   // ctor: 0x00400000
   // init: 0x00400000
    bool LiveUpdate; // 0x4
    uint8_t ShowOnPlatform; // 0x5
    unique_ptr_t<IOptionItemFilter> Filter; // 0x8
};
struct IOptionTemplate: PropertyBase { // 0x24
   // ctor: 0x009AE0D0
   // init: 0x009AE2F0
    hash_t BoundsElement; // 0x4
};
struct OptionItemBorder: IOptionItem { // 0x44
   // ctor: 0x009ADD30
   // init: 0x009ADE80
    hash_t Template; // 0x20
    vector_t<unique_ptr_t<IOptionItem>> Items; // 0x2C
};
struct OptionItemCheckbox: IOptionItem { // 0x58
   // ctor: 0x009AEBB0
   // init: 0x009ADE50
    hash_t Template; // 0x24
    string_t LabelTraKey; // 0x30
    string_t TooltipTraKey; // 0x3C
    uint16_t Option; // 0x48
    bool Negate; // 0x4A
};
struct OptionItemColumns: IOptionItem { // 0x44
   // ctor: 0x009AEBF0
   // init: 0x009AD3A0
    vector_t<unique_ptr_t<IOptionItem>> ItemsEither; // 0x20
    vector_t<unique_ptr_t<IOptionItem>> ItemsLeft; // 0x2C
    vector_t<unique_ptr_t<IOptionItem>> ItemsRight; // 0x38
};
struct OptionItemDropdownItem { // 0x10
   // ctor: 0x00607F40
   // init: 0x00608200
    string_t TraKey; // 0x0
    int32_t Value; // 0xC
};
struct OptionItemDropdown: IOptionItem { // 0x5C
   // ctor: 0x009AEB20
   // init: 0x009AD970
    hash_t Template; // 0x24
    string_t LabelTraKey; // 0x30
    string_t TooltipTraKey; // 0x3C
    uint16_t Option; // 0x48
    vector_t<OptionItemDropdownItem> Items; // 0x4C
};
struct IOptionItemFilter: PropertyBase { // 0x4
   // ctor: 0x00400000
   // init: 0x00400000
};
struct t_0x0A6743A7: IOptionItemFilter { // 0x10
   // ctor: 0x009AE1D0
   // init: 0x009AE3B0
    vector_t<unique_ptr_t<IOptionItemFilter>> Filters; // 0x4
};
struct t_0xCD391C99: IOptionItemFilter { // 0x8
   // ctor: 0x009AD780
   // init: 0x009ADAC0
    bool ShowInLolGame; // 0x4
    bool ShowInLolReplay; // 0x5
    bool ShowInTftGame; // 0x6
    bool ShowInTftReplay; // 0x7
};
struct t_0x3E59E2CA: IOptionItemFilter { // 0x8
   // ctor: 0x009AF0E0
   // init: 0x009AF0C0
    bool m_0x7B98FFDD; // 0x4
    bool m_0x812748A2; // 0x5
    bool m_0x37985B59; // 0x6
};
struct t_0xD90E7018: IOptionItemFilter { // 0x10
   // ctor: 0x009AD650
   // init: 0x009AF090
    hash_t Map; // 0x4
};
struct t_0xEE4D1304: IOptionItemFilter { // 0x10
   // ctor: 0x009AFAF0
   // init: 0x009AE400
    string_t Mutator; // 0x4
};
struct t_0xF8026218: IOptionItemFilter { // 0x4
   // ctor: 0x009AFA60
   // init: 0x009AE7D0
};
struct t_0xA4941383: IOptionItemFilter { // 0x4
   // ctor: 0x009AF890
   // init: 0x009AD840
};
struct t_0x00C58386: IOptionItemFilter { // 0x8
   // ctor: 0x009AE360
   // init: 0x009AEF90
    bool m_0xC77C4866; // 0x4
};
struct t_0xA6A54243: IOptionItemFilter { // 0x4
   // ctor: 0x009AEFC0
   // init: 0x009ADF40
};
struct OptionItemGroup: IOptionItem { // 0x58
   // ctor: 0x009ADFD0
   // init: 0x009AEB00
    hash_t Template; // 0x24
    string_t LabelTraKey; // 0x30
    bool ExpandedByDefault; // 0x3C
    vector_t<unique_ptr_t<IOptionItem>> Items; // 0x40
};
struct OptionItemHotkeys: IOptionItem { // 0x60
   // ctor: 0x009ADCB0
   // init: 0x009AF180
    hash_t Template; // 0x24
};
struct OptionItemLabel: IOptionItem { // 0x44
   // ctor: 0x009AFA40
   // init: 0x009AF5C0
    hash_t Template; // 0x20
    string_t Label1TraKey; // 0x2C
    string_t Label2TraKey; // 0x38
};
struct OptionItemResolutionDropdown: OptionItemDropdown { // 0x70
   // ctor: 0x009AEB60
   // init: 0x009AE190
};
struct t_0x55212361 { // 0x48
   // ctor: 0x009ADC30
   // init: 0x009AE8F0
    string_t Column0LabelTraKey; // 0x0
    string_t Column1LabelTraKey; // 0xC
};
struct t_0x518D5FC0 { // 0x3C
   // ctor: 0x009AF1F0
   // init: 0x009AFB90
    string_t LabelTraKey; // 0x0
    string_t EventName; // 0xC
};
struct OptionItemSecondaryHotkeys1Column: IOptionItem { // 0x84
   // ctor: 0x009ADD20
   // init: 0x009AE4D0
    hash_t Template; // 0x24
    t_0x55212361 Header; // 0x30
    vector_t<t_0x518D5FC0> Rows; // 0x78
};
struct t_0xEA321356 { // 0x6C
   // ctor: 0x009AF320
   // init: 0x009AE820
    string_t Column0LabelTraKey; // 0x0
    string_t Column1LabelTraKey; // 0xC
    string_t Column2LabelTraKey; // 0x18
};
struct t_0x430DD10D { // 0x4C
   // ctor: 0x009AD380
   // init: 0x009AE660
    string_t LabelTraKey; // 0x0
    string_t EventName; // 0xC
    unique_ptr_t<IOptionItemFilter> Filter; // 0x18
};
struct OptionItemSecondaryHotkeys2Column: IOptionItem { // 0xA8
   // ctor: 0x009AF2D0
   // init: 0x009AED30
    hash_t Template; // 0x24
    t_0xEA321356 Header; // 0x30
    vector_t<t_0x430DD10D> Rows; // 0x9C
};
struct OptionItemSlider: IOptionItem { // 0x54
   // ctor: 0x00400000
   // init: 0x00400000
    hash_t Template; // 0x24
    string_t LabelTraKey; // 0x30
    string_t TooltipTraKey; // 0x3C
};
struct OptionItemSliderFloat: OptionItemSlider { // 0x5C
   // ctor: 0x009AEF40
   // init: 0x009AE610
    uint16_t Option; // 0x54
    bool UpdateOnDrag; // 0x56
    float_t Scale; // 0x58
};
struct OptionItemSliderGraphicsQuality: OptionItemSlider { // 0x54
   // ctor: 0x009AE870
   // init: 0x009AFB20
};
struct OptionItemSliderInt: OptionItemSlider { // 0x5C
   // ctor: 0x009AE560
   // init: 0x009AF450
    uint16_t Option; // 0x54
    uint32_t OptionScale; // 0x58
};
struct OptionItemSliderVolume: OptionItemSliderFloat { // 0x78
   // ctor: 0x009AD570
   // init: 0x009AD330
    hash_t MuteButtonTemplate; // 0x5C
    uint16_t MuteOption; // 0x68
};
struct t_0xF5324E2A: OptionItemDropdown { // 0x68
   // ctor: 0x009AE480
   // init: 0x009AD3B0
};
struct OptionsTab { // 0x30
   // ctor: 0x009AFA80
   // init: 0x009AF540
    string_t TabNameTraKey; // 0x0
    uint8_t ShowOn; // 0xC
    bool m_0x9255C052; // 0xD
    unique_ptr_t<IOptionItemFilter> Filter; // 0x10
    vector_t<unique_ptr_t<IOptionItem>> Items; // 0x14
};
struct OptionTemplateBorder: IOptionTemplate { // 0x4C
   // ctor: 0x009AD600
   // init: 0x009ADE10
    hash_t Border; // 0x24
};
struct OptionTemplateCheckbox: IOptionTemplate { // 0x54
   // ctor: 0x009AF7B0
   // init: 0x009AD8F0
    hash_t ButtonDefinition; // 0x24
    hash_t LabelElement; // 0x3C
};
struct OptionTemplateDropdown: IOptionTemplate { // 0x48
   // ctor: 0x009ADC60
   // init: 0x009AF140
    hash_t LabelElement; // 0x24
    hash_t ComboBoxDefinition; // 0x3C
};
struct OptionTemplateGroup: IOptionTemplate { // 0x74
   // ctor: 0x009ADB60
   // init: 0x009AF310
    hash_t ExpandButtonDefinition; // 0x24
    hash_t LabelElement; // 0x3C
    hash_t m_0xE76606D7; // 0x54
    float_t m_0x999669B3; // 0x6C
};
struct OptionTemplateHotkeysLabel { // 0x18
   // ctor: 0x009AE290
   // init: 0x009AE200
    hash_t Label; // 0x0
};
struct OptionTemplateHotkeysKey { // 0x38
   // ctor: 0x009AF840
   // init: 0x009AE0F0
    string_t EventName; // 0x0
    string_t EventNameTraKey; // 0xC
    hash_t Position; // 0x18
};
struct OptionTemplateHotkeys: IOptionTemplate { // 0xF4
   // ctor: 0x009AE7E0
   // init: 0x009AE270
    hash_t HotkeyButtonDefinition; // 0x24
    hash_t HotkeyButtonTextSmall; // 0x3C
    hash_t HotkeyModifierText; // 0x54
    hash_t HotkeyQuickCastButtonDefinition; // 0x6C
    hash_t CastAllButtonDefinition; // 0x84
    hash_t m_0x2F11F1CB; // 0x9C
    hash_t m_0xA8E4F979; // 0xB4
    vector_t<OptionTemplateHotkeysLabel> Labels; // 0xCC
    vector_t<OptionTemplateHotkeysKey> Keys; // 0xD8
};
struct OptionTemplateLabel: IOptionTemplate { // 0x54
   // ctor: 0x009AED80
   // init: 0x009AD480
    hash_t Label1; // 0x24
    hash_t Label2; // 0x3C
};
struct OptionTemplateMuteButton: IOptionTemplate { // 0x3C
   // ctor: 0x009AECA0
   // init: 0x009AE120
    hash_t ButtonDefinition; // 0x24
};
struct t_0xCEB70E5A { // 0x30
   // ctor: 0x009AE040
   // init: 0x009AEE60
    hash_t BackgroundElement; // 0x0
    hash_t TextElement; // 0x18
};
struct t_0x354988A8 { // 0x18
   // ctor: 0x009AE290
   // init: 0x009AE200
    hash_t ButtonDefinition; // 0x0
};
struct OptionTemplateSecondaryHotkeys1Column: IOptionTemplate { // 0xCC
   // ctor: 0x009AE670
   // init: 0x009AF030
    t_0xCEB70E5A m_0x5B59B589; // 0x24
    t_0xCEB70E5A m_0x5A59B3F6; // 0x54
    t_0xCEB70E5A m_0xFD31CBCB; // 0x84
    t_0x354988A8 m_0x545758A8; // 0xB4
};
struct OptionTemplateSecondaryHotkeys2Column: IOptionTemplate { // 0x114
   // ctor: 0x009AEE10
   // init: 0x009ADDE0
    t_0xCEB70E5A m_0x5B59B589; // 0x24
    t_0xCEB70E5A m_0x5A59B3F6; // 0x54
    t_0xCEB70E5A m_0x5959B263; // 0x84
    t_0xCEB70E5A m_0xFD31CBCB; // 0xB4
    t_0x354988A8 m_0x545758A8; // 0xE4
    t_0x354988A8 m_0x57575D61; // 0xFC
};
struct OptionTemplateSlider: IOptionTemplate { // 0x6C
   // ctor: 0x009AE900
   // init: 0x009AEAF0
    hash_t LabelElement; // 0x24
    hash_t ValueElement; // 0x3C
    hash_t m_0x6A05258C; // 0x54
};
struct NamedIconData { // 0x24
   // ctor: 0x009AD850
   // init: 0x009AE320
    string_t Name; // 0x0
    hash_t Icon; // 0xC
};
struct PostGameViewController: ViewController { // 0x1A7C
   // ctor: 0x009AEFA0
   // init: 0x009ADC00
    hash_t Scene; // 0x1C
    vector_t<NamedIconData> RankIconData; // 0x2C
    hash_t RankText; // 0x38
    hash_t CurrentExpText; // 0x50
    hash_t GainedExpText; // 0x68
    hash_t LostExpText; // 0x80
    hash_t PlacementTextRight; // 0x98
    hash_t ProvisionalTextRight; // 0xB0
    hash_t BackgroundTexture; // 0xC8
    hash_t CurrentPlayerHighlight; // 0xE0
    hash_t GainedRatingText; // 0xF8
    hash_t LostRatingText; // 0x110
    hash_t CurrentRatingText; // 0x128
    hash_t m_0x1ABF4B19; // 0x140
    vector_t<NamedIconData> RatedIconData; // 0x158
    hash_t m_0x8ECD9248; // 0x164
    hash_t m_0xB726620C; // 0x17C
    hash_t PlayAgainButtonDefinition; // 0x1A50
    hash_t QuitButtonDefinition; // 0x1A5C
    map_t<string_t, string_t> m_0xB06A57FD; // 0x1A70
};
struct CelebrationViewController: ViewController { // 0x170
   // ctor: 0x009AF960
   // init: 0x009ADC20
    hash_t Scene; // 0x54
    float_t m_0x615C3C29; // 0x14C
    string_t m_0x4FE75004; // 0x158
    map_t<string_t, string_t> m_0xC4ECB642; // 0x164
};
struct ModeSelectButtonData { // 0x18
   // ctor: 0x009AF640
   // init: 0x009AE450
    int64_t QueueId; // 0x0
    hash_t ButtonDefinition; // 0x8
};
struct HomeViewController: ViewController { // 0x158
   // ctor: 0x009ADE90
   // init: 0x009AEA00
    hash_t m_0xBBB37EF7; // 0x30
    t_0xFBD72D16 SpecialOfferController; // 0x40
    hash_t Scene; // 0xC4
    vector_t<ModeSelectButtonData> ModeSelectCustomButtonData; // 0xD4
    hash_t ModeSelectDefaultButtonData; // 0xE8
    hash_t PlayGameButtonDefinition; // 0xF8
    hash_t BattlepassButtonDefinition; // 0x104
    hash_t StoreButtonDefinition; // 0x110
    hash_t TeamPlannerButtonDefinition; // 0x11C
    hash_t SpecialOfferButtonDefinition; // 0x128
    link_ptr_t<t_0x75259AD3> m_0x56F22512; // 0x134
    string_t ThemeMusicStateGroup; // 0x138
    string_t ThemeMusicState; // 0x144
    float_t m_0xDC1D621E; // 0x150
    uint8_t m_0x86A69E37; // 0x154
};
struct ILoadoutFeatureDataBehavior { // 0x40
   // ctor: 0x009AD9D0
   // init: 0x009AD980
    string_t DisplayNameTraKey; // 0x0
    uint32_t LoadoutType; // 0xC
    hash_t m_0x4E2C59D6; // 0x10
    hash_t IllustrationIcon; // 0x1C
    hash_t Region; // 0x28
    hash_t ButtonDefinition; // 0x34
};
struct LoadoutSelectViewController: ViewController { // 0x48
   // ctor: 0x009AE5A0
   // init: 0x009AF6D0
    vector_t<ILoadoutFeatureDataBehavior> LoadoutsButtonData; // 0x1C
    hash_t Scene; // 0x38
};
struct LoadoutViewController: ViewController { // 0x940
   // ctor: 0x009E36A0
   // init: 0x009E3450
    hash_t m_0x78407281; // 0x28
    hash_t m_0xD1ABEB9D; // 0x2B4
    hash_t EquipButton; // 0x2CC
    hash_t GridItemButton; // 0x2D8
    hash_t CloseButton; // 0x2E4
    hash_t UpgradeButton; // 0x2F0
    hash_t m_0x91672418; // 0x2FC
    string_t SoundOnActivate; // 0x310
    string_t SoundOnDeActivate; // 0x31C
    LoadoutCompanionInfoPanel CompanionInfoPanel; // 0x328
    LoadoutArenaSkinInfoPanel ArenaInfoPanel; // 0x548
    LoadoutEmoteInfoPanel EmoteInfoPanel; // 0x648
    LoadoutDamageSkinInfoPanel DamageSkinInfoPanel; // 0x7E0
};
struct LobbyViewController: ViewController { // 0x560
   // ctor: 0x009E35D0
   // init: 0x009E3580
    hash_t m_0x573E7831; // 0x480
    hash_t ReadyCheckAcceptButton; // 0x490
    hash_t ReadyCheckDeclineButton; // 0x49C
    hash_t m_0xD5989AAE; // 0x4A8
    hash_t LobbyCloseButton; // 0x4B4
    hash_t FriendInviteButton; // 0x4C0
    hash_t FriendEditButton; // 0x4CC
    hash_t LoadoutsButton; // 0x4D8
    map_t<int64_t, string_t> m_0xBD29D956; // 0x4E4
    string_t m_0x1A361782; // 0x4EC
    string_t m_0xA38F5021; // 0x4F8
    string_t m_0x72C4914B; // 0x504
    string_t m_0xBF51F61A; // 0x510
    link_ptr_t<t_0x75259AD3> m_0x671C34C8; // 0x51C
    hash_t m_0xB3E2F60E; // 0x520
    string_t ThemeMusicStateGroup; // 0x538
    string_t LobbyMusicState; // 0x544
    string_t InQueueMusicState; // 0x550
};
struct LootTableDialogViewController: t_0x75259AD3 { // 0xBC
   // ctor: 0x009E3680
   // init: 0x009E3790
    hash_t m_0xE8B4823E; // 0x8C
    hash_t m_0x8F597852; // 0xA4
};
struct MissionsPanelViewController: ViewController { // 0x100
   // ctor: 0x009E36D0
   // init: 0x009E39A0
    hash_t Scene; // 0x30
    ViewPaneDefinition ViewPaneDefinition; // 0x7C
    float_t m_0xFA7C8443; // 0xF4
    uint8_t m_0xEC740D9E; // 0xF8
};
struct QueueDisplayData { // 0x48
   // ctor: 0x009E3490
   // init: 0x009E3440
    int64_t QueueId; // 0x0
    hash_t m_0xCE96BFFC; // 0x8
    hash_t m_0xF221C7D2; // 0x14
    hash_t m_0x021EAF8B; // 0x20
    hash_t IllustrationIconElement; // 0x2C
    string_t DisplayNameTraKey; // 0x38
};
struct ModeSelectViewController: ViewController { // 0xA0
   // ctor: 0x009E34E0
   // init: 0x009E3830
    hash_t Scene; // 0x3C
    vector_t<QueueDisplayData> QueueDisplayData; // 0x4C
    hash_t m_0x9E4BE5ED; // 0x58
    hash_t PageLeftButtonDefinition; // 0x64
    hash_t PageRightButtonDefinition; // 0x70
    string_t SoundOnActivate; // 0x7C
    string_t SoundOnDeActivate; // 0x88
    vector_t<hash_t> m_0x71378D8B; // 0x94
};
struct NotificationsPanelViewController: ViewController { // 0xF8
   // ctor: 0x009E3590
   // init: 0x009E3B40
    hash_t Scene; // 0x28
    ViewPaneDefinition ViewPaneDefinition; // 0x74
    hash_t ClearAllButtonDefinition; // 0xEC
};
struct t_0x6D8B7FBA { // 0x78
   // ctor: 0x00933120
   // init: 0x00932F60
    hash_t m_0xDC4A41FF; // 0x0
    hash_t m_0x351DE0C4; // 0x18
    hash_t m_0xFBD508B7; // 0x30
    hash_t m_0x3B5D2F94; // 0x48
    hash_t m_0xA67DBAB3; // 0x60
};
struct PurchaseDialog: t_0x75259AD3 { // 0x2A4
   // ctor: 0x009E3A80
   // init: 0x009E3410
    hash_t m_0x88F6A038; // 0x84
    hash_t m_0xB0DD6202; // 0x9C
    hash_t m_0x909D5D3F; // 0xAC
    hash_t m_0x25C805C3; // 0xC4
    hash_t m_0x07061DA5; // 0xDC
    hash_t m_0x8DD1DA54; // 0xF4
    hash_t m_0x2E6D3C7E; // 0x10C
    hash_t m_0xF42E1D1A; // 0x124
    hash_t m_0x3591028E; // 0x13C
    t_0x6D8B7FBA m_0x67C3B51B; // 0x154
    hash_t m_0x49D6BD37; // 0x1CC
    hash_t m_0x2FBBD4D0; // 0x1DC
    hash_t m_0x2AA5CB5E; // 0x1F4
    hash_t m_0xE338A1DA; // 0x20C
    hash_t m_0x32CD31DF; // 0x224
    hash_t PurchaseButton; // 0x274
    hash_t MoreInfoButton; // 0x28C
};
struct t_0x39BBCA88: t_0x75259AD3 { // 0x1F8
   // ctor: 0x009E3B00
   // init: 0x009E3890
    hash_t ActionButtonDefinition; // 0x80
    hash_t m_0x523F1F5E; // 0xBC
    hash_t m_0x44B4862A; // 0xD4
    hash_t m_0xCD92A830; // 0xEC
    hash_t m_0x4B932928; // 0x104
    hash_t m_0x4FA419B5; // 0x11C
    hash_t m_0x738917DB; // 0x134
    hash_t m_0x52662FAD; // 0x14C
    hash_t m_0xA8F48B28; // 0x164
    hash_t m_0x56ED0D27; // 0x17C
    hash_t m_0xD5B6BCD3; // 0x194
    hash_t m_0x5C05F04D; // 0x1AC
    hash_t m_0x7D83E942; // 0x1C4
};
struct SocialPanelViewController: ViewController { // 0x118
   // ctor: 0x009E3810
   // init: 0x009E3AE0
    hash_t Scene; // 0x20
    ViewPaneDefinition ViewPaneDefinition; // 0x7C
    hash_t AddFriendButtonDefinition; // 0xF4
    hash_t InviteButtonDefinition; // 0x100
    hash_t FriendButtonDefinition; // 0x10C
};
struct t_0xFBD72D16 { // 0x20
   // ctor: 0x009E3360
   // init: 0x009E39D0
    link_ptr_t<t_0x4D31ED46> m_0x4D31ED46; // 0x1C
};
struct StoreCategoryButtonDefinition { // 0x10
   // ctor: 0x009E3500
   // init: 0x009E3710
    uint32_t Category; // 0x0
    hash_t ButtonDefinition; // 0x4
};
struct StoreViewController: ViewController { // 0x84
   // ctor: 0x009E3930
   // init: 0x009E3530
    hash_t m_0x36A4C8EE; // 0x34
    hash_t m_0x9EAE8CC2; // 0x5C
    hash_t m_0xD2CC0CDF; // 0x68
    unique_ptr_t<ViewPaneDefinition> MainViewPaneDefinition; // 0x74
    vector_t<StoreCategoryButtonDefinition> StoreCategoryButtonDefinitions; // 0x78
};
struct TftBattlepassViewController: ViewController { // 0x1F0
   // ctor: 0x009E3420
   // init: 0x009E3610
    hash_t m_0xCFD1AA4A; // 0x50
    hash_t UpgradePassButton; // 0x64
    hash_t LootTableButton; // 0x7C
    hash_t m_0x59434C33; // 0x15C
    ViewPaneDefinition ViewPaneDefinition; // 0x16C
    float_t m_0xC034AF02; // 0x1E4
    HudMenuTransitionData m_0x650B36B5; // 0x1E8
};
struct LoadoutArenaSkinInfoPanel: ILoadoutInfoPanel { // 0x100
   // ctor: 0x009E3660
   // init: 0x009E3650
};
struct LoadoutCompanionInfoPanel: ILoadoutInfoPanel { // 0x220
   // ctor: 0x009E37B0
   // init: 0x009E3AD0
    hash_t UpgradeInfoText; // 0x158
    hash_t UpgradeErrorText; // 0x170
    array_t<hash_t, 3> TierButton; // 0x1A8
    array_t<hash_t, 3> UpgradeTierButton; // 0x1CC
    hash_t m_0x6A5635F2; // 0x1F0
    hash_t m_0x90DD73EF; // 0x208
};
struct LoadoutDamageSkinInfoPanel: ILoadoutInfoPanel { // 0x160
   // ctor: 0x009E33B0
   // init: 0x009E3550
    array_t<hash_t, 3> TierButton; // 0x13C
};
struct LoadoutEmoteInfoPanel: ILoadoutInfoPanel { // 0x198
   // ctor: 0x009E38E0
   // init: 0x009E3640
    hash_t EmoteWheelUpperButton; // 0x144
    hash_t EmoteWheelLeftButton; // 0x150
    hash_t EmoteWheelLowerButton; // 0x15C
    hash_t EmoteWheelRightButton; // 0x168
    hash_t EmoteWheelCenterButton; // 0x174
    hash_t EmoteStartButton; // 0x180
    hash_t EmoteVictoryButton; // 0x18C
};
struct ILoadoutInfoPanel: PropertyBase { // 0x84
   // ctor: 0x00400000
   // init: 0x00400000
    ViewPaneDefinition ViewPaneDefinition; // 0xC
};
struct t_0x759A8C58: t_0x75259AD3 { // 0x168
   // ctor: 0x009E3910
   // init: 0x009E3840
    hash_t UpgradeText; // 0x80
    hash_t ErrorText; // 0x98
    hash_t ItemIcon; // 0xB0
    hash_t ItemFrame; // 0xC8
    hash_t RarityFrameCommon; // 0xE0
    hash_t RarityFrameEpic; // 0xF8
    hash_t RarityFrameLegendary; // 0x110
    hash_t m_0xDA8BCD33; // 0x128
    hash_t m_0x41ED38A6; // 0x140
};
struct NotificationSettings { // 0x30
   // ctor: 0x009E38C0
   // init: 0x009E3900
    string_t DefaultSound; // 0x4
    unordered_map_t<uint8_t, string_t> m_0x89667868; // 0x10
};
struct QuestDefinition { // 0x34
   // ctor: 0x009E34B0
   // init: 0x009E3350
    string_t CategoryTitleText; // 0x0
    uint32_t MaxViewableQuests; // 0xC
    string_t RecievedSoundPath; // 0x10
    string_t CompletedSoundPath; // 0x1C
    string_t FailedSoundPath; // 0x28
};
struct t_0x46533086 { // 0x138
   // ctor: 0x009E3560
   // init: 0x009E3800
    QuestDefinition PrimaryQuest; // 0x0
    QuestDefinition SecondaryQuest; // 0x34
    QuestDefinition ObjectiveQuest; // 0x68
    QuestDefinition m_0x56647830; // 0x9C
    QuestDefinition m_0x6CEE1705; // 0xD0
    QuestDefinition ScoreDisplayQuest; // 0x104
};
struct QuestTrackerViewController: ViewController { // 0x5C
   // ctor: 0x009E32F0
   // init: 0x009E36C0
    HudMessageDisplayData MessageDisplayData; // 0x18
    uint32_t m_0x062EAB0B; // 0x28
    float_t m_0x18BAE045; // 0x2C
    float_t m_0xDBA6FEBB; // 0x30
    float_t m_0x9FA3719E; // 0x34
    float_t m_0x28F5E138; // 0x38
    float_t m_0xA0AE36A8; // 0x3C
    float_t m_0xC67A95A4; // 0x40
};
struct t_0xE20BE0BE: ViewController { // 0x34
   // ctor: 0x009E3A60
   // init: 0x009E3730
    hash_t m_0x4D302530; // 0x20
};
struct t_0x320B890E: ViewController { // 0x3A4
   // ctor: 0x009E3B20
   // init: 0x009E34D0
};
struct GeneralSettingsGroup { // 0x58
   // ctor: 0x009E35B0
   // init: 0x009E37A0
    hash_t PromoteAccountButton; // 0x34
    hash_t SignOutButton; // 0x40
    hash_t RestorePurchaseButton; // 0x4C
};
struct SettingsViewController: ViewController { // 0x144
   // ctor: 0x009E33F0
   // init: 0x009E3AF0
    GeneralSettingsGroup GeneralSettings; // 0x28
    hash_t CloseButton; // 0x108
    hash_t TabButton; // 0x114
    string_t SoundOnActivate; // 0x120
    string_t SoundOnDeActivate; // 0x12C
};
struct t_0x1FA3E21C { // 0x78
   // ctor: 0x00A03CA0
   // init: 0x00A04050
    hash_t m_0xA2BC2CB5; // 0x0
    hash_t m_0x43B27471; // 0x18
    hash_t Icon; // 0x30
    hash_t Title; // 0x48
    hash_t Description; // 0x60
};
struct t_0x61A8DEDA: ViewController { // 0x118
   // ctor: 0x00A03CC0
   // init: 0x00A03E90
    hash_t Scene; // 0x1C
    hash_t m_0xAF871A91; // 0x2C
    hash_t m_0xDF85B25F; // 0x44
    t_0x1FA3E21C m_0x1FA3E21C; // 0x5C
    float_t m_0x0B6200FC; // 0xD4
    float_t m_0x4A65C1A7; // 0xD8
    uint8_t m_0x017A5149; // 0xDC
    uint32_t m_0xF75A1005; // 0xE0
};
struct SurrenderTypeData { // 0x14
   // ctor: 0x00A03A80
   // init: 0x00A03EC0
    float_t VoteTimeout; // 0x0
    float_t WindowLength; // 0x4
    float_t StartTime; // 0x8
    float_t PercentageRequired; // 0xC
    float_t m_0x3F72F07A; // 0x10
};
struct SurrenderData { // 0x1C
   // ctor: 0x00A03B60
   // init: 0x00A03AD0
    float_t m_0x43F7599B; // 0x0
    float_t m_0x0E98993C; // 0x4
    float_t m_0xCC805103; // 0x8
    float_t m_0x3AFEACF3; // 0xC
    map_t<uint8_t, SurrenderTypeData> mTypeData; // 0x10
};
struct LoadScreenTip { // 0x24
   // ctor: 0x00A03BE0
   // init: 0x00A03F40
    uint16_t mId; // 0x0
    optional_t<uint32_t> mMinimumSummonerLevel; // 0x4
    optional_t<uint32_t> mMaximumSummonerLevel; // 0x8
    string_t mLocalizationKey; // 0xC
    string_t mHeaderLocalizationKey; // 0x18
};
struct LoadScreenTipSet { // 0x10
   // ctor: 0x005CA800
   // init: 0x005CA650
    hash_t mName; // 0x0
    vector_t<link_ptr_t<LoadScreenTip>> mTips; // 0x4
};
struct LoadScreenTipConfiguration { // 0xC
   // ctor: 0x00A03E10
   // init: 0x00A03DF0
    bool mShowInCustomGames; // 0x0
    bool mShowPbiTipsOnLoadingScreen; // 0x1
    float_t mPbiTipDurationOnLoadingScreen; // 0x4
    float_t mDurationInGame; // 0x8
};
struct TooltipInstanceSpell: TooltipInstance { // 0x78
   // ctor: 0x00A03F90
   // init: 0x00A03EA0
    bool EnableExtendedTooltip; // 0x74
};
struct TooltipInstanceBuff: TooltipInstance { // 0x78
   // ctor: 0x00A03C30
   // init: 0x00A03E70
    bool mEnableExtendedTooltip; // 0x74
};
struct TooltipInstanceItem: TooltipInstance { // 0x74
   // ctor: 0x00A03B10
   // init: 0x00A03B40
};
struct t_0x9E5AED77 { // 0x18
   // ctor: 0x00608900
   // init: 0x00608F30
    int32_t m_0x571A97A3; // 0x0
    int32_t m_0x88A45101; // 0x4
    int32_t m_0x1A8B3CC8; // 0x8
    int32_t m_0xBB9129AB; // 0xC
    int32_t m_0xE2E4F9C2; // 0x10
    int32_t m_0x47BDBBE9; // 0x14
};
struct TooltipViewController: ViewController { // 0x330
   // ctor: 0x00A03CE0
   // init: 0x00A03FE0
    t_0x9E5AED77 DefaultAdjustments; // 0x1C
    map_t<string_t, t_0x9E5AED77> m_0xF5FC1D3A; // 0x34
    float_t m_0x9E2FCAD4; // 0x2EC
    float_t m_0x750AD235; // 0x2F0
};
struct ViewController: PropertyBase { // 0x14
   // ctor: 0x00400000
   // init: 0x00400000
    link_ptr_t<ViewController> m_0xB79C86AE; // 0xC
};
struct t_0xD9438618 { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    vector_t<string_t> m_0x799F2859; // 0x0
};
struct t_0x7FEB6200: PropertyBase { // 0x1C
   // ctor: 0x00A040D0
   // init: 0x00A03D00
    vector_t<string_t> m_0x71581E65; // 0x4
    vector_t<link_ptr_t<t_0xD9438618>> m_0x121B136B; // 0x10
};
struct VoiceChatViewController: ViewController { // 0x27C
   // ctor: 0x00A03EF0
   // init: 0x00A03D40
    hash_t PanelSceneHandle; // 0x2C
    VoiceChatViewSelfSlot SelfSlot; // 0x3C
    t_0x86504CEF PlayerSlotData; // 0xF8
    hash_t PlayerGrid; // 0x1B8
    hash_t Backdrop; // 0x1D0
    hash_t ErrorText; // 0x1F8
    hash_t m_0x8C45EB46; // 0x210
    hash_t m_0x788862BD; // 0x228
};
struct t_0x86504CEF { // 0xA8
   // ctor: 0x00A03DD0
   // init: 0x00A03DC0
    hash_t Group; // 0x0
    hash_t Portrait; // 0x18
    hash_t VolumeText; // 0x30
    hash_t Halo; // 0x48
    hash_t NameText; // 0x60
    hash_t VolumeSliderBar; // 0x78
    hash_t MuteButton; // 0x90
};
struct VoiceChatViewSelfSlot { // 0xBC
   // ctor: 0x00A03A60
   // init: 0x00A03AC0
    hash_t Portrait; // 0x4
    hash_t Halo; // 0x1C
    hash_t NameText; // 0x34
    hash_t MicVolumeText; // 0x4C
    hash_t MicVolumeSliderBar; // 0x6C
    hash_t MuteButton; // 0x84
    hash_t ConnectionButton; // 0x9C
};
struct NeutralTimerSourceIconData { // 0x24
   // ctor: 0x005CA9E0
   // init: 0x005CA8E0
    string_t mTooltipName; // 0x0
    string_t mIconName; // 0xC
};
struct NeutralTimerData { // 0x74
   // ctor: 0x00A358E0
   // init: 0x00A36170
    string_t mTimerKeyName; // 0x0
    string_t mTooltip; // 0xC
    string_t mTooltipCampName; // 0x18
    string_t mTooltipRespawn; // 0x24
    string_t mTooltipChatNameOrder; // 0x30
    string_t mTooltipChatNameChaos; // 0x3C
    map_t<hash_t, NeutralTimerSourceIconData> mSourceIcons; // 0x48
};
struct NeutralTimers { // 0x2C
   // ctor: 0x00A35CD0
   // init: 0x00A36060
    string_t mSceneName; // 0x0
    string_t m_0xEE974CAE; // 0xC
    map_t<hash_t, NeutralTimerData> mTimers; // 0x18
};
struct CommonUiTunables { // 0xC
   // ctor: 0x00A35700
   // init: 0x00A356C0
    float_t m_0x472B866D; // 0x4
    uint8_t m_0xB3F4A621; // 0x8
};
struct ViewPaneDefinition { // 0x78
   // ctor: 0x00A35E70
   // init: 0x00A35F90
    hash_t m_0x6EAC67FC; // 0x0
    hash_t DragRegionElement; // 0x18
    hash_t ScrollRegionElement; // 0x30
    hash_t ScissorRegionElement; // 0x48
    hash_t ScrollingScene; // 0x60
    uint8_t ScrollDirection; // 0x70
    hash_t ObjectPath; // 0x74
};
struct UiButtonState { // 0x10
   // ctor: 0x005CA800
   // init: 0x005CA650
    vector_t<link_ptr_t<BaseElementData>> DisplayElements; // 0x0
    link_ptr_t<TextElementData> TextElement; // 0xC
};
struct UiButtonDefinition { // 0x98
   // ctor: 0x00A358A0
   // init: 0x00A35980
    UiButtonState DefaultStateElements; // 0x0
    UiButtonState InactiveStateElements; // 0x10
    UiButtonState HoverStateElements; // 0x20
    UiButtonState m_0xAD0F8882; // 0x30
    UiButtonState SelectedStateElements; // 0x40
    UiButtonState SelectedHoverStateElements; // 0x50
    UiButtonState SelectedClickedStateElements; // 0x60
    link_ptr_t<RegionElementData> HitRegionElement; // 0x70
    link_ptr_t<ParticleSystemElementData> ClickReleaseParticleElement; // 0x74
    unique_ptr_t<t_0x209B0277> SoundEvents; // 0x78
    string_t ActiveTooltipTraKey; // 0x7C
    string_t InactiveTooltipTraKey; // 0x88
    hash_t ObjectPath; // 0x94
};
struct UiButtonAdditionalState { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    vector_t<link_ptr_t<BaseElementData>> DisplayElements; // 0x0
};
struct UiButtonAdditionalElements { // 0x54
   // ctor: 0x00A35C10
   // init: 0x00A35870
    UiButtonAdditionalState DefaultStateElements; // 0x0
    UiButtonAdditionalState InactiveStateElements; // 0xC
    UiButtonAdditionalState HoverStateElements; // 0x18
    UiButtonAdditionalState m_0xAD0F8882; // 0x24
    UiButtonAdditionalState SelectedStateElements; // 0x30
    UiButtonAdditionalState SelectedHoverStateElements; // 0x3C
    UiButtonAdditionalState SelectedClickedStateElements; // 0x48
};
struct t_0x209B0277 { // 0x48
   // ctor: 0x00A35770
   // init: 0x00A35BA0
    string_t RolloverEvent; // 0x0
    string_t m_0x210EA29E; // 0xC
    string_t MouseDownEvent; // 0x18
    string_t m_0x0452034C; // 0x24
    string_t MouseUpEvent; // 0x30
    string_t m_0xB49CA145; // 0x3C
};
struct t_0xE262E6BE { // 0xC
   // ctor: 0x0067CE10
   // init: 0x0067CB50
    string_t OnSelectionEvent; // 0x0
};
struct UiComboBoxDefinition { // 0x38
   // ctor: 0x00A35F30
   // init: 0x00A35730
    hash_t ButtonDefinition; // 0x0
    link_ptr_t<IconElementData> m_0xB2A3BE3C; // 0xC
    link_ptr_t<IconElementData> m_0x03487222; // 0x10
    link_ptr_t<IconElementData> m_0x9C4781A2; // 0x14
    link_ptr_t<TextElementData> m_0x21C9D879; // 0x18
    link_ptr_t<RegionElementData> m_0x337B72D4; // 0x1C
    uint8_t m_0x0EB2B67E; // 0x20
    unique_ptr_t<t_0xE262E6BE> SoundEvents; // 0x24
    hash_t ObjectPath; // 0x28
    string_t m_0xCD0AAA2E; // 0x2C
};
struct t_0xD149DD3F { // 0x8
   // ctor: 0x00A360B0
   // init: 0x00A35FA0
    int32_t FromSlotId; // 0x0
    int32_t ToSlotId; // 0x4
};
struct t_0xB35AD9D8 { // 0x20
   // ctor: 0x00A35AF0
   // init: 0x00A35AB0
    vector_t<hash_t> Items; // 0x0
    uint32_t ItemsPerRow; // 0xC
    bool m_0xD8BEA346; // 0x10
    int32_t DefaultIndex; // 0x14
    t_0xD149DD3F SwapData; // 0x18
};
struct t_0xD20000F6 { // 0x38
   // ctor: 0x00A36120
   // init: 0x00A35EE0
    hash_t SceneData; // 0x0
    hash_t PinButton; // 0xC
    t_0xB35AD9D8 m_0x434952B4; // 0x18
};
struct t_0xEF05BA42: PropertyBase { // 0x60
   // ctor: 0x00A36000
   // init: 0x00A360F0
    link_ptr_t<BaseElementData> ItemIcon; // 0x4
    link_ptr_t<BaseElementData> FrameIcon; // 0x8
    link_ptr_t<BaseElementData> MythicFrameIcon; // 0xC
    link_ptr_t<BaseElementData> HoverFrameIcon; // 0x10
    link_ptr_t<BaseElementData> m_0x5B96B3BD; // 0x14
    link_ptr_t<BaseElementData> HoverIcon; // 0x18
    link_ptr_t<BaseElementData> SelectedIcon; // 0x1C
    link_ptr_t<BaseElementData> UnpurchaseableOverlay; // 0x20
    link_ptr_t<BaseElementData> PurchasedOverlay; // 0x24
    link_ptr_t<BaseElementData> PopularIcon; // 0x28
    link_ptr_t<BaseElementData> LockedIcon; // 0x2C
    link_ptr_t<BaseElementData> LockedHoverIcon; // 0x30
    link_ptr_t<BaseElementData> RecentlyChangedIcon; // 0x34
    link_ptr_t<BaseElementData> CostText; // 0x38
    link_ptr_t<BaseElementData> CostTextUnpurchaseable; // 0x3C
    link_ptr_t<BaseElementData> CostTextSelected; // 0x40
    link_ptr_t<BaseElementData> NameText; // 0x44
    link_ptr_t<BaseElementData> HitRegion; // 0x48
    link_ptr_t<BaseElementData> OffsetRegion; // 0x4C
    link_ptr_t<BaseElementData> SelectedVfx; // 0x50
    link_ptr_t<BaseElementData> m_0x987DD59E; // 0x54
    link_ptr_t<BaseElementData> MythicPurchaseableVfx; // 0x58
    link_ptr_t<BaseElementData> MythicPurchasedVfx; // 0x5C
};
struct t_0x9205B275: t_0xEF05BA42 { // 0xE4
   // ctor: 0x00A36040
   // init: 0x00A35F50
    link_ptr_t<BaseElementData> CardDefault; // 0x60
    link_ptr_t<BaseElementData> CardHoverMythic; // 0x64
    link_ptr_t<BaseElementData> CardHoverNonMythic; // 0x68
    link_ptr_t<BaseElementData> CardSelectedMythic; // 0x6C
    link_ptr_t<BaseElementData> CardSelectedNonMythic; // 0x70
    link_ptr_t<BaseElementData> BriefText; // 0x74
    link_ptr_t<BaseElementData> BriefTextBackdrop; // 0x78
    link_ptr_t<BaseElementData> AdviceIconDefault; // 0x7C
    link_ptr_t<BaseElementData> m_0x09C2A9D4; // 0x80
    link_ptr_t<BaseElementData> m_0xC68C22CF; // 0x84
    link_ptr_t<BaseElementData> AdviceLabel; // 0x88
    link_ptr_t<BaseElementData> AdviceCharIcon0; // 0x8C
    link_ptr_t<BaseElementData> AdviceCharIcon1; // 0x90
    link_ptr_t<BaseElementData> CardHoverNonMythicVfx; // 0x94
    link_ptr_t<BaseElementData> CardHoverMythicVfx; // 0x98
    link_ptr_t<BaseElementData> CardRefreshMythicVfx; // 0x9C
    link_ptr_t<BaseElementData> CardRefreshNonMythicVfx; // 0xA0
    link_ptr_t<BaseElementData> CardSelectedMythicVfx; // 0xA4
    link_ptr_t<BaseElementData> CardSelectedNonMythicVfx; // 0xA8
    link_ptr_t<BaseElementData> AdviceEmptyIconDefault; // 0xAC
    link_ptr_t<BaseElementData> m_0x59FBBD19; // 0xB0
    link_ptr_t<BaseElementData> m_0x9566584E; // 0xB4
    link_ptr_t<BaseElementData> AdviceEmptyText; // 0xB8
    link_ptr_t<BaseElementData> AdviceEmptyTextHover; // 0xBC
    link_ptr_t<BaseElementData> AdviceCharBorder0; // 0xC0
    link_ptr_t<BaseElementData> AdviceCharBorderHover0; // 0xC4
    link_ptr_t<BaseElementData> AdviceCharBorder1; // 0xC8
    link_ptr_t<BaseElementData> AdviceCharBorderHover1; // 0xCC
    link_ptr_t<BaseElementData> PlusIcon; // 0xD0
    link_ptr_t<BaseElementData> BundleItemIcon; // 0xD4
    link_ptr_t<BaseElementData> BundleStackText; // 0xD8
    link_ptr_t<BaseElementData> BundleItemFrameIcon; // 0xDC
    link_ptr_t<BaseElementData> BundleItemFrameHoverIcon; // 0xE0
};
struct t_0x38691790 { // 0x18
   // ctor: 0x005CA580
   // init: 0x005CA210
    vector_t<uint8_t> m_0x837FCF93; // 0x0
    string_t GroupName; // 0xC
};
struct StatFilterDefinition { // 0x18
   // ctor: 0x009AE290
   // init: 0x009AE200
    hash_t ButtonDefinition; // 0x0
    vector_t<hash_t> MatchingCategories; // 0xC
};
struct t_0x77595AA9 { // 0x174
   // ctor: 0x00A35DA0
   // init: 0x00A357C0
    StatFilterDefinition PhysicalDamage; // 0x0
    StatFilterDefinition CriticalStrike; // 0x18
    StatFilterDefinition AttackSpeed; // 0x30
    StatFilterDefinition OnHit; // 0x48
    StatFilterDefinition ArmorPenetration; // 0x60
    StatFilterDefinition AbilityPower; // 0x78
    StatFilterDefinition Mana; // 0x90
    StatFilterDefinition MagicPenetration; // 0xA8
    StatFilterDefinition Health; // 0xC0
    StatFilterDefinition Armor; // 0xD8
    StatFilterDefinition MagicResist; // 0xF0
    StatFilterDefinition AbilityHaste; // 0x108
    StatFilterDefinition MoveSpeed; // 0x120
    StatFilterDefinition m_0xD628825F; // 0x138
    StatFilterDefinition DisableStatFilters; // 0x150
};
struct HudItemShopData { // 0x514
   // ctor: 0x00A35F60
   // init: 0x00A35EB0
    hash_t TabButtonDefinition; // 0x4
    hash_t CloseButtonDefinition; // 0x10
    hash_t PurchaseButtonDefinition; // 0x1C
    hash_t SellButtonDefinition; // 0x28
    hash_t UndoButtonDefinition; // 0x34
    hash_t m_0x616B3A84; // 0x40
    hash_t m_0x1EE195A0; // 0x4C
    hash_t m_0xAA05F252; // 0x58
    hash_t m_0xDCF2BBE3; // 0x64
    hash_t m_0x6D532C7A; // 0x70
    hash_t m_0x655C70A4; // 0x7C
    hash_t m_0xF1B77DE6; // 0x88
    hash_t m_0xD2202861; // 0x94
    hash_t m_0x6FF1FABE; // 0xA0
    hash_t m_0xA1F85097; // 0xAC
    hash_t m_0x77595AA9; // 0xB8
    ViewPaneDefinition m_0x71D17542; // 0xC4
    ViewPaneDefinition m_0x0CE14C25; // 0x13C
    ViewPaneDefinition m_0xB3E9D346; // 0x1B4
    ViewPaneDefinition SearchViewPaneDefinition; // 0x22C
    hash_t AllItemsHeaderRegion; // 0x2A4
    hash_t AllItemsItemRegion; // 0x2BC
    hash_t ItemSetsHeaderRegion; // 0x2D4
    hash_t ItemSetsItemRegion; // 0x2EC
    hash_t AllItemsHeaderText; // 0x304
    hash_t m_0xF481F566; // 0x31C
    hash_t m_0x4823F71D; // 0x334
    vector_t<t_0x38691790> m_0x79A37750; // 0x34C
    t_0xD20000F6 BootsPanelDefinition; // 0x358
    t_0xD20000F6 ConsumablesPanelDefinition; // 0x390
    t_0xD20000F6 InventoryPanelDefinition; // 0x3C8
    array_t<hash_t, 6> m_0xE00BE811; // 0x400
    float_t m_0x0F8310AA; // 0x448
    float_t m_0x7DF5B85F; // 0x44C
    hash_t BuildsIntoIconDefinition; // 0x450
    hash_t BuildTreeIconDefinition; // 0x45C
    hash_t QuickBuyIconDefinition; // 0x468
    hash_t InventoryIconDefinition; // 0x474
    hash_t AllItemsIconDefinition; // 0x480
    hash_t ItemSetsIconDefinition; // 0x48C
    hash_t SearchIconDefinition; // 0x498
    hash_t m_0x494A4B42; // 0x4A4
    hash_t CommonlyBuiltIconDefinition; // 0x4B0
    hash_t m_0x5AB9B659; // 0x4BC
    hash_t m_0xF8E1342C; // 0x4C8
    hash_t m_0x69988DB6; // 0x4D4
    float_t m_0x7BA0C753; // 0x4E0
    hash_t ItemDetailsScene; // 0x4E4
    hash_t m_0xF48CF36F; // 0x4F0
    hash_t m_0xAA352F81; // 0x4FC
    string_t m_0xD6F8B1FA; // 0x508
};
struct IHudLoadingScreenWidget: PropertyBase { // 0x10
   // ctor: 0x00400000
   // init: 0x00400000
    string_t mSceneName; // 0x4
};
struct HudLoadingScreenCarouselData { // 0x10
   // ctor: 0x009AD940
   // init: 0x009AE640
    string_t Image; // 0x0
    uint8_t mTipType; // 0xC
};
struct HudLoadingScreenWidgetCarousel: IHudLoadingScreenWidget { // 0x24
   // ctor: 0x00A359F0
   // init: 0x00A35E10
    uint8_t m_0x7B1F4FC8; // 0x10
    link_ptr_t<HudLoadingScreenCarouselData> mCarouselData; // 0x20
};
struct HudLoadingScreenWidgetClash: IHudLoadingScreenWidget { // 0x1C
   // ctor: 0x00A35DC0
   // init: 0x00A35FC0
};
struct HudLoadingScreenWidgetPing: IHudLoadingScreenWidget { // 0x17C
   // ctor: 0x00A360D0
   // init: 0x00A35E60
    uint32_t mDebugPing; // 0x38
    uint32_t mPingThresholdGreen; // 0x3C
    uint32_t mPingThresholdYellow; // 0x40
    uint32_t mPingThresholdOrange; // 0x44
    uint32_t mPingThresholdRed; // 0x48
};
struct HudLoadingScreenWidgetPlayers: IHudLoadingScreenWidget { // 0x38
   // ctor: 0x00A35B80
   // init: 0x00A35EC0
    PlayerCardWidgetConfig mCardConfig; // 0x30
};
struct HudLoadingScreenWidgetProgressBar: IHudLoadingScreenWidget { // 0x4C
   // ctor: 0x00A358C0
   // init: 0x00A35660
};
struct HudLoadingScreenWidgetTutorial: IHudLoadingScreenWidget { // 0x64
   // ctor: 0x00A35840
   // init: 0x00A35670
};
struct PlayerCardWidgetConfig { // 0x8
   // ctor: 0x00A65F00
   // init: 0x00A65F70
    bool mTeamBased; // 0x0
    uint8_t mCardType; // 0x1
    uint32_t m_0x7B9B52C3; // 0x4
};
struct t_0x97599AD3 { // 0x1C
   // ctor: 0x00A65F20
   // init: 0x00A65FE0
    hash_t m_0x634C549E; // 0x4
    hash_t m_0x299164E2; // 0x10
};
struct HudReplaySliderIconData { // 0x3C
   // ctor: 0x00A65F90
   // init: 0x00A660B0
    hash_t mType; // 0x0
    uint8_t mTooltipStyle; // 0x4
    string_t mElementName; // 0x8
    float_t mElementSpacer; // 0x14
    float_t mElementAlphaDefault; // 0x18
    float_t mElementAlphaSelected; // 0x1C
    float_t mElementAlphaUnselected; // 0x20
    vector_t<string_t> mTooltipIconNames; // 0x24
};
struct HudReplaySliderData { // 0x10
   // ctor: 0x00A65FB0
   // init: 0x00A65F50
    vector_t<HudReplaySliderIconData> mIconDataPriorityList; // 0x0
    float_t mTooltipEventWindow; // 0xC
};
struct WadFileDescriptor: PropertyBase { // 0x4
   // ctor: 0x00400000
   // init: 0x00400000
};
struct EsportsBannerMaterialController: SkinnedMeshDataMaterialController { // 0x4
   // ctor: 0x00A8C940
   // init: 0x00A8C920
};
struct BaseRigPoseModifierData: PropertyBase { // 0x4
   // ctor: 0x00400000
   // init: 0x00400000
};
struct ConformToPathRigPoseModifierData: BaseRigPoseModifierData { // 0x20
   // ctor: 0x00C73660
   // init: 0x00C73A80
    hash_t mStartingJointName; // 0x4
    hash_t mEndingJointName; // 0x8
    hash_t mDefaultMaskName; // 0xC
    float_t mMaxBoneAngle; // 0x10
    float_t mDampingValue; // 0x14
    float_t mVelMultiplier; // 0x18
    float_t mFrequency; // 0x1C
};
struct JointSnapRigPoseModifilerData: BaseRigPoseModifierData { // 0x4
   // ctor: 0x00C74830
   // init: 0x00C74150
};
struct LockRootOrientationRigPoseModifierData: BaseRigPoseModifierData { // 0x4
   // ctor: 0x00C74700
   // init: 0x00C74100
};
struct SyncedAnimationRigPoseModifierData: BaseRigPoseModifierData { // 0x8
   // ctor: 0x00C74320
   // init: 0x00C73A30
};
struct VertexAnimationRigPoseModifierData: BaseRigPoseModifierData { // 0x14
   // ctor: 0x00C74440
   // init: 0x00C740D0
    float_t mMaxSpeed; // 0x4
    float_t mStiffness; // 0x8
    float_t mMass; // 0xC
    float_t mDamping; // 0x10
};
struct AnimationGraphData { // 0x68
   // ctor: 0x00C737B0
   // init: 0x00C74160
    bool mUseCascadeBlend; // 0x0
    float_t mCascadeBlendValue; // 0x4
    map_t<hash_t, unique_ptr_t<ClipBaseData>> mClipDataMap; // 0x8
    map_t<hash_t, MaskData> mMaskDataMap; // 0x14
    map_t<hash_t, TrackData> mTrackDataMap; // 0x20
    map_t<hash_t, SyncGroupData> mSyncGroupDataMap; // 0x2C
    map_t<uint64_t, unique_ptr_t<BaseBlendData>> mBlendDataTable; // 0x38
};
struct AnimationResourceData { // 0x10
   // ctor: 0x00607F40
   // init: 0x00608200
    string_t mAnimationFilePath; // 0x0
};
struct MaskData { // 0x14
   // ctor: 0x0073B920
   // init: 0x0073B8F0
    uint32_t mId; // 0x0
    vector_t<float_t> mWeightList; // 0x4
};
struct Joint { // 0x6C
   // ctor: 0x00C73CD0
   // init: 0x00C73F60
    uint16_t mIndex; // 0x0
    uint16_t mFlags; // 0x2
    uint32_t mNameHash; // 0x4
    string_t mName; // 0x8
    float_t mRadius; // 0x14
    int16_t mParentIndex; // 0x18
};
struct RigResource { // 0x74
   // ctor: 0x00C74300
   // init: 0x00C74240
    string_t mName; // 0x0
    string_t mAssetName; // 0xC
    uint16_t mFlags; // 0x18
    vector_t<Joint> mJointList; // 0x1C
    vector_t<uint16_t> mShaderJointList; // 0x28
};
struct SyncGroupData { // 0x8
   // ctor: 0x00522060
   // init: 0x00521FF0
    uint32_t mType; // 0x0
};
struct TrackData { // 0x10
   // ctor: 0x00C73DE0
   // init: 0x00C73960
    uint8_t mPriority; // 0x0
    uint8_t mBlendMode; // 0x1
    float_t mBlendWeight; // 0x4
};
struct UpdaterData { // 0x14
   // ctor: 0x00C74540
   // init: 0x00C73FF0
    uint32_t mInputType; // 0x0
    uint32_t mOutputType; // 0x4
    vector_t<unique_ptr_t<ValueProcessorData>> mValueProcessorDataList; // 0x8
};
struct UpdaterResourceData { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    vector_t<UpdaterData> mUpdaterDataList; // 0x0
};
struct AtomicClipData: BlendableClipData { // 0x58
   // ctor: 0x00C74060
   // init: 0x00C73E80
    float_t mTickDuration; // 0x40
    AnimationResourceData mAnimationResourceData; // 0x44
    unique_ptr_t<UpdaterResourceData> mUpdaterResourceData; // 0x54
};
struct BlendableClipData: ClipBaseData { // 0x40
   // ctor: 0x00400000
   // init: 0x00400000
    hash_t mMaskDataName; // 0x1C
    hash_t mTrackDataName; // 0x20
    hash_t mSyncGroupDataName; // 0x24
    map_t<hash_t, unique_ptr_t<BaseEventData>> mEventDataMap; // 0x28
};
struct ConditionBoolClipData: ClipBaseData { // 0x38
   // ctor: 0x00C73590
   // init: 0x00C74040
    uint32_t mUpdaterType; // 0x1C
    bool mChangeAnimationMidPlay; // 0x20
    bool m_0x31DB4E6A; // 0x21
    bool m_0x92213DEE; // 0x22
    float_t mChildAnimDelaySwitchTime; // 0x24
    hash_t mTrueConditionClipName; // 0x28
    hash_t mFalseConditionClipName; // 0x2C
};
struct ConditionFloatPairData { // 0x14
   // ctor: 0x00C73D90
   // init: 0x00C73EC0
    hash_t mClipName; // 0x0
    float_t mValue; // 0x4
    float_t mHoldAnimationToHigher; // 0x8
    float_t mHoldAnimationToLower; // 0xC
};
struct ConditionFloatClipData: ClipBaseData { // 0x34
   // ctor: 0x00C736B0
   // init: 0x00C735B0
    uint32_t mUpdaterType; // 0x1C
    bool mChangeAnimationMidPlay; // 0x20
    bool m_0x31DB4E6A; // 0x21
    bool m_0xF88501B8; // 0x22
    bool m_0x92213DEE; // 0x23
    float_t mChildAnimDelaySwitchTime; // 0x24
    vector_t<ConditionFloatPairData> mConditionFloatPairDataList; // 0x28
};
struct ParallelClipData: ClipBaseData { // 0x34
   // ctor: 0x00C73A10
   // init: 0x00C741A0
    vector_t<hash_t> mClipNameList; // 0x1C
};
struct ParametricPairData { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    hash_t mClipName; // 0x0
    float_t mValue; // 0x4
};
struct ParametricClipData: BlendableClipData { // 0x54
   // ctor: 0x00C74620
   // init: 0x00C74480
    uint32_t mUpdaterType; // 0x40
    vector_t<ParametricPairData> mParametricPairDataList; // 0x44
};
struct SelectorPairData { // 0xC
   // ctor: 0x00C73A50
   // init: 0x00C74170
    hash_t mClipName; // 0x0
    float_t mProbability; // 0x4
};
struct SelectorClipData: ClipBaseData { // 0x28
   // ctor: 0x00C74500
   // init: 0x00C74720
    vector_t<SelectorPairData> mSelectorPairDataList; // 0x1C
};
struct SequencerClipData: ClipBaseData { // 0x34
   // ctor: 0x00C73BB0
   // init: 0x00C74030
    vector_t<hash_t> mClipNameList; // 0x1C
};
struct BaseBlendData: PropertyBase { // 0x4
   // ctor: 0x00400000
   // init: 0x00400000
};
struct BaseEventData: PropertyBase { // 0x14
   // ctor: 0x00C74670
   // init: 0x00C73E50
    bool mIsSelfOnly; // 0x4
    bool mFireIfAnimationEndsEarly; // 0x5
    float_t mStartFrame; // 0x8
    float_t mEndFrame; // 0xC
    hash_t mName; // 0x10
};
struct ClipBaseData: PropertyBase { // 0x1C
   // ctor: 0x00400000
   // init: 0x00400000
    uint32_t mFlags; // 0x8
    vector_t<hash_t> mAnimationInterruptionGroupNames; // 0xC
};
struct ConformToPathEventData: BaseEventData { // 0x24
   // ctor: 0x00C73FA0
   // init: 0x00C74580
    hash_t mMaskDataName; // 0x14
    float_t mBlendInTime; // 0x18
    float_t mBlendOutTime; // 0x1C
};
struct EnableLookAtEventData: BaseEventData { // 0x18
   // ctor: 0x00C742A0
   // init: 0x00C744D0
    bool mEnableLookAt; // 0x14
    bool mLockCurrentValues; // 0x15
};
struct FaceCameraEventData: BaseEventData { // 0x20
   // ctor: 0x00C745D0
   // init: 0x00C74380
    float_t m_0xB9CFC1AB; // 0x14
    float_t BlendInTime; // 0x18
    float_t BlendOutTime; // 0x1C
};
struct FadeEventData: BaseEventData { // 0x1C
   // ctor: 0x00C747C0
   // init: 0x00C73BD0
    float_t mTimeToFade; // 0x14
    float_t mTargetAlpha; // 0x18
};
struct IdleParticlesVisibilityEventData: BaseEventData { // 0x18
   // ctor: 0x00C73920
   // init: 0x00C736D0
    bool mShow; // 0x14
};
struct JointSnapEventData: BaseEventData { // 0x1C
   // ctor: 0x00C74250
   // init: 0x00C743C0
    hash_t mJointNameToOverride; // 0x14
    hash_t mJointNameToSnapTo; // 0x18
};
struct LinearTransformProcessorData: ValueProcessorData { // 0xC
   // ctor: 0x00C746B0
   // init: 0x00C73C10
    float_t mMultiplier; // 0x4
    float_t mIncrement; // 0x8
};
struct LockRootOrientationEventData: BaseEventData { // 0x14
   // ctor: 0x00C73EF0
   // init: 0x00C738F0
};
struct ParticleEventDataPair { // 0x8
   // ctor: 0x00522060
   // init: 0x00521FF0
    hash_t mBoneName; // 0x0
    hash_t mTargetBoneName; // 0x4
};
struct ParticleEventData: BaseEventData { // 0x3C
   // ctor: 0x00C742E0
   // init: 0x00C740C0
    hash_t mEffectKey; // 0x14
    hash_t mEnemyEffectKey; // 0x18
    string_t mEffectName; // 0x1C
    vector_t<ParticleEventDataPair> mParticleEventDataPairList; // 0x28
    bool mIsLoop; // 0x34
    bool mIsKillEvent; // 0x35
    bool mIsDetachable; // 0x36
    bool mScalePlaySpeedWithAnimation; // 0x37
    bool m_0xA3826203; // 0x38
};
struct SoundEventData: BaseEventData { // 0x24
   // ctor: 0x00C73750
   // init: 0x00C74770
    string_t mSoundName; // 0x14
    bool mIsLoop; // 0x20
    bool mIsKillEvent; // 0x21
    bool m_0x067227D6; // 0x22
};
struct StopAnimationEventData: BaseEventData { // 0x18
   // ctor: 0x00C738B0
   // init: 0x00C73990
    hash_t mStopAnimationName; // 0x14
};
struct SubmeshVisibilityEventData: BaseEventData { // 0x2C
   // ctor: 0x00C744C0
   // init: 0x00C73AC0
    vector_t<hash_t> mShowSubmeshList; // 0x14
    vector_t<hash_t> mHideSubmeshList; // 0x20
};
struct SyncedAnimationEventData: BaseEventData { // 0x18
   // ctor: 0x00C73B30
   // init: 0x00C74510
    float_t mLerpTime; // 0x14
};
struct TimeBlendData: BaseBlendData { // 0x8
   // ctor: 0x00C73D10
   // init: 0x00C73F30
    float_t mTime; // 0x4
};
struct TransitionClipBlendData: BaseBlendData { // 0xC
   // ctor: 0x00C74850
   // init: 0x00C74400
    hash_t mClipName; // 0x4
};
struct ValueProcessorData: PropertyBase { // 0x4
   // ctor: 0x00C73720
   // init: 0x00C74190
};
struct EngineFeatureToggles { // 0x8
   // ctor: 0x00CA8E40
   // init: 0x00CA90A0
    bool m_0x05FE6E49; // 0x4
    bool m_0xCDBBC6E1; // 0x5
};
struct t_0xC0C056F1: GenericMapPlaceable { // 0xA0
   // ctor: 0x00CA9100
   // init: 0x00CA8EC0
    string_t PropName; // 0x58
    uint32_t SkinId; // 0x64
    bool PlayIdleAnimation; // 0x68
    string_t IdleAnimationName; // 0x6C
    int32_t Quality; // 0x7C
    bool IsClickable; // 0x80
    bool EyeCandy; // 0x9C
};
struct MapAudio: GenericMapPlaceable { // 0x74
   // ctor: 0x00CA8DE0
   // init: 0x00CA9320
    string_t EventName; // 0x58
    uint32_t AudioType; // 0x64
    float_t StartTime; // 0x68
    float_t m_0xDF1B8A47; // 0x6C
    float_t m_0x518F49B9; // 0x70
};
struct MapCamera: MapPlaceable { // 0x6C
   // ctor: 0x00CA8FE0
   // init: 0x00CA9250
    float_t m_0x6F3E4327; // 0x58
    float_t m_0x563A1941; // 0x5C
    float_t Pitch; // 0x60
    float_t Yaw; // 0x64
    float_t FieldOfView; // 0x68
};
struct MapComponent: PropertyBase { // 0x4
   // ctor: 0x00400000
   // init: 0x00400000
};
struct MapContainer { // 0x3C
   // ctor: 0x00CA8FC0
   // init: 0x00CA8DD0
    string_t MapPath; // 0x0
    vector_t<unique_ptr_t<MapComponent>> Components; // 0xC
    point2D_t BoundsMin; // 0x18
    point2D_t BoundsMax; // 0x20
    float_t LowestWalkableHeight; // 0x28
    float_t m_0xF010DEFB; // 0x2C
    map_t<hash_t, link_ptr_t<MapPlaceableContainer>> Chunks; // 0x30
};
struct MapContainsOtherMaps: MapComponent { // 0x8
   // ctor: 0x00CA8FA0
   // init: 0x00CA93C0
    link_ptr_t<MapPlaceableContainer> MapContainerLocations; // 0x4
};
struct LaneData { // 0x18
   // ctor: 0x00608900
   // init: 0x00608F30
    vector_t<string_t> mNavigationPoints; // 0x0
    vector_t<string_t> mContainedRegions; // 0xC
};
struct MapLaneComponent: MapComponent { // 0x10
   // ctor: 0x00CA93E0
   // init: 0x00CA92F0
    vector_t<LaneData> mLanes; // 0x4
};
struct MapLocator: GenericMapPlaceable { // 0x58
   // ctor: 0x00CA8F20
   // init: 0x00CA90C0
};
struct MapPathSegment: PropertyBase { // 0x20
   // ctor: 0x00400000
   // init: 0x00400000
    point3D_t EndPosition; // 0x4
};
struct MapPathLineSegment: MapPathSegment { // 0x20
   // ctor: 0x00CA9270
   // init: 0x00CA8ED0
};
struct MapPathCurveSegment: MapPathSegment { // 0x68
   // ctor: 0x00CA8DB0
   // init: 0x00CA9310
    point3D_t ControlPoint1; // 0x20
    point3D_t ControlPoint2; // 0x2C
};
struct MapMotionPath: MapPlaceable { // 0x78
   // ctor: 0x00CA9410
   // init: 0x00CA92E0
    vector_t<unique_ptr_t<MapPathSegment>> Segments; // 0x58
};
struct MapNavGrid: MapComponent { // 0x10
   // ctor: 0x00CA9370
   // init: 0x00CA9070
    string_t NavGridPath; // 0x4
};
struct MapPlaceable: PropertyBase { // 0x58
   // ctor: 0x00CA9430
   // init: 0x00CA9160
    matrix44_t Transform; // 0x4
    string_t Name; // 0x44
    uint8_t mVisibilityFlags; // 0x50
};
struct GenericMapPlaceable: MapPlaceable { // 0x58
   // ctor: 0x00CA9020
   // init: 0x00CA8E00
};
struct MapPlaceableContainer { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    map_t<hash_t, unique_ptr_t<MapPlaceable>> Items; // 0x0
};
struct MapPrefabInstance: MapPlaceable { // 0x5C
   // ctor: 0x00CA91A0
   // init: 0x00CA8E70
    link_ptr_t<MapPlaceableContainer> PrefabDefinition; // 0x58
};
struct MapThemeMusic: MapComponent { // 0x1C
   // ctor: 0x00CA9200
   // init: 0x00CA9120
    string_t LocalThemeMusic; // 0x4
    string_t ThemeMusicTransitionEvent; // 0x10
};
struct RegionsThatAllowContent { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    vector_t<hash_t> mRegionList; // 0x0
};
struct RegionSettings { // 0x14
   // ctor: 0x00CA9330
   // init: 0x00CA8D80
    map_t<hash_t, RegionsThatAllowContent> mContentTypeAllowedSettings; // 0x8
};
struct FontLocaleType { // 0x30
   // ctor: 0x00CAE370
   // init: 0x00CAE3D0
    string_t LocaleName; // 0x0
    string_t mFontFilePath; // 0xC
    string_t FontFilePathBold; // 0x18
    string_t FontFilePathItalics; // 0x24
};
struct FontResolution { // 0x14
   // ctor: 0x00CAE5B0
   // init: 0x00CAE450
    uint32_t ScreenHeight; // 0x0
    uint32_t FontSize; // 0x4
    uint32_t OutlineSize; // 0x8
    int32_t ShadowDepthX; // 0xC
    int32_t ShadowDepthY; // 0x10
};
struct FontLocaleResolutions { // 0x18
   // ctor: 0x00CAE160
   // init: 0x00CAE270
    string_t LocaleName; // 0x0
    vector_t<FontResolution> Resolutions; // 0xC
};
struct FontType { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    vector_t<FontLocaleType> LocaleTypes; // 0x0
};
struct FontResolutionData { // 0x10
   // ctor: 0x00CAE0E0
   // init: 0x00CAE2E0
    bool AutoScale; // 0x0
    vector_t<FontLocaleResolutions> LocaleResolutions; // 0x4
};
struct GameFontDescription { // 0x60
   // ctor: 0x00CAE430
   // init: 0x00CAE660
    string_t Name; // 0x0
    link_ptr_t<FontType> TypeData; // 0xC
    link_ptr_t<FontResolutionData> ResolutionData; // 0x10
    color_t Color; // 0x14
    color_t OutlineColor; // 0x18
    color_t ShadowColor; // 0x1C
    color_t GlowColor; // 0x20
    color_t m_0x3CC9AC15; // 0x24
    optional_t<color_t> ColorblindColor; // 0x28
    optional_t<color_t> ColorblindOutlineColor; // 0x30
    optional_t<color_t> ColorblindShadowColor; // 0x38
    optional_t<color_t> ColorblindGlowColor; // 0x40
    optional_t<color_t> m_0xC2008B7B; // 0x48
    string_t FillTextureName; // 0x50
};
struct CssStyle { // 0xC
   // ctor: 0x00CAE5F0
   // init: 0x00CAE3B0
    optional_t<color_t> Color; // 0x0
    optional_t<bool> Bold; // 0x8
    optional_t<bool> Italics; // 0x9
    optional_t<bool> Underline; // 0xA
};
struct CssIcon { // 0x18
   // ctor: 0x00CAE6D0
   // init: 0x00CAE710
    point2D_t Xy; // 0x0
    point2D_t Wh; // 0x8
    float_t m_0x81E208EF; // 0x10
};
struct CssSheet { // 0x28
   // ctor: 0x00CAE250
   // init: 0x00CAE590
    map_t<string_t, CssStyle> Styles; // 0x0
    string_t IconTexture; // 0xC
    map_t<string_t, CssIcon> Icons; // 0x18
};
struct TooltipFormat { // 0xCC
   // ctor: 0x00CAE6B0
   // init: 0x00CAE580
    string_t mObjectName; // 0x0
    unordered_map_t<string_t, string_t> mInputLocKeysWithDefaults; // 0xC
    vector_t<string_t> mListNames; // 0x2C
    unordered_map_t<string_t, string_t> mListTypeChoices; // 0x38
    unordered_map_t<uint32_t, string_t> mListStyles; // 0x58
    bool mUsesListValues; // 0x78
    string_t mListValueSeparator; // 0x7C
    string_t mListGridPrefix; // 0x88
    string_t mListGridPostfix; // 0x94
    string_t mListGridSeparator; // 0xA0
    unordered_map_t<string_t, string_t> mOutputStrings; // 0xAC
};
struct TooltipInstanceListElement { // 0x24
   // ctor: 0x00CAE6A0
   // init: 0x00CAE480
    string_t Type; // 0x0
    int32_t TypeIndex; // 0xC
    float_t Multiplier; // 0x10
    string_t NameOverride; // 0x14
    uint32_t Style; // 0x20
};
struct TooltipInstanceList { // 0x10
   // ctor: 0x00CAE4D0
   // init: 0x00CAE560
    uint32_t LevelCount; // 0x0
    vector_t<TooltipInstanceListElement> Elements; // 0x4
};
struct TooltipInstance: PropertyBase { // 0x74
   // ctor: 0x00CAE1A0
   // init: 0x00CAE740
    string_t mObjectName; // 0x4
    link_ptr_t<TooltipFormat> mFormat; // 0x10
    unordered_map_t<string_t, string_t> mLocKeys; // 0x14
    unordered_map_t<string_t, TooltipInstanceList> mLists; // 0x34
};
struct ValueFloat { // 0x8
   // ctor: 0x00522060
   // init: 0x00521FF0
    float_t ConstantValue; // 0x0
    unique_ptr_t<VfxAnimatedFloatVariableData> Dynamics; // 0x4
};
struct IntegratedValueFloat: ValueFloat { // 0xC
   // ctor: 0x00CD9EC0
   // init: 0x00CD9BA0
};
struct ValueVector2 { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    point2D_t ConstantValue; // 0x0
    unique_ptr_t<VfxAnimatedVector2fVariableData> Dynamics; // 0x8
};
struct IntegratedValueVector2: ValueVector2 { // 0x10
   // ctor: 0x00CD9F50
   // init: 0x00CD90C0
};
struct ValueVector3 { // 0x10
   // ctor: 0x005CA800
   // init: 0x005CA650
    point3D_t ConstantValue; // 0x0
    unique_ptr_t<VfxAnimatedVector3fVariableData> Dynamics; // 0xC
};
struct IntegratedValueVector3: ValueVector3 { // 0x14
   // ctor: 0x00CDA000
   // init: 0x00CD9400
};
struct ValueColor { // 0x14
   // ctor: 0x0073B920
   // init: 0x0073B8F0
    point4D_t ConstantValue; // 0x0
    unique_ptr_t<VfxAnimatedColorVariableData> Dynamics; // 0x10
};
struct VfxAnimatedFloatVariableData { // 0x30
   // ctor: 0x00CD9A10
   // init: 0x00CD9DD0
    array_t<unique_ptr_t<VfxProbabilityTableData>, 1> ProbabilityTables; // 0x0
    vector_t<float_t> Times; // 0x4
    vector_t<float_t> Values; // 0x10
};
struct VfxAnimatedVector2fVariableData { // 0x38
   // ctor: 0x00CD8E00
   // init: 0x00CDA1A0
    array_t<unique_ptr_t<VfxProbabilityTableData>, 2> ProbabilityTables; // 0x0
    vector_t<float_t> Times; // 0x8
    vector_t<point2D_t> Values; // 0x14
};
struct VfxAnimatedVector3fVariableData { // 0x40
   // ctor: 0x00CD92A0
   // init: 0x00CD8E10
    array_t<unique_ptr_t<VfxProbabilityTableData>, 3> ProbabilityTables; // 0x0
    vector_t<float_t> Times; // 0xC
    vector_t<point3D_t> Values; // 0x18
};
struct VfxAnimatedColorVariableData { // 0x48
   // ctor: 0x00CDA340
   // init: 0x00CD9390
    array_t<unique_ptr_t<VfxProbabilityTableData>, 4> ProbabilityTables; // 0x0
    vector_t<float_t> Times; // 0x10
    vector_t<point4D_t> Values; // 0x1C
};
struct VfxSoftParticleDefinitionData { // 0x20
   // ctor: 0x00CD8C00
   // init: 0x00CD9B20
    float_t BeginIn; // 0x0
    float_t BeginOut; // 0x4
    float_t DeltaIn; // 0x8
    float_t DeltaOut; // 0xC
};
struct FlexValueVector3 { // 0x14
   // ctor: 0x00CDA230
   // init: 0x00CD8BC0
    uint32_t mFlexId; // 0x0
    ValueVector3 mValue; // 0x4
};
struct FlexValueVector2 { // 0x10
   // ctor: 0x005CA800
   // init: 0x005CA650
    uint32_t mFlexId; // 0x0
    ValueVector2 mValue; // 0x4
};
struct FlexValueFloat { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    uint32_t mFlexId; // 0x0
    ValueFloat mValue; // 0x4
};
struct FlexTypeFloat { // 0x8
   // ctor: 0x00522060
   // init: 0x00521FF0
    uint32_t mFlexId; // 0x0
    float_t mValue; // 0x4
};
struct ColorGraphMaterialDriver: IDynamicMaterialDriver { // 0x50
   // ctor: 0x00CD8DE0
   // init: 0x00CD9030
    unique_ptr_t<IDynamicMaterialFloatDriver> Driver; // 0x4
    VfxAnimatedColorVariableData Colors; // 0x8
};
struct VfxFieldAccelerationDefinitionData { // 0x14
   // ctor: 0x00CD9940
   // init: 0x00CD9230
    bool IsLocalSpace; // 0x0
    ValueVector3 Acceleration; // 0x4
};
struct VfxFieldAttractionDefinitionData { // 0x20
   // ctor: 0x00CD8C00
   // init: 0x00CD9B20
    ValueVector3 Position; // 0x0
    ValueFloat Radius; // 0x10
    ValueFloat Acceleration; // 0x18
};
struct VfxFieldCollectionDefinitionData { // 0x3C
   // ctor: 0x00CD8FC0
   // init: 0x00CD9560
    vector_t<VfxFieldAccelerationDefinitionData> FieldAccelerationDefinitions; // 0x0
    vector_t<VfxFieldAttractionDefinitionData> FieldAttractionDefinitions; // 0xC
    vector_t<VfxFieldDragDefinitionData> FieldDragDefinitions; // 0x18
    vector_t<VfxFieldNoiseDefinitionData> FieldNoiseDefinitions; // 0x24
    vector_t<VfxFieldOrbitalDefinitionData> FieldOrbitalDefinitions; // 0x30
};
struct VfxFieldDragDefinitionData { // 0x20
   // ctor: 0x00CD8C00
   // init: 0x00CD9B20
    ValueVector3 Position; // 0x0
    ValueFloat Radius; // 0x10
    ValueFloat Strength; // 0x18
};
struct VfxFieldNoiseDefinitionData { // 0x34
   // ctor: 0x00CD9B80
   // init: 0x00CD9D70
    ValueVector3 Position; // 0x0
    ValueFloat Radius; // 0x10
    ValueFloat Frequency; // 0x18
    ValueFloat VelocityDelta; // 0x20
    point3D_t AxisFraction; // 0x28
};
struct VfxFieldOrbitalDefinitionData { // 0x14
   // ctor: 0x00CD9710
   // init: 0x00CD9690
    bool IsLocalSpace; // 0x0
    ValueVector3 Direction; // 0x4
};
struct FloatGraphMaterialDriver: IDynamicMaterialDriver { // 0x38
   // ctor: 0x00CD94E0
   // init: 0x00CD9470
    unique_ptr_t<IDynamicMaterialFloatDriver> Driver; // 0x4
    VfxAnimatedFloatVariableData Graph; // 0x8
};
struct IVfxMaterialDriver: PropertyBase { // 0x4
   // ctor: 0x00400000
   // init: 0x00400000
};
struct VfxMaterialOverrideDefinitionData { // 0x48
   // ctor: 0x00CDA490
   // init: 0x00CD9600
    int32_t Priority; // 0x0
    optional_t<string_t> SubMeshName; // 0x4
    uint32_t OverrideBlendMode; // 0x14
    string_t BaseTexture; // 0x18
    string_t GlossTexture; // 0x24
    string_t TransitionTexture; // 0x30
    float_t TransitionSample; // 0x3C
    uint32_t TransitionSource; // 0x40
    link_ptr_t<IMaterialDef> Material; // 0x44
};
struct VfxProbabilityTableData { // 0x20
   // ctor: 0x00CD9AD0
   // init: 0x00CD9260
    vector_t<float_t> KeyTimes; // 0x0
    vector_t<float_t> KeyValues; // 0xC
    float_t SingleValue; // 0x18
};
struct VfxSystemDefinitionData: IResource { // 0xEC
   // ctor: 0x00CD9A60
   // init: 0x00CD8DD0
    vector_t<VfxMaterialOverrideDefinitionData> MaterialOverrideDefinitions; // 0x8
    vector_t<unique_ptr_t<VfxEmitterDefinitionData>> ComplexEmitterDefinitionData; // 0x14
    vector_t<unique_ptr_t<VfxEmitterDefinitionData>> SimpleEmitterDefinitionData; // 0x20
    float_t VisibilityRadius; // 0x2C
    string_t ParticleName; // 0x30
    string_t ParticlePath; // 0x3C
    optional_t<float_t> OverrideScaleCap; // 0x48
    string_t SoundOnCreateDefault; // 0x4C
    string_t VoiceOverOnCreateDefault; // 0x58
    string_t SoundPersistentDefault; // 0x64
    string_t VoiceOverPersistentDefault; // 0x70
    string_t AssetCategory; // 0x7C
    int32_t AudioParameterFlexId; // 0x88
    float_t AudioParameterTimeScaledDuration; // 0x8C
    uint8_t DrawingLayer; // 0x90
    uint8_t Flags; // 0x91
    float_t BuildUpTime; // 0x94
    float_t SelfIllumination; // 0x98
    vector_t<VfxAssetRemap> AssetRemappingTable; // 0x9C
    point3D_t SystemTranslation; // 0xA8
    point3D_t SystemScale; // 0xB4
    float_t HudLayerDimension; // 0xC0
    float_t HudLayerAspect; // 0xC4
    bool HudAnchorPositionFromWorldProjection; // 0xC8
    bool ScaleDynamicallyWithAttachedBone; // 0xC9
    bool mEyeCandy; // 0xCA
    bool m_0xCF08F8E6; // 0xCB
};
struct VfxMigrationResources { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    map_t<hash_t, link_ptr_t<VfxSystemDefinitionData>> ResourceMap; // 0x0
};
struct VfxAssetRemap { // 0x14
   // ctor: 0x00609100
   // init: 0x00608DA0
    uint32_t Type; // 0x0
    hash_t OldAsset; // 0x4
    string_t NewAsset; // 0x8
};
struct VfxColorOverLifeMaterialDriver: IVfxMaterialDriver { // 0x50
   // ctor: 0x00CD95E0
   // init: 0x00CD9610
    uint8_t Frequency; // 0x4
    VfxAnimatedColorVariableData Colors; // 0x8
};
struct VfxShape { // 0x38
   // ctor: 0x00CD91D0
   // init: 0x00CD94D0
    ValueVector3 BirthTranslation; // 0x0
    ValueVector3 EmitOffset; // 0x10
    vector_t<ValueFloat> EmitRotationAngles; // 0x20
    vector_t<point3D_t> EmitRotationAxes; // 0x2C
};
struct VfxEmitterDefinitionData { // 0x50C
   // ctor: 0x00CD9FA0
   // init: 0x00CD8DB0
    string_t EmitterName; // 0x0
    bool Disabled; // 0xC
    bool DisableBackfaceCull; // 0xD
    bool IsTexturePixelated; // 0xE
    link_ptr_t<IMaterialDef> Material; // 0x10
    map_t<string_t, unique_ptr_t<IVfxMaterialDriver>> MaterialDrivers; // 0x14
    uint8_t RenderPhaseOverride; // 0x1C
    uint8_t BlendMode; // 0x1D
    uint8_t ColorblindVisibility; // 0x1E
    unique_ptr_t<VfxFieldCollectionDefinitionData> FieldCollectionDefinition; // 0x20
    vector_t<VfxMaterialOverrideDefinitionData> MaterialOverrideDefinitions; // 0x24
    unique_ptr_t<VfxSoftParticleDefinitionData> SoftParticleParams; // 0x30
    unique_ptr_t<VfxAlphaErosionDefinitionData> AlphaErosionDefinition; // 0x34
    unique_ptr_t<VfxPaletteDefinitionData> PaletteDefinition; // 0x38
    unique_ptr_t<VfxReflectionDefinitionData> ReflectionDefinition; // 0x3C
    unique_ptr_t<VfxDistortionDefinitionData> DistortionDefinition; // 0x40
    unique_ptr_t<VfxEmissionSurfaceData> EmissionSurfaceDefinition; // 0x44
    unique_ptr_t<VfxPrimitiveBase> Primitive; // 0x48
    int16_t Pass; // 0x4C
    uint8_t MiscRenderFlags; // 0x4E
    uint8_t MeshRenderFlags; // 0x4F
    uint8_t ColorRenderFlags; // 0x50
    uint8_t StencilMode; // 0x51
    uint8_t StencilRef; // 0x52
    uint8_t AlphaRef; // 0x53
    point2D_t DepthBiasFactors; // 0x54
    float_t SliceTechniqueRange; // 0x5C
    point2D_t TexDiv; // 0x60
    point2D_t TexDivMult; // 0x68
    string_t Texture; // 0x70
    string_t TextureMult; // 0x7C
    string_t ParticleColorTexture; // 0x88
    string_t FalloffTexture; // 0x94
    uint8_t TexAddressModeMult; // 0xA0
    uint8_t UvMode; // 0xA1
    uint8_t ColorLookUpTypeX; // 0xA2
    uint8_t ColorLookUpTypeY; // 0xA3
    point2D_t ColorLookUpScales; // 0xA4
    point2D_t ColorLookUpOffsets; // 0xAC
    point4D_t ModulationFactor; // 0xB4
    float_t ScaleEmitOffsetByBoundObjectSize; // 0xC4
    float_t ScaleBirthScaleByBoundObjectSize; // 0xC8
    float_t ScaleEmitOffsetByBoundObjectHeight; // 0xCC
    float_t ScaleBirthScaleByBoundObjectHeight; // 0xD0
    float_t ScaleEmitOffsetByBoundObjectRadius; // 0xD4
    float_t ScaleBirthScaleByBoundObjectRadius; // 0xD8
    vector_t<string_t> KeywordsExcluded; // 0xDC
    vector_t<string_t> KeywordsRequired; // 0xE8
    vector_t<string_t> KeywordsIncluded; // 0xF4
    vector_t<string_t> ExcludedAttachmentTypes; // 0x100
    uint8_t Importance; // 0x10C
    uint8_t CensorPolicy; // 0x10D
    uint8_t SpectatorPolicy; // 0x10E
    uint8_t ParticleLingerType; // 0x10F
    ValueFloat ParticleLifetime; // 0x110
    optional_t<float_t> Lifetime; // 0x118
    unique_ptr_t<FlexValueFloat> FlexParticleLifetime; // 0x11C
    optional_t<float_t> ParticleLinger; // 0x120
    optional_t<float_t> EmitterLinger; // 0x124
    ValueVector3 BirthVelocity; // 0x128
    unique_ptr_t<FlexValueVector3> FlexBirthTranslation; // 0x138
    unique_ptr_t<FlexValueVector3> FlexBirthVelocity; // 0x13C
    unique_ptr_t<FlexTypeFloat> FlexScaleBirthScale; // 0x140
    unique_ptr_t<FlexValueVector2> FlexBirthUvScrollRate; // 0x144
    unique_ptr_t<FlexValueVector2> FlexBirthUvScrollRateMult; // 0x148
    ValueColor BirthColor; // 0x14C
    ValueVector3 BirthAcceleration; // 0x160
    ValueVector3 BirthRotationalAcceleration; // 0x170
    ValueVector3 BirthDrag; // 0x180
    ValueVector3 BirthOrbitalVelocity; // 0x190
    ValueFloat BirthFrameRate; // 0x1A0
    ValueVector2 BirthUvoffset; // 0x1A8
    ValueVector2 BirthUvoffsetMult; // 0x1B4
    unique_ptr_t<FlexValueVector2> FlexBirthUvoffset; // 0x1C0
    ValueFloat Rate; // 0x1C4
    ValueVector2 RateByVelocityFunction; // 0x1CC
    optional_t<float_t> MaximumRateByVelocity; // 0x1D8
    unique_ptr_t<FlexValueFloat> FlexRate; // 0x1DC
    float_t TimeBeforeFirstEmission; // 0x1E0
    float_t m_0xCEF2BA70; // 0x1E4
    optional_t<float_t> TimeActiveDuringPeriod; // 0x1E8
    optional_t<float_t> Period; // 0x1EC
    VfxShape Shape; // 0x1F0
    unique_ptr_t<FlexTypeFloat> FlexScaleEmitOffset; // 0x228
    unique_ptr_t<FlexValueVector3> FlexOffset; // 0x22C
    uint16_t StartFrame; // 0x230
    uint16_t NumFrames; // 0x232
    float_t FrameRate; // 0x234
    string_t SoundOnCreateName; // 0x238
    string_t VoiceOverOnCreateName; // 0x244
    string_t SoundPersistentName; // 0x250
    string_t VoiceOverPersistentName; // 0x25C
    point4D_t CensorModulateValue; // 0x268
    string_t EmissionMeshName; // 0x278
    point3D_t OffsetLifetimeScaling; // 0x284
    uint8_t OffsetLifeScalingSymmetryMode; // 0x290
    point2D_t EmitterUvScrollRate; // 0x294
    point2D_t EmitterUvScrollRateMult; // 0x29C
    point3D_t TranslationOverride; // 0x2A4
    point3D_t RotationOverride; // 0x2B0
    point3D_t ScaleOverride; // 0x2BC
    unique_ptr_t<FlexTypeFloat> FlexInstanceScale; // 0x2C8
    bool UvScrollAlphaMult; // 0x2CC
    bool ParticleIsLocalOrientation; // 0x2CC
    bool IsDirectionOriented; // 0x2CC
    bool IsUniformScale; // 0x2CC
    bool HasPostRotateOrientation; // 0x2CC
    bool IsRandomStartFrame; // 0x2CC
    bool IsRandomStartFrameMult; // 0x2CC
    bool DoesCastShadow; // 0x2CC
    bool IsRotationEnabled; // 0x2CD
    bool UvScrollClamp; // 0x2CD
    bool UvScrollClampMult; // 0x2CD
    bool IsFollowingTerrain; // 0x2CD
    bool IsGroundLayer; // 0x2CD
    bool UseEmissionMeshNormalForBirth; // 0x2CD
    bool UseNavmeshMask; // 0x2CD
    bool m_0x676949A1; // 0x2CD
    bool m_0x538EFFA4; // 0x2CE
    bool IsSingleParticle; // 0x2CE
    bool m_0xBD9B83C7; // 0x2CE
    bool UseLingerRotation; // 0x2CE
    bool IsLocalOrientation; // 0x2CE
    bool UseLingerScale; // 0x2CE
    bool HasFixedOrbit; // 0x2CE
    bool LockedToEmitter; // 0x2CE
    bool DoesLifetimeScale; // 0x2CF
    bool DoesParticleLifetimeScale; // 0x2CF
    bool UseLingerVelocity; // 0x2CF
    bool UseLingerDrag; // 0x2CF
    bool UseLingerAcceleration; // 0x2CF
    bool UseLingerColor; // 0x2CF
    bool m_0x51AF37D2; // 0x2CF
    bool ScaleUpFromOrigin; // 0x2CF
    point3D_t PostRotateOrientationAxis; // 0x2D0
    ValueVector2 BirthUvScrollRate; // 0x2DC
    ValueVector2 BirthUvScrollRateMult; // 0x2E8
    ValueFloat BirthUvRotateRate; // 0x2F4
    ValueFloat BirthUvRotateRateMult; // 0x2FC
    ValueFloat UvRotation; // 0x304
    IntegratedValueVector2 ParticleUvScrollRate; // 0x314
    IntegratedValueVector2 ParticleUvScrollRateMult; // 0x324
    IntegratedValueFloat ParticleUvRotateRate; // 0x334
    IntegratedValueFloat ParticleUvRotateRateMult; // 0x340
    float_t DirectionVelocityScale; // 0x34C
    float_t DirectionVelocityMinScale; // 0x350
    float_t UvParallaxScale; // 0x354
    ValueVector3 Velocity; // 0x358
    ValueVector3 Acceleration; // 0x368
    IntegratedValueVector3 WorldAcceleration; // 0x378
    ValueColor Color; // 0x38C
    ValueFloat BindWeight; // 0x3A0
    ValueVector3 Drag; // 0x3A8
    ValueVector3 LingerVelocity; // 0x3B8
    ValueVector3 LingerAcceleration; // 0x3C8
    ValueColor LingerColor; // 0x3D8
    ValueVector3 LingerDrag; // 0x3EC
    VfxChildParticleSetDefinitionData ChildParticleSetDefinition; // 0x3FC
    float_t EmissionMeshScale; // 0x420
    uint8_t TexAddressModeBase; // 0x424
    uint8_t FixedOrbitType; // 0x425
    uint8_t Orientation; // 0x426
    point2D_t ParticleBind; // 0x428
    point2D_t ScaleBias; // 0x430
    ValueVector3 BirthRotation0; // 0x438
    ValueVector3 BirthScale0; // 0x448
    ValueVector3 BirthRotationalVelocity0; // 0x458
    unique_ptr_t<FlexValueVector3> FlexBirthRotationalVelocity0; // 0x468
    ValueVector3 Scale0; // 0x46C
    IntegratedValueVector3 Rotation0; // 0x47C
    ValueVector2 UvScale; // 0x490
    ValueVector2 UvScaleMult; // 0x49C
    point2D_t UvTransformCenter; // 0x4A8
    point2D_t UvTransformCenterMult; // 0x4B0
    ValueVector3 LingerRotation0; // 0x4B8
    ValueVector3 LingerScale0; // 0x4C8
    ValueFloat BirthRotation1; // 0x4D8
    ValueFloat BirthScale1; // 0x4E0
    ValueFloat BirthRotationalVelocity1; // 0x4E8
    unique_ptr_t<FlexValueFloat> FlexBirthRotationalVelocity1; // 0x4F0
    point2D_t UvScrollRate1; // 0x4F4
    ValueFloat Scale1; // 0x4FC
    ValueFloat Rotation1; // 0x504
};
struct VfxChildIdentifier { // 0x14
   // ctor: 0x00609100
   // init: 0x00608DA0
    link_ptr_t<VfxSystemDefinitionData> Effect; // 0x0
    hash_t EffectKey; // 0x4
    string_t EffectName; // 0x8
};
struct VfxChildParticleSetDefinitionData { // 0x24
   // ctor: 0x0075D1F0
   // init: 0x0075D240
    vector_t<VfxChildIdentifier> ChildrenIdentifiers; // 0x0
    vector_t<string_t> BoneToSpawnAt; // 0xC
    ValueFloat ChildrenProbability; // 0x18
    bool ChildEmitOnDeath; // 0x20
};
struct VfxAlphaErosionDefinitionData { // 0x48
   // ctor: 0x00CD98C0
   // init: 0x00CD9980
    ValueFloat ErosionDriveCurve; // 0x0
    uint32_t ErosionDriveSource; // 0x8
    bool UseLingerErosionDriveCurve; // 0xC
    ValueFloat LingerErosionDriveCurve; // 0x10
    float_t ErosionFeatherIn; // 0x18
    float_t ErosionFeatherOut; // 0x1C
    float_t ErosionSliceWidth; // 0x20
    string_t ErosionMapName; // 0x24
    uint8_t ErosionMapAddressMode; // 0x30
    ValueColor ErosionMapChannelMixer; // 0x34
};
struct VfxPaletteDefinitionData { // 0x48
   // ctor: 0x00CD8D10
   // init: 0x00CD97D0
    string_t PaletteTexture; // 0x0
    uint8_t PaletteTextureAddressMode; // 0xC
    ValueColor PalleteSrcMixColor; // 0x10
    ValueVector3 PaletteSelector; // 0x24
    ValueFloat m_0x34D8FAC6; // 0x34
    ValueFloat m_0x44FD44CB; // 0x3C
    int32_t PaletteCount; // 0x44
};
struct VfxReflectionDefinitionData { // 0x3C
   // ctor: 0x00CD9FD0
   // init: 0x00CDA1F0
    string_t ReflectionMapTexture; // 0x0
    float_t ReflectionOpacityDirect; // 0xC
    float_t ReflectionOpacityGlancing; // 0x10
    float_t ReflectionFresnel; // 0x14
    point4D_t ReflectionFresnelColor; // 0x18
    float_t Fresnel; // 0x28
    point4D_t FresnelColor; // 0x2C
};
struct VfxDistortionDefinitionData { // 0x14
   // ctor: 0x00CD8A90
   // init: 0x00CDA500
    float_t Distortion; // 0x0
    uint8_t DistortionMode; // 0x4
    string_t NormalMapTexture; // 0x8
};
struct VfxProjectionDefinitionData { // 0x8
   // ctor: 0x00CD9B60
   // init: 0x00CD9D50
    float_t mYRange; // 0x0
    float_t mFading; // 0x4
};
struct VfxTrailDefinitionData { // 0x1C
   // ctor: 0x00CD9C40
   // init: 0x00CDA300
    ValueVector3 mBirthTilingSize; // 0x0
    float_t mCutoff; // 0x10
    int32_t mMaxAddedPerFrame; // 0x14
    uint8_t mSmoothingMode; // 0x18
    uint8_t mMode; // 0x19
};
struct VfxBeamDefinitionData { // 0x48
   // ctor: 0x00CD9DB0
   // init: 0x00CD9A40
    ValueVector3 mBirthTilingSize; // 0x0
    uint8_t mMode; // 0x10
    uint8_t mTrailMode; // 0x11
    int32_t mSegments; // 0x14
    point3D_t mLocalSpaceSourceOffset; // 0x18
    point3D_t mLocalSpaceTargetOffset; // 0x24
    bool mIsColorBindedWithDistance; // 0x30
    ValueColor mAnimatedColorWithDistance; // 0x34
};
struct VfxEmissionSurfaceData { // 0x2C
   // ctor: 0x00CD9FC0
   // init: 0x00CD92C0
    string_t MeshName; // 0x0
    string_t SkeletonName; // 0xC
    string_t AnimationName; // 0x18
    float_t MeshScale; // 0x24
    uint16_t MaxJointWeights; // 0x28
    bool UseAvatarPose; // 0x2A
    bool UseSurfaceNormalForBirthPhysics; // 0x2B
};
struct VfxMeshDefinitionData { // 0x58
   // ctor: 0x00CD9EA0
   // init: 0x00CDA2F0
    string_t mMeshName; // 0x0
    string_t mMeshSkeletonName; // 0xC
    string_t mSimpleMeshName; // 0x18
    vector_t<hash_t> mSubmeshesToDraw; // 0x24
    vector_t<hash_t> mSubmeshesToDrawAlways; // 0x30
    bool mLockMeshToAttachment; // 0x3C
    string_t mAnimationName; // 0x40
    vector_t<string_t> mAnimationVariants; // 0x4C
};
struct VfxPrimitiveBase: PropertyBase { // 0x8
   // ctor: 0x00400000
   // init: 0x00400000
};
struct VfxPrimitiveCameraQuad: VfxPrimitiveBase { // 0x8
   // ctor: 0x00CDA060
   // init: 0x00CD9180
};
struct VfxPrimitiveArbitraryQuad: VfxPrimitiveBase { // 0x8
   // ctor: 0x00CD9010
   // init: 0x00CD8B20
};
struct VfxPrimitiveRay: VfxPrimitiveBase { // 0x8
   // ctor: 0x00CD8EC0
   // init: 0x00CD8BF0
};
struct VfxPrimitiveProjectionBase: VfxPrimitiveBase { // 0x10
   // ctor: 0x00400000
   // init: 0x00400000
    VfxProjectionDefinitionData mProjection; // 0x8
};
struct VfxPrimitivePlanarProjection: VfxPrimitiveProjectionBase { // 0x10
   // ctor: 0x00CD90E0
   // init: 0x00CDA4B0
};
struct VfxPrimitiveTrailBase: VfxPrimitiveBase { // 0x24
   // ctor: 0x00400000
   // init: 0x00400000
    VfxTrailDefinitionData mTrail; // 0x8
};
struct VfxPrimitiveCameraTrail: VfxPrimitiveTrailBase { // 0x24
   // ctor: 0x00CD9810
   // init: 0x00CDA160
};
struct VfxPrimitiveArbitraryTrail: VfxPrimitiveTrailBase { // 0x24
   // ctor: 0x00CD8AD0
   // init: 0x00CDA270
};
struct VfxPrimitiveBeamBase: VfxPrimitiveBase { // 0x50
   // ctor: 0x00400000
   // init: 0x00400000
    VfxBeamDefinitionData mBeam; // 0x8
};
struct VfxPrimitiveCameraSegmentBeam: VfxPrimitiveBeamBase { // 0x50
   // ctor: 0x00CD97E0
   // init: 0x00CD9EF0
};
struct VfxPrimitiveArbitrarySegmentBeam: VfxPrimitiveBeamBase { // 0x50
   // ctor: 0x00CD9910
   // init: 0x00CD99D0
};
struct VfxPrimitiveMeshBase: VfxPrimitiveBase { // 0x64
   // ctor: 0x00400000
   // init: 0x00400000
    VfxMeshDefinitionData mMesh; // 0x8
    bool m_0xFBF6793F; // 0x60
    bool m_0xEA861DAA; // 0x61
};
struct VfxPrimitiveMesh: VfxPrimitiveMeshBase { // 0x64
   // ctor: 0x00CD9A90
   // init: 0x00CDA4D0
};
struct VfxPrimitiveAttachedMesh: VfxPrimitiveMeshBase { // 0x64
   // ctor: 0x00CDA080
   // init: 0x00CD9320
};
struct VfxPrimitiveBeam: VfxPrimitiveBase { // 0xA8
   // ctor: 0x00CD9C90
   // init: 0x00CDA430
    VfxBeamDefinitionData mBeam; // 0x8
    VfxMeshDefinitionData mMesh; // 0x50
};
struct VfxFloatOverLifeMaterialDriver: IVfxMaterialDriver { // 0x38
   // ctor: 0x00CD9F80
   // init: 0x00CD9CD0
    uint8_t Frequency; // 0x4
    VfxAnimatedFloatVariableData Graph; // 0x8
};
struct VfxSineMaterialDriver: IVfxMaterialDriver { // 0x10
   // ctor: 0x00CD8EE0
   // init: 0x00CDA530
    float_t mFrequency; // 0x4
    float_t mScale; // 0x8
    float_t mBias; // 0xC
};
struct MapParticle: MapPlaceable { // 0x88
   // ctor: 0x00CD93E0
   // init: 0x00CD92B0
    link_ptr_t<VfxSystemDefinitionData> System; // 0x58
    bool EyeCandy; // 0x5C
    bool Transitional; // 0x5D
    int32_t Quality; // 0x60
    uint32_t VisibilityMode; // 0x64
    point4D_t ColorModulate; // 0x68
    string_t GroupName; // 0x78
    bool StartDisabled; // 0x84
};
struct MapParticleGroups { // 0xC
   // ctor: 0x005A1E00
   // init: 0x005A1E50
    vector_t<string_t> Groups; // 0x0
};
struct ColorChooserMaterialDriver: IDynamicMaterialDriver { // 0x28
   // ctor: 0x00D20C70
   // init: 0x00D209E0
    unique_ptr_t<IDynamicMaterialBoolDriver> mBoolDriver; // 0x4
    point4D_t mColorOn; // 0x8
    point4D_t mColorOff; // 0x18
};
struct DelayedBoolMaterialDriver: IDynamicMaterialBoolDriver { // 0x30
   // ctor: 0x00D21150
   // init: 0x00D1FFF0
    unique_ptr_t<IDynamicMaterialBoolDriver> mBoolDriver; // 0x4
    float_t mDelayOn; // 0x8
    float_t mDelayOff; // 0xC
};
struct DynamicMaterialParameterDef { // 0x14
   // ctor: 0x00D20DD0
   // init: 0x00D1FE90
    string_t Name; // 0x0
    unique_ptr_t<IDynamicMaterialDriver> Driver; // 0xC
    bool Enabled; // 0x10
};
struct DynamicMaterialTextureSwapOption { // 0x14
   // ctor: 0x00D20220
   // init: 0x00D20950
    unique_ptr_t<IDynamicMaterialBoolDriver> Driver; // 0x0
    string_t TextureName; // 0x4
};
struct DynamicMaterialTextureSwapDef { // 0x1C
   // ctor: 0x00D20B40
   // init: 0x00D20550
    string_t Name; // 0x0
    vector_t<DynamicMaterialTextureSwapOption> Options; // 0xC
    bool Enabled; // 0x18
};
struct DynamicMaterialStaticSwitch { // 0x14
   // ctor: 0x00D20DD0
   // init: 0x00D1FE90
    string_t Name; // 0x0
    unique_ptr_t<IDynamicMaterialBoolDriver> Driver; // 0xC
    bool Enabled; // 0x10
};
struct DynamicMaterialDef { // 0x50
   // ctor: 0x00D203B0
   // init: 0x00D20F90
    bool m_0x5ED2DB8D; // 0x0
    vector_t<DynamicMaterialParameterDef> Parameters; // 0x4
    vector_t<DynamicMaterialTextureSwapDef> Textures; // 0x10
    unique_ptr_t<DynamicMaterialStaticSwitch> StaticSwitch; // 0x1C
};
struct FixedDurationTriggeredBoolDriver: IDynamicMaterialBoolDriver { // 0x2C
   // ctor: 0x00D20750
   // init: 0x00D1FEC0
    unique_ptr_t<IDynamicMaterialBoolDriver> mBoolDriver; // 0x4
    float_t mCustomDuration; // 0x8
};
struct FloatComparisonMaterialDriver: IDynamicMaterialBoolDriver { // 0x10
   // ctor: 0x00D20000
   // init: 0x00D20980
    uint32_t mOperator; // 0x4
    unique_ptr_t<IDynamicMaterialFloatDriver> mValueA; // 0x8
    unique_ptr_t<IDynamicMaterialFloatDriver> mValueB; // 0xC
};
struct FloatLiteralMaterialDriver: IDynamicMaterialFloatDriver { // 0x8
   // ctor: 0x00D20A50
   // init: 0x00D20E20
    float_t mValue; // 0x4
};
struct FloorFloatMaterialDriver: IDynamicMaterialFloatDriver { // 0x8
   // ctor: 0x00D200A0
   // init: 0x00D20730
    unique_ptr_t<IDynamicMaterialFloatDriver> mDriver; // 0x4
};
struct IDynamicMaterialBoolDriver: IDynamicMaterialFloatDriver { // 0x4
   // ctor: 0x00400000
   // init: 0x00400000
};
struct IDynamicMaterialDriver: PropertyBase { // 0x4
   // ctor: 0x00400000
   // init: 0x00400000
};
struct IDynamicMaterialFloatDriver: IDynamicMaterialDriver { // 0x4
   // ctor: 0x00400000
   // init: 0x00400000
};
struct LerpMaterialDriver: IDynamicMaterialFloatDriver { // 0x3C
   // ctor: 0x00D20810
   // init: 0x00D20770
    unique_ptr_t<IDynamicMaterialBoolDriver> mBoolDriver; // 0x4
    float_t mOnValue; // 0x8
    float_t mOffValue; // 0xC
    float_t mTurnOnTimeSec; // 0x10
    float_t mTurnOffTimeSec; // 0x14
    bool m_0xA452BE9F; // 0x18
};
struct AllTrueMaterialDriver: IDynamicMaterialBoolDriver { // 0x10
   // ctor: 0x00D20CA0
   // init: 0x00D20EA0
    vector_t<unique_ptr_t<IDynamicMaterialBoolDriver>> mDrivers; // 0x4
};
struct OneTrueMaterialDriver: IDynamicMaterialBoolDriver { // 0x10
   // ctor: 0x00D207E0
   // init: 0x00D20930
    vector_t<unique_ptr_t<IDynamicMaterialBoolDriver>> mDrivers; // 0x4
};
struct NotMaterialDriver: IDynamicMaterialBoolDriver { // 0x8
   // ctor: 0x00D20260
   // init: 0x00D20170
    unique_ptr_t<IDynamicMaterialBoolDriver> mDriver; // 0x4
};
struct MaxMaterialDriver: IDynamicMaterialDriver { // 0x10
   // ctor: 0x00D200C0
   // init: 0x00D207C0
    vector_t<unique_ptr_t<IDynamicMaterialDriver>> mDrivers; // 0x4
};
struct MinMaterialDriver: IDynamicMaterialDriver { // 0x10
   // ctor: 0x00D206C0
   // init: 0x00D20620
    vector_t<unique_ptr_t<IDynamicMaterialDriver>> mDrivers; // 0x4
};
struct RemapFloatMaterialDriver: IDynamicMaterialFloatDriver { // 0x18
   // ctor: 0x00D20BD0
   // init: 0x00D20640
    unique_ptr_t<IDynamicMaterialFloatDriver> mDriver; // 0x4
    float_t mMinValue; // 0x8
    float_t mMaxValue; // 0xC
    float_t mOutputMinValue; // 0x10
    float_t mOutputMaxValue; // 0x14
};
struct SineMaterialDriver: IDynamicMaterialFloatDriver { // 0x14
   // ctor: 0x00D20860
   // init: 0x00D20500
    unique_ptr_t<IDynamicMaterialFloatDriver> mDriver; // 0x4
    float_t mFrequency; // 0x8
    float_t mScale; // 0xC
    float_t mBias; // 0x10
};
struct SpecificColorMaterialDriver: IDynamicMaterialDriver { // 0x14
   // ctor: 0x00D20280
   // init: 0x00D21050
    point4D_t mColor; // 0x4
};
struct SwitchMaterialDriverElement { // 0x8
   // ctor: 0x00522060
   // init: 0x00521FF0
    unique_ptr_t<IDynamicMaterialBoolDriver> mCondition; // 0x0
    unique_ptr_t<IDynamicMaterialDriver> mValue; // 0x4
};
struct SwitchMaterialDriver: IDynamicMaterialDriver { // 0x14
   // ctor: 0x00D208F0
   // init: 0x00D201F0
    vector_t<SwitchMaterialDriverElement> mElements; // 0x4
    unique_ptr_t<IDynamicMaterialDriver> mDefaultValue; // 0x10
};
struct BlendingSwitchMaterialDriver: SwitchMaterialDriver { // 0x44
   // ctor: 0x00D20150
   // init: 0x00D210C0
    float_t mBlendTime; // 0x14
    vector_t<float_t> mOverrideBlendTimes; // 0x18
};
struct TimeMaterialDriver: IDynamicMaterialFloatDriver { // 0x4
   // ctor: 0x00D20F60
   // init: 0x00D20830
};
struct CustomShaderDef: IShaderDef { // 0x60
   // ctor: 0x00D1FF30
   // init: 0x00D203D0
    string_t ObjectPath; // 0x3C
};
struct IdMappingEntry { // 0x4
   // ctor: 0x00D1FF80
   // init: 0x00D21080
    uint16_t Id; // 0x0
    uint16_t Count; // 0x2
};
struct FixedShaderDef: IShaderDef { // 0x54
   // ctor: 0x00D1FED0
   // init: 0x00D20110
    string_t VertexShader; // 0x3C
    string_t PixelShader; // 0x48
};
struct HybridMaterialDefPreset { // 0x30
   // ctor: 0x00D20070
   // init: 0x00D20EC0
    map_t<string_t, string_t> ShaderMacros; // 0x0
    bool DepthEnable; // 0xC
    bool StencilEnable; // 0xD
    bool BlendEnable; // 0xE
    bool CullEnable; // 0xF
    bool m_0xAAB4104C; // 0x10
    uint8_t DepthCompareFunc; // 0x11
    uint8_t StencilCompareFunc; // 0x12
    uint32_t StencilReferenceVal; // 0x14
    uint32_t StencilMask; // 0x18
    uint8_t StencilFailOp; // 0x1C
    uint8_t StencilPassDepthFailOp; // 0x1D
    uint8_t StencilPassDepthPassOp; // 0x1E
    uint8_t SrcColorBlendFactor; // 0x1F
    uint8_t SrcAlphaBlendFactor; // 0x20
    uint8_t DstColorBlendFactor; // 0x21
    uint8_t DstAlphaBlendFactor; // 0x22
    uint8_t BlendEquation; // 0x23
    uint8_t WindingToCull; // 0x24
    uint8_t WriteMask; // 0x25
    float_t DepthOffsetSlope; // 0x28
    float_t DepthOffsetBias; // 0x2C
};
struct HybridMaterialDef: CustomShaderDef { // 0x17C
   // ctor: 0x00D21120
   // init: 0x00D20690
    string_t Name; // 0x60
    uint32_t Type; // 0x6C
    MaterialDataCollections DataCollections; // 0x70
    link_ptr_t<HybridMaterialDefPreset> Preset; // 0x16C
    map_t<string_t, string_t> ShaderMacros; // 0x170
};
struct IMaterialDef { // 0x4
   // ctor: 0x00400000
   // init: 0x00400000
};
struct ShaderLogicalParameter { // 0x10
   // ctor: 0x00607F40
   // init: 0x00608200
    string_t Name; // 0x0
    uint32_t Fields; // 0xC
};
struct ShaderPhysicalParameter { // 0x28
   // ctor: 0x00D1FFA0
   // init: 0x00D209A0
    string_t Name; // 0x0
    point4D_t Data; // 0xC
    vector_t<ShaderLogicalParameter> LogicalParameters; // 0x1C
};
struct ShaderStaticSwitch { // 0x10
   // ctor: 0x009AD940
   // init: 0x009AE640
    string_t Name; // 0x0
    bool OnByDefault; // 0xC
};
struct ShaderTexture { // 0x18
   // ctor: 0x00608150
   // init: 0x00607E90
    string_t Name; // 0x0
    string_t DefaultTexturePath; // 0xC
};
struct IShaderDef: PropertyBase { // 0x3C
   // ctor: 0x00400000
   // init: 0x00400000
    vector_t<ShaderPhysicalParameter> Parameters; // 0x4
    vector_t<ShaderStaticSwitch> StaticSwitches; // 0x10
    vector_t<ShaderTexture> Textures; // 0x1C
    map_t<string_t, string_t> FeatureDefines; // 0x28
    uint32_t FeatureMask; // 0x34
    uint32_t m_0x9BFE7D81; // 0x38
};
struct MaterialParameterData { // 0x14
   // ctor: 0x00D20D90
   // init: 0x00D20C10
    uint8_t Type; // 0x0
    point4D_t DefaultValue; // 0x4
};
struct MaterialTextureData { // 0x14
   // ctor: 0x00D20590
   // init: 0x00D20FB0
    string_t DefaultTexturePath; // 0x0
    uint8_t AddressU; // 0xC
    uint8_t AddressV; // 0xD
    uint8_t AddressW; // 0xE
    uint8_t FilterMin; // 0xF
    uint8_t FilterMip; // 0x10
    uint8_t FilterMag; // 0x11
};
struct MaterialSwitchData { // 0x1
   // ctor: 0x00D202E0
   // init: 0x00D21140
    bool On; // 0x0
};
struct MaterialParameterDataCollection { // 0x54
   // ctor: 0x00D20E50
   // init: 0x00D20090
    uint16_t NextId; // 0x4
    unordered_map_t<string_t, IdMappingEntry> Entries; // 0x8
    string_t m_0xEA57BF12; // 0x28
    unordered_map_t<uint16_t, MaterialParameterData> Data; // 0x34
};
struct MaterialTextureDataCollection { // 0x54
   // ctor: 0x00D20190
   // init: 0x00D207B0
    uint16_t NextId; // 0x4
    unordered_map_t<string_t, IdMappingEntry> Entries; // 0x8
    string_t m_0xEA57BF12; // 0x28
    unordered_map_t<uint16_t, MaterialTextureData> Data; // 0x34
};
struct MaterialSwitchDataCollection { // 0x54
   // ctor: 0x00D201B0
   // init: 0x00D20670
    uint16_t NextId; // 0x4
    unordered_map_t<string_t, IdMappingEntry> Entries; // 0x8
    string_t m_0xEA57BF12; // 0x28
    unordered_map_t<uint16_t, MaterialSwitchData> Data; // 0x34
};
struct MaterialDataCollections { // 0xFC
   // ctor: 0x00D20AA0
   // init: 0x00D20840
    MaterialParameterDataCollection ParameterData; // 0x0
    MaterialTextureDataCollection TextureData; // 0x54
    MaterialSwitchDataCollection SwitchData; // 0xA8
};
struct MaterialInstanceParamDef { // 0x10
   // ctor: 0x00D20780
   // init: 0x00D20FA0
    point4D_t Value; // 0x0
};
struct MaterialInstanceSwitchDef { // 0x1
   // ctor: 0x0090B760
   // init: 0x0090B7D0
    bool On; // 0x0
};
struct MaterialInstanceTextureDef { // 0x18
   // ctor: 0x006086D0
   // init: 0x00608E10
    string_t TexturePath; // 0x0
    map_t<hash_t, string_t> UncensoredTextures; // 0xC
};
struct t_0xF7084B4A { // 0x18
   // ctor: 0x006086D0
   // init: 0x00608E10
    string_t Name; // 0x0
    map_t<string_t, string_t> ShaderMacros; // 0xC
};
struct MaterialInstanceDynamicParam { // 0x8
   // ctor: 0x00D20C80
   // init: 0x00D20F80
    bool Enabled; // 0x0
    unique_ptr_t<IDynamicMaterialDriver> Driver; // 0x4
};
struct MaterialInstanceDynamicSwitch { // 0x8
   // ctor: 0x00D206A0
   // init: 0x00D207A0
    bool Enabled; // 0x0
    unique_ptr_t<IDynamicMaterialBoolDriver> Driver; // 0x4
};
struct MaterialInstanceDynamicTexture { // 0x10
   // ctor: 0x00CAE0E0
   // init: 0x00CAE2E0
    bool Enabled; // 0x0
    vector_t<DynamicMaterialTextureSwapOption> Options; // 0x4
};
struct MaterialInstanceDef: IResource, IMaterialDef { // 0x88
   // ctor: 0x00D20430
   // init: 0x00D1FF70
    string_t Name; // 0xC
    link_ptr_t<HybridMaterialDef> BaseMaterial; // 0x18
    vector_t<t_0xF7084B4A> ChildTechniques; // 0x24
    map_t<string_t, string_t> ShaderMacros; // 0x30
    map_t<uint16_t, MaterialInstanceParamDef> Params; // 0x3C
    map_t<uint16_t, MaterialInstanceSwitchDef> Switches; // 0x48
    map_t<uint16_t, MaterialInstanceTextureDef> Textures; // 0x54
    map_t<uint16_t, MaterialInstanceDynamicParam> DynamicParams; // 0x60
    map_t<uint16_t, MaterialInstanceDynamicTexture> DynamicTextures; // 0x6C
    MaterialInstanceDynamicSwitch DynamicSwitch; // 0x78
    uint16_t DynamicSwitchId; // 0x80
};
struct StaticMaterialShaderParamDef { // 0x1C
   // ctor: 0x007815B0
   // init: 0x00781690
    string_t Name; // 0x0
    point4D_t Value; // 0xC
};
struct StaticMaterialSwitchDef { // 0x10
   // ctor: 0x00D21090
   // init: 0x00D204E0
    string_t Name; // 0x0
    bool On; // 0xC
};
struct StaticMaterialShaderSamplerDef { // 0x38
   // ctor: 0x00D20530
   // init: 0x00D20D80
    string_t SamplerName; // 0x0
    string_t TextureName; // 0xC
    map_t<hash_t, string_t> UncensoredTextures; // 0x18
    uint32_t AddressU; // 0x20
    uint32_t AddressV; // 0x24
    uint32_t AddressW; // 0x28
    uint32_t FilterMin; // 0x2C
    uint32_t FilterMip; // 0x30
    uint32_t FilterMag; // 0x34
};
struct StaticMaterialPassDef { // 0x64
   // ctor: 0x00D21100
   // init: 0x00D21040
    link_ptr_t<IShaderDef> Shader; // 0x0
    map_t<string_t, string_t> ShaderMacros; // 0x4
    vector_t<StaticMaterialShaderParamDef> ParamValues; // 0x10
    bool DepthEnable; // 0x1C
    bool StencilEnable; // 0x1D
    bool BlendEnable; // 0x1E
    bool CullEnable; // 0x1F
    bool m_0xAAB4104C; // 0x20
    uint32_t DepthCompareFunc; // 0x24
    uint32_t StencilCompareFunc; // 0x28
    uint32_t StencilReferenceVal; // 0x2C
    uint32_t StencilMask; // 0x30
    uint32_t StencilFailOp; // 0x34
    uint32_t StencilPassDepthFailOp; // 0x38
    uint32_t StencilPassDepthPassOp; // 0x3C
    uint32_t SrcColorBlendFactor; // 0x40
    uint32_t SrcAlphaBlendFactor; // 0x44
    uint32_t DstColorBlendFactor; // 0x48
    uint32_t DstAlphaBlendFactor; // 0x4C
    uint32_t BlendEquation; // 0x50
    uint32_t WindingToCull; // 0x54
    uint32_t WriteMask; // 0x58
    float_t DepthOffsetSlope; // 0x5C
    float_t DepthOffsetBias; // 0x60
};
struct StaticMaterialTechniqueDef { // 0x18
   // ctor: 0x006086D0
   // init: 0x00608E10
    string_t Name; // 0x0
    vector_t<StaticMaterialPassDef> Passes; // 0xC
};
struct StaticMaterialChildTechniqueDef { // 0x24
   // ctor: 0x00D20680
   // init: 0x00D20300
    string_t Name; // 0x0
    string_t ParentName; // 0xC
    map_t<string_t, string_t> ShaderMacros; // 0x18
};
struct StaticMaterialDef: IResource, IMaterialDef { // 0x7C
   // ctor: 0x00D20A30
   // init: 0x00D208E0
    string_t Name; // 0xC
    uint32_t Type; // 0x18
    string_t DefaultTechnique; // 0x1C
    vector_t<StaticMaterialShaderSamplerDef> SamplerValues; // 0x28
    vector_t<StaticMaterialShaderParamDef> ParamValues; // 0x34
    vector_t<StaticMaterialSwitchDef> Switches; // 0x40
    map_t<string_t, string_t> ShaderMacros; // 0x4C
    vector_t<StaticMaterialTechniqueDef> Techniques; // 0x58
    vector_t<StaticMaterialChildTechniqueDef> ChildTechniques; // 0x64
    unique_ptr_t<DynamicMaterialDef> DynamicMaterial; // 0x70
};
struct MapPerInstanceInfo { // 0x1C
   // ctor: 0x00D4D830
   // init: 0x00D4D9B0
    string_t ShadowMapPath; // 0x0
    point4D_t ShadowMapUvScaleAndBias; // 0xC
};
struct MapBakeProperties: MapComponent { // 0x24
   // ctor: 0x00D4D5E0
   // init: 0x00D4D930
    uint32_t LightGridSize; // 0x4
    float_t m_0x22D24A9A; // 0x8
    float_t LightGridCharacterFullBrightIntensity; // 0xC
    float_t m_0xEA4E5CC8; // 0x10
    float_t m_0x2F3B5471; // 0x14
    string_t LightGridFileName; // 0x18
};
struct MapCloudsLayer { // 0x10
   // ctor: 0x00D4D900
   // init: 0x00D4D650
    point2D_t Direction; // 0x0
    float_t Scale; // 0x8
    float_t Speed; // 0xC
};
struct MapClouds: MapGraphicsFeature { // 0x64
   // ctor: 0x00D4D9F0
   // init: 0x00D4D700
    string_t CloudsTexturePath; // 0x4
    point4D_t m_0x64847953; // 0x10
    bool IsEyeCandy; // 0x20
    array_t<MapCloudsLayer, 3> Layers; // 0x24
};
struct MapGraphicsFeature: MapComponent { // 0x4
   // ctor: 0x00400000
   // init: 0x00400000
};
struct MapLightingV2: MapGraphicsFeature { // 0xC
   // ctor: 0x00D4D980
   // init: 0x00D4D630
    float_t m_0xEE91017D; // 0x4
    float_t m_0xC916A9FC; // 0x8
};
struct MapLightingVolume: MapPlaceable { // 0x134
   // ctor: 0x00D4D7F0
   // init: 0x00D4D510
    point4D_t SunColor; // 0x98
    point3D_t SunDirection; // 0xA8
    optional_t<point3D_t> m_0xA04BD9BF; // 0xB4
    float_t m_0xD8851203; // 0xC0
    float_t m_0xBA02F116; // 0xC4
    point4D_t SkyLightColor; // 0xC8
    point4D_t HorizonColor; // 0xD8
    point4D_t GroundColor; // 0xE8
    float_t SkyLightScale; // 0xF8
    float_t LightMapColorScale; // 0xFC
    bool FogEnabled; // 0x100
    point4D_t FogColor; // 0x104
    point4D_t FogAlternateColor; // 0x114
    point2D_t FogStartAndEnd; // 0x124
    float_t FogEmissiveRemap; // 0x12C
    float_t FogLowQualityModeEmissiveRemap; // 0x130
};
struct MapPointLight: MapPlaceable { // 0x68
   // ctor: 0x00D4D750
   // init: 0x00D4D880
    link_ptr_t<MapPointLightType> Type; // 0x58
    float_t RadiusScale; // 0x5C
    float_t IntensityScale; // 0x60
    optional_t<bool> OverrideCastStaticShadows; // 0x64
    optional_t<bool> OverrideUseSpecular; // 0x65
};
struct MapPointLightType { // 0x2C
   // ctor: 0x00D4D6D0
   // init: 0x00D4D7A0
    point4D_t LightColor; // 0x0
    point4D_t FalloffColor; // 0x10
    float_t Radius; // 0x20
    bool CastStaticShadows; // 0x24
    bool Specular; // 0x25
    int32_t Impact; // 0x28
};
struct MapSunProperties: MapComponent { // 0xA8
   // ctor: 0x00D4D710
   // init: 0x00D4D580
    point4D_t SunColor; // 0x4
    point3D_t SunDirection; // 0x14
    optional_t<point3D_t> m_0xA04BD9BF; // 0x20
    float_t m_0xD8851203; // 0x2C
    float_t m_0xBA02F116; // 0x30
    point4D_t SkyLightColor; // 0x34
    point4D_t HorizonColor; // 0x44
    point4D_t GroundColor; // 0x54
    float_t SkyLightScale; // 0x64
    float_t LightMapColorScale; // 0x68
    bool FogEnabled; // 0x6C
    point4D_t FogColor; // 0x70
    point4D_t FogAlternateColor; // 0x80
    point2D_t FogStartAndEnd; // 0x90
    float_t FogEmissiveRemap; // 0x98
    float_t FogLowQualityModeEmissiveRemap; // 0x9C
    bool UseBloom; // 0xA0
    float_t SurfaceAreaToShadowMapScale; // 0xA4
};
struct MapTerrainPaint: MapGraphicsFeature { // 0x18
   // ctor: 0x00D4D540
   // init: 0x00D4D670
    string_t TerrainPaintTexturePath; // 0x4
};
struct ShData { // 0x6C
   // ctor: 0x00D4D5B0
   // init: 0x00D4D8C0
    array_t<point3D_t, 9> BandData; // 0x0
};
struct SkinMeshDataProperties_MaterialOverride { // 0x28
   // ctor: 0x006A2E50
   // init: 0x006A2D60
    link_ptr_t<IMaterialDef> Material; // 0x0
    string_t Texture; // 0x4
    string_t GlossTexture; // 0x10
    string_t Submesh; // 0x1C
};
struct SkinnedMeshDataMaterialController: PropertyBase { // 0x4
   // ctor: 0x00400000
   // init: 0x00400000
};
struct SkinMeshDataProperties { // 0xF8
   // ctor: 0x00D4D8E0
   // init: 0x00D4D8B0
    string_t Skeleton; // 0x18
    string_t SimpleSkin; // 0x24
    string_t Texture; // 0x30
    string_t EmissiveTexture; // 0x3C
    string_t GlossTexture; // 0x48
    float_t SkinScale; // 0x54
    float_t SelfIllumination; // 0x58
    bool m_0xD62DF07C; // 0x5C
    float_t BrushAlphaOverride; // 0x60
    optional_t<point3D_t> OverrideBoundingBox; // 0x64
    link_ptr_t<IMaterialDef> Material; // 0x70
    float_t BoundingCylinderRadius; // 0x74
    float_t BoundingCylinderHeight; // 0x78
    optional_t<float_t> BoundingSphereRadius; // 0x7C
    color_t FresnelColor; // 0x80
    float_t Fresnel; // 0x84
    bool UsesSkinVo; // 0x88
    bool CastShadows; // 0x89
    bool AllowCharacterInking; // 0x8A
    string_t ReflectionMap; // 0x8C
    float_t ReflectionOpacityDirect; // 0x98
    float_t ReflectionOpacityGlancing; // 0x9C
    float_t ReflectionFresnel; // 0xA0
    color_t ReflectionFresnelColor; // 0xA4
    string_t InitialSubmeshToHide; // 0xA8
    string_t InitialSubmeshShadowsToHide; // 0xB4
    string_t InitialSubmeshMouseOversToHide; // 0xC0
    string_t SubmeshRenderOrder; // 0xCC
    bool m_0x2543480A; // 0xD8
    vector_t<unique_ptr_t<BaseRigPoseModifierData>> RigPoseModifierData; // 0xDC
    vector_t<SkinMeshDataProperties_MaterialOverride> MaterialOverride; // 0xE8
    unique_ptr_t<SkinnedMeshDataMaterialController> MaterialController; // 0xF4
};
struct BaseResourceResolver: IResourceResolver { // 0x10
   // ctor: 0x00D635E0
   // init: 0x00D63610
    map_t<hash_t, link_ptr_t<IResource>> ResourceMap; // 0x4
};
struct GlobalResourceResolver: BaseResourceResolver { // 0x10
   // ctor: 0x00D63540
   // init: 0x00D63590
};
struct IResource: PropertyBase { // 0x8
   // ctor: 0x00400000
   // init: 0x00400000
};
struct IResourceResolver: PropertyBase { // 0x4
   // ctor: 0x00400000
   // init: 0x00400000
};
struct ResourceResolver: BaseResourceResolver { // 0x10
   // ctor: 0x00D635B0
   // init: 0x00D63570
};
struct SetVarInTableBlock: IScriptBlock { // 0x18
   // ctor: 0x00D649C0
   // init: 0x00D64ED0
    ScriptTableSet Dest; // 0x8
    unique_ptr_t<IScriptValueGet> Value; // 0x14
};
struct ScriptCommentBlock: IScriptBlock { // 0x18
   // ctor: 0x00D64D00
   // init: 0x00D643F0
    ScriptSequence Sequence; // 0x8
};
struct ConcatenateStringsBlock: IScriptBlock { // 0x1C
   // ctor: 0x00D64910
   // init: 0x00D647A0
    unique_ptr_t<IStringGet> String1; // 0x8
    unique_ptr_t<IStringGet> String2; // 0xC
    StringTableSet Result; // 0x10
};
struct CreateCustomTableBlock: IScriptBlock { // 0x14
   // ctor: 0x00D65350
   // init: 0x00D640E0
    CustomTableSet CustomTable; // 0x8
};
struct DestroyCustomTableBlock: IScriptBlock { // 0x14
   // ctor: 0x00D64820
   // init: 0x00D65020
    CustomTableSet CustomTable; // 0x8
};
struct SetKeyValueInCustomTableBlock: IScriptBlock { // 0x1C
   // ctor: 0x00D64CA0
   // init: 0x00D64880
    CustomTableGet CustomTable; // 0x8
    unique_ptr_t<IScriptValueGet> Key; // 0x14
    unique_ptr_t<IScriptValueGet> Value; // 0x18
};
struct GetKeyValueInCustomTableBlock: IScriptBlock { // 0x24
   // ctor: 0x00D64310
   // init: 0x00D64FC0
    CustomTableGet CustomTable; // 0x8
    unique_ptr_t<IScriptValueGet> Key; // 0x14
    ScriptTableSet OutValue; // 0x18
};
struct InsertIntoCustomTableBlock: IScriptBlock { // 0x28
   // ctor: 0x00D652A0
   // init: 0x00D64300
    CustomTableGet CustomTable; // 0x8
    unique_ptr_t<IIntGet> Index; // 0x14
    unique_ptr_t<IScriptValueGet> Value; // 0x18
    IntTableSet OutIndex; // 0x1C
};
struct RemoveFromCustomTableBlock: IScriptBlock { // 0x1C
   // ctor: 0x00D641F0
   // init: 0x00D64130
    CustomTableGet CustomTable; // 0x8
    unique_ptr_t<IScriptValueGet> Key; // 0x14
    unique_ptr_t<IIntGet> Index; // 0x18
};
struct GetSizeOfCustomTableBlock: IScriptBlock { // 0x20
   // ctor: 0x00D645A0
   // init: 0x00D64B10
    CustomTableGet CustomTable; // 0x8
    ScriptTableSet OutSize; // 0x14
};
struct ForEachInCustomTableBlock: IScriptBlock { // 0x40
   // ctor: 0x00D65280
   // init: 0x00D651E0
    CustomTableGet CustomTable; // 0x8
    bool SortedByKeys; // 0x14
    ScriptTableSet OutKey; // 0x18
    ScriptTableSet OutValue; // 0x24
    ScriptSequence Sequence; // 0x30
};
struct CustomTableContainsValueBlock: IScriptBlock { // 0x30
   // ctor: 0x00D64240
   // init: 0x00D65180
    CustomTableGet CustomTable; // 0x8
    unique_ptr_t<IScriptValueGet> Value; // 0x14
    ScriptTableSet OutKey; // 0x18
    BoolTableSet OutWasFound; // 0x24
};
struct FunctionDefinition { // 0x28
   // ctor: 0x00D64610
   // init: 0x00D64B70
    vector_t<hash_t> InputParameters; // 0x0
    vector_t<hash_t> OutputParameters; // 0xC
    ScriptSequence Sequence; // 0x18
};
struct CreateFunctionBlock: IScriptBlock { // 0x3C
   // ctor: 0x00D650C0
   // init: 0x00D64590
    FunctionTableSet Function; // 0x8
    FunctionDefinition FunctionDefinition; // 0x14
};
struct IRunFunctionBlock: IScriptBlock { // 0x2C
   // ctor: 0x00400000
   // init: 0x00400000
    FunctionTableGet Function; // 0x8
    vector_t<unique_ptr_t<IScriptValueGet>> InputParameters; // 0x14
    vector_t<ScriptTableSet> OutputParameters; // 0x20
};
struct IScriptBlock: PropertyBase { // 0x8
   // ctor: 0x00400000
   // init: 0x00400000
    bool IsDisabled; // 0x4
};
struct SwitchCase { // 0x18
   // ctor: 0x00D64E90
   // init: 0x00D645C0
    unique_ptr_t<IScriptCondition> Condition; // 0x0
    ScriptSequence Sequence; // 0x4
    bool IsDisabled; // 0x14
};
struct SwitchScriptBlock: IScriptBlock { // 0x14
   // ctor: 0x00D64200
   // init: 0x00D64C70
    vector_t<SwitchCase> Cases; // 0x8
};
struct IScriptCondition: PropertyBase { // 0x4
   // ctor: 0x00400000
   // init: 0x00400000
};
struct TableValueExistsScriptCondition: IScriptCondition { // 0x10
   // ctor: 0x00D64950
   // init: 0x00D64330
    ScriptTableGet TableValue; // 0x4
};
struct RandomChanceScriptCondition: IScriptCondition { // 0x8
   // ctor: 0x00D64800
   // init: 0x00D64AF0
    unique_ptr_t<IFloatGet> Chance; // 0x4
};
struct AndScriptCondition: IScriptCondition { // 0x10
   // ctor: 0x00D64DC0
   // init: 0x00D651F0
    vector_t<unique_ptr_t<IScriptCondition>> Conditions; // 0x4
};
struct OrScriptCondition: IScriptCondition { // 0x10
   // ctor: 0x00D64A20
   // init: 0x00D64420
    vector_t<unique_ptr_t<IScriptCondition>> Conditions; // 0x4
};
struct NotScriptCondition: IScriptCondition { // 0x8
   // ctor: 0x00D645F0
   // init: 0x00D649A0
    unique_ptr_t<IScriptCondition> Condition; // 0x4
};
struct ComparisonScriptCondition: IScriptCondition { // 0x10
   // ctor: 0x00D64E60
   // init: 0x00D64180
    unique_ptr_t<IScriptValueGet> Value1; // 0x4
    unique_ptr_t<IScriptValueGet> Value2; // 0x8
    uint32_t Operation; // 0xC
};
struct IScriptSequence: Rscript { // 0x4
   // ctor: 0x00400000
   // init: 0x00400000
};
struct Rscript: PropertyBase { // 0x4
   // ctor: 0x00400000
   // init: 0x00400000
};
struct ScriptSequence: IScriptSequence { // 0x10
   // ctor: 0x00D64D90
   // init: 0x00D64260
    vector_t<unique_ptr_t<IScriptBlock>> Blocks; // 0x4
};
struct ScriptTable: PropertyBase { // 0x4
   // ctor: 0x00400000
   // init: 0x00400000
};
struct PassThroughParamsTable: ScriptTable { // 0x4
   // ctor: 0x00D64930
   // init: 0x00D63F40
};
struct IBoolGet: IScriptValueGet { // 0x4
   // ctor: 0x00400000
   // init: 0x00400000
};
struct BoolGet: IBoolGet { // 0x8
   // ctor: 0x00D64020
   // init: 0x00D648D0
    bool Value; // 0x4
};
struct BoolTableGet: IBoolGet { // 0x10
   // ctor: 0x00D650E0
   // init: 0x00D64500
    unique_ptr_t<ScriptTable> Table; // 0x4
    hash_t Var; // 0x8
    optional_t<bool> Default; // 0xC
};
struct CustomTableGet: IScriptValueGet { // 0xC
   // ctor: 0x00D65230
   // init: 0x00D65440
    unique_ptr_t<ScriptTable> Table; // 0x4
    hash_t Var; // 0x8
};
struct IFloatGet: IScriptValueGet { // 0x4
   // ctor: 0x00400000
   // init: 0x00400000
};
struct FloatGet: IFloatGet { // 0x8
   // ctor: 0x00D64380
   // init: 0x00D64C50
    float_t Value; // 0x4
};
struct FloatTableGet: IFloatGet { // 0x10
   // ctor: 0x00D64C00
   // init: 0x00D64090
    unique_ptr_t<ScriptTable> Table; // 0x4
    hash_t Var; // 0x8
    optional_t<float_t> Default; // 0xC
};
struct FloatOffsetTableGet: IFloatGet { // 0x10
   // ctor: 0x00D64AA0
   // init: 0x00D64BC0
    unique_ptr_t<ScriptTable> Table; // 0x4
    hash_t Var; // 0x8
    float_t Offset; // 0xC
};
struct IFunctionGet: IScriptValueGet { // 0x4
   // ctor: 0x00400000
   // init: 0x00400000
};
struct FunctionTableGet: IFunctionGet { // 0xC
   // ctor: 0x00D64040
   // init: 0x00D653B0
    unique_ptr_t<ScriptTable> Table; // 0x4
    hash_t Var; // 0x8
};
struct IIntGet: IScriptValueGet { // 0x4
   // ctor: 0x00400000
   // init: 0x00400000
};
struct IntGet: IIntGet { // 0x8
   // ctor: 0x00D64620
   // init: 0x00D646D0
    int32_t Value; // 0x4
};
struct IntTableGet: IIntGet { // 0x10
   // ctor: 0x00D65190
   // init: 0x00D64750
    unique_ptr_t<ScriptTable> Table; // 0x4
    hash_t Var; // 0x8
    optional_t<int32_t> Default; // 0xC
};
struct IntOffsetTableGet: IIntGet { // 0x10
   // ctor: 0x00D653F0
   // init: 0x00D652C0
    unique_ptr_t<ScriptTable> Table; // 0x4
    hash_t Var; // 0x8
    int32_t Offset; // 0xC
};
struct ScriptTableGet: IScriptValueGet { // 0xC
   // ctor: 0x00D64440
   // init: 0x00D64690
    unique_ptr_t<ScriptTable> Table; // 0x4
    hash_t Var; // 0x8
};
struct ScriptTableSet: PropertyBase { // 0xC
   // ctor: 0x00D642B0
   // init: 0x00D64E20
    unique_ptr_t<ScriptTable> Table; // 0x4
    hash_t Var; // 0x8
};
struct IntTableSet: ScriptTableSet { // 0xC
   // ctor: 0x00D64A50
   // init: 0x00D643A0
};
struct BoolTableSet: ScriptTableSet { // 0xC
   // ctor: 0x00D63FD0
   // init: 0x00D641A0
};
struct FloatTableSet: ScriptTableSet { // 0xC
   // ctor: 0x00D64CB0
   // init: 0x00D64F70
};
struct StringTableSet: ScriptTableSet { // 0xC
   // ctor: 0x00D646F0
   // init: 0x00D64B20
};
struct VectorTableSet: ScriptTableSet { // 0xC
   // ctor: 0x00D63F50
   // init: 0x00D65070
};
struct FunctionTableSet: ScriptTableSet { // 0xC
   // ctor: 0x00D64D40
   // init: 0x00D65130
};
struct CustomTableSet: ScriptTableSet { // 0xC
   // ctor: 0x00D64540
   // init: 0x00D64640
};
struct IScriptValueGet: PropertyBase { // 0x4
   // ctor: 0x00400000
   // init: 0x00400000
};
struct IStringGet: IScriptValueGet { // 0x4
   // ctor: 0x00400000
   // init: 0x00400000
};
struct StringGet: IStringGet { // 0x10
   // ctor: 0x00D648E0
   // init: 0x00D65480
    string_t Value; // 0x4
};
struct StringTableGet: IStringGet { // 0x1C
   // ctor: 0x00D64740
   // init: 0x00D64F20
    unique_ptr_t<ScriptTable> Table; // 0x4
    hash_t Var; // 0x8
    optional_t<string_t> Default; // 0xC
};
struct IVectorGet: IScriptValueGet { // 0x4
   // ctor: 0x00400000
   // init: 0x00400000
};
struct VectorGet: IVectorGet { // 0x10
   // ctor: 0x00D64280
   // init: 0x00D63FA0
    point3D_t Value; // 0x4
};
struct VectorTableGet: IVectorGet { // 0x18
   // ctor: 0x00D64FD0
   // init: 0x00D65300
    unique_ptr_t<ScriptTable> Table; // 0x4
    hash_t Var; // 0x8
    optional_t<point3D_t> Default; // 0xC
};
struct t_0xD1951F45: PropertyBase { // 0xC
   // ctor: 0x00400000
   // init: 0x00400000
    float_t TransitionTime; // 0x4
    uint8_t StartAlpha; // 0x8
    uint8_t EndAlpha; // 0x9
    uint8_t EasingType; // 0xA
};
struct t_0x8F1E6A22: t_0xD1951F45 { // 0xC
   // ctor: 0x00D6ABC0
   // init: 0x00D6AB40
};
struct t_0x6CE97639: t_0xD1951F45 { // 0x10
   // ctor: 0x00D6AC40
   // init: 0x00D6ADD0
    uint8_t Edge; // 0xC
};
struct SceneData { // 0x20
   // ctor: 0x00D6B700
   // init: 0x00D6B600
    string_t mName; // 0x0
    link_ptr_t<SceneData> mParentScene; // 0xC
    uint32_t mLayer; // 0x10
    unique_ptr_t<t_0xD1951F45> SceneTransitionIn; // 0x14
    unique_ptr_t<t_0xD1951F45> SceneTransitionOut; // 0x18
    bool mEnabled; // 0x1C
    bool mHealthBar; // 0x1D
    bool m_0x22413173; // 0x1E
    bool m_0xF80397EE; // 0x1F
};
struct AnchorBase: PropertyBase { // 0x4
   // ctor: 0x00400000
   // init: 0x00400000
};
struct AnchorSingle: AnchorBase { // 0xC
   // ctor: 0x00D6A8A0
   // init: 0x00D6B330
    point2D_t Anchor; // 0x4
};
struct AnchorDouble: AnchorBase { // 0x14
   // ctor: 0x00D6A820
   // init: 0x00D6B000
    point2D_t AnchorLeft; // 0x4
    point2D_t AnchorRight; // 0xC
};
struct AtlasDataBase: PropertyBase { // 0x1C
   // ctor: 0x00400000
   // init: 0x00400000
    string_t mTextureName; // 0x4
    uint32_t mTextureSourceResolutionWidth; // 0x10
    uint32_t mTextureSourceResolutionHeight; // 0x14
};
struct AtlasData: AtlasDataBase { // 0x2C
   // ctor: 0x00D6A800
   // init: 0x00D6AEC0
    point4D_t mTextureUv; // 0x1C
};
struct t_0xB5D136DB: AtlasDataBase { // 0x3C
   // ctor: 0x00D6AD30
   // init: 0x00D6AD90
    point4D_t TextureUs; // 0x1C
    point2D_t TextureVs; // 0x2C
    point2D_t m_0x1B57CC27; // 0x34
};
struct t_0xA3D11A85: AtlasDataBase { // 0x3C
   // ctor: 0x00D6AA20
   // init: 0x00D6AD50
    point2D_t TextureUs; // 0x1C
    point4D_t TextureVs; // 0x24
    point2D_t m_0x15EC9181; // 0x34
};
struct t_0xAB3D1567: AtlasDataBase { // 0x4C
   // ctor: 0x00D6B640
   // init: 0x00D6B040
    point4D_t TextureUs; // 0x1C
    point4D_t TextureVs; // 0x2C
    point2D_t m_0x15EC9181; // 0x3C
    point2D_t m_0x1B57CC27; // 0x44
};
struct BaseElementData: t_0x231DD1A2 { // 0x48
   // ctor: 0x00400000
   // init: 0x00400000
    bool mEnabled; // 0x14
    bool mKeepMaxScale; // 0x15
    bool mFullscreen; // 0x16
    bool mNoPixelSnappingX; // 0x17
    bool mNoPixelSnappingY; // 0x18
    bool m_0x258BAE9A; // 0x19
    bool mUseRectSourceResolutionAsFloor; // 0x1A
    bool StickyDrag; // 0x1B
    uint32_t mDraggable; // 0x1C
    uint32_t mLayer; // 0x20
    uint16_t mRectSourceResolutionWidth; // 0x24
    uint16_t mRectSourceResolutionHeight; // 0x26
    unique_ptr_t<AnchorBase> mAnchors; // 0x28
    point4D_t mRect; // 0x2C
    vector_t<point2D_t> mHitTestPolygon; // 0x3C
};
struct EffectElementData: BaseElementData { // 0x68
   // ctor: 0x00400000
   // init: 0x00400000
};
struct EffectCooldownElementData: EffectElementData { // 0x68
   // ctor: 0x00D6AE90
   // init: 0x00D6AA70
    color_t mEffectColor0; // 0x58
    color_t mEffectColor1; // 0x5C
};
struct EffectCircleMaskCooldownElementData: EffectElementData { // 0x68
   // ctor: 0x00D6B870
   // init: 0x00D6A9D0
    color_t mEffectColor0; // 0x58
    color_t mEffectColor1; // 0x5C
};
struct EffectCooldownRadialElementData: EffectElementData { // 0x6C
   // ctor: 0x00D6B6C0
   // init: 0x00D6AE40
    bool mFlipX; // 0x61
    bool mFlipY; // 0x62
    bool mPerPixelUvsX; // 0x63
    unique_ptr_t<AtlasData> mAtlas; // 0x64
    bool mIsFill; // 0x68
};
struct EffectArcFillElementData: EffectElementData { // 0x68
   // ctor: 0x00D6AB30
   // init: 0x00D6B450
    bool mFlipX; // 0x61
    bool mFlipY; // 0x62
    bool mPerPixelUvsX; // 0x63
    unique_ptr_t<AtlasData> mAtlas; // 0x64
};
struct EffectAmmoElementData: EffectElementData { // 0x68
   // ctor: 0x00D6B360
   // init: 0x00D6ABF0
    color_t mEffectColor0; // 0x58
    color_t mEffectColor1; // 0x5C
};
struct EffectGlowElementData: EffectElementData { // 0x68
   // ctor: 0x00D6B530
   // init: 0x00D6B820
    float_t CycleTime; // 0x48
    float_t BaseScale; // 0x4C
    float_t CycleBasedScaleAddition; // 0x50
    float_t MinimumAlpha; // 0x54
    bool mFlipX; // 0x61
    bool mFlipY; // 0x62
    bool mPerPixelUvsX; // 0x63
    unique_ptr_t<AtlasData> mAtlas; // 0x64
};
struct EffectAnimationElementData: EffectElementData { // 0x6C
   // ctor: 0x00D6B5E0
   // init: 0x00D6A970
    float_t FramesPerSecond; // 0x48
    float_t TotalNumberOfFrames; // 0x4C
    float_t NumberOfFramesPerRowInAtlas; // 0x50
    bool mFlipX; // 0x61
    bool mFlipY; // 0x62
    bool mPerPixelUvsX; // 0x63
    unique_ptr_t<AtlasData> mAtlas; // 0x64
    bool mLooping; // 0x68
    uint8_t mFinishBehavior; // 0x69
};
struct EffectFillPercentageElementData: EffectElementData { // 0x68
   // ctor: 0x00D6B3E0
   // init: 0x00D6B760
    bool mFlipX; // 0x61
    bool mFlipY; // 0x62
    bool mPerPixelUvsX; // 0x63
    unique_ptr_t<AtlasData> mAtlas; // 0x64
};
struct EffectDesaturateElementData: EffectElementData { // 0x68
   // ctor: 0x00D6ACE0
   // init: 0x00D6A6F0
    float_t MinimumSaturation; // 0x48
    float_t MaximumSaturation; // 0x4C
    bool mFlipX; // 0x61
    bool mFlipY; // 0x62
    bool mPerPixelUvsX; // 0x63
    unique_ptr_t<AtlasData> mAtlas; // 0x64
};
struct EffectRotatingIconElementData: EffectElementData { // 0x68
   // ctor: 0x00D6B520
   // init: 0x00D6B050
    unique_ptr_t<AtlasData> mAtlas; // 0x64
};
struct EffectGlowingRotatingIconElementData: EffectRotatingIconElementData { // 0x68
   // ctor: 0x00D6AB00
   // init: 0x00D6ADF0
    float_t CycleTime; // 0x48
    float_t m_0x054C178E; // 0x4C
};
struct EffectAnimatedRotatingIconElementData: EffectAnimationElementData { // 0x6C
   // ctor: 0x00D6B3C0
   // init: 0x00D6B580
};
struct EffectLineElementData: EffectElementData { // 0x70
   // ctor: 0x00D6B220
   // init: 0x00D6AFB0
    unique_ptr_t<AtlasData> mAtlas; // 0x64
    float_t mThickness; // 0x68
    float_t mRightSlicePercentage; // 0x6C
};
struct EffectInstancedElementData: EffectElementData { // 0x74
   // ctor: 0x00D6B7B0
   // init: 0x00D6B670
    bool mFlipX; // 0x61
    bool mFlipY; // 0x62
    bool mPerPixelUvsX; // 0x63
    unique_ptr_t<AtlasData> mAtlas; // 0x64
    vector_t<point2D_t> mAdditionalOffsets; // 0x68
};
struct EffectCircleMaskDesaturateElementData: EffectDesaturateElementData { // 0x68
   // ctor: 0x00D6B2B0
   // init: 0x00D6B3F0
};
struct t_0xF6FD1C96: EffectElementData { // 0x6C
   // ctor: 0x00D6B880
   // init: 0x00D6B1A0
    link_ptr_t<StaticMaterialDef> mMaterial; // 0x68
};
struct t_0x231DD1A2: PropertyBase { // 0x14
   // ctor: 0x00400000
   // init: 0x00400000
    string_t mName; // 0x4
    link_ptr_t<SceneData> mScene; // 0x10
};
struct IconElementDataExtension: PropertyBase { // 0x4
   // ctor: 0x00400000
   // init: 0x00400000
};
struct IconElementGradientExtension: IconElementDataExtension { // 0x44
   // ctor: 0x00D6AB80
   // init: 0x00D6AC70
    point4D_t mStartColor; // 0x4
    point4D_t mEndColor; // 0x14
    uint32_t mGradientDirection; // 0x24
    point4D_t m_0x4DFF519D; // 0x28
    string_t mAlphaTexture; // 0x38
};
struct IconElementData: BaseElementData { // 0x5C
   // ctor: 0x00D6B150
   // init: 0x00D6AAC0
    color_t mColor; // 0x48
    bool mUseAlpha; // 0x4C
    bool mFlipX; // 0x4D
    bool mFlipY; // 0x4E
    bool mPerPixelUvsX; // 0x4F
    unique_ptr_t<AtlasDataBase> mAtlas; // 0x50
    link_ptr_t<StaticMaterialDef> mMaterial; // 0x54
    unique_ptr_t<IconElementDataExtension> mExtension; // 0x58
};
struct ParticleSystemElementData: BaseElementData { // 0x54
   // ctor: 0x00D6B540
   // init: 0x00D6AD60
    link_ptr_t<VfxSystemDefinitionData> mVfxSystem; // 0x48
    uint32_t m_0xC47CF6C7; // 0x4C
    bool m_0x02824440; // 0x50
    bool m_0x94B088EA; // 0x51
    bool m_0x8EF629C9; // 0x52
};
struct RegionElementData: BaseElementData { // 0x48
   // ctor: 0x00D6ACB0
   // init: 0x00D6A6D0
};
struct ScissorRegionElementData: BaseElementData { // 0x4C
   // ctor: 0x00D6ADA0
   // init: 0x00D6AFC0
    link_ptr_t<SceneData> m_0xACCC80B5; // 0x48
};
struct TextElementData: BaseElementData { // 0x64
   // ctor: 0x00D6AF20
   // init: 0x00D6B370
    string_t TraKey; // 0x48
    link_ptr_t<GameFontDescription> mFontDescription; // 0x54
    uint8_t mTextAlignmentHorizontal; // 0x58
    uint8_t mTextAlignmentVertical; // 0x59
    uint8_t WrappingMode; // 0x5A
    float_t IconScale; // 0x5C
    link_ptr_t<CssSheet> m_0x7C0A8359; // 0x60
};
struct t_0x63394A54 { // 0x54
   // ctor: 0x00A35C10
   // init: 0x00A35870
    vector_t<hash_t> DefaultStateElements; // 0x0
    vector_t<hash_t> InactiveStateElements; // 0xC
    vector_t<hash_t> HoverStateElements; // 0x18
    vector_t<hash_t> m_0xAD0F8882; // 0x24
    vector_t<hash_t> SelectedStateElements; // 0x30
    vector_t<hash_t> SelectedHoverStateElements; // 0x3C
    vector_t<hash_t> SelectedClickedStateElements; // 0x48
};
struct t_0xFC2D67AA { // 0x48
   // ctor: 0x00A35770
   // init: 0x00A35BA0
    string_t RolloverEvent; // 0x0
    string_t m_0x210EA29E; // 0xC
    string_t MouseDownEvent; // 0x18
    string_t m_0x0452034C; // 0x24
    string_t MouseUpEvent; // 0x30
    string_t m_0xB49CA145; // 0x3C
};
struct t_0x6780C1C5 { // 0x10
   // ctor: 0x005CA800
   // init: 0x005CA650
    vector_t<link_ptr_t<t_0x231DD1A2>> DisplayElements; // 0x0
    link_ptr_t<TextElementData> TextElement; // 0xC
};
struct t_0x25E82B58: t_0x89FA8D1C { // 0xB8
   // ctor: 0x00D6B4A0
   // init: 0x00D6AFE0
    t_0x6780C1C5 DefaultStateElements; // 0x20
    t_0x6780C1C5 InactiveStateElements; // 0x30
    t_0x6780C1C5 HoverStateElements; // 0x40
    t_0x6780C1C5 m_0xAD0F8882; // 0x50
    t_0x6780C1C5 SelectedStateElements; // 0x60
    t_0x6780C1C5 SelectedHoverStateElements; // 0x70
    t_0x6780C1C5 SelectedClickedStateElements; // 0x80
    link_ptr_t<RegionElementData> HitRegionElement; // 0x90
    link_ptr_t<ParticleSystemElementData> ClickReleaseParticleElement; // 0x94
    unique_ptr_t<t_0xFC2D67AA> SoundEvents; // 0x98
    string_t ActiveTooltipTraKey; // 0x9C
    string_t InactiveTooltipTraKey; // 0xA8
    bool IsActive; // 0xB4
    bool IsEnabled; // 0xB5
    bool IsSelected; // 0xB6
};
struct t_0x89FA8D1C: t_0x231DD1A2 { // 0x20
   // ctor: 0x00D6B2D0
   // init: 0x00D6B100
    vector_t<link_ptr_t<t_0x231DD1A2>> Elements; // 0x14
};
struct t_0x345C1C77: t_0x89FA8D1C { // 0x24
   // ctor: 0x00D6B750
   // init: 0x00D6B7D0
    link_ptr_t<IconElementData> m_0x76EF64DE; // 0x20
};
struct t_0xA51270E5: PropertyBase { // 0x8
   // ctor: 0x00400000
   // init: 0x00400000
    uint8_t m_0xA1527EAD; // 0x4
    uint8_t m_0xF00A885B; // 0x5
};
struct t_0x26F2A088: t_0xA51270E5 { // 0xC
   // ctor: 0x00D6A8E0
   // init: 0x00D6AF70
    uint8_t m_0xBBD94716; // 0x8
};
struct t_0xB277FA06: t_0xA51270E5 { // 0xC
   // ctor: 0x00D6B0D0
   // init: 0x00D6A6B0
    uint8_t m_0xB49ED6F0; // 0x8
};
struct t_0xD7D5F570: t_0xA51270E5 { // 0xC
   // ctor: 0x00D6B4C0
   // init: 0x00D6AA40
    uint8_t m_0x590BD78C; // 0x8
    uint8_t m_0xBBD94716; // 0x9
};
struct t_0x89A3465F: t_0x89FA8D1C { // 0x28
   // ctor: 0x00D6AB70
   // init: 0x00D6A770
    link_ptr_t<RegionElementData> Region; // 0x20
    unique_ptr_t<t_0xA51270E5> m_0xFA4C41A0; // 0x24
};
struct t_0x560E6C39 { // 0x24
   // ctor: 0x00D6AF90
   // init: 0x00D6B270
    string_t m_0xD8073196; // 0x0
    string_t m_0x8F1A336D; // 0xC
    string_t m_0x73DBEF7A; // 0x18
};
struct t_0xDF3BDC62 { // 0xC
   // ctor: 0x00D6A750
   // init: 0x00D6AEA0
    link_ptr_t<IconElementData> BarBackdrop; // 0x0
    link_ptr_t<IconElementData> BarFill; // 0x4
    link_ptr_t<IconElementData> SliderIcon; // 0x8
};
struct t_0x474F1541: t_0x89FA8D1C { // 0x64
   // ctor: 0x00D6AB10
   // init: 0x00D6B660
    t_0xDF3BDC62 DefaultState; // 0x20
    t_0xDF3BDC62 SliderClickedState; // 0x2C
    t_0xDF3BDC62 m_0x05B9CBD0; // 0x38
    t_0xDF3BDC62 m_0xB4F0CBDE; // 0x44
    link_ptr_t<RegionElementData> BarHitRegion; // 0x50
    link_ptr_t<RegionElementData> SliderHitRegion; // 0x54
    uint8_t Direction; // 0x58
    unique_ptr_t<t_0x560E6C39> SoundEvents; // 0x5C
};
struct X3dSharedConstantDef { // 0x20
   // ctor: 0x00D84EC0
   // init: 0x00D84F30
    string_t Name; // 0x0
    uint32_t Type; // 0xC
    uint32_t Count; // 0x10
    int32_t Register; // 0x14
    bool SetManually; // 0x18
    uint32_t PlatformMask; // 0x1C
};
struct X3dSharedConstantBufferDef { // 0x2C
   // ctor: 0x00D84DE0
   // init: 0x00D84DF0
    string_t Name; // 0x0
    uint32_t Type; // 0xC
    uint32_t Frequency; // 0x10
    vector_t<X3dSharedConstantDef> Constants; // 0x14
    bool m_0xA87049BC; // 0x20
    int32_t Register; // 0x24
    uint32_t PlatformMask; // 0x28
};
struct X3dSharedData { // 0x18
   // ctor: 0x00608900
   // init: 0x00608F30
    vector_t<link_ptr_t<X3dSharedConstantBufferDef>> m_0xE595DD78; // 0x0
    vector_t<X3dSharedTextureDef> Textures; // 0xC
};
struct X3dSharedTextureDef { // 0x18
   // ctor: 0x00D84F70
   // init: 0x00D84E90
    string_t Name; // 0x0
    uint32_t Type; // 0xC
    int32_t Register; // 0x10
    uint32_t PlatformMask; // 0x14
};
