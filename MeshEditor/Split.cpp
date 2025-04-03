#include "Split.h"

const std::string& Split::getName() const
{
	// TODO: insert return statement here
}

int Split::execute(const std::map<std::string, std::string>& args)
{
	return 0;
}

Vec Split::get_origin(const std::string str_origin)
{
	double e[3];
	size_t prev = 1;
	for (size_t i = 0; i < 3; i++)
	{
		size_t curr = str_origin.find_first_of(",)", prev);
		e[i] = std::stod(str_origin.substr(prev, curr - prev));
		prev = curr + 1;
	}
	return Vec(e[0], e[1], e[2]);
}
