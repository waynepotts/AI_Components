// Copyright Wayne Potts 2024

#pragma once

#include "CoreMinimal.h"
#include "BehaviorComponent.h"
#include "TestLocationRange_Strategy.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class MEMORY_API UTestLocationRange_Strategy : public UBehavior_Strategy
{
	GENERATED_BODY()
	
public:
	UTestLocationRange_Strategy();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test Location Range")
	double Range{ 1000.0 };
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test Location Range")
	FVector Location = FVector(0, 0, 0);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Test Location Range")
	FVector OtherLocation = FVector(0, 0, 0);
	FBehaviorAction ScoreStrategy() override;
};
