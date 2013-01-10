#pragma once
#include "endpointtraits.h"

namespace Effects
{
	class NoteEndpointTraits :
		public EndpointTraits
	{
	public:
		NoteEndpointTraits(void);
		virtual ~NoteEndpointTraits(void);
		virtual EndpointType GetType() const;
	};
}
