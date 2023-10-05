// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WidgetCore.generated.h"

class UWeaponComponent; 
class AWeaponCore;
/**
 * 
 */
UCLASS()
class SOLITUDESURVIVAL_API UWidgetCore : public UUserWidget
{
	GENERATED_BODY()
public:
	UWidgetCore(const FObjectInitializer& ObjectInitializer);
	UFUNCTION(BlueprintCallable) 
	float GetHealthProcents() const; 
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	//
	// Copy of Inventory 
	//
	TArray<AWeaponCore*> Inventory_copybycharacter;
	TArray<FString> OnDeathWords; 
public:
	void printOnDeath(); 
	UFUNCTION(BlueprintCallable)
	void onClicked(); 
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TSubclassOf<UWidgetCore> InventoryHUD; 
};
                                                                           