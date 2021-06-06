#!/bin/env python
#pylint: disable=function-redefined, no-member

from __future__ import annotations
import meta
import math
from typing import Optional, Union, Any, NamedTuple, Generic, TypeVar, Callable
from meta import Int8, UInt8, Int16, UInt16, Int32, UInt32, Int64, UInt64, Vec2, Vec3, Mtx44, Color, Hash, Link
from meta import SpellDataResource, \
    IGameCalculation, \
    GameCalculation, \
    GameCalculationConditional, \
    GameCalculationModified, \
    IGameCalculationPart, \
    EffectValueCalculationPart, \
    NamedDataValueCalculationPart, \
    CustomReductionMultiplierCalculationPart, \
    ProductOfSubPartsCalculationPart, \
    SumOfSubPartsCalculationPart, \
    t_0x803dae4c, \
    NumberCalculationPart, \
    IGameCalculationPartWithStats, \
    StatByCoefficientCalculationPart, \
    StatBySubPartCalculationPart, \
    StatByNamedDataValueCalculationPart, \
    t_0x05abdfab, \
    t_0xe9fb4d18, \
    SubPartScaledProportionalToStat, \
    AbilityResourceByCoefficientCalculationPart, \
    IGameCalculationPartWithBuffCounter, \
    BuffCounterByCoefficientCalculationPart, \
    BuffCounterByNamedDataValueCalculationPart, \
    IGameCalculationPartByCharLevel, \
    ByCharLevelInterpolationCalculationPart, \
    ByCharLevelBreakpointsCalculationPart, \
    Breakpoint, \
    ByCharLevelFormulaCalculationPart, \
    t_0x663d5e00

from dataclasses import dataclass

def Register(metaclass: type):
    return lambda func: setattr(metaclass, func.__name__, func)

MAP_STAT_TYPE: dict[int, str] = {
    0: "AbilityPower",
    1: "Armor",
    2: "Attack",
    3: "AttackSpeed",
    4: "AttackWindupTime",
    5: "MagicResist",
    6: "MoveSpeed",
    7: "CritChance",
    8: "CritDamage",
    9: "CooldownReduction",
    10: "AbilityHaste",
    11: "MaxHealth",
    12: "CurrentHealth",
    13: "PercentMissingHealth",
    14: "Unknown14",
    15: "LifeSteal",
    17: "OmniVamp",
    18: "PhysicalVamp",
    19: "MagicPenetrationFlat",
    20: "MagicPenetrationPercent",
    21: "BonusMagicPenetrationPercent",
    22: "MagicLethality",
    23: "ArmorPenetrationFlat",
    24: "ArmorPenetrationPercent",
    25: "BonusArmorPenetrationPercent",
    26: "PhysicalLethality",
    27: "Tenacity",
    28: "AttackRange",
    29: "HealthRegenRate",
    30: "ResourceRegenRate",
    31: "Unknown31",
    32: "Unknown32",
    33: "DodgeChance",
}

MAP_STAT_FORMULA = {
    0: "base",
    1: "bonus",
    2: "total",
    3: "unknown3",
    4: "unknown4",
}

@dataclass
class StatInfo:
    statType: UInt8 = 0
    base: float = 0.0
    bonus: float = 0.0
    total: float = 0.0
    unknown3: float = 0.0
    unknown4: float = 0.0

