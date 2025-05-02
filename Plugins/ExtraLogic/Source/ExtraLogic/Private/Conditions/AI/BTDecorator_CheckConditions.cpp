// Copyright 2025 Crippling Depression Ind. all rights reserved.


#include "Conditions/AI/BTDecorator_CheckConditions.h"
#include "AIController.h"


UBTDecorator_CheckConditions::UBTDecorator_CheckConditions()
{
	NodeName = "Check Conditions";
	bCreateNodeInstance = true;
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
		if (Condition)
		{
			SetConditionOwner(OwnerComp, Condition);

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
	}

	return Result;
}

FString UBTDecorator_CheckConditions::GetStaticDescription() const
{
	if (Conditions.IsEmpty())
	{
		return "No conditions provided";
	}

	FString Description = "Processing: \n";
	for (auto const& Condition : Conditions)
	{
		if (Condition)
		{
			Description += Condition->GetConditionName() + "\n";
		}
	}
	Description.TrimEndInline();

	return Description;
}

void UBTDecorator_CheckConditions::SetConditionOwner(UBehaviorTreeComponent& OwnerComp, UBaseCondition* Condition) const
{
	APawn* Owner = Cast<AAIController>(OwnerComp.GetOwner())->GetPawn();

	if (!Condition->GetOwner())
	{
		Condition->SetOwner(Owner);
	}
}
