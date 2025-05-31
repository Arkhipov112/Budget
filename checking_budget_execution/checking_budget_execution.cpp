#include "checking_budget_execution.hpp"

double CheckingBudgetExecution::getTotalExpense(const ExpensesTree& expenses_tree, const Date& date_1, const Date& date_2, const Budget& budget) {
    double total_expense = 0;

    for (const auto& path : budget.getPathList()) {
        std::vector<Expense> expenses = expenses_tree.getAllExpenses(path);

        for (const auto& expense : expenses) {
            if (expense.getDate() >= date_1 && expense.getDate() <= date_2) {
                total_expense += expense.getAmount();
            }
        }
    }

    return total_expense;
}

double CheckingBudgetExecution::getOtherExpense(const ExpensesTree& expenses_tree, const Date& date_1, const Date& date_2, const Budget& budget) {
    double other_expense = 0;

    for (const auto& path : budget.getPathList()) {
        std::vector<Expense> expenses = expenses_tree.getAllExpenses(path);

        for (const auto& expense : expenses) {
            if (expense.getDate() < date_1 || expense.getDate() > date_2) {
                other_expense += expense.getAmount();
            }
        }
    }

    return other_expense;
}