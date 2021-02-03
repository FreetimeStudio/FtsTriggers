// Copyright 2017-2020 FreetimeStudio

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerSphere.h"
#include "FtsTriggerInterface.h"
#include "FtsTriggerSphere.generated.h"

class UFtsTriggerComponent;

/**
 * 
 */
UCLASS()
class FTSTRIGGERS_API AFtsTriggerSphere : public ATriggerSphere, public IFtsTriggerInterface
{
	GENERATED_BODY()
	
private:
	UPROPERTY(VisibleAnywhere, Category = "Trigger")
	UFtsTriggerComponent* TriggerComponent;

public:

	AFtsTriggerSphere();

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

	virtual UFtsTriggerComponent* GetTriggerComponent_Implementation() override;
};
