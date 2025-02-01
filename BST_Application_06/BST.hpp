#pragma once

#include <string>
using namespace std;

// Struktura danych przechowująca informacje o książce
struct Book {
    string author;
    int copies;
    int year;
};

// Węzeł drzewa BST
struct Node {
    string title;
    Book book;
    Node* left;
    Node* right;

    Node(string t, string a, int c, int y)
        : title(t), book{ a, c, y }, left(nullptr), right(nullptr) {
    }
};

// Klasa zarządzająca katalogiem książek w BST
class BookBST {
private:
    Node* root;

    Node* addBook(Node* node, const string& title, const string& author, int copies, int year);
    Node* removeBook(Node* node, const string& title);
    Node* findMin(Node* node);
    Node* findMax(Node* node);
    Node* search(Node* node, const string& title);
    void inOrderTraversal(Node* node);
    void displayBooksByYearRange(Node* node, int startYear, int endYear);

public:
    BookBST();
    ~BookBST();
    void addBook(const string& title, const string& author, int copies, int year);
    void removeBook(const string& title);
    void searchBook(const string& title);
    void displayCatalog();
    void findEarliestTitle();
    void findLatestTitle();
    void displayBooksInYearRange(int startYear, int endYear);
    void clear(Node* node);
};
