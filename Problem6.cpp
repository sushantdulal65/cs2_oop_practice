/*Design an Essay class that is derived from the GradedActivity class presented 
in this chapter. The Essay class should determine the grade a student receives on an essay.
 The student’s essay score can be up to 100, and is determined in the following manner:
• Grammar: 30 points
• Spelling: 20 points
• Correct length: 20 points
• Content: 30 points
Demonstrate the class in a simple program.
*/
#include "GradedActivity.h"
class Essay: public GradedActivity{
    private:
        double grammar; // total 30
        double spelling; // total 20
        double correctLength; // total 20
        double content; // total 30
    public:
        Essay():GradedActivity(),grammar(0),spelling(0),correctLength(0),content(0){}
        Essay(double gram,double spel,double corLen,double cont)
{
    if ((gram >= 0 && gram <= 30) &&
        (spel >= 0 && spel <= 20) &&
        (corLen >= 0 && corLen <= 20) &&
        (cont >= 0 && cont <= 30))
    {
        grammar = gram;
        spelling = spel;
        correctLength = corLen;
        content = cont;

        setScore(grammar + spelling + correctLength + content);
    }
    else
    {
        grammar = 0;
        spelling = 0;
        correctLength = 0;
        content = 0;

        setScore(0);
    }
}
};

#include <iostream>
using namespace std;

int main(){
    Essay e1(20,20,20,30);
    cout<<e1.getScore()<<" "<<e1.getLetterGrade();
    
}