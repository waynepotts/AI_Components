// Copyright Wayne Potts 2024

#pragma once

#include "CoreMinimal.h"
#include "BehaviorComponent.h"
#include "TestActorRangeBehavior_Strategy.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class MEMORY_API UTestActorRangeBehavior_Strategy : public UBehavior_Strategy
{
	GENERATED_BODY()

public:
	UTestActorRangeBehavior_Strategy();

	FBehaviorAction ScoreStrategy() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test Actor Range")
	AActor* OtherActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test Actor Range")
	AActor* Actor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test Actor Range")
	float Range{ 100.0f};
};
