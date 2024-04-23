// Fill out your copyright notice in the Description page of Project Settings.


#include "RepBag.h"
#include "Net/UnrealNetwork.h"

// Sets default values
ARepBag::ARepBag()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;

	// SetReplicates(true);
	// SetReplicateMovement(true);
}

// Called when the game starts or when spawned
void ARepBag::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		if (const UWorld* World = GetWorld())
		{
			constexpr float Delay = 5.0f;
			FTimerHandle TimerHandle;
			World->GetTimerManager().SetTimer(TimerHandle, FTimerDelegate::CreateWeakLambda(this,[this]()
			{
				if (JustInt > 0)
				{
					JustInt -= 1;
				}
				else
				{
					JustInt = 100;
					GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::White, FString::Printf(TEXT("Server reset int")));
				}
			}), Delay, /*bLoop*/ false);
		}
	}
}

// Called every frame
void ARepBag::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARepBag::OnRep_ReplicatedJustInt() const
{
	if (HasAuthority())
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::White, FString::Printf(TEXT("Server ReplicatedStruct")));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::White, FString::Printf(TEXT("Client ReplicatedStruct")));
	}
}

// void ARepBag::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
// {
//     Super::GetLifetimeReplicatedProps(OutLifetimeProps);
//
//     DOREPLIFETIME(ARepBag, RepData);
// }

void ARepBag::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(ARepBag, JustInt);
}
