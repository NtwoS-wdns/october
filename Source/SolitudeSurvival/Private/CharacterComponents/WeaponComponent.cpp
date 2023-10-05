// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterComponents/WeaponComponent.h"
#include "Weapons/WeaponCore.h"
#include "Kismet/GameplayStatics.h"
#include "CharacterComponents/SLS_Character.h"



// Sets default values for this component's properties
UWeaponComponent::UWeaponComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UWeaponComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UWeaponComponent::spawnWeapon(FTransform* socketTransform, FName* socketName)
{
	if (!Weapon_Core) { return; }
	auto Owner = Cast<ASLS_Character>(GetOwner());
	if (!Owner) { return; }
	ESpawnActorCollisionHandlingMethod Spawn(ESpawnActorCollisionHandlingMethod::AlwaysSpawn);
	auto Weapon = UGameplayStatics::BeginDeferredActorSpawnFromClass(GetWorld(), Weapon_Core, *socketTransform, Spawn, GetOwner()); 
	UGameplayStatics::FinishSpawningActor(Weapon, *socketTransform);
	FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, false);

	Weapon->AttachToComponent(Cast<USceneComponent>(Owner), AttachmentRules, *socketName);
}


// Called every frame
