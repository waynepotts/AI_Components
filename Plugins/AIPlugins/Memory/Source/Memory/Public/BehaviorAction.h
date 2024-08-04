// Copyright Wayne Potts 2024

#pragma once

#include "CoreMinimal.h"
#include "BehaviorAction.generated.h"

USTRUCT(BlueprintType)
struct MEMORY_API FBehaviorAction
{
    GENERATED_BODY()

    /**
    * There are three levels behavior action, Goal, Action
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Behavior")
    int32 Level{ 0 };

    /**
    * The priority of the action, the higher that this value is then the more likely it will be executed
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Behavior")
    double Priority{ 0.0 };

    /**
    * Used to identify what this behavior action is
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Behavior")
    FString Note;

    /**
    * The value of the action, this would determine what action occurs e.g. 0 = Move, 1 = Attack.
    * These values could come from an enum for clarity.
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Behavior")
    int32 Value{ 0 };
};