//
// Created by mar on 09/03/2020.
//

#include <iostream>
#include <string>
#include "cars.h"
using namespace std;


//YEAR
Year::Year(int y_value) {
    if (y_value < 2020 && y_value > 1940) {
        y = y_value;
    }
    else {
        throw std::invalid_argument("Incorrect value!");
    };
}


// BRAND
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
void Cars_base::show_cars() {
    if (cars->size() == 0) {
        cout << "There are no cars yet." << endl;
        return;
    }
    for (Car &c :*cars) {
        cout << c << endl;
    }
}
void Cars_base::show_brands() {
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
    return os << b.name;
}
ostream& operator<<(ostream& os, Motor m) {
    return os << m.name() << " " << m.value();
}
ostream& operator<<(ostream& os, Car c) {
    return os << c.brand << " " << c.name << " (" << c.country << "), " << c.motor << ", " << c.year.year();
}