// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemPickupAmmo.h"
#include "Prepper/Character/PlayerCharacter.h"
#include "Prepper/Character/Component/Combat/CombatComponent.h"

void AItemPickupAmmo::Interaction(APlayerCharacter* Target)
{
	Super::Interaction(Target);

	if(Target)
	{
		if(UBaseCombatComponent* Combat = Target->GetCombatComponent())
		{
			Combat->PickupAmmo(WeaponType, AmmoAmount);
		}
	}
	Destroy();
}
