// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

#define klog_w(x) UE_LOG(LogTemp, Warning, TEXT(x)); 
DECLARE_MULTICAST_DELEGATE_OneParam(FPrintHealth, float)
DECLARE_MULTICAST_DELEGATE(FDied)

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LASTTEST_API UHealthComponent : public UActorComponent
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
public:
	FDied OnDeath; 
	FPrintHealth OnHealthPrint; 
public:
	float healthValue;
	float MaxHealthValue = 100.0f; 
	float gethealth() { return healthValue; };
	bool isDead(); 
	UFUNCTION()
	void OnTakeAnyDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser); 
 
public:
	UWorld* PointerOnWorld; 
	bool autoheal = true;
	float pauseForautoheal = 5.0f;
	float timeRate = 0.5f; 
	FTimerHandle damagehastaken; 
	FTimerHandle autohealTimer; 
	void autoHealFunction(); 
	void movetoAutoHeal();
	UFUNCTION(BlueprintCallable)
	float GetHealthProcent() const; 
};
