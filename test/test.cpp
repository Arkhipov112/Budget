#include "../expense/expense.hpp"
#include "../parser/parser.hpp"

#include <iomanip>
#include <sstream>

int main() {
    std::istringstream iss_expenses(
        "24.11.2014 Auto:Fuel 1400\n"       \
        "23.11.2014 Products:Meat 500\n"    \
        "23.11.2014 Products:Bread 90.33\n" \
        "14.11.2014 Catering:Canteen 190"
    );

    std::istringstream iss_budget(
        "Auto 6000\n"                   \
        "Products + Catering 10000\n"   \
        "Alcohol:Beer 900"
    );

    expense_tree et = parser::parse_expenses(iss_expenses);
    budget b = parser::parse_budget(iss_budget);

    for (size_t i = 0; i < b.size(); ++i) {
        double amount = et.find_expense(b[i].first)->get_amount();
    
        std::cout << std::left << std::setw(10) << b[i].first;
        std::cout << std::left << std::setw(10) << b[i].second;
        std::cout << std::left << std::setw(10) << amount;
        std::cout << std::left << std::setw(10) << (amount / b[i].second) * 100 << '%';
        std::cout << std::endl;
    }
}