// Copyright Wayne Potts 2024


#include "TestActorRangeBehavior_Strategy.h"
#include "Misc/AssertionMacros.h"
UTestActorRangeBehavior_Strategy::UTestActorRangeBehavior_Strategy()
{
	
}

FBehaviorAction UTestActorRangeBehavior_Strategy::ScoreStrategy()
{
	check(Actor != nullptr);
	check(OtherActor != nullptr);
	check(Range >= 0.0);
	FBehaviorAction Act = Super::ScoreStrategy();
	if (FVector::Distance(Actor->GetActorLocation(), OtherActor->GetActorLocation()) <= Range)
	{
		Act.Priority = PassScore > Act.Priority ? PassScore : Act.Priority;
	}
	return Act;
}
