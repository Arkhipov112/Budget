#pragma once

#include "../googletest/googletest/include/gtest/gtest.h"

#include "../expense/expense.hpp"

TEST(ExpenseTest, OperatorEqual_1) {
    Expense expense(Date("23.11.2014"), 10);
    EXPECT_TRUE(expense == expense);
}

TEST(ExpenseTest, OperatorEqual_2) {
    Expense expense_1(Date("23.11.2014"), 10);
    Expense expense_2(Date("22.11.2014"), 10);

    EXPECT_FALSE(expense_1 == expense_2);
}

TEST(ExpenseTest, OperatorEqual_3) {
    Expense expense_1(Date("23.11.2014"), 10);
    Expense expense_2(Date("23.10.2014"), 10);

    EXPECT_FALSE(expense_1 == expense_2);
}

TEST(ExpenseTest, OperatorEqual_4) {
    Expense expense_1(Date("23.11.2014"), 10);
    Expense expense_2(Date("23.11.2013"), 10);

    EXPECT_FALSE(expense_1 == expense_2);
}

TEST(ExpenseTest, OperatorEqual_5) {
    Expense expense_1(Date("23.11.2014"), 10);
    Expense expense_2(Date("23.11.2014"), 9);

    EXPECT_FALSE(expense_1 == expense_2);
}