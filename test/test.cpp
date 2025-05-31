#include "test_date.hpp"
#include "test_expense.hpp"
#include "test_expenses_node.hpp"
#include "test_expenses_tree.hpp"
#include "test_budget.hpp"
#include "test_parser.hpp"

int runTests() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}