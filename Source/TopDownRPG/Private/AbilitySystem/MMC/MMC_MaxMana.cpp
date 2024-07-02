// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/MMC/MMC_MaxMana.h"



UMMC_MaxMana::UMMC_MaxMana()
{
	IntelligenceDef.AttributeToCapture = UAuraAttributeSet::GetIntelligenceAttribute();
	IntelligenceDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	IntelligenceDef.bSnapshot = false;

	//Òª²¶»ñµÄFGameplayEffectAttributeCaptureDefinition
	RelevantAttributesToCapture.Add(IntelligenceDef);
}

float UMMC_MaxMana::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	const FGameplayTagContainer* SourceTag = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* Target = Spec.CapturedTargetTags.GetAggregatedTags();
	FAggregatorEvaluateParameters EvaluateParmeters;
	EvaluateParmeters.SourceTags=SourceTag;
	EvaluateParmeters.TargetTags = Target;
	float Intelligence = 0.f;
	GetCapturedAttributeMagnitude(IntelligenceDef,Spec, EvaluateParmeters, Intelligence);
	Intelligence = FMath::Max<float>(Intelligence, 0);
	const int32 Level=Cast<ICombatInterface>(Spec.GetContext().GetSourceObject())->GetPlayerLevel();
	return 50.f + Intelligence * 2.5f + 10.f * Level;
}
