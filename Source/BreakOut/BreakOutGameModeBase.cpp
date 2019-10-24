// Fill out your copyright notice in the Description page of Project Settings.


#include "BreakOutGameModeBase.h"
#include "Game/Block.h"
#include "Game/Ball.h"
#include "TimerManager.h"

#define DEFAULT_Score 0;
#define DEFAULT_Lives 3;


void ABreakOutGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	playerScore = DEFAULT_Score;
	playerLives = DEFAULT_Lives;
}

void ABreakOutGameModeBase::SpawnGrid()
{
	// Check if grid is already spawned
	if (blocksArray.Num() > 0)
		return;

	UWorld* world = GetWorld();


	// Spawning Block Grids
	if (world && blockType)
	{	//TODO change vectors
		FVector spawnLoc = FVector::ZeroVector;
		FRotator spawnRot = FRotator::ZeroRotator;
		FActorSpawnParameters SpawnInfo;

		FVector heightBuf = FVector(0.f, 0.f, 0.f);
		FVector widthBuf = FVector(0.f, 0.f, 0.f);

		for (unsigned rows = 0; rows < grid_Width; rows++)
		{
			spawnLoc = FVector(0.f, rows * grid_RightGap, 0.f);

			for (unsigned column = 0; column < grid_Height; column++)
			{
				ABlock* tempblock = world->SpawnActor<ABlock>(blockType,spawnLoc, spawnRot, SpawnInfo);
				tempblock->ActivateBlock();
				blocksArray.Emplace(tempblock);

				spawnLoc = spawnLoc - FVector(grid_TopGap, 0.f, 0.f);
			}
			
		}
	}
}

void ABreakOutGameModeBase::UpdateScore()
{
	playerScore++;
}

void ABreakOutGameModeBase::UpdateLives()
{
	if (playerLives>0)
	{
		playerLives--;
		ResetTheBall();
	}
	else 
	{
		// If Dead Reset Level
		ResetLevel();
	}
		
}

void ABreakOutGameModeBase::ResetScore()
{
	playerScore = DEFAULT_Score;
}

void ABreakOutGameModeBase::ResetLives()
{
	playerLives = DEFAULT_Lives;
}

int ABreakOutGameModeBase::GetScore()
{
	return playerScore;
}

int ABreakOutGameModeBase::GetLives()
{
	return playerLives;
}

void ABreakOutGameModeBase::SpawnBall()
{
	if (theBall == nullptr)
	{
		FVector spawnLoc = FVector(-1244.24f, 997.28f, 0.0f);
		FRotator spawnRot = FRotator(0.f,0.f,0.f);
		FActorSpawnParameters SpawnInfo;
		theBall = GetWorld()->SpawnActor<ABall>(ballType, spawnLoc, spawnRot, SpawnInfo);
		theBall->StartBall();
	}
	else
	{
		theBall->StartBall();
	}
	
}

void ABreakOutGameModeBase::StartGame()
{
	SpawnGrid();
	SpawnBall();
}

void ABreakOutGameModeBase::ResetTheBall()
{
	if (theBall == nullptr)
		return;
	FVector spawnLoc = FVector(-1244.24f, 997.28f, 0.0f);
	theBall->SetActorLocation(spawnLoc,false);
	
}

void ABreakOutGameModeBase::PauseBall()
{
	theBall->PauseBall();
}

void ABreakOutGameModeBase::ResetTheGrid()
{
	for (ABlock* it : blocksArray) 
	{
		it->ActivateBlock();
	}
}

void ABreakOutGameModeBase::ResetLevel()
{
	ResetLives();
	ResetScore();

	PauseBall();
	ResetTheBall();
	
	ResetTheGrid();
	ShowMenu();
}

// To check Level Completion
void ABreakOutGameModeBase::CheckLevelState()
{
	if (playerScore >= blocksArray.Num())
	{
		ResetLevel();
	}
}
