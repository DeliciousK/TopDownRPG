// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AruaPlayerState.h"


AAruaPlayerState::AAruaPlayerState()
{
	NetUpdateFrequency = 100.f;

	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");
}

void AAruaPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AAruaPlayerState, Level);
}

UAbilitySystemComponent* AAruaPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AAruaPlayerState::OnRep_Level(int32 OldLevel)
{

}
