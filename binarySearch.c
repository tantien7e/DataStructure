#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

int main(){
    int Arr[5] = {1,3,5,7,9};
    int k = binarySearch(Arr, 5, 9);
    if(k != -1) printf("%d", Arr[k]);
    return 0;
}