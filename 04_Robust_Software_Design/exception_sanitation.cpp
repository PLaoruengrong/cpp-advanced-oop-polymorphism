// Overflow

double BMI::calculateBMI(const Person &person) { 
    if (person.getHeight()==0) throw overflow_error("incorrect height of 0"); 
    return person.getWeight()/pow(person.getHeight(),2);
} 

// Invalid argument

void HumiditySensor::calibrate(double factor) { // 3 remove const 
        if(factor<0) throw invalid_argument("Negative number entered"); 
        std::cout << typeid(this).name() << " calibrated" << std::endl; 
        factor_ = factor;} 

// Runtime error

double Calculator::findHighestResult() const{ 
    double high=0; 
    double temp=0; 
    if(operations_.size()==0) throw runtime_error("No operation."); 
    for(int i=0; i<operations_.size(); i++){ 
        temp=operations_[i].calculate(); 
        if(temp>high) high=temp;} 
    return high;
}