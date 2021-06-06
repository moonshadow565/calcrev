// ida preprocessor is broken can't automatically switch this depending on arch
#define THISCALL __fastcall
#define THISCALL __thiscall
#define make_virt_destructor(name) void* dtor[sizeof(void*) / 4]

struct Breakpoint;
struct UnitStatComponent;
struct SpellData;
struct GameCalculation;
struct IGameCalculation;
struct IGameCalculationPart;
struct ICastRequirement;
struct RatioConversion;
struct SpellModifier;
struct SpellModifiersApplicator;
struct GlobalStatsUIData;

/// Basic types
struct AString {
    char* data;
    uint32_t size;
    uint32_t capacity;
};
struct hash_t {
    uint32_t hash;
};

/// Instantiate vectors
struct vector_of_Breakpoint {
    Breakpoint* data;
    uint32_t size;
    uint32_t capacity;
};
struct vector_of_p_ICastRequirement {
    ICastRequirement** data;
    uint32_t size;
    uint32_t capacity;
};
struct vector_ptrs_of_IGameCalculationPart {
    IGameCalculationPart** data;
    uint32_t size;
    uint32_t capacity;
};
struct vector_of_uint8_t {
    uint8_t* data;
    uint32_t size;
    uint32_t capacity;
};
struct std_vector_of_RatioConversion {
    RatioConversion* beg;
    RatioConversion* end;
    RatioConversion* cap;
};
struct std_vector_of_p_SpellModifier {
    SpellModifier** beg;
    SpellModifier** end;
    SpellModifier** cap;
};

/// Common data structures
struct StatCalc { // this might actually be just Unit::StatInfo
    uint8_t mStat;
    uint8_t mStatFormula;
    float value;
};
struct Unit::StatInfo {
    uint8_t statType;
    float base;
    float bonus;
    float total;
    float unk16;
    float unk20;
};

struct UnitStatComponentVtable {
    make_virt_destructor(UnitStatComponent);
    int (THISCALL *GetCooldownMultiplyMaybe)(UnitStatComponent *this, int slot, float *out);
    float (THISCALL *GetStatTotal)(UnitStatComponent *this, const StatCalc *a1);
    float (THISCALL *GetAbilityResource)(UnitStatComponent *this, uint8_t mAbilityResourceType, uint8_t statFormula);
    int (THISCALL *GetBuffInstanceCounter)(UnitStatComponent *this, const hash_t *buffNameHash);
    int (THISCALL *unk20)(UnitStatComponent *this, uint8_t epicness);
    int (THISCALL *GetCharLevel)(UnitStatComponent *this);
    float (THISCALL *unk28)(UnitStatComponent *this, int a2);
    int (THISCALL *owner) (UnitStatComponent *this);
};
struct UnitStatComponent {
    UnitStatComponentVtable* vtable;
    size_t aibase;
};

struct SpellModifiersApplicatorVtable {
    make_virt_destructor(SpellModifiersApplicator);
    void (THISCALL* Apply) (SpellModifiersApplicator *this, StatCalc *out);
};
struct SpellModifiersApplicator {
    SpellModifiersApplicatorVtable* vtable;
    SpellData* spellData;
    std_vector_of_p_SpellModifier modifiers;
};

struct SpellDataVtable {
    make_virt_destructor(SpellData);
    IGameCalculation* (THISCALL* GetResourceGameCalculation) (SpellData* this, uint32_t calculationHash);
    void (THISCALL* GetResourceSpellDataValuePerLevel) (SpellData* this, uint32_t dataValueHash, uint32_t level, float *out);
    void (THISCALL* GetResourceSpellEffectAmountPerLevel) (SpellData* this, int effectIndex, int level, float *out);
    SpellModifiersApplicator* (THISCALL* GetSpellModifiersApplicator) (SpellData* this, UnitStatComponent* unitStatComponent);
    void (THISCALL* Reset) (SpellData* this, bool a2);
};
struct SpellData {
    SpellDataVtable* vtable;
};

