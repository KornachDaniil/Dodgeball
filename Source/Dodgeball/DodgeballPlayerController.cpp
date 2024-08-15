// Fill out your copyright notice in the Description page of Project Settings.


#include "DodgeballPlayerController.h"

void ADodgeballPlayerController::ShowRestartWidget()
{
	if(BP_ResrtartWidget != nullptr)
	{
		SetPause(true);
		SetInputMode(FInputModeUIOnly());
		bShowMouseCursor = true;
		RestartWidget = CreateWidget<URestartWidget>(this, BP_ResrtartWidget);
		RestartWidget->AddToViewport();
		
	}
}

void ADodgeballPlayerController::HideRestartWidget()
{
	RestartWidget->RemoveFromParent();
	RestartWidget->Destruct();
	SetPause(false);
	SetInputMode(FInputModeGameOnly());
	bShowMouseCursor = false;
}

void ADodgeballPlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (BP_HUDWidget != nullptr)
	{
		HUDWidget = CreateWidget<UHUDWidget>(this, BP_HUDWidget);
		HUDWidget->AddToViewport();
	}
}

void ADodgeballPlayerController::UpdateHealthPercent(float HealthPercent) const
{
	if(HUDWidget != nullptr)
	{
		HUDWidget->UpdateHealthPercent(HealthPercent);
	}
}

void ADodgeballPlayerController::RemoveHealthBar() const
{
	HUDWidget->RemoveFromParent();
	HUDWidget->Destruct();
}

void ADodgeballPlayerController::ShowWinWidget()
{
	if (BP_WinWidget != nullptr)
	{
		SetPause(true);
		SetInputMode(FInputModeUIOnly());
		bShowMouseCursor = true;
		WinWidget = CreateWidget<UWinWidget>(this, BP_WinWidget);
		WinWidget->AddToViewport();
	}
}

void ADodgeballPlayerController::RemoveWinWidget()
{
	WinWidget->RemoveFromParent();
	WinWidget->Destruct();
	SetPause(false);
	SetInputMode(FInputModeGameOnly());
	bShowMouseCursor = false;
}
