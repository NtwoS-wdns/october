// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Knife.generated.h"



class USkeletalMeshComponent; 
class Acharacter_prot; 
UCLASS()
class LASTTEST_API AKnife : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AKnife();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* BaseMesh;
	 
	ACharacter* CharacterCom = nullptr; 
	void kickWithKnife(); 

	FTransform SocketTransform; 

	UWorld* PointerOnWorldObject = GetWorld(); 

	
	


};
