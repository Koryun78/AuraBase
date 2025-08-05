// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraEnemy.h"

#include "../AbilitySystem/AuraAbilitySystemComponent.h"
#include "../AbilitySystem/AuraAttributeSet.h"
#include "Aura/Aura.h"


AAuraEnemy::AAuraEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	AbilitySystemComp = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AuraAbilitySystemComp");
	AbilitySystemComp->SetIsReplicated(true);

	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");

}

void AAuraEnemy::BeginPlay()
{
	Super::BeginPlay();
	check(AbilitySystemComp);
	AbilitySystemComp->InitAbilityActorInfo(this, this);

}

void AAuraEnemy::HighlightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(250.f);
	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(250.f);
}

void AAuraEnemy::UnHighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
	//bHighlighted = false;
}
