#include <sstream>
#include <stdexcept>

#include "expense.hpp"

calendar::calendar() : day(0), month(0), year(0) {}

calendar::calendar(const std::string& dd_mm_yyyy) {
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
        throw (std::invalid_argument("Year cannot be negative"));
    }

    if ((month < 1) || (month > 12)) {
        throw (std::invalid_argument("Month takes a value from 1 to 12"));
    }

    if ((day < 1) || (day > days_in_month(month, year))) {
        throw (std::invalid_argument("Invalid day value"));
    }
}

int calendar::get_day() const noexcept {
    return day;
}

int calendar::get_month() const noexcept {
    return month;
}

int calendar::get_year() const noexcept {
    return year;
}

bool calendar::is_leap_year(int year) const noexcept {
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

int calendar::days_in_month(int month, int year) const noexcept {
    static const int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if ((month == 2) && is_leap_year(year)) {
        return days[1] + 1;
    }

    return days[month];
}



expense_node::expense_node() : amount(0) {}

expense_node::expense_node(calendar date, const std::string& name, double amount)
: date(date), name(name), amount(amount) {
    if (name.empty()) {
        throw (std::invalid_argument("Name cannot be empty"));
    }

    else if (amount < 0) {
        throw (std::invalid_argument("Amount cannot be negative"));
    }
}

void expense_node::update_expense(calendar date, double amount) {
    if (amount < 0) {
        throw (std::invalid_argument("Amount cannot be negative"));
    }

    this->date = date;
    this->amount += amount;
}

calendar expense_node::get_date() const noexcept {
    return date;
}

std::string expense_node::get_name() const noexcept {
    return name;
}

double expense_node::get_amount() const noexcept {
    return amount;
}

expense_node* expense_node::get_child(const std::string& name) {
    if (name.empty()) {
        throw (std::invalid_argument("Name cannot be empty"));
    }

    auto child = children.find(name);
    return (child != children.end()) ? &child->second : nullptr;
}

std::vector<expense_node*> expense_node::get_children() {
    std::vector<expense_node*> res;

    for (auto& child : children) {
        res.push_back(&child.second);
    }

    return res;
}

expense_node* expense_node::get_or_create_child(const std::string& name) {
    expense_node* res = &children[name];
    res->name = name;

    return res;
}



std::vector<std::string> expense_tree::split_path(const std::string& path) const {
    std::vector<std::string> nodes;
    
    std::istringstream iss(path);
    std::string part;
    
    while (std::getline(iss, part, ':')) {
        nodes.push_back(part);
    }

    return nodes;
}

void expense_tree::add_expense(calendar date, const std::string& path, double amount) {
    std::vector<std::string> nodes = split_path(path);

    expense_node* current = &root;

    for (const auto& node : nodes) {
        current = current->get_or_create_child(node);
        current->update_expense(date, amount);
    }
};

expense_node* expense_tree::find_expense(const std::string& path) {
    std::vector<std::string> nodes = split_path(path);

    expense_node* current = &root;

    for (const auto& node : nodes) {
        current = current->get_child(node);
        
        if (!current) {
            return nullptr;
        }
    }

    return current;
}
