#include "student_grade.h" 
string Student::getName() const{return name_;} 
void Student::addQuiz(int score){ 
    totalQuizScore_+=score; 
    numberOfQuizzes_++; 
    addGrade();} 
int Student::getTotalScore() const{return totalQuizScore_;} 
double Student::getAverageScore() const{ 
    return totalQuizScore_*1.0/numberOfQuizzes_;} 
void Student::addGrade() { 
    if(getAverageScore()>=90) grade_ = Grade("A+"); 
    else if(getAverageScore()>=80) grade_ = Grade("A"); 
    else if(getAverageScore()>=75) grade_ = Grade("A-"); 
    else if(getAverageScore()>=70) grade_ = Grade("B+"); 
    else if(getAverageScore()>=65) grade_ = Grade("B"); 
    else if(getAverageScore()>=60) grade_ = Grade("B-"); 
    else if(getAverageScore()>=55) grade_ = Grade("C+"); 
    else if(getAverageScore()>=50) grade_ = Grade("C"); 
    else if(getAverageScore()>=45) grade_ = Grade("C-"); 
    else if(getAverageScore()>=40) grade_ = Grade("D"); 
    else grade_ = Grade("F");} 
double Student::getGPA() const{return grade_.getGPA();}
Grade::Grade(): GPA(0.0) {} 
Grade::Grade(string grade){ 
    if(grade == "A+") GPA = 1.0; 
    else if(grade == "A") GPA = 1.3; 
    else if(grade == "A-")GPA = 1.7; 
    else if(grade == "B+")GPA = 2.0; 
    else if(grade == "B")GPA = 2.3; 
    else if(grade == "B-")GPA = 2.7; 
    else if(grade == "C+")GPA = 3.0; 
    else if(grade == "C")GPA = 3.3; 
    else if(grade == "C-")GPA = 3.7; 
    else if(grade == "D")GPA = 4.0; 
    else if(grade == "F")GPA = 5.0;} 
double Grade::getGPA() const{return GPA;}