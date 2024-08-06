// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/AuraAbilitySystemLibrary.h"




UOverlayWidgetController* UAuraAbilitySystemLibrary::GetOverlayWidgetController(const UObject* WorldContextObject)
{
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0)) {
		if (AAuraUUD* AuraHUD = Cast<AAuraUUD>(PC->GetHUD())) {

			AAruaPlayerState* AuraPS=PC->GetPlayerState<AAruaPlayerState>();
			UAbilitySystemComponent* AuraASC = AuraPS->GetAbilitySystemComponent();
			UAttributeSet* AuraAS= Cast<UAuraAttributeSet>(AuraPS->GetAttributeSet());
			return AuraHUD->GetOverlayWidgetController(FWidgetControllerParams(PC, AuraPS, AuraASC, AuraAS));

		}
	}
	return nullptr;
}

UAttributeMenuWidgetController* UAuraAbilitySystemLibrary::GetAttributeMenuWidgetController(const UObject* WorldContextObject)
{
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0)) {
		if (AAuraUUD* AuraHUD = Cast<AAuraUUD>(PC->GetHUD())) {

			AAruaPlayerState* AuraPS = PC->GetPlayerState<AAruaPlayerState>();
			UAbilitySystemComponent* AuraASC = AuraPS->GetAbilitySystemComponent();
			UAttributeSet* AuraAS = Cast<UAuraAttributeSet>(AuraPS->GetAttributeSet());
			return AuraHUD->GetUAttributeMenuWidgetController(FWidgetControllerParams(PC, AuraPS, AuraASC, AuraAS));
		}
	}
	return nullptr;
}


