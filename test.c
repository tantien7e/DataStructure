#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
    char name[30];
    char email[30];
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

Node* root;
Node* makeNode(char* name, char* email){
    Node* p = (Node*)malloc(sizeof(Node));
    strcpy(p->name, name);
    strcpy(p->email, email);
    p->leftChild = p->rightChild = NULL;
    return p;
}
Node* insert(Node* r, char* name, char* email){
    if(r == NULL) {
        root = makeNode(name, email);
    }
    else {
        if(strcmp(r->name, name) > 0) {
            if(r->leftChild == NULL){
                r->leftChild = makeNode(name, email);
            }
            else {
                insert(r->leftChild, name, email);
            }
        }
        else if(strcmp(r->name, name) < 0){
            if(r->rightChild == NULL){
                r->rightChild = makeNode(name, email);
            }
            else {
                insert(r->rightChild,name, email);
            }
        }
        else if(strcmp(r->name, name) == 0){
            printf("Name adready existed!\n");
            return NULL;
        }
    }
}
void inOrder(Node* r){
    if(r==NULL) return;
    inOrder(r->leftChild);
    printf("%s, %s\n", r->name, r->email);
    inOrder(r->rightChild);
}

void processPrint(){
    inOrder(root);
}

void load(char* filename){
    char name[30];
    char email[30];
    FILE* fptr = fopen(filename, "r");
    while(!feof(fptr)){
        fscanf(fptr, "%s %s", &name, &email);
        insert(root, name, email);
    }
}

void processLoad(){
    char filename[30];
    printf("Enter the filename: ");
    scanf("%s", filename);
    load(filename);
}

Node* find(Node* r, char* name){
    if(r == NULL){
        printf("Cannot find student!\n");
        return NULL;
    }
    if(strcmp(r->name, name) == 0){
        printf("Found student!\n");
        printf("Name: %s, Email: %s\n", r->name, r->email);
        return r;
    }
    if(strcmp(r->name, name) < 0){
        find(r->rightChild, name);
    }
    if(strcmp(r->name, name) > 0){
        find(r->leftChild, name);
    }
}

void processFind(){
    char name[30];
    printf("Enter the name of the student: ");
    scanf("%s", name);
    find(root, name);
}

int main(){
    int mode;
    printf("1. Load\n2. Print\n3. Find\n");
    do{
        printf("Enter mode: ");
        scanf("%d", &mode);
        switch(mode){
            case 1: processLoad();
                break;
            case 2: processPrint();
                break;
            case 3: processFind();
                break;
        }
    }while(mode!=0);
    return 0;
}