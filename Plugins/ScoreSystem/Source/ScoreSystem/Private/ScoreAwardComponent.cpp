// Fill out your copyright notice in the Description page of Project Settings.


#include "ScoreAwardComponent.h"
#include "ScoreManagerComponent.h"
#include "GameFramework/GameModeBase.h"


// Sets default values for this component's properties
UScoreAwardComponent::UScoreAwardComponent()
{
	//Constructor
}


// Called when the game starts
void UScoreAwardComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

void UScoreAwardComponent::AwardScore()
{
	if (GetWorld())
	{
		AGameModeBase* GameMode = GetWorld()->GetAuthGameMode();
		if (GameMode)
		{

			//Score award gets AddScoreValue function from the manager and provides a value so that this one can be updated in the UI.
			//Make Manager in a bit

			UScoreManagerComponent* manager = GameMode->FindComponentByClass<UScoreManagerComponent>();
			if (manager)
			{
				manager->AddScoreValue(ScoreValue);
			}
		}
	}

}

void UScoreAwardComponent::OnComponentDestroyed(bool bValue)
{
	if (bValue)
	{
		AwardScore();
	}
}



