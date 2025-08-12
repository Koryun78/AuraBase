// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraHUD.h"
#include "Aura/UI/Widget/AuraUserWidget.h"
#include "Aura/UI/WidgetController/OverlayWidgetController.h"

UOverlayWidgetController* AAuraHUD::GetOverLayWidgetController(const FWidgetControllerParams& WCParams)
{
	if (!OverlayWidgetController)
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, UOverlayWidgetController::StaticClass());
		OverlayWidgetController->SetWidgetConttrolerParams(WCParams);

		return OverlayWidgetController;
	}
	return OverlayWidgetController;
}

void AAuraHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	checkf(OverlayWidgetClass, TEXT("Overlay Widget class uninitialazed"));
	checkf(OverlayWidgetControllerClass, TEXT("Overlay Widget Controller class uninitialazed"));

	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget = Cast<UAuraUserWidget>(Widget);

	const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
	UOverlayWidgetController* WidgetController = GetOverLayWidgetController(WidgetControllerParams);

	OverlayWidget->SetWidgetController(WidgetController);
	WidgetController->BroadcastInitialValue();

	Widget->AddToViewport();
}

void AAuraHUD::BeginPlay()
{
	Super::BeginPlay();

	
}
