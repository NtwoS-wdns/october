// Fill out your copyright notice in the Description page of Project Settings.


#include "protController.h"
#include "character_prot.h"
#include "Kismet/GamePlayStatics.h"


void AprotController::possesc()
{


	UGameplayStatics::GetAllActorsOfClass(GetWorld(), Acharacter_prot::StaticClass(), arrayT);
	temp = Cast<ACharacter>(arrayT[numTemp]);
	numTemp = (numTemp + 1) % arrayT.Num();
	Possess(temp);
}

void AprotController::SetupInputComponent()
{
	Super::SetupInputComponent(); 
	InputComponent->BindAction("G", IE_Pressed, this, &AprotController::possesc); 

}
