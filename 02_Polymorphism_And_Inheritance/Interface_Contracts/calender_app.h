#ifndef _CALENDER_APP_H_ 
#define _CALENDER_APP_H_ 
#include <string> 
#include <vector> 
#include <iostream> 
using namespace std; 

class Appointment { 
    protected: 
        string description_; 
        int year_; 
        int month_; 
        int day_; 
        int time_; 
    public: 
        Appointment(string description, int day, int mth, int yr, int time): description_(description), day_(day), month_(mth), year_(yr), time_(time) {}; 
        virtual ~Appointment(); 
        virtual bool occursOn(int yr, int mth, int dy) const = 0; 
        virtual void display() const;
}; 

class Onetime : public Appointment { 
    public: 
        using Appointment::Appointment; 
        bool occursOn(int yr, int mth, int dy) const override;
};

class Daily : public Appointment { 
    public: 
        using Appointment::Appointment; 
        bool occursOn(int yr, int mth, int dy) const override;
};

class Weekly : public Appointment { 
    public: 
        using Appointment::Appointment; 
        static int weekday(int year, int month, int day); 
        bool occursOn(int yr, int mth, int dy) const override;
};

class Monthly : public Appointment { 
    public: 
        using Appointment::Appointment; 
        bool occursOn(int yr, int mth, int dy) const override;
}; 

#endif 