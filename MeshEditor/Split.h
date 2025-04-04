#pragma once
#include "Command.h"
#include "STLParser.h"

// 0 — if succeeded.
// 1 — if a normal length <= 0.
// 2 — if input, output1, or output2 is incorrect.
// 3 — if one or all arguments are not specified.
// 4 — if the plane doesn’t intersect the original mesh, which becomes the result


class Split : public Command
{
public:
	const std::string& getName() const override;
	int execute(const std::map<std::string, std::string>& args) override;

private:
	std::string m_command_name = "Split";

	bool fileExists(const std::string& file_path, bool input_file);
	Vec get_origin(const std::string str_origin);
	TriangleSoup triangulate_hole(const std::vector<Vec>& vecs);
};

