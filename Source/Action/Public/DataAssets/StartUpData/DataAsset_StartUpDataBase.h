#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartUpDataBase.generated.h"

class UActionGameplayAbility;
class UActionAbilitySystemComponent;

/**
 * 
 */
UCLASS()
class ACTION_API UDataAsset_StartUpDataBase : public UDataAsset
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(UActionAbilitySystemComponent* InAscToGive,int32 ApplyLevel = 1);

protected:
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray< TSubclassOf < UActionGameplayAbility > > ActivateOnGivenAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray< TSubclassOf < UActionGameplayAbility > > ReactiveAbilities;

	void GrantAbilities(const TArray< TSubclassOf < UActionGameplayAbility > >& InAbilitiesToGive,UActionAbilitySystemComponent* InAscToGive,int32 ApplyLevel = 1);
};
