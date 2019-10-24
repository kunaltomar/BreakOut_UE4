// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ball.generated.h"

class USphereComponent;
class UAudioComponent;
UCLASS()
class BREAKOUT_API ABall : public AActor
{
	GENERATED_BODY()
	
private:
	bool pauseBall;
	FTimerHandle timerHandle;
	FVector ballDirection;
	UMaterialInstanceDynamic* matInst;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Sets default values for this actor's properties
	ABall();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleDefaultsOnly, Category = "BallConfig")
		UStaticMeshComponent* meshComp;

	UPROPERTY(EditAnywhere, Category = "BallConfig")
		float ballSpeed;

	UPROPERTY(VisibleDefaultsOnly, Category = "BallConfig")
		UAudioComponent* ballDefaultHitSound;

	UPROPERTY(VisibleDefaultsOnly, Category = "BallConfig")
		UAudioComponent* ballBlocktHitSound;

	UPROPERTY(VisibleDefaultsOnly, Category = "BallConfig")
		UAudioComponent* ballDeathSound;

	// Ball Movement Control
	void StartBall();
	void PauseBall();
	void RemovePause();

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

};
