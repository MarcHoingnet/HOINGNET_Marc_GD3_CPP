// Fill out your copyright notice in the Description page of Project Settings.


#include "MemoryGM.h"

void AMemoryGM::UpdateScore(int32 value)
{
	MemoryScore = MemoryScore + value;
}

bool AMemoryGM::TestPair(int32 FirstWindowValue, int32 SecondWindowvalue)
{
	bool result = false;

	result = (FirstWindowValue == SecondWindowvalue);

	return result;
}