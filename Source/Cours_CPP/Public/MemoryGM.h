// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Window.h"
#include "GameFramework/GameModeBase.h"
#include "MemoryGM.generated.h"

/**
 * 
 */
UCLASS()
class COURS_CPP_API AMemoryGM : public AGameModeBase
{
	GENERATED_BODY()
	

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Memory")
	int32 MemoryScore;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Memory")
	AWindow* PreviousWindow;

public :
	UFUNCTION(BlueprintCallable)
	void UpdateScore(int32 value);

	UFUNCTION(BlueprintCallable)
	bool TestPair(int32 FirstWindowValue, int32 SecondWindowvalue);
};
