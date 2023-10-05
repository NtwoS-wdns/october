// Fill out your copyright notice in the Description page of Project Settings.


#include "Helper/Helper.h"
#include "Weapons/WeaponCore.h"
#include "Weapons/WP_Knife.h"
#include "GameFramework/Actor.h"
#include "Engine/Engine.h"






void Helper::autoCast_weaponObject(AWeaponCore* Object)
{
	qcheck(Object);
	switch (Object->WeaponData.type) {
	case EType::KNF: {
		Object = Cast<AWP_Knife>(Object);
	};break;
	default: break;
	}


	
	
	
}

