#include "orderedList.hpp"


orderedList::orderedList()
{
    this->start = nullptr;
}

void orderedList::insert(int n)
{
    nodo *newNodo = new nodo();

    if (newNodo == nullptr)
    {
        std::cout << "No memory available" << std::endl;
        return;
    }
    newNodo->info = n;

    nodo *behind = this->start;
    nodo *temp = this->start;

    if (this->start == nullptr)
    {
        this->start = newNodo;
        newNodo->next = nullptr;
    }
    else
    {
        while (temp != nullptr && temp->info < n)
        {
            behind = temp;
            temp = temp->next;
        }
        
        if (temp == nullptr)
        {
            behind->next = newNodo;
            newNodo->next = nullptr;
        }
        else
        {
            if (this->start == temp)
            {
                newNodo->next = this->start;
                this->start = newNodo;
            }
            else
            {
                behind->next = newNodo;
                newNodo->next = temp;
            }
        }
    }
}

void orderedList::pop(int n)
{
    this->handleEmptyStructure();
    
    nodo *behind = this->start;
    nodo *temp = this->start;

    while (temp != nullptr && temp->info != n)
    {
        behind = temp;
        temp = temp->next;

    }
    
    if (temp == nullptr)
    {
        std::cout << "Number " << n << " was not encountered!!" << std::endl;
        return;
    }

    // Encountered number to be poped 
    if (temp == this->start)
    {
        this->start = this->start->next;
    }
    else
    {
        behind->next = temp->next;
    }
    delete temp;
   
}

void orderedList::list()
{
    this->handleEmptyStructure();

    nodo *temp = this->start;

    while (temp != nullptr)
    {
        std::cout << "Value --> " << temp->info << std::endl;
        temp = temp->next;
    }
}

void orderedList::handleEmptyStructure()
{
    if (this->start == nullptr)
    {
        std::cout << "The structure is empty" << std::endl;
        exit(0);
    }
}

int main()
{
    orderedList lista = orderedList();
    lista.insert(3);
    lista.insert(10);
    lista.insert(5);
    lista.insert(1);
    lista.insert(11);
    lista.insert(0);
    lista.insert(7);
    lista.pop(0);
    lista.pop(11);
    lista.list();

}