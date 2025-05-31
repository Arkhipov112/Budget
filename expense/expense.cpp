#include "expense.hpp"

Expense::Expense(const Date& date, double amount) : date(date), amount(amount) {}

Date Expense::getDate() const noexcept {
	return date;
}

double Expense::getAmount() const noexcept {
	return amount;
}

bool operator==(const Expense& lhs, const Expense& rhs) noexcept {
	return (lhs.getDate() == rhs.getDate()) && (lhs.getAmount() == rhs.getAmount());
}