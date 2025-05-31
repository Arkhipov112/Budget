#pragma once

#include "../googletest/googletest/include/gtest/gtest.h"

#include "../expenses_tree/expenses_tree.hpp"

TEST(ExpensesTreeTest, AddExpense_Getters_RecurringExpenses) {
    ExpensesTree expense_tree;
    expense_tree.addExpense("Auto:Fuel", Expense(Date("24.11.2014"), 1400));
    expense_tree.addExpense("Auto:Fuel", Expense(Date("24.11.2014"), 1400));

    EXPECT_EQ(expense_tree.getAllExpenses("Auto").size(), 2);

    EXPECT_EQ(expense_tree.getAllExpenses("Auto")[0].getDate(), Date("24.11.2014"));
    EXPECT_EQ(expense_tree.getAllExpenses("Auto")[0].getAmount(), 1400);

    EXPECT_EQ(expense_tree.getAllExpenses("Auto")[1].getDate(), Date("24.11.2014"));
    EXPECT_EQ(expense_tree.getAllExpenses("Auto")[1].getAmount(), 1400);
}

TEST(ExpensesTreeTest, AddExpense_Getters) {
    ExpensesTree expense_tree;

    expense_tree.addExpense("Products:Meat", Expense(Date("23.11.2014"), 500));
    expense_tree.addExpense("Products:Bread", Expense(Date("23.11.2014"), 90.33));

    expense_tree.addExpense("Products:Meat:Beef", Expense(Date("23.11.2014"), 400));
    expense_tree.addExpense("Products:Meat:Chicken", Expense(Date("23.11.2014"), 300));

    expense_tree.addExpense("Catering:Canteen", Expense(Date("14.11.2014"), 190));

    EXPECT_EQ(expense_tree.getAllExpenses("Products").size(), 4);
    EXPECT_EQ(expense_tree.getAllExpenses("Products:Meat").size(), 3);
    EXPECT_EQ(expense_tree.getAllExpenses("Products:Meat:Beef").size(), 1);
    EXPECT_EQ(expense_tree.getAllExpenses("Catering").size(), 1);

    EXPECT_EQ(expense_tree.getAllExpenses("Products")[0].getAmount(), 90.33);
    EXPECT_EQ(expense_tree.getAllExpenses("Products")[1].getAmount(), 500);
    EXPECT_EQ(expense_tree.getAllExpenses("Products:Meat:Beef")[0].getAmount(), 400);
    EXPECT_EQ(expense_tree.getAllExpenses("Products:Meat:Chicken")[0].getAmount(), 300);
    EXPECT_EQ(expense_tree.getAllExpenses("Catering:Canteen")[0].getAmount(), 190);
}