
#ifndef TEAMLEADER_H
#define TEAMLEADER_H

#include "ProductionWorker.h"

class TeamLeader : public ProductionWorker
{
private:
      float monthlyBonusAmount;
      int requiredNumOfTrainingHours;
      int numOfTrainingHoursAttended;

public:
      TeamLeader() : ProductionWorker(),
                     monthlyBonusAmount(0),
                     requiredNumOfTrainingHours(0),
                     numOfTrainingHoursAttended(0) {}

      TeamLeader(string name, int num, string date, int shift, double rate, float bonus, int reqHrs, int attHrs) : ProductionWorker(name, num, date, shift, rate),
                                                                                                                   monthlyBonusAmount(bonus),
                                                                                                                   requiredNumOfTrainingHours(reqHrs),
                                                                                                                   numOfTrainingHoursAttended(attHrs) {}
      //mutators
      void setMonthlyBonusAmount(float bonus){monthlyBonusAmount=bonus;}
      void setRequiredNumOfTrainingHours(int numHrs){requiredNumOfTrainingHours=numHrs;}
      void setNumOfTrainingHoursAttended(int attHrs){numOfTrainingHoursAttended=attHrs;}

      //accessors
      float getMonthlyBonusAmount() const{
            return monthlyBonusAmount;
      }
      int getRequiredNumOfTrainingHours() const{
            return requiredNumOfTrainingHours;
      }
      int getNumOfTrainingHoursAttended() const{
            return numOfTrainingHoursAttended;
      }
};

#endif