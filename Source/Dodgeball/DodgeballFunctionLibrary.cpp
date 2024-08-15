// Fill out your copyright notice in the Description page of Project Settings.


#include "DodgeballFunctionLibrary.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "CollisionQueryParams.h"


bool UDodgeballFunctionLibrary::CanSeeActor(const UWorld* World, FVector Location, const AActor* TargetActor,
	TArray<AActor*> IgnoreActors)
{
	if (TargetActor == nullptr) return false;

	// Store the results of the Line Trace
	FHitResult Hit;

	// Where the Line Trace starts and ends
	FVector Start = Location;
	FVector End = TargetActor->GetActorLocation();

	// The trace channel we want to compare against
	ECollisionChannel Channel = ECollisionChannel::ECC_GameTraceChannel1;

	FCollisionQueryParams QueryParams;
	// Ignore the actors specified
	QueryParams.AddIgnoredActors(IgnoreActors);

	// Execute the Line Trace
	World->LineTraceSingleByChannel(Hit, Start, End, Channel, QueryParams);

	// Show the Line Trace inside the game
	// DrawDebugLine(World, Start, End, FColor::Red);

	return !Hit.bBlockingHit;
}
