#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int *p, int start, int end){
    int pivot = p[end];
    int index = start;
    for(int i = start; i<=end; i++){
        if(p[i]<=pivot){
            swap(&p[i], &p[index]);
            index++;
        }
    }
    return index-1;
}

void quickSort(int* p, int start, int end){
    if(start < end){
        int k = partition(p, start, end);
        quickSort(p, start, k-1);
        quickSort(p, k+1, end);
    }
    else return;
}

void processQuickSort(int * p, int n){
    int start = 0;
    end = n -1;
    quickSort(p, start, end);
}

int main(){
    int Arr[5] = {4,9,1,7,3};
    quickSort(Arr, 0 , 4);
    for(int i = 0; i<5; i++){
    printf("%d ", Arr[i]);
    }
}