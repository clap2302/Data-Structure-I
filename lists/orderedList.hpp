#pragma once
#ifndef ORDERED_LIST_HPP
#define ORDERED_LIST_HPP

#include <iostream>
using namespace std;

struct Node
{
    int info;
    struct Node *next;
};

class orderedList
{
    private:
    
    public:
    Node *start;
    Node *end;

    orderedList();
    orderedList(Node *start);
    void insert(int n);
    int pop(int n);
    void list();

    /*
    *  FIRST QUESTION
    */
    
    bool isOddPrime(int n);
    orderedList popOddPrimes();
    void insertInDescendingOrder(Node *&node, Node *&startList);
    void cleanList(Node *&startList);
    void sortInAscendigOrder();


    void handleEmptyStructure();
};

#endif