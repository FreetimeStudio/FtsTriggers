// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Filter/FtsTriggerFilterBase.h"
#include "FtsPlayerTriggerFilter.generated.h"

/**
 * 
 */
UCLASS(meta=(DisplayName="Player"))
class FTSTRIGGERS_API UFtsPlayerTriggerFilter : public UFtsTriggerFilterBase
{
	GENERATED_BODY()

public:
	virtual bool PassesFilter_Implementation(UObject* Object) override;
};

