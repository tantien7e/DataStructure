#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

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
    fscanf(fptr, "%d\n", &element);
    int i;
    for( i = 0; i<element; i++){
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

void sort(){
    Address toLowerList[element];
    int i;
    for(i=0; i<element; i++){

    }

}

int main(){
    processLoad();
    int i;
    for( i = 0; i < element; i++){
        printf("%s\n", List[i].name);
    }
    return 0;
}
