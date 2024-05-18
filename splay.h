#include <iostream>
using namespace std;

template <typename Comparable>
class SplayTree
{
    private:
    struct BinaryNode
    {
        Comparable element;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode(const Comparable &theElement = Comparable{}, BinaryNode *lt = nullptr, BinaryNode *rt = nullptr)
            : element{theElement}, left{lt}, right{rt} {}
    };

    BinaryNode *root;
    BinaryNode *nullNode;

    bool contains(const Comparable &x)
    {
        if (isEmpty())
            return false;
        splay(x, root);
        return root->element == x;
    }

    bool isEmpty() const
    {
        return root == nullNode;
    }

    void rotateWithLeftChild(BinaryNode *&k2)
    {
        BinaryNode *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2 = k1;
    }

    void rotateWithRightChild(BinaryNode *&k1)
    {
        BinaryNode *k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;
        k1 = k2;
    }
    void splay(const Comparable &x, BinaryNode *&t)
    {
        BinaryNode *leftTreeMax, *rightTreeMin;
        static BinaryNode header;

        header.left = header.right = nullNode;
        leftTreeMax = rightTreeMin = &header;

        nullNode->element = x; 

        for (;;)
            if (x < t->element)
            {
                if (x < t->left->element)
                    rotateWithLeftChild(t);
                if (t->left == nullNode)
                    break;

                rightTreeMin->left = t;
                rightTreeMin = t;
                t = t->left;
            }
            else if (t->element < x)
            {
                if (t->right->element < x)
                    rotateWithRightChild(t);
                if (t->right == nullNode)
                    break;

                leftTreeMax->right = t;
                leftTreeMax = t;
                t = t->right;
            }
            else
                break;

        leftTreeMax->right = t->left;
        rightTreeMin->left = t->right;
        t->left = header.right;
        t->right = header.left;
    }

    void makeEmpty(BinaryNode *&t)
    {
        if (t != nullNode)
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        t = nullNode;
    }

public:
    SplayTree()
    {
        nullNode = new BinaryNode;
        nullNode->left = nullNode->right = nullNode;
        root = nullNode;
    }

    ~SplayTree()
    {
        makeEmpty(root);
        delete nullNode;
    }

    void insert(const Comparable &x)
    {
        static BinaryNode *newNode = nullptr;

        if (newNode == nullptr)
            newNode = new BinaryNode;
        newNode->element = x;

        if (root == nullNode)
        {
            newNode->left = newNode->right = nullNode;
            root = newNode;
        }
        else
        {
            splay(x, root);
            if (x < root->element)
            {
                newNode->left = root->left;
                newNode->right = root;
                root->left = nullNode;
                root = newNode;
            }
            else if (root->element < x)
            {
                newNode->right = root->right;
                newNode->left = root;
                root->right = nullNode;
                root = newNode;
            }
            else
                return;
        }
        newNode = nullptr; 
    }

    void remove(const Comparable &x)
    {
        if (!contains(x))
            return; 

        BinaryNode *newTree;

        if (root->left == nullNode)
            newTree = root->right;
        else
        {
            newTree = root->left;
            splay(x, newTree);
            newTree->right = root->right;
        }
        delete root;
        root = newTree;
    }

        void display(){
            display(root);
        }
        void printTree(){
            printTree(root,0);
        }
        void printTree(BinaryNode *root,int level){
            if(root!=nullNode){
                printTree(root->right,level+1);
                for(int i=0;i<level;i++)
                cout<<"      ";
                cout<<root->element<<endl;
                printTree(root->left,level+1);
            }
        }

};
