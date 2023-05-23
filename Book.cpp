//
// Created by Lenovo on 20.06.2022.
//

#include "Book.h"
#include <iostream>
#include <string>

Book::Book(int id, string tit, string aut, int yearP) {
    setID(id);
    setAuthor(aut);
    setTitle(tit);
    setYear(yearP);
    setAvailable(true);
}
Book::Book(const Book &b1) {
    this->title =  b1.title;
    this->bId = b1.bId;
    this->author = b1.author;
    this->year = b1.year;
    this->available = b1.available;

}

Book::~Book() {


}

Book::Book() {
    setID(0);
    setTitle("");
    setAuthor("");
    setYear(0);
    setAvailable(true);
}

bool Book::isCheckedOut() {
    if(!getAvailable()){
        return true;
    }
    else
        return false;
}

void Book::checkOut() {
    setAvailable(false);
}

string Book::getTitle() {
    return this->title;
}

string Book::getAuthor() {
    return this->author;
}

int Book::getYear() {
    return this->year;
}

int Book::getID() {
    return this->bId;
}

void Book::setAuthor(string au) {
    this->author = au;
}

void Book::setYear(int ye) {
    this->year = ye;
}

void Book::setID(int idNum) {
    this->bId = idNum;
}

void Book::setTitle(string tit) {
    this->title = tit;
}

void Book::setAvailable(bool av) {

    this->available = av;
}

bool Book::getAvailable() {
    return this->available;
}


