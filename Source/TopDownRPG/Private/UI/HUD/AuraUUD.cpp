// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/AuraUUD.h"

UOverlayWidgetController* AAuraUUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	if (OverlayWidgetController == nullptr) {
	
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(WCParams);
		//在设置4要素那一刻就可以绑定了Attribute监听。Controller依赖数据层
		OverlayWidgetController->BindCallbacksToDependencies();

		return  OverlayWidgetController;
	}
	return  OverlayWidgetController;
}

void AAuraUUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	checkf(OverlayWidgetClass, TEXT("Overlay Widget Class Uninitialized , please fill out BP_ AuraHUD "));
	checkf(OverlayWidgetControllerClass, TEXT("Overlay Widget Controller Class Uninitialized , please fill out BP_ AuraHUD "));

	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget = Cast<UAuraUserWidget>(Widget);

	const FWidgetControllerParams WidgetControllerParams(PC,PS,ASC,AS);
	UOverlayWidgetController* WidgetController = GetOverlayWidgetController(WidgetControllerParams);

	//set之后调用WidgetControllerSet()事件;set事件之后会有绑定成功的反馈，获取UIController，执行绑定初始值的操作，
	// 所以BroadcastInitialValues();要在SetWidgetController之后，UI层依赖Controller层
	OverlayWidget->SetWidgetController(OverlayWidgetController);
	
	WidgetController->BroadcastInitialValues();
	
	Widget->AddToViewport();
}

