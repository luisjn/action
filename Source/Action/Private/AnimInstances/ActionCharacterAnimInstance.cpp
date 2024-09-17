#include "AnimInstances/ActionCharacterAnimInstance.h"
#include "Characters/ActionCharacterBase.h"
#include "GameFramework/CharacterMovementComponent.h"

void UActionCharacterAnimInstance::NativeInitializeAnimation()
{
	OwningCharacter = Cast<AActionCharacterBase>(TryGetPawnOwner());

	if (OwningCharacter)
	{
		OwningMovementComponent = OwningCharacter->GetCharacterMovement();
	}
}

void UActionCharacterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if (!OwningCharacter || !OwningMovementComponent)
	{
		return;
	}

	Velocity = OwningCharacter->GetVelocity();
	GroundSpeed = Velocity.Size2D();

	bHasAcceleration = OwningMovementComponent->GetCurrentAcceleration().SizeSquared2D()>0.f;
	IsFalling = OwningMovementComponent->IsFalling();
	IsCrouching = OwningMovementComponent->IsCrouching();
}