// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterIAController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

void AShooterIAController::BeginPlay()
{
    Super::BeginPlay();
    if (mIABehavior != nullptr) {
        RunBehaviorTree(mIABehavior);
        GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
        APawn*  playerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
        GetBlackboardComponent()->SetValueAsVector(TEXT("PatrolGoal"), playerPawn->GetActorLocation());        
    }
}

void AShooterIAController::Tick(float dt_)
{
    Super::Tick(dt_);
    // APawn*  playerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    // if (LineOfSightTo(playerPawn)) {
    //     GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), playerPawn->GetActorLocation());
    //     GetBlackboardComponent()->SetValueAsVector(TEXT("LastKnownLocation"), playerPawn->GetActorLocation());
    //     // mMemoryTime = 0.0f;
    // } else {
    //     GetBlackboardComponent()->ClearValue(TEXT("PlayerLocation"));
    //     // mMemoryTime += dt_;
    //     // if (mMemoryTime >= mMaxMemoryTime) {
    //     //     GetBlackboardComponent()->ClearValue(TEXT("LastKnownLocation"));
    //     // }
    // }
}