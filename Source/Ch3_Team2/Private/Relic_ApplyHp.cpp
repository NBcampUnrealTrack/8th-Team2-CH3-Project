#include "Relic_ApplyHp.h"
#include "Ch3_Team2/APlayer.h"

void URelic_ApplyHp::ApplyEffect(AActor* Owner,int32 Value)
{
	AAPlayer* Player = Cast<AAPlayer>(Owner);
	if (!Player) return;
		
	Player->AddMaxHp(Value);
}