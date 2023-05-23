//
// Created by Lenovo on 20.06.2022.
//

#include <iostream>
#include "LibrarySystem.h"
using namespace std;


LibrarySystem::LibrarySystem() {
    books = NULL;
    students = NULL;
    numOfBooks = 0;
    numOfStudents = 0;
}

LibrarySystem::~LibrarySystem() {
    if(books != NULL) {
        delete[] books;
    }
    if(students != NULL) {
        delete[] students;
    }

}

void LibrarySystem::addBook(const int bookId, const string name, const string authors, const int year) {

    if(books == NULL){
        books = new Book[1]; //first book if books array is null

        Book nBook(bookId,name,authors,year); //constructing the new book
        books[numOfBooks] = nBook; // books[number of books ] points to new book object

        cout << "Book  " << books[numOfBooks].getID() << " has been added." << endl; //message for ending result
        numOfBooks++; // incrementing the number of books
        //testing
        /*for (int i = 0; i < numOfBooks; ++i) {
            cout << books[i].getID() << endl;
            cout << "-------------" << endl;
        }*/

    }
    else {

        bool unique = false;
        //checking if the book id is unique
        for (int i = 0; i < numOfBooks; ++i) {
            if(books[i].getID() == bookId){
                unique = true; //id is not unique
            }
        }
        if(unique){ //id is not unique
            cout << "Book  " << bookId  << "  already exists" << endl;
        }
        else {
            //allocating memory
            Book *temp = books; //temp array to copy books
            books = new Book[numOfBooks + 1]; //construct a new element in array
            for (int k = 0; k < numOfBooks; k++) {
                books[k] = temp[k]; //copying
            }

            Book nBook(bookId,name,authors,year); //constructing the new book
            books[numOfBooks] = nBook; //assigning new space to new book

            cout << "Book  " << books[numOfBooks].getID() << " has been added." << endl;//message for ending result

            numOfBooks++;//incrementing the number of books
            /*for (int i = 0; i < numOfBooks; ++i) {
                cout << books[i].getID() << endl;
                cout << "-------------" << endl;
            }*/
            delete[] temp; // deallocating the temp array
        }

    }

}

void LibrarySystem::deleteBook(const int bookId) {

    int stuIndex = 0;
    bool bookExist = false;
    int index = 0;

    //checking if the book exists on library
    for (int i = 0; i < numOfBooks; i++) {
        if (books[i].getID() == bookId) {
            bookExist = true;
            index = i;
        }
    }
    if(!bookExist){
        cout << "Book  " << bookId << "  does not exist" << endl;
    }
    else if (bookExist) {


        if (books[index].isCheckedOut()) {


            //this->returnBook(bookId);

            for (int i = 0; i < numOfStudents; ++i) {
                for (int j = 0; j < students[i].getBookCount(); ++j) {
                    if (students[i].getListBook()[j].getID() == books[index].getID()) {
                        this->returnBook(students[i].getListBook()[j].getID());

                        break;
                    }

                }
            }
        }

    } else if (!books[index].isCheckedOut()) {
        cout << "Book  " << bookId << " has not been checked out" << endl;
    }


    for (int i = 0; i < numOfBooks; i++) {

        Book *temp = books;
        books = new Book[numOfBooks - 1];
        for (int j = 0; j < index; j++) {
            books[j] = temp[j];
        }
        for (int j = index + 1; j < numOfBooks; j++) {
            books[(j - 1)] = temp[j];
        }

        cout << "Book  " << bookId << " has been deleted" << endl;


        delete[] temp;
        numOfBooks--;

        /*for (int i = 0; i < numOfBooks; ++i) {
            cout << books[i].getID() << endl;
            cout << "-------------" << endl;
        }*/

        break;

    }


}


