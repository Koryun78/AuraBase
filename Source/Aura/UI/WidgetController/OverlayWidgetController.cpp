#include "OverlayWidgetController.h"
#include "Aura/AbilitySystem/AuraAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValue()
{
	const UAuraAttributeSet* AuraAttributeSet = CastChecked<UAuraAttributeSet>(AttributeSet);

	OnHealtChanged.Broadcast(AuraAttributeSet->GetHealth());
	OnMaxHealtChanged.Broadcast(AuraAttributeSet->GetMaxHealth());
}
