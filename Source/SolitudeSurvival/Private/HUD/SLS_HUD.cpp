// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/SLS_HUD.h"
#include "HUD/WidgetCore.h"
#include "Helper/Helper.h"

void ASLS_HUD::DrawHUD()
{
	Super::DrawHUD(); 
}

void ASLS_HUD::BeginPlay()
{
	Super::BeginPlay();
	auto Widget1 = CreateWidget<UWidgetCore>(GetWorld(), Widget); 
	qcheck(Widget1);
	Widget1->AddToViewport(); 
}

void ASLS_HUD::AOnClicked_Status(TSubclassOf<UWidgetCore>* otherWidget) 
{
	auto Widgetpointer = CreateWidget<UWidgetCore>(GetWorld(), *otherWidget);
	qcheck(Widgetpointer);
	Widgetpointer->AddToViewport(); 
}

