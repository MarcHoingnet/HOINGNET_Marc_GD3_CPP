// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GM_Collectible.generated.h"

/**
 * 
 */
UCLASS()
class COURS_CPP_API AGM_Collectible : public AGameModeBase
{
	GENERATED_BODY()
protected:
    virtual void BeginPlay() override;

public:
    UFUNCTION(BlueprintCallable)
    void GetScore(int32 Score);

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ScoreTotal;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Timer")
    int32 TimerDuration = 20;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Timer")
    int32 RemainingTime;


    FTimerHandle TimerHandle;


    UFUNCTION(BlueprintCallable, category = "Timer")
    void StartTimer();

    UFUNCTION(BlueprintCallable, category = "Timer")
    void UpdateTimer();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> WB_ScoreCollectible;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
    UUserWidget* ScoreWidgetInstance; 

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> WB_EndCollectible;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
    UUserWidget* EndCollectibleInstance;

};