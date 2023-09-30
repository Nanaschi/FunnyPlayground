// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class UNREALFALLDUDES_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);
	double GetDistanceMoved() const;
	bool ShouldReturn() const;

	UPROPERTY(EditAnywhere, Category= "Movement")
	FVector PlatformLocation = FVector(20, 30, 10);

	UPROPERTY(EditAnywhere, Category= "Movement")
	FVector Speed;

	FVector StartLocation;



	UPROPERTY(EditAnywhere, Category= "Movement")
	double Distance;

	UPROPERTY(EditAnywhere, Category= "Rotation")
	FRotator RotationVelocity;
};
