#pragma once
#include "../expense/expense.hpp"

#include <iostream>
#include <string>
#include <vector>

class parser final {
public:
	parser() = delete;

private:
	static std::vector<std::string> split(const std::string& line, const std::string& delims);
};