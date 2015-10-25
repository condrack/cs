/***************
Name: Taylor Condrack
Course: 3110-001
Assignment: Program 3
Due Date: 10/24/15
****************/
#include <iostream>
#include <cstdlib>
using namespace std;
//tree class contains tree operations
class tree
{
    private:
//nested class for the nodes int value and ptrs to left and right nodes
        class node
        {
            public:
                int data;
            private:
                node *right;
                node *left;
            friend class tree;
        };
//privte functions are accessed by their public counter part accesses the ptrs to the tree
        void insertnode(node *&tree_node, int x);
        void printtree(node *start);
        void deletenode(node *start, int x);
        int treemax(node *start);
        int treemin(node *start);
        void removenode(node *ptr,node* match,bool left);
    public:
//public functions will call the private functions
        node *root;
//constructor initializes root
        tree(){root=NULL;};
        void startnode(int x){ insertnode(root, x);};
        void printnode(){printtree(root);};
        void deletebegin(int x){deletenode(root,x);};
        void tmin(){treemin(root);};
        void tmax(){treemax(root);};
};
//creates a node in the tree if tree is empty creates the root node
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
//traverses right if the integer is greater than the value in the node
//traverses left if the integer is greater than the value in the node
    if(tree_node->data < x)
    {
        insertnode(tree_node->right, x);
    }
    else
        insertnode(tree_node->left, x);
}
//traverses the tree and prints the values in ascending order
void tree::printtree(node *start)
{
    if(start==NULL)
        return;

    printtree(start->left);
    cout<<start->data<<" ";
    printtree(start->right);
}
//locates the largest value in subtree
int tree::treemax(node *start)
{
    if(root==NULL)
    {
        return -898765;
    }
    else
    {
        if(start->right != NULL)
        {
            return treemin(start->right);
        }
        else
        {
            return start->data;
        }
    }
}
//locates the smallest value in subtree
int tree::treemin(node *start)
{
    if(root==NULL)
    {
        return -898765;
    }
    else
    {
        if(start->left != NULL)
        {
            return treemin(start->left);
        }
        else
        {
            return start->data;
        }
    }
}
//method a of deleting a node replaces node with largest in subtree recursively deletes
void tree::deletenode(node *start, int x)
{
   if(root!=NULL)
   {
       if(x<start->data && start->left!=NULL)
       {
            start->left->data==x?
            removenode(start,start->left,true):
            deletenode(start->left,x);
       }
        else if(x>start->data && start->right!=NULL)
        {
            start->right->data==x?
            removenode(start,start->right,false):
            deletenode(start->right,x);
        }
   }

}
//removes moved node caled in delete node function
//arguments node ptr, node ptr, bool
void tree::removenode(node* ptr, node* match,bool left)
{
    if(root!=NULL)
    {
        node* del;
//matches value with data in node to remove
 //       int matchx = match->data;
//stores value returned by treemin()
        int largest;
//statement removes node for node with no children
        if(match->left==NULL && match->right==NULL)
        {
            del=match;
            left == true? ptr->left=NULL:ptr->right=NULL;
            delete del;
            cout<<"node has been removed"<<endl;
        }
//this statement runs if node has right child
        else if(match->left ==NULL && match->right!= NULL)
        {
            left==true?ptr->left=match->right:ptr->right=match->right;
            match->right=NULL;
            del=match;
            delete del;
            cout<<"node has been removed"<<endl;
        }
//statement runs if node has left child
        else if(match->left !=NULL && match->right== NULL)
        {
            left==true?ptr->left=match->left:ptr->right=match->left;
            match->left=NULL;
            del=match;
            delete del;
            cout<<"node has been removed"<<endl;
        }
//statement runs if node has two children
        else
        {
            largest = treemax(match->right);
            deletenode(match,largest);
            match->data = largest;
            cout<<"node has been removed"<<endl;
        }

    }
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
    branch.deletebegin(12);
    branch.printnode();

    return 0;
}
