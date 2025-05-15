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

    expense_tree et;
    et.add_expense("Auto:Fuel", expense_node(calendar("12.12.2012"), 200));
    et.add_expense("Auto:Other", expense_node(calendar("12.12.2012"), 200));

    std::cout << et.find_expense("Auto")->amount << std::endl;
}