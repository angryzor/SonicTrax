#include "StdAfx.h"
#include "OutputBinding.h"

#include <sstream>

namespace Effects
{
	using namespace std;

	OutputBinding::OutputBinding(EffectInstance& effectinst, unsigned int outputidx) : effect_inst(effectinst), output_idx(outputidx)
	{
	}


	OutputBinding::~OutputBinding(void)
	{
	}


	void OutputBinding::Compile(TotalCompilationContext& tcc, EffectCompilationContext& ecc) const
	{
		effect_inst.Compile(tcc,ecc);
	}


	std::string OutputBinding::GetInvoke(TotalCompilationContext& tcc, EffectCompilationContext& ecc) const
	{
		ostringstream oss;
		oss << ecc.GetVarNameFor(&effect_inst) << "[" << output_idx << "]";
		return oss.str();
	}
}
