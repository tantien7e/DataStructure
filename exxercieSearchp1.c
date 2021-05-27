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
    FILE* fptr = fopen(filename, "r");
    nbOStd  = 0;
    while(!feof(fptr)){
        fscanf(fptr, "%s %s\n", list[nbOStd].name, list[nbOStd].email);
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
int findPlace(char* name){
    for(int i = 0; i<nbOStd; i++){
        if(strcmp(name, list[i].name)<0) return i;
    } 
    return nbOStd;
}

void processInsert(){
    char name[30];
    char email[30];
    printf("Enter the name: ");
    scanf("%s", name);
    printf("Enter the email: ");
    scanf("%s", email);
    int k = findPlace(name);
    for(int i = nbOStd; i> k; i--){
        list[i] = list[i-1];
    }
    strcpy(list[k].name, name);
    strcpy(list[k].email, email);
    nbOStd++;

}

void processPrint(){
    for(int i = 0; i<nbOStd; i++){
        printf("Student number[%d]: %s - %s\n",i+1, list[i].name, list[i].email);
    }
}
int find(char* name){
    int start = 0;
    int end = nbOStd - 1;
    while(start<=end) {
        int mid = (start + end)/2;    
        if(strcmp(name, list[mid].name) == 0) return mid;
        if(strcmp(name, list[mid].name) < 0) end = mid - 1;
        if(strcmp(name, list[mid].name)> 0) start = mid + 1;
    }
    return -1;
}

void processFind(){
    char name[30];
    printf("Enter the name of the student: ");
    scanf("%s", name);
    int k = find(name);
    if(k==-1) printf("Cannot find student!\n");
    else{
        printf("Found student!\n");
        printf("%s-%s\n", list[k].name, list[k].email);
    }
}

void processRemove(){
    char* name[30];
    printf("Enter the student's name: ");
    scanf("%s", name);
    int k = find(name);
    if(k==-1){
        printf("Cannot find student's profile!\n");
        return;
    }
    else{
        nbOStd--;
        for(int i = k; i<nbOStd; i++){
            list[i] = list[i+1];
        }
        printf("Found Student, profile removed!\n");
    }
}

void heapify(int n, int i){
    int largest = i;
    int l = i * 2 + 1;
    int r = i * 2 + 2;
    if(l<n && strcmp(list[l].name, list[largest].name) == 1) largest =l;
    if(r<n && strcmp(list[r].name, list[largest].name) == 1) largest = r;
    if(largest != i){
        student tmp = list[i];
        list[i] = list[largest];
        list[largest] = tmp;
        heapify(n, largest);
    }
}
void processHeapSort(){
    for(int i = nbOStd/2 - 1; i>=0; i--) heapify(nbOStd, i);
    for(int i = nbOStd - 1; i>0; i--){
        student tmp = list[0];
        list[0] = list[i];
        list[i] = tmp;
        heapify(i, 0);
    }
}

void processStore(){
    char filename[30];
    printf("Enter the file name: ");
    scanf("%s", filename);
    FILE* fptr = fopen(filename, "w+");
    for(int i = 0; i<nbOStd; i++){
        fprintf(fptr, "%s %s\n", list[i].name, list[i].email);
    }
    fclose(fptr);
}

int main(){
    int mode;
    iniStdNum();
    printf("1. Load\n2. Find\n3. Insert\n4. Remove\n5. Sort (Acsending order)\n6. Print\n7. Store\n0. Quit\n");
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
            case 5: processHeapSort();
                break;
            case 6: processPrint();
                break;
            case 7: processStore();
                break;
            default:; printf("Invalid Mode!\n");
        }
    } while(mode!=0);
}
