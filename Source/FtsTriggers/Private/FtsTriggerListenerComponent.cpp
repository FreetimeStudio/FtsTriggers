// Copyright 2017-2020 FreetimeStudio

#include "FtsTriggerListenerComponent.h"
#include "FtsTriggerInterface.h"
#include "FtsTriggerComponent.h"
#include "GameFramework/Actor.h"

DEFINE_LOG_CATEGORY(LogFtsTriggerListener);

UFtsTriggerListenerComponent::UFtsTriggerListenerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UFtsTriggerListenerComponent::Triggered(UFtsTriggerComponent* Trigger, UObject* Instigator)
{
	if (OnTriggered.IsBound())
	{
		OnTriggered.Broadcast(this, Trigger, Instigator);
	}
}

void UFtsTriggerListenerComponent::UnTriggered(UFtsTriggerComponent* Trigger, UObject* Instigator)
{
	if (OnUnTriggered.IsBound())
	{
		OnUnTriggered.Broadcast(this, Trigger, Instigator);
	}
}

bool UFtsTriggerListenerComponent::AddTrigger(UObject* InTrigger)
{
	auto TriggerComp = GetActualTrigger(InTrigger);
	if (!TriggerComp)
	{
		UE_LOG(LogFtsTriggerListener, Error, TEXT("UFtsTriggerListenerComponent::AddTrigger %s Cannot start listening to %s"), *GetNameSafe(GetOwner()), *GetNameSafe(InTrigger));
		return false;
	}

	if (ObservedTriggers.Contains(TriggerComp))
	{
		return true;
	}

	auto& TriggerDelegate = TriggerComp->GetTriggerDelegate();
	TriggerDelegate.AddDynamic(this, &UFtsTriggerListenerComponent::Triggered);
	auto& UnTriggerDelegate = TriggerComp->GetUnTriggerDelegate();
	UnTriggerDelegate.AddDynamic(this, &UFtsTriggerListenerComponent::UnTriggered);
	return true;
}

void UFtsTriggerListenerComponent::AddTriggers(TArray<UObject*> InTriggers)
{
	for (auto Trigger : InTriggers)
	{
		if (!AddTrigger(Trigger))
		{
			//TODO message
		}
	}
}

bool UFtsTriggerListenerComponent::RemoveTrigger(UObject* InTrigger)
{
	auto TriggerComp = GetActualTrigger(InTrigger);
	if (!TriggerComp)
	{
		return false;
	}

	if (!ObservedTriggers.Contains(TriggerComp))
	{
		return false;
	}

	auto& TriggerDelegate = TriggerComp->GetTriggerDelegate();
	TriggerDelegate.RemoveDynamic(this, &UFtsTriggerListenerComponent::Triggered);
	auto& UnTriggerDelegate = TriggerComp->GetUnTriggerDelegate();
	UnTriggerDelegate.RemoveDynamic(this, &UFtsTriggerListenerComponent::UnTriggered);
	return true;
}

void UFtsTriggerListenerComponent::RemoveTriggers(TArray<UObject*> InTriggers)
{
	for (auto Trigger : InTriggers)
	{
		if (!RemoveTrigger(Trigger))
		{
			UE_LOG(LogFtsTriggerListener, Error, TEXT("UFtsTriggerListenerComponent::RemoveTriggers %s unable to remove %s"), *GetNameSafe(GetOwner()), *GetNameSafe(Trigger));
		}
	}
}

UFtsTriggerComponent* UFtsTriggerListenerComponent::GetActualTrigger(UObject* InTrigger) const
{
	ensure(IsValid(InTrigger)); //Not sure yet how to handle it best
	if (!IsValid(InTrigger))
	{
		return nullptr;
	}

	if (!InTrigger->Implements<UFtsTriggerInterface>())
	{
		return nullptr;
	}

	return IFtsTriggerInterface::Execute_GetTriggerComponent(InTrigger);
}

bool UFtsTriggerListenerComponent::IsListeningToTrigger(UObject* InTrigger)
{
	const auto TriggerComp = GetActualTrigger(InTrigger);
	if (!TriggerComp)
	{
		return false;
	}

	return ObservedTriggers.Contains(TriggerComp);
}
