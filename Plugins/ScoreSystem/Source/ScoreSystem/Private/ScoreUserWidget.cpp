// Fill out your copyright notice in the Description page of Project Settings.


#include "ScoreUserWidget.h"

void UScoreUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	if (GetWorld())
	{
		AGameModeBase* GameMode = GetWorld()->GetAuthGameMode();
		if (GameMode)
		{

			UScoreManagerComponent* manager = GameMode->FindComponentByClass<UScoreManagerComponent>();
			if (manager)
			{
				//Subscring the updateScoreText function to our scoreManager delegate which this one is going to broadcast the score variable and automatically replace our _currentScore
				//Param in our UpdateScoreText function below.
				manager->
					OnScoreChangedDelegate.AddDynamic(
						this, &UScoreUserWidget::UpdateScoreText);
			}
		}
	}

}

void UScoreUserWidget::UpdateScoreText(int _CurrentScore)
{
	FString ScoreString = FString::Printf(TEXT("%i"), _CurrentScore);
	if (ScoreTextBlock)
	{
		ScoreTextBlock->SetText(FText::FromString(ScoreString));
	}
}
