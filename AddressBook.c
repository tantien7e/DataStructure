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


void insertionSort(Address List[]){
    for(int i = 0; i<element; i++){
        Address min = List[i];
    while(i > 0 && strcmp(min.name, List[i-1].name) <0 ){
        List[i]= List[i-1];
        i--;
    }
    List[i] = min;
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
    insertionSort(List);
    store();
    return 0;
}