#include "StdAfx.h"
#include "Effect.h"

namespace Effects
{
	Effect::Effect(std::string name) : name_(name)
	{
	}


	Effect::~Effect(void)
	{
	}

	std::string Effect::GetName() const
	{
		return name_;
	}
}
