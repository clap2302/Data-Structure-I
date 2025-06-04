#include <iostream>

struct Nodo2
{
    int info;
    Nodo2 * prox;
    Nodo2 * ant;
};

void clearScreen() 
{
    #ifdef _WIN32
        system("cls");   // Windows
    #else
        system("clear"); // Linux / macOS
    #endif
}

class questao2Prova
{
private:
    Nodo2 *inicio;
    Nodo2 *fim;
    
public:
    questao2Prova();
    void inserir(int n);
    void removerVizinhos(int n);
    void removerElemento(int n);
    void listar();
};

questao2Prova::questao2Prova()
{
    this->inicio = nullptr;
    this->fim = nullptr;
}

void questao2Prova::inserir(int n)
{
    Nodo2 *novo = new Nodo2();
    novo->info = n;
    novo->prox = nullptr;

    if (this->inicio == nullptr)
    {
        novo->ant = nullptr;
        this->inicio = novo;
    }
    else
    {
        novo->ant = this->fim;
        this->fim->prox = novo;
    }
    this->fim = novo;
}

void questao2Prova::removerVizinhos(int n)
{
    if (this->inicio == nullptr)
    {
        return;
    }

    Nodo2 *atual = this->inicio;

    while (atual != nullptr)
    {
        if (atual->info == n)
        {
            Nodo2 * ant = atual->ant;
            Nodo2 * prox = atual->prox;

            if (ant != nullptr)
            {
                if (ant->ant != nullptr)
                {
                    ant->ant->prox = atual;
                }
                else
                {
                    this->inicio = atual;
                }
                atual->ant = ant->ant;
                delete ant;
            }
            
            if (prox != nullptr)
            {
                if (prox->prox != nullptr)
                {
                    prox->prox->ant = atual;
                }
                else
                {
                    this->fim = atual;
                }
                atual->prox = prox->prox;
                delete prox;
            }
        }
        atual = atual->prox;
    }
}

void questao2Prova::removerElemento(int n)
{
    Nodo2 *aux;

    if(this->inicio == nullptr)
        return;

    aux = this->inicio;

    while (aux != nullptr && n != aux->info)
    {
        aux = aux->prox;
    }

    if (aux == nullptr)
        return;
    
    if (this->inicio == aux && aux->prox == nullptr)
    {
        this->inicio = nullptr;
        return;
    }

    if (this->inicio == aux)
    {
        this->inicio = this->inicio->prox;
        this->inicio->ant = nullptr;
    }

    else
    {
        if (aux->prox == nullptr)
        {
            aux->ant->prox = nullptr;
        }
        else
        {
            aux->ant->prox = aux->prox;
            aux->prox->ant = aux->ant;
        }
    }

    delete aux;
}

void questao2Prova::listar()
{
    Nodo2 *aux = this->inicio;

    while (aux != nullptr)
    {
        std::cout << "Value --> " << aux->info << std::endl;
        aux = aux->prox;
    }

    std::cout << std::endl;
}


int main()
{
    clearScreen();
    questao2Prova lista = questao2Prova();

    while (true)
    {
        int option;

        std::cout << "Lista atual: " << std::endl;
        lista.listar();

        std::cout << "1 - Inserir elemento" << std::endl;
        std::cout << "2 - Remover elemento" << std::endl;
        std::cout << "3 - Retirar elementos vizinhos" << std::endl;
        std::cout << "4 - Sair" << std::endl << std::endl;


        std::cout << "Insira sua opção: " << std::endl;
        std::cin >> option;

        switch (option)
        {
        case 1:
            std::cout << "Insira o número para adicionar: " << std::endl;
            std::cin >> option;
            lista.inserir(option);
            break;

        case 2:
            std::cout << "Insira o número para remover: " << std::endl;
            std::cin >> option;
            lista.removerElemento(option);
            break;

        case 3:
            std::cout << "Insira o número que deseja remover os vizinhos: " << std::endl;
            std::cin >> option;
            lista.removerVizinhos(option);
            break;

        case 4:
            exit(1);
            break;
        
        default:
            break;
        }

        clearScreen();
    }
}