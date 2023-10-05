// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthPickup.h"
#include "Components/SphereComponent.h"
#include "character_prot.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/Actor.h"


// Sets default values
AHealthPickup::AHealthPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SphereComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent"); 
	SphereComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap); 
	SphereComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly); 
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh"); 
	


}

void AHealthPickup::PickUp(ACharacter* Actor)
{
	auto PlayerCom = Cast<Acharacter_prot>(Actor); 
}



// Called when the game starts or when spawned
void AHealthPickup::BeginPlay()
{
	Super::BeginPlay();
	//OnActorBeginOverlap.AddDynamic(this, &AHealthPickup::NotifyActorBeginOverlap);
	
}

// Called every frame
void AHealthPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

