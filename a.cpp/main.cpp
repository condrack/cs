/***************
Name: Taylor Condrack
Course: 3110-001
Assignment: Program 3
Due Date: 10/24/15
****************/
#include <iostream>
#include <cstdlib>
using namespace std;

class tree
{
    private:
        class node
        {
            public:
                int data;
            private:
                node *right;
                node *left;
            friend class tree;
        };
        void insertnode(node *&tree_node, int x);
        void printtree(node *start);
    public:
        node *root;
        tree(){root=NULL;};
        void startnode(int x){ insertnode(root, x);};
        void printnode(){printtree(root);};
};
void tree::insertnode(node *&tree_node,int x)
{
    if(tree_node == NULL)
    {
        tree_node = new node;
        tree_node->left = NULL;
        tree_node->right = NULL;
        tree_node->data = x;
    }
    if(tree_node->data ==x)
    {
        return;
    }
    if(tree_node->data < x)
    {
        insertnode(tree_node->right, x);
    }
    else
        insertnode(tree_node->left, x);
}

void tree::printtree(node *start)
{
    if(start==NULL)
        return;

    printtree(start->left);
    cout<<start->data<<" ";
    printtree(start->right);
}

int main()
{
    tree branch;
    branch.startnode(20);
    branch.startnode(12);
    branch.startnode(30);
    branch.startnode(10);
    branch.startnode(16);
    branch.startnode(25);
    branch.startnode(32);
    branch.startnode(5);
    branch.startnode(11);
    branch.startnode(13);
    branch.startnode(17);
    branch.startnode(27);
    branch.startnode(22);
    branch.startnode(31);
    branch.startnode(34);

    branch.printnode();



    return 0;
}
