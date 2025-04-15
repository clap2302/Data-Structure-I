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
                // entre um e outro
                behind->next = newNodo;
                newNodo->next = temp;
            }
        }
    }
}

void orderedList::list()
{
    if (this->start == nullptr)
    {
        std::cout << "The queue is empty" << std::endl;
    }

    nodo *temp = this->start;

    while (temp != nullptr)
    {
        std::cout << "Value --> " << temp->info << std::endl;
        temp = temp->next;
    }
}

int main()
{
    orderedList lista = orderedList();
    lista.insert(3);
    lista.insert(10);
    lista.insert(5);
    lista.insert(1);
    lista.list();

}