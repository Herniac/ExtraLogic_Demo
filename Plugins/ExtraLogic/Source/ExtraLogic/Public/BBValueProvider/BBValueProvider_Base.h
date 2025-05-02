// Copyright 2025 Crippling Depression Ind. all rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BBValueProvider_Base.generated.h"

/**
 *	Blackboard value providers are meant to simplify setting up values
 *  for Behavior Trees' blackboards by gathering types under one parent class.
 *	Value providers are meant to be used as Instanced objects in TArrays.
 *	@see BBValueProviderHolder
 */
 class UBlackboardComponent;

UCLASS(Abstract, EditInlineNew, Blueprintable)
class EXTRALOGIC_API UBBValueProvider_Base : public UObject
{
	GENERATED_BODY()
	
public:
	/** Blueprint callable setter. */
	UFUNCTION(BlueprintCallable, Category = "Blackboard", meta = (DisplayName = "SetBlackboardValue"))
	void K2_SetBlackboardValue(UBlackboardComponent* Blackboard) const { SetBlackboardValue(Blackboard); }

	/** Main setter function. Each derived class must override this to handle a value of its specific type. */
	virtual void SetBlackboardValue(UBlackboardComponent* Blackboard) const PURE_VIRTUAL(UBBValueProvider_Base::SetBlackboardValue, );

protected:
	/** */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Blackboard")
	FName BlackboardKeyName;
};

/**
 *	Bool
 */
UCLASS()
class EXTRALOGIC_API UBBValueProvider_Bool : public UBBValueProvider_Base
{
	GENERATED_BODY()

public:
	void SetBlackboardValue(UBlackboardComponent* Blackboard) const override;

protected:
	/** */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Blackboard")
	bool Value;
};

/**
 *	Integer
 */
UCLASS()
class EXTRALOGIC_API UBBValueProvider_Int : public UBBValueProvider_Base
{
	GENERATED_BODY()

public:
	void SetBlackboardValue(UBlackboardComponent* Blackboard) const override;

protected:
	/** */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Blackboard")
	int32 Value;
};

/**
 *	Float
 */
UCLASS()
class EXTRALOGIC_API UBBValueProvider_Float : public UBBValueProvider_Base
{
	GENERATED_BODY()

public:
	void SetBlackboardValue(UBlackboardComponent* Blackboard) const override;

protected:
	/** */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Blackboard")
	float Value;
};

/**
 *	Vector
 */
UCLASS()
class EXTRALOGIC_API UBBValueProvider_Vector : public UBBValueProvider_Base
{
	GENERATED_BODY()

public:
	void SetBlackboardValue(UBlackboardComponent* Blackboard) const override;

protected:
	/** */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Blackboard")
	FVector Value;
};

/**
 *	Object
 */
UCLASS()
class EXTRALOGIC_API UBBValueProvider_Object : public UBBValueProvider_Base
{
	GENERATED_BODY()

public:
	void SetBlackboardValue(UBlackboardComponent* Blackboard) const override;

protected:
	/** */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Blackboard")
	UObject* Value;
};

/**
 *	Class
 */
UCLASS()
class EXTRALOGIC_API UBBValueProvider_Class : public UBBValueProvider_Base
{
	GENERATED_BODY()

public:
	void SetBlackboardValue(UBlackboardComponent* Blackboard) const override;

protected:
	/** */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Blackboard")
	UClass* Value;
};

/**
 *	Enum
 */
UCLASS()
class EXTRALOGIC_API UBBValueProvider_Enum : public UBBValueProvider_Base
{
	GENERATED_BODY()

public:
	void SetBlackboardValue(UBlackboardComponent* Blackboard) const override;

protected:
	/** */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Blackboard")
	uint8 Value;
};

/**
 *	Rotator
 */
UCLASS()
class EXTRALOGIC_API UBBValueProvider_Rotator : public UBBValueProvider_Base
{
	GENERATED_BODY()

public:
	void SetBlackboardValue(UBlackboardComponent* Blackboard) const override;

protected:
	/** */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Blackboard")
	FRotator Value;
};

/**
 *	Name
 */
UCLASS()
class EXTRALOGIC_API UBBValueProvider_Name : public UBBValueProvider_Base
{
	GENERATED_BODY()

public:
	void SetBlackboardValue(UBlackboardComponent* Blackboard) const override;

protected:
	/** */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Blackboard")
	FName Value;
};

/**
 *	String
 */
UCLASS()
class EXTRALOGIC_API UBBValueProvider_String : public UBBValueProvider_Base
{
	GENERATED_BODY()

public:
	void SetBlackboardValue(UBlackboardComponent* Blackboard) const override;

protected:
	/** */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Blackboard")
	FString Value;
};

