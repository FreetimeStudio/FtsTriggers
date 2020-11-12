// Copyright 2017-2020 FreetimeStudio

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerCapsule.h"
#include "FtsTriggerInterface.h"
#include "FtsTriggerCapsule.generated.h"

class UFtsTriggerComponent;

/**
 * 
 */
UCLASS()
class FTSTRIGGERS_API AFtsTriggerCapsule : public ATriggerCapsule, public IFtsTriggerInterface
{
	GENERATED_BODY()
	
private:
	UPROPERTY(VisibleAnywhere, Category = "Trigger")
	UFtsTriggerComponent* TriggerComponent;

public:

	AFtsTriggerCapsule();

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

	virtual UFtsTriggerComponent* GetTriggerComponent_Implementation() override;
};
