#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

int main(){
    Queue q;
    q = iniQueue(q);
    q = enQueue(q,4);
    q = enQueue(q,5);
    q = deQueue(q);
    printFront(q);
    return 0;
}
