#include "Time.hpp"
#include <stdexcept>
using namespace std;

Time::Time(int hour, int minute, int second) {
    if (hour < 0 || hour >= 24 || minute < 0 || minute >= 60 || second < 0 || second >= 60) {
        throw invalid_argument("Invalid time values");
    }
    this->hour = hour;
    this->minute = minute;
    this->second = second;
}

int Time::getHour() const { return hour; }
int Time::getMinute() const { return minute; }
int Time::getSecond() const { return second; }

void Time::addSeconds(int seconds) {
    second += seconds;
    while (second >= 60) {
        second -= 60;
        minute++;
    }
    while (second < 0) {
        second += 60;
        minute--;
    }
    while (minute >= 60) {
        minute -= 60;
        hour++;
    }
    while (minute < 0) {
        minute += 60;
        hour--;
    }
    while (hour >= 24) {
        hour -= 24;
    }
    while (hour < 0) {
        hour += 24;
    }
}

void Time::addMinutes(int minutes) {
    addSeconds(minutes * 60);
}

void Time::addHours(int hours) {
    addSeconds(hours * 3600);
}

int Time::calculateTimeDifference(const Time& other) const {
    int totalSeconds = 0;
    Time temp = *this;
    while (temp.hour != other.hour || temp.minute != other.minute || temp.second != other.second) {
        temp.addSeconds(other.second > temp.second ? 1 : -1);
        totalSeconds++;
    }
    return totalSeconds;
}
