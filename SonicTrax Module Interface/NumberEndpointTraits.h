#pragma once
#include "endpointtraits.h"
namespace Effects
{
	class NumberEndpointTraits :
		public EndpointTraits
	{
	public:
		NumberEndpointTraits(void);
		virtual ~NumberEndpointTraits(void);
		virtual EndpointType GetType() const;
	};
}
