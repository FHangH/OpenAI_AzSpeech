#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FH_FuncLib_INI.generated.h"

UENUM(BlueprintType)
enum class EDirPath : uint8
{
	EDP_RootDir				UMETA(Displayname="RootDir"),
	EDP_ProjectDir			UMETA(Displayname="ProjectDir"),
	EDP_ProjectConfigDir	UMETA(Displayname="ProjectConfigDir"),
	EDP_ProjectContentDir	UMETA(Displayname="ProjectContentDir"),
	EDP_ProjectLogDir		UMETA(Displayname="ProjectLogDir"),
	EDP_ProjectPluginsDir	UMETA(Displayname="ProjectPluginsDir"),
	EDP_ProjectSavedDir		UMETA(Displayname="ProjectSavedDir"),
	EDP_ProjectUserDir		UMETA(Displayname="ProjectUserDir"),
	EDP_EngineDir			UMETA(Displayname="EngineDir"),
	EDP_EngineConfigDir		UMETA(Displayname="EngineConfigDir"),
	EDP_EngineContentDir	UMETA(Displayname="EngineContentDir"),
	EDP_EnginePluginsDir	UMETA(Displayname="EnginePluginsDir"),
	EDP_EngineSavedDir		UMETA(Displayname="EngineSavedDir"),
	EDP_EngineSourceDir		UMETA(Displayname="EngineSourceDir"),
	EDP_LaunchDir			UMETA(Displayname="LaunchDir"),
	EDP_GameSourceDir		UMETA(Displayname="GameSourceDir")
};

UCLASS(BlueprintType)
class FH_INI_API UFH_FuncLib_INI : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

/* My Code */
public:
	// Enum Convert To String
	UFUNCTION(BlueprintPure, Category="FH|INI|Convert")
	static FString ConvertPathToString(const EDirPath EDP);

	// Check Local File Exists
	UFUNCTION(BlueprintPure, Category="FH|INI|Check")
	static bool IsLocalFileExists(const FString& FilePath);

	// Create INI File
	UFUNCTION(BlueprintPure, Category="FH|INI|Init")
	static FString GenerateFilePath(const FString& RelativePath, const FString& FileName, FString& Path, const EDirPath EDP = EDirPath::EDP_ProjectDir);

	// Init INI File
	UFUNCTION(BlueprintPure, Category="FH|INI|Init")
	static bool InitConfigINIByStr(const FString& RelativePath, const FString& FileName, FString& Path);

	UFUNCTION(BlueprintPure, Category="FH|INI|Init")
	static bool InitConfigINIByEnum(const EDirPath EDP, const FString& RelativePath, const FString& FileName, FString& Path);

	// Read INI File
	UFUNCTION(BlueprintPure, Category="FH|INI|Read")
	static bool ReadConfigINIByStr(const FString& Path, const FString& Section, const FString& Key, FString& Value);

	UFUNCTION(BlueprintPure, Category="FH|INI|Read")
	static bool ReadConfigINIByEnum(const EDirPath EDP, const FString& RelativePath, const FString& FileName, const FString& Section, const FString& Key, FString& Value);

	// Write INI File
	UFUNCTION(BlueprintPure, Category="FH|INI|Write")
	static bool WriteConfigInIByStr(const FString& Path, const FString& Section, const FString& Key, const FString& Value);

	UFUNCTION(BlueprintPure, Category="FH|INI|Write")
	static bool WriteConfigInIByEnum(const EDirPath EDP, const FString& RelativePath, const FString& FileName, const FString& Section, const FString& Key, const FString& Value);
};