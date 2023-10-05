// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/WP_Knife.h"
#include "Components/SkeletalMeshComponent.h"

AWP_Knife::AWP_Knife()
{
	MeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>("MeshComponent"); 
	MeshComponent->SetupAttachment(GetRootComponent()); 
	

	WeaponData.isGun = false;
	WeaponData.damage = 30.f;
	WeaponData.type = EType::KNF;

}

