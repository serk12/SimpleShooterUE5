// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ShooterIAController.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API AShooterIAController : public AAIController
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float dt_) override;
private:

	UPROPERTY(EditAnywhere)
	class UBehaviorTree* mIABehavior;

	float mMemoryTime;
	// UPROPERTY(EditAnywhere)
	// float mMaxMemoryTime = 10.0f;
};
