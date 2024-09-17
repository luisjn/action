#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActionWeaponBase.generated.h"

class UBoxComponent;

UCLASS()
class ACTION_API AActionWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	AActionWeaponBase();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapons")
	UStaticMeshComponent* WeaponMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapons")
	UBoxComponent* WeaponCollisionBox;

public:
	FORCEINLINE UBoxComponent* GetWeaponCollisionBox() const { return WeaponCollisionBox;}
};
