#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int swap(int a, int b){
    int tmp = a;
    a=b;
    b=tmp;
}

typedef struct books {
    char book_name[30];
    char author_name[30];
    char publisher[20];
    int year;
    double price;
    struct books* next;
} books;

books* top, last;

void iniList(){
    return top = last = NULL;
}


books* makeBook(char* book_name, char* author_name, char * publisher, int year, double price){
    books* new = (books*)malloc(sizeof(books));
    strcpy(new->book_name, book_name);
    strcpy(new->author_name, author_name);
    strcpy(new->publisher, publisher);
    new->year = year;
    new->price  = price;
    new->next = NULL;
    return new;
}

void processMakeBook(){
    int i;
    char book_name[30], author_name[30], publisher[30];
    int year;
    double price;
    printf("Enter the name of the book: ");
    scanf("%s", book_name);
    printf("Enter the name of the author: ");
    scanf("%s", author_name);
    printf("Enter the name of the publisher: ");
    scanf("%s", publisher);
    printf("Enter the year: ");
    scanf("%d", &year);
    printf("Enter the price: ");
    scanf("%lf" &price);
    books* new = makeBook(book_name, author_name, publisher, year, price);
    if (top == NULL){
        top = last = new;
    }
    else{
        last->next = new;
        last = new;
    }
}

void processPrint(){
    if(top == NULL){
        printf("The list is empty!\n");
        return;
    }
    for(books* p = top; p!= NULL; p=p->next){
        printf("%s %s %s %d %lf\n", p->book_name, p->author_name, p->publisher, p->year, p->price);
    }
}

int main(){

    int mode;
    iniList();
    printf("1. Enter information of n books of HUST\n2. Print the information of the entered books on the screen\n3. Sort descending information by year of publication and display\n4. Search for books by tile\n5. Seach books by authors' name\6. Exit");

    do 
    {
        printf("Choose mode: ");
        scanf("%d", &mode);
        switch(mode){
            case 1:; int p;
                    printf("How many books you want to enter: ");
                    scanf("%d", &p);
                    for(int q = 1; q<=p; q++){
                        printf("%d", q);
                        processMakeBook();
                    }
                break;
            case 2:processPrint();
                break;
            case 3:
                break;
            case 4: 
                break;
            case 5: 
                break;
            case 6:
                break;
        }
    } while(mode != 6);
    
}


    int Arr[] = {1, 2};
    swap(Arr[0], Arr[1]);
    printf("%d", Arr[0]);
    return 0;
}

