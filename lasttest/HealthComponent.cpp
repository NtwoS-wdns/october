// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"
#include "GameFramework/Actor.h"






// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	
	PointerOnWorld = GetWorld(); 

	healthValue = MaxHealthValue; 
	AActor* C = GetOwner(); 
	if (C) {
		C->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::OnTakeAnyDamage);
	}
	
	// ...
	
}


bool UHealthComponent::isDead()
{
	if (healthValue <= 0.0f) { return true; }
	else { return false; }
}

void UHealthComponent::OnTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	if (isDead())return; 
	PointerOnWorld->GetTimerManager().ClearTimer(damagehastaken);
	PointerOnWorld->GetTimerManager().ClearTimer(autohealTimer);
	
	if (Damage <= 0.0f || isDead()) { return; }
	klog_w("hurt!")
	healthValue = FMath::Clamp(healthValue-Damage, 0.0f, 100.0f); 
	OnHealthPrint.Broadcast(healthValue); 
	if (isDead()) {
		OnDeath.Broadcast(); 
	}

	PointerOnWorld->GetTimerManager().SetTimer(damagehastaken, this, &UHealthComponent::autoHealFunction, 0.5f, true, 5.0f);

	
}

void UHealthComponent::autoHealFunction()
{
	if (isDead())return; 
	if (healthValue == MaxHealthValue) { PointerOnWorld->GetTimerManager().ClearTimer(autohealTimer); PointerOnWorld->GetTimerManager().ClearTimer(damagehastaken); klog_w("off+") }
	healthValue = FMath::Clamp(healthValue + 1, 0.0f, MaxHealthValue); 
	OnHealthPrint.Broadcast(healthValue); 
}

float UHealthComponent::GetHealthProcent() const
{
	return (healthValue / MaxHealthValue );
}






