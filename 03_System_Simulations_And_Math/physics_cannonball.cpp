#include <cmath> 
#include <iostream> 
using namespace std; 

class CannonBall { 
    private: 
        double xPos_; 
        double xVelo_; 
        double yPos_=0; 
        double yVelo_; 
        static const double yAcc_; 
        static const double rad; 
    public: 
        CannonBall(double xPos): xPos_(xPos) {}; 
        void move(double sec); 
        void shoot(int angle, double velo); 
        void display() const;
}; 

const double CannonBall::yAcc_=-9.81; 
const double CannonBall::rad = M_PI / 180.0; 
void CannonBall::move(double sec){ 
    xPos_+=xVelo_*sec; 
    yPos_+=yVelo_*sec; 
    yVelo_+=yAcc_*sec;
} 
void CannonBall::shoot(int angle, double velo){ 
    xVelo_=velo*cos(angle*rad); 
    yVelo_=velo*sin(angle*rad); 
    do{ 
        move(0.1); 
        if(yPos_ <0) yPos_=0; 
        display(); 
    }while(yPos_>0);
} 
void CannonBall::display() const{ cout << "(" << xPos_ << "," << yPos_ << ")" << endl;}