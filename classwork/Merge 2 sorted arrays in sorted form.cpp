#include <bits/stdc++.h>
using namespace std;

void mergeSortedArray(vector <int>A, vector<int> B){
    vector<int> result;
    int i=0, j=0;
    
    
    while(i<A.size() && j<B.size()){
        if(A[i]<B[j]){
            result.push_back(A[i]);
            i++;
        }
        else if(B[j]<A[i]){
            result.push_back(B[j]);
            j++;
        }
        else{
            result.push_back(A[i]);
            result.push_back(B[j]);
            i++;
            j++;
            
        }
    }
    
    
    while(i<A.size()){
        result.push_back(A[i]);
        i++;

    }
    while(j<B.size()){
        result.push_back(B[j]);
        j++;
    }
    
    
    for(int k=0;k<result.size();k++){
        cout<<result[k]<<" ";
    }
}

int main(){
    
    vector<int> A{1,2,5,6};
    vector<int> B{1,3,4,7};
    
     mergeSortedArray(A,B);
    
    
    
    
    
    return 0;
    }
