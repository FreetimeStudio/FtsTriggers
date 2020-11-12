// Copyright 2017-2020 FreetimeStudio

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "FtsTriggerInterface.h"
#include "FtsTriggerBox.generated.h"

class UFtsTriggerComponent;

/**
 * 
 */
UCLASS()
class FTSTRIGGERS_API AFtsTriggerBox : public ATriggerBox, public IFtsTriggerInterface
{
	GENERATED_BODY()
	
private:
	UPROPERTY(VisibleAnywhere, Category="Trigger")
	UFtsTriggerComponent* TriggerComponent;

public:

	AFtsTriggerBox();

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;
	
	virtual UFtsTriggerComponent* GetTriggerComponent_Implementation() override;
};
