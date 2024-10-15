// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerStatsManager.h"

// Sets default values
APlayerStatsManager::APlayerStatsManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerStatsManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerStatsManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlayerStatsManager::InitializeStats(int32 playersnumber)
{
	UE_LOG(LogTemp, Warning, TEXT("j'ai initialize les stats !"));
	playersnumber = playersnumber;