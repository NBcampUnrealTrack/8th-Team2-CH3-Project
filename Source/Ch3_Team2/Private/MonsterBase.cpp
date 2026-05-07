// Fill out your copyright notice in the Description page of Project Settings.


#include "MonsterBase.h"

// Sets default values
AMonsterBase::AMonsterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMonsterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

float AMonsterBase::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float ActualDamage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
	CurrentStats.CurrentHP = FMath::Clamp(CurrentStats.CurrentHP-ActualDamage, 0.f,CurrentStats.MaxHP);
	if (CurrentStats.CurrentHP <= 0.f)
	{
		OnDeath();
	}
	return ActualDamage;
}

void AMonsterBase::OnDeath()
{
	UE_LOG(LogTemp,Warning,TEXT("Monster Death"));
}

// Called every frame
void AMonsterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



