#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ActionFunctionLibrary.generated.h"

class UActionAbilitySystemComponent;

UENUM()
enum class EActionConfirmType : uint8
{
	Yes,
	No
};

/**
 * 
 */
UCLASS()
class ACTION_API UActionFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static UActionAbilitySystemComponent* NativeGetWarriorASCFromActor(AActor* InActor);

	UFUNCTION(BlueprintCallable, Category = "Action|FunctionLibrary")
	static void AddGameplayTagToActorIfNone(AActor* InActor,FGameplayTag TagToAdd);

	UFUNCTION(BlueprintCallable, Category = "Action|FunctionLibrary")
	static void RemoveGameplayFromActorIfFound(AActor* InActor,FGameplayTag TagToRemove);

	static bool NativeDoesActorHaveTag(AActor* InActor,FGameplayTag TagToCheck);

	UFUNCTION(BlueprintCallable, Category = "Action|FunctionLibrary", meta = (DisplayName = "Does Actor Have Tag", ExpandEnumAsExecs = "OutConfirmType"))
	static void BP_DoesActorHaveTag(AActor* InActor,FGameplayTag TagToCheck,EActionConfirmType& OutConfirmType);
};
