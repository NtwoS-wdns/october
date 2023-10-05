// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "protController.generated.h"

class Acharacter_prot;

/**
 * 
 */
UCLASS()
class LASTTEST_API AprotController : public APlayerController
{
	GENERATED_BODY()

	void possesc(); 
	virtual void SetupInputComponent() override; 
	int numTemp = 0; 
	int returnNumTemp() { return numTemp;  }
public:
	TArray<AActor*> arrayT;
	ACharacter* temp;
};
