#include <iostream> 
#include <cmath> 
using namespace std; 

class ResonantCircuit { 
    protected: 
        double wo_; 
        double B_; 
        double k_; 
    public: 
        ResonantCircuit(double wo, double B, double k): wo_(wo), B_(B), k_(k) {}; 
        virtual ~ResonantCircuit(); 
        void setwo(const double& wo); 
        double getwo() const; 
        void setB(const double& B); 
        double getB() const; 
        void setk(const double& k); 
        double getk() const; 
        virtual void display() const;
};

class SeriesResonantCircuit : public ResonantCircuit{ 
    private: 
        double R_; 
        double C_; 
        double L_; 
    public: 
        SeriesResonantCircuit(double wo, double B, double k); 
        virtual ~SeriesResonantCircuit(); 
        void calculation(); 
        void display() const override;
};

class ParallelResonantCircuit : public ResonantCircuit{ 
    private: 
        double R_; 
        double C_; 
        double L_; 
    public: 
        ParallelResonantCircuit(double wo, double B, double k); 
        virtual ~ParallelResonantCircuit(); 
        void calculation(); 
        void display() const override;
}; 

ResonantCircuit::~ResonantCircuit(){} 
void ResonantCircuit::setwo(const double& wo){wo_=wo;} 
double ResonantCircuit::getwo() const{return B_;} 
void ResonantCircuit::setB(const double& B){B_=B;} 
double ResonantCircuit::getB() const{return B_;} 
void ResonantCircuit::setk(const double& k){k_=k;} 
double ResonantCircuit::getk() const{return k_;} 
void ResonantCircuit::display() const{ cout << "wo: " << wo_ << ", B: " << B_ << ", k: " << k_ << endl;}

SeriesResonantCircuit::SeriesResonantCircuit(double wo, double B, double k): ResonantCircuit(wo, B, k) {calculation();} 
SeriesResonantCircuit::~SeriesResonantCircuit(){} 
void SeriesResonantCircuit::calculation(){ 
    R_=1/k_; 
    L_=R_/B_; 
    C_=1/pow(wo_,2)*L_;
} 
void SeriesResonantCircuit::display() const{ 
    ResonantCircuit::display(); 
    cout << "R: " << R_ << ", C: " << C_ << ", L: " << L_ << endl;
}

ParallelResonantCircuit::ParallelResonantCircuit(double wo, double B, double k): ResonantCircuit(wo, B, k) {calculation();} 
ParallelResonantCircuit::~ParallelResonantCircuit(){} 
void ParallelResonantCircuit::calculation(){ 
    R_=k_; 
    C_=R_*B_; 
    L_=1/pow(wo_,2)*C_;} 
void ParallelResonantCircuit::display() const{ 
    ResonantCircuit::display(); 
    cout << "R: " << R_ << ", C: " << C_ << ", L: " << L_ << endl;
}