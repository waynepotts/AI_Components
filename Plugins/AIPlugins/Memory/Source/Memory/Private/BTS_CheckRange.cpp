// Copyright Wayne Potts 2024


#include "BTS_CheckRange.h"
#include <Runtime/AIModule/Classes/BehaviorTree/Blackboard/BlackboardKeyType.h>
#include <Runtime/AIModule/Classes/BehaviorTree/Blackboard/BlackboardKeyType_Vector.h>
UBTS_CheckRange::UBTS_CheckRange()
{
	NodeName = "My Service";

	bNotifyBecomeRelevant = true;	// necessarily!!!
	//bNotifyCeaseRelevant = true;

	// accept only actors and vectors
	//BlackboardKey.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(UBTService_MyService, BlackboardKey));

	BlackboardKey.SelectedKeyName = FName("NameOfKey");
	BlackboardKey.SelectedKeyType = UBlackboardKeyType_Vector::StaticClass();

	Interval = 0.5f;	// Any value.
	RandomDeviation = 0.f;
}

void UBTS_CheckRange::OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::OnBecomeRelevant(OwnerComp, NodeMemory);
}

void UBTS_CheckRange::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}
