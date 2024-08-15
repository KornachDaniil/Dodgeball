// Fill out your copyright notice in the Description page of Project Settings.


#include "WinWidget.h"

#include "DodgeballPlayerController.h"
#include "Kismet/GameplayStatics.h"

void UWinWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	if (RestartButton != nullptr)
	{
		
		RestartButton->OnClicked.AddDynamic(this, &UWinWidget::OnRestartClicked);
	}
	if (ExitButton != nullptr)
	{
		ExitButton->OnClicked.AddDynamic(this,&UWinWidget::OnExitClicked);
	}
}

void UWinWidget::OnRestartClicked()
{
	ADodgeballPlayerController* PlayerController = Cast<ADodgeballPlayerController>(GetOwningPlayer());
	if(PlayerController != nullptr)
	{
		PlayerController->RemoveWinWidget();
		UGameplayStatics::OpenLevel(this, FName(/* * */UGameplayStatics::GetCurrentLevelName(this))); //!!!
	}
}

void UWinWidget::OnExitClicked()
{
	UKismetSystemLibrary::QuitGame(GetWorld(), nullptr, EQuitPreference::Quit, true);
}
