#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/ActionAnimInstanceBase.h"
#include "ActionHeroLinkedAnimLayer.generated.h"

class UActionHeroAnimInstance;

/**
 * 
 */
UCLASS()
class ACTION_API UActionHeroLinkedAnimLayer : public UActionAnimInstanceBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, meta = (BlueprintThreadSafe))
	UActionHeroAnimInstance* GetHeroAnimInstance() const;	
};
