// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterPlayerController.h"
#include "TimerManager.h"

void AShooterPlayerController::GameHasEnded(class AActor* EndGameFocus, bool bIsWinner)
{
    Super::GameHasEnded(EndGameFocus , bIsWinner);

    UE_LOG(LogTemp, Warning, TEXT("GG easy, you lost"));

    GetWorldTimerManager().SetTimer(mRestartTimer, this, &APlayerController::RestartLevel, mRestartDelay);
}