// Copyright Wayne Potts 2024

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include <Runtime/AIModule/Classes/BehaviorTree/BehaviorTreeComponent.h>
#include <Runtime/AIModule/Classes/BehaviorTree/BehaviorTreeTypes.h>
#include "BTS_CheckRange.generated.h"



/**
 * 
 */
UCLASS()
class MEMORY_API UBTS_CheckRange : public UBTService
{
	GENERATED_BODY()
	
public:
	FBlackboardKeySelector BlackboardKey;
	UBTS_CheckRange();
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	virtual void OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
