#include "../expense/expense.hpp"
#include "../parser/parser.hpp"

int main() {
    expense_tree et;
    et.add_expense(сalendar("24.11.2014"), "Auto:Fuel", 1400);
    et.add_expense(сalendar("23.11.2014"), "Products:Meat", 500);
    et.add_expense(сalendar("23.11.2014"), "Products:Bread", 99.33);
    et.add_expense(сalendar("14.11.2014"), "Catering:Canteen", 190);

    std::cout << et.find_expense("Products")->get_amount() << std::endl;
}