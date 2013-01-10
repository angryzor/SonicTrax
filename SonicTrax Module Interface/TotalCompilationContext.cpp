#include "StdAfx.h"
#include "TotalCompilationContext.h"

namespace Effects
{
	TotalCompilationContext::TotalCompilationContext(void)
	{
	}


	TotalCompilationContext::~TotalCompilationContext(void)
	{
	}


	bool TotalCompilationContext::IsEffectCompiled(const Effect* e)
	{
		return compiled_effects_.find(e) != compiled_effects_.end();
	}


	void TotalCompilationContext::SetEffectCompiled(const Effect* e)
	{
		compiled_effects_.insert(e);
	}
}
