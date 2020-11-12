// Copyright 2017-2020 FreetimeStudio

#include "FtsTriggerBox.h"
#include "FtsTriggerComponent.h"


AFtsTriggerBox::AFtsTriggerBox()
	: Super()
{
	PrimaryActorTick.bStartWithTickEnabled = false;

	TriggerComponent = CreateDefaultSubobject<UFtsTriggerComponent>(TEXT("TriggerComponent"));
}

void AFtsTriggerBox::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	TriggerComponent->TryTrigger(OtherActor);
}

void AFtsTriggerBox::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);

	TriggerComponent->TryUnTrigger(OtherActor);
}

UFtsTriggerComponent* AFtsTriggerBox::GetTriggerComponent_Implementation()
{
	return TriggerComponent;
}
