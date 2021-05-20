#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int swap(int a, int b){
    int tmp = a;
    a=b;
    b=tmp;
}

int main(){
    char a[] = "bka";
    char b[] = "tka";
    int i = strcmp(a, b);
    printf("%d\n", i);
    return 0;
}