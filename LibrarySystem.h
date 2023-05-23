//
// Created by Lenovo on 20.06.2022.
//

#ifndef HW1_LIBRARYSYSTEM_LIBRARYSYSTEM_H
#define HW1_LIBRARYSYSTEM_LIBRARYSYSTEM_H
#include <string>
#include <iostream>
#include "Book.h"
#include "Student.h"
#include "Student.h"
using namespace std;
class LibrarySystem {
public :
    LibrarySystem () ;
    ~ LibrarySystem () ;
    void addBook ( const int bookId , const string name , const string authors ,
                   const int year ) ;
    void deleteBook ( const int bookId ) ;
    void addStudent ( const int studentId , const string name ) ;
    void deleteStudent ( const int studentId ) ;
    void checkoutBook ( const int bookId , const int studentId ) ;
    void returnBook ( const int bookId ) ;
    void showAllBooks () ;
    void showBook ( const int bookId ) ;
    void showStudent ( const int studentId ) ;
    string getStatus(Book& bo);

private:

    Book* books;
    Student* students;
    int numOfBooks;
    int numOfStudents;
};

#endif //HW1_LIBRARYSYSTEM_LIBRARYSYSTEM_H
