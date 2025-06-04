#include "stack.hpp"

stack::stack()
{
    this->top = nullptr;
}

void stack::push(int n)
{
    Nodo *newNodo;
    newNodo = new Nodo();

    newNodo->info = n;

    if (this->top != nullptr)
    {
        newNodo->next = this->top;
    }
    else
    {
        newNodo->next = nullptr;
    }

    this->top = newNodo;
}

int stack::pop()
{
    if(this->top != nullptr)
    {
        Nodo *temp = this->top;
        int info = this->top->info;
    
        this->top = temp->next;
        delete temp;

        return info;
    }
    else
    {
        throw(std::underflow_error("Stack is empty"));
    }
}

void stack::list()
{
    Nodo *temp = this->top;
    
    while (this->top != nullptr)
    {
        std::cout << temp->info << std::endl;
        
        if (temp->next == nullptr)
            break;

        temp = temp->next;
    }
}


int main()
{
    stack demands = stack();
    
    demands.push(10);
    demands.push(4);
    demands.push(1234);

    /*
    * PRITING POPED VALUE
    */
    std::cout << demands.pop() << std::endl << std::endl;
    

    /*
    * PRITING REST OF THE STACK
    */
    demands.list();

}