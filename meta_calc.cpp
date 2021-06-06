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
// NEW
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
struct ObjectTags { // 0x18
   // ctor: 0x00932E40
   // init: 0x00608DA0
    string_t mTagList; // 0x8
};
