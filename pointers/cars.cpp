//
// Created by mar on 09/03/2020.
//

#include <iostream>
#include <string>
#include "cars.h"
using namespace std;


//YEAR
Year::Year(int y) {
    if (y < 2020 && y > 1940) {
        year = y;
    }
    else {
        throw invalid_argument("Incorrect value!");
    }
}
int Year::get_year() const {
    return year;
}


// MOTOR
string Motor::get_name() const {
    return name;
}
float Motor::get_value() const {
    return value;
}


// BRAND
string Brand::get_name() const {
    return name;
}
Country Brand::get_country() const {
    return country;
}
void Brand::add_factory(Country c) {
    factories.push_back(c);
}
void Brand::add_motor(Motor m) {
    motors.push_back(m);
}


// CAR
Car::Car(string n, Brand b, Motor m, Country c, Year y) :
        name(n), brand(b), motor(m), country(c), year(y) {
    // TODO check for correct values - (Toyota from Belarus, incorrect name of car...)
}
string Car::get_name() const {
    return name;
}
Brand Car::get_brand() const {
    return brand;
}
Motor Car::get_motor() const {
    return motor;
}
Country Car::get_country() const {
    return country;
}
int Car::get_year() const {
    return year.get_year();
}
double Car::get_prize() const {
    return prize;
}
void Car::set_prize(double p) {
    prize = p;
}


// CARS_BASE
Cars_base::Cars_base() {
    brands = new vector<Brand>;
    motors = new vector<Motor>;
    cars = new vector<Car>;
}

Brand* Cars_base::add_brand(string n, Country c) {
    Brand *b = new Brand{n, c};
    // default: brand has own factory in brand's country
    b->add_factory(c);
    brands->push_back(*b);
    return b;
}
Motor* Cars_base::add_motor(string n, float v) {
    Motor *m =  new Motor{n, v};
    motors->push_back(*m);
    return m;
}
Car* Cars_base::add_car(string n, Brand b, Motor m, Country c, int y) {
    Car *car = new Car(n, b, m, c, Year{y});
    car->set_prize(0.0);
    cars->push_back(*car);
    return car;
}

// TODO fix double code
void Cars_base::show_cars() const {
    if (cars->size() == 0) {
        cout << "There are no cars yet." << endl;
        return;
    }
    for (Car &c :*cars) {
        cout << c << endl;
    }
}
void Cars_base::show_brands() const {
    if (brands->size() == 0) {
        cout << "There are no brands yet." << endl;
        return;
    }
    for (Brand &b :*brands) {
        cout << b << endl;
    }
}


// OPERATORS
ostream& operator<<(ostream& os, Brand b) {
    return os << b.get_name();
}
ostream& operator<<(ostream& os, Motor m) {
    return os << m.get_name() << " " << m.get_value();
}
ostream& operator<<(ostream& os, Car c) {
    return os << c.get_brand() << " " << c.get_name() << " (" << c.get_country() << "), " << c.get_motor() << ", " << c.get_year();
}