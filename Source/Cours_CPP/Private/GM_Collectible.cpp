// Fill out your copyright notice in the Description page of Project Settings.


#include "GM_Collectible.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"



void AGM_Collectible::BeginPlay()
{
    Super::BeginPlay();

    ScoreWidgetInstance = CreateWidget<UUserWidget>(GetWorld(), WB_ScoreCollectible);
    ScoreWidgetInstance->AddToViewport();
}

void AGM_Collectible::GetScore(int32 Score)
{
    ScoreTotal = ScoreTotal + Score;

    if (ScoreWidgetInstance)
    {
        UFunction* UpdateScoreFunc = ScoreWidgetInstance->FindFunction(FName("UpdateScore"));

        if (UpdateScoreFunc)
        {
            struct FUpdateScoreParams
            {
                int32 NewScore;
            };

            FUpdateScoreParams Parms;
            Parms.NewScore = ScoreTotal;

            ScoreWidgetInstance->ProcessEvent(UpdateScoreFunc, &Parms);
        }
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

        //Appelle la fonction UpdateTimer dans WB_ScoreCollectible
        if (ScoreWidgetInstance)
        {
            UFunction* UpdateTimerFunc = ScoreWidgetInstance->FindFunction(FName("UpdateTimer"));

            if (UpdateTimerFunc)
            {
                struct FUpdateTimerParams
                {
                    int32 NewTime;
                };

                FUpdateTimerParams Parms;
                Parms.NewTime = RemainingTime;

                ScoreWidgetInstance->ProcessEvent(UpdateTimerFunc, &Parms);
            }
        }
    }
    else
    {
        EndCollectibleInstance = CreateWidget<UUserWidget>(GetWorld(), WB_EndCollectible);
        EndCollectibleInstance->AddToViewport();

        if (EndCollectibleInstance)
        {
            UFunction* GetFinalScoreFunc = EndCollectibleInstance->FindFunction(FName("GetFinalScore"));

            if (GetFinalScoreFunc)
            {
                struct FGetFinalScoreParams
                {
                    int32 FinalScore;
                };

                FGetFinalScoreParams Parms;
                Parms.FinalScore = ScoreTotal;

                EndCollectibleInstance->ProcessEvent(GetFinalScoreFunc, &Parms);
            }
        }
    }
}
