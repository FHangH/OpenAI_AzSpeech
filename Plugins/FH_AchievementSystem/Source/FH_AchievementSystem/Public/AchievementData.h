#pragma once

#include <CoreMinimal.h>
#include "AchievementData.generated.h"

UENUM(BlueprintType)
enum class EAchievementGrade : uint8
{
	EAG_C	UMETA(Displayname="C"),
	EAG_B	UMETA(Displayname="B"),
	EAG_A	UMETA(Displayname="A"),
	EAG_S	UMETA(Displayname="S")
};

UENUM(BlueprintType)
enum class EAchievementType : uint8
{
	EAT_OneTime		UMETA(Displayname="一次任务"),
	EAT_Cumulative	UMETA(Displayname="累计任务")
};

USTRUCT(BlueprintType)
struct FH_ACHIEVEMENTSYSTEM_API FAchievement
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 AchievementID{0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name{TEXT("")};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Describe{TEXT("")};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EAchievementGrade EAG{EAchievementGrade::EAG_C};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* Image{nullptr};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMaterialInstance* ImageIns{nullptr};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EAchievementType EAT{EAchievementType::EAT_OneTime};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CurProgressCount{0};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxProgressCount{1};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsAchievement{false};
};

static TMap<int32, FAchievement> AchievementsList{};