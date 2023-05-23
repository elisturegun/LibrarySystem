//
// Created by Lenovo on 20.06.2022.
//

#ifndef HW1_LIBRARYSYSTEM_STUDENT_H
#define HW1_LIBRARYSYSTEM_STUDENT_H
#include <iostream>
#include <string>
#include "Book.h"
using namespace std;

class Student{
public:
    Student();
    Student(int sId, string sName);
    ~Student();

    bool hasCheckout();
    void checkOut();

    int getID();
    string getNameS();

    void setID( int nID);
    void setName( string nName);

    void addBook(Book nBook);
    Book * getListBook();
    void listBookInfos();

    void deleteOneBook(const int bookID);

    int getBookCount();

    int id;
    bool check;


private:
    string nameS;
    Book* listBook;
    int bookCount;

};
#endif //HW1_LIBRARYSYSTEM_STUDENT_H
