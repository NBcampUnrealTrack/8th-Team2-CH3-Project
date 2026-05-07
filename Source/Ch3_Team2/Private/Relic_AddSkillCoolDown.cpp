#include "Relic_AddSkillCoolDown.h"
#include "Ch3_Team2/APlayer.h"

void URelic_AddSkillCoolDown::ApplyEffect(AActor* Owner, int32 Value)
{
	AAPlayer* Player = Cast<AAPlayer>(Owner);
	if (!Player) return;
	
	Player->SkillCooldown += Value;
}