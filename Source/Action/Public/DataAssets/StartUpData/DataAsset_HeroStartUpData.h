#pragma once

#include "CoreMinimal.h"
#include "DataAsset_StartUpDataBase.h"
#include "ActionTypes/ActionStructTypes.h"
#include "DataAsset_HeroStartUpData.generated.h"

/**
 * 
 */
UCLASS()
class ACTION_API UDataAsset_HeroStartUpData : public UDataAsset_StartUpDataBase
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(UActionAbilitySystemComponent* InAscToGive,int32 ApplyLevel = 1) override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData", meta = (TitleProperty = "InputTag"))
	TArray<FActionHeroAbilitySet> HeroStartUpAbilitySets;
};
