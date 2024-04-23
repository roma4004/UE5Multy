// Fill out your copyright notice in the Description page of Project Settings.


#include "TestActor.h"

#include "Net/UnrealNetwork.h"

// Sets default values
ATestActor::ATestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mesh"));
	SetRootComponent(StaticMesh);
}

// Called when the game starts or when spawned
void ATestActor::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATestActor::PressedTestRep()
{
	//callback called after each replicating
}

void ATestActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	DOREPLIFETIME(ATestActor, StaticMesh);
}