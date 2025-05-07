#pragma once
#ifndef EVEN_AND_ODD_LIST_HPP
#define EVEN_AND_ODD_LIST_HPP

#include <iostream>
using namespace std;

struct nodo
{
    int info;
    struct nodo *next, *other;
};

class evenAndOddList
{
    private:

    public:

        nodo *start, *evenStart, *oddStart;
        evenAndOddList();
        
        void insert(int n);
        void list();
};

#endif