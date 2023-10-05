// Fill out your copyright notice in the Description page of Project Settings.


#include "Cave/PointLight_Cave.h"
#include "Components/PointLightComponent.h"
#include "Components/StaticMeshComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "Helper/Helper.h"

// Sets default values
APointLight_Cave::APointLight_Cave()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PointLight = CreateDefaultSubobject<UPointLightComponent>("PoinLight"); 
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent"); 
	SetRootComponent(Mesh); 
	PointLight->SetupAttachment(GetRootComponent());
	
	

}

// Called when the game starts or when spawned
void APointLight_Cave::BeginPlay()
{
	Super::BeginPlay();
//	Mesh->OnComponentHit.AddDynamic(this, &APointLight_Cave::OnHitFunction);
	
	

	
}

// Called every frame
void APointLight_Cave::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	float time;
	time = GetWorld()->GetTimeSeconds();
	FVector NewActorLocation = GetActorLocation();
	NewActorLocation.Z = ActorLocation.Z + FMath::Sin(time * frequency) * magnitude; 
	SetActorLocation(NewActorLocation);
	PointLight->SetWorldLocation(FVector(NewActorLocation.X, NewActorLocation.Y, NewActorLocation.Z+100));
	
}

void APointLight_Cave::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	ActorLocation = GetActorLocation();
}

void APointLight_Cave::OnHitFunction(UPrimitiveComponent OnComponentHit, UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
}

 