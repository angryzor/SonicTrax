#pragma once
#include "CompilationContext.h"

#include <boost/unordered_set.hpp>

#include "EffectFwd.h"

namespace Effects
{
	class TotalCompilationContext : public CompilationContext
	{
	public:
		TotalCompilationContext(void);
		virtual ~TotalCompilationContext(void);
		bool TotalCompilationContext::IsEffectCompiled(const Effect* e);
		void TotalCompilationContext::SetEffectCompiled(const Effect* e);

	private:
		boost::unordered_set<const Effect*> compiled_effects_;
	};
}
