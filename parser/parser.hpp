#pragma once
#include "../expense/expense.hpp"

#include <iostream>
#include <string>
#include <vector>

class parser final {
public:
	parser() = delete;

	static expense_tree parse_expenses(std::istream& in);
	static budget parse_budget(std::istream& in);

private:
	static std::vector<std::string> split(const std::string& line, const std::string& delims);
};