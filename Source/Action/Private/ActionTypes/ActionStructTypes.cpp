#include "ActionTypes/ActionStructTypes.h"
#include "AbilitySystem/Abilities/ActionGameplayAbility.h"

bool FActionHeroAbilitySet::IsValid() const
{
	return InputTag.IsValid() && AbilityToGrant;
}
