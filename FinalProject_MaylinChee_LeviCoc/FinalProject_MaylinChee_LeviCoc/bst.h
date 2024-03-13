#ifndef BST_H
#define BST_H
#include <iostream>
using std::string;

/*
Author: Maylin Chee, Levi Coc
Date: Decemeber 4, 2023
*/

//struct use to group several related variables into one place
struct node {
    int bookID;
    string author;
    string title;
    node* right;
    node* left;
};
//class name bst Member functions
class bst {
public:
    bst();
    ~bst();
    void insert(int id, string title, string author);
    node* search(int id);
    void update(int id, string title, string author);
    void deleteNode(int id);
    void traverse();
    void display(node* node);
    node* root;
private:
    void insertHelper(struct node** node, int id, string title, string author);
    node* searchHelper(node* node, int id);
    void updateHelper(node* node, int id, string title, string author);
    void deleteHelper(node** node, int id);
    void traverseInOrder(node* root);
    void deleteTree(node* root);
};


#endif