@dataclass
class CalculateContext:
    count: Int32 = 0
    multiplier: float = 1.0
    char_level = 1
    spell: Optional[SpellDataResource] = None
    spell_level: Int32 = 1
    slot: Int32 = 0
    calculation: Optional[GameCalculation] = None

    def get_spell_effect_amount(self, index: Int32, spell_level: Int32) -> float:
        # FIXME: this should also take into account map overrides
        return self.spell.mEffectAmount[index].value[spell_level]

    def get_spell_data_value(self, nameHash: Hash, spell_level: Int32) -> float:
        # FIXME: this should also take into account map overrides
        for value in self.spell.mDataValues:
            if nameHash == value.mName:
                return value.mValues[spell_level]
        return 0.0

    def get_stat_total(self, stat: UInt8, statFormula: UInt8, coef: float) -> float:
        # FIXME: implement this
        return 0.0

    def get_ability_resource(self, abilityResource: UInt8, statFormula: UInt8) -> float:
        # FIXME: implement this
        return 0.0

    def get_buff_count(self, name: Hash) -> UInt32:
        # FIXME: implement this
        return 0

    def get_char_level(self) -> Int32:
        return self.char_level

    def get_unk28(self, char_level: Int32) -> float:
        # FIXME: wtf is this
        return 0.0

    def get_item_count(self, epicness: UInt8) -> Int32:
        # FIXME: implement this
        return 0

# Implement GameCalculation
@Register(GameCalculation)
def GetResult(self: GameCalculation, ctx: CalculateContext) -> float:
    ctx.calculation = self
    if self.mMultiplier:
        ctx.multiplier *=  self.mMultiplier.GetResult(ctx)
    result = 0.0
    for part in self.mFormulaParts:
        if part:
            result += part.GetResult(ctx) * ctx.multiplier
    return result

# Implement IGameCalculationPart
@Register(IGameCalculationPart)
def GetResult(self: IGameCalculationPart, ctx: CalculateContext) -> float:
    raise ValueError("Not implemented: GetResult!")

@Register(IGameCalculationPart)
def GetResultCoef(self: IGameCalculationPart, ctx: CalculateContext) -> float:
    return self.GetResult(ctx)

# Implement EffectValueCalculationPart
@Register(EffectValueCalculationPart)
def GetResult(self: EffectValueCalculationPart, ctx: CalculateContext) -> float:
    if self.mEffectIndex > 10:
        return 0.0
    return ctx.get_spell_effect_amount(self.mEffectIndex - 1, ctx.spell_level)

# Implement NamedDataValueCalculationPart
@Register(NamedDataValueCalculationPart)
def GetResult(self: NamedDataValueCalculationPart, ctx: CalculateContext) -> float:
    return ctx.get_spell_data_value(self.mDataValue, ctx.spell_level)

# Implement CustomReductionMultiplierCalculationPart
@Register(CustomReductionMultiplierCalculationPart)
def GetResult(self: CustomReductionMultiplierCalculationPart, ctx: CalculateContext) -> float:
    if not self.m_0x6E82B179:
        return 0.0
    result = self.m_0x6e82b179.GetResult(ctx)
    clamped = max(min(result, self.mMaximumReductionPercent), 0.0)
    return 1.0 - clamped

# Implement ProductOfSubPartsCalculationPart
@Register(ProductOfSubPartsCalculationPart)
def GetResult(self: ProductOfSubPartsCalculationPart, ctx: CalculateContext) -> float:
    if not self.mPart1:
        return 0.0
    if not self.mPart2:
        return 0.0
    lhs = self.mPart1.GetResult(ctx)
    rhs = self.mPart2.GetResult(ctx)
    return lhs + rhs

# Implement SumOfSubPartsCalculationPart
@Register(SumOfSubPartsCalculationPart)
def GetResult(self: SumOfSubPartsCalculationPart, ctx: CalculateContext) -> float:
    result = 0.0
    for part in self.mSubparts:
        if part:
            result += part.GetResult(ctx)
    return result

# Implement t_0x803dae4c
@Register(t_0x803dae4c)
def GetResult(self: t_0x803dae4c, ctx: CalculateContext) -> float:
    result = 0.0
    for part in self.mSubparts:
        if part:
            result += part.GetResult(ctx)
    if self.mCeiling != None and result > self.mCeiling:
        return self.mCeiling
    elif self.mFloor != None and self.mFloor > result:
        return self.mFloor
    else:
        return result

