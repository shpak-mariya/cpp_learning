#include <iostream>
#include <fstream>
#include <vector>
#include "points.h"
using namespace std;

int main() {
    vector<Point> origin_points;
//    cout << "Enter 8 pairs of coordinates: " << endl;
    for (int i = 0; i < 8; ++i) {
        int x, y;
        /*cout << i << "th:" << endl;
        cout << "x: ";
        cin >> x;
        cout << "y: ";
        cin >> y;*/
        // TODO add check for user's input
        x = i;
        y = i;
        origin_points.push_back(Point{x, y});
    }

    string oname;
    // TODO add check for input
    //cout << "Enter output file name: ";
    //cin >> oname;
    oname = "/home/mar/Documents/git_rep/cpp_learning/streams/io_data/coordinates.txt";
    write_data_to_file(oname, origin_points);
    return 0;
}
