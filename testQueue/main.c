#include<stdio.h>
#include<stdlib.h>

void sort(int a[], int n){
    for(int k = 0; k< n;k++){
    for(int i = 0; i<n; i++){
        if(a[i]>a[i+1]){
            int tmp = a[i];
            a[i] = a[i+1];
            a[i+1] = tmp;
        }
    }
    }
}

int main(){
    int a[6] = {3, 19, 17, 18, 5, 76};
    sort(a, 6);
    for(int i = 0; i< 6; i++){
        printf("%d ", a[i]);
    }
    return 0;
}
