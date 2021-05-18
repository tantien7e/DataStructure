#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char a[] = "bak";
    char b[] = "taw";
    int i = strcmp(a, b);
    printf("%d\n",i);
    return 0;
}