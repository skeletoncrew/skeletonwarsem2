// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "SkeleUtilityFunctionLibrary.generated.h"


/**
 *
 */
UCLASS()
class USkeleUtilityFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_UCLASS_BODY()

	/** Returns the name of the map that the given actor currently occupies. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = SkeleFunctionLibrary)
	static FString GetCurrentMapReference(AActor* sourceActor);

    /** Reads in an array of default player names from file (Config/DefaultPlayerNames.ini). */
    UFUNCTION(BlueprintCallable, Category = SkeleFunctionLibrary)
        static TArray<FString> GetDefaultPlayerNamesFromFile();

    /** Sorts the given array of scores in descending order and returns the indices of the sorted array. */
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = SkeleFunctionLibrary)
        static TArray<int32> SortPlayerScores(TArray<int32> scores);

    /** Returns the current width and height of the default monitor. */
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = SkeleFunctionLibrary)
        static void GetMonitorResolution(int32 &width, int32 &height);

    /** Returns an array of common resolutions up to the current width and height of the monitor. */
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = SkeleFunctionLibrary)
        static TArray<FString> GetValidResolutions();

    /** Returns the substring up to the first hyphen in the given string. */
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = SkeleFunctionLibrary)
        static FString ExtractHostName(FString sessionName);

    /** Counts how many names in the array have the same base name as given and returns the name with an appropriate suffix. */
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = SkeleFunctionLibrary)
        static FString GetPlayerNameWithSuffix(TArray<FString> playerNames, FString playerName);

    /** Gets a list of the inputs bound to a given action. */
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = SkeleFunctionLibrary)
        static TArray<FKey> GetKeysForAction(APlayerController* controller, const FName actionName);

    /** Returns a list of the inputs bound to the forward axis with the given scale. */
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = SkeleFunctionLibrary)
        static TArray<FKey> GetKeysForForwardAxis(APlayerController* controller, bool positiveScale);

    /** Returns a list of the inputs bound to the right axis with the given scale. */
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = SkeleFunctionLibrary)
        static TArray<FKey> GetKeysForRightAxis(APlayerController* controller, bool positiveScale);

};

