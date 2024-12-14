#ifndef DATE_SERIALIZATION_HPP
#define DATE_SERIALIZATION_HPP

#include <iostream>
#include <stdexcept>
using namespace std;

class Date {
public:
    int day;
    int month;
    int year;

    Date(int day, int month, int year); // Constructor with error handling

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    void addDays(int days);
    void addMonths(int months);
    void addYears(int years);
    int calculateDateDifference(const Date& other) const;
    static bool isLeapYear(int year);
    static int getDaysInMonth(int month, int year);
};

#endif
