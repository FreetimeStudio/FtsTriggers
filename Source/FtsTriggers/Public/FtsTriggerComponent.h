// Copyright 2017-2020 FreetimeStudio

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FtsTriggerInterface.h"
#include "FtsTriggerComponent.generated.h"

class UFtsTriggerFilterBase;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FFtsTriggerDelegate, UFtsTriggerComponent*, Trigger, UObject*, Instigator);

UCLASS( ClassGroup=(Trigger), meta=(BlueprintSpawnableComponent) )
class FTSTRIGGERS_API UFtsTriggerComponent : public UActorComponent, public IFtsTriggerInterface
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFtsTriggerComponent();

//protected:
//	// Called when the game starts
//	virtual void BeginPlay() override;

private:
	/**
		Holds the trigger event delegate.
		Giving Blueprint access to this private variable allows Blueprint scripts to bind to the event.
	*/
	UPROPERTY(BlueprintAssignable, Category = "Trigger", meta = (AllowPrivateAccess = true))
	FFtsTriggerDelegate OnTriggered;

	UPROPERTY(BlueprintAssignable, Category = "Trigger", meta = (AllowPrivateAccess = true))
	FFtsTriggerDelegate OnUnTriggered;

	UPROPERTY(EditAnywhere, Instanced, Category = "Trigger", meta = (AllowPrivateAccess = true))
	TArray<UFtsTriggerFilterBase*> Filters;

public:
	FFtsTriggerDelegate& GetTriggerDelegate();
	FFtsTriggerDelegate& GetUnTriggerDelegate();

	virtual UFtsTriggerComponent* GetTriggerComponent_Implementation() override;

	UFUNCTION(BlueprintCallable, Category = "Trigger")
	bool PassesTriggerFilter(UObject* Object);

	UFUNCTION(BlueprintCallable, Category = "Trigger")
	bool TryTrigger(UObject* Instigator);

	UFUNCTION(BlueprintCallable, Category = "Trigger")
	bool TryUnTrigger(UObject* Instigator);

protected:
	UFUNCTION(BlueprintCallable, Category = "Trigger")
	void Trigger(UObject* Instigator);

	UFUNCTION(BlueprintCallable, Category = "Trigger")
	void UnTrigger(UObject* Instigator);
};
