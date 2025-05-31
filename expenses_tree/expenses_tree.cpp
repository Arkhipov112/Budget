#include "expenses_tree.hpp"

#include <sstream>

void ExpensesTree::addExpense(const std::string& path, const Expense& expense) {
    std::vector<std::string> nodes = splitPath(path);

    ExpensesNode* current = &root;

    for (const auto& node : nodes) {
        current = current->findOrCreateChild(node);
    }

	current->addExpense(expense);
}

std::vector<Expense> ExpensesTree::getAllExpenses(const std::string& path) const {
    const ExpensesNode* current = getExpensesNode(path);

    if (current == nullptr) {
        return std::vector<Expense>();
    }

    std::vector<Expense> all_expenses;
    recursiveExpensesCollection(current, all_expenses);

    return all_expenses;
}

std::vector<std::string> ExpensesTree::splitPath(const std::string& path) const {
    std::vector<std::string> nodes;

    std::istringstream iss(path);
    std::string token;

    while (std::getline(iss, token, ':')) {
        nodes.push_back(token);
    }

    return nodes;
}

const ExpensesNode* ExpensesTree::getExpensesNode(const std::string& path) const {
    std::vector<std::string> nodes = splitPath(path);

    const ExpensesNode* current = &root;

    for (const auto& node : nodes) {
        auto child = current->getChildren().find(node);
        if (child == current->getChildren().end()) {
            return nullptr;
        }

        current = &(child->second);
    }

    return current;
}

void ExpensesTree::recursiveExpensesCollection(const ExpensesNode* expense_node, std::vector<Expense>& all_expenses) {
    all_expenses.insert(all_expenses.end(), expense_node->getExpenses().begin(), expense_node->getExpenses().end());

    for (auto& child : expense_node->getChildren()) {
        recursiveExpensesCollection(&child.second, all_expenses);
    }
}