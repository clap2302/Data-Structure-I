#pragma once
#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
using namespace std;

struct Node
{
    int info;
    struct Node *next;
};

class list
{
    private:
    
    public:
    Node *start;
    Node *end;

    list();
    list(Node *start);
    void insert(int n);
    void remove(int n);
    void printList();
    void sortInAscendingOrder();
};

#endif