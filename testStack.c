#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

int main(){
    Stack s;
    iniStack(s);
    s = push(s, 'c');
    s= push(s, 'h');
    s = push(s, 'o');
    s = pop(s);
    printFront(s);
    return 0;
}