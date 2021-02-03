// Copyright 2017-2020 FreetimeStudio

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "FtsTriggerInterface.generated.h"

class UFtsTriggerComponent;

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UFtsTriggerInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class FTSTRIGGERS_API IFtsTriggerInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Trigger")
	UFtsTriggerComponent* GetTriggerComponent();
};
