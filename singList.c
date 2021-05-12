#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
    char name[30];
    char email[30];
    struct Node* next;
} Node;

typedef struct List {
    Node* top;
    Node* last;
} List;

List list;
Node* iniList(List list){
    list.top = NULL;
    list.last = NULL;
}
Node* makeNode(char* name, char* email){
    Node* new = (Node*)malloc(sizeof(Node));
    strcpy(new->name, name);
    strcpy(new->email, email);
    new->next = NULL;
    return new;
}


void processAddNode(){
    char name[30];
    char email[30];
    printf("Enter the name: ");
    scanf("%s", name);
    printf("Enter the email: ");
    scanf("%s", email);
    if(list.top == NULL){
        list.top = list.last = makeNode(name, email);
    }
    else{
        Node* p = makeNode(name, email);
        p = list.last->next;
        list.last->next = p;
    }
}

void print(Node* p){
    for(p; p!= NULL; p = p->next){
        printf("%s %s\n", p->name, p->email);
    }
}
void load(char* filename){
    FILE* fptr = fopen(filename, "r");
    iniList(list);
    while(!feof(fptr)){
        char name[30]; 
        char email[30];
        fscanf(fptr,"%s - %s\n", name, email);
        if(list.top == NULL){
            list.top = list.last = makeNode(name, email);
        }
        else{
        Node* p = makeNode(name, email);
        list.last->next = p;
        list.last = p;
        }
    }
    fclose(fptr);
}
void processLoad(){
    char filename[30];
    printf("Enter the filename: ");
    scanf("%s", filename);
    load(filename);
}

void store(char* filename){
    FILE* fptr = fopen(filename, "w+");
    Node* p = list.top;
    for(p; p!= NULL; p = p->next){
        fprintf(fptr, "%s-%s\n", p->name, p->email);
    }
    fclose(fptr);
}

void processStore(){
    char filename[30];
    printf("Enter the file output: ");
    scanf("%s", filename);
    store(filename);
}

Node* find(char* name){
    Node* p = list.top;
    for(p;  p!= NULL; p=p->next){
        if(strcmp(p->name, name)==0) return p;
    }
    return p;
}

void processFind(){
    char name[30];
    printf("Enter the name of the student: ");
    scanf("%s", name);
    Node* p = find(name);
    if(p == NULL){
        printf("Can not find the student with the name %s\n", name);
        return;
    }
    else{
        printf("Found student!\n");
        printf("The email of this student is: %s\n", p->email);
        return;
    }
}

void processRemove(){
    char name[30];
    printf("Enter the name of the student to remove profile: ");
    scanf("%s", name);
    Node* tmp = find(name);
    if(tmp = list.top){
        list.top = list.top->next;
        free(tmp);
        printf("Remove Profile Successfully!\n");
        return;
    }
    Node* p = list.top;
    for(p; p!= NULL; p  = p->next){
        if(p->next == tmp){
            p->next = tmp->next;
            free(tmp);
            printf("Remove Profile Successfully!\n");
            return;
        }
    }
    if(p == NULL){
        printf("Can not remove this profile!\n");
        return;
    }
    
}

int main(){
    int mode;
    iniList(list);
    printf("1: Load a file to make list\n");
    printf("2: Print list\n");
    printf("3: Add a student to the last of the list\n");
    printf("4: Remove a student\n");
    printf("5: Find a student\n");
    printf("6: Store the list to a file\n");
    do{
        printf("Choose mode: ");
        scanf("%d", &mode);
        switch(mode){
            case 0: return 0;

            case 1: processLoad();
                    break;
            case 2: print(list.top);
                    break;
            case 3: processAddNode();
                    break;
            case 4: processRemove();
                    break;
            case 5: processFind();
                    break;
            case 6: processStore();
                    break;
            default: printf("Invalid Mode!\n");
                    break;
        } 
    } while(mode !=0);
    
    return 0;
}