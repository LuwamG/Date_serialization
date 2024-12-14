#include "DateTime.hpp"
#include <iostream>
using namespace std;

int main() {
    try {
        DateTime dateTime(4, 2, 1999, 2, 20, 0, 0);  // 0 is the default time zone offset (UTC)
        dateTime.displayDateTime();

        // Adjust the time zone to UTC+2
        dateTime.adjustTimeZone(120);
        dateTime.displayDateTime();

        // Adjust for Daylight Saving Time
        dateTime.adjustDST(true);
        dateTime.displayDateTime();

        // Deserialize DateTime from string
        string dateTimeStr = "14/03/2024 12:30:45";
        DateTime newDateTime = DateTime::deserialize(dateTimeStr);
        newDateTime.displayDateTime();

        // Testing format
        string formatted = dateTime.format("Today is YYYY-MM-DD, and the time is HH:MM:SS");
        cout << formatted << endl;

    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
