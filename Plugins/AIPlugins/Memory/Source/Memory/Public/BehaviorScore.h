// Copyright Wayne Potts 2024

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "BehaviorAction.h"
#include "BehaviorScore.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UBehaviorScore : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MEMORY_API IBehaviorScore
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.

public:

	virtual FBehaviorAction Score(int32 Level) const = 0;
	virtual void ScoreAll() const = 0;
};
