// Copyright Wayne Potts 2024.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MemoryComponent.generated.h"

UENUM(BlueprintType)
enum class EMemorySource : uint8 {
    NONE = 0 UMETA(DisplayName = "NONE"),
    HEARING = 1 UMETA(DisplayName = "HEARD"),
    SEEN = 2  UMETA(DisplayName = "SEEN"),
    TOUCHED = 3     UMETA(DisplayName = "TOUCHED"),
    ACTOR = 4 UMETA(DisplayName = "ACTOR"),
    EVENT = 5 UMETA(DisplayName = "EVENT"),
    DAMAGED = 6 UMETA(DisplayName = "DAMAGED")
};



USTRUCT(BlueprintType)
struct MEMORY_API FMemoryStruct
{
    GENERATED_BODY()

    /**
    * Where this memory came from
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Memory")
    EMemorySource Source = EMemorySource::NONE;

    /**
    * The time when this memory will expire. Less than 0 means never expire.
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Memory")
    float ExpireTime{ 0.0f };

    /**
    * The location of the memory
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Memory")
    FVector Location;


    /**
    * What object is associated with this memory.
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Memory")
    TWeakObjectPtr<UObject> Object = nullptr;

    bool operator==(const FMemoryStruct& Other) const
    {
        return Source == Other.Source && ExpireTime == Other.ExpireTime && Location == Other.Location && Object == Other.Object;
    }
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAddedMemory, const FMemoryStruct&, NewMemory, UObject*, Source);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FRemovedMemory, const FMemoryStruct&, OldMemory, UObject*, Source);
/**
* Base memory component used for controllers to remember things like where they last saw an actor.
*/
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MEMORY_API UMemoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMemoryComponent();
    UPROPERTY(BlueprintAssignable)
	FAddedMemory OnAddMemory;
    UPROPERTY(BlueprintAssignable)
    FRemovedMemory OnRemoveMemory;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Memory Component")
    TArray<FMemoryStruct> Memories;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	/**
	* Add a memory to this component
	*/
	UFUNCTION(BlueprintCallable, Category = "Memory Component")
	void AddMemory(const FMemoryStruct& Memory);

	/**
	* Remove a memory from this component
	*/
	UFUNCTION(BlueprintCallable, Category = "Memory Component")
	const void RemoveMemory(const FMemoryStruct& Memory);

    /**
    * Removes expired memories
    */
    UFUNCTION(BlueprintCallable, Category = "Memory Component")
    void UpdateMemory();


	/**
	* Returns all memories for an object
	*/
	UFUNCTION(BlueprintCallable, Category = "Memory Component")
	TArray<FMemoryStruct> GetMemoriesWithObject(const UObject* Object);

    /**
    * Returns all memories with source
	*/
	UFUNCTION(BlueprintCallable, Category = "Memory Component")
	TArray<FMemoryStruct> GetMemoriesWithSource(const EMemorySource Source);

    /**
    * Returns all memories in radius
    */
    UFUNCTION(BlueprintCallable, Category = "Memory Component")
    TArray<FMemoryStruct> GetMemoriesInRadius(const FVector& Location, double Radius);

    /**
    * Returns all memories for an object
    */
    UFUNCTION(BlueprintCallable, Category = "Memory Component")
    void RemoveMemoriesWithObject(const UObject* Object);

    /**
    * Returns all memories with source
    */
    UFUNCTION(BlueprintCallable, Category = "Memory Component")
    void RemoveMemoriesWithSource(const EMemorySource Source);

    /**
    * Returns all memories in radius
    */
    UFUNCTION(BlueprintCallable, Category = "Memory Component")
    void RemoveMemoriesInRadius(const FVector& Location, double Radius);

    /**
    * Clear all memories
    */
	UFUNCTION(BlueprintCallable, Category = "Memory Component")
	void ClearMemories();

    UFUNCTION(BlueprintNativeEvent, Category = "Memory Component")
    bool IsValidMemory(const FMemoryStruct& Memory);

};
