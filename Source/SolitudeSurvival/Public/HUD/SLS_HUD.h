// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SLS_HUD.generated.h"


class UWidgetCore; 


/**
 * 
 */
UCLASS()
class SOLITUDESURVIVAL_API ASLS_HUD : public AHUD
{
	GENERATED_BODY()
public:
	virtual void DrawHUD() override; 
	virtual void BeginPlay() override; 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UWidgetCore> Widget;
	void AOnClicked_Status(TSubclassOf<UWidgetCore>* otherWidget);
};
