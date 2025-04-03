#pragma once
#include "Command.h"
#include "STLParser.h"

class Split : public Command
{
public:
	const std::string& getName() const override;
	int execute(const std::map<std::string, std::string>& args) override;

private:
	std::string m_command_name = "Split";

	Vec get_origin(const std::string str_origin);
};

