/* 
    1. Escreva  funções,  em  C,  que  recebam  uma  lista  simplesmente  encadeada 
    ordenada, e realizem as seguintes operações:  
        a.  retirar  todos  os  elementos  ímpares  que  são  primos,  e,  gerar  uma 
    outra  lista  contendo  apenas  os  elementos  retirados  da  lista  inicial, 
    em ordem decrescente; 
        b.  retirar todos os elementos pares da lista inicial. 
    
    2. Escreva uma  função, em  C,  que  receba uma  lista  simplesmente encadeada, e 
    retorne uma lista ordenada (crescente) sem alocar espaços para novos 
    elementos da lista.

    4. Escreva uma função, em C, para eliminar todos os elementos inteiros
    repetidos em uma lista simplesmente encadeada. Considere que os elementos
    nesta estrutura não estão ordenados.

    5. Considere  uma  lista  simplesmente  encadeada  que  armazene  números  em 
    ordem crescente. Escreva uma função, em C, que receba esta lista, e remova o 
    nó  antecessor  e  o  sucessor  a  um  determinado  nó  contendo  um  elemento  X 
    (inteiro).

    6. Escreva  uma  função,  em  C,  que  receba  uma  lista  simplesmente  encadeada 
    contendo  em  cada  nó  um  inteiro,  e  retorne  uma  outra  lista  contendo  nas
    primeiras  posições  os  elementos  pares  em  ordem  decrescente,  seguidos  dos 
    elementos ímpares em ordem crescente. 
    OBS.: A função não deverá alocar nenhum nó, e todas as funções utilizadas na 
    resolução deverão ser implementadas. 


*/

#include <iostream>
#include "../queue.hpp"

struct Node
{
    int info;
    struct Node *next;
};

class ListQueue: public 
{
    private:
    Node *start;

    public:
    void list();
    void insert(int n);
    int pop(int n);

    void sortInAscendingOrder();
    void sortInDecreasingOrder();

    void popOddPrimeNumbers(Node *startOldList)
    {
        Node *newListStart, *temp, *end, *behind;
        
        if (startOldList == nullptr)
        {
            std::cout << "The list is empty" << std::endl;
            return;
        }

        temp = startOldList;
        behind = nullptr;
        // iterating old list
        while (temp != nullptr)
        {
            // identifing prime numbers
            for (int i=2; temp->info/2; i++)
            {
                if (temp->info % i == 0)
                {
                    if (newListStart == nullptr)
                    {
                        newListStart = temp;
                        end = temp;
                    }
                    else
                    {
                        end->next = temp;
                        end = temp;
                    }
                }
            }

            temp = temp->next;
        }
        
    }


    
};