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