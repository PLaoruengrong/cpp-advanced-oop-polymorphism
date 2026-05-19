#ifndef _BIKE_RENTAL_SYSTEM_H_ 
#define _BIKE_RENTAL_SYSTEM_H_ 
#include <string> 
#include <sstream> 
#include <iostream> 
using namespace std;

enum BikeType { kUnknown, kRoadBike, kTouringBike, kMountainBike, kCruiser, kCityBike, kBmxBike,kFoldingBike, kTandem, kTricycle };

class Date { 
    private: 
        int day_; 
        int month_; 
        int year_; 
    public: 
        Date(); 
        Date(int dy, int mth, int yr);
        ~Date(); 
        string ToString() const;
};

class BikeSaddle { 
    private: 
        string color_;  
        string manufacturer_;  
    public: 
        BikeSaddle(); 
        BikeSaddle(string color,string manufacturer); 
        void set_color(string color); 
        void set_manufacturer(string name); 
        string color() const; 
        string manufacturer() const;}; 


class Bike { 
    private: 
        BikeType type_; 
        int id_; 
    public: 
         Bike(); 
        Bike(BikeType type,int id, string saddle_color, string saddle_maker); 
        void set_type(BikeType type); 
        void set_id(int id); 
        void set_saddle(string color,string manufacturer); 
        BikeType type() const; 
        int id() const; 
        BikeSaddle saddle() const;
}; 

class RentalBike {   
    private: 
        float price_; 
        Bike* bike_ptr_; 
        Date* hire_date_ptr_; 
    public: 
        RentalBike(); 
        RentalBike(Bike* bike_ptr, Date* hire_date_ptr, float price); 
        float price() const {return price_;}; 
        Bike* bike() const {return bike_ptr_;}; 
        Date* date() const {return hire_date_ptr_;};
};
        
#endif 