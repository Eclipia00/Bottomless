#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Prepper/Character/Component/Status.h"
#include "Prepper/Item/Inventory/MapInventory.h"
#include "Prepper/_Base/ObserverPattern/Observer.h"
#include "Prepper/_Base/Util/GaugeValue.h"
#include "CharacterOverlay.generated.h"

class UCanvasPanel;

UCLASS()
class PREPPER_API UCharacterOverlay : public UUserWidget,
										public IObserver<GaugeValue<float>>,
										public IObserver<TArray<FItemConvertData>>
{
	GENERATED_BODY()

	// Health
private:
	UPROPERTY(EditAnywhere, meta = (BindWidget), Category=Health)
	UProgressBar* HealthBar;
	UPROPERTY(EditAnywhere, meta = (BindWidget), Category=Health)
	UTextBlock* HealthText;
	
public:
	virtual void Update(const GaugeValue<float>& NewData) override;

	
	// UI에서 사용할 Vertical Box 변수
	UPROPERTY(EditAnywhere, meta = (BindWidget), Category=Story)
	class UVerticalBox* ItemBox;

public:
	virtual void Update(const TArray<FItemConvertData>& NewData) override;

	// 아이콘을 Vertical Box에 추가하는 함수
	UFUNCTION(BlueprintCallable, Category="Inventory")
	void AddItemIcon(UTexture2D* ItemIconTexture);

	UFUNCTION(BlueprintCallable, Category="Inventory")
	void ClearAllItemIcons();
};
