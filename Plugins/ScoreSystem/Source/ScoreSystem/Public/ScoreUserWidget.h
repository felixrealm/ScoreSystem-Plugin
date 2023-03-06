// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "ScoreManagerComponent.h"
#include "ScoreUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class SCORESYSTEM_API UScoreUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* ScoreTextBlock;

	UPROPERTY(BlueprintAssignable)
		FOnScoreChangedSignature OnScoreChangedDelegate;

	UFUNCTION(BlueprintCallable)
		void UpdateScoreText(int _CurrentScore);


	
};
