// Copyright 2017-2020 FreetimeStudio

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "FtsTriggerInterface.h"
#include "FtsTriggerVolume.generated.h"

class UFtsTriggerComponent;

/**
 * 
 */
UCLASS(Blueprintable)
class FTSTRIGGERS_API AFtsTriggerVolume : public ATriggerVolume, public IFtsTriggerInterface
{
	GENERATED_BODY()
	
private:
	UPROPERTY(VisibleAnywhere, Category = "Trigger")
	UFtsTriggerComponent* TriggerComponent;

public:

	AFtsTriggerVolume();

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

	virtual UFtsTriggerComponent* GetTriggerComponent_Implementation() override;
};
