#pragma once
#include <string>

#include "TotalCompilationContext.h"
#include "EffectCompilationContext.h"

namespace Effects
{
	class InputEndpointInstance
	{
	public:
		InputEndpointInstance(void);
		virtual ~InputEndpointInstance(void);

		virtual void Compile(TotalCompilationContext& tcc, EffectCompilationContext& ecc) const = 0;
		virtual std::string GetInvoke(TotalCompilationContext& tcc, EffectCompilationContext& ecc) const = 0;
	};
}
