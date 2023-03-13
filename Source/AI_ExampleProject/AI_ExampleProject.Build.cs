// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AI_ExampleProject : ModuleRules
{
	public AI_ExampleProject(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
