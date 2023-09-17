#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>
#include "trabalho.h"

int count = 0;
const int deckSize = 52;
const int freeCellsSize = 4;

//================================================================[[[[PILHAS DE JOGO]]]]================================================================

Pile::Pile()
{
    top = 0;
}

Pile::~Pile()
{
    std::cout << "Pilha destruida \n";
}

bool Pile::Empty()
{
    return (top == 0);
}

bool Pile::Full()
{
    return (top == maxGamePile);
}

void Pile::Top(card& c)
{
    if(top == 0)
    {
        std::cout << "Pilha vazia";
    }
    c = Entry[top];
}

void Pile::Push(card& c)
{
    if(Full())
    {
        std::cout << "Pilha Cheia \n";
    }

    top++;
    Entry[top] = c;
}

void Pile::pop(card& c)
{
    if(Empty())
    {
        std::cout << "Pilha ja esta vazia \n";
    }

    c = Entry[top];
    top = top - 1;

}

//================================================================[[[[CÓDIGO DO JOGO]]]]=============================================================
void Regras_Frecell()
{
    std::cout << "como jogar: " << std::endl
    << "O objetivo do jogo empilhar todas as cartas de cada um dos naipe do as ate o rei em suas respectivas pilhas de saida. " << std::endl
    << "E possivel movimentar cartas entre as pilhas de jogo, contanto que obedeca a seguinte regra:" << "\n"
    << "nas pilhas de jogo todas as cartas devem ser empilhadas em ordem decrescente(do rei ate o as) sempre alternando a cor do naipe, ou seja se voce tiver uma carta preta a de baixo obrigatoriamente sera  vermelha" << "\n"
    << "Voce pode mover qualquer carta para uma free cell vazia, deste modo e possivel acessar a carta de tras da mesma." << std::endl
    << "Uma vez movida para uma das freecells a carta so pode retorna a pilha de jogo sob as condicoes de movimento das pilhas de jogo" << "\n"
    << "As jogadas consistem em indicar qual sera a pilha do seu movimento(ultima carta da pilha) e o endereco para qual a carta sera movida." <<std::endl
    << "(Digite 99 para encerrar o jogo)\n\n";
    
    std::cout << "\n\n";

}

void card::cardMaker(card deck[])
{
    int l = 0;
    char num[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    char suit[] = {'C', 'D', 'H', 'S'}; // ♣ ♦ ♥ ♠
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 13; j++)
        {
            deck[l].face = suit[i];
            deck[l].symbol = num[j];
            deck[l].index = l;
            deck[l].isEmpty = false;
            l++;
        }
    }
}

void card::cardShuffler(card deck[])
{
    const int size = 52;
    int n, m;
    card temp;
    for (n = 0; n < size; n++)
    {
        m = rand() % size;
        temp = deck[n];
        deck[n] = deck[m];
        deck[m] = temp;
    }

}

void dealForDeck(card deck[], Pile& pile1, Pile& pile2, Pile& pile3, Pile& pile4, Pile& pile5, Pile& pile6, Pile& pile7, Pile& pile8) //distribui as cartas para as pilhas de jogo
{
    int count = 0;
    for(int i = 0; i < 52; i++)
    {
        if(count <= 7)
        {
            pile1.Push(deck[i]);
            count++;
        }
        else if(count <= 14)
        {
            pile2.Push(deck[i]);
            count++;
        }
        else if(count <= 21)
        {
            pile3.Push(deck[i]);
        }
        else if(count <= 28)
        {
            pile4.Push(deck[i]);
        }
        else if(count <= 34)
        {
            pile5.Push(deck[i]);
        }
        else if(count <= 41)
        {
            pile6.Push(deck[i]);
        }
        else if(count <= 47)
        {
            pile7.Push(deck[i]);
        }
        else if(count <= 52)
        {
            pile8.Push(deck[i]);
        }
    }
}

void card::freeCellsMaker(card deck[], card freeCells[])
{
    std:: cout << "free cells: \n";
    for(int i = 0; i < freeCellsSize; i++)
    {
        if(deck[i].isEmpty == false)
        {
        std::cout << "[  ]" << " ";
        } 
    }
}

