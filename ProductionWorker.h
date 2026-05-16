#ifndef PRODUCTIONWORKER_H
#define PRODUCTIONWORKER_H

#include "Employee.h"

class ProductionWorker : public Employee
{
private:
    int shift;
    double hourlyPayRate;

public:
    ProductionWorker() : Employee(),
                         shift(DAY_SHIFT),
                         hourlyPayRate(0)
    {
    }

    ProductionWorker(string name, int number, string date, int shift, double rate) : Employee(name, number, date),
                                                                                      shift(shift),
                                                                                      hourlyPayRate(rate)
    {
    }

    // accessor
    int getShift() const
    {
        return shift;
    }
    double gethourlyPayRate() const
    {
        return hourlyPayRate;
    }

    // mutator
    void setShift(int x)
    {
        if (x == DAY_SHIFT || x == NIGHT_SHIFT)
            shift = x;
    }
    void sethourlyPayRate(double rate)
    {
        hourlyPayRate = rate;
    }
};

#endif
