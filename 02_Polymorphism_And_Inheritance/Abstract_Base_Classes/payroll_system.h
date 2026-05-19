#ifndef _PAYROLL_SYSTEM_H_ 
#define _PAYROLL_SYSTEM_H_ 
#include <string> 
#include <iostream> 
using namespace std; 

class Employee{ 
    private: 
        string first_name_; 
        string last_name_; 
        string social_security_number_; 
    public: 
        Employee(string& first_ref, string& last_ref, string& ssn_ref): first_name_(first_ref), last_name_(last_ref), social_security_number_(ssn_ref) {}; 
        virtual ~Employee(); 
        virtual double earnings() const=0; //pure virtual 
        virtual void print() const; 
        void setFirstName(string& first_ref); 
        void setLastName(string& last_ref); 
        void setSSN(string& ssn_ref); 
        string getFirstName() const {return first_name_;}; 
        string getLastName() const {return last_name_;}; 
        string getSSN() const {return social_security_number_;};
}; 

class SalariedEmployee : public Employee{ 
    private: 
        double weekly_salary_; 
    public: 
        SalariedEmployee(string first_ref, string last_ref, string ssn_ref, double salary = 0.0): Employee(first_ref, last_ref, ssn_ref), weekly_salary_(salary) {}; 
        virtual ~SalariedEmployee(); 
        double earnings() const {return weekly_salary_;}; 
        void print() const override; 
        void setWeeklySalary(double salary); 
        double getWeeklySalary () const {return weekly_salary_;};
}; 

class CommissionEmployee : public Employee{ 
    private: 
        double gross_sales_; 
        double commission_rate_; 
    public: 
        CommissionEmployee(string first_ref, string last_ref, string ssn_ref, double sales=0.0, double rate=0.0): Employee(first_ref, last_ref, ssn_ref), gross_sales_(sales), commission_rate_(rate) {}; 
        virtual ~CommissionEmployee(); 
        virtual double earnings() const {return gross_sales_*commission_rate_;}; 
        virtual void print() const override; 
        void setGrossSales(double sales); 
        void setCommissionRate(double rate); 
        double getGrossSales() const {return gross_sales_;}; 
        double getCommissionRate() const {return commission_rate_;};
};

class BasePlusEmployee : public CommissionEmployee{ 
    private: 
        double base_salary_; 
    public: 
        BasePlusEmployee(string first_ref, string last_ref, string ssn_ref, double sales=0.0, double rate=0.0, double salary=0.0): CommissionEmployee(first_ref, last_ref, ssn_ref, sales, rate), base_salary_(salary) {}; 
        virtual ~BasePlusEmployee(); 
        double earnings() const {return (getGrossSales()*getCommissionRate())+base_salary_;}; 
        void print() const override; 
        void setBaseSalary(double salary); 
        double getBaseSalary () const {return base_salary_;};
}; 

class PieceWorker : public Employee{ 
    private: 
        double wage_; 
        int pieces_; 
    public: 
        PieceWorker(string first_ref, string last_ref, string ssn_ref, double wage = 0.0, int pieces =0): Employee(first_ref, last_ref, ssn_ref), wage_(wage), pieces_(pieces) {}; 
        virtual ~PieceWorker(); 
        double earnings() const override {return wage_*pieces_;}; 
        void setWage(double wage); 
        void setPieces(int pieces); 
        double getWage () const {return wage_;}; 
        int getPieces () const {return pieces_;}; 
        void print() const override;
}; 

class HourlyWorker : public Employee{ 
    private: 
        double wage_; 
        int hours_; 
    public: 
        HourlyWorker(string first_ref, string last_ref, string ssn_ref, double wage = 0.0, int hours =0): Employee(first_ref, last_ref, ssn_ref), wage_(wage), hours_(hours) {}; 
        virtual ~HourlyWorker(); 
        double earnings() const override {return (hours_ > 40) ? (wage_*40)+(wage_*(hours_-40)*1.5) : wage_*hours_;}; 
        void setWage(double wage); 
        void setHour(int hour); 
        double getWage () const {return wage_;}; 
        int getHour () const {return hours_;}; 
        void print() const override;
}; 

#endif 