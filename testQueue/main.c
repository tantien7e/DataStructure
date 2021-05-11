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



void iniList(List alpha){
    alpha.top = NULL;
    alpha.last =NULL;
}

int isEmpty(List alpha){
    return alpha.top == NULL;
}
Node* makeNode(char name[30], char  email[30]){
    Node* p = (Node*)malloc(sizeof(Node));
    p->name = name;
    p->email = email;
    p->next = NULL;
    return p;
}

List addLast(List p, char* name, char* email){
    Node* new = makeNode(name, email);
    if(isEmpty(p)){
        p.top = new;
        p.last = new;
    }
    else {
        p.last->next = new;
        p.last = new;
    }
    return p;
}
void processAddLast(){
    char name[30];
    char email[30];
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your email: ");
    scanf("%s", email);
    addLast(name, email);
}
void printInfo(Node* p){
    for(p; p!= NULL; p =p->next){
        printf("%s - %s\n", p->name, p->email);
    }
}
void processPrint(List p){
    if(isEmpty(p)){
        printf("THe list has no data!\n");
        return;
    }
    else printInfo(p.top);
}




int main(){
    int mode;
    List student;
    iniList(student);
    do{
        printf("Choose mode: ");
        scanf("%d", &mode);
        switch(mode){
            case 0: return 0;

            case 1:
                    break;
            case 2:
                    break;
            case 3:
                    break;
            case 4:
                    break;
            case 5:
                    break;
            case 6:
                    break;
            default: printf("Invalid Mode!\n");
                    break;
        }
    } while(mode !=0);

    return 0;
}
