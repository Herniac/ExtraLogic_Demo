// Copyright 2025 Crippling Depression Ind. all rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BBValueProviderHolder.generated.h"

class UBBValueProvider_Base;

UCLASS(Blueprintable)
class EXTRALOGIC_API ABBValueProviderHolder : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABBValueProviderHolder();

protected:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Instanced, meta=(ShowOnlyInnerProperties))
	TArray<UBBValueProvider_Base*> Providers;
};
