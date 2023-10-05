// Fill out your copyright notice in the Description page of Project Settings.


#include "test2.h"
#include "NiagaraFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "STBU_Core.h"
#include "Components/DecalComponent.h"


// Sets default values for this component's properties
Utest2::Utest2()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	
	

	// ...
}

void Utest2::FXspawn(FHitResult& Hit)

{
	TestClass = Cast<Utest2>(Utest2::StaticClass());
	if (!Hit.PhysMaterial.IsValid())return;
	UE_LOG(LogTemp, Warning, TEXT("Ye"))
	auto Effect = Default; 
	auto Phys = Hit.PhysMaterial.Get(); 
	if (EffectPropertya.Contains(Phys)) {
		Effect = EffectPropertya[Phys]; 
		UE_LOG(LogTemp, Error, TEXT("Im here"))
	}
	UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), Effect, Hit.ImpactPoint, Hit.Normal.Rotation());
	
	if (!TestClass)return; 
	
	//continue here:: //UGameplayStatics::SpawnDecalAtLocation(GetWorld(), )
	//auto EDecals = UGameplayStatics::SpawnDecalAtLocation(GetWorld(), EffectF.Decal.DecalsMaterial, EffectF.Decal.Size, Hit.ImpactPoint, Hit.ImpactNormal.Rotation());
	//if (EDecals) {
		//EDecals->SetFadeOut(0.0f, EffectF.Decal.animEnding, false); 
	//}

}


// Called when the game starts



// Called every frame


