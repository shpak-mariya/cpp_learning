//
// Created by mar on 06/03/2020.
//

#include "library.h"
#include <iostream>
#include <string>
//#include <regex>

using namespace std;

Patron::Patron(string n, int c) : name{n}, card_number{c} {
    set_donate_value(0.0);
}
bool Patron::is_donated() {\
    if(donate > donated) {
        return true;
    }
    return false;
}
void Patron::set_donate_value(float d) {
    donate = d;
}

bool check_isbn(string s) {
    //TODO add regexp working
    return true;
}

ISBN::ISBN(string s) {
    if(check_isbn(s)) {
        code = s;
    }
}
ISBN::ISBN(int i) {
    string s = to_string(i);
    if(check_isbn(s)) {
        code = s;
    }
}
ISBN::ISBN(int i1, int i2, int i3, int i4) {
    string s;
    s += to_string(i1);
    s += to_string(i2);
    s += to_string(i3);
    s += to_string(i4);
    if(check_isbn(s)) {
        code = s;
    }
}
ISBN::ISBN(int i1, int i2, int i3, char c1) {
    string s;
    s += to_string(i1);
    s += to_string(i2);
    s += to_string(i3);
    s += c1;
    if(check_isbn(s)) {
        code = s;
    }
}


Book::Book(string n, string a, Date d, ISBN i, Genre g, bool s) :
        name{n}, author{a}, reg_date{d}, isbn{i}, genre{g}, status{s} { }

Book::Book(string n, string a, Date d, ISBN i, Genre g) :
        name{n}, author{a}, reg_date{d}, isbn{i}, genre{g} {
    status = false;
}

void Book::change_status() {
    cout << "Status has changed! Now book is ";
    if(!status) {
        status = true;
        cout << "free";
    }
    else {
        status = false;
        cout << "on hand";
    }
    cout << " !" << endl;
}

ostream& operator<<(ostream& os, const Book& B) {
    //TODO add genre, date and isbn output
    string out = B.get_author() + ", " +
                 B.get_name() + " - ";
    B.get_status() == true? out += "FREE!" : out += "NOT AVAILABLE :c";
    return os << out << endl;
}

ostream& operator<< (ostream& os, const vector<Book>* B) {
    for(auto &b : *B) {
        os << b;
    }
    return os << endl;
}
ostream& operator<<(ostream& os, const Patron& P) {
    // TODO add info about donate
    return os << P.get_card_number() << ": " << P.get_name() << endl;
}

ostream& operator<< (ostream& os, const vector<Patron>* P) {
    //TODO fix double code (operator for vector<Book>)
    //TODO add sorting (card_number)
    for(auto &p : *P) {
        os << p;
    }
    return os << endl;
}

void Library::add_book(string name, string author,
                          Date reg_date, ISBN isbn, Genre g) {
    get_books()->push_back(Book{name, author, reg_date, isbn, g});
}
void Library::add_book(Book B) {
    get_books()->push_back(B);
}
void Library::add_patron(string name, int card_number) {
    get_patrons()->push_back(Patron{name, card_number});
}
void Library::add_patron(Patron P) {
    get_patrons()->push_back(P);
}
void Library::give_book(Book B, Patron P) {
    if(!P.is_donated()) {
        cout << "Patron hasn't paid yet!" << endl;
    }
    else if(!B.get_status()) {
        cout << "Book is not available!" << endl;
    }
    else {
        B.change_status();
        //TODO owner, patron's list_of_books
    }
}
void Library::return_book(Book B, Patron P) {
    B.change_status();
}
