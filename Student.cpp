//
// Created by Lenovo on 20.06.2022.
//
#include "Student.h"
#include <iostream>
#include <string>

Student::Student(int sId, string sName) {
    setID(sId);
    setName(sName);
    this->check = false;
    listBook = NULL;
    bookCount = 0;
}

Student::Student() {
    setID(0);
    setName("");
    this->check = false;
    listBook = NULL;
    bookCount = 0;
}

Student::~Student() {
    if(listBook != NULL){
        delete[] listBook;
    }
}

bool Student::hasCheckout() {
    if(this->check = true){
        return true;
    }
    else
        return false;
}

void Student::checkOut() {
    this->check = true;
}

int Student::getID() {
    return this->id;
}

string Student::getNameS() {
    return this->nameS;
}

void Student::setID(int nID) {
    this->id = nID;
}

void Student::setName(string nName) {

    this->nameS = nName;
}

void Student::addBook(Book nBook) {
    if(listBook == NULL){
        listBook = new Book[1]; //first book if books array is null

        Book newBook(nBook.getID(),nBook.getTitle(),nBook.getAuthor(),nBook.getYear()); //constructing the new book
        listBook[bookCount] = newBook; // books[number of books ] points to new book object

        //cout << "The book  " << listBook[bookCount].getID() << " has been added." << endl; //message for ending result
        bookCount++; // incrementing the number of books
    }
    else {

        bool unique = false;
        //checking if the book id is unique
        for (int i = 0; i < bookCount; ++i) {
            if(listBook[i].getID() == nBook.getID()){
                unique = true; //id is not unique
            }
        }
        if(unique){ //id is not unique
           cout<<"";
        }
        else {
            Book *temp = listBook;
            listBook = new Book[bookCount + 1];
            for (int k = 0; k < bookCount; k++) {
                listBook[k] = temp[k];
            }

            Book newBook(nBook.getID(), nBook.getTitle(), nBook.getAuthor(), nBook.getYear());
            listBook[bookCount] = newBook;


            newBook.setAvailable(false);
            bookCount++;
            delete[] temp;
        }
    }
}

Book * Student::getListBook() {
    return listBook;
}

void Student::listBookInfos() {

    if(getBookCount() == 0){
        cout << "Student   " << this->getID() << "  has no books" << endl;
    }
    else {
        cout << "Book id          Book name           Authors           Year             " << endl;
        for (int i = 0; i < getBookCount(); ++i) {
            if (getListBook()[i].getID() != 0) {
                cout << getListBook()[i].getID() << "       " << getListBook()[i].getTitle() << "     "
                     << getListBook()[i].getAuthor() << "     " << getListBook()[i].getYear()  << endl;
            }
        }
    }
}

void Student::deleteOneBook(const int bookID) {
    int index = 0;

    if(getBookCount() > 0) {

        for (int i = 0; i < getBookCount(); ++i) {
            if (getListBook()[i].getID() == bookID) {
                index = i;
            }
        }

        for (int i = 0; i < getBookCount(); ++i) {

            if (getListBook()[i].getID() == bookID) {
                Book *temp = listBook;
                listBook = new Book[bookCount - 1];
                for (int j = 0; j < index; ++j) {
                    listBook[j] = temp[j];
                }
                for (int j = index + 1; j < bookCount; j++) {
                    listBook[(j - 1)] = temp[j];
                }

                delete[] temp;

                //CHECKING OPERATION

                //cout << listBook[i].getID() << endl;

                //cout << "Book " << listBook[i].getID() << " deleted from student  " << getID() << endl;
                bookCount--;
                break;
            }
        }
    }
    else{
        cout << "";
    }

}

int Student::getBookCount() {
    return this->bookCount;
}









