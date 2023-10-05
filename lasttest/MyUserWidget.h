// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyUserWidget.generated.h"

/**
 * 
 */

class Acharacter_prot; 

UCLASS()
class LASTTEST_API UMyUserWidget : public UUserWidget
{
	GENERATED_BODY()
	UFUNCTION(BlueprintCallable)
	float GetHealthPrecent1 () const;

public:


	TSubclassOf<Acharacter_prot*> Character; 

	UFUNCTION(BlueprintCallable)
	Acharacter_prot* returnCharacter();

	
};
