#include<stdio.h>
#include<stdlib.h>

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
int main(){
    processLoad();
    for(int i = 0; i < element; i++){
        printf("%s\n", List[i].name);
    }
    return 0;
}