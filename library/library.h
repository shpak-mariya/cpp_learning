//
// Created by mar on 06/03/2020.
//

#ifndef TESTING_LIBRARY_H
#define TESTING_LIBRARY_H

#include <string>
#include <vector>
#include <iostream>
using std::string;
using std::vector;

class Patron {
    string name;
    int card_number;
    float donate;
    float donated;
public:
    Patron(string, int);
    Patron();
    string get_name() const {
        return name;
    };
    int get_card_number() const {
        return card_number;
    };
    float get_donate() const {
        return donate;
    };
    bool is_donated();
    void set_donate_value(float);
};

class Date {
    int d;
    int m;
    int y;
    //TODO string view
public:
    Date(int dd, int mm, int yyyy) :
            d{dd}, m{mm}, y{yyyy}{};
    Date(){};
};

bool check_isbn(string);

class ISBN {
    string code;
public:
    ISBN(string);
    ISBN(int);
    ISBN(int, int, int, int);
    ISBN(int, int, int, char);
    string get_code() const {
        return code;
    };
};

enum class Genre {
    fantasy, horror, classic, science,
    roman, detective, historical
};

class Book {
    string name;
    string author;
    Date reg_date;
    ISBN isbn;
    Genre genre;
    bool status;
public:
    Book(string, string, Date, ISBN, Genre, bool);
    Book(string, string, Date, ISBN, Genre);
    //TODO const?
    string get_name() const {
        return name;
    };
    string get_author() const {
        return author;
    };
    Date get_reg_date() const {
        return reg_date;
    };
    string get_isbn() const {
        return isbn.get_code();
    };
    Genre get_genre() const {
        return genre;
    };
    bool get_status() const {
        return status;
    };
    void change_status();

};
std::ostream& operator<<(std::ostream&, const Book&);
std::ostream& operator<<(std::ostream&, const vector<Book>*);
std::ostream& operator<<(std::ostream&, const Patron&);
std::ostream& operator<<(std::ostream&, const vector<Patron>*);

class Library {
    vector<Book> *books;
    vector<Patron> *patrons;
    vector<Date> dates;
public:
    Library() {
        books = new vector<Book>;
        patrons = new vector<Patron>;
    }
    vector<Book>* get_books() {
        return books;
    };
    vector<Patron>* get_patrons() {
        return patrons;
    };

    //TODO struct Transactions
    void add_patron(string, int);
    void add_patron(Patron);
    // TODO add creations way (as in classes)
    void add_book(string, string, Date, ISBN, Genre);
    void add_book(Book);
    void give_book(Book, Patron);
    void return_book(Book, Patron);
};

#endif //TESTING_LIBRARY_H
