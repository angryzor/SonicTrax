#pragma once
#include "effect.h"

#include <string>

namespace Effects
{
	class LeafEffect :
		public Effect
	{
	public:
		LeafEffect(std::string name, std::string code);
		virtual ~LeafEffect(void);
		virtual void Compile(TotalCompilationContext& tcc) const;
		
	private:
		std::string code_;
	};
}
