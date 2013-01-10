#pragma once
#include <vector>

#include "Effect.h"
#include "InputEndpointInstance.h"
#include "TotalCompilationContext.h"
#include "EffectCompilationContext.h"

namespace Effects
{
	class EffectInstance
	{
	public:
		typedef std::vector<InputEndpointInstance*> input_vec;

		EffectInstance(Effect& effect);
		virtual ~EffectInstance(void);
		void Compile(TotalCompilationContext& tcc, EffectCompilationContext& ecc) const;
		input_vec inputs;

	private:
		Effect& effect_;
	};
}
