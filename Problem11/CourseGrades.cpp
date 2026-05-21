/*Course Grades
In a course, a teacher gives the following tests and assignments:
• A lab activity that is observed by the teacher and assigned a numeric score.
• A pass/fail exam that has ten questions. The minimum passing score is 70.
• An essay that is assigned a numeric score.
• A final exam that has 50 questions.
Write a class named CourseGrades. The class should have a member named grades that 
is an array of GradedActivity pointers. The grades array should have four elements,
 one for each of the assignments previously described. The class should have the 
following member functions:setLab:

This function should accept the address of a GradedActivity object as its 
argument. This object should already hold the student’s score for the lab 
activity. Element 0 of the grades array should reference this object.


setPassFailExam:

This function should accept the address of a PassFailExam object as its argument. This object should already hold the student’s score for the pass/fail exam. Element 1 of the grades array should reference this object.

setEssay:

This function should accept the address of an Essay object as its argument. (See Programming Challenge 6 for the Essay class. If you have not completed Programming Challenge 6, use a GradedActivity object instead.) This object should already hold the student’s score for the essay. Element 2 of the grades array should reference this object.

setPassFailExam:

This function should accept the address of a FinalExam object as its argument. This object should already hold the student’s score for the final exam. Element 3 of the grades array should reference this object.

print:﻿

This function should display the numeric scores and grades for each element in the grades array.
Demonstrate the class in a program.*/
#include <iostream>
#include <iomanip>
#include "GradedActivity.h"
#include "PassFailExam.h"
#include "Essay.h"
#include "FinalExam.h"

class CourseGrades
{
private:
    GradedActivity* grades[4];

public:
    CourseGrades()
    {
        for (int i = 0; i < 4; i++)
            grades[i] = nullptr;
    }

    void setLab(GradedActivity* lab)
    {
        grades[0] = lab;
    }

    void setPassFailExam(PassFailExam* exam)
    {
        grades[1] = exam;
    }

    void setEssay(Essay* essay)
    {
        grades[2] = essay;
    }

    void setFinalExam(FinalExam* exam)
    {
        grades[3] = exam;
    }

    void print() const
    {
        const char* labels[4] = {
            "Lab",
            "Pass/Fail Exam",
            "Essay",
            "Final Exam"
        };

        std::cout << std::fixed << std::setprecision(1);

        for (int i = 0; i < 4; i++)
        {
            if (grades[i] != nullptr)
            {
                std::cout << labels[i] << ":\n";
                std::cout << "  Score: " << grades[i]->getScore() << "\n";
                std::cout << "  Grade: " << grades[i]->getLetterGrade() << "\n";
            }
            else
            {
                std::cout << labels[i] << ": not set\n";
            }
        }
    }
};

int main()
{
    GradedActivity lab(84.0);
    PassFailExam passFail(10, 3, 70.0);
    Essay essay(28.0, 18.0, 20.0, 27.0);
    FinalExam finalExam(50, 5);

    CourseGrades course;
    course.setLab(&lab);
    course.setPassFailExam(&passFail);
    course.setEssay(&essay);
    course.setFinalExam(&finalExam);

    course.print();
    return 0;
}