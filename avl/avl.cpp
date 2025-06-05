using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>


template<typename Key>
class AVLNode{
    public:
        Key key;
        int height;
        AVLNode* leftChild;
        AVLNode* rightChild;

        AVLNode (Key& k){
            this->key=k;
            this->height=0;
            this->leftChild=NULL;
            this->rightChild=NULL;
            
        }

        AVLNode( Key& k,AVLNode* lc, AVLNode* rc){
            this->key=k;
            this->height=max(getHeight(lc), getHeight(rc))+1;
            this->leftChild=lc;
            this->rightChild=rc;
        }

};

template<typename Key>
class AVL{
    private:
        AVLNode<Key>* root;
        int nodecount;

    public:
        AVL(){
            this->root=NULL;
            this->nodecount=0;
        }

        ~AVL() {
        clearHelp(root);  // Libera todos os nós da árvore
        root = nullptr;
        nodecount = 0;
        }

        void clearHelp(AVLNode<Key>* n) {
            if (n == nullptr) return;
            
            clearHelp(n->leftChild);
            clearHelp(n->rightChild);
            delete n;
        }

        int getHeight(AVLNode<Key>* n){
            if(n==NULL){return -1;}
            return n->height;
        }

        int getBalanceFactor(AVLNode<Key>* n){
            if(n==NULL){return 0;}
            return getHeight(n->leftChild) - getHeight(n->rightChild);
        }

        AVLNode<Key>* Lrotate(AVLNode<Key>* n ){//right heavy
            AVLNode<Key>* r=n->rightChild;
            AVLNode<Key>* rl=r->leftChild;
            r->leftChild=n;
            n->rightChild=rl;
            n->height=max(getHeight(n->leftChild), getHeight(n->rightChild))+1;
            r->height=max(getHeight(r->leftChild), getHeight(r->rightChild))+1;
            return r;
        }
        AVLNode<Key>* Rrotate(AVLNode<Key>* n){
            AVLNode<Key>* l=n->leftChild;
            AVLNode<Key>* lr=l->rightChild;
            l->rightChild=n;
            n->leftChild=lr;
            n->height=max(getHeight(n->leftChild),getHeight(n->rightChild))+1;
            l->height=max(getHeight(l->leftChild), getHeight(l->rightChild))+1;
            return l;
        }

               
        void insert( Key k){
            root=insertHelp(root, k);
            nodecount++;
        }

        AVLNode<Key>* insertHelp(AVLNode<Key>* n, Key k){
            if (n== NULL){
                return  new AVLNode<Key> (k);}//cria

            if (n->key > k){
                n->leftChild=insertHelp(n->leftChild, k);}
            else{// se que eu quero inserir é igual ou maior
                n->rightChild= insertHelp(n->rightChild, k);}

            //////////
            n->height= 1+max(getHeight(n->leftChild), getHeight(n->rightChild));
            int balance=getBalanceFactor(n);
            if(balance<-1 && k>=n->rightChild->key){//right heavy
                return Lrotate(n);
            }
            if(balance > 1 && k< n->leftChild->key){//left heavy
                return Rrotate(n);
            }
            if(balance>1 && k>= n->leftChild->key){//left heavy       MEXE NA SUB DA ESQUERDA  E  DEPOSI  troca o a n
                n->leftChild=Lrotate(n->leftChild);
                return Rrotate(n);
            }
            if(balance<-1 && k<n->rightChild->key){//right heavy mexe na sub da direita e depois troca o n 
                n->rightChild=Rrotate(n->rightChild);
                return Lrotate(n);
            }
            return n;
        }

        ////pra delecoa mudar a latura no delete  min e 
        //atualizar a altura dos nos pra cima
        //depois de delete deposi da linha 13 fora do else maior
        //e no delete min
        

        void preOrder(AVLNode<Key>* n) {// raiz esquerda direita
            if(n != NULL){
                cout<< n->key<<" ";
                preOrder(n->leftChild);
                preOrder(n->rightChild);
            }
        }
        
        void inOrder(AVLNode<Key>* n) {// esquerda raiz direita
            if (n != NULL){ 
                inOrder(n->leftChild);
                cout<< n->key<<" ";
                inOrder(n->rightChild);}
        }

        void postOrder(AVLNode<Key>* n){// esquerda direita raiz
            if (n != NULL){
                postOrder(n->leftChild);
                postOrder(n->rightChild);
                cout<< n->key<<" ";

            }    
        }
        AVLNode<Key>* getRoot() {
            return root;
        }

};

int main(){
    AVL<int> tree;
    string entrada;
    int query, num;
    cin>>query;
    for(int i=0; i<query;i++){
        cin>>entrada;
        if (entrada=="insert"){
            cin>>num;
            tree.insert(num);
        }
        else if(entrada=="pre"){
            tree.preOrder(tree.getRoot());
            cout<<endl;
        }
        else if (entrada=="in"){
            tree.inOrder(tree.getRoot());
            cout<<endl;
        }
        else{
            tree.postOrder(tree.getRoot());
            cout<<endl;
        }
    }
}

