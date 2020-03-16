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
double Car::get_price() const {
    return price;
}
void Car::set_price(double p) {
    this->price = p;
}


// CARS_BASE
Brand* Cars_base::add_brand(string n, Country c) {
    auto brand = make_unique<Brand>(n, c);
    // default: brand has own factory in brand's country
    brand->add_factory(c);
    brands.push_back(move(brand));
    return brands[brands.size() - 1].get();
}
Motor* Cars_base::add_motor(string n, float v) {
    auto motor = make_unique<Motor>(n, v);
    motors.push_back(move(motor));
    return motors[motors.size() - 1].get();
}
Car* Cars_base::add_car(string n, const Brand& b, const Motor& m, Country c, int y) {
    auto car = make_unique<Car>(n, b, m, c, Year{y});
    car->set_price(0.0);
    cars.push_back(move(car));
    return cars[cars.size() - 1].get();
}

// TODO fix double code
void Cars_base::show_brands() const {
    if (brands.empty()) {
        cout << "There are no brands yet." << endl;
        return;
    }
    for (auto &b : brands) {
        cout << *b << endl;
    }
}
void Cars_base::show_motors() const {
    if (motors.empty()) {
        cout << "There are no brands yet." << endl;
        return;
    }
    for (auto &m : motors) {
        cout << *m << endl;
    }
}
void Cars_base::show_cars() const {
    if (cars.empty()) {
        cout << "There are no cars yet." << endl;
        return;
    }
    for (auto &c : cars) {
        cout << *c << endl;
    }
}


// OPERATORS
ostream& operator<<(ostream& os, const Brand& b) {
    return os << b.get_name();
}
ostream& operator<<(ostream& os, const Motor& m) {
    return os << m.get_name() << " " << m.get_value();
}
ostream& operator<<(ostream& os, const Car& c) {
    os << c.get_brand() << " " << c.get_name() << " ("
       << c.get_country() << "), " << c.get_motor() << ", "
       << c.get_year() << ". ";
    if (c.get_price() != 0.0) {
        os << "Price: " << c.get_price();
    }
    return os;
}