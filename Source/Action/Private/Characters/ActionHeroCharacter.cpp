#include "Characters/ActionHeroCharacter.h"
#include "ActionGameplayTags.h"
#include "EnhancedInputSubsystems.h"
#include "AbilitySystem/ActionAbilitySystemComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/Input/ActionInputComponent.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "DataAssets/StartUpData/DataAsset_HeroStartUpData.h"
#include "Components/Combat/HeroCombatComponent.h"

#include "ActionDebugHelper.h"

AActionHeroCharacter::AActionHeroCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(42.f,96.f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 200.f;
	CameraBoom->SocketOffset = FVector(0.f,55.f,65.f);
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom,USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f,500.f,0.f);
	GetCharacterMovement()->MaxWalkSpeed = 400.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;
	GetCharacterMovement()->JumpZVelocity = 500.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->SetCrouchedHalfHeight(70.f);
	JumpMaxCount = 2;
	GetCharacterMovement()->GetNavAgentPropertiesRef().bCanCrouch = true;

	HeroCombatComponent = CreateDefaultSubobject<UHeroCombatComponent>(TEXT("HeroCombatComponent"));
}

void AActionHeroCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (!CharacterStartUpData.IsNull())
	{
		if (UDataAsset_StartUpDataBase* LoadedData = CharacterStartUpData.LoadSynchronous())
		{
			LoadedData->GiveToAbilitySystemComponent(ActionAbilitySystemComponent);
		}
	}
}

void AActionHeroCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AActionHeroCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{	
	checkf(InputConfigDataAsset,TEXT("Forgot to assign a valid data asset as input config"));

	ULocalPlayer* LocalPlayer = GetController<APlayerController>()->GetLocalPlayer();

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);

	check(Subsystem);

	Subsystem->AddMappingContext(InputConfigDataAsset->DefaultMappingContext,0);

	UActionInputComponent* ActionInputComponent = CastChecked<UActionInputComponent>(PlayerInputComponent);

	ActionInputComponent->BindNativeInputAction(InputConfigDataAsset,ActionGameplayTags::InputTag_Move,ETriggerEvent::Triggered,this,&ThisClass::Input_Move);
	ActionInputComponent->BindNativeInputAction(InputConfigDataAsset,ActionGameplayTags::InputTag_Look,ETriggerEvent::Triggered,this,&ThisClass::Input_Look);
	ActionInputComponent->BindNativeInputAction(InputConfigDataAsset,ActionGameplayTags::InputTag_Jump,ETriggerEvent::Started,this,&ACharacter::Jump);
	ActionInputComponent->BindNativeInputAction(InputConfigDataAsset,ActionGameplayTags::InputTag_Jump,ETriggerEvent::Completed,this,&ACharacter::StopJumping);
	ActionInputComponent->BindNativeInputAction(InputConfigDataAsset,ActionGameplayTags::InputTag_Crouch,ETriggerEvent::Started,this,&ThisClass::Input_Crouch);
	ActionInputComponent->BindNativeInputAction(InputConfigDataAsset,ActionGameplayTags::InputTag_Crouch,ETriggerEvent::Completed,this,&ACharacter::UnCrouch, false);

	ActionInputComponent->BindAbilityInputAction(InputConfigDataAsset,this,&ThisClass::Input_AbilityInputPressed,&ThisClass::Input_AbilityInputReleased);
}

void AActionHeroCharacter::Input_Move(const FInputActionValue& InputActionValue)
{	
	const FVector2D MovementVector = InputActionValue.Get<FVector2D>();

	const FRotator MovementRotation(0.f,Controller->GetControlRotation().Yaw,0.f);

	if (MovementVector.Y != 0.f)
	{
		const FVector ForwardDirection = MovementRotation.RotateVector(FVector::ForwardVector);

		AddMovementInput(ForwardDirection,MovementVector.Y);
	}

	if (MovementVector.X != 0.f)
	{
		const FVector RightDirection = MovementRotation.RotateVector(FVector::RightVector);

		AddMovementInput(RightDirection,MovementVector.X);
	}
}

void AActionHeroCharacter::Input_Look(const FInputActionValue& InputActionValue)
{
	const FVector2D LookAxisVector = InputActionValue.Get<FVector2D>();

	if (LookAxisVector.X != 0.f)
	{
		AddControllerYawInput(LookAxisVector.X);
	}

	if (LookAxisVector.Y != 0.f)
	{
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void AActionHeroCharacter::Input_Crouch(const FInputActionValue& InputActionValue)
{
	if (!GetCharacterMovement()->IsFalling())
	{
		Crouch(false);
	}
}

void AActionHeroCharacter::Input_AbilityInputPressed(FGameplayTag InInputTag)
{
	ActionAbilitySystemComponent->OnAbilityInputPressed(InInputTag);
}

void AActionHeroCharacter::Input_AbilityInputReleased(FGameplayTag InInputTag)
{
	ActionAbilitySystemComponent->OnAbilityInputReleased(InInputTag);
}
