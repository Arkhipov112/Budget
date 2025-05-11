#include <iostream>
#include <sstream>

#include <ctime>

#include "../expense/expense.hpp"
#include "../parser/parser.hpp"

int main() {
    ExpenseTree et;

    et.addNode("Auto:Fuel", 100);
    et.addNode("Auto:Other", 200);

    std::cout << et.findNode("Auto")->getAmount();
}