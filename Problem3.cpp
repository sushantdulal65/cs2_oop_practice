/*3.	TeamLeader Class
      In a particular factory, a team leader is an hourly paid production worker who leads a small team.
     In addition to hourly pay, team leaders earn a fixed monthly bonus. Team leaders are required to
     attend a minimum number of hours of training per year. Design a TeamLeader class that extends the
      ProductionWorker class you designed in Programming Challenge 1 (Employee and Production Worker
      Classes). The TeamLeader class should have member variables for the monthly bonus amount, the
      required number of training hours, and the number of training hours that the team leader has
      attended. Write one or more constructors and the appropriate accessor and mutator functions
      for the class. Demonstrate the class by writing a program that uses a TeamLeader object.
*/
#include "TeamLeader.h"
#include <iostream>
using namespace std;

int main(){
    TeamLeader Troyfest("Sushant Dulal",6854777,"10/10/2025",1,5.5,2000.50,50,32);
    cout << "The details of the team leader is given below:"<<endl;
    cout << "Name: " << Troyfest.getempName() << endl;
    cout << "Number: " << Troyfest.getempNumber() << endl;
    cout << "Date: " << Troyfest.getempDate() << endl;
    cout << "Shift: " << Troyfest.getShift() << endl;
    cout << "Hourly Pay Rate: " << Troyfest.gethourlyPayRate() << endl;
    cout << "Monthy Bonus Amount: "<<Troyfest.getMonthlyBonusAmount() <<endl;
    cout << "Required Number of Training Hours: "<<Troyfest.getRequiredNumOfTrainingHours() << endl;
    cout << "Number of Training Hours Attended: "<<Troyfest.getNumOfTrainingHoursAttended()<<endl;


}