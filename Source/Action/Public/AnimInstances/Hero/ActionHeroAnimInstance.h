#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/ActionCharacterAnimInstance.h"
#include "ActionHeroAnimInstance.generated.h"

class AActionHeroCharacter;
// class UCharacterMovementComponent;

/**
 * 
 */
UCLASS()
class ACTION_API UActionHeroAnimInstance : public UActionCharacterAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|Refrences")
	AActionHeroCharacter* OwningHeroCharacter;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	bool bShouldEnterRelaxState;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	float EnterRelaxStateThreshold = 5.f;

	float IdleElapsedTime;
};
