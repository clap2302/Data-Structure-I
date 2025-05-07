#include <iostream>
#include <string>
#include <cstdlib>

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
    Node * changeWord(std::string newString, Node *currentNode);
    Node * removeWord(Node *currentNode);
    std::string showSentence();

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

Node *task2::changeWord(std::string newString, Node *currentNode)
{
    currentNode->info = newString;
    return currentNode;
}

Node *task2::removeWord(Node *currentNode)
{
    if (currentNode->next == currentNode)
    {
        delete currentNode;
        return nullptr;
    }
    else
    {
        currentNode->next->behind = currentNode->behind;
        currentNode->behind->next = currentNode->next;
        Node *aux = currentNode->next;

        delete currentNode;
        return aux;
    }
}

std::string task2::showSentence()
{
    Node *temp = this->start;
    std::string sentence;
    
    do
    {
        sentence += temp->info + " ";
        temp = temp->next;
    } while (temp != this->start);

    return sentence;
}

void clearScreen() 
{
    #ifdef _WIN32
        system("cls");   // Windows
    #else
        system("clear"); // Linux / macOS
    #endif
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
        {
            std::cout << "\n\n\nFrase: " << editor.showSentence() << std::endl;
            std::cout << "\n\nPalavra atual: " << currentNode->info << std::endl;
        }
        else
        {
            std::cout << "\n\n\nFrase: " << "*FRASE VAZIA*" << std::endl;
            std::cout << "\n\nPalavra atual: " << "*FRASE VAZIA*" << std::endl;
        }
        
        std::cout << "\n\nInsira uma opção: " << std::endl;
        std::cout << "e -> Editar palavra atual" << std::endl;
        std::cout << "i -> Inserir palavra depois da atual" << std::endl;
        std::cout << "r -> Eliminar palavra atual" << std::endl;
        std::cout << "< -> Palavra anterior" << std::endl;
        std::cout << "> -> Palavra posterior" << std::endl;
        std::cout << "s -> Sair" << std::endl;

        std::cout << "\nDigite sua opção: ";
        std::cin >> option;

        switch (option)
        {
        case 'e':
            std::cout << "\nDigite a nova palavra: ";
            std::cin >> newWord;
            currentNode = editor.changeWord(newWord, currentNode);
            break;
        
        case 'i':
            std::cout << "\nDigite a nova palavra: ";
            std::cin >> newWord;
            currentNode = editor.insert(newWord, currentNode);
            break;
        
        case 'r':
            currentNode = editor.removeWord(currentNode);
            break;
        
        case '<':
            currentNode = currentNode->behind;
            break;
        
        case '>':
            currentNode = currentNode->next;
            break;
        
        case 's':
            exit(1);
        
        default:
            std::cout << "Selecione uma opção válida!!" << std::endl;
        }

        clearScreen();
    }
    
}
