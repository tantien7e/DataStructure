#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char* a = "bka";
    char* b = "tka";
    int v = strcmp(a,b);
    printf("%d\n", v);
    return 0;
}