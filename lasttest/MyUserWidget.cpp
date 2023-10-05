// Fill out your copyright notice in the Description page of Project Settings.


#include "MyUserWidget.h"
#include "HealthComponent.h"
#include "character_prot.h"


//#define returnPlayerComponent(PlayerClassPointer, x) PlayerClassPointer->GetComponentByClass(x)  

float UMyUserWidget::GetHealthPrecent1() const
{
	auto Player = GetOwningPlayerPawn(); 
	//check(Player)
	if (!Player)return 0.0f; 
	

	auto Component = Player->GetComponentByClass(UHealthComponent::StaticClass());
	auto HealthComponentObject = Cast<UHealthComponent>(Component); 
	//check(HealthComponentObject)
	if (!HealthComponentObject) return 0.0f; 
	return HealthComponentObject->GetHealthProcent();
}

Acharacter_prot* UMyUserWidget::returnCharacter()
{
	Acharacter_prot* Player = Cast<Acharacter_prot>(GetOwningPlayerPawn()); 
	if (!Player)return nullptr; 




	return Player;
}






