#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int swap(int a, int b){
    int tmp = a;
    a=b;
    b=tmp;
}

int main(){
    int Arr[] = {1, 2};
    swap(Arr[0], Arr[1]);
    printf("%d", Arr[0]);
    return 0;
}