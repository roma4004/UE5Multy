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

	UPROPERTY(EditAnywhere)
	FRepStruct RepData{};
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// virtual void ARepBag::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
