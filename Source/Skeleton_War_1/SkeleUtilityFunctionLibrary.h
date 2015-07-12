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

};


