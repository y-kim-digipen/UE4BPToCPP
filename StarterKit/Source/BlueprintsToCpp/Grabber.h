// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Grabber.generated.h"

class UPhysicsHandleComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable )
class BLUEPRINTSTOCPP_API UGrabber : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintPure, Category = Getter)
	UPhysicsHandleComponent* GetPhysicsComponent();

	UFUNCTION(BlueprintPure, Category = Getter)
	FVector GetHoldLocation();

	UFUNCTION(BlueprintPure, Category=Getter)
    FVector GetMaxGripLocation();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = GrabSettings)
		float MaxGrabDistance = 100.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = GrabSettings)
		float HoldDistance = 100.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = GrabSettings)
		float GrabRadius = 50.0f;
};
