#pragma once

namespace Effects
{
	enum EndpointType
	{
		ET_NUMBER = 0,
		ET_LIST = 1,
		ET_NOTE = 2
	};

	class EndpointTraits
	{
	public:
		EndpointTraits(void);
		virtual ~EndpointTraits(void);
		virtual EndpointType GetType() const = 0;
	};
}
