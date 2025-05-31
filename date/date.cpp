#include "date.hpp"

#include <sstream>
#include <vector>

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
        throw (std::invalid_argument("Year cannot be negative"));
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

bool operator==(const Date& lhs, const Date& rhs) noexcept {
    return (lhs.getYear() == rhs.getYear()) && (lhs.getMonth() == rhs.getMonth()) && (lhs.getDay() == rhs.getDay());
}

bool operator<(const Date& lhs, const Date& rhs) noexcept {
    if (lhs.getYear() != rhs.getYear()) {
        return lhs.getYear() < rhs.getYear();
    }

    if (lhs.getMonth() != rhs.getMonth()) {
        return lhs.getMonth() < rhs.getMonth();
    }

    return lhs.getDay() < rhs.getDay();
}

bool operator>(const Date& lhs, const Date& rhs) noexcept {
    return rhs < lhs;
}

bool operator<=(const Date& lhs, const Date& rhs) noexcept {
    return !(lhs > rhs);
}

bool operator>=(const Date& lhs, const Date& rhs) noexcept {
    return !(lhs < rhs);
}