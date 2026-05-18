#ifndef MILTIME_H
#define MILTIME_H

#include "Time.h"

class MilTime : public Time
{
private:
    int milHours;
    int milSeconds;
    bool isPM;

public:
    MilTime() : Time(), milHours(0), milSeconds(0), isPM(false) {}

    MilTime(int milHrs, int milSec)
    {
        setTime(milHrs, milSec);
    }

    void setTime(int milHrs, int milSec)
    {
        // validation
        if (milHrs < 0 || milHrs > 2359 || milSec < 0 || milSec > 59)
        {
            milHours = 0;
            milSeconds = 0;
            hour = 12;
            min = 0;
            sec = 0;
            isPM = false;
            return;
        }

        milHours = milHrs;
        milSeconds = milSec;

        int h = milHrs / 100;
        int m = milHrs % 100;

        min = m;
        sec = milSec;

        // conversion logic
        if (h == 0)
        {
            hour = 12;
            isPM = false;
        }
        else if (h == 12)
        {
            hour = 12;
            isPM = true;
        }
        else if (h > 12)
        {
            hour = h - 12;
            isPM = true;
        }
        else
        {
            hour = h;
            isPM = false;
        }
    }

    int getMilHour() const
    {
        return (milHours/100);
    }
    int getMilMin() const{
        return (milHours%100);
    }
    int getStandHr() const
    {
        return hour;
    }
    bool getIsPM() const
    {
        return isPM;
    }
};
#endif