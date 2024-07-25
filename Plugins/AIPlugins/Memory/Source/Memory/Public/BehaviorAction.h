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
    * The priority of the action
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Behavior")
    float Priority{ 0.0f };

    /**
    * Used to identify what this behavior action is
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Behavior")
    FString Note;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Behavior")
    int32 Value{ 0 };
};