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
    if(r==NULL) {
        r = makeNode(name, email);
        return r;
    }
    int c = strcmp(r->name, name);
    if(c == 0){
        printf("Student %s exist, insert incomplete!\n", name);
        return r;
    } 
    else if (c > 0){
        r->leftChild = insert(r->leftChild, name, email);
        return r;
    }
    else {
        r->rightChild = insert(r->rightChild, name, email);
        return r;
    }
}

void processInsert(){
    char name[30], email[30];
    printf("Enter the student's name: ");
    scanf("%s", name);
    printf("Enter the student's email: ");
    scanf("%s", email);
    root = insert(root, name, email);
}

Node* find(Node* r, char* name){
    if(r==NULL) return NULL;
    int c = strcmp(r->name, name);
    if(c==0) return r;
    else if(c<0) return find(r->rightChild, name);
    if(c>0) return find(r->leftChild, name);
}

void processFind(){
    char name[30];
    printf("Enter the student's name: ");
    scanf("%s", name);
    Node* tmp = find(root, name);
    if(tmp == NULL){
        printf("Cannot find student with the name '%s'!\n", name);
        return; 
    }
    else{
        printf("Found student!\n");
        printf("%s-%s", tmp->name, tmp->email);
    }
}

Node* findMin(Node* r){
    if(r==NULL) return NULL;
    Node* lmin = findMin(r->leftChild);
    if(lmin !=NULL) return lmin;
    return r;
}
Node* removeStudent(Node*r, char* name){
    if(r==NULL) return NULL;
    int c = strcmp(r->name, name);
    if(c>0) r->leftChild = removeStudent(r->leftChild, name);
    else if (c<0) r->rightChild = removeStudent(r->rightChild, name);
    else {
        if(r->leftChild != NULL && r->rightChild != NULL){
            Node* tmp = findMin(r->rightChild);
            strcpy(r->name, tmp->name);
            strcpy(r->email, tmp->email);
            r->rightChild = removeStudent(r->rightChild, tmp->name);
        }
        else{
            Node* tmp = r;
            if(r->leftChild == NULL) {
                r= r->rightChild;
            }
            else {
                    r= r->leftChild;
                }
        free(tmp);
        }
    }
    return r;

}
void freeTree(Node* r){
    if(r == NULL) return;
    freeTree(r->leftChild);
    freeTree(r->rightChild);
    free(r);
}

void load(char* filename){
    FILE* f = fopen(filename, "r");
    if(f==NULL) printf("Load data -> File not found!\n");
    root = NULL;
    while(!feof(f)){
        char name[256], email[256];
        fscanf(f, "%s %s",name, email);
        root = insert(root, name, email);
    }
    fclose(f);
}

void inOrder(Node* r){
    if(r==NULL) return;
    inOrder(r->leftChild);
    printf("%s, %s\n", r->name, r->email);
    inOrder(r->rightChild);
}

void inOrderF(Node*r, FILE* f){
    if(r==NULL) {
        return;
    }
    inOrderF(r->leftChild, f);
    fprintf(f,"%s %s\n", r->name, r->email);
    inOrderF(r->rightChild, f);
}

void processPrint(){
    inOrder(root);
}

void processStore(){
    char filename[256];
    scanf("%s", filename);
    FILE* f = fopen(filename, "w");
    inOrderF(root, f);
    fclose(f);
}
void processLoad(){
    char filename[256];
    printf("Enter the file name: ");
    scanf("%s", filename);
    load(filename);
}

void processRemove(){
    char name[256];
    scanf("%s", name);
    root = removeStudent(root, name);
}
int main(){
    int mode;
    printf("1. Load\n2. Find\n3. Insert\n4. Remove\n5. Print\n6. Store\n0. Quit\n");
    do {
        
        printf("Choose mode: ");
        scanf("%d", &mode);
        switch(mode){
            case 0:; return 0;
            case 1: processLoad();
                break;
            case 2: processFind();
                break;
            case 3: processInsert();
                break;
            case 4: processRemove();
                break;
            case 5: processPrint();
                break;
            case 6: processStore();
                break;
            default:; printf("Invalid Mode!\n");
        }
    } while(mode!=0);
    freeTree(root);
    return 0;
}