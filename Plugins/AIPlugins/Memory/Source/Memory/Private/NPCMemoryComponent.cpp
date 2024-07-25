// Copyright Wayne Potts 2024


#include "NPCMemoryComponent.h"

TArray<TSubclassOf<UObject>> UNPCMemoryComponent::NeutralAll;// = { UClass::StaticClass(), UObject::StaticClass() };
TArray<TSubclassOf<UObject>> UNPCMemoryComponent::FriendlyAll; // = { UClass::StaticClass(), UObject::StaticClass() };
TArray<TSubclassOf<UObject>> UNPCMemoryComponent::EnemyAll; // = { UClass::StaticClass(), UObject::StaticClass() };
UNPCMemoryComponent::UNPCMemoryComponent()
{
}

ERelationshipeType UNPCMemoryComponent::GetRelationship(UObject* Other)
{
	ERelationshipeType Type{ ERelationshipeType::NONE };
	Type = GetRelationshipRefs(Other);
	if (Type < ERelationshipeType::NEUTRAL)
	{
		Type = GetRelationshipSpecific(Other);
		if (Type < ERelationshipeType::NEUTRAL)
		{
			Type = GetRelationshipStatic(Other);
		}
	}
	return Type;
}

ERelationshipeType UNPCMemoryComponent::GetRelationshipRefs(UObject* Other)
{
	ERelationshipeType Type{ ERelationshipeType::NONE };
	if (NeutralRefs.Contains(Other))
	{
		Type = ERelationshipeType::NEUTRAL;
	}
	if (FriendlyRefs.Contains(Other))
	{
		Type = ERelationshipeType::FRIEND;
	}
	if (EnemyRefs.Contains(Other))
	{
		Type = ERelationshipeType::ENEMY;
	}
	return Type;
}

ERelationshipeType UNPCMemoryComponent::GetRelationshipSpecific(UObject* Other)
{
	if (Neutral.Contains(Other->GetClass())) 
	{
		return ERelationshipeType::NEUTRAL;
	}
	if (Friendly.Contains(Other->GetClass()))
	{
		return ERelationshipeType::FRIEND;
	}
	if (Enemy.Contains(Other->GetClass()))
	{
		return ERelationshipeType::ENEMY;
	}
	return ERelationshipeType::NONE;
}

ERelationshipeType UNPCMemoryComponent::GetRelationshipStatic(UObject* Other)
{
	if(NeutralAll.Contains(Other->GetClass()))
	{
		return ERelationshipeType::NEUTRAL;
	}
	if(FriendlyAll.Contains(Other->GetClass()))
	{
		return ERelationshipeType::FRIEND;
	}
	if(EnemyAll.Contains(Other->GetClass()))
	{
		return ERelationshipeType::ENEMY;
	}
	return ERelationshipeType::NONE;
}
