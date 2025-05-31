#pragma once

#include "../expenses_tree/expenses_tree.hpp"
#include "../budget/budget.hpp"

class CheckingBudgetExecution final {
public:
    CheckingBudgetExecution() = delete;
    static double getTotalExpense(const ExpensesTree& expenses_tree, const Date& date_1, const Date& date_2, const Budget& budget);
    static double getOtherExpense(const ExpensesTree& expenses_tree, const Date& date_1, const Date& date_2, const Budget& budget);
};