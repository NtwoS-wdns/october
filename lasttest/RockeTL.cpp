// Fill out your copyright notice in the Description page of Project Settings.


#include "RockeTL.h"
#include "Components/SphereComponent.h"
#include "Kismet/GamePlayStatics.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "GameFramework/Actor.h"
#include "WeaponComponent.h"
#include "GameFramework/Character.h"
#include "Knife.h"

// Sets default values
ARockeTL::ARockeTL()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SphereComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
	MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("Movem");

	SphereComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly); 
	SphereComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block); 
	SphereComponent->IgnoreActorWhenMoving(GetOwner(), true); 
	SphereComponent->IgnoreActorWhenMoving(Cast<AActor>(Weapon1), true); 
	//SphereComponent->IgnoreActorWhenMoving(GetOwner()->GetOwner(), true); 
	
	
	
	
}

// Called when the game starts or when spawned
void ARockeTL::BeginPlay()
{
	Super::BeginPlay();
	SphereComponent->InitSphereRadius(5.0); 
	MovementComponent->Velocity = ShotD * MovementComponent->InitialSpeed;
	SphereComponent->IgnoreActorWhenMoving(GetOwner(), true);
	SphereComponent->OnComponentHit.AddDynamic(this, &ARockeTL::damagetoObject); 
}

// Called every frame
void ARockeTL::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FHitResult WE;
	
}



void ARockeTL::damagetoObject(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	ACharacter* C = Cast<ACharacter>(GetOwner()); 
	

	UGameplayStatics::ApplyRadialDamage(GetWorld(), 100.0f, Hit.ImpactPoint, 750.0f, nullptr, {}, this, C->GetController(), false, ECollisionChannel::ECC_Visibility);
	DrawDebugSphere(GetWorld(), Hit.ImpactPoint, 750.0f, 10, FColor::Emerald, false, 5.0f);
	Destroy();

}

