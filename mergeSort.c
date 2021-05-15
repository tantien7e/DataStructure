#include<stdio.h>
#include<stdlib.h>

void merge(int* L, int* R, int* Arr, int l, int r){
    int i,j,k;
    i=j=k=0;
    while(i < l && j< r){
        if(L[i] <= R[j]){
            Arr[k] = L[i];
            k++;
            i++;
        }
        else{
            Arr[k] = R[j];
            k++;
            j++;
        }
    }
    while (i < l){
        Arr[k] = L[i];
        k++;
        i++;
    }
    while(j <r){
        Arr[k] = R[j];
        k++;
        j++;
    }
}

void mergeSort(int Arr[], int l){
    if(l < 2) return;
    else{
        int mid = l/2;
        int Left[mid];
        int Right[l-mid];
        for(int i = 0; i<mid; i++){
            Left[i] = Arr[i];
        }
        for(int j = mid; j<l; j++){
            Right[j-mid]= Arr[j];
        }
        mergeSort(Left, mid);
        mergeSort(Right, l-mid);
        merge(Left, Right, Arr, mid, l-mid);
        
    }
}


int main(){
    int B[7] = {1,6,8,3,4,10,12};
    mergeSort(B, 7);
    for(int i = 0; i<7; i++){
        printf("%d ", B[i]);
    }
    return 0;
}
