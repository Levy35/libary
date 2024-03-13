#include <iostream>
#include "bst.h"
#include "main.cpp"
using namespace std;


/* Use a binary search tree (BST) to create a bookstore app.
 * Demonstrate efficiently handle operations like searching, inserting, deleting, and updating books.
 * The books will be stored in a binary search tree based on a specific key (for example, book title). 
 * Each node could represent a book and contains information of the book (title, author, etc).
 * 
 /*
Author: Maylin Chee, Levi Coc
Date: Decemeber 4, 2023
*/

//showMenu function to add a prompt for user to choose what they want to do
void showMenu() {
    cout << "****************************\n";
    cout << "* Press 1 to INSERT        *\n";
    cout << "* Press 2 to UPDATE        *\n";
    cout << "* Press 3 to SEARCH        *\n";
    cout << "* Press 4 to DELETE        *\n";
    cout << "* Press 5 to TRAVERSE      *\n";
    cout << "* Press 6 to QUIT          *\n";
    cout << "****************************\n";
    cout << "=====> ";
}
//getresponse function to take user to desired key
int getResponse() {
    int response;
    
    do {
        showMenu();
        cin >> response;
    } while (response < 1 || response > 6);
    
    return response;
}
//use switch case to prompt user with the input of thier books
int main() {
    bst bookstore;
    int response;
    while ( (  response = getResponse() ) != 6 ) {
        switch( response ) {
            case 1: {
                int id;
                string title, author;
                cout << "Insert book ID: ";
                cin >> id;
                cout << "Insert book title: ";
                cin >> title;
                cout << "Insert book author: ";
                cin >> author;
                
                bookstore.insert(id, title, author); 
            } cout << "\n\n"; break;
            case 2: {
                int id;
                string title, author;
                cout << "Insert book ID: ";
                cin >> id;
                cout << "Insert new book title: ";
                cin >> title;
                cout << "Insert new book author: ";
                cin >> author;
                
                bookstore.update(id, title, author); 
            } cout << "\n\n"; break;
            case 3: {
                int id;
                cout << "Insert ID of the book to search for: ";
                cin >> id;
                
                bookstore.display( bookstore.search(id) );
            } cout << "\n\n"; break;
            case 4: {
                int id;
                cout << "Insert ID of the book to delete: ";
                cin >> id;
                
                bookstore.deleteNode(id);
            } cout << "\n\n"; break;
            case 5:
                cout << "Inorder traversal:\n";
                bookstore.traverse();
                cout << "\n\n"; break;
        }
    }
    return 0;
}