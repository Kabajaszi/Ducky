// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseWeapon.generated.h"

UCLASS()
class DUCKY_API ABaseWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintCallable)
	void WeaponShoot();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Damage;
	UFUNCTION(BlueprintPure)
	float CalculateDamage(float _Damage, float multiplier);
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* WeaponMesh;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
