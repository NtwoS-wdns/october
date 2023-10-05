// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WeaponComponent.generated.h"

class UWeaponComponent; 
class AKnife;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LASTTEST_API UWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWeaponComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	void spawnWeapon();
	ACharacter* Character;
	UPROPERTY(EditAnywhere)
	TSubclassOf<AKnife> knifes; 
	void fireGeneral();
	AKnife* Weapon;
	UPROPERTY(EditAnywhere)
	bool isE = false;
};
