cmake_minimum_required(VERSION 3.30.4)

set(CMAKE_CXX_STANDARD 14)

project(Budget)

add_subdirectory(
    googletest
)

add_library(
    parser
    parser/parser.cpp
    parser/parser.hpp
)

add_library(
    expense
    expense/expense.cpp
    expense/expense.hpp
)

add_executable(
    BudgetTest
    test/test.cpp
)

target_link_libraries(
    BudgetTest
    gtest
    gtest_main
    parser
    expense
)