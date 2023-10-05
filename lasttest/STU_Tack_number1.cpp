// Fill out your copyright notice in the Description page of Project Settings.


#include "STU_Tack_number1.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "NavigationSystem.h"


USTU_Tack_number1::USTU_Tack_number1()
{
	NodeName = "Find New Location"; 

}

EBTNodeResult::Type USTU_Tack_number1::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto Controller = OwnerComp.GetAIOwner(); 
	if (!Controller) { return EBTNodeResult::Failed; UE_LOG(LogTemp, Error, TEXT("1"))}
	auto Pawn = Controller->GetPawn(); 
	if (!Pawn) { return EBTNodeResult::Failed; UE_LOG(LogTemp, Error, TEXT("2"))}
	auto BlackboardComponent = OwnerComp.GetBlackboardComponent(); 
	if (!BlackboardComponent) { return EBTNodeResult::Failed; UE_LOG(LogTemp, Error, TEXT("3")) }
	auto Nav = UNavigationSystemV1::GetCurrent(Pawn); 
	if (!Nav) { return EBTNodeResult::Failed; UE_LOG(LogTemp, Error, TEXT("5")) }
	FNavLocation FNav; 
	auto Found = Nav->GetRandomReachablePointInRadius(Pawn->GetActorLocation(), radius, FNav); 
	if (!Found) { return EBTNodeResult::Failed; UE_LOG(LogTemp, Error, TEXT("6")) }
	
	BlackboardComponent->SetValueAsVector(RLocation.SelectedKeyName, FNav.Location); 
	return EBTNodeResult::Succeeded; 





}
