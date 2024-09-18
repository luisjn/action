#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/ActionGameplayAbility.h"
#include "ActionHeroGameplayAbility.generated.h"

class AActionHeroCharacter;
class AActionHeroController;

/**
 * 
 */
UCLASS()
class ACTION_API UActionHeroGameplayAbility : public UActionGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Action|Ability")
	AActionHeroCharacter* GetHeroCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Action|Ability")
	AActionHeroController* GetHeroControllerFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Action|Ability")
	UHeroCombatComponent* GetHeroCombatComponentFromActorInfo();

private:
	TWeakObjectPtr<AActionHeroCharacter> CachedActionHeroCharacter;
	TWeakObjectPtr<AActionHeroController> CachedActionHeroController;
};
