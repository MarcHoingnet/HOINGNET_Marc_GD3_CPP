// Fill out your copyright notice in the Description page of Project Settings.


#include "Kismet/GameplayStatics.h"
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

void AGM_Collectible::StartTimer()
{
    RemainingTime = TimerDuration;
    GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AGM_Collectible::UpdateTimer, 1.0f, true);

}

void AGM_Collectible::UpdateTimer()
{
    if (RemainingTime > 0)
    {
        RemainingTime--;
        UE_LOG(LogTemp, Warning, TEXT("Temps restant : %d secondes"), RemainingTime);
    }
    else
    {
        if (GetWorld())
        {
            UGameplayStatics::OpenLevel(GetWorld(), FName("testMap"));
        }
    }
}
