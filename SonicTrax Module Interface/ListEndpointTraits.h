#pragma once
#include "endpointtraits.h"

namespace Effects
{
	class ListEndpointTraits :
		public EndpointTraits
	{
	public:
		ListEndpointTraits(void);
		virtual ~ListEndpointTraits(void);
		virtual EndpointType GetType() const;
	};
}
