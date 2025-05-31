#include "parser.hpp"

#include <sstream>

ExpensesTree Parser::parseExpenses(std::istream& in) {
	ExpensesTree expenses_tree;

	std::string line;
	while (std::getline(in, line)) {
		std::vector<std::string> split_data = splitData(line, " ");

		try {
			Expense expense(Date(split_data[0]), std::stod(split_data[2]));
			expenses_tree.addExpense(split_data[1], expense);
		}

		catch (std::exception& exception) {
			continue;
		}
	}

	return expenses_tree;
}

std::vector<Budget> Parser::parseBudget(std::istream& in) {
	std::vector<Budget> budget;

	std::string line;
	while (std::getline(in, line)) {
		std::vector<std::string> split_data = splitData(line, " +");

		try {
			std::vector<std::string> path_list;

			for (long i = 0; i < split_data.size() - 1; ++i) {
				path_list.push_back(split_data[i]);
			}

			double amount = std::stod(split_data[split_data.size() - 1]);

			budget.push_back(Budget(path_list, amount));
		}

		catch (std::exception& exception) {
			continue;
		}
	}

	return budget;
}

std::vector<std::string> Parser::splitData(const std::string& line, const std::string& delimiters) {
	std::vector<std::string> split_data;

	std::istringstream iss(line);
	std::string token;

	char current;
	while (iss.get(current)) {
		if (delimiters.find(current) != std::string::npos) {
			if (!token.empty()) {
				split_data.push_back(token);
				token.clear();
			}
		}

		else {
			token += current;
		}
	}

	if (!token.empty()) {
		split_data.push_back(token);
	}

	return split_data;
}