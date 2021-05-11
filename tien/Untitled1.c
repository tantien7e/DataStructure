
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char* book_name;
	char* author_name;
	char* publisher;
	int year;
	double price;
} book;

int main(){
	book book[30];
	printf("Enter the name of the book: ");
    scanf("%s", &book[0].book_name);
    printf("%s", book[0].book_name);
    return 0;
}
