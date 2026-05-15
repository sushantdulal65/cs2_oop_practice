/*15: Programming Challenges
    Employee and ProductionWorker Classes
    Design a class named Employee. The class should keep the following information:
    • Employee name
    • Employee number
    • Hire date
    Write one or more constructors, and the appropriate accessor and mutator functions, for the class.
    Next, write a class named ProductionWorker that is derived from the Employee class. The ProductionWorker class should have member variables to hold the following information:
    • Shift (an integer)
    • Hourly pay rate (a double)
    The workday is divided into two shifts: day and night. The shift variable will hold an integer value representing the shift that the employee works. The day shift is shift 1, and the night shift is shift 2. Write one or more constructors, and the appropriate accessor and mutator functions, for the class. Demonstrate the classes by writing a program that uses a ProductionWorker object.
*/
#include <iostream>
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

int main()
{
    ProductionWorker a("Ram Karki", 20, "5/9/2024", 1, 10);
    cout << "The details of the employee is given below: " << endl;
    cout << "Name: " << a.getempName() << endl;
    cout << "Number: " << a.getempNumber() << endl;
    cout << "Date: " << a.getempDate() << endl;
    cout << "Shift: " << a.getShift() << endl;
    cout << "Hourly Pay Rate: " << a.gethourlyPayRate() << endl;
}
