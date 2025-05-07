#include "evenAndOddList.hpp"

evenAndOddList::evenAndOddList()
{
    this->start = nullptr;
    this->oddStart = nullptr;
    this->evenStart = nullptr;
}

void evenAndOddList::insert(int n)
{
    nodo *newNodo = new nodo();
    newNodo->info = n;
    
    /* Main List */
    if (this->start == nullptr)
    {
        newNodo->next = nullptr;
        newNodo->other = nullptr;
        this->start = newNodo;
    }

    nodo *temp = this->start;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNodo;
    
    int isEvenNumber = 0;
    if (newNodo->info%2 == 0)
    {    
        isEvenNumber = 1;
    }
    
    temp = isEvenNumber ? this->evenStart: this->oddStart;

    if (temp == nullptr)
    {
        if (isEvenNumber)
        {
            this->evenStart = newNodo;
        }
        else
        {
            this->oddStart = newNodo;
        }
        return;
    }

    while (temp->other != nullptr && temp->other->info >= newNodo->info)
    {
        temp = temp->other;
    }

    if (temp->other == nullptr && temp->info < newNodo->info)
    {
        temp->other = newNodo;
        newNodo->other = nullptr;
    }

    else if (temp == this->evenStart || temp == this->oddStart)
    {
        if (isEvenNumber)
        {
            newNodo->other = this->evenStart;
            this->evenStart = newNodo;
        }
        else
        {
            newNodo->other = this->oddStart;
            this->oddStart = newNodo;
        }
    }
    
    else
    {
        newNodo->other = temp->other;
        temp->other = newNodo;
    }

}

void evenAndOddList::list()
{
    nodo *temp = this->start;
    
    std::cout << "Linear List" << std::endl;
    while (temp != nullptr)
    {
        std::cout << "Value --> " << temp->info << std::endl;
        temp = temp->next;
    }
    
    temp = this->evenStart;
    std::cout << "\n\nEven List" << std::endl;
    while (temp != nullptr)
    {
        std::cout << "Value --> " << temp->info << std::endl;
        temp = temp->other;
    }
    
    temp = this->oddStart;
    std::cout << "\n\nOdd List" << std::endl;
    while (temp != nullptr)
    {
        std::cout << "Value --> " << temp->info << std::endl;
        temp = temp->other;
    }
}

int main()
{
    evenAndOddList lista = evenAndOddList();

    lista.insert(3);
    lista.insert(10);
    lista.insert(5);
    lista.insert(1);
    lista.insert(11);
    lista.insert(0);
    lista.insert(7);
    lista.list();
}