// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraAssetManager.h"

UAuraAssetManager& UAuraAssetManager::Get()
{
	// TODO: 在此处插入 return 语句
	check(GEngine);
	UAuraAssetManager* AssetManager=Cast<UAuraAssetManager>(GEngine->AssetManager);
	return *AssetManager;
}

void UAuraAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();
	FAuraGameplayTags::InitializeNativeGameplayTags();
	

}
