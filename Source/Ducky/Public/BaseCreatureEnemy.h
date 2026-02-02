// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCreatureEnemy.generated.h"

//class AAIController;
//class ABaseMagicCharacter;

UCLASS()
class DUCKY_API ABaseCreatureEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCreatureEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
<<<<<<< Updated upstream
	//UPROPERTY(EditAnywhere)
	//ABaseMagicCharacter* PlayerRef = nullptr;
	
	//UPROPERTY(EditAnywhere)
	//AAIController* AI;
=======
	UPROPERTY(EditAnywhere)
	ABaseMagicCharacter* PlayerRef = nullptr;
	
	UPROPERTY(BlueprintReadWrite)
	float Health;
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
