#include<stdio.h>
#include<stdlib.h>

typedef struct stackNode{
    char data;
    struct stackNode* next;
}stackNode;

typedef struct Stack{
    struct stackNode* top;
}Stack;

stackNode* makeNode(char data){
    stackNode* newNode = (stackNode*)malloc(sizeof(stackNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void iniStack(Stack s){
    s.top = NULL;
}

int isEmpty(Stack q){
    return q.top == NULL;
}

Stack push(Stack s, char data){
    stackNode* p = makeNode(data);
    p->next = s.top; 
    s.top = p;
    return s;
}

Stack pop(Stack s){
    if(isEmpty(s)) return s;
    else{
        stackNode* tmp = s.top;
        s.top = (s.top)->next;
        free(tmp);
    }
    return s;
}

void printFront(Stack s){
    char x = (s.top)->data;
    printf("Top stack: %c", x);
}