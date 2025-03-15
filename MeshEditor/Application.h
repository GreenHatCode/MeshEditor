#pragma once
#include "Command.h"
#include <iostream>

class Application
{
public:
	void registerCommand(std::unique_ptr<Command> command);
	int execute(int argc, char* argv[]);

private:
	//todo
};

