// Fill out your copyright notice in the Description page of Project Settings.


#include "Filter/FtsPlayerTriggerFilter.h"
#include "GameFramework/Pawn.h"

bool UFtsPlayerTriggerFilter::PassesFilter_Implementation(UObject* Object)
{
	const auto Pawn = Cast<APawn>(Object);
	if(!Pawn)
	{
		return false;
	}

	return Pawn->IsPlayerControlled();
}
