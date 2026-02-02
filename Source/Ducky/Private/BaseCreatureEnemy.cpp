// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCreatureEnemy.h"
#include "BaseMagicCharacter.h"

// Sets default values
ABaseCreatureEnemy::ABaseCreatureEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
<<<<<<< Updated upstream

=======
	
	GetCharacterMovement()->bOrientRotationToMovement = true;
	bUseControllerRotationYaw = false;
	
	GetCharacterMovement()->MaxWalkSpeed = 200.f;
	
	
<<<<<<< Updated upstream
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
=======
>>>>>>> Stashed changes
}

// Called when the game starts or when spawned
void ABaseCreatureEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	//PlayerRef = Cast<ABaseMagicCharacter>(UGameplayStatics::GetPlayerCharacter(this,0));
	
}

// Called every frame
void ABaseCreatureEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	//AI = Cast<AAIController>(GetController());
	//if (!AI) return;
	//dokonczyc cpp ->
}

// Called to bind functionality to input
void ABaseCreatureEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

