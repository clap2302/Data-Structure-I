#include <iostream>
#include <string>

using namespace std;

struct Node
{
    std::string info;
    Node *next;
    Node *behind;
};

class task2
{
private:
    Node *start;
public:
    task2();
    Node * insert(std::string info, Node *currentNode);
    Node * changeWord(bool isNextWord);

};

task2::task2()
{
    this->start = nullptr;
}

Node * task2::insert(std::string info, Node *currentNode)
{
    Node *newNode = new Node;
    newNode->info = info;

    if (this->start == nullptr)
    {
        newNode->behind = newNode;
        newNode->next = newNode;
        this->start = newNode;
        return newNode;
    }

    if (currentNode->next == this->start)
    {
        newNode->next = this->start;
        newNode->behind = currentNode;

        currentNode->next = newNode;
        this->start->behind = newNode;
    }
    else
    {
        newNode->next = currentNode->next;
        newNode->behind = currentNode;

        currentNode->next->behind = newNode;
        currentNode->next = newNode;
    }

    return newNode;
}

Node *task2::changeWord(bool isNextWord)
{
    return nullptr;
}

int main()
{

    task2 editor = task2();
    Node *currentNode = nullptr;
    std::string newWord;

    while (true)
    {
        char option;
        if (currentNode != nullptr)
            std::cout << "\n\nPalavra atual: " << currentNode->info << std::endl;
        else
            std::cout << "\n\nPalavra atual: " << "*FRASE VAZIA*" << std::endl;
        
        std::cout << "\n\nInsira uma opção: " << std::endl;
        std::cout << "Editar palavra atual: e" << std::endl;
        std::cout << "Inserir palavra depois da atual: i" << std::endl;
        std::cout << "Eliminar palavra atual: r" << std::endl;
        std::cout << "Palavra anterior: a" << std::endl;
        std::cout << "Palavra posterior: p" << std::endl;
        std::cout << "Sair: s" << std::endl;

        std::cout << "\nDigite sua opção: ";
        std::cin >> option;

        switch (option)
        {
        case 'e':
            break;
        
        case 'i':
            std::cout << "\nDigite a nova palavra: ";
            std::cin >> newWord;
            currentNode = editor.insert(newWord, currentNode);
            break;
        
        case 'r':
            break;
        
        case 'a':
            currentNode = currentNode->behind;
            break;
        
        case 'p':
            currentNode = currentNode->next;
            break;
        
        case 's':
            exit(1);
        
        default:
            std::cout << "Selecione uma opção válida!!" << std::endl;
        }
    }
    
}
