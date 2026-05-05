// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SkeletalMeshComponent.h"
#include "AWeaponComponet.generated.h"

class AAPlayer;
UCLASS(Blueprintable, BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CH3_TEAM2_API UAWeaponComponet : public USkeletalMeshComponent
{
	GENERATED_BODY()
public:
	UAWeaponComponet();
	
	// Sound to play each time we fire 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	USoundBase* FireSound;
	
	// AnimMontage to play each time we fire 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	UAnimMontage* FireAnimation;

	// Gun muzzle's offset from the characters location 
	// 발사위치
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	FVector MuzzleOffset;

	// MappingContext 
	// InputMapping 발사 입력 Mapping
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	class UInputMappingContext* FireMappingContext;

	// Fire Input Action 
	// 발사 입력 엑션
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	class UInputAction* FireAction;

	// Sets default values for this component's properties 
	//UCh3_Team2WeaponComponent();

	// Attaches the actor to a FirstPersonCharacter 
	UFUNCTION(BlueprintCallable, Category="Weapon")
	bool AttachWeapon(AAPlayer* TargetCharacter);

	// Make the weapon Fire a Projectile 
	UFUNCTION(BlueprintCallable, Category="Weapon")
	void Fire();
	
protected:
	/** Ends gameplay for this component. */
	UFUNCTION()
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	
public:
	/** The Character holding this weapon*/
	UPROPERTY(EditAnyWhere, BluePrintReadWrite, Category = "Input")
	AAPlayer* Character;
};
