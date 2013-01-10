#pragma once
#include <sstream>

namespace Effects
{
	class CompilationContext
	{
	public:
		CompilationContext(void);
		virtual ~CompilationContext(void);

		void AddCodeLine(const std::string& code);
		void NewLine();
		CompilationContext& operator<<(const std::string& code);

		std::string GetCode() const;

	private:
		std::ostringstream		code_;
	};
}
