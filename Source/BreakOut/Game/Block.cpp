// Fill out your copyright notice in the Description page of Project Settings.


#include "Block.h"
#include "Components/StaticMeshComponent.h"
#include "ConstructorHelpers.h"


// Sets default values
ABlock::ABlock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = meshComp;

	
	/*static ConstructorHelpers::FObjectFinder<UStaticMesh> blockMeshAsset(TEXT("StaticMesh'/Game/Assets/Block_StaticMesh.Block_StaticMesh'"));

	if (blockMeshAsset.Object)
	{
		meshComp->SetStaticMesh(blockMeshAsset.Object);
	}*/
}

// Called when the game starts or when spawned
void ABlock::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABlock::ActivateBlock()
{
	SetActorHiddenInGame(false);
	meshComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	meshComp->SetCollisionResponseToAllChannels(ECR_Block);
	meshComp->SetNotifyRigidBodyCollision(true);
}

void ABlock::DeActivateBlock()
{
	SetActorHiddenInGame(true);
	meshComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	meshComp->SetNotifyRigidBodyCollision(false);
}

