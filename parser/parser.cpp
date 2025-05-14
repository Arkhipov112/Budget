#include <sstream>
#include <stdexcept>

#include "parser.hpp"

namespace {
	const int EXPENSES_PARSER_COUNT = 3;
}

expense_tree parser::parse_expenses(std::istream& in) {
	expense_tree res;

	std::string line;
	while (std::getline(in, line)) {
		std::vector<std::string> temp = split(line, " ");

		if (temp.size() != EXPENSES_PARSER_COUNT) {
			throw (std::invalid_argument("Does not match the type"));
		}

		res.add_expense(calendar(temp[0]), temp[1], std::stod(temp[2]));
	}

	return res;
}



budget parser::parse_budget(std::istream& in) {
	budget res;

	std::string line;
	while (std::getline(in, line)) {
		std::vector<std::string> temp = split(line, " +");

		std::pair<std::vector<std::string>, double> pair;
		for (int i = 0; i < temp.size() - 1; ++i) {
			pair.first.push_back(temp[i]);
		}
		pair.second = std::stod(temp[temp.size() - 1]);

		res.push_back(pair);
	}

	return res;
}



std::vector<std::string> parser::split(const std::string& line, const std::string& delims) {
	std::vector<std::string> res;

	std::istringstream iss(line);
	std::string token;

	char c;
	while (iss.get(c)) {
		if (delims.find(c) != std::string::npos) {
			if (!token.empty()) {
				res.push_back(token);
				token.clear();
			}
		}

		else {
			token += c;
		}
	}

	if (!token.empty()) {
		res.push_back(token);
	}

	return res;
}