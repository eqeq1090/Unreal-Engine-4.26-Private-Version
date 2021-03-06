// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GroomSettings.h"
#include "UObject/Object.h"
#include "Engine/SkeletalMesh.h"
#include "GroomAsset.h"
#include "GroomCreateBindingOptions.generated.h"

UCLASS(BlueprintType, config = EditorPerProjectUserSettings, autoCollapseCategories = (Conversion), hideCategories = (Hidden))
class HAIRSTRANDSCORE_API UGroomCreateBindingOptions : public UObject
{
	GENERATED_UCLASS_BODY()

public:
	/** Skeletal mesh on which the groom has been authored. This is optional, and used only if the hair
		binding is done a different mesh than the one which it has been authored, i.e., only if the curves 
		roots and the surface geometry don't aligned and need to be wrapped/transformed. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, meta = (ShowOnlyInnerProperties), Category = Conversion)
	USkeletalMesh* SourceSkeletalMesh;

	/** Skeletal mesh on which the groom is attached to. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ShowOnlyInnerProperties), Category = BuildSettings)
	USkeletalMesh* TargetSkeletalMesh;

	/** Number of points used for the rbf interpolation */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ShowOnlyInnerProperties, ClampMin = "0", ClampMax = "100"), Category = HairInterpolation)
	int32 NumInterpolationPoints;

	/** Section to pick to transfer the position */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, meta = (ShowOnlyInnerProperties), Category = Conversion)
	int32 MatchingSection;
};
