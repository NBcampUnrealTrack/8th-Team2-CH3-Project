// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MonsterTypes.h"
#include "MonsterBase.generated.h"

UCLASS()
class CH3_TEAM2_API AMonsterBase : public ACharacter
{
	GENERATED_BODY()

public:
	AMonsterBase();
	virtual void Tick(float DeltaTime) override;
protected:
	virtual void BeginPlay() override;
	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
	void OnDeath();
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Stats")
	FMonsterStats BaseStats;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Stats")
	FMonsterStats CurrentStats;
};
