#include "BST.hpp"
#include <iostream>

using namespace std;

BookBST::BookBST() : root(nullptr) {}

BookBST::~BookBST() {
    clear(root);
}

void BookBST::clear(Node* node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

Node* BookBST::addBook(Node* node, const string& title, const string& author, int copies, int year) {
    if (!node) return new Node(title, author, copies, year);

    if (title < node->title)
        node->left = addBook(node->left, title, author, copies, year);
    else if (title > node->title)
        node->right = addBook(node->right, title, author, copies, year);
    else
        node->book.copies += copies;

    return node;
}

void BookBST::addBook(const string& title, const string& author, int copies, int year) {
    root = addBook(root, title, author, copies, year);
}

Node* BookBST::removeBook(Node* node, const string& title) {
    if (!node) return nullptr;

    if (title < node->title)
        node->left = removeBook(node->left, title);
    else if (title > node->title)
        node->right = removeBook(node->right, title);
    else {
        if (node->book.copies > 1) {
            node->book.copies--;
            return node;
        }
        if (!node->left) {
            Node* rightNode = node->right;
            delete node;
            return rightNode;
        }
        else if (!node->right) {
            Node* leftNode = node->left;
            delete node;
            return leftNode;
        }
        Node* minNode = findMin(node->right);
        node->title = minNode->title;
        node->book = minNode->book;
        node->right = removeBook(node->right, minNode->title);
    }
    return node;
}

void BookBST::removeBook(const string& title) {
    root = removeBook(root, title);
}

Node* BookBST::findMin(Node* node) {
    while (node && node->left) node = node->left;
    return node;
}

Node* BookBST::findMax(Node* node) {
    while (node && node->right) node = node->right;
    return node;
}

Node* BookBST::search(Node* node, const string& title) {
    if (!node || node->title == title) return node;
    if (title < node->title) return search(node->left, title);
    return search(node->right, title);
}

void BookBST::searchBook(const string& title) {
    Node* result = search(root, title);
    if (result)
        cout << "Title: " << result->title << ", Author: " << result->book.author
        << ", Copies: " << result->book.copies << endl;
    else
        cout << "Book not found.\n";
}

void BookBST::inOrderTraversal(Node* node) {
    if (node) {
        inOrderTraversal(node->left);
        cout << "Title: " << node->title << ", Author: " << node->book.author
            << ", Copies: " << node->book.copies << endl;
        inOrderTraversal(node->right);
    }
}

void BookBST::displayCatalog() {
    inOrderTraversal(root);
}

void BookBST::findEarliestTitle() {
    Node* minNode = findMin(root);
    if (minNode)
        cout << "Earliest title: " << minNode->title << endl;
}

void BookBST::findLatestTitle() {
    Node* maxNode = findMax(root);
    if (maxNode)
        cout << "Latest title: " << maxNode->title << endl;
}

void BookBST::displayBooksByYearRange(Node* node, int startYear, int endYear) {
    if (node) {
        displayBooksByYearRange(node->left, startYear, endYear);
        if (node->book.year >= startYear && node->book.year <= endYear)
            cout << "Title: " << node->title << ", Author: " << node->book.author
            << ", Year: " << node->book.year << endl;
        displayBooksByYearRange(node->right, startYear, endYear);
    }
}

void BookBST::displayBooksInYearRange(int startYear, int endYear) {
    displayBooksByYearRange(root, startYear, endYear);
}
