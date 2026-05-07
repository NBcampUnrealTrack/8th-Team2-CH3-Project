#pragma once

#include "CoreMinimal.h"
#include "RelicEffectBase.h"
#include "Relic_ApplyHp.generated.h"

UCLASS(Blueprintable)
class CH3_TEAM2_API URelic_ApplyHp : public URelicEffectBase
{
	GENERATED_BODY()
	
public:
	
	virtual void ApplyEffect(AActor* Owner,int32 Value) override;

	
};
