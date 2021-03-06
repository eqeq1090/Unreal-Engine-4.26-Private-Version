// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Render/Synchronization/DisplayClusterRenderSyncPolicySoftwareBase.h"


/**
 * Generic network synchronization policy (soft sync)
 */
class FDisplayClusterRenderSyncPolicySoftwareGeneric
	: public FDisplayClusterRenderSyncPolicySoftwareBase
{
public:
	static TMap<FString, FString> DefaultParameters;

public:
	FDisplayClusterRenderSyncPolicySoftwareGeneric(const TMap<FString, FString>& Parameters);
	virtual ~FDisplayClusterRenderSyncPolicySoftwareGeneric();

public:
	//////////////////////////////////////////////////////////////////////////////////////////////
	// IDisplayClusterRenderSyncPolicy
	//////////////////////////////////////////////////////////////////////////////////////////////
	virtual bool SynchronizeClusterRendering(int32& InOutSyncInterval) override;
};
