// Copyright 2017-2020 FreetimeStudio

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FtsTriggerListenerComponent.generated.h"

class UFtsTriggerListenerComponent;
class UFtsTriggerComponent;

DECLARE_LOG_CATEGORY_EXTERN(LogFtsTriggerListener, Log, All);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FFtsTriggerListenerDelegate, UFtsTriggerListenerComponent*, Listener, UFtsTriggerComponent*, Trigger, UObject*, Instigator);

UCLASS( ClassGroup=(Trigger), meta=(BlueprintSpawnableComponent) )
class FTSTRIGGERS_API UFtsTriggerListenerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFtsTriggerListenerComponent();

protected:
	// Called when the game starts
	//virtual void BeginPlay() override;
	//virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UFUNCTION()
	void Triggered(UFtsTriggerComponent* Trigger, UObject* Instigator);

	UFUNCTION()
	void UnTriggered(UFtsTriggerComponent* Trigger, UObject* Instigator);

	UPROPERTY(BlueprintReadOnly, Category = "Trigger")
	TArray<UFtsTriggerComponent*> ObservedTriggers;

	UFtsTriggerComponent* GetActualTrigger(UObject* InTrigger) const;

public:	
	UPROPERTY(BlueprintAssignable, Category = "Trigger")
	FFtsTriggerListenerDelegate OnTriggered;
	
	UPROPERTY(BlueprintAssignable, Category = "Trigger")
	FFtsTriggerListenerDelegate OnUnTriggered;
	
	UFUNCTION(BlueprintCallable, Category = "Trigger")
	bool AddTrigger(UObject* InTrigger);

	UFUNCTION(BlueprintCallable, Category = "Trigger")
	void AddTriggers(TArray<UObject*> InTriggers);


	UFUNCTION(BlueprintCallable, Category = "Trigger")
	bool RemoveTrigger(UObject* InTrigger);

	UFUNCTION(BlueprintCallable, Category = "Trigger")
	void RemoveTriggers(TArray<UObject*> InTriggers);


	UFUNCTION(BlueprintCallable, Category = "Trigger")
	bool IsListeningToTrigger(UObject* InTrigger);
};
