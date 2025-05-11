#pragma once
#include <map>
#include <string>
#include <vector>

struct Date final {
public:
    Date() = default;
    Date(const std::string& dd_mm_yyyy);

    int getDay() const noexcept;
    int getMonth() const noexcept;
    int getYear() const noexcept;

private:
    bool isLeapYear(int year) const noexcept;
    int daysInMonth(int month, int year) const noexcept;

    int day, month, year;
};



struct ExpenseNode final {
public:
    ExpenseNode() = default;
    ExpenseNode(Date date, const std::string& name, double amount);

    ExpenseNode* addChild(const ExpenseNode& en);

    Date getDate() const noexcept;
    std::string getName() const noexcept;
    double getAmount() const noexcept;
    
    ExpenseNode* getChild(const std::string& name);
    const std::map<std::string, ExpenseNode>& getChildren() { 
        return children;
    }

    ExpenseNode* getOrCreateChild(const std::string& name) {
        return &children[name];
    }

    void addAmount(double val) {
        amount += val;
    }

private:
    Date date;
    std::string name;
    double amount;

    std::map<std::string, ExpenseNode> children;
};



struct ExpenseTree {
public:
    ExpenseNode* findNode(const std::string& path);
    void addNode(const std::string& path, double amount);

private:
    static std::vector<std::string> splitPath(const std::string& path);

    ExpenseNode root;
};