// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUpComp.h"

UPickUpComp::UPickUpComp()
{
	// Setup the Sphere Collision
	SphereRadius = 32.f;
}

void UPickUpComp::BeginPlay()
{
	Super::BeginPlay();

	// Register our Overlap Event
	OnComponentBeginOverlap.AddDynamic(this, &UPickUpComp::OnSphereBeginOverlap);
}

void UPickUpComp::OnSphereBeginOverlap(
	UPrimitiveComponent* OverlappedComponent
	, AActor* OtherActor,
	UPrimitiveComponent* OtherComp
	, int32 OtherBodyIndex
	, bool bFromSweep
	, const FHitResult& SweepResult)
{
	// Checking if it is a First Person Character overlapping
	AAPlayer* Character = Cast<AAPlayer>(OtherActor);
	if(Character != nullptr)
	{
		// Notify that the actor is being picked up
		OnPickUp.Broadcast(Character);

		// Unregister from the Overlap Event so it is no longer triggered
		OnComponentBeginOverlap.RemoveAll(this);
	}
}
