#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int* createArr(){
    int *p = (int*)malloc(sizeof(int)*10000000);
    return p;
}

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void generateArr(int* p, int n){
    srand((int) time(0));
    for(int i = 0; i< n; i++){
        p[i] = rand();
    }
}


void insertionSort(int *p, int n){
    for(int i =1; i < n; i++){
        int value = p[i];
        while(i> 0 && value < p[i-1]){
            p[i] = p[i-1];
            i--;
        }
        p[i] = value; 
    }
    int t = clock();
    printf("Running time is: %f\n",(float) t/CLOCKS_PER_SEC);
}

void selectionSort (int *p, int n){
    for(int i = 0; i< n; i++){
        for(int j = i+ 1; j<n; j++){
            if(p[j]< p[i]){
                int tmp = p[j];
                p[j] = p[i];
                p[i] = tmp;
            }
        }
    }
    int t = clock();
    printf("Running time is: %f\n",(float) t/CLOCKS_PER_SEC);
}

void heapify(int *p, int n, int i){
    int largest = i;
    int l = i*2 + 1;
    int r = i*2 + 2;
    if(l<n && p[l] > p[largest]){
        largest = l;
    }
    if( r<n && p[r] > p[largest]){
        largest = r;
    }
    if(largest != i){
        swap(&p[largest], &p[i]);
        heapify(p,n,largest);
    }
}

void heapSort(int* p, int n){
    //Build heap from bottom up
    for(int i = n/2-1; i>=0; i--){
        heapify(p, n, i);
    }
    //take out the biggest item, the heap -1 element
    for(int i = n-1; i> 0; i--){
        swap(&p[i], &p[0]);
        heapify(p, i, 0);
    }
    int t = clock();
    printf("Running time is: %f\n",(float) t/CLOCKS_PER_SEC);
}

int main(){

    int* p = createArr();
    generateArr(p, 10000000);
    heapSort(p, 10000000);
    
    return 0;
}
