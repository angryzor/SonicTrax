#include "StdAfx.h"
#include "EffectCompilationContext.h"

namespace Effects
{
	using namespace std;

	EffectCompilationContext::EffectCompilationContext(void) : cur_var_id_(0)
	{
	}


	EffectCompilationContext::~EffectCompilationContext(void)
	{
	}

	
	std::string EffectCompilationContext::GetNewVarName()
	{
		ostringstream oss;
		oss << 'v' << cur_var_id_++;
		return oss.str();
	}


	bool EffectCompilationContext::IsInstanceCompiled(const EffectInstance* ei)
	{
		return varnames_.find(ei) != varnames_.end();
	}

		
	std::string EffectCompilationContext::GetVarNameFor(const EffectInstance* ei)
	{
		if(!IsInstanceCompiled(ei))
			return varnames_[ei] = GetNewVarName();
		else
			return varnames_[ei];
	}

	void EffectCompilationContext::SetVarNameFor(const EffectInstance* ei, const std::string name)
	{
		varnames_[ei] = name;
	}
}
