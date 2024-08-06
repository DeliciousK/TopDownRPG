// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include <UI/Widget/AuraUserWidget.h>
#include <UI/WidgetController/OverlayWidgetController.h>
#include <UI/WidgetController/AttributeMenuWidgetController.h>
#include "AuraUUD.generated.h"






UCLASS()
class TOPDOWNRPG_API AAuraUUD : public AHUD
{
	GENERATED_BODY()
public:
	
	
	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams);
	UAttributeMenuWidgetController* GetUAttributeMenuWidgetController(const FWidgetControllerParams& WCParams);
	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);
protected :
	
private:
	UPROPERTY(EditAnywhere, Category = "AuraUI")
	TSubclassOf<UAuraUserWidget>OverlayWidgetClass;
	UPROPERTY()
	TObjectPtr<UAuraUserWidget>OverlayWidget;
	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;
	UPROPERTY(EditAnywhere, Category = "AuraUI")
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;


	UPROPERTY()
	TObjectPtr<UAttributeMenuWidgetController> MenuWidgetController;
	
	UPROPERTY(EditAnywhere, Category = "AuraUI")
	TSubclassOf<UAttributeMenuWidgetController> MenuWidgetControllerClass;

};
