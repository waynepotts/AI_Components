// Copyright Wayne Potts 2024

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "BehaviorScore.h"
#include "UseBehaviorComponent.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UUseBehaviorComponent : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MEMORY_API IUseBehaviorComponent
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual UBehaviorScore* ScoreBehavior(int32 Level) = 0;
};
