#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "../expense/expense.hpp"

class parser final {
public:
	static expense_tree parse_expenses(std::istream& in);
	static budget parse_budget(std::istream& in);

private:
	static std::string trim(const std::string& line);
	static std::string split(const std::string& line, const std::string& delims) noexcept;
	static std::vector<std::string> parse(const std::string& line);
};