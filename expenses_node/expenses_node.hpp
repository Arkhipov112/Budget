#pragma once

#include "../expense/expense.hpp"

#include <vector>
#include <map>

class ExpensesNode final {
public:
    ExpensesNode() = default;

    ExpensesNode* findOrCreateChild(const std::string& child_name);

    const std::vector<Expense>& getExpenses() const noexcept;
    const std::map<std::string, ExpensesNode>& getChildren() const noexcept;

    void addExpense(const Expense& expense);

private:
    std::vector<Expense> expenses;
    std::map<std::string, ExpensesNode> children;
};