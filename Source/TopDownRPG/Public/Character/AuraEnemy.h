// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include <TopDownRPG/TopDownRPG.h>
#include <AbilitySystem/AuraAbilitySystemComponent.h>
#include <AbilitySystem/AuraAttributeSet.h>
#include "AuraEnemy.generated.h"



UCLASS()
class TOPDOWNRPG_API AAuraEnemy : public AAuraCharacterBase,public IEnemyInterface
{
	GENERATED_BODY()
public:
	AAuraEnemy();
	/*IEnemyInterface*/
	virtual void HighLightActor()override;
	virtual void UnHighLightActor()override;
	/*End IEnemyInterface*/
	
	/*IEnemyInterface*/
	virtual int32 GetPlayerLevel() override;
	/*end IEnemyInterface*/


	UPROPERTY(BlueprintReadOnly)
	bool bhighlighted = false;
protected:
	virtual void BeginPlay()override;
	virtual void InitAbilityActorInfor()override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Class Defualts")
	int32 Level = 1;
};
 