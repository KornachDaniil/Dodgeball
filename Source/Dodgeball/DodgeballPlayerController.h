// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HUDWidget.h"
#include "RestartWidget.h"
#include "WinWidget.h"
#include "GameFramework/PlayerController.h"
#include "DodgeballPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class DODGEBALL_API ADodgeballPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<URestartWidget> BP_ResrtartWidget;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UHUDWidget> BP_HUDWidget;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UWinWidget> BP_WinWidget;
	
	void ShowRestartWidget();
	void HideRestartWidget();
	void UpdateHealthPercent(float HealthPercent) const;
	void RemoveHealthBar() const;
	void ShowWinWidget();
	void RemoveWinWidget();

protected:
	virtual void BeginPlay() override;
	
private:
	UPROPERTY()
	URestartWidget* RestartWidget;

	UPROPERTY()
	UHUDWidget* HUDWidget;

	UPROPERTY()
	UWinWidget* WinWidget;
	
};
