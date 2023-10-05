// Fill out your copyright notice in the Description page of Project Settings.
/*

	if u dont understand - DO NOT CHANGE!
		0__0
		/()\
		 /\
	I see you

*/

#include "CharacterComponents/SLS_Character.h"
#include "Camera/CameraComponent.h" 
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "CharacterComponents/HealthComponent.h"
#include "Engine/Engine.h"
#include "Net/UnrealNetwork.h"
#include "CharacterComponents/SLS_Controller.h"
#include "GameFramework/Actor.h"
#include "CharacterComponents/WeaponComponent.h"
#include "CharacterComponents/BuildComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"
#include "HUD/WidgetCore.h"




// Sets default values
ASLS_Character::ASLS_Character()
{
	

 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true; 
	

	SetOwner(Cast<AActor>(ASLS_Controller::StaticClass()));


	FirstCamera = CreateDefaultSubobject<UCameraComponent>("FirstCamera");
	FirstCamera->SetupAttachment(GetRootComponent()); 
	FirstCamera->bUsePawnControlRotation = true;
	firstCameraAttachment(); 
	CharacterSkeletal = GetMesh(); 
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent"); 
	WeaponComponent = CreateDefaultSubobject<UWeaponComponent>("WeaponComponent"); 
	BuildComponent = CreateDefaultSubobject<UBuildComponent>("BuildComponent"); 

	
	HealthComponent = CreateDefaultSubobject<UHealthComponent>("HealthComponent"); 
	HealthComponent->OnDeath.AddUObject(this, &ASLS_Character::OnDeath);
	OnTakeAnyDamage.AddDynamic(HealthComponent, &UHealthComponent::takeDamage); 
	LandedDelegate.AddDynamic(this, &ASLS_Character::landingDamage); 

	MovementComponent = GetCharacterMovement();
	MovementComponent->MaxWalkSpeed = MWSpeed;

	Role = GetRemoteRole();
	
	
}

// Called when the game starts or when spawned
void ASLS_Character::BeginPlay()
{
	Super::BeginPlay(); 
	
}

// Called every frame
void ASLS_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	

}

// Called to bind functionality to input
void ASLS_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("moveForward", this, &ASLS_Character::moveForward); 
	PlayerInputComponent->BindAxis("moveSide", this, &ASLS_Character::moveSide); 
	PlayerInputComponent->BindAxis("lookUp", this, &ASLS_Character::lookY); 
	PlayerInputComponent->BindAxis("lookSide", this, &ASLS_Character::lookR); 
	PlayerInputComponent->BindAction("jump",IE_Pressed, this , &ASLS_Character::Jump_custom);
	PlayerInputComponent->BindAction("speedUp", IE_Pressed, this, &ASLS_Character::startSprinting);
	PlayerInputComponent->BindAction("speedUp", IE_Released, this, &ASLS_Character::stopSprinting);


	
}

void ASLS_Character::moveForward(float amount)
{
	AddMovementInput(GetActorForwardVector(), amount); 
}

void ASLS_Character::moveSide(float amount)
{
	AddMovementInput(GetActorRightVector(), amount); 
}

void ASLS_Character::lookY(float amount)
{
	AddControllerPitchInput(amount); 
}

void ASLS_Character::lookR(float amount)
{
	AddControllerYawInput(amount); 
}

void ASLS_Character::Jump_custom()
{
	Super::Jump(); 
}



//without bind 08.09
//
void ASLS_Character::sitDown()
{
	isSitting = true;
}

//without bind 08.09
//
void ASLS_Character::stendUp()
{
	isSitting = Default_boolean;
}

void ASLS_Character::firstCameraAttachment()
{
	if (!CharacterSkeletal) { return; }
	FTransform HeadSocket = CharacterSkeletal->GetSocketTransform("headSocket"); 
	FirstCamera->SetupAttachment(GetRootComponent()); 
	FAttachmentTransformRules AttachmentCameraRules(EAttachmentRule::SnapToTarget, false); 
	FirstCamera->AttachToComponent(CharacterSkeletal, AttachmentCameraRules, "headSocket");
	

}




void ASLS_Character::OnDeath()
{
	MovementComponent->Deactivate();
	GetOwner()->SetLifeSpan(2.f);
	SetLifeSpan(2.f);
	//01.10.2023 need tobe completed 

	UGameplayStatics::OpenLevel(GetWorld(), "worldName"); 
}

void ASLS_Character::landingDamage(const FHitResult& Hit)
{
	CurrentHealth = HealthComponent->getHealth();
	float VelocityVector = -GetVelocity().Z; 
	FVector2D height = {1200, 2900};
	FVector2D DamageOfHeight = { 10,100 }; 
	int Damage = FMath::GetMappedRangeValueClamped(height, DamageOfHeight, VelocityVector);
	*CurrentHealth -= Damage; 

	UE_LOG(LogTemp, Error, TEXT("%0.f"), VelocityVector)


}





void ASLS_Character::startSprinting_Implementation() {
	MovementComponent->MaxWalkSpeed = SUSpeed;
}



void ASLS_Character::stopSprinting_Implementation(){
	MovementComponent->MaxWalkSpeed = MWSpeed;
}

