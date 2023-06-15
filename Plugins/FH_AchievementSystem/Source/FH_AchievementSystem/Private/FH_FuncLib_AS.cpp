#include "FH_FuncLib_AS.h"

// Add And Remove Achievement List
bool UFH_FuncLib_AS::IsAchievementExists(const int32 AchievementID)
{
	if (AchievementsList.IsEmpty()) return false;
	if (AchievementsList.Find(AchievementID)) return true;
	return false;
}

bool UFH_FuncLib_AS::AddAchievement(const FAchievement& NewAchievement)
{
	if (AchievementsList.Find(NewAchievement.AchievementID)) return false;
	AchievementsList.Add(NewAchievement.AchievementID, NewAchievement);
	return true;
}

bool UFH_FuncLib_AS::RemoveAchievement(const int32 AchievementID)
{
	if (AchievementsList.IsEmpty()) return false;
	if (AchievementsList.Find(AchievementID))
	{
		AchievementsList.Remove(AchievementID);
		return true;
	}
	return false;
}

TMap<int32, FAchievement> UFH_FuncLib_AS::GetAchievementsList()
{
	return AchievementsList;
}

bool UFH_FuncLib_AS::ClearAchievementsList()
{
	AchievementsList.Empty();
	if (AchievementsList.IsEmpty()) return true;
	return false;
}

void UFH_FuncLib_AS::GetAllAchievements(TArray<FAchievement>& Achievements)
{
	AchievementsList.GenerateValueArray(Achievements);
}

// Complete Task
void UFH_FuncLib_AS::DoOnceTask(const int32 AchievementID, int32& ID, bool& IsDoOver)
{
	if (!IsAchievementExists(AchievementID))
	{
		IsDoOver = false;
		return;
	}
	const auto Achievement = AchievementsList.Find(AchievementID);
	ID = AchievementID;
	
	if (Achievement->IsAchievement && Achievement->CurProgressCount == Achievement->MaxProgressCount)
	{
		IsDoOver = false;
		return;
	}

	switch (Achievement->EAT)
	{
	case EAchievementType::EAT_OneTime:
		{
			Achievement->CurProgressCount = 1;
			Achievement->IsAchievement = true;
			IsDoOver = true;
		}
		break;
	case EAchievementType::EAT_Cumulative:
		{
			Achievement->CurProgressCount += 1;
			IsDoOver = true;
			if (Achievement->CurProgressCount == Achievement->MaxProgressCount)
			{
				Achievement->IsAchievement = true;
			}
		}
		break;
	default:
		IsDoOver = false;
		break;
	}
}

void UFH_FuncLib_AS::IsAchievementComplete(const int32 AchievementID, bool& IsComplete)
{
	if (!IsAchievementExists(AchievementID))
	{
		IsComplete = false;
		return;
	}
	const auto Achievement = AchievementsList.Find(AchievementID);
	
	if (Achievement->IsAchievement && Achievement->CurProgressCount == Achievement->MaxProgressCount)
	{
		IsComplete = true;
	}
	else
	{
		IsComplete = false;
	}
}
