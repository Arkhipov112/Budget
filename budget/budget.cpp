#include "budget.hpp"

Budget::Budget() : amount(0) {}

void Budget::addPath(const std::string& path) {
	this->path_list.push_back(path);
}

void Budget::setAmount(double amount) noexcept {
	this->amount = amount;
}

const std::vector<std::string>& Budget::getPathList() const noexcept {
	return path_list;
}

double Budget::getAmount() const noexcept {
	return amount;
}