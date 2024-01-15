#include "BinarySearchTree.h"
#include <iostream>
#include <fstream>
#include <string>

BinarySearchTree::BinarySearchTree()
{
    root = NULL;
}

BinarySearchTree::~BinarySearchTree()
{
    clear(root);
}

void BinarySearchTree::ReadFile()
{
    ifstream File("exemplo1.tree");
    string s1, s2, s3;
    while (File >> s1 >> s2 >> s3) // Faz a inserção de Cada Linha do Arquivo de Exemplo
    {
        Insert(s1, s2, s3, root);
    }
    DeleteX(root); //Função que Deleta os nós que Devem ser Nulos no Arquivo de Exemplo
    PrintNodes(root); // Mostra na Tela como Requisitado
    CountNodes(); // Conta e Mostra os nós totais e Folhas no fim da Execução
}



void BinarySearchTree::Insert(string s1, string s2, string s3, TreePointer &Node)
{
    if (s1 == "X" && s2 == "X" && s3 == "X"){

    return;

    }
    if (Node == NULL)
    {
        Node = new TreeNode;
        Node->Entry = s1;
        Node->LeftNode = new TreeNode;
        Node->RightNode = new TreeNode;
        Node->LeftNode->Entry = s2;
        Node->RightNode->Entry = s3;
        return;
    }
    else if (s1 == Node->Entry & s1 != "X")
    {
        Node->LeftNode = new TreeNode;
        Node->RightNode = new TreeNode;
        Node->LeftNode->Entry = s2;
        Node->RightNode->Entry = s3;
    }else if(Node->Entry != "X")
    {
        Insert(s1, s2, s3, Node->LeftNode);
        Insert(s1, s2, s3, Node->RightNode);
    }
}

void BinarySearchTree::clear(TreePointer &x)
{
    if (x != NULL)
    {
        clear(x->LeftNode);
        clear(x->RightNode);
        delete x;
        x = NULL;
    }
}


void BinarySearchTree::PrintNodes(TreePointer &Print)
{

    if (Print != NULL)
    {
        int children = 0;
        if (Print->LeftNode !=NULL) children++;
        if (Print->RightNode !=NULL) children++;
     if (children == 0){
        cout<<Print->Entry << " 0 F"<< endl;
     }else if (children == 2){
      cout<<Print->Entry << " 2 ED"<< endl;
    }else if (Print->LeftNode !=NULL){
        cout<<Print->Entry<< " 1 E"<<endl;
    }else cout<<Print->Entry<< " 1 D"<<endl;
    PrintNodes(Print->LeftNode);
    PrintNodes(Print->RightNode);

    }
}

void BinarySearchTree::DeleteX(TreePointer &Node)
{
    if (Node != NULL)
    {
        if (Node->Entry == "X")
        {
            clear(Node);
            Node = NULL;
        }
        else
        {
            DeleteX(Node->LeftNode);
            DeleteX(Node->RightNode);
        }
    }
} // Deleta todos os Nós que tem o X como Entrada e atribui eles como NULL

void BinarySearchTree::CountNodes(TreePointer &Node, int &SubNodes, int &leafNodes)
{
    if (Node != NULL)
    {
        if (Node->LeftNode != NULL || Node->RightNode != NULL)
        {
            SubNodes++;
        }

        if (Node->LeftNode == NULL && Node->RightNode == NULL)
        {
            leafNodes++;
        }

        CountNodes(Node->LeftNode, SubNodes, leafNodes);
        CountNodes(Node->RightNode, SubNodes, leafNodes);
    }
} // Conta a Quantidade de nós que estão na Arvore

void BinarySearchTree::CountNodes()
{
    int SubNodes = 0;
    int leafNodes = 0;

    CountNodes(root, SubNodes, leafNodes);

    cout << SubNodes+leafNodes << " " << leafNodes << endl;
} // função que é chamada para fazer impressão no *ReadFile*
