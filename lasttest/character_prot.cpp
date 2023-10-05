// Fill out your copyright notice in the Description page of Project Settings.


#include "character_prot.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GamePlayStatics.h"
#include "GameFramework/CharacterMovementComponent.h" 
#include "HealthComponent.h" 
#include "Components/TextRenderComponent.h"
#include "Engine/DamageEvents.h" 
#include "Knife.h"
#include "WeaponComponent.h"
#include "Components/PoseableMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "protController.h" 
#include "GameFramework/Controller.h"
#include "RockeTL.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "test2.h"



// Sets default values
Acharacter_prot::Acharacter_prot()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FirstCamera = CreateDefaultSubobject<UCameraComponent>("FirstCamera");
	ThirdCamera = CreateDefaultSubobject<UCameraComponent>("ThirdCamera");
	Arm = CreateDefaultSubobject<USpringArmComponent>("Arm");
	Arm->SetupAttachment(GetRootComponent()); 
	FirstCamera->SetupAttachment(GetRootComponent());
	ThirdCamera->SetupAttachment(Arm); 
	Arm->bUsePawnControlRotation = true;
	FirstCamera->bUsePawnControlRotation = true; 
	HealthComponent = CreateDefaultSubobject<UHealthComponent>("HealthComponent");
	HealthTextRender = CreateDefaultSubobject<UTextRenderComponent>("TextRender");
	HealthTextRender->SetupAttachment(GetRootComponent()); 
	Weapon = CreateDefaultSubobject<UWeaponComponent>("WC");
	effect = CreateDefaultSubobject<Utest2>("effect");
	
	
	
	
	
}

void Acharacter_prot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called when the game starts or when spawned
void Acharacter_prot::BeginPlay()
{
	Super::BeginPlay();
	camerachange();
	A = GetCharacterMovement();
	A->MaxWalkSpeed = 600.0f;
	HealthComponent->OnHealthPrint.AddUObject(this, &Acharacter_prot::printhealth);
	HealthComponent->OnDeath.AddUObject(this, &Acharacter_prot::onDeath);
	LandedDelegate.AddDynamic(this, &Acharacter_prot::falldamage);
	printhealth(HealthComponent->gethealth());
	
	FAttachmentTransformRules forhead(EAttachmentRule::SnapToTarget, false); 
	FirstCamera->AttachToComponent(GetMesh(), forhead, "headSocket");

		
}
	
	
// Called every frame

// Called to bind functionality to input
void Acharacter_prot::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump",IE_Pressed, this, &Acharacter_prot::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &Acharacter_prot::StopJumping);
	PlayerInputComponent->BindAxis("MoveForward", this, &Acharacter_prot::movef); 
	PlayerInputComponent->BindAxis("MoveRightLeft", this, &Acharacter_prot::moverl);
	PlayerInputComponent->BindAxis("lookUP", this, &Acharacter_prot::lookUP);
	PlayerInputComponent->BindAxis("lookRL", this, &Acharacter_prot::lookRL); 
	PlayerInputComponent->BindAction("CS", IE_Pressed, this, &Acharacter_prot::camerachange); 
	PlayerInputComponent->BindAction("speedUP", IE_Pressed, this, &Acharacter_prot::speedup);
	PlayerInputComponent->BindAction("speedUP", IE_Released, this, &Acharacter_prot::speedstop);
	PlayerInputComponent->BindAction("Ctrl", IE_Pressed, this, &Acharacter_prot::changeSit);
	PlayerInputComponent->BindAction("Ctrl", IE_Released, this, &Acharacter_prot::changeSitF); 
	PlayerInputComponent->BindAction("Fire", IE_Pressed, Weapon , &UWeaponComponent::fireGeneral);

}

void Acharacter_prot::movef(float amount) {
	AddMovementInput(GetActorForwardVector(), amount); 
}

void Acharacter_prot::moverl(float amount)
{
	AddMovementInput(GetActorRightVector(), amount); 
}

void Acharacter_prot::lookUP(float amount) {
	AddControllerPitchInput(amount);

}

void Acharacter_prot::lookRL(float amount) {
	AddControllerYawInput(amount);
}

void Acharacter_prot::camerachange()
{
	if (CameraStatus == ECameraStatus::FirstCamera) {
		CameraStatus = ECameraStatus::ThirdCamera;
		FirstCamera->Deactivate();
		ThirdCamera->Activate();
	}
	else {
		CameraStatus = ECameraStatus::FirstCamera; 
		FirstCamera->Activate(); 
		ThirdCamera->Deactivate(); 
	}
}

void Acharacter_prot::printhealth(float health)
{
	if (!HealthComponent)return;
	if (HealthComponent->isDead())return;
	if (!HealthTextRender)return;
	HealthTextRender->SetText(FText::FromString(FString::Printf(TEXT("%.f"), health)));
}

void Acharacter_prot::onDeath() {
	if (!GetCharacterMovement())return;

	GetCharacterMovement()->DestroyComponent();
	GetMesh()->SetSimulatePhysics(true); 

	FirstCamera->bUsePawnControlRotation = false;
	
	HealthTextRender->DestroyComponent();
	//InputComponent->Deactivate(); 
	//HealthComponent->DestroyComponent();
	//Controller->Destroy();
	//SetLifeSpan(5.0f); 
	
	UCapsuleComponent* CpS = GetCapsuleComponent();
	if (!CpS)return;
	CpS->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore); 
	


	
}

