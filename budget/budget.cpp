#include "budget.hpp"

Budget::Budget(const std::vector<std::string>& path_list, double amount) : path_list(path_list), amount(amount) {}

const std::vector<std::string>& Budget::getPathList() const noexcept {
	return path_list;
}

double Budget::getAmount() const noexcept {
	return amount;
}