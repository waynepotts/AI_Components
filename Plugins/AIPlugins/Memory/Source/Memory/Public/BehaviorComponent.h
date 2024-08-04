// Copyright Wayne Potts 2024

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BehaviorAction.h"
#include "BehaviorComponent.generated.h"





/**
* Used to create the behavior action value. This class would test if a goal is met,
* or would set the action priority based on the how close the goal is. e.g. we test 
* how far away the character is from the goal. A goal that is too far away would have a
* lower priority than a closer one.
*/
UCLASS(Blueprintable)
class MEMORY_API UBehavior_Strategy : public UObject
{
    GENERATED_BODY()

public:

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Behavior Strategy")
    FBehaviorAction Action;

    /**
    * Used to create the behavior action value
    */
    virtual FBehaviorAction ScoreStrategy();

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Behavior Strategy", meta = (DisplayName = "Score"))
    FBehaviorAction ReceiveScoreStrategy();

protected:
    /**
    * The value returned if this strategy passes
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Behavior Strategy")
    double PassScore{ 0.1 };
};
USTRUCT(BlueprintType)
struct MEMORY_API FBehaviorActionArray
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Behavior")
    TArray<UBehavior_Strategy*> Strategies;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MEMORY_API UBehaviorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBehaviorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Behavior Component")
    TArray<FBehaviorAction> Actions;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Behavior Component")
    TArray <FBehaviorActionArray> Strategies;
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    /**
    * Score all levels of action and update the Actions array
    */
    UFUNCTION(BlueprintCallable, Category = "Behavior Component")
    void ScoreAll();

    /**
    * Score a level of action, the result would need to be added to the Actions array
    */
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Behavior Component")
    FBehaviorAction Score(int32 Level);
};
