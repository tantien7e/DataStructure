#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int nbOfE;
int* createArr(){
    int *p = (int*)malloc(sizeof(int)*10000000);
    return p;
}
void generateArr(int* p, int n){
    srand((int) time(0));
    for(int i = 0; i< n; i++){
        p[i] = rand();
    }
}

void bruteForceSolve(int*p, int n, int Q){
    int cnt = 0;
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            if(p[i] + p[j] == Q) {
            cnt++;
            printf("%d %d\n", p[i], p[j]);
            }
        }
    }
    printf("result brutal= %d\n", cnt);
}

void merge(int* Left, int* Right, int* p, int l, int r){
    int i, j, k;
    i = j =k =0;
    while (i < l && j< r){
        if(Left[i]<=Right[j]){
            p[k] = Left[i];
            k++;
            i++;
        }
        else{
            p[k] = Right[j];
            j++;
            k++;
        }
    }
    while(i<l){
        p[k] = Left[i];
        i++;
        k++;
    }
    while(j<r){
        p[k] = Right[j];
        j++;
        k++;
    }
}

void mergeSort(int*p, int n){
    
    if(n<2) return;
    else{
        int mid = n/2;
        int Left[mid];
        int Right[n-mid];
        for(int i = 0; i< mid; i++){
            Left[i] = p[i];
        }
        for(int j = mid; j< n; j++){
            Right[j-mid] = p[j];
        }
        mergeSort(Left, mid);
        mergeSort(Right, n-mid);
        merge(Left, Right, p, mid, n-mid);
    }
}

int binarySearch(int* Arr, int n, int x){
    int start = 0;
    int end = n-1;
    while(start <=end){
        int mid = (start+end)/2;
        if(Arr[mid] == x) return mid;
        else if(Arr[mid] > x){
            end=mid -1;
        }
        else if(Arr[mid]<x){
            start = mid +1;
        }
    }
    return -1;
}

void processBinarySearch(int* p, int Q){
    mergeSort(p, nbOfE);
    int cnt = 0;
    for(int i = 0; i<nbOfE; i++){
        int ok = binarySearch(p, nbOfE, Q-p[i]);
        if(ok!=-1 && ok>i){
        cnt++;
        printf("%d %d\n", p[i], p[ok]);
        }
    }
    printf("result binary: %d\n", cnt);
}
int main(){
    int* p = createArr();
    int Q;
    printf("Enter the number of element in your array: ");
    scanf("%d", &nbOfE);
    generateArr(p, nbOfE);
    printf("\nEnter the number Q: ");
    scanf("%d", &Q);
    bruteForceSolve(p, nbOfE, Q);
    processBinarySearch(p, Q);
    return 0;
}