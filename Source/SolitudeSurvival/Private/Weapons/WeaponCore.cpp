// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/WeaponCore.h"
#include "Net/UnrealNetwork.h"

// Sets default values
AWeaponCore::AWeaponCore()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = true;
}

// Called every frame







