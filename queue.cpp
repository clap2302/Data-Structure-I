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

nodo *queue::zip(nodo * startList)
{
    nodo *start, *current, *temp;

    if (startList == nullptr)
    {
        return nullptr;
    }
    current = startList;

    while (current != nullptr)
    {
        nodo *cont = new nodo();
        temp = current;

        while (temp != nullptr)
        {
            if (temp == current)
            {
                cont->info += 1;
                temp->next = temp;
            }
            else
            {
                cont->next = temp;
                break;
            }
        }
        
        current = temp;
    }
    return start;    
}

nodo *queue::intercalate(nodo *x, nodo *y)
{
    nodo *start, *end, *tempx, *tempy;
    start = nullptr;

    if (x == nullptr)
    {
        start = y;
    }
    else
    {
        if (y == nullptr)
        {
            start = x;
        }
        else
        {
            while (x != nullptr && y != nullptr)
            {
                tempx = x;
                tempy = y;
                x = x->next;
                y = y->next;

                tempx->next = tempy;
                tempy->next = nullptr;

                if (start == nullptr)
                {
                    start = tempx;
                    end = tempy;
                }
                else
                {
                    end->next = tempx;
                    end = tempy;
                }
            }

            if (x == nullptr)
            {
                if (y == nullptr)
                {
                    return start;
                }
                else
                {
                    end->next = y;
                }
            }
            else
            {
                end->next = x;
            }
        }
    }
    return start;
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
