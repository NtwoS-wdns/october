// Fill out your copyright notice in the Description page of Project Settings.


#include "Knife.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "WeaponComponent.h"
#include "GameFramework/Character.h"
#include "character_prot.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "Engine/DamageEvents.h"

// Sets default values
AKnife::AKnife()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("base");

}

// Called when the game starts or when spawned
void AKnife::BeginPlay()
{
	Super::BeginPlay();
	
	//ACharacter* CharacterPointer = Cast<ACharacter>(GetOwner());
	//AController* CharacterController = CharacterPointer->GetController(); 
	
	//CharacterController->GetPlayerViewPoint()
	SocketTransform = BaseMesh->GetSocketTransform("FS");
	
}

void AKnife::kickWithKnife()
{
	

	ACharacter* CharacterPointer = Cast<ACharacter>(GetOwner()); 
	AController* CharacterController = CharacterPointer->GetController(); 
	FVector StartDot; 
	FRotator ViewPointRotator; 

	

	CharacterController->GetPlayerViewPoint(StartDot, ViewPointRotator);
	FVector EndDot = ViewPointRotator.Vector() * 10; 

	if (!PointerOnWorldObject)return; 
	FHitResult HitR;

	PointerOnWorldObject->LineTraceSingleByChannel(HitR, StartDot, EndDot, ECollisionChannel::ECC_Visibility);
	if (HitR.bBlockingHit) {
		DrawDebugLine(GetWorld(), SocketTransform.GetLocation(), HitR.ImpactPoint, FColor::Cyan, false, 10.0f);
		//TakeDamage(5.0f, FDamageEvent{}, CharacterController, this); 
	}
}







// Called every frame

