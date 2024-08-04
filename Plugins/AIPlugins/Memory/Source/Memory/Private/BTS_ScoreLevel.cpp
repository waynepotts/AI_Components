// Copyright Wayne Potts 2024



#include "BTS_ScoreLevel.h"
#include <Kismet/KismetSystemLibrary.h>
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
//#include "Runtime/AIModule/Classes/BehaviorTree/Blackboard/BlackboardKeyType_Object.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Int.h"
#include "BehaviorAction.h"
#include "BehaviorScore.h"
#include "UseBehaviorComponent.h"


UBTS_ScoreLevel::UBTS_ScoreLevel()
{
	NodeName = "Score Level";

	bNotifyBecomeRelevant = true;	// necessarily!!!

	ActorKey.SelectedKeyName = FName("Actor Key");
	ActorKey.SelectedKeyType = UBlackboardKeyType_Object::StaticClass();

	LevelKey.SelectedKeyName = FName("Level Key");
	LevelKey.SelectedKeyType = UBlackboardKeyType_Int::StaticClass();
	Interval = 0.5f;	// Any value.
	RandomDeviation = 0.1f;
}
void UBTS_ScoreLevel::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::OnBecomeRelevant(OwnerComp, NodeMemory);

	UBlackboardComponent* CurrentBlackboard = OwnerComp.GetBlackboardComponent();

	
	APawn* AIPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (UKismetSystemLibrary::DoesImplementInterface(AIPawn, UBehaviorScore::StaticClass()))
	{
		int32 Level = CurrentBlackboard->GetValueAsInt(LevelKey.SelectedKeyName);
		if (AIPawn->GetClass()->ImplementsInterface(UBehaviorScore::StaticClass()))
		{
			FBehaviorAction Action = IBehaviorScore::Execute_ScoreLevel(AIPawn, Level);
			IBehaviorScore::Execute_SetLevelScore(AIPawn, Action);
		}
		
	}
}

void UBTS_ScoreLevel::OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::OnBecomeRelevant(OwnerComp, NodeMemory);

}
