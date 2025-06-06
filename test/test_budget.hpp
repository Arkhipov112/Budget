#pragma once

#include "../googletest/googletest/include/gtest/gtest.h"

#include "../budget/budget.hpp"

TEST(BudgetTest, Setters_Getters) {
    Budget budget(std::vector<std::string>("Auto", "Products"), 1400);

    EXPECT_EQ(budget.getPathList().size(), 2);

    EXPECT_EQ(budget.getPathList()[0], "Auto");
    EXPECT_EQ(budget.getPathList()[1], "Products");
    EXPECT_EQ(budget.getAmount(), 1400);
}