#include "Relic_AddSpeed.h"
#include "Ch3_Team2/APlayer.h"

void URelic_AddSpeed::ApplyEffect(AActor* Owner, int32 Value)
{
	AAPlayer* Player = Cast<AAPlayer>(Owner);
	if (!Player) return;
	
	Player->MoveSpeed += Value;
}