// Copyright 2017-2020 FreetimeStudio

#include "FtsTriggerSphere.h"
#include "FtsTriggerComponent.h"


AFtsTriggerSphere::AFtsTriggerSphere()
	: Super()
{
	PrimaryActorTick.bStartWithTickEnabled = false;

	TriggerComponent = CreateDefaultSubobject<UFtsTriggerComponent>(TEXT("TriggerComponent"));
}

void AFtsTriggerSphere::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	TriggerComponent->TryTrigger(OtherActor);
}

void AFtsTriggerSphere::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);

	TriggerComponent->TryUnTrigger(OtherActor);
}

UFtsTriggerComponent* AFtsTriggerSphere::GetTriggerComponent_Implementation()
{
	return TriggerComponent;
}