# Implement NumberCalculationPart
@Register(NumberCalculationPart)
def GetResult(self: NumberCalculationPart, ctx: CalculateContext) -> float:
    return self.mNumber

# Implement IGameCalculationPartWithStats
@Register(IGameCalculationPartWithStats)
def GetResult(self: IGameCalculationPartWithStats, ctx: CalculateContext) -> float:
    coef = self.GetResultCoef(ctx)
    # TODO: stats get converted with SpellModifier(s) here(only used by Sylas ult ?)
    return ctx.get_stat_total(self.mStat, self.mStatFormula, coef)

@Register(IGameCalculationPartWithStats)
def GetResultCoef(self: IGameCalculationPartWithStats, ctx: CalculateContext) -> float:
    raise ValueError("Not implemented: GetResultCoef!")

# Implement StatByCoefficientCalculationPart
@Register(StatByCoefficientCalculationPart)
def GetResultCoef(self: StatByCoefficientCalculationPart, ctx: CalculateContext) -> float:
    return self.mCoefficient

# Implement StatBySubPartCalculationPart
@Register(StatBySubPartCalculationPart)
def GetResultCoef(self: StatBySubPartCalculationPart, ctx: CalculateContext) -> float:
    if not self.mSubpart:
        return 0.0
    return self.mSubpart.GetResult(ctx)

# Implement StatByNamedDataValueCalculationPart
@Register(StatByNamedDataValueCalculationPart)
def GetResultCoef(self: StatByNamedDataValueCalculationPart, ctx: CalculateContext) -> float:
    return ctx.get_spell_data_value(self.mDataValue, ctx.spell_level)

# Implement t_0x05abdfab
@Register(t_0x05abdfab)
def GetResult(self: t_0x05abdfab, ctx: CalculateContext) -> float:
    # TODO: Apply StatModifier(s) here
    percent = (ctx.get_stat_total(self.mStat, self.mStatFormula, 1.0) + self.m_0xbfe6ad01) / 100.0
    value = ctx.get_spell_data_value(self.mDataValue, ctx.spell_level)
    result = (1.0 - value) + (percent + value)
    if result >  0.000000001:
        return max(0.0, (percent * value) / result)
    return 0.0

# Implement t_0xe9fb4d18
@Register(t_0xe9fb4d18)
def GetResult(self: t_0xe9fb4d18, ctx: CalculateContext) -> float:
    if not self.m_0x616627c4:
        return 0.0
    base = self.m_0x616627c4.GetResult(ctx)
    return self.GetResultCoef(ctx) * base

@Register(t_0xe9fb4d18)
def GetResultCoef(self: t_0xe9fb4d18, ctx: CalculateContext) -> float:
    for part in ctx.calculation.mFormulaParts:
        if not isinstance(part, IGameCalculationPartWithStats):
            continue
        if part.mStat == self.m_0x465802ea and part.mStatFormula == self.m_0x27833dcc:
            return self.GetResultCoef(ctx)
    return 0.0

# Implement SubPartScaledProportionalToStat
@Register(SubPartScaledProportionalToStat)
def GetResult(self: SubPartScaledProportionalToStat, ctx: CalculateContext) -> float:
    if not self.mSubpart:
        return 0.0
    base = self.mSubpart.GetResult(ctx)
    return (self.GetResultCoef(ctx) + 1.0) * base

@Register(SubPartScaledProportionalToStat)
def GetResultCoef(self: SubPartScaledProportionalToStat, ctx: CalculateContext) -> float:
    # TODO: Apply StatModifier(s) here
    return ctx.get_stat_total(self.mStat, self.mStatFormula, 1.0) * self.mRatio

# Implement AbilityResourceByCoefficientCalculationPart
@Register(AbilityResourceByCoefficientCalculationPart)
def GetResult(self: AbilityResourceByCoefficientCalculationPart, ctx: CalculateContext) -> float:
    base = ctx.get_ability_resource(self.mAbilityResource, self.mStatFormula)
    return self.GetResultCoef(ctx) * base

