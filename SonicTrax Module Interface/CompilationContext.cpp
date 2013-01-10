#include "StdAfx.h"
#include "CompilationContext.h"

namespace Effects
{
	using namespace std;

	CompilationContext::CompilationContext(void)
	{
	}


	CompilationContext::~CompilationContext(void)
	{
	}


	void CompilationContext::AddCodeLine(const std::string& code)
	{
		code_ << code << endl;
	}


	void CompilationContext::NewLine()
	{
		code_ << endl;
	}


	CompilationContext& CompilationContext::operator<<(const std::string& code)
	{
		code_ << code;
		return *this;
	}


	std::string CompilationContext::GetCode() const
	{
		return code_.str();
	}
}
