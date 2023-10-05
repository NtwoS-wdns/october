// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "character_prot.generated.h"

class UCameraComponent;
class USpringArmComponent; 
class UCharacterMovementComponent;
class UHealthComponent; 
class UTextRenderComponent; 
class AKnife;
class UWeaponComponent;
class AprotController;
class UCapsuleComponent; 
class ARockeTL;
class UProjectileMovementComponent;
class Utest2;


UENUM()

enum class EWeapon :uint8 {
	Riffle,
	Launcher 
};



USTRUCT()
struct FWeaponData {
	GENERATED_USTRUCT_BODY()
public:
	int32 amounth; 
	int32 magazine; 
	int32 maxValueOfMagazine = 7; 
	int32 maxValueOfAmount  = 130; 
	int32 returnAmounth() { return amounth; }
	EWeapon Wepon; 
};

UENUM()

enum class ECameraStatus :uint8 {
	FirstCamera,
	ThirdCamera,
};



UCLASS()
class LASTTEST_API Acharacter_prot : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	Acharacter_prot();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
public:
	FWeaponData WeaponRiffleData; 
	UPROPERTY(EditAnywhere)
	UCameraComponent* FirstCamera;
	UCameraComponent* ThirdCamera;
	ECameraStatus CameraStatus = ECameraStatus::FirstCamera; 
	UCharacterMovementComponent* A; 
public:
	UPROPERTY(EditAnywhere)
	USpringArmComponent* Arm; 

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void movef(float amount);
	void moverl(float amount); 
	void lookUP(float amount); 
	void lookRL(float amount);
	void camerachange(); 
public:
	//HEALTH COMPONENT
	UHealthComponent* HealthComponent; 
	UPROPERTY(EditAnywhere)
	UTextRenderComponent* HealthTextRender; 
	void printhealth(float health);
	void onDeath(); 
	void speedup();
	void speedstop();
	UFUNCTION()
	void falldamage(const FHitResult& Param);
	float FallVelocity; 
	UFUNCTION(BlueprintCallable)
	bool returnSit() { return sitdowm; };
	bool sitdowm = false;



	void changeSit();
	void changeSitF();
	UFUNCTION(BlueprintCallable)
	double fg16(float direction) { if (direction > 90) { return (direction * (-1)); } else { return direction; } }
	//
	
	AKnife* knifes;

	UPROPERTY(EditAnywhere)
	UWeaponComponent* Weapon; 
	UFUNCTION(BlueprintCallable)
	void fireCharacterPoint();
	UPROPERTY(EditAnywhere)
	TSubclassOf<ARockeTL> RocketL; 
public:
	UPROPERTY(EditAnywhere)
	UProjectileMovementComponent* MovementComponent; 
public:
	ARockeTL* Rocket; 
	bool isEuqet = false; 
public:
	UPROPERTY(EditAnywhere)
	Utest2* effect; 
	//

	//

	


	
};
