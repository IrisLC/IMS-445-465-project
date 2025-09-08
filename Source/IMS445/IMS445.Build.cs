// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class IMS445 : ModuleRules
{
	public IMS445(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
