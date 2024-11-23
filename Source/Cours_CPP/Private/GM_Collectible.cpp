// Fill out your copyright notice in the Description page of Project Settings.


#include "GM_Collectible.h"

void AGM_Collectible::GetScore(int32 Score)
{
    ScoreTotal = ScoreTotal + Score;
    UE_LOG(LogTemp, Warning, TEXT("Score Total mis à jour : %d"), ScoreTotal);

    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("Score Total : %d"), ScoreTotal));
    }
}
