#include <iostream>
using namespace std;

template <typename Comparable>
class SplayTree
{
    private:
    struct BinaryNode
    {
        Comparable element1;
        Comparable element2;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode(const Comparable &theelement1 = Comparable{}, const Comparable &theelement2 = Comparable{}, BinaryNode *lt = nullptr, BinaryNode *rt = nullptr)
            : element1{theelement1}, element2{theelement2}, left{lt}, right{rt} {}
    };

    BinaryNode *root;
    BinaryNode *nullNode;
    // Function to get the top element1 of the Splay Tree
    


    

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

        nullNode->element1 = x; 

        for (;;)
            if (x < t->element1)
            {
                if (x < t->left->element1)
                    rotateWithLeftChild(t);
                if (t->left == nullNode)
                    break;

                rightTreeMin->left = t;
                rightTreeMin = t;
                t = t->left;
            }
            else if (t->element1 < x)
            {
                if (t->right->element1 < x)
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
   Comparable getTop() {
    if (isEmpty())
        return Comparable{}; // Return default value if tree is empty
    return root->element1;
}

bool isEmpty() const
    {
        return root == nullNode;
    }


    bool contains(const Comparable &x)
    {
        if (isEmpty())
            return false;
        splay(x, root);
        return root->element1 == x;
    }

    
    void insert(const Comparable &x, const Comparable &y = Comparable{})
    {
        static BinaryNode *newNode = nullptr;

        if (newNode == nullptr)
            newNode = new BinaryNode;
        newNode->element1 = x;
        newNode->element2 = y;

        if (root == nullNode)
        {
            newNode->left = newNode->right = nullNode;
            root = newNode;
        }
        else
        {
            splay(x, root);
            if (x < root->element1)
            {
                newNode->left = root->left;
                newNode->right = root;
                root->left = nullNode;
                root = newNode;
            }
            else if (root->element1 < x)
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

        void printTree(){
            printTree(root,0);
        }
        void printTree(BinaryNode *root,int level){
            if(root!=nullNode){
                printTree(root->right,level+1);
                for(int i=0;i<level;i++)
                cout<<"      ";
                cout<<root->element1<<endl;
                printTree(root->left,level+1);
            }
        }
    void displayRoot()
    {
        cout<<root->element1<<endl<<root->element2<<endl;
    }

    void readQnA(BinaryNode *t){
    ifstream file("texts/questions.txt");
    string qn,ans;
    while(getline(file,qn)){
        getline(file,ans);
        t.insert(qn,ans);
    }
}

};
