// Copyright 2017-2020 FreetimeStudio

#include "FtsTriggerCapsule.h"
#include "FtsTriggerComponent.h"


AFtsTriggerCapsule::AFtsTriggerCapsule()
	: Super()
{
	PrimaryActorTick.bStartWithTickEnabled = false;

	TriggerComponent = CreateDefaultSubobject<UFtsTriggerComponent>(TEXT("TriggerComponent"));
}

void AFtsTriggerCapsule::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	TriggerComponent->TryTrigger(OtherActor);
}

void AFtsTriggerCapsule::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);

	TriggerComponent->TryUnTrigger(OtherActor);
}

UFtsTriggerComponent* AFtsTriggerCapsule::GetTriggerComponent_Implementation()
{
	return TriggerComponent;
}




