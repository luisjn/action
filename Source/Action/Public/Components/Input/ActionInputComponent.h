#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "ActionInputComponent.generated.h"

/**
 * 
 */
UCLASS()
class ACTION_API UActionInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	template<class UserObject,typename CallbackFunc, typename... VarTypes>
	void BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig,const FGameplayTag& InInputTag,ETriggerEvent TriggerEvent,UserObject* ContextObject,CallbackFunc Func,VarTypes... Vars);
};

template<class UserObject, typename CallbackFunc, typename... VarTypes>
inline void UActionInputComponent::BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func, VarTypes... Vars)
{
	checkf(InInputConfig,TEXT("Input config data asset is null,can not proceed with binding"));

	if (UInputAction* FoundAction = InInputConfig->FindNativeInputActionByTag(InInputTag))
	{
		BindAction(FoundAction,TriggerEvent,ContextObject,Func,Vars...);
	}
}