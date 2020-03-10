#include <iostream>
#include "cars.h"

int main() {
    Cars_base CB;
    Brand *b = CB.add_brand("Volkswagen", Country::DEU);
    Car *mycar = CB.add_car("Polo", *b, *(CB.add_motor("TSI", 1.4)), Country::RUS, 2019);
    Car *camry = CB.add_car("Camry", *(CB.add_brand("Toyota", Country::JPN)), *(CB.add_motor("V6", 3.5)), Country::JPN, 2016);
    camry->set_prize(60430);
    CB.show_cars();
    return 0;
}
