#pragma once

#include "CoreMinimal.h"
#include "RelicEffectBase.h"
#include "Relic_AddAtk.generated.h"

UCLASS(Blueprintable)
class CH3_TEAM2_API URelic_AddAtk : public URelicEffectBase
{
	GENERATED_BODY()
	
public:
	virtual void ApplyEffect(AActor* Owner, int32 Value) override;
	
};