void LibrarySystem::addStudent(const int studentId, const string name) {
    if(students == NULL){ //if students array is null
        students = new Student[1]; //allocating memory for first student object

        Student nStu(studentId, name); //new Student object
        students[numOfStudents] = nStu; //assigning element to new student

        cout << "Student  " << students[numOfStudents].getID() << " has been added." << endl; //ending message
        numOfStudents++; //incrementing the number of students
    }
    else {

        bool unique = false;
        for (int i = 0; i < numOfStudents; ++i) {
            if(students[i].getID() == studentId){
                unique = true; //is not unique
            }
        }
        if(unique){
            cout << "Student  " << studentId << "  already exists" << endl; //warning message
        }
        else {

            Student *temp = students; //temp array
            students = new Student[numOfStudents + 1]; //allocating memory for new object
            for (int k = 0; k < numOfStudents; k++) {
                students[k] = temp[k]; //copying
            }

            Student nStu(studentId,name);//constructing new student object
            students[numOfStudents] = nStu; //assigning element to new student

            cout << "Student  " << students[numOfStudents].getID() << " has been added." << endl; //ending message

            numOfStudents++;//incrementing the number of students
            delete[] temp;//deallocating temp array
        }

    }
}


void LibrarySystem::deleteStudent(const int studentId) {
    bool idExist = false;
    int indexStu = 0;
    int indexBook = 0;

    //checking if the id is existing or not
    for (int i = 0; i < numOfStudents; i++) {
        if (students[i].getID() == studentId) {
            idExist = true;

        }
    }
    if (idExist) {

        for (int i = 0; i < numOfStudents; i++) {
            if (students[i].getID() == studentId) {
                indexStu = i;

            }
        }
        if (students[indexStu].hasCheckout()) {

            for (int i = 0; i < students[indexStu].getBookCount(); ++i) {

                this->returnBook(students[indexStu].getListBook()[i].getID());
                //students[indexStu].deleteOneBook(books[i].getID());

            }

            //deleting and updating the array
            for (int i = 0; i < numOfStudents; ++i) {
                Student *temp = students;
                students = new Student[numOfStudents - 1]; //allocating memory
                for (int j = 0; j < indexStu; ++j) {
                    students[j] = temp[j];
                }
                for (int j = indexStu + 1; j < numOfStudents; j++) {
                    students[(j - 1)] = temp[j];
                }
                cout << "Student  " << studentId << " has been deleted" << endl;

                delete[] temp; //deallocating
                numOfStudents--; //updating number of students in the system
                break;
            }
        }

        } else {
            cout << "Student  " << studentId << " does not exist " << endl;
        }

}


void LibrarySystem::checkoutBook(const int bookId, const int studentId) {

    bool bookExist = false;
    bool studentExist = false;

    int indexBook = 0;
    int indexStu = 0;

    for(int i = 0; i < numOfBooks; i++){
        if(books[i].getID() == bookId ) {
            bookExist = true;

        }

    }
    for (int i = 0; i < numOfStudents; ++i) {
        if (students[i].getID() == studentId ) {
            studentExist = true;

        }
    }

    if(bookExist && studentExist) {

        //finding index of both book and student with specified ids
        for (int i = 0; i < numOfBooks; ++i) {
            if (books[i].getID() == bookId) {
                indexBook = i;
            }
        }
        for (int i = 0; i < numOfStudents; ++i) {
            if (students[i].getID() == studentId) {
                indexStu = i;
            }
        }

        //checking if the book is checked out
        if (books[indexBook].isCheckedOut()) {
            cout << "Book   " << books[indexBook].getID()
                 << "  has been already checked out by another student" << endl;
        }

        else if (!books[indexBook].isCheckedOut()) {
            books[indexBook].checkOut();
            cout << "Book  " << books[indexBook].getID() << "  has been checked out by "
                 << students[indexStu].getID()
                 << endl;
            students[indexStu].addBook(books[indexBook]);
            students[indexStu].checkOut();

            //testing if the book is added to specific student
            /*for (int i = 0; i < students[indexStu].getBookCount(); ++i) {
                cout << students[indexStu].getListBook()[i].getID() << endl;
                cout << "-------------" << endl;
            }*/

        }
    }

    else if(!bookExist && studentExist){

        cout << "Book   " << bookId << "  does not exist for checkout" << endl;
    }
    else if(!studentExist && bookExist){
        cout << "Student   " << studentId <<"  does not exist for checkout" << endl;
    }

}

