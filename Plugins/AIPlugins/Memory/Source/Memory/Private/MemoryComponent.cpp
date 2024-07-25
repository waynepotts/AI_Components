// Fill out your copyright notice in the Description page of Project Settings.


#include "MemoryComponent.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UMemoryComponent::UMemoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	// ...
}


// Called when the game starts
void UMemoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMemoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UMemoryComponent::AddMemory(const FMemoryStruct& Memory)
{
	Memories.Emplace(Memory);
	OnAddMemory.Broadcast(Memory, this);
}

const void UMemoryComponent::RemoveMemory(const FMemoryStruct& Memory) 
{
	Memories.Remove(Memory);
	OnRemoveMemory.Broadcast(Memory, this);
}

void UMemoryComponent::UpdateMemory()
{
	/*TArray<FMemoryStruct> NewMemories;
	for (auto& Memory : Memories)
	{
		if (Memory.ExpireTime <= 0.0f || Memory.ExpireTime < GetWorld()->GetTimeSeconds())
		{
			if (Memory.Object != nullptr && Memory.Object->IsValidLowLevel())
			{
				NewMemories.Emplace(Memory);
			}
		}
	}
	Memories = NewMemories;*/
	const double Time{ GetWorld()->GetTimeSeconds() };
	Memories = Memories.FilterByPredicate([Time](const FMemoryStruct& Memory) { 
		return (Memory.ExpireTime <= 0.0f || Memory.ExpireTime < Time) &&
			Memory.Object != nullptr && Memory.Object->IsValidLowLevel(); });
}

TArray<FMemoryStruct> UMemoryComponent::GetMemoriesWithObject(const UObject* Object)
{
	/*TArray<FMemoryStruct> FoundMemories;
	for (auto& Memory : Memories)
	{
		if (Memory.Object == Object)
		{
			FoundMemories.Emplace(Memory);
		}
	}
	return FoundMemories;*/
	return Memories.FilterByPredicate([Object](const FMemoryStruct& Memory) 
		{ return Memory.Object == Object; });
}

TArray<FMemoryStruct> UMemoryComponent::GetMemoriesWithSource(const EMemorySource Source)
{
	/*TArray<FMemoryStruct> FoundMemories;
	for (auto& Memory : Memories)
	{
		if (Memory.Source == Source)
		{
			FoundMemories.Emplace(Memory);
		}
	}
	return FoundMemories;*/
	return Memories.FilterByPredicate([Source](const FMemoryStruct& Memory) 
		{ return Memory.Source == Source; });
}

TArray<FMemoryStruct> UMemoryComponent::GetMemoriesInRadius(const FVector& Location, const double Radius)
{
	return Memories.FilterByPredicate(
		[Location, Radius](const FMemoryStruct& Memory) 
		{
			return FVector::Distance(Memory.Location, Location) < Radius; 
		});
}

void UMemoryComponent::RemoveMemoriesWithObject(const UObject* Object)
{
	/*TArray<FMemoryStruct> FoundMemories;
	for (auto& Memory : Memories)
	{
		if (Memory.Object != Object)
		{
			FoundMemories.Emplace(Memory);
		}
	}
	Memories = FoundMemories;*/
	Memories = Memories.FilterByPredicate([Object]
	(const FMemoryStruct& Memory) { return Memory.Object != Object; });
}

void UMemoryComponent::RemoveMemoriesWithSource(const EMemorySource Source)
{
	/*TArray<FMemoryStruct> FoundMemories;
	for (auto& Memory : Memories)
	{
		if (Memory.Source != Source)
		{
			FoundMemories.Emplace(Memory);
		}
	}
	Memories = FoundMemories;*/
	Memories = Memories.FilterByPredicate([Source]
	(const FMemoryStruct& Memory) { return Memory.Source != Source; });
}

void UMemoryComponent::RemoveMemoriesInRadius(const FVector& Location, double Radius)
{
	Memories = Memories.FilterByPredicate([Location, Radius	]
	(const FMemoryStruct& Memory) 
		{ return FVector::Distance(Memory.Location, Location) > Radius; });
}

void UMemoryComponent::ClearMemories()
{
	Memories.Empty();
}

bool UMemoryComponent::IsValidMemory_Implementation(const FMemoryStruct& Memory)
{
	if (Memory.Object == nullptr || !Memory.Object->IsValidLowLevel())
	{
		return false;
	}
	if (Memory.ExpireTime > 0.0f && Memory.ExpireTime < GetWorld()->GetTimeSeconds())
	{
		return false;
	}
	return true;
}

