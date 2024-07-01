// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/CapsuleComponent.h"
#include <AbilitySystemComponent.h>
#include "AttributeSet.h"
#include "AbilitySystemInterface.h"
#include "AuraCharacterBase.generated.h"


UCLASS()
class TOPDOWNRPG_API AAuraCharacterBase : public ACharacter,public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAuraCharacterBase();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const { return AttributeSet;}
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;

	//----------
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent>AbilitySystemComponent;
	UPROPERTY()
	TObjectPtr<UAttributeSet>AttributeSet;

	virtual void InitAbilityActorInfor();
};
