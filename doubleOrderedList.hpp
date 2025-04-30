#pragma once
#ifndef DOUBLE_ORDERED_LIST_HPP
#define DOUBLE_ORDERED_LIST_HPP

#include <iostream>
using namespace std;

struct nodo
{
    int info;
    struct nodo *next, *behind;
};

class doubleOrderedList
{
    private:
    
    public:
    nodo *start;
    nodo *end;

    doubleOrderedList();
    void insert(int n);
    void pop(int n);
    void list();

    void handleEmptyStructure();
};

#endif