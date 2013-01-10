#include "StdAfx.h"
#include "StaticNumberInputEndpointInstance.h"

#include <sstream>

namespace Effects
{
	using namespace std;

	StaticNumberInputEndpointInstance::StaticNumberInputEndpointInstance(float number) : number_(number)
	{
	}


	StaticNumberInputEndpointInstance::~StaticNumberInputEndpointInstance(void)
	{
	}

	std::string StaticNumberInputEndpointInstance::GetInvoke(TotalCompilationContext& tcc, EffectCompilationContext& ecc) const
	{
		ostringstream oss;
		oss << number_;
		return oss.str();
	}
}
