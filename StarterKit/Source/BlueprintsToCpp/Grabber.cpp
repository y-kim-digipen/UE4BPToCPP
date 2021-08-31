// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

UPhysicsHandleComponent* UGrabber::GetPhysicsComponent()
{
	return GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
}

FVector UGrabber::GetHoldLocation()
{
	const FVector WorldLocation = GetOwner()->FindComponentByClass<USceneComponent>()->GetComponentLocation();
	const FVector ForwardVector = GetOwner()->FindComponentByClass<USceneComponent>()->GetForwardVector();
	return WorldLocation + ForwardVector * HoldDistance;
}

FVector UGrabber::GetMaxGripLocation()
{
	const FVector WorldLocation = GetOwner()->FindComponentByClass<USceneComponent>()->GetComponentLocation();
	const FVector ForwardVector = GetOwner()->FindComponentByClass<USceneComponent>()->GetForwardVector();
	return WorldLocation + ForwardVector * MaxGrabDistance;
}

