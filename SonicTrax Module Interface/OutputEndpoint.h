#pragma once
#include "endpoint.h"

namespace Effects
{
	class OutputEndpoint :
		public Endpoint
	{
	public:
		OutputEndpoint(std::string name);
		virtual ~OutputEndpoint(void);
	};
}
