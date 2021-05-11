#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char fileinp[] = "tree.inp";
char fileout[] = "tree.out";
struct Node{
    char name[256];
    struct Node* leftMostChild;
    struct Node* rightSibling;
    struct Node* parent;
} typedef Node;

Node *root;

Node* makeNode(char* name){
    Node* p = (Node*)malloc(sizeof(Node));
    strcpy(p->name, name);
    p->leftMostChild = NULL;
    p->rightSibling = NULL;
    return p;
}

Node* find(Node* r, char *name){
    if (r==NULL) return NULL;
    if(strcmp(r->name, name) == 0) return r;
    Node* p = r->leftMostChild;
    while(p){
        Node* q = find(p, name);
        if(q) return q;
        p = p->rightSibling;
    }
}

Node* addLast(Node*p, char *name){
    if(p==NULL) return makeNode(name);
    p->rightSibling = addLast(p->rightSibling, name);
    return p;
}

void addChild(char* name, char* child){
    Node* r = find(root, name);
    if (r == NULL) {
        printf("Cannot find that name!\n");
        return;}
    r->leftMostChild = addLast(r->leftMostChild, child);
}

void printTree(Node* r){
    if(r==NULL) return;
    printf("%s: ", r->name);
    Node* p = r->leftMostChild;
    while(p){
        printf("%s ", p->name);
        p = p->rightSibling;
    }

    printf("\n");
    p = r->leftMostChild;
    while(p){
        printTree(p);
        p = p->rightSibling;
    }
}

void printTreeToF(Node* r, char* filename){
    FILE*f;
    f = fopen(filename, "a+");
    if(r == NULL) return;
    fprintf(f,"%s: ", r->name);
    Node* p = r->leftMostChild;
    while(p){
        fprintf(f,"%s ", p->name);
        p = p->rightSibling;
    }

    fprintf(f ,"$\n");
    p = r->leftMostChild;
    while(p){
        printTreeToF(p, filename);
        p = p->rightSibling;
    }

    fclose(f);
}

int height(Node* p){
    if(!p) return 0;
    int maxH = 0;
    Node*q = p->leftMostChild;
    while(q){
        int h = height(q);
        maxH = maxH < h? h:maxH;
        q = q->rightSibling;
    }
    return maxH + 1;
}

int count(Node* r){
    if(r==NULL) return 0;
    int cnt = 1;
    Node* q = r->leftMostChild;
    while(q){
        cnt += count(q);
        q = q->rightSibling;
    }
    return cnt;
}

void load(char* filename){
    char name[256] = "@", parent[256];
    FILE* fp;
    fp = fopen(filename, "r+");
    fscanf(fp, "%s ", parent);
    root = makeNode(parent);
    fscanf(fp, "%s ", name);
    while(strcmp(name,"$")!=0){
            addChild(parent, name);
            fscanf(fp, "%s ", name);
        }
    fscanf(fp, "\n");
    while(!feof(fp)){
        fscanf(fp, "%s ", parent);
        fscanf(fp, "%s ", name);
        while(strcmp(name,"$")!=0){
            addChild(parent, name);
            fscanf(fp, "%s ", name);
        }
        fscanf(fp,"\n");
    }
}

void menu(){
    int choice;
    char name[256], child[256];
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    getchar();
    switch(choice){
        case 1: load(fileinp);
                break;
        case 2:
            printf("Enter a name: ");
            gets(name);
            printf("\n");
            Node* p = find(root, name)->leftMostChild;
            printf("%s: ", name);
            while(p){
                printf("%s, ", p->name);
                p = p->rightSibling;
            }
            printf("\n");
            break;
        case 3:
            if(root == NULL)
            {
                printf("Enter the name: ");
                gets(name);
                root = makeNode(name);
            }
            else{
            printf("Enter parent's name: ");
            gets(name);
            printf("\n");
            printf("Enter child's name: ");
            gets(child);
            printf("\n");
            addChild(name,child);
            }
            break;
        case 4: printTree(root);
                break;
        case 5: printf("The height of the current tree is: %d\n", height(root));
                break;
        case 6: printf("The faminly has %d members", count(root));
                break;
        case 7: clearFile("tree.out");
                printTreeToF(root, "tree.out");
                break;
        default: return;
    }
    menu();
}


void clearFile(char* filename){
    FILE *f;
    f = fopen(filename, "w");
    fprintf(f, "");
    fclose(f);
}

int main(){
    printf("Menu: \n");
    printf("1. Load File\n2. Find Child Of a Parent\n3. Add Child to Tree\n4. Print TREE\n5. Find Height\n6. Count\n7. Store\n8: Exit\n");
    menu();


    return 0;
}