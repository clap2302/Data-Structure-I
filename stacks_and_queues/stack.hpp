#pragma once
#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <stdexcept>
using namespace std;

struct Nodo
{
    int info;
    struct Nodo *next;
};

class stack
{
    private:
    
    public:
    Nodo *top;
    stack();
    void push(int n);
    int pop();
    void list();
};

#endif