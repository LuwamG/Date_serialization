#include "DateTime.hpp"
#include <sstream>
#include <iostream>
#include <stdexcept>
using namespace std;

DateTime::DateTime(int day, int month, int year, int hour, int minute, int second, int timeZoneOffset)
    : Date(day, month, year), Time(hour, minute, second), timeZoneOffset(timeZoneOffset) {
}

void DateTime::displayDateTime() const {
    cout << getDay() << "/" << getMonth() << "/" << getYear() << " ";
    cout << getHour() << ":" << getMinute() << ":" << getSecond() << endl;
}

void DateTime::difference(const DateTime& dt1, const DateTime& dt2) {
    int dateDiff = dt1.calculateDateDifference(dt2);
    int timeDiff = dt1.calculateTimeDifference(dt2);

    int days = dateDiff;
    int hours = timeDiff / 3600;
    int minutes = (timeDiff % 3600) / 60;
    int seconds = timeDiff % 60;

    cout << "Difference: " << days << " days, " << hours << " hours, "
        << minutes << " minutes, " << seconds << " seconds" << endl;
}

string DateTime::format(const string& formatString) const {
    string result = formatString;
    size_t pos;

    pos = result.find("YYYY");
    if (pos != string::npos) result.replace(pos, 4, to_string(getYear()));

    pos = result.find("MM");
    if (pos != string::npos) result.replace(pos, 2, to_string(getMonth()));

    pos = result.find("DD");
    if (pos != string::npos) result.replace(pos, 2, to_string(getDay()));

    pos = result.find("HH");
    if (pos != string::npos) result.replace(pos, 2, to_string(getHour()));

    pos = result.find("MM");
    if (pos != string::npos) result.replace(pos, 2, to_string(getMinute()));

    pos = result.find("SS");
    if (pos != string::npos) result.replace(pos, 2, to_string(getSecond()));

    return result;
}

void DateTime::adjustTimeZone(int newTimeZoneOffset) {
    int diff = newTimeZoneOffset - timeZoneOffset;
    addSeconds(diff * 60); // Adjust the seconds by the difference in time zone
    timeZoneOffset = newTimeZoneOffset; // Update the internal time zone offset
}

void DateTime::adjustDST(bool isDST) {
    if (isDST) {
        addHours(1); // Start DST (add 1 hour)
    }
    else {
        addHours(-1); // End DST (subtract 1 hour)
    }
}

DateTime DateTime::deserialize(const string& dateTimeStr) {
    int day, month, year, hour, minute, second;
    char separator;
    stringstream ss(dateTimeStr);
    if (!(ss >> day >> separator >> month >> separator >> year >> hour >> separator >> minute >> separator >> second)) {
        throw invalid_argument("Invalid DateTime format");
    }
    return DateTime(day, month, year, hour, minute, second);
}
