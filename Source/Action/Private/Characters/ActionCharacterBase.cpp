#include "Characters/ActionCharacterBase.h"
#include "AbilitySystem/ActionAbilitySystemComponent.h"
#include "AbilitySystem/ActionAttributeSet.h"
#include "MotionWarpingComponent.h"

// Sets default values
AActionCharacterBase::AActionCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals = false;

	ActionAbilitySystemComponent = CreateDefaultSubobject<UActionAbilitySystemComponent>(TEXT("ActionAbilitySystemComponent"));

	ActionAttributeSet = CreateDefaultSubobject<UActionAttributeSet>(TEXT("ActionAttributeSet"));

	MotionWarpingComponent = CreateDefaultSubobject<UMotionWarpingComponent>(TEXT("MotionWarpingComponent"));
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

		ensureMsgf(!CharacterStartUpData.IsNull(),TEXT("Forgot to assign start up data to %s"),*GetName());
	}
}