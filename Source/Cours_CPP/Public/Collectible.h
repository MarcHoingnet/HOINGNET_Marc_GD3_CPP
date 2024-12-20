// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Collectible.generated.h"

UCLASS()
class COURS_CPP_API ACollectible : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACollectible();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsBonus;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ScoreBonus = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ScoreMalus = -10;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void PickUp(int32& Score);

};
