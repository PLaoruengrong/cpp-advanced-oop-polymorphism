#include "adaptive_quiz.h" 

void Question::setText(const string& questionText){text_=questionText;} 
void Question::setAnswer(const string& correctResponse){answer_=correctResponse;} 
bool Question::checkAnswer(const string& response) const{ 
    for(size_t i=0; i<answer_.length(); i++){ 
        if(toupper(static_cast<unsigned char>(answer_[i]))!=toupper(static_cast<unsigned char>(response[i]))) return false;} 
        return true;
    } 
void Question::display() const{cout << text_ << endl;} 
void Question::addText(const string& questionText){text_+=questionText;} 

bool NumericQuestion::checkAnswer(const double& response){ return abs(stod(answer_)-response) <=0.01;} 

void FillInQuestion::display() const{ cout << text_ << " was _" << answer_ << "_\n";} 

bool MultiChoiceQuestion::checkAnswer(const string& response) const{ 
    stringstream ss(answer_); 
    string choice; 
    while(ss >> choice){ 
        if(choice == response) return true;} 
    return false;
}

bool ChooseAllCorrect::checkAnswer(const string& response) const{ 
    string token; 
    istringstream correctStream(answer_); 
    set<string> correctAnswer; 
    while(correctStream >> token) correctAnswer.insert(token); 
    istringstream userStream(response); 
    set<string> userAnswer; 
    while(userStream >> token) userAnswer.insert(token); 
    return correctAnswer==userAnswer;
}

void ChoiceQuestion::addChoice(const string& choice, bool correct){ 
    choice_++; 
    string prefix = to_string(choice_) + ")" + choice + "\n"; 
    addText(prefix); 
    if(correct) setAnswer(to_string(choice_));
} 

void ChoiceQuestion::display() const{ Question::display();}