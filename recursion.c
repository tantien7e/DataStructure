#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    /* data */
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* root;


Node* createNode(int data){
    Node* ptr = (Node*)malloc(sizeof(Node));
    ptr->data = data;
    ptr->right = NULL;
    ptr->left = NULL;
    return ptr;
}

Node* find(Node* ptr, int data){
    if(ptr == NULL) return NULL;
    if(ptr->data == data){
        printf("found parents\n");
        return ptr;
    }
    Node* q = ptr-> left;
    if(find(q, data) == NULL){
        q = ptr->right;
        find(q, data);
    }
}

void addChild(int name, int data){
    Node* k= find(root, name);
    
    if(k == NULL)
    {   printf("Cannot ad child!\n");
        return;
    }
    if(k->left != NULL && k-> right != NULL){
        printf("This Node has already 2 children!\n");
        return;
    }

    if(k->left == NULL){
        k->left = createNode(data);
        return;
    }
    else if(k->right == NULL){
        k->right = createNode(data);
        return;
    } 
}

int findSum(Node* ptr){
    if(ptr == NULL) return 0;
    else{
        int sum = 0;
        sum = sum + ptr->data + findSum(ptr->left) + findSum(ptr->right);
        return sum;
    }
}


int main(){
    int mode, name, data, tong;
    printf("Initialize Tree. Enter data for root: ");
    scanf("%d", &data);
    root = createNode(data);
    printf("0. Exit\n");
    printf("1. Add Child\n");
    printf("2. Find Sum of Tree\n");
    do {
        printf("Enter Mode: ");
        scanf("%d", &mode);
        switch(mode){
            case 1:;
                    printf("Enter the name of the parents: ");
                    scanf("%d", &name);
                    printf("Enter the data: ");
                    scanf("%d", &data);
                    addChild(name, data);
                    break;
            case 2:;
                    tong = findSum(root);
                    printf("The sum is: %d\n", tong);
                    break;

        }
    } while(mode !=0);
    return 0;
}
