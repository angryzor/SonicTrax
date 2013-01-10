#pragma once
#include "inputendpointinstance.h"

#include "EffectFwd.h"

namespace Effects
{
	class EntranceBoundInputEndpointInstance :
		public InputEndpointInstance
	{
	public:
		EntranceBoundInputEndpointInstance(Effect& effect, unsigned int entr_idx);
		virtual ~EntranceBoundInputEndpointInstance(void);

		virtual void Compile(TotalCompilationContext& tcc, EffectCompilationContext& ecc) const;
		virtual std::string GetInvoke(TotalCompilationContext& tcc, EffectCompilationContext& ecc) const;

	private:
		Effect& effect_;
		unsigned int entr_idx_;
	};
}

