#include "queue.hpp"

queue::queue()
{
    this->start = nullptr;
    this->end = nullptr;
}

void queue::insert(int n)
{
    nodo *newNodo;

    newNodo = new nodo();
    if (newNodo == nullptr)
    {
        std::cout << "No memory available" << std::endl;
        return;
    }

    newNodo->info = n;
    newNodo->next == nullptr;

    if (this->start == nullptr)
    {
        this->start = newNodo;
    }
    else
    {
        this->end->next = newNodo;
    }
    this->end = newNodo;
}

int queue::pop()
{
    if (this->end == nullptr)
    {
        std::cout << "The queue is empty" << std::endl;
        return 0;
    }

    nodo *temp = this->start;
    this->start = this->start->next;
    int info = temp->info;
    
    delete temp;
    return info;
}

void queue::list()
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
    queue lista = queue();
    lista.insert(1);
    lista.insert(2);
    lista.insert(3);
    lista.insert(4);
    lista.list();
    lista.pop();
    lista.list();
}