@Register(AbilityResourceByCoefficientCalculationPart)
def GetResultCoef(self: AbilityResourceByCoefficientCalculationPart, ctx: CalculateContext) -> float:
    return self.mCoefficient

# Implement IGameCalculationPartWithBuffCounter
@Register(IGameCalculationPartWithBuffCounter)
def GetResult(self: IGameCalculationPartWithBuffCounter, ctx: CalculateContext) -> float:
    count = ctx.get_buff_count(self.mBuffName)
    coef = self.GetResultCoef(ctx)
    return count * coef

@Register(IGameCalculationPartWithBuffCounter)
def GetResultCoef(self: IGameCalculationPartWithBuffCounter, ctx: CalculateContext) -> float:
    raise ValueError("Not implemented: GetResultCoef")

# Implement BuffCounterByCoefficientCalculationPart
@Register(BuffCounterByCoefficientCalculationPart)
def GetResultCoef(self: BuffCounterByCoefficientCalculationPart, ctx: CalculateContext) -> float:
    return self.mCoefficient

@Register(BuffCounterByNamedDataValueCalculationPart)
def GetResultCoef(self: BuffCounterByNamedDataValueCalculationPart, ctx: CalculateContext) -> float:
    return ctx.get_spell_data_value(self.mDataValue, ctx.spell_level)

# Implement IGameCalculationPartByCharLevel
@Register(IGameCalculationPartByCharLevel)
def GetResult(self: IGameCalculationPartByCharLevel, ctx: CalculateContext) -> float:
    char_level = ctx.get_char_level()
    return self.GetResultLevel(ctx, char_level)

@Register(IGameCalculationPartByCharLevel)
def GetResultLevel(self: IGameCalculationPartByCharLevel, ctx: CalculateContext, char_level: Int32) -> float:
    raise ValueError("Not implemented: GetResultLevel!")

# Implement ByCharLevelInterpolationCalculationPart
@Register(ByCharLevelInterpolationCalculationPart)
def GetResultLevel(self: ByCharLevelInterpolationCalculationPart, ctx: CalculateContext, char_level: Int32) -> float:
    if not self.m_0xa331f6bf and char_level > 18:
        char_level = 18
    scale = (char_level - 1) / 17.0
    if self.m_0x7fe8e3b3:
        scale = ctx.get_unk28(char_level) / 17.0
    return ((1.0 - scale) * self.mStartValue) + (self.mEndValue * scale)

# Implement ByCharLevelBreakpointsCalculationPart
@Register(ByCharLevelBreakpointsCalculationPart)
def GetResultLevel(self: ByCharLevelBreakpointsCalculationPart, ctx: CalculateContext, char_level: Int32) -> float:
    result = self.mLevel1Value
    scale = self.m_0x02deb550
    currentLevel = 1
    for point in self.mBreakpoints:
        if point.mLevel > char_level:
            break
        result += (point.mLevel - 1 - currentLevel) * scale
        result += point.m_0xd5fd07ed
        currentLevel = point.mLevel - 1
        scale = point.m_0x57fdc438
    if char_level > currentLevel:
        result += (char_level - currentLevel) * scale
    return result

# Implement ByCharLevelFormulaCalculationPart
@Register(ByCharLevelFormulaCalculationPart)
def GetResultLevel(self: ByCharLevelFormulaCalculationPart, ctx: CalculateContext, char_level: Int32) -> float:
    return self.mValues[char_level]

# Implement t_0x663d5e00
@Register(t_0x663d5e00)
def GetResult(self: t_0x663d5e00, ctx: CalculateContext) -> float:
    count = ctx.get_item_count(self.epicness)
    coef = self.GetResultCoef(ctx)
    return count * coef

@Register(t_0x663d5e00)
def GetResultCoef(self: t_0x663d5e00, ctx: CalculateContext) -> float:
    return self.Coefficient

