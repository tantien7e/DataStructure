#include<stdio.h>
#include<stdlib.h>

void sort(int a[], int n){
    for(int k = 0; k< n-2;k++){
    for(int i = 0; i<n-2; i++){
        if(a[i]>a[i+1]){
            int tmp = a[i];
            a[i] = a[i+1];
            a[i+1] = tmp;
        }
    }
    }
}

#include<stdio.h>
#include<stdlib.h>