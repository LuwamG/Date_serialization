#ifndef DATETIME_HPP
#define DATETIME_HPP

#include "Date_serialization.hpp"
#include "Time.hpp"
#include <string>
using namespace std;

class DateTime : public Date, public Time {
private:
    int timeZoneOffset; // Time zone offset in minutes from UTC

public:
    DateTime(int day, int month, int year, int hour, int minute, int second, int timeZoneOffset = 0);

    void displayDateTime() const;
    static void difference(const DateTime& dt1, const DateTime& dt2);
    string format(const string& formatString) const;
    void adjustTimeZone(int newTimeZoneOffset); // Adjust time to a new time zone
    void adjustDST(bool isDST); // Adjust for Daylight Saving Time (DST)
    static DateTime deserialize(const string& dateTimeStr); // Deserialize DateTime from string
};

#endif
