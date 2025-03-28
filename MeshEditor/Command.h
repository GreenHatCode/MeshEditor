#pragma once
#include <string>
#include <map>

// shows the command interface

class Command 
{
public:
	virtual ~Command(){}
	virtual const std::string& getName() const = 0;
	virtual int execute(const std::map<std::string, std::string>& args) = 0;
};
