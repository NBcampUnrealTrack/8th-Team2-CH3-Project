#pragma once

#include "CoreMinimal.h"
#include "RelicGrade.generated.h"

UENUM(BlueprintType)
enum class ERelicGrade : uint8
{
	Common UMETA(DisplayName = "Common"),
	Rare UMETA(DisplayName = "Rare"),
	Epic UMETA(DisplayName = "Epic"),
	Legendary UMETA(DisplayName = "Legendary"),
};
