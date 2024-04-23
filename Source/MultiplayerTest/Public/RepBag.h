// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RepStruct.h"
#include "GameFramework/Actor.h"

#include "RepBag.generated.h"

UCLASS()
class MULTIPLAYERTEST_API ARepBag : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ARepBag();

	// UPROPERTY(ReplicatedUsing=OnRep_ReplicatedStruct, EditAnywhere)
	// FRepStruct RepData{};

	UPROPERTY(ReplicatedUsing=OnRep_ReplicatedJustInt, EditAnywhere)
	int32 JustInt = 0;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// UFUNCTION()
	// void OnRep_ReplicatedStruct();

	UFUNCTION()
	void OnRep_ReplicatedJustInt() const;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
