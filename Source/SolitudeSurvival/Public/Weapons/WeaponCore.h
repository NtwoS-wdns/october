// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponCore.generated.h"

 

/*
	
	types:
	launchers - LUC
	riffles - RIL
	tools - TOS
	knife - KNF


*/


UENUM()

enum class EType : uint8 {
	LUC,
	RIL, 
	TOS,
	KNF
};


USTRUCT()

struct FWeaponData {
	GENERATED_USTRUCT_BODY()
public:
	float damage; 
	bool isGun; 
	EType type; 
};










UCLASS()
class SOLITUDESURVIVAL_API AWeaponCore : public AActor
{
	GENERATED_BODY()
public:
	 FWeaponData WeaponData;
	
public:	
	// Sets default values for this actor's properties
	AWeaponCore();
public:
	//virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const override;

};


