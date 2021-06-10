#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char c1[] = "tka";
    char c2[] = "bka";
    int k = strcmp(c1, c2);
    printf("%d", k);
    return 0;
}