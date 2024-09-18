#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/PawnExtensionComponentBase.h"
#include "PawnCombatComponent.generated.h"

class AActionWeaponBase;

UCLASS()
class ACTION_API UPawnCombatComponent : public UPawnExtensionComponentBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Action|Combat")
	void RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister,AActionWeaponBase* InWeaponToRegister,bool bRegisterAsEquippedWeapon = false);

	UFUNCTION(BlueprintCallable, Category = "Action|Combat")
	AActionWeaponBase* GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const;

	UPROPERTY(BlueprintReadWrite, Category = "Action|Combat")
	FGameplayTag CurrentEquippedWeaponTag;

	UFUNCTION(BlueprintCallable, Category = "Action|Combat")
	AActionWeaponBase* GetCharacterCurrentEquippedWeapon() const;

private:
	TMap<FGameplayTag,AActionWeaponBase*> CharacterCarriedWeaponMap;
};
