// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

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

public:
    UFUNCTION(BlueprintCallable)
    void GetScore(int32 Score);

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ScoreTotal;
};