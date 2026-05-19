#include "payroll_system.h" 

Employee::~Employee() {} 
void Employee::print() const{ cout << "employee: " << first_name_ << " " << last_name_ << endl << "social security number: " << social_security_number_ << endl;} 
void Employee::setFirstName(string& first_ref){first_name_=first_ref;} 
void Employee::setLastName(string& last_ref){last_name_=last_ref;} 
void Employee::setSSN(string& ssn_ref){social_security_number_=ssn_ref;}

SalariedEmployee::~SalariedEmployee() {} 
void SalariedEmployee::print() const{ 
    Employee::print(); 
    cout << "weekly salary: " << weekly_salary_;
} 
void SalariedEmployee::setWeeklySalary(double salary){weekly_salary_=salary;}

CommissionEmployee::~CommissionEmployee() {} 
void CommissionEmployee::setGrossSales(double sales){gross_sales_=sales;} 
void CommissionEmployee::setCommissionRate(double rate){commission_rate_=rate;} 
void CommissionEmployee::print() const{ 
    Employee::print(); 
    cout << "gross sales: " << gross_sales_ << "; commission rate: " << commission_rate_;
}

BasePlusEmployee::~BasePlusEmployee(){} 
void BasePlusEmployee::setBaseSalary(double salary){ base_salary_=salary;} 
void BasePlusEmployee::print() const{ 
    CommissionEmployee::print(); 
    cout << "; base salary: " << base_salary_;
}    

PieceWorker::~PieceWorker(){} 
void PieceWorker::setWage(double wage){wage_=wage;} 
void PieceWorker::setPieces(int pieces){pieces_=pieces;} 
void PieceWorker::print() const{ 
    Employee::print(); 
    cout << "Wage: " << wage_ << "; Pieces: " << pieces_;
}

HourlyWorker::~HourlyWorker(){} 
 
void HourlyWorker::setWage(double wage){wage_=wage;} 
void HourlyWorker::setHour(int hour){hours_=hour;} 
void HourlyWorker::print() const{ 
    Employee::print(); 
    cout << "hourly wage: " << wage_ << "; hours worked: " << hours_;
}