#!/usr/bin/env python3
import json
import calc
from calc import CalculateContext
from meta import MetaBase, MetaCreate, Hash

annie = json.load(open("json/champs/annie.bin.json"))
annie = { k: MetaCreate(MetaBase, v) for k,v in annie.items() }
R = annie["Characters/Annie/Spells/AnnieRAbility/AnnieR"].mSpell
R_burst_damage = R.mSpellCalculations[Hash("InitialBurstDamage")]

print(R_burst_damage.GetResult(CalculateContext(spell = R, spell_level = 1)))
