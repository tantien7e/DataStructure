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
	int bookNum = 0;
	/* Menu function */
	for(int count = 0; count < 100; count++){
	int mode;
	printf("=======================================================\n");
	printf("1. Enter the information of n books of HUST\n");
	printf("2. print the information of the entered books on the screen\n");
	printf("3. Sort descending information by year of publication\n");
	printf("4. Search for books by title\n");
	printf("5. Search books by author's name\n");
	printf("6. Exit\n");
	printf("=======================================================\n");
	scanf("%d", &mode);
	
	/*mode 1 - enter book */
	if(mode == 1){
        
        printf("How many books you want to enter: ");
        scanf("%d", &bookNum);
        for(int i = 0; i< bookNum; i++){
            printf("Enter the information for book number %d\n", i+1);
            printf("Enter the name of the book: ");
            scanf("%s", &book[i].book_name);
            printf("Enter the name of the author: ");
            scanf("%s", &book[i].author_name);
            printf("Enter the name of the publisher: ");
            scanf("%s", &book[i].publisher);
            printf("Enter the year: ");
            scanf("%d", &book[i].year);
            printf("Enter the price: ");
            scanf("%lf", &book[i].price);
        }
	}

	/*mode 2 - print entered book */
	if(mode == 2){
		if(bookNum ==0){
			printf("You haven't entered any books!\n");
		}
		else{
			printf("%d\n", bookNum);
			for(int i = 0; i< bookNum; i++){
				printf("%s\n", book[i].book_name);
				printf("%s\n", book[i].author_name);
				printf("%s\n", book[i].publisher);
				printf("%d\n", book[i].year);
				printf("%lf\n", book[i].price);
				printf("\n");
			}
		}
	}
	
	
	
	}
	return 0;
}
