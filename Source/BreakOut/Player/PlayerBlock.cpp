// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerBlock.h"


// Sets default values
APlayerBlock::APlayerBlock()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	//RootComponent =meshComp;

	speed = 1.0f;

}

// Called when the game starts or when spawned
void APlayerBlock::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerBlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerBlock::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerBlock::MoveRight);
}

// Moving Player Paddle
void APlayerBlock::MoveRight(float Value)
{
	//AddMovementInput(GetActorRightVector()* Value);
	float relativeLocY = meshComp->GetComponentLocation().Y;
	relativeLocY = relativeLocY + Value *speed ;
	relativeLocY = FMath::Clamp(relativeLocY, -400.0f, 2400.0f);

	meshComp->SetRelativeLocation(FVector(meshComp->GetComponentLocation().X, relativeLocY, meshComp->GetComponentLocation().Z));
	
}


