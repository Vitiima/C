#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class BinarySearchTree
{
private:
    struct TreeNode
    {
        std::string Entry;
        TreeNode *LeftNode = NULL;
        TreeNode *RightNode = NULL;
    };

    typedef TreeNode *TreePointer;
    TreePointer root;
    void Insert(string s1,string s2, string s3, TreePointer &Node);
    void PreOrdem(TreePointer &Node);
    void clear(TreePointer &x);
    void DeleteX(TreePointer &Node);
    int totalNodes;
    int leafNodes;
    void CountNodes(TreePointer &Node, int &nodesWithChildren, int &leafNodes);

public:
    BinarySearchTree();
    ~BinarySearchTree();
    void PrintNodes(TreePointer &Print);
    void PreOrdem();
    void ReadFile();
    void CountNodes();
};

#endif
