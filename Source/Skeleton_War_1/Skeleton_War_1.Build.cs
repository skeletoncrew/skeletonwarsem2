// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class Skeleton_War_1 : ModuleRules
{
	public Skeleton_War_1(TargetInfo Target)
	{
        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "OnlineSubsystem", "OnlineSubsystemUtils" });

        //PrivateDependencyModuleNames.AddRange(new string[] { "OnlineSubsystem" });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
        //PrivateDependencyModuleNames.Add("OnlineSubsystem");
        DynamicallyLoadedModuleNames.Add("OnlineSubsystemNull");

        //if ((Target.Platform == UnrealTargetPlatform.Win32) || (Target.Platform == UnrealTargetPlatform.Win64)) {
        //    if (UEBuildConfiguration.bCompileSteamOSS == true) {
        //        DynamicallyLoadedModuleNames.Add("OnlineSubsystemSteam");
        //    }
        //}
	}
}
