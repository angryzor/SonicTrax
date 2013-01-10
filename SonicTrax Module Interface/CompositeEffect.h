#pragma once
#include "effect.h"

#include <vector>

#include "InputEndpointInstance.h"
#include "TotalCompilationContext.h"

namespace Effects
{
	class CompositeEffect :
		public Effect
	{
	public:
		typedef std::vector<InputEndpointInstance*>		exit_binding_vec;

		CompositeEffect(std::string name);
		virtual ~CompositeEffect(void);
		virtual void Compile(TotalCompilationContext& tcc) const;

		exit_binding_vec	exit_bindings;

	private:
		typedef std::vector<EffectInstance*>	effects_vec;

		effects_vec			effects_;
	};
}
