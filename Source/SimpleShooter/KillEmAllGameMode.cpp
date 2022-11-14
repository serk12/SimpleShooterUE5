// Fill out your copyright notice in the Description page of Project Settings.


#include "KillEmAllGameMode.h"


void AKillEmAllGameMode::PawnKilled(APawn* pawnKilled_) 
{
    Super::PawnKilled(pawnKilled_);

    UE_LOG(LogTemp, Warning, TEXT("A pawn is dead"));
    APlayerController* player = Cast<APlayerController>(pawnKilled_->GetController());
    if (player != nullptr) {
        player->GameHasEnded(nullptr, false);
    }
}