// Copyright Wayne Potts 2024

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "BehaviorAction.h"
#include "BehaviorScore.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, BlueprintType)
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

	/**
	* Used to calculate the score for the behavior action
	*/
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Score Behavior")
	FBehaviorAction ScoreLevel(int32 Level);

	/**
	* Gets the current behavior action
	*/
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Score Behavior")
	FBehaviorAction GetLevelScore(int32 Level);

	/**
	* Updates the current behavior action
	*/
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Score Behavior")
	void SetLevelScore(FBehaviorAction Action);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Score Behavior")
	 void ScoreAll();
};
