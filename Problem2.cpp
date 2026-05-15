/*2.	ShiftSupervisor Class
In a particular factory, a shift supervisor is a salaried employee who supervises a shift.
In addition to a salary, the shift supervisor earns a yearly bonus when his or her shift
meets production goals. Design a ShiftSupervisor class that is derived from the Employee
class you created in Programming Challenge 1 (Employee and Production Worker Classes).
The ShiftSupervisor class should have a member variable that holds the annual salary,
and a member variable that holds the annual production bonus that a shift supervisor has earned.
 Write one or more constructors and the appropriate accessor and mutator functions for the class.
  Demonstrate the class by writing a program that uses a ShiftSupervisor object.
*/

#include "Employee.h"
#include <iostream>
using namespace std;

class ShiftSupervisor : public Employee
{
private:
    double annualSalary;
    double annualBonus;

public:
    ShiftSupervisor() : Employee(), annualSalary(0), annualBonus(0) {}
    ShiftSupervisor(string name, int num, string date, double salary, double bonus):
    Employee(name,num,date),annualSalary(salary),annualBonus(bonus){}
    //accessors
    double getAnnualSalary() const{
        return annualSalary;
    }
    double getAnnualBonus() const{
        return annualBonus;
    }
    //mutators
    void setAnnualSalary(int salary){
        annualSalary = salary;
    }
    void setAnnualBonus(int bonus){
        annualBonus = bonus;
    }
};

int main(){
    ShiftSupervisor Company("Sushant Dulal",6854777,"10/10/2025",10000,500);
    cout << "The details of the shift supervisor is given below: "<< endl;
    cout << "Name: "<< Company.getempName()<<endl;
    cout <<"Employee Id: "<<Company.getempNumber()<<endl;
    cout << "Hire Date: "<<Company.getempDate()<<endl;
    cout << "Annual Salary: "<< Company.getAnnualSalary()<<endl;
    cout << "Annual Bonus: "<<Company.getAnnualBonus()<<endl;
}