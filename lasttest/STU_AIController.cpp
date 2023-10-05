// Fill out your copyright notice in the Description page of Project Settings.


#include "STU_AIController.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "RAICharacter.h"
#include "Perception/AISense_sight.h"
#include "EyeSense.h"






/*

void ASTU_AIController::OnPossess(APawn* InPawn)
{
	auto STJ = Cast<ARAICharacter>(InPawn); 
	if (STJ) {
		RunBehaviorTree(STJ->Tree); 
	}
	
}
*/

ASTU_AIController::ASTU_AIController()
{
	AIeSense = CreateDefaultSubobject<UEyeSense>("AISense"); 
	SetPerceptionComponent(*AIeSense); 


}

void ASTU_AIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto Atemp = AIeSense->GetSight(); 
	SetFocus(Atemp); 
}


