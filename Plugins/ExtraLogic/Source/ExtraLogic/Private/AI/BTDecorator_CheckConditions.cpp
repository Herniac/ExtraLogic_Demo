// Copyright 2025 Crippling Depression Ind. all rights reserved.


#include "AI/BTDecorator_CheckConditions.h"

UBTDecorator_CheckConditions::UBTDecorator_CheckConditions()
{
	NodeName = "Check Conditions";
}

bool UBTDecorator_CheckConditions::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	if (Conditions.IsEmpty())
	{
		return false;
	}

	bool Result = MatchType == EConditionMatchType::ANY ? false : true;

	for (auto const& Condition : Conditions)
	{
		if (Condition->CheckCondition())
		{
			if (MatchType == EConditionMatchType::ANY)
			{
				return true;
			}
		}
		else
		{
			if (MatchType == EConditionMatchType::ALL)
			{
				return false;
			}
		}	
	}

	return Result;
}

FString UBTDecorator_CheckConditions::GetStaticDescription() const
{
	if (Conditions.IsEmpty())
	{
		return "No conditions provided";
	}

	FString Description = "Processing: ";
	for (auto const& Condition : Conditions)
	{
		Description += Condition->GetConditionName() + "\n";
	}
	Description.TrimEndInline();

	return Description;
}
