// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BreakOutGameModeBase.generated.h"

class ABlock;
class ABall;
/**
 * 
 */
UCLASS()
class BREAKOUT_API ABreakOutGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

		
protected:

	virtual void BeginPlay() override;

	

private:
	
	TArray<ABlock*> blocksArray;
	
	ABall* theBall = nullptr;

	int playerScore;
	int playerLives;
	
	void SpawnGrid();
	void SpawnBall();

	void ResetScore();
	void ResetLives();
	
	void PauseBall();

	void ResetTheGrid();
	void ResetLevel();
	
public:

	UPROPERTY(EditDefaultsOnly, Category = "GameConfig")
		TSubclassOf<ABall> ballType;
	 
	UPROPERTY(EditDefaultsOnly, Category = "GameConfig")
		TSubclassOf<ABlock> blockType;

	UPROPERTY(EditDefaultsOnly,Category = "GameConfig")
		unsigned grid_Height; 

	UPROPERTY(EditDefaultsOnly, Category = "GameConfig")
		unsigned grid_Width;

	UPROPERTY(EditDefaultsOnly, Category = "GameConfig")
		unsigned grid_TopGap;

	UPROPERTY(EditDefaultsOnly, Category = "GameConfig")
		unsigned grid_RightGap;
		

	UFUNCTION(BlueprintCallable)
	int GetScore();

	UFUNCTION(BlueprintCallable)
	int GetLives();

	UFUNCTION(BlueprintCallable)
	void StartGame();

	UFUNCTION(BlueprintCallable)
	void ResetTheBall();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Game")
	void ShowMenu();

	void CheckLevelState();

	void UpdateScore();
	void UpdateLives();

};
