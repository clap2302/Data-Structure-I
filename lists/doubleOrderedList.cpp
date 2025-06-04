#include "doubleOrderedList.hpp"

doubleOrderedList::doubleOrderedList()
{
    this->start = nullptr;
}

void doubleOrderedList::insert(int n)
{
    nodo *newNode, *temp;

    newNode = new nodo();
    newNode->info = n;
    
    if (this->start == nullptr)
    {
        newNode->behind = nullptr;
        newNode->next = nullptr;
        this->start = newNode;
        return;
    }
    
    temp = this->start;
    while (temp->next != nullptr && newNode->info > temp->info)
    {
        temp = temp->next;
    }
    
    // When the info is placed on the end of the list
    if (temp->next == nullptr && newNode->info > temp->info)
    {
        temp->next = newNode;
        newNode->behind = temp;
        newNode->next = nullptr;
    }

    // When the info is placed on the start of the list
    else if (temp == this->start)
    {
        temp->behind = newNode;
        newNode->next = temp;
        newNode->behind = nullptr;
        this->start = newNode;
    }
    // Whe the info is placed on the middle of the list
    else
    {
        newNode->behind = temp->behind;
        temp->behind->next = newNode;
        newNode->next = temp;
        temp->behind = newNode;
    }    

}

void doubleOrderedList::pop(int n)
{
    nodo *temp;

    if(this->start == nullptr)
        return;

    temp = this->start;

    while (temp != nullptr && n != temp->info)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
        return;
    
    if (this->start == temp && temp->next == nullptr)
    {
        this->start = nullptr;
        return;
    }

    if (this->start == temp)
    {
        this->start = this->start->next;
        this->start->behind = nullptr;
    }

    else
    {
        if (temp->next == nullptr)
        {
            temp->behind->next = nullptr;
        }
        else
        {
            temp->behind->next = temp->next;
            temp->next->behind = temp->behind;
        }
    }

    delete temp;
}


void doubleOrderedList::handleEmptyStructure()
{
    if (this->start == nullptr)
    {
        std::cout << "The structure is empty" << std::endl;
        exit(0);
    }
}

void doubleOrderedList::list()
{
    this->handleEmptyStructure();

    nodo *temp = this->start;

    while (temp != nullptr)
    {
        std::cout << "Value --> " << temp->info << std::endl;
        temp = temp->next;
    }
}

int main()
{
    doubleOrderedList lista = doubleOrderedList();

    lista.insert(3);
    lista.insert(10);
    lista.insert(5);
    lista.insert(1);
    lista.insert(11);
    lista.insert(0);
    lista.insert(7);
    lista.pop(0);
    lista.pop(11);
    lista.pop(5);
    lista.list();
}