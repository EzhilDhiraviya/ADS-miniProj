#include<iostream>
using namespace std;

template <typename Comparable>
class AvlTree{
    private:
        struct AvlNode{
        Comparable element;
        AvlNode *left;
        AvlNode *right;
        int height;
        
        AvlNode(const Comparable &x, AvlNode* lt=nullptr,AvlNode *rt=nullptr, int h=0):element(x),left(lt),right(rt),height(h){}

        };
        AvlNode *root;
        static const int ALLOWED_IMBALANCE=1;

        int height(AvlNode *t)
        {
            return (t==nullptr?-1:t->height);
        }

        void insert(const Comparable &x, AvlNode *&t)
        {
            if(t==nullptr)
                t=new AvlNode(x);
            else if(x<t->element)
                insert(x,t->left);
            else if(x>t->element)
                insert(x,t->right);
            else;
            balance(t);
        }

        bool contains(const Comparable &x, AvlNode *&t)
        {
            if(t==nullptr)
                return false;
            else if(x<t->element)
                insert(x,t->left);
            else if(x>t->element)
                insert(x,t->right);
            else
                return true;
        }

        void balance(AvlNode *&t)
        {
            if(height(t->left)-height(t->right)>ALLOWED_IMBALANCE)
            {
                if(height(t->left->left)>=height(t->left->right))
                    rotateWithLeftChild(t);
                else
                    doubleWithLeftChild(t);
            }
            else
            {
                if(height(t->right)-height(t->left)>ALLOWED_IMBALANCE)
                {
                    if(height(t->right->right)>=height(t->right->left))
                        rotateWithRightChild(t);
                    else
                        doubleWithRightChild(t);
                }
            }
            t->height=max(height(t->left),height(t->right))+1;
        }

        void doubleWithLeftChild(AvlNode *&k3)
        {
            rotateWithRightChild(k3->left);
            rotateWithLeftChild(k3);
        }

        void doubleWithRightChild(AvlNode *&k3)
        {
            rotateWithLeftChild(k3->right);
            rotateWithRightChild(k3);
        }

        void rotateWithLeftChild(AvlNode *&k2)
        {
            AvlNode *k1=k2->left;
            k2->left=k1->right;
            k1->right=k2;
            k2->height=max(height(k2->left),height(k2->right))+1;
            k1->height=max(height(k1->left),height(k1->right))+1;
            k2=k1;
        }

        void rotateWithRightChild(AvlNode *&k1)
        {
            AvlNode *k2=k1->right;
            k1->right=k2->left;
            k2->left=k1;
            k2->height=max(height(k2->left),height(k2->right))+1;
            k1->height=max(height(k1->left),height(k1->right))+1;
            k1=k2;
        }

        void remove(const Comparable &x, AvlNode *&t)
        {
            if(t==nullptr)
                return;
            else if(x<t->element)
                remove(x,t->left);
            else if(x>t->element)
                remove(x,t->right);
            else if(t->left!=nullptr && t->right!=nullptr)
            {
                t->element=findmin(t->right)->element;
                remove(t->element,t->right);
            }
            else
            {
                AvlNode *oldnode=t;
                t=(t->left!=nullptr)?t->left:t->right;
                delete oldnode;
            }
           if(t!=nullptr)
            balance(t);
        }

        AvlNode* findmin(AvlNode *t)const{
            if(t!=nullptr)
            {
                while(t->left!=nullptr)
                    t=t->left;
                return t;
            }
        }

        void printTreeStructure(AvlNode* node, int level)const {
            if (node == nullptr)
                return;

            printTreeStructure(node->right, level + 1);
            for (int i = 0; i < level; ++i)
                cout << "    ";
            cout << node->element << endl;
            printTreeStructure(node->left, level + 1);
        }

    public:

        AvlTree():root(nullptr){}

        void insert(const Comparable &x)
        {
            insert(x,root);
        }

        bool contains(const Comparable &x)
        {
            return contains(x,root);
        }
        
        void printTreeStructure()
        {
            printTreeStructure(root,0);
        }

        void remove(const Comparable &x)
        {
            remove(x,root);
        }

};