void LibrarySystem::returnBook(const int bookId) {

    int indexBook = 0;
    bool idExist = false;
    for(int i = 0; i < numOfBooks; i++) {
        if (books[i].getID() == bookId) {
            idExist = true;
            indexBook = i;
        }
    }
    if(idExist) {

        if (books[indexBook].isCheckedOut()) {
            //books[indexBook].setAvailable(true);

            for (int i = 0; i < numOfStudents; ++i) {
                //if (students[i].hasCheckout()) {
                    students[i].deleteOneBook(books[indexBook].getID());
                    books[indexBook].setAvailable(true);

                    cout <<  "Book  " << bookId << " has been returned" << endl;
                    break;
                //}
            }
        }

        else if(!books[indexBook].isCheckedOut()){

            cout <<  "Book  " << books[indexBook].getID() << " has not been checked out" << endl;
        }

    }
    else {
        cout << "Book  " << bookId << "  does not exist" << endl;
    }

}


void LibrarySystem::showAllBooks() {

    if (numOfBooks == 0) {
        cout << "Library is empty" << endl;
    } else {

        cout << "BOOK ID" << "       " << "TITLE" << "                    " << "AUTHORS" << "            "
             << "YEAR PUBLISHED"
             << "       STATUS" << endl;
        cout << endl;

        for (int i = 0; i < numOfBooks; ++i) {

            cout << books[i].getID() << "         " << books[i].getTitle() << "       " << books[i].getAuthor() << "          " << books[i].getYear() << "        " << getStatus(books[i]) << endl;
        }

    }
}

void LibrarySystem::showBook(const int bookId) {

    int index = 0;
    bool idExist = false;

    for(int i = 0; i < numOfBooks; i++) {
        if (books[i].getID() == bookId) {
            idExist = true;
            index = i;
        }
    }
    if(idExist) {
        cout << "BOOK ID" << "       " << "TITLE" << "                    " << "AUTHORS" << "            "
             << "YEAR PUBLISHED"
             << "       STATUS" << endl;

       /* for (int i = 0; i < numOfBooks; ++i) {
            if (books[i].getID() == bookId) {
                index = i;
            }
        }*/


        cout << books[index].getID() << "     " << books[index].getTitle() << "       " << books[index].getAuthor() << "            "<< books[index].getYear() << "                " << this->getStatus(books[index]) << endl;
        cout << endl;

    }
    else{
        cout << "Book is not in the library" << endl;
    }

}


void LibrarySystem::showStudent(const int studentId) {
    bool stuExist = false;
    int indexStu = 0;
    for (int i = 0; i < numOfStudents; ++i) {
        if (students[i].getID() == studentId) {
            indexStu = i;
            stuExist = true;
        }
    }

    if(stuExist) {
        cout << "Student id: " << students[indexStu].getID() << "  Student name:  " << students[indexStu].getNameS()
             << endl;



            cout << "Student  " <<  students[indexStu].getID() << "  has checked out the following books:" << endl;
            students[indexStu].listBookInfos();

    }
    else{
        cout << "Student  " << studentId << "  does not exist " << endl;
    }
    cout << endl;
}

string LibrarySystem::getStatus(Book& bo) {
    int indexBook = 0;
    int indexStu = 0;
    int idStudent = 0;
    string result ="";
    if(bo.isCheckedOut()){

        for (int i = 0; i < numOfBooks; ++i) {
            if (books[i].getID() == bo.getID()) {
                indexBook = i;
            }
        }

        for (int i = 0; i < numOfStudents; i++) {
            for (int j = 0; j < students[i].getBookCount(); j++) {
                if (students[i].getListBook()[j].getID() == books[indexBook].getID()) {
                    indexStu = i;

                    break;
                }
            }
        }

        cout << "Checked out by student  " << students[indexStu].getID() << endl;

    }
    else {
        result = "Not checked out";
    }
    return result;

}
