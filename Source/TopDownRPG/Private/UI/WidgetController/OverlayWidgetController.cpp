// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/OverlayWidgetController.h"



void UOverlayWidgetController::BroadcastInitialValues()
{
	const  UAuraAttributeSet* AuraAttributeSet = CastChecked<UAuraAttributeSet>(AttributeSet);
	OnHealthChanged.Broadcast(AuraAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(AuraAttributeSet->GetMaxHealth());
	OnManaChanged.Broadcast(AuraAttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(AuraAttributeSet->GetMaxMana());

	


}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const  UAuraAttributeSet* AuraAttributeSet = CastChecked<UAuraAttributeSet>(AttributeSet);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetHealthAttribute()).
		AddLambda([this](const FOnAttributeChangeData& Data)->void {OnHealthChanged.Broadcast(Data.NewValue); });
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetMaxHealthAttribute()).
		AddLambda([this](const FOnAttributeChangeData& Data)->void {OnMaxHealthChanged.Broadcast(Data.NewValue); });
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetManaAttribute()).
		AddLambda([this](const FOnAttributeChangeData& Data)->void {OnManaChanged.Broadcast(Data.NewValue); });
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetMaxManaAttribute()).
		AddLambda([this](const FOnAttributeChangeData& Data)->void {OnMaxManaChanged.Broadcast(Data.NewValue); });


	UAuraAbilitySystemComponent* AuraASC=  Cast<UAuraAbilitySystemComponent>(AbilitySystemComponent);

	AuraASC->EffectAssetTags.AddLambda(
		//lambda表达式不了解当前类的信息，只知道传入信息还有全局内容,想要访问成员变量，必须捕获拥有那个成员变量的类
		 [this](const FGameplayTagContainer& AssetTags)->void{
			for (const FGameplayTag tag : AssetTags) {
				/*
				FString msg = FString::Printf(TEXT("GE tag: %s"), *tag.ToString());
				GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Red, msg);
				*/
				FGameplayTag MessageTag= FGameplayTag::RequestGameplayTag(FName("Message"));
				if(tag.MatchesTag(MessageTag)){
					const FUIWidgetRow* Row = GetDataTableRowByTag<FUIWidgetRow>(MessageWidgetDataTable, tag);
					MessageWidgetRowDelegate.Broadcast(*Row);
				}
						
			}			
		}
	);
}

