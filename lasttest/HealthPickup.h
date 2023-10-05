// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HealthPickup.generated.h"

class USphereComponent; 
class Acharacter_prot; 


UCLASS()
class LASTTEST_API AHealthPickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHealthPickup();
	void PickUp(ACharacter* Actor); 
	//Notify Actor BeginOverlap
	//UFUNCTION()
	//void NotifyActorBeginOverlap(AActor* OnActorBeginOverlap, AActor* OverlappedActor, AActor* OtherActor);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere)
	USphereComponent* SphereComponent; 

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMesh;
public:
	UPROPERTY(EditAnywhere)
	float comeBackHealth = 35.0f; 


};
