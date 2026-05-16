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
#include "ProductionWorker.h"
#include <iostream>
#include <string>
using namespace std;

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
