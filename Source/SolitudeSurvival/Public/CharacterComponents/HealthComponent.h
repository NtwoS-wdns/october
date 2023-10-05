// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnDeath)


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SOLITUDESURVIVAL_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	float maxHealthValue = 100.0f; 
private:
	UPROPERTY(replicated)
	float healthReplication; 
	float privateHealthValue; 
public:
	float* healthValue; 
	float* getHealth() const; 
	UFUNCTION()
	void takeDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);
	bool isDead() { return healthValue <= 0; }
	FOnDeath OnDeath; 
public:
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;
	
		
};
