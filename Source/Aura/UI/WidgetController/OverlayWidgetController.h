// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Aura/UI/WidgetController/AuraWidgetController.h"
#include "OverlayWidgetController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealtChangedSignature, float, NewHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHealtChangedSignature, float, NewMaxHealth);

UCLASS(BlueprintType, Blueprintable)
class AURA_API UOverlayWidgetController : public UAuraWidgetController
{
	GENERATED_BODY()

public:

	virtual void BroadcastInitialValue() override;
	virtual void BindCallbacksToDependencies() override;
	
	UPROPERTY(BlueprintAssignable, Category = "GAS|Attribute")
	FOnHealtChangedSignature OnHealtChanged;


	UPROPERTY(BlueprintAssignable, Category = "GAS|Attribute")
	FOnMaxHealtChangedSignature OnMaxHealtChanged;

protected:

	void HealthChanged(const struct FOnAttributeChangeData& Data) const;
	void MaxHealthChanged(const struct FOnAttributeChangeData& Data) const;
};
