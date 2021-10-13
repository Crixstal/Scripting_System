#include "Script.hpp"

Script::Script(const char* fileName, const char* functionName)
{
	std::vector<const char*> names;

	names.push_back(functionName);

	scripts[fileName] = names;


	//auto module = pybind11::module::import(fileName);
	//auto function = module.attr(functionName);
}