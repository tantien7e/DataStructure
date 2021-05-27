#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student {
    char name[30];
    char email[30];
} student;

student list[100];
int nbOStd;

void iniStdNum(){
    nbOStd = 0;
}

void load(char* filename){
    char name[30];
    char email[30];
    FILE* fptr = fopen(filename, "r");
    nbOStd = 0;
    while(!feof(fptr)){
        fscanf("%s %s\n", list[i].name, list[i].email);
        nbOStd++;
    }
    fclose(fptr);
}

void processLoad(){
    char filename[30];
    printf("Enter file name: ");
    scanf("%s", filename);
    load(filename);
}
void insert(char* name, char* email){
    strcpy(list[nbOStd].name, name);
    strcpy(list[nbOStd].email, email);
    nbOStd ++;
}

void processInsert(){
    char name[30];
    char email[30];
    printf("Enter the name: ");
    scanf("%s", name);
    printf("Enter the email: ");
    scanf("%s", email);
    insert(name, email);
}

void processPrint(){
    for(int i = 0; i<nbOStd; i++){
        printf("%s %s", list[i].name, list[i].email);
    }
}

int main(){
    iniStdNum();
    processInsert();
    processPrint();
}
