#pragma once

#include "../date/date.hpp"

class Expense final {
public:
	explicit Expense(const Date& date, double amount = 0);

	Date getDate() const noexcept;
	double getAmount() const noexcept;

private:
	Date date;
	double amount;
};

bool operator==(const Expense& lhs, const Expense& rhs) noexcept;