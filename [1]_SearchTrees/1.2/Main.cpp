#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include <set>
#include <iterator>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("input.txt");
ofstream out("output.txt");

struct Node {
    int x;

    Node* l;
    Node* r;
};

void add(int x, Node*& MyTree) {

    if (NULL == MyTree) {
        MyTree = new Node; 
        MyTree->x = x; 
        MyTree->l = MyTree->r = NULL; 
    }

    if (x > MyTree->x) {
        if (MyTree->r != NULL) add(x, MyTree->r);
        else {
            MyTree->r = new Node;
            MyTree->r->l = MyTree->r->r = NULL;
            MyTree->r->x = x;
        }
    }

    if (x < MyTree->x) {
        if (MyTree->l != NULL) add(x, MyTree->l);
        else {
            MyTree->l = new Node;  
            MyTree->l->l = MyTree->l->r = NULL; 
            MyTree->l->x = x;
        }
    }

}

void Out(Node*& tree) {
    if (NULL == tree)    return;   

    out << tree->x << endl; 
    Out(tree->l); 
    Out(tree->r);    
}


void main() {
    Node* MyTree = NULL; 

    ifstream fin("input.txt");
    ofstream out("output.txt");

    for (int i = 0; fin ; i++)  {
        int x;
        fin >> x;
        add(x, MyTree);
	}
    Out(MyTree); 
}
