// Copyright 2017-2020 FreetimeStudio

#include "FtsTriggerComponent.h"
#include "Filter/FtsTriggerFilterBase.h"

UFtsTriggerComponent::UFtsTriggerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}

FFtsTriggerDelegate& UFtsTriggerComponent::GetTriggerDelegate()
{
	return OnTriggered;
}

FFtsTriggerDelegate& UFtsTriggerComponent::GetUnTriggerDelegate()
{
	return OnUnTriggered;
}

UFtsTriggerComponent* UFtsTriggerComponent::GetTriggerComponent_Implementation()
{
	return this;
}

bool UFtsTriggerComponent::PassesTriggerFilter(UObject* Object)
{
	if(Filters.Num() == 0)
	{
		return true;
	}

	for (auto Filter : Filters)
	{
		if (!IsValid(Filter))
		{
			continue;
		}

		if (Filter->PassesFilter(Object))
		{
			return true;
		}
	}

	return false;
}

bool UFtsTriggerComponent::TryTrigger(UObject* Instigator)
{
	if (!PassesTriggerFilter(Instigator))
	{
		return false;
	}

	Trigger(Instigator);
	return true;
}

bool UFtsTriggerComponent::TryUnTrigger(UObject* Instigator)
{
	if (!PassesTriggerFilter(Instigator))
	{
		return false;
	}

	UnTrigger(Instigator);
	return true;
}

void UFtsTriggerComponent::Trigger(UObject* Instigator)
{
	//UE_LOG(LogTemp, Log, TEXT("TRIGGERED"));
	if (OnTriggered.IsBound())
	{
		//UE_LOG(LogTemp, Log, TEXT("BOUND"));
		OnTriggered.Broadcast(this, Instigator);
	}
}

void UFtsTriggerComponent::UnTrigger(UObject* Instigator)
{
	//UE_LOG(LogTemp, Log, TEXT("UNTRIGGERED"));
	if (OnUnTriggered.IsBound())
	{
		//UE_LOG(LogTemp, Log, TEXT("BOUND"));
		OnUnTriggered.Broadcast(this, Instigator);
	}
}