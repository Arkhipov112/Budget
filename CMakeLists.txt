cmake_minimum_required(VERSION 3.30.4)

set(CMAKE_CXX_STANDARD 14)

project(Budget)

add_library(
    date
    date/date.cpp
)

add_library(
    expense
    expense/expense.cpp
)

add_library(
    expenses_node
    expenses_node/expenses_node.cpp
)

add_library(
    expenses_tree
    expenses_tree/expenses_tree.cpp
)

add_library(
    budget
    budget/budget.cpp
)

add_library(
    checking_budget_execution
    checking_budget_execution/checking_budget_execution.cpp
)

add_library(
    parser
    parser/parser.cpp
)

add_executable(
    BudgetApp
    main.cpp
)

target_link_libraries(
    BudgetApp
    date
    parser
    expense
    expenses_tree
    expenses_node
    budget
    checking_budget_execution
)