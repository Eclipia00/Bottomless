// Fill out your copyright notice in the Description page of Project Settings.


#include "SurvivorSettingUI.h"

#include "Components/Button.h"
#include "Prepper/PlayerController/SurvivorController.h"

void USurvivorSettingUI::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	SaveButton->OnClicked.
			AddDynamic(this, &USurvivorSettingUI::DataSave);
}

void USurvivorSettingUI::DataSave()
{
	const TObjectPtr<ASurvivorController> PC = GetWorld()->GetFirstPlayerController<ASurvivorController>();
	if (PC == nullptr) return;

	PC->SaveGame();
}
