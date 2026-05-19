#ifndef STUDENT_GRADE_H_ 
#define STUDENT_GRADE_H_ 
#include <vector> 
#include <string> 
using namespace std; 
class Student { 
    private: 
        string name_; 
        int totalQuizScore_; 
        int numberOfQuizzes_; 
        Grade grade_; 
    public: 
        Student(string name): name_(name), totalQuizScore_(0), numberOfQuizzes_(0) {}; 
        string getName() const; 
        void addQuiz(int score); 
        int getTotalScore() const; 
        double getAverageScore() const; 
        void addGrade(); 
        double getGPA() const;}; 


class Grade { 
    private: 
        double GPA; 
    public: 
        Grade(); 
        Grade(string grade); 
        double getGPA() const;}; 
#endif