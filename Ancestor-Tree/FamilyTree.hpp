/**
 * This class represents a family tree that uses a binary tree data structure. 
 * The tree root is a person and the two edges that coming out from him represent his parents. 
 * And so is every person in the tree.
 * 
 * Author: Meir Nizri
 * Second assignment in cpp course
 * Date: 2020-04
 */

#pragma once
#include <string>
#include <stdbool.h>
using namespace std;

namespace family {
    
    struct Person {
		string name;
		string relation;
        bool isMale;
        Person *father, *mother, *son;
    };
    
    class Tree {
    private:
        Person* root;
        // private methods
        Person* newPerson(string name);
        Person* search(string name, Person* p);
        Person* find(string relation, Person* p);
        void freeTree(Person* p);
        void printTree(Person* root, int space);
    public:
	    Tree(string name);
        Tree& addFather(string son, string father);
        Tree& addMother(string son, string mother);
        string relation(string name);
        string find(string relation);
        Tree& remove(string name);
	    ~Tree();
        void display();
    };
}