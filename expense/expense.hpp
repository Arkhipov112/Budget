#pragma once
#include <map>
#include <string>
#include <vector>

typedef std::vector<std::pair<std::vector<std::string>, double>> budget;

struct calendar final {
public:
    calendar();
    calendar(const std::string& dd_mm_yyyy);

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
    expense_node(calendar data, const std::string& name, double amount);

    void update_expense(calendar date, double amount);

    calendar get_date() const noexcept;
    std::string get_name() const noexcept;
    double get_amount() const noexcept;

    expense_node* get_child(const std::string& name);
    std::vector<expense_node*> get_children();

    expense_node* get_or_create_child(const std::string& name);

private:
    calendar date;
    std::string name;
    double amount;

    std::map<std::string, expense_node> children;
};



struct expense_tree final {
public:
    void add_expense(calendar date, const std::string& path, double amount);
    expense_node* find_expense(const std::string& path);

private:
    std::vector<std::string> split_path(const std::string& path) const;

    expense_node root;
};