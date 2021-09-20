/**
 * This class represents a family tree that uses a binary tree data structure. 
 * The tree root is a person and the two edges that coming out from him represent his parents. 
 * And so is every person in the tree.
 * 
 * Author: Meir Nizri
 * Second assignment in cpp course
 * Date: 2020-04
 */

#include "FamilyTree.hpp"
#include <stdexcept>
#include <iostream>
#define COUNT 10  

using namespace std;
using namespace family;

/* Create new person */
Person* Tree::newPerson(string name) {
    Person* p = new Person;
    p->name = name;
    p->father = p->mother = p->son = NULL;
    return p;
}

/* Constructor. build only the root */
Tree::Tree(string name) {
    root = newPerson(name);
    root->relation = "me";
}

/* Search person by its name and returns pointer to it */
Person* Tree::search(string name, Person* p) {
    if(p != NULL) {
        if(p->name == name) return p;
        else {
            // recursive on father than mother
            Person* tmp = search(name, p->father);
            if(tmp != NULL) return tmp;
            return search(name, p->mother);
        }
    }
    return NULL;
}

/* Add father to this specific name */
Tree& Tree::addFather(string son, string father) {
    Person* s = search(son, root);
    // if son doesn't exist or already has a father throw exception
    if(s == NULL) throw std::runtime_error("There is no such person");
    if(s->father != NULL) throw std::runtime_error("Already has a father");
    // Create and initialize father variables
    Person* f = newPerson(father);
    s->father = f;
    f->isMale = true;
    f->son = s;
    // Find the relation of the father to the root
    if(s->relation == "me")
        f->relation = "father";
    else if(s->relation == "father" || s->relation == "mother")
        f->relation = "grandfather";
    else
        f->relation = "great-" + s->relation.substr(0,s->relation.size()-6) + "father";
    return *this;
}

/* Add mother to this specific name */
Tree& Tree::addMother(string son, string mother) {
    Person* s = search(son, root);
    // if son doesn't exist or already has a mother throw exception
    if(s == NULL) throw std::runtime_error("There is no such person");
    if(s->mother != NULL) throw std::runtime_error("Already has a mother");
    // Create and initialize mother variables
    Person* m = newPerson(mother);
    s->mother = m;
    m->isMale = false;
    m->son = s;
    // Find the relation of the mother to the root
    if(s->relation == "me")
        m->relation = "mother";
    else if(s->relation == "father" || s->relation == "mother")
        m->relation = "grandmother";
    else
        m->relation = "great-" + s->relation.substr(0,s->relation.size()-6) + "mother";
    return *this;         
}

/* Finds the relation of the name given relative to the root */
string Tree::relation(string name) {
    Person* p = search(name, root);
    if(p != NULL)
        return p->relation;
    else
        return "unrelated";
}

/* Finds and return the person given his relation to the root */
Person* Tree::find(string relation, Person* p) {
    if(p != NULL) {
        if(p->relation == relation) return p;
        else {
            // recursive on father than mother
            Person* tmp = find(relation, p->father);
            if(tmp != NULL) return tmp;
            return find(relation, p->mother);
        }
    }
    return NULL;
}

/* Finds and return the person name given his relation to the root */
string Tree::find(string relation) {
    Person* p = find(relation, root);
    if(p != NULL)
        return p->name;
    else
        throw std::runtime_error("There is no person with this relation");
    return " ";
}

/* Recursive function that deletes all person in the subtree of p */
void Tree::freeTree(Person* p) {
	if(p) {
		freeTree(p->father);
		freeTree(p->mother);
		delete p;
	}
}

/* Removes person and deletes all his subtree from the tree */
Tree& Tree::remove(string name) {
    Person* p = search(name, root);
    if(p == NULL || root == NULL || p == root) 
        throw std::runtime_error ("Unable to remove this person");
    else {
        // delets the son relation to this person
        if(p->isMale) p->son->father = NULL;
        else p->son->mother = NULL;
        freeTree(p);
    }
    return *this;          
}

/* Destructor for the tree */
Tree::~Tree() {
	freeTree(root);
}

/* Recursive function to print the tree */
void Tree::printTree(Person* root, int space) {  
    if (root == NULL)  
        return;  
    // Increase distance between levels  
    space += COUNT;  
    // Process father first  
    printTree(root->father, space);  
    // Print current person after space  
    cout << endl;  
    for (int i = COUNT; i < space; i++)  
        cout << " ";  
    cout << root->name << "\n";  
    // Process mother  
    printTree(root->mother, space);  
}  

/* print the tree */
void Tree::display() {
     printTree(root, 0);         
}