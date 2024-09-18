#include "Components/Combat/HeroCombatComponent.h"
#include "Items/Weapons/ActionHeroWeapon.h"

AActionHeroWeapon* UHeroCombatComponent::GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const
{	
	return Cast<AActionHeroWeapon>(GetCharacterCarriedWeaponByTag(InWeaponTag));
}
