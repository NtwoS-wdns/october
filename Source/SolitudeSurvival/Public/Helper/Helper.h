// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
class AWeaponCore;
/*
	This is an auxiliary class created specifically for the "Solitude Survival" project.
	Created by N2S 
	Here are methods that will simplify your development, use them confidently. 
	Intervention is only permissible for the purpose of addition and if you fully understand their design.	

 */
//macroses
DEFINE_LOG_CATEGORY_STATIC(LogHelper, All, All)
#define logh_m(x) UE_LOG(LogHelper, Display, TEXT(x)) 
#define logh_w(x) UE_LOG(LogHelper, Warning, TEXT(x))
#define logh_e(x) UE_LOG(LogHelper, Error, TEXT(x))
#define qcheck(x) if(!x)return // **must use ";" after**  

//




class SOLITUDESURVIVAL_API Helper
{
public:
	static void autoCast_weaponObject(AWeaponCore* Object); 
	/*
		cast WeaponCore's obeject to class which need  
	*/
	//TMap<EType, TSubclassOf<AWeaponCore>> ArrCast; 
	//
};
