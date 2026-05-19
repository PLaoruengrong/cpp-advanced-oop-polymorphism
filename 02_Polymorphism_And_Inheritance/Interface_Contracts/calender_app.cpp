#include "calender_app.h" 

Appointment::~Appointment(){} 
void Appointment::display() const{ cout << description_ << " on " << day_ << "." << month_ << "." << year_ <<" at " << time_ << endl;}

bool Onetime::occursOn(int yr, int mth, int dy) const {return yr== year_ && mth == month_ && day_ == dy;} 

bool Daily::occursOn(int yr, int mth, int dy) const {return true;} 

int Weekly::weekday(int year, int month, int day){ 
    if (month<3){ 
        month+=12; 
        year-=1;} 
    int K=year%100; 
    int J = year/100; 
    int h=(day+13*(month+1)/5+K+K/4+J/4+5*J)%7; 
    return h;
} 

bool Weekly::occursOn(int yr, int mth, int dy) const{ 
    int queryDay = weekday(yr, mth, dy); 
    int appointmentDay = weekday(year_, month_, day_); 
    return queryDay == appointmentDay;
}

bool Monthly::occursOn(int yr, int mth, int dy) const{return day_ == dy;}