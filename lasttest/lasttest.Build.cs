// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class lasttest : ModuleRules
{
	public lasttest(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay",
			"EnhancedInput", 
			"Niagara", 
			"PhysicsCore", 
			"GameplayTasks", 
			"NavigationSystem" 
		
		});
		PublicIncludePaths.AddRange(new string[]{

            "lasttest/AI"

		}); 
	}
}
