#include "bike_rental_system.h"

BikeSaddle::BikeSaddle() {} 
BikeSaddle::BikeSaddle(string color,string manufacturer): color_(color), manufacturer_(manufacturer){} 
void BikeSaddle::set_color(string color){color_=color;} 
void BikeSaddle::set_manufacturer(string name){manufacturer_=name;} 
string BikeSaddle::color() const{return color_;} 
string BikeSaddle::manufacturer() const{return manufacturer_;} 

Bike::Bike(): type_(BikeType::kUnknown), id_(0){} 
Bike::Bike(BikeType type,int id, string saddle_color, string saddle_maker): type_(type), id_(id){ 
    saddle_.set_color(saddle_color); 
    saddle_.set_manufacturer(saddle_maker); } 
void Bike::set_type(BikeType type){type_=type;} 
void Bike::set_id(int id){id_=id;} 
void Bike::set_saddle(string color,string manufacturer){ 
    saddle_.set_color(color); 
    saddle_.set_manufacturer(manufacturer);} 
BikeType Bike::type() const{return type_;} 
int Bike::id() const{return id_;} 
BikeSaddle Bike::saddle() const{return saddle_;} 

RentalBike::RentalBike(): bike_ptr_(nullptr), hire_date_ptr_(nullptr), price_(0){} 
RentalBike::RentalBike(Bike* bike_ptr, Date* hire_date_ptr, float price): bike_ptr_(bike_ptr), hire_date_ptr_(hire_date_ptr), price_(price) {}

Date::Date() {} 
Date::Date(int dy, int mth, int yr): day_(dy), month_(mth), year_(yr) {} 
Date::~Date() { cout << ToString() << ": Date object destroyed" << endl;} 
string Date::ToString() const  { 
    ostringstream output; 
    output << day_ << '.' << month_ << '.' << year_; 
    return output.str();
} 