// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "STBU_Core.generated.h"

/**
 * 
 */
class UMaterialInterface; 

UCLASS()
class LASTTEST_API USTBU_Core : public UObject
{
	GENERATED_BODY()
	
};


USTRUCT(BlueprintType)
struct FDecalStruct {

	GENERATED_USTRUCT_BODY()
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "DecalsANDNiagara")
	UMaterialInterface* DecalsMaterial; 
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "DecalsANDNiagara")
	FVector Size = { 10.0f, 10.0f, 10.0f };
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "DecalsANDNiagara")
	float quicLifeSpan = 5.0f; 
	//UPROPERTY(EditAnywhere)
	float animEnding = 0.7f; // 7 milliseconds



};


USTRUCT(BlueprintType)
struct FimpactEffect {
	GENERATED_USTRUCT_BODY()

	
	FDecalStruct Decal; 

};
