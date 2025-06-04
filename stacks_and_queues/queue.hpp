#pragma once
#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
using namespace std;

struct nodo
{
    int info;
    struct nodo *next;
};

class queue
{
    private:
    nodo *start, *end;
    
    public:
    queue();
    void insert(int n);
    int pop();
    void list();

    nodo * zip(nodo *startList);
    nodo * unzip(nodo *startList);
    nodo * intercalate(nodo *firstList, nodo *secondList);

};

#endif