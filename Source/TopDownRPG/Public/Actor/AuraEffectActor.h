// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <GameplayEffect.h>
#include "GameplayEffectTypes.h"
#include "AuraEffectActor.generated.h"
UENUM(BlueprintType)
enum class EEffectApplicationPolicy : uint8
{
	ApplyOnOverlap,
	ApplyOnEndOverlap,
	NoNotApply

};
UENUM(BlueprintType)
enum class EEffectRemovePolicy : uint8
{
	RemoveOnEndOverlap,
	NoNotRemove

};

UCLASS()
class TOPDOWNRPG_API AAuraEffectActor : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AAuraEffectActor();
	

protected:
	virtual void BeginPlay()override;

	UPROPERTY(BlueprintReadOnly,EditAnywhere,Category="Applied Effects")

	bool bDestroyOnEffectRemoval = false;

	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* AppliedTarget, TSubclassOf<UGameplayEffect>GameplayEffectClass);

	UFUNCTION(BlueprintCallable)
	void OnOverlap(AActor* TargetActor);

	UFUNCTION(BlueprintCallable)
	void OnEndOverlap(AActor* TargetActor);

	UPROPERTY(BlueprintReadOnly,EditAnywhere,Category="Applied Effects")
	EEffectApplicationPolicy InstantEffectApplicationPolicy=EEffectApplicationPolicy::NoNotApply;

	UPROPERTY(BlueprintReadOnly,EditAnywhere,Category="Applied Effects")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;

	UPROPERTY(BlueprintReadOnly,EditAnywhere,Category="Applied Effects")
	EEffectApplicationPolicy DurationEffectApplicationPolicy = EEffectApplicationPolicy::NoNotApply;
	
	UPROPERTY(BlueprintReadOnly,EditAnywhere,Category="Applied Effects")
	TSubclassOf<UGameplayEffect> DurationGameplayEffectClass;

	UPROPERTY(BlueprintReadOnly,EditAnywhere,Category="Applied Effects")
	EEffectApplicationPolicy  InfiniteEffectApplicationPolicy = EEffectApplicationPolicy::NoNotApply;

	UPROPERTY(BlueprintReadOnly,EditAnywhere,Category="Applied Effects")
	EEffectRemovePolicy  InfiniteEffectRemovePolicy= EEffectRemovePolicy::RemoveOnEndOverlap;

	UPROPERTY(BlueprintReadOnly,EditAnywhere,Category="Applied Effects")
	TSubclassOf<UGameplayEffect> InfiniteGameplayEffectClass;
	
	UPROPERTY()
	TMap<FActiveGameplayEffectHandle, UAbilitySystemComponent*> ActiveEffectHandles;

	UPROPERTY(BlueprintReadOnly,EditAnywhere,Category="Applied Effects")
	float AcotorLevel = 1.f;
private:
	


};
