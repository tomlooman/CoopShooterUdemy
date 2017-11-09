// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SGameMode.generated.h"

/**
 * 
 */
UCLASS()
class COOPGAME_API ASGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
protected:

	FTimerHandle TimerHandle_BotSpawner;

	// Bots to spawn in current wave
	int32 NrOfBotsToSpawn;

	int32 WaveCount;

	UPROPERTY(EditDefaultsOnly, Category = "GameMode")
	float TimeBetweenWaves;
	
protected:

	// Hook for BP to spawn a single bot
	UFUNCTION(BlueprintImplementableEvent, Category = "GameMode")
	void SpawnNewBot();

	void SpawnBotTimerElapsed();

	// Start Spawning Bots
	void StartWave();

	// Stop Spawning Bots
	void EndWave();

	// Set timer for next startwave
	void PrepareForNextWave();

public:

	ASGameMode();

	virtual void StartPlay() override;
};
