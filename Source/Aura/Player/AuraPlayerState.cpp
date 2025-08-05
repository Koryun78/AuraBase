// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraPlayerState.h"
#include "Aura/AbilitySystem/AuraAbilitySystemComponent.h"
#include "Aura/AbilitySystem/AuraAttributeSet.h"

AAuraPlayerState::AAuraPlayerState()
{
	NetUpdateFrequency = 100.0f; // Set a high update frequency for smoother gameplay
	MinNetUpdateFrequency = 50.0f; // Minimum update frequency to maintain performance


	AbilitySystemComp = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AuraAbilitySystemComp");
	AbilitySystemComp->SetIsReplicated(true);
	AbilitySystemComp->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");
}

UAbilitySystemComponent* AAuraPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComp;
}
