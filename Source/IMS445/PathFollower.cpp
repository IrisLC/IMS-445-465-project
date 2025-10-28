// Fill out your copyright notice in the Description page of Project Settings.


#include "PathFollower.h"

// Sets default values
APathFollower::APathFollower()
{

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	
	
	
		
	
	
}

// Called when the game starts or when spawned
void APathFollower::BeginPlay()
{
	Super::BeginPlay();
	
	if (SplineHolder != nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("1"));
		TArray<UActorComponent*> ActorComponents;
		SplineHolder->GetComponents(ActorComponents);
		for (auto* ActorComp : ActorComponents)
		{

			Spline = Cast<USplineComponent>(ActorComp);

		}
	}
}

// Called every frame
void APathFollower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Spline != nullptr) {

		DistanceTraveled += Speed * DeltaTime;

		FVector location = Spline->GetLocationAtDistanceAlongSpline(DistanceTraveled, ESplineCoordinateSpace::World);
		FRotator rotation = Spline->GetRotationAtDistanceAlongSpline(DistanceTraveled, ESplineCoordinateSpace::World);

		SetActorLocationAndRotation(location, rotation);

	}
}

