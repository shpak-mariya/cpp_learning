#include <iostream>
#include <memory>
#include "cars.h"

int main() {
    std::unique_ptr<Cars_base> Cb(new Cars_base);
    Cb->add_brand("Volkswagen", Country::DEU);
    Cb->add_motor("TSI", 1.4);
    // TODO add functional for finding added brands, motors
    // preparing to use forms (when target motor, brand, car will be selected)
    Cb->add_car("Polo", Brand("Volkswagen", Country::DEU),
            Motor("TSI", 1.4), Country::RUS, 2019);
    Cb->add_car("Camry", Brand("Toyota", Country::JPN),
            Motor("V6", 3.5), Country::JPN, 2016);
    cout << "CARS:" << endl;
    Cb->show_cars();
    cout << "BRANDS:" << endl;
    Cb->show_brands();
    cout << "MOTORS:" << endl;
    Cb->show_motors();
    return 0;
}
