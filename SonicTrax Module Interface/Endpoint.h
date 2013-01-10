#pragma once
#include <string>

namespace Effects
{
	class Endpoint
	{
	public:
		Endpoint(std::string name);
		virtual ~Endpoint(void);
		std::string GetName();

	private:
		std::string name_;
	};
}
