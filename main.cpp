#include <iostream>
#include "LibrarySystem.h"
#include "Book.h"
#include "Student.h"

using namespace std;
int main () {
    LibrarySystem LS ;
    LS . addBook (1000 , " Machine Learning ", " Tom Mitchell ", 1997) ;
    LS . addBook (1200 , " Data Mining ", " Michael S. , Vipin K.", 1991) ;
    LS . addBook (1300 , " Problem S. with C++", " Frank M. Carrano ", 1991) ;
    LS . addBook (1400 , "C++ How to Program ", " Deitel & Deitel ", 2005) ;
    LS . addBook (1200 , " Data Mining ", " Michael S. , Vipin K.", 1991) ;
    LS . deleteBook (1300) ;
    LS . deleteBook (2000) ;
    LS . addBook (1500 , " Pattern Recognition ", "Duda , Hart , Stork ", 2000) ;
    cout << endl ;
    LS . addStudent (21000000 , " Ali Tekin ") ;
    LS . addStudent (21000011 , " Hasan Ak") ;

    LS . addStudent (21000011 , " Fadime Sener ") ;
    LS . addStudent (21000020 , " Gokhan Karaca ") ;
    LS . addStudent (21000001 , " Eren Tunc ") ;
    LS . addStudent (21000005 , " Merve Zarif ") ;
    LS . deleteStudent (21000011) ;
    LS . deleteStudent (21000050) ;
    cout << endl ;
    LS . checkoutBook (1200 , 21000000) ;
    LS . checkoutBook (1400 , 21000020) ;
    LS . checkoutBook (2050 , 21000011) ;
    LS . checkoutBook (1000 , 21000444) ;
    LS . checkoutBook (1500 , 21000000) ;
    LS . checkoutBook (1400 , 21000001) ;
    cout << endl ;
    LS . showStudent (21000000) ;
    cout << endl ;
    LS . showStudent (21000005) ;
    cout << endl ;
    LS . showStudent (21000011) ;
    cout << endl ;
    LS . showBook (1000) ;
    LS . showBook (1200) ;
    cout << endl ;
    LS . showAllBooks () ;
    cout << endl ;
    LS . returnBook (1200) ;
    LS . returnBook (1000) ;
    cout << endl ;
    LS . checkoutBook (1200 , 21000020) ;
    LS . checkoutBook (1000 , 21000000) ;
    cout << endl ;
    LS . showAllBooks () ;
    cout << endl ;
    LS . deleteStudent (21000020) ;
    cout << endl ;
    LS . deleteBook (1000) ;
    cout << endl ;
    LS . showStudent (21000000) ;
    cout << endl ;
    LS . showAllBooks () ;
    return 0;
}