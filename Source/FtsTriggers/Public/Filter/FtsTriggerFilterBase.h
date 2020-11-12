// Copyright 2017-2020 FreetimeStudio

#pragma once

#include "CoreMinimal.h"
#include "FtsTriggerFilterBase.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew, AutoExpandCategories = ("Filter"))
class FTSTRIGGERS_API UFtsTriggerFilterBase : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, Category="Filter")
	bool PassesFilter(UObject* Object);
	virtual bool PassesFilter_Implementation(UObject* Object);
};
