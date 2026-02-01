#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseMagicCharacter.generated.h"

//forward declarations
class UCameraComponent;
class USpringArmComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

UCLASS()
class DUCKY_API ABaseMagicCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseMagicCharacter();
	
	void ValidateSetup(const FString &Value)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT("Issue in cpp with: %s"),*Value));
	}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	
	void Shoot();
	void Move(const FInputActionValue &Value);
	void Look(const FInputActionValue &Value);
	
	UPROPERTY(EditAnywhere)
	UChildActorComponent* Weapon;
	
	UPROPERTY(EditAnywhere)
	UCameraComponent* Camera;
	
	UPROPERTY(EditAnywhere)
	USpringArmComponent* CameraBoom;
	
	UPROPERTY(EditAnywhere)
	UInputMappingContext* MappingInput;

	UPROPERTY(EditAnywhere)
	UInputAction* MoveInput;
	
	UPROPERTY(EditAnywhere)
	UInputAction* JumpInput;
	
	UPROPERTY(EditAnywhere)
	UInputAction* LookInput;
	
	
	
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
