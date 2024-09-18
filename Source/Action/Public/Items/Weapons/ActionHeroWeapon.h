#pragma once

#include "CoreMinimal.h"
#include "ActionWeaponBase.h"
#include "ActionTypes/ActionStructTypes.h"
#include "GameplayAbilitySpecHandle.h"
#include "ActionHeroWeapon.generated.h"

UCLASS()
class ACTION_API AActionHeroWeapon : public AActionWeaponBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "WeaponData")
	FActionHeroWeaponData HeroWeaponData;

	UFUNCTION(BlueprintCallable)
	void AssignGrantedAbilitySpecHandles(const TArray<FGameplayAbilitySpecHandle>& InSpecHandles);

	UFUNCTION(BlueprintPure)
	TArray<FGameplayAbilitySpecHandle> GetGrantedAbilitySpecHandles() const;

private:
	TArray<FGameplayAbilitySpecHandle> GrantedAbilitySpecHandles;
};
