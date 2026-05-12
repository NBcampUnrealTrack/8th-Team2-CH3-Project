// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WeaponBase.h"
#include "GunBase.generated.h"

UCLASS()
class CH3_TEAM2_API AGunBase : public AWeaponBase
{
	GENERATED_BODY()

public:
	AGunBase();


	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category= "Weapon")
	void Reload();

	// 무기 스텟 초기화 
	// 매개 변수 설정
	virtual void Stats_Initialize();
	
protected:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	// NatveEnvent로 하이브리드 형으로 만들면 
	//_Implementaion 함수 이름 뒤에 작성해야하고 
	// 블루 프린트로 위임했기 때문에 코드 작성하면 안된다.
	bool CheckAmmo();

	//총알 업데이트
	UFUNCTION(BlueprintNativeEvent)
	void UpdateAmmo();

	// 블루프린트의 "fireGun" Custom Event에 해당하는 함수
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void Fire_Gun(FVector Location, FVector Direction);

	void Fire(FVector Location, FVector Direction);

	UFUNCTION()
	void HandleFireDelay();
	// 공격력 추가
	void AddDmage(float Add_Damage){ AmmoDamage += Add_Damage;}

	// 이부분은 아직 keep
	/*
	//총을 어떻게 쏠지
	UFUNCTION(BlueprintImplementableEvent)
	void ProcessFiring();

	//이펙트 실행
	UFUNCTION(BlueprintImplementableEvent)
	void PlayEffects();
	 */
};
