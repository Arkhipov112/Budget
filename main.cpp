#include "parser/parser.hpp"
#include "checking_budget_execution/checking_budget_execution.hpp"

#include <fstream>
#include <iomanip>
#include <stdexcept>

int main(int argc, char* argv[]) {
    if (argc != 5) {
        throw (std::invalid_argument("Format: path_expenses_file path_budget_file date_start date_end"));
    }

    std::string path_expenses_file = argv[1];
    std::ifstream ifs_expenses(path_expenses_file);
    if (!ifs_expenses.is_open()) {
        throw (std::invalid_argument("Could not open file"));
    }

    std::string path_budget_file = argv[2];
    std::ifstream ifs_budget(path_budget_file);
    if (!ifs_expenses.is_open()) {
        throw (std::invalid_argument("Could not open file"));
    }

    Date date_start = Date(argv[3]);
    Date date_end = Date(argv[4]);
    if (date_start > date_end) {
        throw (std::invalid_argument("Invalid date value"));
    }

    ExpensesTree expenses_tree = Parser::parseExpenses(ifs_expenses);
    std::vector<Budget> budget = Parser::parseBudget(ifs_budget); 

    double other_expenses = 0;

    for (long i = 0; i < budget.size(); ++i) {
        double total_expense = CheckingBudgetExecution::getTotalExpense(expenses_tree, date_start, date_end, budget[i]);
        other_expenses += CheckingBudgetExecution::getOtherExpense(expenses_tree, date_start, date_end, budget[i]);

        std::string name;
        for (long j = 0; j < budget[i].getPathList().size(); ++j) {
            name += budget[i].getPathList()[j];
            name += "+";
        }
        name.pop_back();

        std::cout << std::setw(20) << std::left << name;
        std::cout << std::setw(20) << std::left << budget[i].getAmount();
        std::cout << std::setw(20) << std::left << total_expense;
        std::cout << std::setw(20) << std::left << total_expense / budget[i].getAmount() * 100 << "%";

        std::cout << std::endl;
    }

    std::cout << std::setw(20) << std::left << "<Other expenses>";
    std::cout << std::setw(20) << std::left << other_expenses;
}