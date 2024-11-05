// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Window.generated.h"

UCLASS()
class COURS_CPP_API AWindow : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AWindow();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsClickable = true;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void TurnWindow();

	
};