void Acharacter_prot::speedup() {
	if (sitdowm == true)return;
	A->MaxWalkSpeed = 1000.0f; 
}

void Acharacter_prot::speedstop() {
	if (sitdowm == true)return;
	A->MaxWalkSpeed = 600.0f; 
}

void Acharacter_prot::falldamage(const FHitResult& Param)
{
	FallVelocity = -GetVelocity().Z;
	UE_LOG(LogTemp, Error, TEXT("%f"), FallVelocity)
	FVector2D Landeddamage = FVector2D(10.0f, 100.0f);
	FVector2D landeddamageVelocity = FVector2D(700.0f, 1000.0f);
	if (FallVelocity <= landeddamageVelocity.X)return;

	int FallDamage = FMath::GetMappedRangeValueClamped(landeddamageVelocity, Landeddamage, FallVelocity); 

	TakeDamage(FallDamage, FDamageEvent{}, nullptr, nullptr);
	
}

void Acharacter_prot::changeSit()
{
	sitdowm = true; 
	A->MaxWalkSpeed = 300.0f; 

}

void Acharacter_prot::changeSitF()
{
	sitdowm = false; 
	A->MaxWalkSpeed = 600.0f;
	
}

void Acharacter_prot::fireCharacterPoint()
{
	if (HealthComponent->isDead())return; 
	UE_LOG(LogTemp, Error, TEXT("FIRE"))
		FTransform SocketT = GetMesh()->GetSocketTransform("headSocket");
	FVector StartShoot;//SocketT.GetLocation();
	FRotator Rotatio;//SocketT.GetRotation().GetForwardVector();

	Controller->GetPlayerViewPoint(StartShoot, Rotatio);

	FVector TraceStart = StartShoot;
	FVector ShorR = Rotatio.Vector();
	auto HT = FMath::DegreesToRadians(1.5);

	FVector StartShoR = FMath::VRandCone(ShorR, HT);

	FVector EndR = TraceStart + (StartShoR * 1000);

	FCollisionQueryParams Cff;
	Cff.AddIgnoredActor(this);
	Cff.bReturnPhysicalMaterial = true;

	FHitResult HitRes;

	GetWorld()->LineTraceSingleByChannel(HitRes, TraceStart, EndR, ECollisionChannel::ECC_Visibility, Cff);

	if (HitRes.bBlockingHit) {
		DrawDebugLine(GetWorld(), SocketT.GetLocation(), HitRes.ImpactPoint, FColor::Green, false, 2.0f, 0, 2.5f);
		FVector PointDot = HitRes.ImpactPoint;
		DrawDebugSphere(GetWorld(), HitRes.ImpactPoint, 8.0f, 5, FColor::Red, false, 2.5f);

		AprotController* pr = Cast<AprotController>(Controller);

		if (HitRes.GetActor() == this)return;
		UGameplayStatics::ApplyPointDamage(HitRes.GetActor(), 20.0f, HitRes.ImpactPoint, HitRes, this->GetController(), this, nullptr);

	}

	FTransform GetSocketF = GetMesh()->GetSocketTransform("pelvisSocket");



	FVector StartLine;// GetSocketF.GetLocation();
	FRotator GG;
	// GetSocketF.GetRotation().Vector();

	Controller->GetPlayerViewPoint(StartLine, GG);
	FVector DirectionL = GG.Vector();

	FVector LineEnd = StartLine + (DirectionL * 10000);
	FHitResult HitRess;

	FCollisionQueryParams Cff1;
	Cff1.bReturnPhysicalMaterial = true; 
	Cff1.AddIgnoredActor(this);

	GetWorld()->LineTraceSingleByChannel(HitRess, StartLine, LineEnd, ECollisionChannel::ECC_Visibility, Cff1);



	FVector EndPoint;
	if (HitRess.bBlockingHit) {
		EndPoint = HitRess.ImpactPoint;
		effect->FXspawn(HitRess); 
	}
	else {
		EndPoint = LineEnd; 
	}
	FVector Dir = (EndPoint - GetSocketF.GetLocation());

	 Rocket = Cast<ARockeTL>(UGameplayStatics::BeginDeferredActorSpawnFromClass(GetWorld(), RocketL, GetSocketF));

	if (Rocket) {
		
		Rocket->ShotDirection(Dir);
		Rocket->SetOwner(this);
		Rocket->Weapon1 = Weapon->Weapon;

		UGameplayStatics::FinishSpawningActor(Rocket, GetSocketF); 
		WeaponRiffleData.Wepon = EWeapon::Launcher; 
		if (WeaponRiffleData.Wepon == EWeapon::Launcher) {
			WeaponRiffleData.amounth = 5; 
			WeaponRiffleData.magazine = 10;
		}
		else if (WeaponRiffleData.Wepon == EWeapon::Riffle) {
			WeaponRiffleData.amounth = 30;
			WeaponRiffleData.magazine = 7;
		}
		
	}
}



