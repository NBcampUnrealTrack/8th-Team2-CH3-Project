#pragma once

#include "CoreMinimal.h"
#include "RelicEffectBase.h"
#include "Relic_AddSpeed.generated.h"

UCLASS(Blueprintable)
class CH3_TEAM2_API URelic_AddSpeed : public URelicEffectBase
{
	GENERATED_BODY()
	
public:
	virtual void ApplyEffect(AActor* Owner, int32 Value) override;
	
};
