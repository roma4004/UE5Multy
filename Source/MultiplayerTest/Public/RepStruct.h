#pragma once

#include "CoreMinimal.h"
#include "Net/UnrealNetwork.h"

#include "RepStruct.generated.h"

USTRUCT(BlueprintType)
struct MULTIPLAYERTEST_API FRepStruct
{
public:
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere)
	int Health = 100;

	UPROPERTY(EditAnywhere)
	float Speed = 4.2f;

	UPROPERTY(EditAnywhere)
	float SomeFlag = false;

	UPROPERTY(EditAnywhere)
	TArray<int32> HealthHistory;

	FRepStruct();
	~FRepStruct();
};
