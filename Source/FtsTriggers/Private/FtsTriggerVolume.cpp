// Copyright 2017-2020 FreetimeStudio

#include "FtsTriggerVolume.h"
#include "FtsTriggerComponent.h"


AFtsTriggerVolume::AFtsTriggerVolume()
	: Super()
{
	PrimaryActorTick.bStartWithTickEnabled = false;

	TriggerComponent = CreateDefaultSubobject<UFtsTriggerComponent>(TEXT("TriggerComponent"));
}

void AFtsTriggerVolume::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	TriggerComponent->TryTrigger(OtherActor);
}

void AFtsTriggerVolume::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);

	TriggerComponent->TryUnTrigger(OtherActor);
}

UFtsTriggerComponent* AFtsTriggerVolume::GetTriggerComponent_Implementation()
{
	return TriggerComponent;
}




