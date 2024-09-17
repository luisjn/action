#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "ActionCharacterBase.generated.h"

class UActionAbilitySystemComponent;
class UActionAttributeSet;
class UDataAsset_StartUpDataBase;

UCLASS()
class ACTION_API AActionCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AActionCharacterBase();

	//~ Begin IAbilitySystemInterface Interface.
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	//~ End IAbilitySystemInterface Interface

protected:
	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	UActionAbilitySystemComponent* ActionAbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	UActionAttributeSet* ActionAttributeSet;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CharacterData")
	TSoftObjectPtr<UDataAsset_StartUpDataBase> CharacterStartUpData;

public:
	FORCEINLINE UActionAbilitySystemComponent* GetActionAbilitySystemComponent() const {return ActionAbilitySystemComponent;}

	FORCEINLINE UActionAttributeSet* GetActionAttributeSet() const {return ActionAttributeSet;}
};
