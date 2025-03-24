#pragma once
#include "Command.h"
#include "STLParser.h"

// execute method return codes
//	0 — if succeeded.
//	1 — if R <= 0.
//	2 — if slices <= 2 or rings <= 1.
//	3 — if the filepath is incorrect.
//	4 — if one or all arguments are not specified.

class Sphere : public Command
{
public:
	const std::string& getName() const override;
	int execute(const std::map<std::string, std::string>& args) override;

private:
	std::string m_command_name = "Sphere";

	Vec get_origin(const std::string str_origin);
};

