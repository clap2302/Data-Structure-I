#pragma once
#ifndef ORDERED_LIST_HPP
#define ORDERED_LIST_HPP

#include <iostream>
using namespace std;

struct nodo
{
    int info;
    struct nodo *next;
};

class orderedList
{
    private:
    
    public:
    nodo *start;
    nodo *end;

    orderedList();
    void insert(int n);
    int pop();
    void list();
};

#endif