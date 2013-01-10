#pragma once
#include "inputendpointinstance.h"

#include "OutputBinding.h"

namespace Effects
{
	class BoundInputEndpointInstance :
		public InputEndpointInstance
	{
	public:
		BoundInputEndpointInstance(OutputBinding& ob);
		virtual ~BoundInputEndpointInstance(void);

		virtual void Compile(TotalCompilationContext& tcc, EffectCompilationContext& ecc) const;
		virtual std::string GetInvoke(TotalCompilationContext& tcc, EffectCompilationContext& ecc) const;

	protected:
		OutputBinding binding_;
	};
}
