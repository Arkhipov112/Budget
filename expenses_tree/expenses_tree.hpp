#pragma once

#include "../expenses_node/expenses_node.hpp"

class ExpensesTree final {
public:
    ExpensesTree() = default;

    void addExpense(const std::string& path, const Expense& expense);
    std::vector<Expense> getAllExpenses(const std::string& path) const;

private:
    std::vector<std::string> splitPath(const std::string& path) const;
    const ExpensesNode* getExpensesNode(const std::string& path) const;

    static void recursiveExpensesCollection(const ExpensesNode* expense_node, std::vector<Expense>& all_expenses);

    ExpensesNode root;
};