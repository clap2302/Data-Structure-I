#include "orderedList.hpp"


orderedList::orderedList()
{
    this->start = nullptr;
}

orderedList::orderedList(Node *start)
{
    this->start = start;
}

void orderedList::insert(int n)
{
    Node *newNode = new Node();

    if (newNode == nullptr)
    {
        std::cout << "No memory available" << std::endl;
        return;
    }
    newNode->info = n;

    Node *behind = this->start;
    Node *temp = this->start;

    if (this->start == nullptr)
    {
        this->start = newNode;
        newNode->next = nullptr;
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
            behind->next = newNode;
            newNode->next = nullptr;
        }
        else
        {
            if (this->start == temp)
            {
                newNode->next = this->start;
                this->start = newNode;
            }
            else
            {
                behind->next = newNode;
                newNode->next = temp;
            }
        }
    }
}

int orderedList::pop(int n)
{
    this->handleEmptyStructure();
    
    Node *behind = this->start;
    Node *temp = this->start;

    while (temp != nullptr && temp->info != n)
    {
        behind = temp;
        temp = temp->next;
    }
    
    if (temp == nullptr)
    {
        std::cout << "Number " << n << " was not encountered!!" << std::endl;
        exit(0);
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
    int info = temp->info;
    delete temp;
    return info;
   
}

void orderedList::list()
{
    this->handleEmptyStructure();

    Node *temp = this->start;

    while (temp != nullptr)
    {
        std::cout << "Value --> " << temp->info << std::endl;
        temp = temp->next;
    }
}

bool orderedList::isOddPrime(int n)
{
    if (n == 2)
        return true;

    if (n<2)
        return false;

    for (int i = 2; i<=n/2; i++)
        if (n%i == 0)
            return false;

    return true;
}

orderedList orderedList::popOddPrimes()
{
    if (this->start == nullptr)
        exit(1);
    
    Node *startList = nullptr;
    Node *current = this->start;
    Node *temp = nullptr;

    while (current != nullptr)
    {
        if (this->isOddPrime(current->info))
        {
            temp = current->next;
            Node *newNode = new Node();
            newNode->info = this->pop(current->info);
            this->insertInDescendingOrder(newNode, startList);
            current = temp;
        }
        else
        {
            current = current->next;
        }
    }

    orderedList primeList = orderedList(startList);
    return primeList;
}

void orderedList::insertInDescendingOrder(Node *&node, Node *&startList)
{
    if (startList == nullptr)
    {
        startList = node;
        return;
    }

    Node *current = startList;
    Node *previous = nullptr;

    while (current != nullptr && current->info > node->info)
    {
        previous = current;
        current = current->next;
    }

    if (current == startList)
    {
        node->next = startList;
        startList = node;
    }
    else if(current == nullptr)
    {
        previous->next = node;
        node->next = nullptr;
    }
    else
    {
        previous->next = node;
        node->next = current;
    }
}

void orderedList::cleanList(Node *&startList)
{
    Node *current = startList;
    Node *temp = startList;

    if (startList == nullptr)
        exit(0);

    while (temp != nullptr)
    {
        temp = current->next;
        delete current;
        current = temp;
    }
    startList = nullptr;
}

void orderedList::handleEmptyStructure()
{
    if (this->start == nullptr)
    {
        exit(0);
    }
}

int main()
{
    orderedList lista = orderedList();
    orderedList primes = orderedList();
    lista.insert(3);
    lista.insert(10);
    lista.insert(5);
    lista.insert(1);
    lista.insert(11);
    lista.insert(0);
    lista.insert(7);
    std::cout << "Original List: " << std::endl;
    lista.list();
    primes = lista.popOddPrimes();
    std::cout << "Primes List: " << std::endl;
    primes.list();
    lista.cleanList(lista.start);
    std::cout << "Original List: " << std::endl;
    lista.list();
}