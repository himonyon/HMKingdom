﻿// Copyright Epic Games, Inc. All Rights Reserved.
#pragma once

#include "GameplayTask.h"
#include "GameplayTaskTransition.h"
#include "GameplayActuationState.h"
#include "GameplayActuationStateProvider.h"
#include "GameplayTask_SuddenTurnTransition.generated.h"

class UCharacterMovementComponent;

USTRUCT(BlueprintType)
struct GAMEPLAYINTERACTIONSMODULE_API FGameplayTransitionDesc_SuddenTurn : public FGameplayTransitionDesc
{
	GENERATED_BODY()

	virtual UGameplayTask* MakeTransitionTask(const FMakeGameplayTransitionTaskContext& Context) const override; 
};

UCLASS()
class GAMEPLAYINTERACTIONSMODULE_API UGameplayTask_SuddenTurnTransition : public UGameplayTask, public IGameplayTaskTransition, public IGameplayActuationStateProvider
{
	GENERATED_BODY()

public:
	UGameplayTask_SuddenTurnTransition(const FObjectInitializer& ObjectInitializer);

protected:
	/** IGameplayActuationStateProvider */
	virtual FConstStructView GetActuationState() const override
	{
		return FConstStructView::Make(ActuationState);
	}

	/** IGameplayTaskTransition */
	virtual FGameplayTransitionCompleted& GetTransitionCompleted() override { return OnTransitionCompleted; };

	virtual void Activate() override;
	virtual void ExternalCancel() override;
	virtual void TickTask(float DeltaTime) override;

	UPROPERTY()
	TObjectPtr<UCharacterMovementComponent> MovementComponent = nullptr;

	FGameplayTransitionCompleted OnTransitionCompleted;

	FGameplayActuationState_MovingTransition ActuationState;
	float BreakingDistance = 0.0f;
	FVector StartHeadingDirection = FVector::ZeroVector;
	bool bCompleted = false;

	friend struct FGameplayTransitionDesc_SuddenTurn;
};
