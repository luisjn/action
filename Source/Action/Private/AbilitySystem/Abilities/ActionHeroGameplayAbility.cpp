#include "AbilitySystem/Abilities/ActionHeroGameplayAbility.h"
#include "Characters/ActionHeroCharacter.h"
#include "Controllers/ActionHeroController.h"

AActionHeroCharacter* UActionHeroGameplayAbility::GetHeroCharacterFromActorInfo()
{
	if (!CachedActionHeroCharacter.IsValid())
	{
		CachedActionHeroCharacter = Cast<AActionHeroCharacter>(CurrentActorInfo->AvatarActor);
	}

	return CachedActionHeroCharacter.IsValid()? CachedActionHeroCharacter.Get() : nullptr;
}

AActionHeroController* UActionHeroGameplayAbility::GetHeroControllerFromActorInfo()
{
	if (!CachedActionHeroController.IsValid())
	{
		CachedActionHeroController = Cast<AActionHeroController>(CurrentActorInfo->PlayerController);
	}

	return CachedActionHeroController.IsValid()? CachedActionHeroController.Get() : nullptr;
}

UHeroCombatComponent* UActionHeroGameplayAbility::GetHeroCombatComponentFromActorInfo()
{
	return GetHeroCharacterFromActorInfo()->GetHeroCombatComponent();
}
