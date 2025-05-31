#pragma once

#include "../googletest/googletest/include/gtest/gtest.h"

#include "../parser/parser.hpp"

TEST(ParserTest, ParseExpenses) {
    std::string file = 
            "24.11.2014 Auto:Fuel 1400\n"       \
            "23.11.2014 Products:Meat 500\n"    \
            "23.11.2014 Products:Bread 90.33\n" \
            "14.11.2014 Catering:Canteen 190\n" \
            "Invalid line";

    std::istringstream iss(file);

    ExpensesTree expense_tree = Parser::parseExpenses(iss);

    EXPECT_EQ(expense_tree.getAllExpenses("Auto:Fuel").size(), 1);
    EXPECT_EQ(expense_tree.getAllExpenses("Auto:Fuel")[0].getDate(), Date("24.11.2014"));
    EXPECT_EQ(expense_tree.getAllExpenses("Auto:Fuel")[0].getAmount(), 1400);

    EXPECT_EQ(expense_tree.getAllExpenses("Products").size(), 2);
    EXPECT_EQ(expense_tree.getAllExpenses("Products")[0].getDate(), Date("23.11.2014"));
    EXPECT_EQ(expense_tree.getAllExpenses("Products")[0].getAmount(), 500);
    EXPECT_EQ(expense_tree.getAllExpenses("Products")[1].getDate(), Date("23.11.2014"));
    EXPECT_EQ(expense_tree.getAllExpenses("Products")[1].getAmount(), 90.33);

    EXPECT_EQ(expense_tree.getAllExpenses("Catering:Canteen").size(), 1);
    EXPECT_EQ(expense_tree.getAllExpenses("Catering")[0].getDate(), Date("14.11.2014"));
    EXPECT_EQ(expense_tree.getAllExpenses("Catering")[0].getAmount(), 190);
}

TEST(ParserTest, ParseBudget) {
    std::string file = 
            "Auto 6000\n"               \
            "Products+Catering 10000\n" \
            "Alcohol:Beer 900\n"        \
            "Invalid line";

    std::istringstream iss(file);

    std::vector<Budget> budget = Parser::parseBudget(iss);

    EXPECT_EQ(budget.size(), 3);

    EXPECT_EQ(budget[0].getPathList()[0], "Auto");
    EXPECT_EQ(budget[0].getAmount(), 6000);

    EXPECT_EQ(budget[1].getPathList()[0], "Products");
    EXPECT_EQ(budget[1].getPathList()[1], "Catering");
    EXPECT_EQ(budget[1].getAmount(), 10000);

    EXPECT_EQ(budget[2].getPathList()[0], "Alcohol:Beer");
    EXPECT_EQ(budget[2].getAmount(), 900);
}