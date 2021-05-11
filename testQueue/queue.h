#include<stdlib.h>
#include<stdio.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    struct Node* front;
    struct Node* rear;
} Queue;

Queue iniQueue(Queue q){
    q.front = NULL;
    q.rear = NULL;
    return q;
}

int isEmpty(Queue q){
    return q.front == NULL;
}
Queue enQueue(Queue q, int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if(isEmpty(q)){
        q.front = newNode;
        q.rear = newNode;
    }
    else{
        q.rear->next = newNode;
        q.rear = newNode;
    }
    return q;
}

Queue deQueue(Queue q){
    if(isEmpty(q)){
        printf("The Queue is already empty!\n");
        exit(0);
    }
    else if(q.front == q.rear){
        q.front = q.rear = NULL;
    }
    else{
        Node* temp = q.front;
        q.front = q.front->next;
        free(temp);
    }
    return q;
}

void printFront(Queue q){
    if(isEmpty(q)){
        printf("The queue is empty!\n");
    }
    else{
        printf("%d ", (q.front)->data);
    }
}
