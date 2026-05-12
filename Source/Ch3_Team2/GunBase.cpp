// Fill out your copyright notice in the Description page of Project Settings.


#include "GunBase.h"
#include "public/MonsterBase.h"

bool AGunBase::CheckAmmo_Implementation()
{
	return CurrentAmmo <= 0;
}

void AGunBase::UpdateAmmo_Implementation()
{
	CurrentAmmo -= 1;
}

void AGunBase::Reload_Implementation()
{
	CurrentAmmo = MaxAmmo;
}

AGunBase::AGunBase()
{
	Stats_Initialize();
}

void AGunBase::Stats_Initialize()
{
	CurrentAmmo = 1;
	MaxAmmo = 12;
	RoundsPerSecond = 1.f;
	CanFire = true;
	EffectiveRange = 1000.f;
	AmmoDamage = 100.f;
	ReloadTime = 1.2;
}

void AGunBase::Fire_Gun(FVector Location, FVector Direction)
{
	if (!CanFire) return;
	if (CheckAmmo())
	{
		Fire(Location,Direction);
		// 순서는 여기서 마음대로 
		//PlayEffects();
		// 총알 업로드
		UpdateAmmo();
		return;
	}
	// 1. 끝점 계산
	FVector End = Location + (Direction * EffectiveRange);

	// 2. 파라미터 설정
	FHitResult HitResult;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);           // 자기 자신 제외
	Params.AddIgnoredActor(GetOwner());    // 소유자(예: 캐릭터) 제외

	// 3. Line Trace 실행
	bool bHit = GetWorld()->LineTraceSingleByChannel(
		HitResult,
		Location,
		End,
		ECC_Visibility, // 블루프린트의 Visibility 채널
		Params
	);
	FLinearColor LColor =bHit ? FLinearColor::Green : FLinearColor::Red; 
	DrawDebugLine(
	GetWorld(),
	Location,           // 시작 지점
	End,                // 끝 지점
	LColor.ToFColor(true),          // 색상
	false,              // 매 프레임마다 그릴지 여부 (고정된 라인은 false)
	2.0f,               // 유지 시간 (초 단위, 블루프린트의 For Duration과 대응)
	0,                  // 우선순위
	1.0f);            // 두께

	// (옵션) 성공 시 로그 출력 - 테스트용
	if (bHit)
	{
		// 배틀 시스템 호출 샬라샬라
		AActor* HitActor = HitResult.GetActor();
		if (HitActor->ActorHasTag("Monster"))
		{
			AMonsterBase* Monster = Cast<AMonsterBase>(HitActor);
		}
		UE_LOG(LogTemp, Log, TEXT("Hit Actor: %s"), *HitActor->GetName());
	}
	
	
}
void AGunBase::Fire(FVector Location, FVector Direction)
{
	// 사격시 
	CanFire = false;

	GetWorld()->GetTimerManager().SetTimer(
		TimerFireDelay
		,this
		,&AGunBase::HandleFireDelay
		,1.f / RoundsPerSecond
		,false);
	
	// 1. 끝점 계산
	FVector End = Location + (Direction * EffectiveRange);

	// 2. 파라미터 설정
	FHitResult HitResult;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);           // 자기 자신 제외
	Params.AddIgnoredActor(GetOwner());    // 소유자(예: 캐릭터) 제외

	// 3. Line Trace 실행
	bool bHit = GetWorld()->LineTraceSingleByChannel(
		HitResult,
		Location,
		End,
		ECC_Visibility, // 블루프린트의 Visibility 채널
		Params
	);
	FLinearColor LColor =bHit ? FLinearColor::Green : FLinearColor::Red; 
	DrawDebugLine(
	GetWorld(),
	Location,           // 시작 지점
	End,                // 끝 지점
	LColor.ToFColor(true),          // 색상
	false,              // 매 프레임마다 그릴지 여부 (고정된 라인은 false)
	2.0f,               // 유지 시간 (초 단위, 블루프린트의 For Duration과 대응)
	0,                  // 우선순위
	1.0f);            // 두께

	// (옵션) 성공 시 로그 출력 - 테스트용
	if (bHit)
	{
		// 배틀 시스템 호출 샬라샬라
		AActor* HitActor = HitResult.GetActor();
		if (HitActor->ActorHasTag("Monster"))
		{
			AMonsterBase* Monster = Cast<AMonsterBase>(HitActor);
		}
		UE_LOG(LogTemp, Log, TEXT("Hit Actor: %s"), *HitActor->GetName());
	}
}

void AGunBase::HandleFireDelay()
{
	GetWorld()->GetTimerManager().ClearTimer(TimerFireDelay);

	CanFire = true;
}
