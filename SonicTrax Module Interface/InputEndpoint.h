#pragma once
#include "endpoint.h"

namespace Effects
{
	class InputEndpoint :
		public Endpoint
	{
	public:
		InputEndpoint(std::string name);
		virtual ~InputEndpoint(void);
	};
}
