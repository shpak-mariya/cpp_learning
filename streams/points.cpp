//
// Created by mar on 06/03/2020.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "points.h"

using namespace std;
void write_data_to_file(string oname, vector<Point> points) {
    std::ofstream ost{oname};
    // TODO add check for file
    if (!ost) {
        cout << "Cannot open this file!" << endl;
    }
    for (auto p : points) {
        ost << "(" << p.get_x() << ", " <<
                      p.get_y() << ")" << endl;
    }
}