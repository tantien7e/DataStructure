#include<stdio.h>
#include<stdlib.h>

typedef struct Address{
    char name[30];
    char phone [15];
    char email[30];
} Address;

Address List[];
int element;

void load(char* filename){
    FILE* fptr = fopen(filename, "r");
    int n;
    fscanf(fptr, "%d\n", &n);
    element = n;
    Address* pointer = (Address*)malloc(sizeof(Address)*n);
    for(int i = 0; i<n; i++){
        fscanf(fptr, "%s-%s-%s\n", List[i].name, List[i].phone, List[i].email);
    }
    fclose(fptr);
}   

void processLoad(){
    char filename[30];
    printf("Enter the file name: ");
    scanf("%s", filename);
    load(filename);
}

void insertionSort(Address List[]){
    for(int i = 1; i< element; i++){

    }
}
int main(){
    processLoad();
    for(int i = 0; i < element; i++){
        printf("%s\n", List[i].name);
    }
    return 0;
}