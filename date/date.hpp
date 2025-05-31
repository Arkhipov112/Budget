#pragma once

#include <string>

class Date final {
public:
    explicit Date(const std::string& dd_mm_yyyy);

    int getDay() const noexcept;
    int getMonth() const noexcept;
    int getYear() const noexcept;

private:
    bool isLeapYear(int year) const noexcept;
    int daysInMonth(int month, int year) const noexcept;

    int day;
    int month;
    int year;
};

bool operator==(const Date& lhs, const Date& rhs) noexcept;
bool operator<(const Date& lhs, const Date& rhs) noexcept;
bool operator>(const Date& lhs, const Date& rhs) noexcept;
bool operator<=(const Date& lhs, const Date& rhs) noexcept;
bool operator>=(const Date& lhs, const Date& rhs) noexcept;