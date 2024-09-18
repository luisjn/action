#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "ActionGameplayAbility.generated.h"

class UPawnCombatComponent;
class UActionAbilitySystemComponent;

UENUM(BlueprintType)
enum class EActionAbilityActivationPolicy : uint8
{
	OnTriggered,
	OnGiven
};

/**
 * 
 */
UCLASS()
class ACTION_API UActionGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

protected:
	//~ Begin UGameplayAbility Interface.
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;
	//~ End UGameplayAbility Interface

	UPROPERTY(EditDefaultsOnly, Category = "ActionAbility")
	EActionAbilityActivationPolicy AbilityActivationPolicy = EActionAbilityActivationPolicy::OnTriggered;

	UFUNCTION(BlueprintPure, Category = "Action|Ability")
	UPawnCombatComponent* GetPawnCombatComponentFromActorInfo() const;

	UFUNCTION(BlueprintPure, Category = "Action|Ability")
	UActionAbilitySystemComponent* GetActionAbilitySystemComponentFromActorInfo() const;
};
