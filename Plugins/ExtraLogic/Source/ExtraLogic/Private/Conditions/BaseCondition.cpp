// Copyright 2025 Crippling Depression Ind. all rights reserved.


#include "Conditions/BaseCondition.h"


bool UBaseCondition::CheckCondition() const
{
	return bInversed ? !Condition() : Condition();
}

UWorld* UBaseCondition::GetWorld() const
{
	UObject* Outer = GetOuter();
	while (Outer)
	{
		if (AActor* Actor = Cast<AActor>(Outer))
		{
			return Actor->GetWorld();
		}
		if (UActorComponent* Comp = Cast<UActorComponent>(Outer))
		{
			return Comp->GetWorld();
		}
		if (UWorld* World = Cast<UWorld>(Outer))
		{
			return World;
		}

		Outer = Outer->GetOuter();
	}

	return nullptr;
}

void UBlueprintBaseCondition::K2_SetOwner(AActor* NewOwner)
{
	SetOwner(NewOwner);
}

AActor* UBlueprintBaseCondition::K2_GetOwner() const
{
	return GetOwner();
}

bool UBlueprintBaseCondition::Condition() const
{
	return K2_Condition();
}
