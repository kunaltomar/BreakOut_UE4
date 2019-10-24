// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include "BreakOutGameModeBase.h"
#include "Block.h"
#include "Components/StaticMeshComponent.h"
#include "Components/PrimitiveComponent.h"
#include "TimerManager.h"
#include "Components/AudioComponent.h"

// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = meshComp;

	ballDefaultHitSound = CreateDefaultSubobject<UAudioComponent>(TEXT("BallDefaultHitSound"));
	ballDefaultHitSound->SetupAttachment(RootComponent);
	ballDefaultHitSound->bAutoActivate = false;

	ballBlocktHitSound = CreateDefaultSubobject<UAudioComponent>(TEXT("BallBlocktHitSound"));
	ballBlocktHitSound->SetupAttachment(RootComponent);
	ballBlocktHitSound->bAutoActivate = false;

	ballDeathSound = CreateDefaultSubobject<UAudioComponent>(TEXT("BallDeathSound"));
	ballDeathSound->SetupAttachment(RootComponent);
	ballDeathSound->bAutoActivate = false;

	ballSpeed = 10.f;
	pauseBall = true;
}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();

	meshComp->OnComponentHit.AddDynamic(this, &ABall::OnHit);

	if (meshComp->GetMaterial(0))
	{
		matInst = meshComp->CreateAndSetMaterialInstanceDynamicFromMaterial(0, meshComp->GetMaterial(0));
	}

	ballDirection = FMath::VRand();
}

// Called every frame
void ABall::Tick(float DeltaTime) 
{
	Super::Tick(DeltaTime);

	// Moving the Ball
	if(!pauseBall)
	SetActorLocation(GetActorLocation() + (ballDirection * ballSpeed), true);

}

void ABall::StartBall()
{
	ballDirection = FMath::VRand() * FVector(1.0f, 1.0f, 0.f);
	//GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &ABall::RemovePause, 5.f, false, 5.f);
	RemovePause();
	
}

void ABall::PauseBall()
{
	pauseBall = true;
}

void ABall::RemovePause()
{
	pauseBall = false;
}


void ABall::OnHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComponent, FVector NormalImpulse, const FHitResult & Hit)
{
	
	if (OtherActor == nullptr)
		return;
	
	// Ball bounce effect
	matInst->SetScalarParameterValue("LastTimeHitTaken", GetWorld()->TimeSeconds);

	// Calculating Bounce Direction
	ballDirection = FMath::GetReflectionVector(ballDirection, Hit.Normal * FVector(1.0f, 1.0f, 0.f));

	// Ball Collision Checking
	if (OtherActor->ActorHasTag("BottomVolume"))
	{
		ballDeathSound->Play(0.f);
		ABreakOutGameModeBase* GM = Cast<ABreakOutGameModeBase>(GetWorld()->GetAuthGameMode());
		if (GM != nullptr)
		{
			GM->UpdateLives();
			
		}
		return;
	}

	ABlock* hitBlock = Cast<ABlock>(OtherActor);
	if (hitBlock != nullptr)
	{
		hitBlock->DeActivateBlock();
		//GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("Hit Brick"));
		ballBlocktHitSound->Play(0.f);
		ABreakOutGameModeBase* GM = Cast<ABreakOutGameModeBase>(GetWorld()->GetAuthGameMode());
		if (GM != nullptr)
		{
			GM->UpdateScore();
			GM->CheckLevelState();
		}
		

	}
	else
	{
		ballDefaultHitSound->Play(0.f);
	}

	
}

