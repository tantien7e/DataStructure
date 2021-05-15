#include<stdio.h>
#include<stdlib.h>

void swap(int a , int b){
    int tmp = a;
    a = b;
    b = tmp;
}

int main(){
    int a = 6;
    int b = 9;
    printf("%d - %d\n", a, a/b);
    swap(a, b);
    printf("%d - %d\n", a, b);
    return 0;
}