// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "CharacterHUD.generated.h"

/**
 * 
 */
UCLASS()
class LASTTEST_API ACharacterHUD : public AHUD
{
	GENERATED_BODY()
	virtual void DrawHUD() override; 
	void drawp(); 
	virtual void BeginPlay() override; 
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> widget; 
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> aim; 
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> button;


	UUserWidget* HealthWidget; 
};
