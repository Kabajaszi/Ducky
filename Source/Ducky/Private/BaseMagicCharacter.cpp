#include "BaseMagicCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "Engine/Engine.h"

// Constructor
ABaseMagicCharacter::ABaseMagicCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Weapon / SocketWeapon
	Weapon = CreateDefaultSubobject<UChildActorComponent>(TEXT("Weapon"));
	Weapon->SetupAttachment(GetMesh(), TEXT("WeaponSocket"));
	
	// Camera / SpringArm
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraBoom);
}

// Called when the game starts or when spawned
void ABaseMagicCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	// Get PlayerController
	APlayerController* PC = Cast<APlayerController>(GetController());
	if(!PC) ValidateSetup(TEXT("PlayerController"));

	// Get Subsystem of the Local Player
	UEnhancedInputLocalPlayerSubsystem* Subsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(
			PC->GetLocalPlayer());

	if (!Subsystem) ValidateSetup(TEXT("Subsystem"));
	if (!InputMapping) ValidateSetup(TEXT("InputMapping"));

	Subsystem->AddMappingContext(InputMapping, 0);
	
}

void ABaseMagicCharacter::Shoot()
{
	
}

void ABaseMagicCharacter::Move(const FInputActionValue& Value)
{
	FVector2D Input  = Value.Get<FVector2D>();
	
	if (Controller == nullptr) ValidateSetup(TEXT("Controller"));
	
	// Adding Movement Inputs
	AddMovementInput(GetActorForwardVector(), Input.Y);
	AddMovementInput(GetActorRightVector(), Input.X);
}



// Called every frame
void ABaseMagicCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ABaseMagicCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if(!EIC) return;
	
	EIC->BindAction(IA_Move, ETriggerEvent::Triggered, this, &ABaseMagicCharacter::Move);
	

}

