// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ShooterPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API AShooterPlayerController : public APlayerController
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere)
	float mRestartDelay = 5.0f;
	
	FTimerHandle mRestartTimer;

public:
	void GameHasEnded(class AActor* EndGameFocus = nullptr, bool bIsWinner = false) override;
};
