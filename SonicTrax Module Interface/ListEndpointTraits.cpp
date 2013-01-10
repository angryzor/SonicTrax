#include "StdAfx.h"
#include "ListEndpointTraits.h"


namespace Effects
{
	ListEndpointTraits::ListEndpointTraits(void)
	{
	}


	ListEndpointTraits::~ListEndpointTraits(void)
	{
	}


	EndpointType ListEndpointTraits::GetType() const
	{
		return ET_LIST;
	}
}
