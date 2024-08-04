// Copyright Wayne Potts 2024


#include "TestLocationRange_Strategy.h"
#include "Misc/AssertionMacros.h"
UTestLocationRange_Strategy::UTestLocationRange_Strategy()
{
}

FBehaviorAction UTestLocationRange_Strategy::ScoreStrategy()
{
	check(Location != OtherLocation);
	FBehaviorAction Act = Super::ScoreStrategy();
	if(FVector::Distance(Location, OtherLocation) <= Range)
	{
		Act.Priority = PassScore > Act.Priority ? PassScore : Act.Priority;
	}
	return Act;
}
