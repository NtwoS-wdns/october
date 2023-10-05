// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Perception/AIPerceptionComponent.h"
#include "EyeSense.generated.h"

/**
 * 
 */


UCLASS()
class LASTTEST_API UEyeSense : public UAIPerceptionComponent
{
	GENERATED_BODY()
public:
	AActor* GetSight(); 

	
};
