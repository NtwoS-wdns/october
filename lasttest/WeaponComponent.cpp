// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponComponent.h"
#include "character_prot.h"
#include "GameFramework/Character.h"
#include "Components/StaticMeshComponent.h"
#include "Knife.h"
#include "RockeTL.h"

//
#define klog_e(x)  UE_LOG(LogTemp, Error , TEXT(x))
#define klog_w(x)  UE_LOG(LogTemp, Warning, TEXT(x))
#define klog_d(x)  UE_LOG(LogTemp, Dislplay, TEXT(x))



//

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
	
	spawnWeapon(); 

	// ...
	
}

void UWeaponComponent::spawnWeapon()
{
	
	Character = Cast<ACharacter>(GetOwner()); 
	if (!Character)return;
	Weapon = GetWorld()->SpawnActor<AKnife>(knifes);
	if (!Weapon)return; 

	FAttachmentTransformRules Attr(EAttachmentRule::SnapToTarget, false);
	

	Weapon->AttachToComponent(Character->GetMesh(), Attr, "KnifeSocket");
	if (!Weapon)return;
	Weapon->SetOwner(Character); 
	isE = true; 

}

void UWeaponComponent::fireGeneral()
{
	
	Acharacter_prot* PointerOnCharacter = Cast<Acharacter_prot>(Character);
	if (!PointerOnCharacter)return;
	PointerOnCharacter->fireCharacterPoint(); 
	Weapon->kickWithKnife();
	UE_LOG(LogTemp, Error, TEXT("Bind")) 
	
}



