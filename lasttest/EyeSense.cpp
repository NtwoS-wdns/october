// Fill out your copyright notice in the Description page of Project Settings.


#include "EyeSense.h"
#include "Perception/AISense_Sight.h"
#include "AIController.h"


AActor* UEyeSense::GetSight()
{
	TArray<AActor*> ArrayT; 

	GetCurrentlyPerceivedActors(UAISense_Sight::StaticClass(), ArrayT); 
	if (ArrayT.Num() == 0)return nullptr; 

	auto Controller = Cast<AAIController>(GetOwner()); 

	auto Pawn = Controller->GetPawn(); 

	double bestD = FLT_MAX; 
	AActor* BestPawn = nullptr; 

	for (auto PercivActor : ArrayT) {
		auto CurrentDistance = ((PercivActor->GetActorLocation() - Pawn->GetActorLocation()).Size()); 
		if (CurrentDistance < bestD) {
			bestD = CurrentDistance; 
			BestPawn = PercivActor; 
		}
	}
	return BestPawn; 
}
