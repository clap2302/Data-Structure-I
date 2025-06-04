#include "list.hpp"

list::list()
{
    this->start = nullptr;
}

list::list(Node *start)
{
    this->start = start;
}

void list::insert(int n)
{
    Node *newNode = new Node();
    newNode->info = n;
    newNode->next = nullptr;

    if (this->start == nullptr)
    {
        this->start = newNode;
        this->end = newNode;
    }
    else
    {
        this->end->next = newNode;
        this->end = newNode;
    }
}

void list::remove(int n)
{
    Node *current = this->start;
    Node *previous = nullptr; 

    while (current != nullptr && current->info != n)
    {
        previous = current;
        current = current->next;
    }
    
    /*
    * There's no 'n' in the list
    */
    if (current == nullptr)
        return;
    
    /*
    * Replacing end pointer if necessary
    */
    if (current == this->end)
        this->end = previous;
    
    /*
    * Replacing start pointer if necessary
    */
    if (current == this->start)
    {
        this->start = current->next;
        delete current;
    }
    
    /*
    * General cases
    */
    else
    {
        previous->next = current->next;
        delete current;
    }    
}

void list::printList()
{
    Node *temp = this->start;

    while (temp != nullptr)
    {
        std::cout << "Value --> " << temp->info << std::endl;
        temp = temp->next;
    }
}

void list::sortInAscendingOrder()
{
    Node *current, *prevCurr, *temp, *prevTemp;
    
    if (this->start == nullptr)
        return;

    current = this->start->next;
    prevCurr = this->start;

    while (current != nullptr)
    {
        temp = this->start;
        prevTemp = nullptr;

        while (current != temp && temp->info < current->info)
        {
            prevTemp = temp;
            temp = temp->next;
        }

        std::cout << current->info << std::endl;
        if (temp == this->start)
        {
            std::cout << current->info << std::endl;
            prevCurr->next = current->next;
            current->next = temp;
            this->start = current;
        }
        else if (temp == current && current->next == nullptr)
        {
            break;
        }
        else
        {
            prevCurr->next = current->next;
            current->next = temp;
            prevTemp->next = current;
        }

        if (temp == current)
        {
            prevCurr = current;
            current = current->next;
        }
        else
            current = prevCurr->next;
    }
}

int main()
{
    list lista = list();
    lista.insert(7);
    lista.insert(1);
    lista.insert(3);
    lista.insert(4);
    lista.insert(6);
    lista.insert(10);

    std::cout << "Original List:" << std::endl;
    lista.printList();

    lista.sortInAscendingOrder();
    std::cout << "Sorted List:" << std::endl;
        lista.printList();

}