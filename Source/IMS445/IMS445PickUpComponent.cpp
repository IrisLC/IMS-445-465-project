// Copyright Epic Games, Inc. All Rights Reserved.

#include "IMS445PickUpComponent.h"

UIMS445PickUpComponent::UIMS445PickUpComponent()
{
	// Setup the Sphere Collision
	SphereRadius = 32.f;
}

void UIMS445PickUpComponent::BeginPlay()
{
	Super::BeginPlay();

	// Register our Overlap Event
	OnComponentBeginOverlap.AddDynamic(this, &UIMS445PickUpComponent::OnSphereBeginOverlap);
}

void UIMS445PickUpComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Checking if it is a First Person Character overlapping
	AIMS445Character* Character = Cast<AIMS445Character>(OtherActor);
	if(Character != nullptr)
	{
		// Notify that the actor is being picked up
		OnPickUp.Broadcast(Character);

		// Unregister from the Overlap Event so it is no longer triggered
		OnComponentBeginOverlap.RemoveAll(this);
	}
}
