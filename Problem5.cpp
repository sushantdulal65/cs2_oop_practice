/*Time Clock
Design a class named TimeClock. The class should be derived from the MilTime class you 
designed in Programming Challenge 4 (Time Format). The class should allow the programmer
 to pass two times to it: starting time and ending time. The class should have a member
  function that returns the amount of time elapsed between the two times. For example,
   if the starting time is 900 hours (9:00 a.m.), and the ending time is 1300 hours (1:00 p.m.),
 the elapsed time is 4 hours.
Input Validation: The class should not accept hours greater than 2359 or less than 0.*/

#include "MilTime.h"
#include <iostream>
using namespace std;

class TimeClock : public MilTime
{
private:
    MilTime startTime;
    MilTime endTime;

public:
    TimeClock(int t1, int t2)
    {
        startTime.setTime(t1, 0);
        endTime.setTime(t2, 0);
    }

    int getElapsedMinutes() const
{
    int start = startTime.getMilHour() * 60 + startTime.getMilMin();
    int end   = endTime.getMilHour() * 60 + endTime.getMilMin();

    if (end < start)
    {
        end += 24 * 60;  // handle midnight crossing
    }

    return end - start;
}

    int getElapsedHours() const
    {
        return (getElapsedMinutes() / 60);

    }
};

int main()
{
    int startTime, endTime;

    cout << "Enter start time (military format HHMM): ";
    cin >> startTime;

    cout << "Enter end time (military format HHMM): ";
    cin >> endTime;

    TimeClock clock(startTime, endTime);

    cout << "\nStart Time: " << startTime << endl;
    cout << "End Time: " << endTime << endl;

    cout << "Elapsed Time (minutes): " 
         << clock.getElapsedMinutes() << endl;

    cout << "Elapsed Time (hours): " 
         << clock.getElapsedHours() << endl;

    return 0;
}