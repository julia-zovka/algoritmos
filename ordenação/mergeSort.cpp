using namespace std;
#include <iostream>;
#include <vector>;



vector<int> mergeSort(int tamanho, vector<int> prime ){
    int meio=tamanho/2;
}

vector<int> merge(vector<int>& A, vector<int>& B){
    vector<int> novo;
    int iA=0;
    int iB=0;
    while(iA< A.size() && iB <B.size()){// se for igual [e porque] j[a comparou o ultimo , começa do 0 e termona no size-1    }
        if(A[iA]<=B[iB]){
            novo.push_back(A[iA]);
            iA++;
        }
        else{
            novo.push_back(B[iB]);
            iB++;
        }
    }
    
    // já acabopu açgum dos vetores
    while(iA<A.size()){
        novo.push_back(A[iA]);
            iA++;
    }
    while(iB<B.size()){
        novo.push_back(B[iB]);
        iB++;
    }
    return novo;
};



int main(){

    int casos, tamanho,num;
    cin>>casos;
    for(int i=0; i < casos; i++){
        cin>>tamanho;
        if(tamanho>1){
            vector<int> prime;
            for(int j=0; j < tamanho;j++){
                cin>>num;
                prime.push_back(num);
            }
            vector<int> r1=mergeSort(tamanho, prime);
   
        }
        else{
            cin>>num;
            cout<<num<<endl;
            return 0;
        }

    }


};

