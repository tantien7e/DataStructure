#include<stdio.h>
#include<stdlib.h>

void insertSort(int a[], int n){
    for(int k = 0; k<n; k++){
        int value = a[k];
        while(k>0 && a[k-1] > value){
            a[k] = a[k-1];
            k = k-1;
        }
        a[k] = value;
    }
}


int main(){
    int a[6] = {3, 19, 17, 18, 5, 76};
    insertSort(a, 6);
    for(int i = 0; i< 6; i++){
        printf("%d ", a[i]);
    }
    return 0;
}