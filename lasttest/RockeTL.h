// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RockeTL.generated.h"

class USphereComponent; 
class UProjectileMovementComponent;
class UWeaponComponent; 
class AKnife; 


UCLASS()
class LASTTEST_API ARockeTL : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARockeTL();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	FVector ShotD;

	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere)
	USphereComponent* SphereComponent;
	void ShotDirection(FVector& Direction) { ShotD = Direction; }
	UPROPERTY(EditAnywhere)
	UProjectileMovementComponent* MovementComponent; 
	AKnife* Weapon1 ;
	UFUNCTION()
	void damagetoObject(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	
};
