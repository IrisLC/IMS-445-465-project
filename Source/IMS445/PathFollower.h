// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SplineComponent.h"
#include "PathFollower.generated.h"

UCLASS()
class IMS445_API APathFollower : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APathFollower();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float DistanceTraveled;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spline")
	AActor* SplineHolder;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	USplineComponent* Spline;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
