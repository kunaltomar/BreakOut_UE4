// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerBlock.generated.h"

UCLASS()
class BREAKOUT_API APlayerBlock : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerBlock();

	UPROPERTY(VisibleDefaultsOnly, Category = "PlayerConfig")
	UStaticMeshComponent* meshComp;
	
	UPROPERTY(EditDefaultsOnly, Category = "PlayerConfig")
	float speed;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveRight(float Value);
};
