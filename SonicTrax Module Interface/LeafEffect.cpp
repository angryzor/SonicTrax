#include "StdAfx.h"
#include "LeafEffect.h"

#include <sstream>

namespace Effects
{
	using namespace std;

	LeafEffect::LeafEffect(std::string name, std::string code) : Effect(name), code_(code)
	{
	}


	LeafEffect::~LeafEffect(void)
	{
	}

	
	void LeafEffect::Compile(TotalCompilationContext& tcc) const
	{
		if(tcc.IsEffectCompiled(this))
			return;

		tcc << "function " << name_ << "(";

		for(input_vec::const_iterator i = inputs.begin(); i != inputs.end(); i++)
		{
			ostringstream oss;
			oss << (*i)->GetName();
			tcc << oss.str();

			if(i+1 != inputs.end())
				tcc << ", ";
		}
		tcc << ")";
		tcc.NewLine();

		tcc << "{";
		tcc.NewLine();

		tcc << "\t" << code_;
		tcc.NewLine();

		tcc << "}";
		tcc.NewLine();
		tcc.NewLine();
	}
}
