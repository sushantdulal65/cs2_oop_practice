#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;
enum
{
    DAY_SHIFT = 1,
    NIGHT_SHIFT = 2
};
class Employee
{
private:
    string empName;
    int empNumber;
    string hireDate;

public:
    Employee() : empName(""), empNumber(0), hireDate("") {}

    Employee(string name, int num, string date) : empName(name), empNumber(num), hireDate(date)
    {
    }
    // mutators
    void setempName(string name)
    {
        empName = name;
    }
    void setempNumber(int num)
    {
        empNumber = num;
    }
    void setHireDate(string date)
    {
        hireDate = date;
    }

    // accessors
    string getempName() const
    {
        return empName;
    }
    int getempNumber() const
    {
        return empNumber;
    }
    string getempDate() const
    {
        return hireDate;
    }
};

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