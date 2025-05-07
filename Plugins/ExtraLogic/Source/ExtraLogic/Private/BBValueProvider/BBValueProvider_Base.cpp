// Copyright 2025 Crippling Depression Ind. all rights reserved.


#include "BBValueProvider/BBValueProvider_Base.h"
#include "BehaviorTree/BlackboardComponent.h"


void UBBValueProvider_Bool::SetBlackboardValue(UBlackboardComponent* Blackboard) const
{
	if (ensureMsgf(Blackboard, TEXT("No blackboard provided!")))
	{
		Blackboard->SetValueAsBool(BlackboardKeyName, Value);
	}
}

void UBBValueProvider_Int::SetBlackboardValue(UBlackboardComponent* Blackboard) const
{
	if (ensureMsgf(Blackboard, TEXT("No blackboard provided!")))
	{
		Blackboard->SetValueAsInt(BlackboardKeyName, Value);
	}
}

void UBBValueProvider_Float::SetBlackboardValue(UBlackboardComponent* Blackboard) const
{
	if (ensureMsgf(Blackboard, TEXT("No blackboard provided!")))
	{
		Blackboard->SetValueAsFloat(BlackboardKeyName, Value);
	}
}

void UBBValueProvider_Vector::SetBlackboardValue(UBlackboardComponent* Blackboard) const
{
	if (ensureMsgf(Blackboard, TEXT("No blackboard provided!")))
	{
		Blackboard->SetValueAsVector(BlackboardKeyName, Value);
	}
}

void UBBValueProvider_Actor::SetBlackboardValue(UBlackboardComponent* Blackboard) const
{
	if (ensureMsgf(Blackboard, TEXT("No blackboard provided!")))
	{
		if (Value.IsValid())
		{
			Blackboard->SetValueAsObject(BlackboardKeyName, Value.Get());
		}
	}
}

void UBBValueProvider_Class::SetBlackboardValue(UBlackboardComponent* Blackboard) const
{
	if (ensureMsgf(Blackboard, TEXT("No blackboard provided!")))
	{
		Blackboard->SetValueAsClass(BlackboardKeyName, Value);
	}
}

void UBBValueProvider_Enum::SetBlackboardValue(UBlackboardComponent* Blackboard) const
{
	if (ensureMsgf(Blackboard, TEXT("No blackboard provided!")))
	{
		Blackboard->SetValueAsEnum(BlackboardKeyName, Value);
	}
}

void UBBValueProvider_Rotator::SetBlackboardValue(UBlackboardComponent* Blackboard) const
{
	if (ensureMsgf(Blackboard, TEXT("No blackboard provided!")))
	{
		Blackboard->SetValueAsRotator(BlackboardKeyName, Value);
	}
}

void UBBValueProvider_Name::SetBlackboardValue(UBlackboardComponent* Blackboard) const
{
	if (ensureMsgf(Blackboard, TEXT("No blackboard provided!")))
	{
		Blackboard->SetValueAsName(BlackboardKeyName, Value);
	}
}

void UBBValueProvider_String::SetBlackboardValue(UBlackboardComponent* Blackboard) const
{
	if (ensureMsgf(Blackboard, TEXT("No blackboard provided!")))
	{
		Blackboard->SetValueAsString(BlackboardKeyName, Value);
	}
}
