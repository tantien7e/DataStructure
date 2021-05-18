#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(int* a, int* b){
    int tmp = *a;
    *a=*b;
    *b= tmp;
}

void heapify(int Arr[], int n, int i){
    //Initiallize largest index, left and right child
    int largest = i;
    int l = i*2 + 1;
    int r = i*2 + 2;
    // If the left child is bigger than its parent => swap left and parent
    if(l<n && Arr[l]>Arr[largest]){
        largest = l;
    }
    //If the right child is larger than the current largest => swap right and largest
    if(r<n && Arr[r]>Arr[largest]){
        largest = r;
    }
    //wap the i to the largest
    if(largest != i){
        swap(&Arr[largest], &Arr[i]);
        //recursively heapify the affected subtree
        heapify(Arr, n, largest);
    }
}

void heapSort(int Arr[], int n){
    // Change the heap into max_heap (bottom up)
    for(int i = (int) n/2 -1; i>= 0; i--){
        heapify(Arr, n, i);
    }
    
    // swap the first and the last node => recursive
    for(int i = n-1; i> 0; i--){
        swap(&Arr[0], &Arr[i]);   
        heapify(Arr, i, 0);
    }
    
}

void main(){
    int Arr[9] = {10,14,8,7,11,6,4,5,3};
    heapSort(Arr, 9);
    for(int i = 0; i<9; i++){
    printf("%d ", Arr[i]);
    }
}