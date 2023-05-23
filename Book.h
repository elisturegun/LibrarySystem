//
// Created by Lenovo on 20.06.2022.
//

#ifndef HW1_LIBRARYSYSTEM_BOOK_H
#define HW1_LIBRARYSYSTEM_BOOK_H
#include <iostream>
#include <string>
using namespace std;
class Book{
public:
    Book();
    Book( int id,  string  tit,  string aut, int yearP);
    ~Book();
    Book(Book const &b1);

    bool isCheckedOut();
    void checkOut();

    string getTitle();
    string getAuthor();
    int getYear();
    int getID();
    bool getAvailable();

    void setTitle(string tit);
    void setID(int idNum);
    void setYear(int ye);
    void setAuthor(string au);
    void setAvailable(bool av);

    int bId;
    bool available;
private:
    string title;
    string author;
    int year;

};
#endif //HW1_LIBRARYSYSTEM_BOOK_H
