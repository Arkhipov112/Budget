#pragma once

#include "../googletest/googletest/include/gtest/gtest.h"

#include "../expenses_node/expenses_node.hpp"

TEST(ExpensesNodeTest, FindOrCreateChild_Getters) {
    ExpensesNode expense_node;
    
    EXPECT_TRUE(expense_node.findOrCreateChild("Auto:Fuel") != nullptr);
    EXPECT_EQ(expense_node.getChildren().size(), 1);

    EXPECT_TRUE(expense_node.findOrCreateChild("Auto:Fuel") != nullptr);
    EXPECT_EQ(expense_node.getChildren().size(), 1);

    EXPECT_TRUE(expense_node.findOrCreateChild("Products:Meat") != nullptr);
    EXPECT_EQ(expense_node.getChildren().size(), 2);

    EXPECT_TRUE(expense_node.findOrCreateChild("Products:Beer") != nullptr);
    EXPECT_EQ(expense_node.getChildren().size(), 3);

    EXPECT_TRUE(expense_node.findOrCreateChild("Catering:Canteen") != nullptr);
    EXPECT_EQ(expense_node.getChildren().size(), 4);
}

TEST(ExpensesNodeTest, FindOrCreateChild_EmptyChildName) {
    ExpensesNode expense_node;
    
    EXPECT_THROW(expense_node.findOrCreateChild(""), std::invalid_argument);
}

TEST(ExpensesNodeTest, AddExpense_Getters) {
    ExpensesNode expense_node;
    expense_node.addExpense(Expense(Date("24.11.2014"), 1400));
    expense_node.addExpense(Expense(Date("23.11.2014"), 500));
    expense_node.addExpense(Expense(Date("23.11.2014"), 90.33));
    expense_node.addExpense(Expense(Date("14.11.2014"), 190));

    EXPECT_EQ(expense_node.getExpenses().size(), 4);

    EXPECT_EQ(expense_node.getExpenses()[0].getDate(), Date("24.11.2014"));
    EXPECT_EQ(expense_node.getExpenses()[0].getAmount(), 1400);

    EXPECT_EQ(expense_node.getExpenses()[1].getDate(), Date("23.11.2014"));
    EXPECT_EQ(expense_node.getExpenses()[1].getAmount(), 500);

    EXPECT_EQ(expense_node.getExpenses()[2].getDate(), Date("23.11.2014"));
    EXPECT_EQ(expense_node.getExpenses()[2].getAmount(), 90.33);

    EXPECT_EQ(expense_node.getExpenses()[3].getDate(), Date("14.11.2014"));
    EXPECT_EQ(expense_node.getExpenses()[3].getAmount(), 190);
}