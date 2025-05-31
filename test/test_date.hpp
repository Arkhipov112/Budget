#pragma once

#include "../googletest/googletest/include/gtest/gtest.h"

#include "../date/date.hpp"

TEST(DateTest, Constructor_Getters) {
    Date date("23.11.2014");
    EXPECT_EQ(date.getDay(), 23);
    EXPECT_EQ(date.getMonth(), 11);
    EXPECT_EQ(date.getYear(), 2014);
}

TEST(DateTest, Constructor_InvalidDay) {
    EXPECT_THROW(Date("32.11.2014"), std::invalid_argument);
}

TEST(DateTest, Constructor_InvalidMonth) {
    EXPECT_THROW(Date("23.13.2014"), std::invalid_argument);
}

TEST(DateTest, Constructor_InvalidYear) {
    EXPECT_THROW(Date("23.11.-2014"), std::invalid_argument);
}