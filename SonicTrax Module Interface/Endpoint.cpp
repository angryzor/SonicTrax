#include "StdAfx.h"
#include "Endpoint.h"

namespace Effects
{
	Endpoint::Endpoint(std::string name) : name_(name)
	{
	}


	Endpoint::~Endpoint(void)
	{
	}


	std::string Endpoint::GetName()
	{
		return name_;
	}
}