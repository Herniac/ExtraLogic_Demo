// Copyright 2025 Crippling Depression Ind. all rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BaseCondition.h"
#include "BTDecorator_CheckConditions.generated.h"

/**
 *	Allows execution flow when provided conditions are met.
 *	Also sets owning Character as conditions' owner if there is none.
 */

UCLASS()
class EXTRALOGIC_API UBTDecorator_CheckConditions : public UBTDecorator
{
	GENERATED_BODY()

public:
	UBTDecorator_CheckConditions();
	
protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
	virtual FString GetStaticDescription() const override;
	void SetConditionOwner(UBehaviorTreeComponent& OwnerComp, UBaseCondition* Condition) const;

	UPROPERTY(EditAnywhere, Category = "CheckConditions")
	EConditionMatchType MatchType;
	UPROPERTY(EditAnywhere, Category = "CheckConditions", Instanced)
	TArray<UBaseCondition*> Conditions;
};
