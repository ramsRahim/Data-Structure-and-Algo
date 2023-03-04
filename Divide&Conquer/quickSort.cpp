#include<iostream>

using namespace std;

void partition(int S[], int low, int high, int pivotpoint ){
    int i,j;
    int pivotitem;

    pivotitem = S[low];
    j= low;

    for (i=low+1;i<=high;i++){
        if(S[i]<pivotitem){
            j++;
            int temp = S[i];
            S[i] = S[j];
            S[j] = temp;
        }
    }
    pivotpoint = j;
    int temp = S[low];
    S[low] = S[pivotpoint];
    S[pivotpoint] = temp;

}

int main(){

    return 0;
}