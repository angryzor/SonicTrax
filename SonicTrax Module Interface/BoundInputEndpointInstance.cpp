#include "StdAfx.h"
#include "BoundInputEndpointInstance.h"

namespace Effects
{
	BoundInputEndpointInstance::BoundInputEndpointInstance(OutputBinding& ob) : binding_(ob)
	{
	}


	BoundInputEndpointInstance::~BoundInputEndpointInstance(void)
	{
	}
	
	void BoundInputEndpointInstance::Compile(TotalCompilationContext& tcc, EffectCompilationContext& ecc) const
	{
		binding_.Compile(tcc,ecc);
	}

	std::string BoundInputEndpointInstance::GetInvoke(TotalCompilationContext& tcc, EffectCompilationContext& ecc) const
	{
		return binding_.GetInvoke(tcc,ecc);
	}
}
