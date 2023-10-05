// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "STU_AIController.generated.h"

/**
 * 
 */

class UEyeSense; 

UCLASS()
class LASTTEST_API ASTU_AIController : public AAIController
{
	GENERATED_BODY()
	//ASTU_AIController(FObjectInitializer& ObjectInit); 

public:
	ASTU_AIController(); 


	//virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, Category = "AI")
	UEyeSense* AIeSense;
	virtual void Tick(float DeltaTime) override; 
	
protected:
	//virtual void OnPossess(APawn* InPawn) override;
	
};
