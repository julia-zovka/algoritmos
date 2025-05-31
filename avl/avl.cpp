using namespace std;
#include <iostream>
#include <string>
#include<algorithm>
#include <vector>

template<typename Key,typename T>
class BSTNode{
    public:
        Key key;
        T element;
        BSTNode* leftChild;
        BSTNode* rightChild;

        BSTNode (Key k , T e){
            this->key=k;
            this->element=e;
            this->leftChild=NULL;
            this->rightChild=NULL;
            
        }

        BSTNode( Key& k,T& e ,BSTNode* lc, BSTNode* rc){
            this->key=k;
            this->element=e;
            this->leftChild=lc;
            this->rightChild=rc;
        }

};

template<typename Key,  typename T>
class BST {
    private:
        BSTNode< Key, T>* root;
        int nodecount;

    public:
        BST(){
            this->root=NULL;
            this->nodecount=0;
        }

        ~BST() {
        clearHelp(root);  // Libera todos os nós da árvore
        root = nullptr;
        nodecount = 0;
        }

        int altura(){
            return alturaHelp(root);
        }
        int alturaHelp(BSTNode<Key, T>* n){
            if (n==NULL){
                return -1;}
            else{
                return 1+ max(alturaHelp(n->leftChild), alturaHelp(n->rightChild));}
        }    
                    
        void clearHelp(BSTNode<Key, T>* n) {
        if (n == nullptr) return;
        
        clearHelp(n->leftChild);
        clearHelp(n->rightChild);
        delete n;
        }

        T find(Key k){
            return findHelp(root,k);
        }

        T findHelp(BSTNode <Key, T>* n, Key k){
            if (n== NULL) { return NULL ;}

            if (n->key > k){//vai pro filho da esquerda
                return findHelp(n->leftChild, k);}

            else if (n->key == k){//achou
                return n->element;}

            else{// se for maior vai por filho da direita
                return findHelp(n->rightChild, k);}
        }
        
        void insert( Key k, T e){
            root=insertHelp(root, k, e);
            nodecount++;
        }

        BSTNode<Key, T>* insertHelp(BSTNode<Key , T>* n, Key k, T e){
            if (n== NULL){
                return  new BSTNode<Key, T> (k, e);}//cria

            if (n->key > k){
                n->leftChild=insertHelp(n->leftChild, k, e);}
            else{// se que eu quero inserir é igual ou maior
                n->rightChild= insertHelp(n->rightChild, k, e);}
            return n;
        }

        T remove(Key k){
            T temp =findHelp(root, k);

            if (temp != NULL){
                root=removeHelp(root, k);
                nodecount--;
            }
            return temp;
        } 

          BSTNode<Key, T>* removeHelp(BSTNode<Key, T>* n, Key k) {
        if (n == NULL) {
            return NULL;
        }

        if (n->key > k) {
            n->leftChild = removeHelp(n->leftChild, k);
        }
        else if (n->key < k) {
            n->rightChild = removeHelp(n->rightChild, k);
        }
        else { // Node found
            if (n->leftChild == NULL) {
                BSTNode<Key, T>* temp = n->rightChild;
                delete n;
                return temp;
            }
            else if (n->rightChild == NULL) {
                BSTNode<Key, T>* temp = n->leftChild;
                delete n;
                return temp;
            }
            else { // Two children
                BSTNode<Key, T>* temp = getMin(n->rightChild);
                n->element = temp->element;
                n->key = temp->key;
                n->rightChild = deleteMin(n->rightChild);
            }
        }
        return n;
    }

            BSTNode<Key, T>* getMin(BSTNode<Key, T>* n){
                if (n->leftChild == NULL){
                    return n;}
                return getMin(n->leftChild);
            }

            BSTNode<Key, T>* deleteMin(BSTNode<Key, T>* n){
                if (n->leftChild == NULL){
                    BSTNode<Key, T>* temp= n->rightChild;
                    delete n;
                    return temp;}
                n->leftChild = deleteMin(n->leftChild);
                return n;
            }    

            // espaço de imprimir antess dos elementos ai náp tem espa;o depois do ultimo

            void preOrder(BSTNode<Key, T>* n) {// raiz esquerda direita
                if(n != NULL){
                    cout<< n->key;
                    preOrder(n->leftChild);
                    preOrder(n->rightChild);
                }
            }
            
            void inOrder(BSTNode<Key, T>* n) {// esquerda raiz direita
                if (n != NULL){ 
                    inOrder(n->leftChild);
                    cout<< n->key;
                    inOrder(n->rightChild);}
            }

            void postOrder(BSTNode<Key, T>* n){// esquerda direita raiz
                if (n != NULL){
                    postOrder(n->leftChild);
                    postOrder(n->rightChild);
                    cout<< n->key;

                }    
            }
            
            BSTNode<Key, T>* getRoot() {
                return root;
            }

};


