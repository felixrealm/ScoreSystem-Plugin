// Fill out your copyright notice in the Description page of Project Settings.


#include "ScoreManagerComponent.h"

// Sets default values for this component's properties
UScoreManagerComponent::UScoreManagerComponent()
{

}


// Called when the game starts
void UScoreManagerComponent::BeginPlay()
{
	Super::BeginPlay();

	if (ScoreUIObject)
	{
		//Getting a reference to the score's UI element and telling it to send to the viewport.
		UUserWidget* ScoreWidgetRef = CreateWidget(GetWorld(), ScoreUIObject);
		if (ScoreWidgetRef)
		{

			ScoreWidgetRef->AddToViewport();
		}
	}


	// ...
	
}

void UScoreManagerComponent::AddScoreValue(int scoreValue)
{

	score += scoreValue;
	if (score < 0)
		score = 0;

	//Broadcasting the new score value to the subscribed classes (ex: the UI class, which is then going to update the tesxt with the new text)
	OnScoreChangedDelegate.Broadcast(score);

}

