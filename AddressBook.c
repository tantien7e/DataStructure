#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Address{
    char name[30];
    char phone [15];
    char email[30];
} Address;

Address List[100];
int element;

void load(char* filename){
    FILE* fptr = fopen(filename, "r");
    fscanf(fptr, "%d\n", &element);
    for(int i = 0; i<element; i++){
        fscanf(fptr, "%s %s %s\n", List[i].name, List[i].phone, List[i].email);
    }
    fclose(fptr);
}   

void processLoad(){
    char filename[30];
    printf("Enter the file name: ");
    scanf("%s", filename);
    load(filename);
}

void merge(Address L[], Address R[], Address List[], int l, int r){
    int i,j,k;
    i=j=k=0;
    while(i< l && j < r){
        if(strcmp(L[i].name, R[j].name)<0){
            List[k] = L[i];
            i++;
            k++;
        }
        else{
            List[k] = R[j];
            j++;
            k++;
        }
    }
    while(i<l){
        List[k] = L[i];
        i++;
        k++;
    }
    while(j<r){
        List[k] = R[j];
        k++;
        j++;
    }
}

void mergeSort(Address List[], int n){
    if(n<2) return;
    else {
        int mid = n/2;
        Address L[mid];
        Address R[n-mid];
        for(int i = 0; i< mid; i++){
            L[i] = List[i];
        }
        for(int j = mid; j<n; j++){
            R[j-mid] = List[j];
        }
        mergeSort(L, mid);
        mergeSort(R, n-mid);
        merge(L,R,List,mid,n-mid);
    }
}


void store(){
    char filename[30];
    printf("Enter the file name: ");
    scanf("%s", filename);
    FILE* p = fopen(filename, "w+");
    fprintf(p, "%d\n", element);
    for(int i = 0; i < element; i++){
        fprintf(p, "%s %s %s\n",List[i].name, List[i].phone, List[i].email);
    }
    fclose(p);
}




int main(){
    processLoad();
    mergeSort(List,element);
    store();
    return 0;
}