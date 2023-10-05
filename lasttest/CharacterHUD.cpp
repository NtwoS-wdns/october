// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterHUD.h"
#include "Engine/Canvas.h"
#include "MyUserWidget.h"
#include "character_prot.h"
#include "WeaponComponent.h"


void ACharacterHUD::DrawHUD()
{
	Super::DrawHUD(); 
	drawp();
}

void ACharacterHUD::drawp()
{
	int32 SizeX = Canvas->SizeX; 
	int32 SizeY = Canvas->SizeY;
	TInterval<float> Centre(SizeX*0.5, SizeY*0.5); 
	auto Player = GetOwningPawn(); 
	if (!Player)return; 

	auto WeaponCom = Player->GetComponentByClass(UWeaponComponent::StaticClass()); 
	if (!WeaponCom)return;
	auto WeaponComponent = Cast<UWeaponComponent>(WeaponCom); 
	if (!WeaponCom)return;
	//wwwwwwcheck(WeaponCom)
	if (!WeaponCom)return;
	if (WeaponComponent->isE) {
		auto WidgetAim = CreateWidget<UUserWidget>(GetWorld(), aim); 
		if (WidgetAim) {
			WidgetAim->AddToViewport();
		}
	}
	//DrawLine(Centre.Min - 10, Centre.Max, Centre.Min + 10, Centre.Max, FLinearColor::Green, 2.0f); 
	//DrawLine(Centre.Min, Centre.Max - 10, Centre.Min, Centre.Max + 10, FLinearColor::Green, 2.0f);
}

void ACharacterHUD::BeginPlay()
{
	Super::BeginPlay(); 
	HealthWidget = CreateWidget<UUserWidget>(GetWorld(), widget);
	auto Hek = Cast<UUserWidget>(HealthWidget); 
	
	if (HealthWidget) {
		HealthWidget->AddToViewport(1); 
	}



	auto buttonWidget = CreateWidget<UUserWidget>(GetWorld(), button); 
	if (buttonWidget) {
		buttonWidget->AddToViewport(2); 
	}



}