void card::printDeck(card deck[])
{
    for(int i = 0; i < 52; i++)
    {
    if(i%8 == 0){std::cout << std::endl;}
    std::cout << "[" <<deck[i].getSymbol() << deck[i].getFace() << "]" << " ";
    }
    std::cout << "\n";
}

bool verifyMovement(Pile& currentPile, Pile& adressPile)
{   
    if(currentPile.Empty() || adressPile.Empty())
    {
        return false;
    }

    card selectedCard;
    currentPile.Top(selectedCard);
    card adressCard;
    adressPile.Top(adressCard);
    char selectedFace = selectedCard.getFace();
    char adressFace = adressCard.getFace();
    char selectedSymbol = selectedCard.getSymbol();
    char adressSymbol = adressCard.getSymbol();

    if((selectedFace == 'H' || selectedFace == 'D') && (adressFace == 'C' || adressFace == 'S'))
    {
        if(selectedSymbol == 'A' && adressSymbol == '2')
        {
            return true;
        }
        else if(selectedSymbol == '2' && adressSymbol == '3')
        {
            return true;
        }
        else if(selectedSymbol == '3' && adressSymbol == '4')
        {
            return true;
        }
        else if(selectedSymbol == '4' && adressSymbol == '5')
        {
            return true;
        }
        else if(selectedSymbol == '5' && adressSymbol == '6')
        {
            return true;
        }
        else if(selectedSymbol == '6' && adressSymbol == '7')
        {
            return true;
        }
        else if(selectedSymbol == '8' && adressSymbol == '9')
        {
            return true;
        }
        else if(selectedSymbol == '9' && adressSymbol == 'T')
        {
            return true;
        }
        else if(selectedSymbol == 'T' && adressSymbol == 'J')
        {
            return true;
        }
        else if(selectedSymbol == 'J' && adressSymbol == 'Q')
        {
            return true;
        }
        else if(selectedSymbol == 'Q' && adressSymbol == 'K')
        {
            return true;
        }
        
    }
    if((selectedFace == 'C' || selectedFace == 'S') && (adressFace == 'H' || adressFace == 'D'))
    {
        if(selectedSymbol == 'A' && adressSymbol == '2')
        {
            return true;
        }
        else if(selectedSymbol == '2' && adressSymbol == '3')
        {
            return true;
        }
        else if(selectedSymbol == '3' && adressSymbol == '4')
        {
            return true;
        }
        else if(selectedSymbol == '4' && adressSymbol == '5')
        {
            return true;
        }
        else if(selectedSymbol == '5' && adressSymbol == '6')
        {
            return true;
        }
        else if(selectedSymbol == '6' && adressSymbol == '7')
        {
            return true;
        }
        else if(selectedSymbol == '8' && adressSymbol == '9')
        {
            return true;
        }
        else if(selectedSymbol == '9' && adressSymbol == 'T')
        {
            return true;
        }
        else if(selectedSymbol == 'T' && adressSymbol == 'J')
        {
            return true;
        }
        else if(selectedSymbol == 'J' && adressSymbol == 'Q')
        {
            return true;
        }
        else if(selectedSymbol == 'Q' && adressSymbol == 'K')
        {
            return true;
        }
        
    }
    return false; 
}

int main() {

int play, adress;
Pile currentPile, adressPile;
Pile gamePiles[] = {pilha1, pilha2, pilha3, pilha4, pilha5, pilha6, pilha7, pilha8}; // organiza a pilha em ordem e enumera elas

do{
    Regras_Freecell();
    card::freeCellsMaker(deck, freeCells);
    card::printDeck(deck);
    std::cout << "\n\nJogada: \n\n";
    std::cin >> play;
    if (play == 99)
    {
        system("cls");
        std::cout << "Jogo terminado!";
        abort();
    }
    std::cin >> adress;

    // caso a jogada esteja fora de 1 a 8 ele invalida a jogada para que não saia das pilhas
    if (play < 1 || play > 8 || adress < 1 || adress > 8){
    std::cout << "\nEscolha de pilha inválida!\n";
    continue; // cancela a jogada e mostra que é invalida
    }

    currentPile = gamePiles[play - 1];
    adressPile = gamePiles[adress - 1];

    bool verify = verifyMovement(currentPile, adressPile);
    if (!verify){
    std::cout << "\nMovimento inválido!\n";
}
}
while (play != 99);
}



