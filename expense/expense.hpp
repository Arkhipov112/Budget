#pragma once
#include <map>
#include <string>
#include <vector>

struct сalendar final {
public:
    сalendar() noexcept;
    сalendar(const std::string& dd_mm_yyyy);

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
    expense_node() noexcept;
    expense_node(сalendar data, const std::string& name, double amount);

    void add_expense(сalendar date, double amount);

    сalendar get_date() const noexcept;
    std::string get_name() const noexcept;
    double get_amount() const noexcept;

    expense_node* get_child(const std::string& name);
    std::vector<expense_node*> get_children();

    expense_node* get_or_create_child(const std::string& name);

private:
    сalendar date;
    std::string name;
    double amount;

    std::map<std::string, expense_node> children;
};



struct expense_tree final {
public:
    void add_expense(сalendar date, const std::string& path, double amount);
    expense_node* find_expense(const std::string& path);

private:
    std::vector<std::string> split_path(const std::string& path);

    expense_node root;
};