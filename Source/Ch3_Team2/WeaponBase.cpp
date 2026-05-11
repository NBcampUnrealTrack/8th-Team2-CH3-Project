// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponBase.h"
#include "Components/ArrowComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
// Sets default values
AWeaponBase::AWeaponBase()
{
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	GunMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("GunMesh"));
	GunMesh->SetupAttachment(Root);
	
	FirePoint = CreateDefaultSubobject<UArrowComponent>(TEXT("FirePoint"));
	FirePoint->SetupAttachment(GunMesh);

	CurrentAmmo = 1;
	MaxAmmo = 12;
	RoundsPerSecond = 1.f;
	CanFire = true;
	EffectiveRange = 1000.f;
	AmmoDamage = 100.f;
	ReloadTime = 1.2;
	
	// 연사 속도는 흠...
	//SpreadAngle = (3.0, 0.2);
}

void AWeaponBase::Fire()
{
	CanFire = false;

	GetWorld()->GetTimerManager().SetTimer(TimerFireDelay, this, &AWeaponBase::HandleFireDelay, 1.f / RoundsPerSecond, false);
}

void AWeaponBase::HandleFireDelay()
{
	GetWorld()->GetTimerManager().ClearTimer(TimerFireDelay);

	CanFire = true;
}
