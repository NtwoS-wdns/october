// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/WidgetCore.h"
#include "CharacterComponents/SLS_Character.h"
#include "CharacterComponents/HealthComponent.h"
#include "CharacterComponents/WeaponComponent.h"
#include "HUD/SLS_HUD.h"
#include "Helper/Helper.h"



UWidgetCore::UWidgetCore(const FObjectInitializer& ObjectInitializer):Super(ObjectInitializer)
{
	auto Pawn = GetOwningPlayerPawn();
	if (!Pawn)return;
	auto Player = Cast<ASLS_Character>(Pawn);
	if (!Player)return;
	auto Inventory = Player->Inventory;
	Inventory_copybycharacter = Inventory; 

	OnDeathWords.Add("Respawn"); 

}

float UWidgetCore::GetHealthProcents() const
{
	auto Pawn = GetOwningPlayerPawn(); 
	if (!Pawn)return -1;
	auto Player = Cast<ASLS_Character>(Pawn);
	if (!Player)return -1;
	auto HealthComponent = Cast<UHealthComponent>(Player->GetComponentByClass(UHealthComponent::StaticClass()));
	if (!HealthComponent)return -1; 

	return (*HealthComponent->healthValue / HealthComponent->maxHealthValue)*100; 
}

void UWidgetCore::printOnDeath()
{
	int index = rand() % OnDeathWords.Num();
	auto Player = Cast<ASLS_Character>(GetOwningPlayer()); 
	if (!Player)return;
	auto HealthComponent = Cast<UHealthComponent>(Player->GetComponentByClass(UHealthComponent::StaticClass())); 
	HealthComponent->OnDeath.AddUObject(this, &UWidgetCore::printOnDeath); 


}

void UWidgetCore::onClicked()
{
	auto HUD = Cast<ASLS_HUD>(ASLS_HUD::StaticClass()); 
	qcheck(HUD)
	HUD->AOnClicked_Status(&InventoryHUD); 
}


