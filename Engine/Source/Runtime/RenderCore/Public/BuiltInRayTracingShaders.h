// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "GlobalShader.h"
#include "ShaderParameterStruct.h"
#include "ShaderParameterMacros.h"

#if RHI_RAYTRACING

class FBuiltInRayTracingShader : public FGlobalShader
{
protected:
	static void ModifyCompilationEnvironment(const FGlobalShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
	{}

public:
	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
	{
		// Built-in ray tracing shaders are always compiled for RHIs that support them, regardless of whether RT is enabled for the project.
		return RHISupportsRayTracingShaders(Parameters.Platform);
	}

	FBuiltInRayTracingShader() = default;
	FBuiltInRayTracingShader(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
		: FGlobalShader(Initializer)
	{}
};

class RENDERCORE_API FOcclusionMainRG : public FBuiltInRayTracingShader
{
	DECLARE_GLOBAL_SHADER(FOcclusionMainRG);
	SHADER_USE_ROOT_PARAMETER_STRUCT(FOcclusionMainRG, FBuiltInRayTracingShader);

	BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
		SHADER_PARAMETER_RDG_BUFFER_SRV(RaytracingAccelerationStructure, TLAS)
		SHADER_PARAMETER_RDG_BUFFER_SRV(StructuredBuffer<FBasicRayData>, Rays)
		SHADER_PARAMETER_RDG_BUFFER_UAV(RWStructuredBuffer<uint>, OcclusionOutput)
	END_SHADER_PARAMETER_STRUCT()
};

class RENDERCORE_API FIntersectionMainRG : public FBuiltInRayTracingShader
{
	DECLARE_GLOBAL_SHADER(FIntersectionMainRG);
	SHADER_USE_ROOT_PARAMETER_STRUCT(FIntersectionMainRG, FBuiltInRayTracingShader);

	BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
		SHADER_PARAMETER_RDG_BUFFER_SRV(RaytracingAccelerationStructure, TLAS)
		SHADER_PARAMETER_RDG_BUFFER_SRV(StructuredBuffer<FBasicRayData>, Rays)
		SHADER_PARAMETER_RDG_BUFFER_UAV(RWStructuredBuffer<FIntersectionPayload>, IntersectionOutput)
	END_SHADER_PARAMETER_STRUCT()
};

class FIntersectionMainCHS : public FBuiltInRayTracingShader
{
	DECLARE_EXPORTED_SHADER_TYPE(FIntersectionMainCHS, Global, RENDERCORE_API);
public:

	FIntersectionMainCHS() = default;
	FIntersectionMainCHS(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
		: FBuiltInRayTracingShader(Initializer)
	{}
};

class FDefaultMainCHS : public FBuiltInRayTracingShader
{
	DECLARE_EXPORTED_SHADER_TYPE(FDefaultMainCHS, Global, RENDERCORE_API);
public:

	FDefaultMainCHS() = default;
	FDefaultMainCHS(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
		: FBuiltInRayTracingShader(Initializer)
	{}
};

class FDefaultMainCHSOpaqueAHS : public FBuiltInRayTracingShader
{
	DECLARE_EXPORTED_SHADER_TYPE(FDefaultMainCHSOpaqueAHS, Global, RENDERCORE_API);
public:

	FDefaultMainCHSOpaqueAHS() = default;
	FDefaultMainCHSOpaqueAHS(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
		: FBuiltInRayTracingShader(Initializer)
	{}
};

class FDefaultPayloadMS : public FBuiltInRayTracingShader
{
	DECLARE_EXPORTED_SHADER_TYPE(FDefaultPayloadMS, Global, RENDERCORE_API);
public:

	FDefaultPayloadMS() = default;
	FDefaultPayloadMS(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
		: FBuiltInRayTracingShader(Initializer)
	{}
};

class FPackedMaterialClosestHitPayloadMS : public FBuiltInRayTracingShader
{
	DECLARE_EXPORTED_SHADER_TYPE(FPackedMaterialClosestHitPayloadMS, Global, RENDERCORE_API);
public:

	FPackedMaterialClosestHitPayloadMS() = default;
	FPackedMaterialClosestHitPayloadMS(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
		: FBuiltInRayTracingShader(Initializer)
	{}
};

#endif // RHI_RAYTRACING

