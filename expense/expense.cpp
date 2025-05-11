#include <sstream>
#include <stdexcept>
#include <vector>

#include "expense.hpp"

Date::Date(const std::string& dd_mm_yyyy) {
    std::vector<std::string> date;
    
    std::istringstream iss(dd_mm_yyyy);
    std::string part;
    
    while (std::getline(iss, part, '.')) {
        date.push_back(part);
    }

    if (date[0].empty() || date[1].empty() || date[2].empty()) {
        throw (std::invalid_argument("Does not match the format"));
    }

    day = std::stoi(date[0]);
    month = std::stoi(date[1]);
    year = std::stoi(date[2]);

    if (year < 0) {
        throw(std::invalid_argument("Year cannot be negative"));
    }

    if ((month < 1) || (month > 12)) {
        throw (std::invalid_argument("Month takes a value from 1 to 12"));
    }

    if ((day < 1) || (day > daysInMonth(month, year))) {
        throw (std::invalid_argument("Invalid day value"));
    }
}

int Date::getDay() const noexcept {
    return day;
}

int Date::getMonth() const noexcept {
    return month;
}

int Date::getYear() const noexcept {
    return year;
}

bool Date::isLeapYear(int year) const noexcept {
    if (year % 4) {
        return false;
    }

    else if (year % 100) {
        return true;
    }

    else {
        return !(year % 400);
    }
}

int Date::daysInMonth(int month, int year) const noexcept {
    static const int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if ((month == 2) && isLeapYear(year)) {
        return days[1] + 1;
    }

    return days[month];
}



ExpenseNode::ExpenseNode(Date date, const std::string& name, double amount) 
: date(date), name(name), amount(amount) {
    if (name.empty()) {
        throw(std::invalid_argument("Name cannot be empty"));
    }

    else if (amount < 0) {
        throw(std::invalid_argument("Amount cannot be negative"));
    }
}

ExpenseNode* ExpenseNode::addChild(const ExpenseNode& en) {
    amount += en.getAmount();
    return &children[en.getName()];
}

Date ExpenseNode::getDate() const noexcept {
    return date;
}

std::string ExpenseNode::getName() const noexcept {
    return name;
}

double ExpenseNode::getAmount() const noexcept {
    return amount;
}

ExpenseNode* ExpenseNode::getChild(const std::string& name) {
    auto child = children.find(name);
    return (child != children.end()) ? &child->second : nullptr;
}



std::vector<std::string> ExpenseTree::splitPath(const std::string& path) {
    std::vector<std::string> nodes;

    std::istringstream iss(path);
    std::string part;

    while (std::getline(iss, part, ':')) {
        nodes.push_back(part);
    }

    return nodes;
}

ExpenseNode* ExpenseTree::findNode(const std::string& path) {
    std::vector<std::string> nodes = splitPath(path);

    ExpenseNode* current = &root;

    for (const std::string& node : nodes) {
        current = current->getChild(node);
        if (!current) return nullptr;
    }

    return current;
}

void ExpenseTree::addNode(const std::string& path, double amount) {
    std::vector<std::string> nodes = splitPath(path);
    ExpenseNode* current = &root;

    for (const std::string& node : nodes) {
        current = current->getOrCreateChild(node);
        current->addAmount(amount);
    }
}