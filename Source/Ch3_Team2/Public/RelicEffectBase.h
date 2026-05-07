
#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "RelicEffectBase.generated.h"

UCLASS(Blueprintable)
class CH3_TEAM2_API URelicEffectBase : public UObject
{
	GENERATED_BODY()
	
public:
	
	virtual void ApplyEffect(AActor* Owner,int32 Value);
	
};