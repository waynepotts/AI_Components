// Copyright Wayne Potts 2024


#include "BehaviorComponent.h"

// Sets default values for this component's properties
UBehaviorComponent::UBehaviorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UBehaviorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UBehaviorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UBehaviorComponent::ScoreAll()
{
	TArray<FBehaviorAction> NewActions;
	for (int32 i = 0; i < Strategies.Num(); i++)
	{
		NewActions.Add(Score(i));
	}
	Actions = NewActions;
}
FBehaviorAction UBehaviorComponent::Score_Implementation(const int32 Level)
{
	FBehaviorAction Highest;
	float Priority{ 0.0f };
	for (const auto& Action : Strategies[Level].Strategies)
	{
		FBehaviorAction NewAction = Action->ScoreStrategy();
		if (NewAction.Priority > Priority)
		{
			Priority = NewAction.Priority;
			Highest = NewAction;
		}
	}
	return Highest;
}
FBehaviorAction UBehavior_Strategy::ScoreStrategy()
{
	return ReceiveScoreStrategy();
}


FBehaviorAction UBehavior_Strategy::ReceiveScoreStrategy_Implementation()
{
	return Action;
}

