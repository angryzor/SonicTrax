#include "StdAfx.h"
#include "NumberEndpointTraits.h"


namespace Effects
{
	NumberEndpointTraits::NumberEndpointTraits(void)
	{
	}


	NumberEndpointTraits::~NumberEndpointTraits(void)
	{
	}

	EndpointType NumberEndpointTraits::GetType() const
	{
		return ET_NUMBER;
	}
}
