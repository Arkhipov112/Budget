#pragma once

#include "../expenses_tree/expenses_tree.hpp"
#include "../budget/budget.hpp"

#include <iostream>

class Parser final {
public:
	Parser() = delete;
	static ExpensesTree parseExpenses(std::istream& in);
    static std::vector<Budget> parseBudget(std::istream& in);

private:
	static std::vector<std::string> splitData(const std::string& line, const std::string& delimiters);
};