// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AuraHUD.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraHUD : public AHUD
{
	GENERATED_BODY()

public:

	UPROPERTY()
	TObjectPtr<class UAuraUserWidget> OverlayWidget;

	class UOverlayWidgetController* GetOverLayWidgetController(const struct FWidgetControllerParams& WCParams);

	void InitOverlay(APlayerController* PC, APlayerState* PS, class UAbilitySystemComponent* ASC, class UAttributeSet* AS);

protected:

	virtual void BeginPlay() override;
	
private:

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UAuraUserWidget> OverlayWidgetClass;

	UPROPERTY(EditAnywhere)
	TObjectPtr<class UOverlayWidgetController> OverlayWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UOverlayWidgetController> OverlayWidgetControllerClass;

};
