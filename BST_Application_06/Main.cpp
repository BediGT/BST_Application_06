#include "BST.hpp"
#include <iostream>
using namespace std;

int main() {
    BookBST catalog;
    catalog.addBook("C++ Programming", "Bjarne Stroustrup", 5, 1991);
    catalog.addBook("The Art of Computer Programming", "Donald Knuth", 3, 1968);
    catalog.addBook("Clean Code", "Robert Martin", 7, 2008);

    cout << "Katalog ksiazek:\n";
    catalog.displayCatalog();

    cout << "\nWyszukiwanie:\n";
    catalog.searchBook("Clean Code");

    cout << "\nDodawanie egzemplarzy:\n";
    catalog.addBook("Clean Code", "Robert Martin", 2, 2008);
    catalog.searchBook("Clean Code");

    cout << "\nUsuwanie ksiazki:\n";
    catalog.removeBook("Clean Code");
    catalog.displayCatalog();

    cout << "\nNajwczesniejszy i najpozniejszy tytul:\n";
    catalog.findEarliestTitle();
    catalog.findLatestTitle();

    cout << "\nKsiazki z lat 1960-2000:\n";
    catalog.displayBooksInYearRange(1960, 2000);

    return 0;
}
