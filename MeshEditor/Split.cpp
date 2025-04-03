#include "Split.h"

const std::string& Split::getName() const
{
	return m_command_name;
}

int Split::execute(const std::map<std::string, std::string>& args)
{
	if (args.count("input") != 1 || args.count("origin") != 1 || args.count("direction") != 1 || args.count("output1") != 1 || args.count("output2") != 1) return 3;
	if (get_origin(args.at("direction")).length() <= 0)return 1;
	if (fileExists(args.at("output1")) || fileExists(args.at("output2")) || fileExists(args.at("input")))return 2;







	return 0;
}

bool Split::fileExists(const std::string& file_path)
{
	std::ofstream test(file_path);
	if (!test)return false;
	else return true;
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
