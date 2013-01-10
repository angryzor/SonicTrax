#pragma once
#include <string>
#include <vector>

#include "InputEndpoint.h"
#include "OutputEndpoint.h"
#include "TotalCompilationContext.h"

namespace Effects
{
	class Effect
	{
	public:
		typedef std::vector<InputEndpoint*>		input_vec;
		typedef std::vector<OutputEndpoint*>	output_vec;

		Effect(std::string name);
		virtual ~Effect(void);

		std::string GetName() const;

		virtual void Compile(TotalCompilationContext& tcc) const = 0;

		input_vec	inputs;
		output_vec	outputs;

	protected:
		std::string name_;
	};
}
