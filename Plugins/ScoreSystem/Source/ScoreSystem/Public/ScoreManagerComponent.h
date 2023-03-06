// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Blueprint/userWidget.h"
#include "ScoreManagerComponent.generated.h"

//Creating a delegate which is going to allow to replace the param from each function that subscribes with the new score. 
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnScoreChangedSignature, int, NewScore);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SCORESYSTEM_API UScoreManagerComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	int score;


public:	
	// Sets default values for this component's properties
	UScoreManagerComponent();

	virtual void AddScoreValue(int scoreValue);


	//Signature for the delegate, so that future classes can subscribe to it
	UPROPERTY(BlueprintAssignable)
		FOnScoreChangedSignature OnScoreChangedDelegate;


	//Score UI 
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> ScoreUIObject;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;
		
};
