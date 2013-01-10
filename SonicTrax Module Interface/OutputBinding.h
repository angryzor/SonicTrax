#pragma once
#include "EffectInstance.h"

namespace Effects
{
	class OutputBinding
	{
	public:
		OutputBinding(EffectInstance& effectinst, unsigned int outputidx);
		virtual ~OutputBinding(void);

		void Compile(TotalCompilationContext& tcc, EffectCompilationContext& ecc) const;
		std::string GetInvoke(TotalCompilationContext& tcc, EffectCompilationContext& ecc) const;

	private:
		EffectInstance& effect_inst;
		unsigned int output_idx;
	};
}
