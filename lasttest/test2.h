// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "test2.generated.h"

class UNiagaraFunctionLibrary;
class UNiagaraSystem;
class UPhysicalMaterial; 
class UDecalComponent; 
struct FimpactEffect;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LASTTEST_API Utest2 : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	Utest2();

protected:
	// Called when the game starts
	//virtual void BeginPlay() override;

public:	
	// Called every frame
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void FXspawn(FHitResult& Hit); 
public: 
	UPROPERTY(EditAnywhere)
	UNiagaraSystem* Default; 

	UPROPERTY(EditAnywhere)
	//FimpactEffect EffectF; 

	Utest2* TestClass; 

	UPROPERTY(EditAnywhere) 
	TMap<UPhysicalMaterial*, UNiagaraSystem*> EffectPropertya;
};
