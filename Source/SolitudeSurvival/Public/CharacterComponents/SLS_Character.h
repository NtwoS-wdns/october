// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SLS_Character.generated.h"

//??????????????? ??????????
class UCameraComponent;
class USpringArmComponent; 
class UCharacterMovementComponent;
class UHealthComponent;
class UWeaponComponent; 
class UBuildComponent; 
class AWeaponCore;

//



UCLASS()
class SOLITUDESURVIVAL_API ASLS_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASLS_Character();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


//=================================================================================================
public: 

	void moveForward(float amount); // ??????? ???????? ????? 
	void moveSide(float amount); // ??????? ???????? ? ???????
	void lookY(float amount); //??????? ???????? ?????? ?????
	void lookR(float amount); //??????? ???????? ?????? ? ???????
	void Jump_custom(); 
	
	void sitDown(); 
	void stendUp(); 
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Camera")
	UCameraComponent* FirstCamera; 
	void firstCameraAttachment(); // ???? ?????? ? ??????
	USkeletalMeshComponent* CharacterSkeletal; // ?????? ?????????
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Camera")
	USpringArmComponent* SpringArm; 
	UCharacterMovementComponent* MovementComponent; 
private:
	bool Default_boolean = false; 

	
	float MWSpeed = 700.0f;
	float SUSpeed = 1100.0f; 
	bool isSitting = Default_boolean; 
	bool isRun; 

public:
	float currentSpeed; 
public:
//===================================================================================================
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Health")
	UHealthComponent* HealthComponent; 
	float* CurrentHealth; 
	//UPROPERTY(rl]eplicated)
	//ASLS_Character* Character = Cast<ASLS_Character>(ASLS_Character::StaticClass());
	
public:
	void OnDeath(); 
	ENetRole Role;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Weapon")
	UWeaponComponent* WeaponComponent; 
	UBuildComponent* BuildComponent; 

public:
	UFUNCTION(Server, unreliable)
	void startSprinting();
	UFUNCTION(Server,  unreliable)
	void stopSprinting(); 
	UFUNCTION()
	void landingDamage(const FHitResult& Hit);
public:
	TArray<AWeaponCore*> Inventory; 
	UPROPERTY(EditAnywhere)
	float repl = false;
	

};
