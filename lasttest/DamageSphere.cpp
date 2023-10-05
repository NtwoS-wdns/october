// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageSphere.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GamePlayStatics.h"

// Sets default values
ADamageSphere::ADamageSphere()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SceneComponent = CreateDefaultSubobject<USceneComponent>("SceneC"); 
	SetRootComponent(SceneComponent); 
}

// Called when the game starts or when spawned
void ADamageSphere::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADamageSphere::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DrawDebugSphere(GetWorld(), GetActorLocation(), radius, 5, FColor::Cyan); 
	UGameplayStatics::ApplyRadialDamage(GetWorld(), 5.0f, GetActorLocation(), radius, nullptr, {}, this, nullptr, false); 

}

