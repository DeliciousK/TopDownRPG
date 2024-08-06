// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraAssetManager.h"

UAuraAssetManager& UAuraAssetManager::Get()
{
	// TODO: �ڴ˴����� return ���
	check(GEngine);
	UAuraAssetManager* AssetManager=Cast<UAuraAssetManager>(GEngine->AssetManager);
	return *AssetManager;
}

void UAuraAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();
	FAuraGameplayTags::InitializeNativeGameplayTags();
	

}
