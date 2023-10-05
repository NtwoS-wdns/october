// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "character_prot.h"
#include "RAICharacter.generated.h"

/**
* 
* 

 * 
 */

class UBehaviorTree;



UCLASS()
class LASTTEST_API ARAICharacter : public Acharacter_prot
{
	GENERATED_BODY()
public:
	ARAICharacter(); 
public:
	//virtual void BeginPlay() override; 
	UPROPERTY(EditAnywhere)
	UBehaviorTree* Tree; 
	//virtual void Possess(APawn* InPawn) override;
	

	
};
