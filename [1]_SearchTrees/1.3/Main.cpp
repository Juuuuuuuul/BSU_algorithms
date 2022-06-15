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

int max_l(Node* root) {
    while (root->l != NULL) root = root->l;
    return root->x;
}

Node* del_elem(Node* dNode, int dData) {
    if (NULL == dNode) return NULL;
    if (dNode->x == dData) {
        if (NULL == dNode->l && NULL == dNode->r) {
            free(dNode);
            return NULL;
        }
        if (NULL == dNode->l && NULL != dNode->r) {
            Node* temp = dNode->r;
            free(dNode);
            return temp;
        }
        if (NULL != dNode->l && NULL == dNode->r) {
            Node* temp = dNode->l;
            free(dNode);
            return temp;
        }
        dNode->x = max_l(dNode->r);
        dNode->r = del_elem(dNode->r, dNode->x);
        return dNode;
    }
    if (dNode->x > dData) {
        dNode->l = del_elem(dNode->l, dData);
        return dNode;
    }
    if (dNode->x < dData) {
        dNode->r = del_elem(dNode->r, dData);
        return dNode;
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

    int k;
    fin >> k;

    for (int i = 1; fin; i++) {
        int x;
        fin >> x;
        add(x, MyTree);
    }
    int del;
    
    //Out(MyTree);
    MyTree = del_elem(MyTree, k);
    Out(MyTree);
}
