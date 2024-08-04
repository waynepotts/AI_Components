// Copyright Wayne Potts 2024

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "UseBehaviorComponent.h"
#include "BTS_ScoreLevel.generated.h"

/**
 * 
 */
UCLASS()
class MEMORY_API UBTS_ScoreLevel : public UBTService
{
	GENERATED_BODY()
	
	UBTS_ScoreLevel();

	FBlackboardKeySelector ActorKey;
	FBlackboardKeySelector LevelKey;
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	virtual void OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
