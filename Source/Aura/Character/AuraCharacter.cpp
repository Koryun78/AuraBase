#include "AuraCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "../Player/AuraPlayerState.h"
#include "AbilitySystemComponent.h"
#include "../Player/AuraPlayerController.h"
#include "Aura/UI/HUD/AuraHUD.h"

AAuraCharacter::AAuraCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 400.0f, 0.0f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

void AAuraCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	InitAbilityActorInfo();
}

void AAuraCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	InitAbilityActorInfo();
}

void AAuraCharacter::InitAbilityActorInfo()
{
	AAuraPlayerState* AuraPlayerState = GetPlayerState<AAuraPlayerState>();
	check(AuraPlayerState);
	AuraPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(AuraPlayerState, this);
	AbilitySystemComp = AuraPlayerState->GetAbilitySystemComponent();
	AttributeSet = AuraPlayerState->GetAttributeSet();

	if (AAuraPlayerController* AuraPlayerController = Cast<AAuraPlayerController>(GetController()))
	{
		if(AAuraHUD* AuraHUD = Cast<AAuraHUD>(AuraPlayerController->GetHUD()))
		{
			//const FWidgetControllerParams WidgetControllerParams(AuraPlayerController, AuraPlayerState, AbilitySystemComp, AttributeSet);
			AuraHUD->InitOverlay(AuraPlayerController, AuraPlayerState, AbilitySystemComp, AttributeSet);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("AuraHUD is not valid"));
		}
	}
}
