// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/WeaponCore.h"
#include "WP_Knife.generated.h"

/**
 * 
 */
UCLASS()
class SOLITUDESURVIVAL_API AWP_Knife : public AWeaponCore
{
	GENERATED_BODY()
public:
	AWP_Knife(); 
	UPROPERTY(EditAnywhere)
	USkeletalMeshComponent* MeshComponent; 
	FWeaponData WeaponData;
public:
	UCollisionProfile* CollisionProfile; 
	
	
};
