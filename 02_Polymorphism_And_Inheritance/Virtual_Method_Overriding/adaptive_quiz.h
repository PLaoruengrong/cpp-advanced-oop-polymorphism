#ifndef _ADAPTIVE_QUIZ_H_ 
#define _ADAPTIVE_QUIZ_H_ 
#include <iostream> 
#include <sstream> 
#include <string> 
#include <cctype>
#include <cmath> 
#include <set>
using namespace std; 

class Question { 
    protected: 
        string text_; 
        string answer_; 
    public: 
        Question(); 
        void setText(const string& questionText); 
        void setAnswer(const string& correctResponse); 
        virtual bool checkAnswer(const string& response) const; 
        virtual void display() const; 
        void addText(const string& questionText);
};


class NumericQuestion : public Question { 
    public: 
        bool checkAnswer(const double& response);
};

class FillInQuestion : public Question { 
    public:  
        void display() const;
}; 

class MultiChoiceQuestion : public Question { 
    public: 
        bool checkAnswer(const string& response) const;
};
        
 
class ChooseAllCorrect : public Question { 
     bool checkAnswer(const string& response) const;
};

class ChoiceQuestion : public Question { 
    private: 
        int choice_=0; 
    public: 
        ChoiceQuestion(); 
        void addChoice(const string& choice, bool correct); 
        virtual void display() const override;
} 

#endif 