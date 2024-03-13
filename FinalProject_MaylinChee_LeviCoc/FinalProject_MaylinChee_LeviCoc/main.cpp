#include <iostream>
#include "bst.h"
using std::string;
/*
Author: Maylin Chee, Levi Coc
Date: Decemeber 4, 2023
*/

bst::bst() { 
    this->root = NULL; 
    }

bst::~bst() { 
    deleteTree(this->root); 
    }
//function use to add books to the tree using nodes 
void bst::insert(int id, string author, string title) { 
    insertHelper( &(this->root), id, title, author ); 
    }

void bst::insertHelper(node** node, int id, string title, string author) {
    if (*node == NULL) {
        struct node* temp = new struct node;
        temp->bookID = id;
        temp->title = title;
        temp->author = author;
        temp->left = temp->right = NULL;
        *node = temp;
    } else {
        if ( id < (*node)->bookID )
            insertHelper( &(*node)->left, id, title, author );
        else
            insertHelper( &(*node)->right, id, title, author );
    }
}
//function calls traverseInOrder
void bst::traverse() {
    traverseInOrder(this->root);
    std::cout << std::endl;
    std::cout  << "ID  " <<  "TITLE  " << "AUTHOR" << "\n";
}
//function shows the in order by node id number
void bst::traverseInOrder(node* root) {
    
    if (root == NULL)
        return;
    traverseInOrder(root->left);
    std::cout << root->bookID << " " << root->title << " " << root->author << "\n";
    traverseInOrder(root->right);    
}
//functions works along the search function to display the node's data
void bst::display(node* node) {
    std::cout <<  "ID: " << node->bookID << "\n"  << "Title: " << node->title << "\n" << "Author: " << node->author << "\n";
   
}
//function use to search node by id in the bst
node* bst::search(int id) { 
    return searchHelper( this->root, id ); 
    }

node* bst::searchHelper(node* node, int id) {
    if (node != NULL) {
        if (id == node->bookID) {
            return node;
        } else if (id > node->bookID) {
            return searchHelper( node->right, id );
        } else if (id < node->bookID) {
            return searchHelper( node->left, id );
            
        }
    } else {
        std::cout << "Sorry, that value isn't in this tree.";
        return NULL;
    }
}
//function to update the existing data node
void bst::update(int id, string title, string author) { 
    updateHelper( this->root, id, title, author ); 
}

void bst::updateHelper(node* node, int id, string title, string author) {
    if (search(id) != NULL) {
        deleteNode(id);
        insert(id, title, author);
    }
}

//deletenode function calls the helper function
void bst::deleteNode(int id) { 
    deleteHelper( &(this->root), id ); 
}
//function to delete the node and data that is with the node
void bst::deleteHelper(node** node, int id) {
	struct node* temp = new struct node;

	if (*node == NULL)
		return;
	else if ( id < (*node)->bookID )
		deleteHelper( &( (*node )->left ), id );
	else if ( id > (*node)->bookID )
		deleteHelper( &( (*node )->right ), id );
	else {
	    temp = *node;

    	if ( (*node)->right == NULL ) {
    		*node = (*node)->left;
    		delete temp;
    	} else if ( (*node)->left == NULL ) {
    		*node = (*node)->right;
    		delete temp;
    	} else
    		delete temp;
	}
}

//simple function to delete the whole binary search tree
void bst::deleteTree(node* root) {
    if (root == NULL)
        return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}
