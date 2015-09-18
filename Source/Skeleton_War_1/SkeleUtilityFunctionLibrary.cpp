// Fill out your copyright notice in the Description page of Project Settings.

#include "Skeleton_War_1.h"
#include "SkeleUtilityFunctionLibrary.h"

// Constructor
USkeleUtilityFunctionLibrary::USkeleUtilityFunctionLibrary(const class FObjectInitializer& PCIP)
    : Super(PCIP) {

}

FString USkeleUtilityFunctionLibrary::GetCurrentMapReference(AActor* sourceActor) {
    if (sourceActor == NULL) {
        return FString(TEXT("Must have a sourceActor (was NULL)"));
    }

    FString mapName = sourceActor->GetWorld()->GetMapName();
    mapName.RemoveFromStart(sourceActor->GetWorld()->StreamingLevelsPrefix);

    return mapName;
}

TArray<FString> USkeleUtilityFunctionLibrary::GetDefaultPlayerNamesFromFile() {
    FString filePath = FPaths::GameDir() + "Config/DefaultPlayerNames.ini";

    FString fileContents = "";
    FFileHelper::LoadFileToString(fileContents, *filePath);

    TArray<FString> items;
    int32 itemCount = fileContents.ParseIntoArray(items, TEXT(","), true);

    if (items.Last().Contains(TEXT("\n"))) {
        items.Pop();
    }

    return items;
}


TArray<int32> USkeleUtilityFunctionLibrary::SortPlayerScores(TArray<int32> scores) {
    TArray<int32> indices;

    while (indices.Num() < scores.Num()) {
        int32 index;
        FMath::Max<int32>(scores, &index);
        indices.Add(index);
        scores[index] = MININT32;
    }

    return indices;
}

void USkeleUtilityFunctionLibrary::GetMonitorResolution(int32 &width, int32 &height) {
    FDisplayMetrics disp;
    FDisplayMetrics::GetDisplayMetrics(disp);
    width = disp.PrimaryDisplayWidth;
    height = disp.PrimaryDisplayHeight;
}

TArray<FString> USkeleUtilityFunctionLibrary::GetValidResolutions() {
    int32 width, height;
    GetMonitorResolution(width, height);

    int32 widthsArray[] = {
        1280,
        1280,
        1366,
        1440,
        1600,
        1600,
        1680,
        1920,
        1920,
        2048,
        2560,
        2560,
        3840,
        4096
    };
    int32 heightsArray[] = {
        800,
        1024,
        768,
        900,
        900,
        1200,
        1050,
        1080,
        1200,
        1080,
        1440,
        1600,
        2160,
        2160
    };

    TArray<FString> resolutions;
    for (int i = 0; i < ARRAY_COUNT(widthsArray); i++) {
        if (widthsArray[i] <= width && heightsArray[i] <= height) {
            resolutions.Add(FString::FromInt(widthsArray[i]) + "x" + FString::FromInt(heightsArray[i]));
        } else {
            break;
        }
    }

    return resolutions;
}

FString USkeleUtilityFunctionLibrary::ExtractHostName(FString sessionName) {
    int32 index;
    bool found = sessionName.FindLastChar('-', index);

    if (found) {
        return sessionName.Mid(0, index);
    } else {
        return sessionName;
    }
}

FString USkeleUtilityFunctionLibrary::GetPlayerNameWithSuffix(TArray<FString> playerNames, FString playerName) {
    int count = 1;
    FString tempName = playerName;

    while (playerNames.Contains(tempName)) {
        count++;
        tempName = playerName + FString::FromInt(count);
    }

    return tempName;
}

TArray<FKey> USkeleUtilityFunctionLibrary::GetKeysForAction(APlayerController* controller, const FName actionName) {
	TArray<FInputActionKeyMapping> mappings = controller->PlayerInput->GetKeysForAction(actionName);
	TArray<FKey> keys;
	for (auto mapping : mappings) {
		keys.Add(mapping.Key);
	}
	return keys;
}

TArray<FKey> USkeleUtilityFunctionLibrary::GetKeysForForwardAxis(APlayerController* controller, bool positiveScale) {
    TArray<FKey> keys;
    for (auto mapping : controller->PlayerInput->AxisMappings) {
        if (mapping.AxisName == FName(TEXT("MoveForward"))) {
            if ((positiveScale && mapping.Scale > 0) || (!positiveScale && mapping.Scale < 0)) {
                keys.Add(mapping.Key);
            }
        }
    }
    return keys;
}

TArray<FKey> USkeleUtilityFunctionLibrary::GetKeysForRightAxis(APlayerController* controller, bool positiveScale) {
    TArray<FKey> keys;
    for (auto mapping : controller->PlayerInput->AxisMappings) {
        if (mapping.AxisName == FName(TEXT("MoveRight"))) {
            if ((positiveScale && mapping.Scale > 0) || (!positiveScale && mapping.Scale < 0)) {
                keys.Add(mapping.Key);
            }
        }
    }
    return keys;
}

 bool USkeleUtilityFunctionLibrary::FileSaveString(FString SaveTextB, FString FileNameB)
 {
     return FFileHelper::SaveStringToFile(SaveTextB, *(FPaths::GameDir() + "GameLogs/GameLog-" + FileNameB));
 }
