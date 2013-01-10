#include "StdAfx.h"
#include "NoteEndpointTraits.h"

namespace Effects
{
	NoteEndpointTraits::NoteEndpointTraits(void)
	{
	}


	NoteEndpointTraits::~NoteEndpointTraits(void)
	{
	}


	EndpointType NoteEndpointTraits::GetType() const
	{
		return ET_NOTE;
	}
}
