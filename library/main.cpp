#include <iostream>
#include "library.h"
using std::cout;
using std::endl;

int main() {
    Patron P1("Masha", 1);
    P1.set_donate_value(2.3);

    Book B1{"C++", "Stroustrup", Date{12, 12, 2018}, ISBN{"020112078X"}, Genre::science};
//    cout << B1 << endl;

    Library L;
    L.add_book("Pride and Prejudice", "Austen", Date{12, 11, 2018}, ISBN{"0672317249"}, Genre::classic);
    L.add_book(B1);
    L.add_patron("Vadim", 2);
    L.add_patron(P1);
    cout << "Books:" << endl << L.get_books();
    cout << "Patrons:" << endl << L.get_patrons();

    return 0;
}
