#pragma once
#include "Command.h"

// execute method return codes
// 0 — if succeeded. 
// 1 — if L <= 0. 
// 2 — if the filepath is incorrect. 
// 3 — if one or all arguments are not specified
//

class Cube : public Command
{
public:
	const std::string& getName() const override;
	int execute(const std::map<std::string, std::string>& args) override;

private:
	// todo: implement
	std::string m_command_name = "Cube";
};

