// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PointLight_Cave.generated.h"

class UPointLightComponent; 
class USceneComponent; 


UCLASS()
class SOLITUDESURVIVAL_API APointLight_Cave : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APointLight_Cave();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void PostInitializeComponents() override; 
	
public:
	FVector ActorLocation; 
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Light")
	UPointLightComponent* PointLight;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh; 
	void OnHitFunction(UPrimitiveComponent OnComponentHit, UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

public:
	UPROPERTY(EditAnywhere, Category="MOVE")
	float magnitude = 50.f; 
	UPROPERTY(EditAnywhere, Category="MOVE")
	float frequency = 1.f; 

};
