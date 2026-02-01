// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCreatureEnemy.h"
#include "AIController.h"
#include "BaseMagicCharacter.h"
#include "NavigationSystem.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Navigation/PathFollowingComponent.h"

// Sets default values
ABaseCreatureEnemy::ABaseCreatureEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	GetCharacterMovement()->bOrientRotationToMovement = true;
	bUseControllerRotationYaw = false;
	
	GetCharacterMovement()->MaxWalkSpeed = 200.f;

}

// Called when the game starts or when spawned
void ABaseCreatureEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	PlayerRef = Cast<ABaseMagicCharacter>(UGameplayStatics::GetPlayerCharacter(this,0));
	
}

// Called every frame
void ABaseCreatureEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	AAIController* AI = Cast<AAIController>(GetController());
	if (!AI) return;
	
	FAIMoveRequest MoveReq;
	MoveReq.SetGoalActor(PlayerRef);
	MoveReq.SetAcceptanceRadius(200.f);
	
	FNavPathSharedPtr NavPath;
	
	AI->MoveTo(MoveReq, &NavPath);
}

// Called to bind functionality to input
void ABaseCreatureEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