/// Overwrite generated stuff
struct SpellCalculationGenerationData {
    int count;
    float multiplier;
    UnitStatComponent* unitStatComponent;
    GameCalculation *calculation;
    SpellData* spellData;
    GlobalStatsUIData *p_GlobalStatsUIData;
    int level;
    int slot;
    SpellModifiersApplicator* spellModifiersApplicator;
};
struct IGameCalculationPartVtable {
    make_virt_destructor(IGameCalculationPart);
    void *(THISCALL *GetMetaClassVirtual)(IGameCalculationPart *this);
    void (THISCALL *Init)(IGameCalculationPart *this);
    float (THISCALL *GetResult)(IGameCalculationPart *this, SpellCalculationGenerationData *data);
    float (THISCALL *GetResult2)(IGameCalculationPart *this, SpellCalculationGenerationData *data);
    size_t unk0;
    uint8_t (THISCALL *AppendStat)(IGameCalculationPart *this, vector_of_uint8_t *out_stats);
    size_t unk[6];
    float (THISCALL *ResultPerLevel)(IGameCalculationPart *this, SpellCalculationGenerationData *data, int level);
};
struct IGameCalculationPart {
    IGameCalculationPartVtable* vtable;
};

struct CastRequirementContext {
    int slot;
    size_t aibase1;
    size_t aibase2;
};
struct ICastRequirementVtable {
    make_virt_destructor(ICastRequirement);
    void* (THISCALL* GetMetaClassVirtual) (ICastRequirement *this);
    void (THISCALL* Init) (ICastRequirement *this);
    bool (THISCALL* Fullfill) (ICastRequirement *this, CastRequirementContext* ctxt);
};
struct ICastRequirement { // 0x8
    ICastRequirementVtable* vtable;
    bool mInvertResult; // 0x4
};

struct IGameCalculationVtable {
    make_virt_destructor(IGameCalculation);
    void* (THISCALL* GetMetaClassVirtual) (IGameCalculation *this);
    void (THISCALL* Init) (IGameCalculation *this);
    float (THISCALL* ResultNum) (IGameCalculation *this, UnitStatComponent* unitStatComponent, SpellData* spellData, int slot, int level);
    void (THISCALL* ResultStats) (IGameCalculation *this, SpellData *spellData, vector_of_uint8_t* stats);
    void (THISCALL* ResultString) (IGameCalculation *this, UnitStatComponent* unitStatComponent, SpellData* spellData, int slot, int level, char outputType, AString *out);
    IGameCalculation* (THISCALL* GetSelf) (IGameCalculation *this);
};
struct IGameCalculation { // 0xC
    IGameCalculationVtable* vtable;
    IGameCalculationPart* mMultiplier; // 0x4
    uint8_t m_0xCBCAC618; // 0x8
    uint8_t m_0x37070A8D; // 0x9
    uint8_t m_0xE6EEBB2F; // 0xA
    bool tooltipOnly; // 0xB
};

/// Generated
struct ObjectTags { // 0x18
    uint64_t flags; // this doesn't exist in meta
    AString mTagList; // 0x8
};
struct RatioConversion {
    uint8_t mSourceStatType; // 0x0
    uint8_t mSourceStatOutput; // 0x1
    uint8_t mResultingStatType; // 0x2
    uint8_t mResultingStatOutput; // 0x3
    float m_0x9227CE44; // 0x4
};
struct SpellModifier { // 0x18
    hash_t mModifierID; // 0x0
    uint8_t m_0xA9CC2BF6; // 0x4
    uint8_t m_0xA47F56D7; // 0x5
    uint32_t m_0x5B1192F5; // 0x8
    std_vector_of_RatioConversion m_0x441A3020; // 0xC
};

