// Copyright 2025 Crippling Depression Ind. all rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BaseCondition.generated.h"

/**
 *	Can be used to specify the way of handling multiple conditions.
 *	@see BTDecorator_CheckConditions
 */
UENUM(BlueprintType)
enum class EConditionMatchType : uint8
{
	ALL,
	ANY
};

/**
 *	This is the base class for condition objects. Derived classes should override
 *	the Condition() function. I also suggest using conditions as Instanced objects
 *	@see BTDecorator_CheckConditions
 */
UCLASS(Abstract, EditInlineNew)
class EXTRALOGIC_API UBaseCondition : public UObject
{
	GENERATED_BODY()

public:
	/** Call this function externally for condition check. It alters the result based on bInversed property */
	bool CheckCondition() const;
	/** Overriden to allow latent functions */
	virtual class UWorld* GetWorld() const override;
	/** */
	FString GetConditionName() const { return ConditionName; }
	/** */
	void SetOwner(AActor* NewOwner) { Owner = NewOwner; }
	/** */
	AActor* GetOwner() const { return Owner.Get(); }

protected:
	/** Body of the condition steering logic */
	virtual bool Condition() const PURE_VIRTUAL(UBaseCondition::CheckCondition, return false;);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Logic")
	FString ConditionName = "Base Condition";
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Logic")
	uint8 bInversed : 1;
	
	TWeakObjectPtr<AActor> Owner;
};

UCLASS(Blueprintable, Abstract, EditInlineNew)
class EXTRALOGIC_API UBlueprintBaseCondition : public UBaseCondition
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category = "Logic", meta = (DisplayName = "Condition"))
	bool K2_Condition() const;
	UFUNCTION(BlueprintCallable, Category = "Logic", meta = (DisplayName = "SetOwner"))
	void K2_SetOwner(AActor* NewOwner);
	UFUNCTION(BlueprintPure, Category = "Logic", meta = (DisplayName = "GetOwner"))
	AActor* K2_GetOwner() const;

	virtual bool Condition() const override;
};