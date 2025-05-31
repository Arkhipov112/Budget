#include "expenses_node.hpp"

#include <stdexcept>

ExpensesNode* ExpensesNode::findOrCreateChild(const std::string& child_name) {
    if (child_name.empty()) {
        throw (std::invalid_argument("Child name could not be empty"));
    }

	auto child = children.emplace(child_name, ExpensesNode());
	return &(child.first->second);
}

const std::vector<Expense>& ExpensesNode::getExpenses() const noexcept {
    return expenses;
}

const std::map<std::string, ExpensesNode>& ExpensesNode::getChildren() const noexcept {
    return children;
}

void ExpensesNode::addExpense(const Expense& expense) {
    expenses.push_back(expense);
}