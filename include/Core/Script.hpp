#pragma once

#include <pybind11/embed.h>
#include <unordered_map>

class Script
{
	private:
		std::unordered_map<const char*, std::vector<const char*>>	scripts;
		//std::shared_ptr<auto> test;
		Script(const char* fileName, const char* functionName);
};