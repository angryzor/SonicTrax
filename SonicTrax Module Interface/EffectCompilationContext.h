#pragma once
#include "CompilationContext.h"

#include <string>
#include <boost/unordered_map.hpp>

#include "EffectInstanceFwd.h"

namespace Effects
{
	class EffectCompilationContext : public CompilationContext
	{
	public:
		EffectCompilationContext(void);
		virtual ~EffectCompilationContext(void);
		std::string GetNewVarName();
		bool IsInstanceCompiled(const EffectInstance* ei);
		std::string GetVarNameFor(const EffectInstance* ei);
		void SetVarNameFor(const EffectInstance* ei, const std::string name);

	private:
		typedef boost::unordered_map<const EffectInstance*,std::string> varname_map;

		unsigned int			cur_var_id_;
		varname_map				varnames_;
	};
}
