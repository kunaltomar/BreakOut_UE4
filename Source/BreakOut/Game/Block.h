// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Block.generated.h"

UCLASS()
class BREAKOUT_API ABlock : public AActor
{
	GENERATED_BODY()

private:
	
	
public:	
	// Sets default values for this actor's properties
	ABlock();
		
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleDefaultsOnly)
	UStaticMeshComponent* meshComp;

	void ActivateBlock();
	void DeActivateBlock();

};
