#include "Characters/ActionCharacterBase.h"
#include "AbilitySystem/ActionAbilitySystemComponent.h"
#include "AbilitySystem/ActionAttributeSet.h"

// Sets default values
AActionCharacterBase::AActionCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals = false;

	ActionAbilitySystemComponent = CreateDefaultSubobject<UActionAbilitySystemComponent>(TEXT("ActionAbilitySystemComponent"));

	ActionAttributeSet = CreateDefaultSubobject<UActionAttributeSet>(TEXT("ActionAttributeSet"));
}

UAbilitySystemComponent* AActionCharacterBase::GetAbilitySystemComponent() const
{
	return GetActionAbilitySystemComponent();
}

void AActionCharacterBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (ActionAbilitySystemComponent)
	{
		ActionAbilitySystemComponent->InitAbilityActorInfo(this,this);
	}
}