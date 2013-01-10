#include "StdAfx.h"
#include "EffectInstance.h"


namespace Effects
{
	EffectInstance::EffectInstance(Effect& effect) : effect_(effect)
	{
	}


	EffectInstance::~EffectInstance(void)
	{
	}


	void EffectInstance::Compile(TotalCompilationContext& tcc, EffectCompilationContext& ecc) const
	{
		if(ecc.IsInstanceCompiled(this))
			return;

		effect_.Compile(tcc);

		for(EffectInstance::input_vec::const_iterator i(inputs.begin()); i != inputs.end(); i++)
		{
			(*i)->Compile(tcc,ecc);
		}

		ecc << "\t" << ecc.GetVarNameFor(this) << " = " << effect_.GetName() << "(";

		for(EffectInstance::input_vec::const_iterator i(inputs.begin()); i != inputs.end(); i++)
		{
			ecc << (*i)->GetInvoke(tcc,ecc);

			if(i+1 != inputs.end())
				ecc << ", ";
		}

		ecc << ");";
		ecc.NewLine();
	}
}
