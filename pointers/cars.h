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
    int year;
public:
    explicit Year(int);
    int get_year() const;
};

class Motor {
    string name;
    float value;
public:
    Motor(string n, float v) : name(n), value(v) {}
    string get_name() const;
    float get_value() const;
};

class Brand {
    string name;
    Country country;
    vector<Country> factories;
    vector<Motor> motors;
public:
    Brand(string n, Country c) : name{n}, country(c) {}
    string get_name() const;
    Country get_country() const;
    void add_factory(Country);
    void add_motor(Motor);
};

class Car {
    string name; // Polo
    Brand brand; // Volkswagen
    Motor motor;
    Country country;
    Year year;
    double prize;
public:
    Car(string, Brand, Motor, Country, Year);
    string get_name() const;
    Brand get_brand() const;
    Motor get_motor() const;
    Country get_country() const;
    int get_year() const;
    double get_prize() const;
    void set_prize(double);
};

class Cars_base {
    vector<Brand> *brands;
    vector<Motor> *motors;
    vector<Car> *cars;
public:
    Cars_base();
    Brand* add_brand(string, Country);
    Motor* add_motor(string, float);
    Car* add_car(string, Brand, Motor, Country, int);
    void show_brands() const;
    void show_cars() const;
};

ostream& operator<<(ostream&, Brand);
ostream& operator<<(ostream&, Motor);
ostream& operator<<(ostream&, Car);

#endif //POINTERS_CARS_H
