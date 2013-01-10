#include "StdAfx.h"
#include "EntranceBoundInputEndpointInstance.h"

#include "Effect.h"

namespace Effects
{
	EntranceBoundInputEndpointInstance::EntranceBoundInputEndpointInstance(Effect& effect, unsigned int entr_idx) : effect_(effect), entr_idx_(entr_idx)
	{
	}


	EntranceBoundInputEndpointInstance::~EntranceBoundInputEndpointInstance(void)
	{
	}

	
	void EntranceBoundInputEndpointInstance::Compile(TotalCompilationContext& tcc, EffectCompilationContext& ecc) const
	{
	}


	std::string EntranceBoundInputEndpointInstance::GetInvoke(TotalCompilationContext& tcc, EffectCompilationContext& ecc) const
	{
		return effect_.inputs[entr_idx_]->GetName();
	}
}