#include <ctime> 
#include <cstdlib> 
#include <string> 
#include <cmath> 
using namespace std; 

class Resistor { 
    private: 
        double nomRes_; 
        double tol_; 
    public: 
        Resistor(double nomRes, double tol): nomRes_(nomRes), tol_(tol) {}; 
        Resistor(string band1, string band2, string band3, string band4); 
        double getNomRes() const; 
        double getTol() const; 
        double getActRes() const;
}; 

class VoltageDivider { 
    private: 
        Resistor r1_; 
        Resistor r2_; 
    public: 
        VoltageDivider(const Resistor& r1, const Resistor& r2): r1_(r1), r2_(r2) {}; 
        double getNomGain() const; 
        double getActGain() const;
};

Resistor::Resistor(string band1, string band2, string band3, string band4){ 
    int digit; 
    if(band1=="black") digit=0; 
    else if(band1=="brown") digit=1; 
    else if(band1=="red") digit=2; 
    else if(band1=="orange") digit=3; 
    else if(band1=="yellow") digit=4; 
    else if(band1=="green") digit=5; 
    else if(band1=="blue") digit=6; 
    else if(band1=="violet") digit=7; 
    else if(band1=="gray") digit=8; 
    else if(band1=="white") digit=9; 
    nomRes_=10*digit; 
    if(band2=="black") digit=0; 
    else if(band2=="brown") digit=1; 
    else if(band2=="red") digit=2; 
    else if(band2=="orange") digit=3; 
    else if(band2=="yellow") digit=4; 
    nomRes_*=pow(10,digit); 
    else if(band2=="green") digit=5; 
    else if(band2=="blue") digit=6; 
    else if(band2=="violet") digit=7; 
    else if(band2=="gray") digit=8; 
    else if(band2=="white") digit=9; 
    nomRes_+=digit; 
    if(band3=="black") digit=0; 
    else if(band3=="brown") digit=1; 
    else if(band3=="red") digit=2; 
    else if(band3=="orange") digit=3; 
    else if(band3=="yellow") digit=4; 
    else if(band3=="green") digit=5; 
    else if(band3=="blue") digit=6; 
    else if(band3=="violet") digit=7; 
    else if(band3=="gray") digit=8; 
    else if(band3=="white") digit=9; 
    else if(band3=="gold") digit=-1; 
    else if(band3=="silver") digit=-2; 
    if(band4=="brown") tol_=1; 
    else if(band4=="red") tol_=2; 
    else if(band4=="green") tol_=0.5; 
    else if(band4=="blue") tol_=0.25; 
    else if(band4=="violet") tol_=0.1; 
    else if(band4=="gray") tol_=0.05; 
    else if(band4=="gold") tol_=5; 
    else if(band4=="silver") tol_=10; 
    else if(band4=="none") tol_=20; 
    else tol_=0;
}; 

double Resistor::getNomRes() const{return nomRes_;} 
double Resistor::getTol() const {return tol_;}; 
double Resistor::getActRes() const { 
    double delta=nomRes_*tol_/100.0; 
    double randomFactor=static_cast<double>(rand())/RAND_MAX; 
    double offset=(rand() % 2 == 0 ? -1 : 1)*randomFactor*delta; 
    return nomRes_+offset;
} 

double VoltageDivider::getNomGain() const{ return r2_.getNomRes()/(r1_.getNomRes()+r2_.getNomRes());} 
double VoltageDivider::getActGain() const{ return r2_.getActRes()/(r1_.getActRes()+r2_.getActRes());}