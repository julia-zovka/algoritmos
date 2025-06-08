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
        int size;

        AVLNode (Key& k){
            this->key=k;
            this->height=0;
            this->leftChild=NULL;
            this->rightChild=NULL;
            this->size=1;
            
        }

        AVLNode( Key& k,AVLNode* lc, AVLNode* rc){
            this->key=k;
            this->height=max(getHeight(lc), getHeight(rc))+1;
            this->leftChild=lc;
            this->rightChild=rc;
            this->size=getSize(lc)+getSize(rc)+1;

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

        int find(Key k){
            return findHelp(root,k,0);
        }

        int findHelp(AVLNode <Key>* n, Key k,int position=0){
            if (n== NULL) { return -1 ;}

            if (n->key > k){//vai pro filho da esquerda
                return findHelp(n->leftChild, k,position);}

            else if (n->key == k){//achou
                return position+getSize(n->leftChild)+1;}

            else{// se for maior vai por filho da direita
                return findHelp(n->rightChild, k, position+1+getSize(n->leftChild));}
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
        int getSize(AVLNode<Key>* n) {
        if(n == NULL){return 0;} 
        return n->size;}


        void updateNode(AVLNode<Key>* n){
            if(n==NULL){return;}
            n->height=max(getHeight(n->leftChild), getHeight(n->rightChild))+1;
            n->size=getSize(n->leftChild)+getSize(n->rightChild)+1;
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
            updateNode(n);
            updateNode(r);
            return r;
        }
        AVLNode<Key>* Rrotate(AVLNode<Key>* n){
            AVLNode<Key>* l=n->leftChild;
            AVLNode<Key>* lr=l->rightChild;
            l->rightChild=n;
            n->leftChild=lr;
            updateNode(n);
            updateNode(l);
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
            updateNode(n);
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
    int num_query, query, num;
    cin>>num_query;
    vector<int> posicao;
    for(int i=0; i<num_query;i++){
        cin>>query;
        if(query==1){
            cin>>num;
            tree.insert(num);
        }
        else{
            cin>>num;
            int y=tree.find(num);
            if(y==-1){
                cout<<"Data tidak ada"<<endl;
            }
            else{//achou a key agora precisa do indiceee
                cout<<y<<endl;
            }
        }
    }
}
