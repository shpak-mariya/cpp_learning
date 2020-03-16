//
// Created by mar on 09/03/2020.
//

#ifndef POINTERS_CARS_H
#define POINTERS_CARS_H

#include <iostream>
#include <memory>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
// TODO add templates for unique_ptr<...>


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
    double price;
public:
    Car(string, Brand, Motor, Country, Year);
    string get_name() const;
    Brand get_brand() const;
    Motor get_motor() const;
    Country get_country() const;
    int get_year() const;
    double get_price() const;
    // TODO change signature
    void set_price(double);
};

class Cars_base {
    vector<unique_ptr<Brand>> brands;
    vector<unique_ptr<Motor>> motors;
    vector<unique_ptr<Car>> cars;
public:
    Cars_base() = default;
    Brand* add_brand(string, Country);
    Motor* add_motor(string, float);
    Car* add_car(string, const Brand&, const Motor&, Country, int);
    void show_brands() const;
    void show_motors() const;
    void show_cars() const;
};

ostream& operator<<(ostream&, const Brand&);
ostream& operator<<(ostream&, const Motor&);
ostream& operator<<(ostream&, const Car&);

#endif //POINTERS_CARS_H
