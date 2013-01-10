#pragma once
#include "staticinputendpointinstance.h"

namespace Effects
{
	class StaticNumberInputEndpointInstance :
		public StaticInputEndpointInstance
	{
	public:
		StaticNumberInputEndpointInstance(float number);
		virtual ~StaticNumberInputEndpointInstance(void);

		virtual std::string GetInvoke(TotalCompilationContext& tcc, EffectCompilationContext& ecc) const;

	private:
		float number_;
	};
}