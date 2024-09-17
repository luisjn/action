#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"

#include "GameplayAbilitySpec.h"
#include "AbilitySystem/ActionAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/ActionGameplayAbility.h"

void UDataAsset_StartUpDataBase::GiveToAbilitySystemComponent(UActionAbilitySystemComponent* InAscToGive,
                                                              int32 ApplyLevel)
{
	check(InAscToGive);

	GrantAbilities(ActivateOnGivenAbilities,InAscToGive,ApplyLevel);
	GrantAbilities(ReactiveAbilities,InAscToGive,ApplyLevel); 
}

void UDataAsset_StartUpDataBase::GrantAbilities(const TArray<TSubclassOf<UActionGameplayAbility>>& InAbilitiesToGive,
	UActionAbilitySystemComponent* InAscToGive, int32 ApplyLevel)
{
	if (InAbilitiesToGive.IsEmpty())
	{
		return;
	}

	for (const TSubclassOf<UActionGameplayAbility>& Ability : InAbilitiesToGive)
	{
		if(!Ability) continue;

		FGameplayAbilitySpec AbilitySpec(Ability);
		AbilitySpec.SourceObject = InAscToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;

		InAscToGive->GiveAbility(AbilitySpec);
	}
}
