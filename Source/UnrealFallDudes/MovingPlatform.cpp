// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"
#include "CoreMinimal.h"

DEFINE_LOG_CATEGORY_STATIC(MyProject, Log, All);

// Sets default values
AMovingPlatform::AMovingPlatform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
}


// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	MovePlatform(DeltaTime);

	RotatePlatform(DeltaTime);
}


void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	auto currentRotation = GetActorRotation();
	currentRotation += RotationVelocity * DeltaTime;
	SetActorRotation(currentRotation);
}


double AMovingPlatform::GetDistanceMoved() const
{
	return FVector::Distance(StartLocation, GetActorLocation());
}

bool AMovingPlatform::ShouldReturn() const
{
	return GetDistanceMoved() > Distance;
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	const auto actorNewPosition = FVector(GetActorLocation() + Speed * DeltaTime);
	SetActorLocation(actorNewPosition);

	//UE_LOG(MyProject, Display, TEXT("Log message: %f"), travelledDistance);
	if (ShouldReturn())
	{
		FString SomeString = GetName();

		StartLocation = GetActorLocation();

		UE_LOG(MyProject, Display, TEXT("Actor %s is at start location %d"), *SomeString, StartLocation.Z);
		Speed = -Speed;
	}
}
