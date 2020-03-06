//
// Created by mar on 06/03/2020.
//

#ifndef STREAMS_POINTS_H
#define STREAMS_POINTS_H
#include <iostream>
#include <fstream>
#include <vector>

class Point {
    int x;
    int y;
public:
    int get_x() const {
        return x;
    };
    int get_y() const {
        return y;
    };
    Point(int x_val, int y_val) : x{x_val}, y{y_val} {};
};

void write_data_to_file(std::string, std::vector<Point>);
#endif //STREAMS_POINTS_H