/// Generated
struct GameCalculation: IGameCalculation { // 0x20
    vector_ptrs_of_IGameCalculationPart mFormulaParts; // 0xC
    bool mDisplayAsPercent; // 0x18
    int32_t mPrecision; // 0x1C
};
struct GameCalculationModified: IGameCalculation { // 0x14
    int32_t mOverrideSpellLevel; // 0xC
    hash_t mModifiedGameCalculation; // 0x10
};
struct GameCalculationConditional: IGameCalculation { // 0x18
    hash_t mDefaultGameCalculation; // 0xC
    hash_t mConditionalGameCalculation; // 0x10
    ICastRequirement* m_0xC0482365; // 0x14
};

struct EffectValueCalculationPart: IGameCalculationPart { // 0x8
    int32_t mEffectIndex; // 0x4
};
struct NamedDataValueCalculationPart: IGameCalculationPart { // 0x8
    hash_t mDataValue; // 0x4
};
struct CooldownMultiplierCalculationPart: IGameCalculationPart { // 0x4
};
struct CustomReductionMultiplierCalculationPart: IGameCalculationPart { // 0xC
    IGameCalculationPart* m_0x6E82B179; // 0x4
    float mMaximumReductionPercent; // 0x8
};
struct ProductOfSubPartsCalculationPart: IGameCalculationPart { // 0xC
    IGameCalculationPart* mPart1; // 0x4
    IGameCalculationPart* mPart2; // 0x8
};
struct SumOfSubPartsCalculationPart: IGameCalculationPart { // 0x10
    vector_ptrs_of_IGameCalculationPart mSubparts; // 0x4
};
struct NumberCalculationPart: IGameCalculationPart { // 0x8
    float mNumber; // 0x4
};
struct IGameCalculationPartWithStats: IGameCalculationPart { // 0x8
    uint8_t mStat; // 0x4
    uint8_t mStatFormula; // 0x5
};
struct StatByCoefficientCalculationPart: IGameCalculationPartWithStats { // 0xC
    float mCoefficient; // 0x8
};
struct StatBySubPartCalculationPart: IGameCalculationPartWithStats { // 0xC
    IGameCalculationPart* mSubpart; // 0x8
};
struct StatByNamedDataValueCalculationPart: IGameCalculationPartWithStats { // 0xC
    hash_t mDataValue; // 0x8
};
struct SubPartScaledProportionalToStat: IGameCalculationPart { // 0x28
    IGameCalculationPart* mSubpart; // 0x4
    float mRatio; // 0x8
    uint8_t mStat; // 0xC
    uint8_t mStatFormula; // 0xD
    AString mStyleTag; // 0x10
    AString m_0xA5749B52; // 0x1C
};
struct AbilityResourceByCoefficientCalculationPart: IGameCalculationPart { // 0xC
    float mCoefficient; // 0x4
    uint8_t mAbilityResource; // 0x8
    uint8_t mStatFormula; // 0x9
};
struct IGameCalculationPartWithBuffCounter: IGameCalculationPart { // 0x20
    hash_t mBuffName; // 0x4
    AString mIconKey; // 0x8
    AString mScalingTagKey; // 0x14
};
struct BuffCounterByCoefficientCalculationPart: IGameCalculationPartWithBuffCounter { // 0x24
    float mCoefficient; // 0x20
};
struct BuffCounterByNamedDataValueCalculationPart: IGameCalculationPartWithBuffCounter { // 0x24
    hash_t mDataValue; // 0x20
};
struct IGameCalculationPartByCharLevel: IGameCalculationPart { // 0x4
};
struct ByCharLevelInterpolationCalculationPart: IGameCalculationPartByCharLevel { // 0x10
    float mStartValue; // 0x4
    float mEndValue; // 0x8
    bool m_0x7FE8E3B3; // 0xC
    bool m_0xA331F6BF; // 0xD
};
struct ByCharLevelBreakpointsCalculationPart: IGameCalculationPartByCharLevel { // 0x18
    float mLevel1Value; // 0x4
    float m_0x02DEB550; // 0x8
    vector_of_Breakpoint mBreakpoints; // 0xC
};
struct Breakpoint { // 0xC
    uint32_t mLevel; // 0x0
    float m_0xD5FD07ED; // 0x4
    float m_0x57FDC438; // 0x8
};
struct ByCharLevelFormulaCalculationPart: IGameCalculationPartByCharLevel { // 0x80
    float mValues[31]; // 0x4
};
struct t_0x663D5E00: IGameCalculationPart { // 0xC
    float Coefficient; // 0x4
    uint8_t epicness; // 0x8
};
struct t_0x05ABDFAB: IGameCalculationPart { // 0x10
    uint8_t mStat; // 0x4
    uint8_t mStatFormula; // 0x5
    hash_t mDataValue; // 0x8
    float m_0xBFE6AD01; // 0xC
};
struct t_0xE9FB4D18: IGameCalculationPart { // 0xC
    IGameCalculationPart* m_0x616627C4; // 0x4
    uint8_t m_0x465802EA; // 0x8
    uint8_t m_0x27833DCC; // 0x9
};
struct t_0x803DAE4C: IGameCalculationPart { // 0x18
    float mCeiling; // 0x4
    float mFloor; // 0x8
    vector_ptrs_of_IGameCalculationPart mSubparts; // 0xC
};
struct HasAllSubRequirementsCastRequirement: ICastRequirement { // 0x14
    vector_of_p_ICastRequirement mSubRequirements; // 0x8
};
struct HasNNearbyUnitsRequirement: ICastRequirement { // 0x20
    vector_of_p_ICastRequirement mUnitsRequirements; // 0x8
    uint32_t mUnitsRequired; // 0x14
    float mRange; // 0x18
    uint32_t mDistanceType; // 0x1C
};
struct HasNNearbyVisibleUnitsRequirement: ICastRequirement { // 0x20
    vector_of_p_ICastRequirement mUnitsRequirements; // 0x8
    uint32_t mUnitsRequired; // 0x14
    float mRange; // 0x18
    uint32_t mDistanceType; // 0x1C
};
struct HasTypeAndStatusFlags: ICastRequirement { // 0x10
    uint32_t mAffectsTypeFlags; // 0x8
    uint32_t mAffectsStatusFlags; // 0xC
};
struct HasAtleastNSubRequirementsCastRequirement: ICastRequirement { // 0x18
    uint32_t mSuccessesRequired; // 0x8
    vector_of_p_ICastRequirement mSubRequirements; // 0xC
};
struct HasUnitTagsCastRequirement: ICastRequirement { // 0x20
    ObjectTags mUnitTags; // 0x8
};
struct SameTeamCastRequirement: ICastRequirement { // 0x8
};
struct HasBuffCastRequirement: ICastRequirement { // 0x10
    hash_t mBuffName; // 0x8
    bool mFromAnyone; // 0xC
};
struct AboveHealthPercentCastRequirement: ICastRequirement { // 0xC
    float mCurrentPercentHealth; // 0x8
};
struct AbovePARPercentCastRequirement: ICastRequirement { // 0x10
    uint8_t mPARType; // 0x8
    float mCurrentPercentPAR; // 0xC
};
struct IsSpecifiedUnitCastRequirement: ICastRequirement { // 0x14
    hash_t mUnit; // 0x8
};
struct ItemSlotHasChargesCastRequirement: ICastRequirement { // 0x8
};
struct t_0x10F4D0BF: ICastRequirement { // 0x8
};
struct t_0xDC65FFE4: ICastRequirement { // 0x8
};
struct t_0x2E7C5EDA: ICastRequirement { // 0xC
    uint32_t level; // 0x8
};
struct t_0x48284759: ICastRequirement { // 0xC
    float Distance; // 0x8
};
