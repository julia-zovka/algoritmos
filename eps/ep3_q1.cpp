#include <iostream>
using namespace std;


class AVLNode{
    public:
    AVLNode* rightChild;
    AVLNode* leftChild;
    int height;
    int key;

    AVLNode(int k){
        this->key=k;
        this->leftChild=NULL;
        this->rightChild=NULL;
        this->height=0;
    }

    AVLNode(int k, AVLNode* lc, AVLNode* rc){
        this->key=k;
        this->leftChild=lc;
        this->rightChild=rc;
        this->height=max(lc->height,rc->height)+1;
    }
};

class AVL{
    private:
        AVLNode* root;
        int nodecount;
    public:
        AVL(){
            this->root=NULL;
            this->nodecount=0;
        }
        int getBalance(AVLNode* n){
                if(n==NULL){return 0;}
                return  getHeight(n->leftChild)- getHeight(n->rightChild);            }

        int getHeight(AVLNode* n){
            if(n==NULL){return -1;}
            return n->height;
        }


        void insert(int k){
            bool rotacao= false;
            root=insertHelp(root, k, &rotacao);
            nodecount++;
            if(rotacao==false){
                cout<<"no rotation!"<<endl;
            }
        }

        AVLNode* insertHelp( AVLNode* n, int k, bool *rotacao ){
            if(n==NULL){
                return new AVLNode(k);
            }
            if(n->key>k){// o no e maior do que eu quero inserir
                n->leftChild=insertHelp(n->leftChild, k, rotacao);
            }
            else{
                n->rightChild=insertHelp(n->rightChild, k, rotacao);
            }
            ////////////////
            n->height=max(getHeight(n->leftChild), getHeight(n->rightChild))+1;
            int balance=getBalance(n);
            if(balance>1 && k < n->leftChild->key){
                *rotacao=true;
                cout<<n->key<< " is unbalanced, R-rotation!"<<endl;
                return rightRotate(n);

            }
            if(balance>1 && k>=n->leftChild->key){
                *rotacao=true;
                cout<<n->key<< " is unbalanced, LR-rotation!"<<endl;
                n->leftChild=leftRotate(n->leftChild);
                return rightRotate(n);
            }
            if(balance< -1 && k>=n->rightChild->key ){
                *rotacao=true;
                cout<<n->key<< " is unbalanced, L-rotation!"<<endl;
                return leftRotate(n);
            }
            if(balance< -1 && k< n->rightChild->key ){
                *rotacao=true;
                cout<<n->key<< " is unbalanced, RL-rotation!"<<endl;
                n->rightChild=rightRotate(n->rightChild);
                return leftRotate(n);
            }
            return n;

        }

            AVLNode* rightRotate(AVLNode* n){
                AVLNode* l=n->leftChild;
                AVLNode* lr=l->rightChild;
                l->rightChild=n;
                n->leftChild=lr;
                n->height=max(getHeight(n->leftChild), getHeight(n->rightChild))+1;
                l->height=max(getHeight(l->leftChild), getHeight(l->rightChild))+1;
                return l;
            }

            AVLNode* leftRotate(AVLNode* n){
                AVLNode* r=n->rightChild;
                AVLNode* rl=r->leftChild;
                r->leftChild=n;
                n->rightChild=rl;
                n->height=max(getHeight(n->leftChild), getHeight(n->rightChild))+1;
                r->height=max(getHeight(r->leftChild), getHeight(r->rightChild))+1;
                return r;
            }

            void preOrder(AVLNode* n){
                if(n!=NULL){
                cout<<" "<<n->key;
                preOrder(n->leftChild);
                preOrder(n->rightChild);
            }}

            void inOrder(AVLNode* n){
                if(n!=NULL) {
                inOrder(n->leftChild);
                cout<<" "<<n->key;
                inOrder(n->rightChild);
                }
            }

            void posOrder(AVLNode* n){
                if(n!=NULL){
                posOrder(n->leftChild);
                posOrder(n->rightChild);
                cout<<" "<<n->key;
            }}

            AVLNode* getRoot(){
                if(root!=NULL)return root;
            }
};


int main(){
    int q_num, num;
    AVL prova;
    cin>>q_num;
    for( int i=0;i<q_num;i++){
        cin>>num;
        cout<<"insert "<< num<<": ";
        prova.insert(num);
    }
    cout<<"preorder:";
    prova.preOrder(prova.getRoot());
    cout<<endl;

    cout<<"inorder:";
    prova.inOrder(prova.getRoot());
    cout<<endl;

    cout<<"postorder:";
    prova.posOrder(prova.getRoot());
    cout<<endl;

}