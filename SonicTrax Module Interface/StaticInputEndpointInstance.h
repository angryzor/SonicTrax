#pragma once
#include "inputendpointinstance.h"

namespace Effects
{
	class StaticInputEndpointInstance :
		public InputEndpointInstance
	{
	public:
		StaticInputEndpointInstance(void);
		virtual ~StaticInputEndpointInstance(void);

		virtual void Compile(TotalCompilationContext& tcc, EffectCompilationContext& ecc) const;
	};
}
