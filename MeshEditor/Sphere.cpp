#include "Sphere.h"

const std::string& Sphere::getName() const
{
	return m_command_name;
}

int Sphere::execute(const std::map<std::string, std::string>& args)
{
	return 0;
}

Vec Sphere::get_origin(const std::string str_origin)
{
	return Vec();
}
