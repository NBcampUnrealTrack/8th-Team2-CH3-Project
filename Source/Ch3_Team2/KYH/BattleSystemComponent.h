// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BattleSystemComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CH3_TEAM2_API UBattleSystemComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UBattleSystemComponent();

protected:
	virtual void BeginPlay() override;

public:	
	// virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Battle")
	void ExecuteDamageCalculation(AActor* Attacker, AActor* Victim, float BaseDamage);
	
};
