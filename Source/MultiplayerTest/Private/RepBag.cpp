// Fill out your copyright notice in the Description page of Project Settings.


#include "RepBag.h"
#include "Net/UnrealNetwork.h"

// Sets default values
ARepBag::ARepBag()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// SetReplicates(true);
	// SetReplicateMovement(true);
}

// Called when the game starts or when spawned
void ARepBag::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ARepBag::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
//
// void ARepBag::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
// {
//     Super::GetLifetimeReplicatedProps(OutLifetimeProps);
//
//     DOREPLIFETIME(ARepBag, RepData);
// }
