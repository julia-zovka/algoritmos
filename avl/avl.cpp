using namespace std;
#include <iostream>
//#include <vector>
//#include <algorithm>


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

        int find(Key k){
            return findHelp(root,k);
        }

        int findHelp(AVLNode <Key>* n, Key k){
            if (n== NULL) { return -1 ;}

            if (n->key > k){//vai pro filho da esquerda
                return findHelp(n->leftChild, k);}

            else if (n->key == k){//achou
                return n->key;
            }

            else{// se for maior vai por filho da direita
                return findHelp(n->rightChild, k);}
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

        AVLNode<Key>* minValueNode(AVLNode<Key>* node) {
            AVLNode<Key>* current = node;
            while (current->leftChild != nullptr)
                current = current->leftChild;
            return current;
        }

            // It returns root of the modified subtree.
        AVLNode<Key>* deleteNode(AVLNode<Key>* n, int key) {
            if (n == nullptr){
                return n;}
            if (key < n->key){
                n->leftChild = deleteNode(n->leftChild, key);}

            else if (key > n->key){
                n->rightChild = deleteNode(n->rightChild, key);}

            else {
                // node with only one child or no child
                if ((n->left == nullptr) || 
                    (n->right == nullptr)) {
                    AVLNode<Key>* temp = n->leftChild ? 
                                    n->leftChild : n->rightChild;
                    // No child case
                    if (temp == nullptr) {
                        temp = n;
                        n = nullptr;
                    } else // One child case
                        *n = *temp; // Copy the contents of 
                                        // the non-empty child
                    free(temp);
                } 
                else {//tem os dois filhos
                    // inorder successor (smallest in he right subtree)
                    AVLNode<Key>* temp = minValueNode(n->rightChild);
                    n->key = temp->key;
                    n->rightChild = deleteNode(n->rightChild, temp->key);
                }
            }
            // If the tree had only one node then return
            if (n == nullptr)
                return n;

            // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
            n->height = 1 + max(height(n->leftChild),height(n->rightChild));

            // STEP 3: GET THE BALANCE FACTOR OF THIS 
            int balance = getBalance(n);

            if (balance > 1 && getBalance(n->leftChild) >= 0)
                return rightRotate(n);

            if (balance > 1 && getBalance(n->leftChild) < 0) {
                n->leftChild = leftRotate(n->leftChild);
                return rightRotate(n);
            }

            if (balance < -1 && getBalance(n->rightChild) <= 0)
                return leftRotate(n);

            if (balance < -1 && getBalance(n->rightChild) > 0) {
                n->rightChild = rightRotate(n->rightChild);
                return leftRotate(n);
            }

            return n;
            }
        
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

