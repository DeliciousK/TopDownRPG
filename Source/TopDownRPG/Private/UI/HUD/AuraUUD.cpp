// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/AuraUUD.h"

UOverlayWidgetController* AAuraUUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	if (OverlayWidgetController == nullptr) {
	
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(WCParams);
		//������4Ҫ����һ�̾Ϳ��԰���Attribute������Controller�������ݲ�
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

	//set֮�����WidgetControllerSet()�¼�;set�¼�֮����а󶨳ɹ��ķ�������ȡUIController��ִ�а󶨳�ʼֵ�Ĳ�����
	// ����BroadcastInitialValues();Ҫ��SetWidgetController֮��UI������Controller��
	OverlayWidget->SetWidgetController(OverlayWidgetController);
	
	WidgetController->BroadcastInitialValues();
	
	Widget->AddToViewport();
}

