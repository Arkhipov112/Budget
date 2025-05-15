#pragma once
#include <map>
#include <string>
#include <vector>

typedef std::vector<std::pair<std::string, double>> budget;

class calendar final {
public:
    calendar();
    explicit calendar(const std::string& dd_mm_yyyy);

    int get_day() const noexcept;
    int get_month() const noexcept;
    int get_year() const noexcept;

private:
    bool is_leap_year(int year) const noexcept;
    int days_in_month(int month, int year) const noexcept;

    int day, month, year;
};



struct expense_node final {
public:
    expense_node();
    expense_node(const calendar& date, double amount);

    calendar date;
    double amount;

    std::string name;
    std::map<std::string, expense_node> children;
};



class expense_tree final {
public:
    expense_node* add_expense(const std::string& path, const expense_node& en);
    expense_node* find_expense(const std::string& path);

private:
    std::vector<std::string> split_path(const std::string& path) const;

    expense_node root;
};