#include "ActionTypes/ActionStructTypes.h"
#include "AbilitySystem/Abilities/ActionHeroGameplayAbility.h"

bool FActionHeroAbilitySet::IsValid() const
{
	return InputTag.IsValid() && AbilityToGrant;
}
