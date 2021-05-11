#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int id;
    struct Node* leftChild;
    struct Node* rightChild;
}Node;

Node* root;

Node* makeNode(int id){
    Node* p = (Node*)malloc(sizeof(Node));
    p->id = id;
    p->leftChild = NULL;
    p->rightChild = NULL;
    return p;
}

Node* find(Node* r, int id){
    if(r == NULL) return NULL;
    if(r->id == id) return r;
    if(find(r->leftChild, id) == NULL){
        find(r->rightChild, id);
    }
}

void addLeftChild(int u, int left){
    Node* pu = find(root, u);
    if(pu == NULL){
        printf("Not Found Parent\n");
        return;
    }
    if(pu->leftChild != NULL){
        printf("This Node has alrady had left Child\n");
        printf("Options: \n");
        int option;
        printf("1. Add Right\n2.Skip\n");
        scanf("%d", &option);
        getchar();
        switch(option){
            case 1: addRightChild(u, left);
                break;
            case 2: return;
        }
    }
    else{
        Node* p = makeNode(left);
        pu->leftChild = p;
    }
}
void addRightChild(int u, int right){
    Node* pu = find(root, u);
    if(pu == NULL){
        printf("Not Found Parents\n");
        return;
    }
    if(pu->rightChild == NULL){
        printf("This Node has already had a right child\n");
        printf("Options: \n");
        int option;
        printf("1. Add Left\n2.Skip\n");
        scanf("%d", &option);
        getchar();
        switch(option){
            case 1: addLeftChild(u, right);
                break;
            case 2: return;
        }
    }
    else{
        Node* p = makeNode(right);
        pu->rightChild = p;
    }
}

void load(char* filename){
    FILE* f = fopen(filename, "r");
    root = NULL;
    while(1){
        int u;
        fscanf(f, "%d", &u);
        if(u == -2) break;
        if(root == NULL) root =makeNode(u);
        int l,r;
        fscanf(f, "%d %d", &l, &r);
        if(l>1) addLeftChild(u,l);
        if(r>1) addRightChild(u, r);
    }
    fclose(f);
}
void printTree(Node* r){
    if(r == NULL) return;
    printf("%d: ", r->id);
    if(r->leftChild == NULL) printf("left Child = NULL");
    else printf("leftChild = %d ", r->leftChild->id);
    if(r->rightChild == NULL) printf("right Child = NULL");
    else printf("rightChild = %d ", r->rightChild->id);
    printf("\n");

    printTree(r->leftChild);
    printTree(r->rightChild);
}

void printTreeFile(Node*r, FILE* f){
    if(r == NULL) return;
    fprintf(f, "%d", r->id);
    if(r->leftChild == NULL) fprintf(f, "-1");
    else fprintf(f, "%d", r->leftChild->id);
    if(r->rightChild == NULL) fprintf(f, "-1");
    else fprintf(f, "%d", r->rightChild->id);
    fprintf(f,"/n");

    printTreeFile(r->leftChild, f);
    printTreeFile(r->rightChild, f);
}
void processLoad(){
    char filename[256];
    scanf("%s", filename);
    load(filename);
}

void printChildren(Node* p){
    if(p->leftChild == NULL) printf("Node %d does not has leftChild", p->id);
    else printf("Left Child = %d", p->leftChild->id);
    if(p->rightChild == NULL) printf("Node %d has no right Child\n", p->id);
    else printf("Right Chiild = %d", p->rightChild->id);
}

void processFind(){
    int id;
    scanf("%d", &id);
    getchar();
    Node* p = find(root, id);
    if(p==NULL) printf("Not Found %d\n", id);
    else{
        printf("Found Node %d: ", id);
        printChildren(p);
    }
}

void processPrint(){
    printTree(root);
}

void processAddLefChild(){
    int id,u;
    printf("Enter the id: ");
    scanf("%d", &id);
    getchar();
    printf("Enter the interger: ");
    scanf("%d", &u);
    getchar();
    addLeftChild(id, u);
    printf("Add Child Successfully!\n");
}
void processAddRightChild(){
    int id,u;
    printf("Enter the id: ");
    scanf("%d", &id);
    getchar();
    printf("Enter the interger: ");
    scanf("%d", &u);
    getchar();
    addRightChild(id, u);
    printf("Add Child Successfully!\n");
}
int height(Node* p){
    if(p == NULL) return 0;
    int maxH = 0;
    int hl = height(p->leftChild);
    if(maxH < hl) maxH = hl;
    int hr = height(p->rightChild);
    if(maxH < hr) maxH = hr;
    return maxH + 1;
}
void processHeight(){
    int id;
    printf("Enter id: ");
    scanf("%d", &id);
    Node* p = find(root, id);
    if(p == NULL) printf("Not Found %d", id);
    else printf("Height of p is %d\n", height(p));

}

int count(Node*p){
    if(p==NULL) return 0;
    return 1 + count(p->leftChild) + count(p->rightChild);
}

void printLeaves(Node*p){
    if(p == NULL) return;
    if(p->leftChild == NULL && p->rightChild == NULL) printf("%d", p->id);
    printLeaves(p->leftChild);
    printLeaves(p->rightChild);
}
void processFindLeaves(){
    printLeaves(root); printf("\n");
}

void processCount(){
    printf("Number of nodes = %d\n", count(root));
}
void processStore(){
    char filename[256];
    scanf("%s", filename);
    FILE*f= fopen(filename, "w");
    printTreeFile(root, f);
    fprintf(f, "-2");
    fclose(f);
}
void freeTree(Node*r){
    if(r == NULL) return;
    freeTree(r->leftChild);
    freeTree(r->rightChild);
    free(r);
    r == NULL;
}
Node* makeRoot(int data){
    Node* p = makeNode(data);
    root = p;
    p->leftChild = NULL;
    p->rightChild = NULL;
    return p;
}

void processMakeRoot(){
    int data;
    printf("Enter data for root: ");
    scanf("%d", &data);
    makeRoot(data);
}
int main(){
    int mode;
    printf("0. Exit\n");
    printf("1. Load\n");
    printf("2. Print\n");
    printf("3. Find\n");
    printf("4. Height\n");
    printf("5. Count\n");
    printf("6. Find Leaves\n");
    printf("7. Add Left Child\n");
    printf("8. Add Right Child\n");
    printf("9. Store\n");
    printf("10. Make Root\n");
    do{
        printf("Choose mode: ");
        scanf("%d",&mode);
        switch (mode)
        {
        case 0: 
            break;
        case 1:
            processLoad();
            break;
        case 2:
            processPrint();
            break;
        case 3:
            processFind();
            break;
        case 4:
            processHeight();
            break;
        case 5:
            processCount();
            break;
        case 6:
            processFindLeaves();
            break;
        case 7:
            processAddLefChild();
            break;
        case 8:
            processAddRightChild();
            break;
        case 9: processStore();
            break;
        case 10: processMakeRoot();
            break;
        default: printf("Please enter valid value!\n");
            break;
        }
    }while(mode != 0);
    freeTree(root);
    return 0;
}
