#include "Data/MyCheatManager.h"
#include "LevelFlowSubsystem.h"

void UMyCheatManager::Next()
{
	APlayerController* PC = GetOuterAPlayerController();
	if (!PC) return;

	UGameInstance* GI = PC->GetGameInstance();
	if (!GI) return;

	ULevelFlowSubsystem* LevelFlow = GI->GetSubsystem<ULevelFlowSubsystem>();
	if (!LevelFlow) return;
	
	LevelFlow->TravelToNextLevel();
	// 플레이어 레벨업
	// player addexp
}

void UMyCheatManager::Relic()
{
	APlayerController* PC = GetOuterAPlayerController();
	if (!PC) return;

	PC->ProcessEvent(
		PC->FindFunction(FName("CallRelicCheat")),
		nullptr
	);
}
