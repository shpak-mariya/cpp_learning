//
// Created by mar on 09/03/2020.
//

#ifndef POINTERS_CARS_H
#define POINTERS_CARS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// TODO add country table with full names
enum Country {
    CHN, RUS, DEU, JPN
};

struct Year {
    int y;
public:
    int year() {
        return y;
    }
    Year(int);
};

class Motor {
    string n; // name - TSI
    float v; // value - 1.4
public:
    string name() {
        return n;
    }
    float value() {
        return v;
    }
    Motor(string name, float value) : n(name), v(value) {
        // TODO check in
    };
};

class Brand {
    vector<Country> factories;
    vector<Motor> motors;
public:
    string name;
    Country country;
    void add_factory(Country);
    void add_motor(Motor);
    Brand(string n, Country c) : name{n}, country(c) {}
};

struct Car {
    string name;
    Brand brand;
    Motor motor;
    Country country;
    double prize;
    Year year;
    Car(string, Brand, Motor, Country, Year);
    void set_prize(double);
};

class Cars_base {
    vector<Brand> *brands;
    vector<Motor> *motors;
    vector<Car> *cars;
    int count;
public:
    Cars_base();
    Brand* add_brand(string, Country);
    Motor* add_motor(string, float);
    Car* add_car(string, Brand, Motor, Country, int);
    void show_brands();
    void show_cars();
};

ostream& operator<<(ostream&, Brand);
ostream& operator<<(ostream&, Motor);
ostream& operator<<(ostream&, Car);


#endif //POINTERS_CARS_H
