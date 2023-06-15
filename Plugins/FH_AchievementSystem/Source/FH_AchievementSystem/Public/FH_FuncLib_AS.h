#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AchievementData.h"
#include "FH_FuncLib_AS.generated.h"

UCLASS(BlueprintType)
class FH_ACHIEVEMENTSYSTEM_API UFH_FuncLib_AS : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

/* My Code */
	/* Function */
public:
	// Add And Remove Achievement List
	UFUNCTION(BlueprintPure, Category="FH|Achievement")
	static bool IsAchievementExists(const int32 AchievementID);
	
	UFUNCTION(BlueprintCallable, Category="FH|Achievement")
	static bool AddAchievement(const FAchievement& NewAchievement);

	UFUNCTION(BlueprintCallable, Category="FH|Achievement")
	static bool RemoveAchievement(const int32 AchievementID);

	UFUNCTION(BlueprintPure, Category="FH|Achievement")
	static TMap<int32, FAchievement> GetAchievementsList();

	UFUNCTION(BlueprintPure, Category="FH|Achievement")
	static bool ClearAchievementsList();

	UFUNCTION(BlueprintCallable, Category="FH|Achievement")
	static void GetAllAchievements(TArray<FAchievement>& Achievements);

	

	// Complete Task
	UFUNCTION(BlueprintCallable, Category="FH|Achievement")
	static void DoOnceTask(const int32 AchievementID, int32& ID, bool& IsDoOver);

	UFUNCTION(BlueprintPure, Category="FH|Achievement")
	static void IsAchievementComplete(int32 AchievementID, bool& IsComplete);
};