// Fill out your copyright notice in the Description page of Project Settings.


#include "RAICharacter.h"
#include "STU_AIController.h"
#include "BehaviorTree/BehaviorTree.h" 
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EyeSense.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISense_sight.h"


ARAICharacter::ARAICharacter(){
	
	//AIControllerClass = ASTU_AIController::StaticClass(); 
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned; 
	bUseControllerRotationYaw = false;
	if (GetCharacterMovement()) {
		GetCharacterMovement()->bUseControllerDesiredRotation = true;
		GetCharacterMovement()->RotationRate = FRotator(0.0f, 200.0f, 0.0f);
	}
	

	
}

