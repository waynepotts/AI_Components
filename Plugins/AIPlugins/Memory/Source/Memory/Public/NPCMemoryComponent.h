// Copyright Wayne Potts 2024

#pragma once

#include "CoreMinimal.h"
#include "Templates/SharedPointer.h"
#include "MemoryComponent.h"
#include "NPCMemoryComponent.generated.h"

UENUM(BlueprintType)
enum class ERelationshipeType : uint8 {
	NONE = 0 UMETA(DisplayName = "NONE"),
	NEUTRAL = 1 UMETA(DisplayName = "NEUTRAL"),
	FRIEND = 2  UMETA(DisplayName = "FRIEND"),
	ENEMY = 3     UMETA(DisplayName = "ENEMY")
};
/**
 * Memory component which also defines the relationship to the owner of this component
 * e.g. if the other actor is a friend or enemy of this actor.
 * 
 * The order of precedence is
 * Refs > Specific classes > static classes
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MEMORY_API UNPCMemoryComponent : public UMemoryComponent
{
	GENERATED_BODY()
	
public:
	UNPCMemoryComponent();
	// Specific classes for this instance
	/**
	* Classes this actor considers to be friendly
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Memory/NPC")
	TArray < TSubclassOf<UObject>> Friendly;
	/**
	* Classes this actor considers to be an enemy
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Memory/NPC")
	TArray < TSubclassOf<UObject>> Enemy;
	/**
	* Classes this actor considers neutral, or should be ignored etc.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Memory/NPC")
	TArray < TSubclassOf<UObject>> Neutral;


	// Static classes
	/*
	* default that all actors of this class should use, the non-static version are 
	* used for specific actors e.g. if an actor has a debuff to consider all 
	* friendlies as enemies they should use the specific versions until the debuff wears off.
	*/
	static TArray < TSubclassOf<UObject>> FriendlyAll;
	static TArray < TSubclassOf<UObject>> EnemyAll;
	static TArray < TSubclassOf<UObject>> NeutralAll;

	// Refs to specific objects that this object has a relationship with N.B. these objects
	// dont need to be in the Friendly, Enemy or Neutral class arrays.
	/**
	* Specific object this actor considers friendly
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Memory/NPC")
	TArray <UObject*> FriendlyRefs;
	/**
	* Classes this actor considers to be an enemy
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Memory/NPC")
	TArray <UObject*> EnemyRefs;
	/**
	* Classes this actor considers neutral, or should be ignored etc.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Memory/NPC")
	TArray <UObject*> NeutralRefs;

	ERelationshipeType GetRelationship(UObject* Other);
	ERelationshipeType GetRelationshipRefs(UObject* Other);
	ERelationshipeType GetRelationshipSpecific(UObject* Other);
	ERelationshipeType GetRelationshipStatic(UObject* Other);
};
