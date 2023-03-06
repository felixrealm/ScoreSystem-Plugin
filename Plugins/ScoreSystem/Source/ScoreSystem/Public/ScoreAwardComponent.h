// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ScoreAwardComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SCORESYSTEM_API UScoreAwardComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
		int ScoreValue = 100;

public:	
	// Sets default values for this component's properties
	UScoreAwardComponent();
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
		void AwardScore();

	virtual void OnComponentDestroyed(bool bValue) override;

	//G

		
};
