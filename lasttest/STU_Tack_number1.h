// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "STU_Tack_number1.generated.h"

/**
 * 
 */
UCLASS()
class LASTTEST_API USTU_Tack_number1 : public UBTTaskNode
{
	GENERATED_BODY()
public:
	USTU_Tack_number1(); 
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override; 
	
	UPROPERTY(EditAnywhere)
	float radius = 100.0f; 
	
	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector RLocation; 

};
