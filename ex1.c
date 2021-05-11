#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char name[30];
	char email[30];
	struct Profile* next;
} Profile;

Profile* first, *last;

void initList(){
	first = NULL;
	last = NULL;
}

void printList(){
	for(Profile* ptr = first; ptr != NULL; ptr = ptr->next){
		printf("%s - %s\n", ptr->name, ptr->email);
	}
}

Profile* makeProfile(char name[], char email[]){
	Profile* node = (Profile*)malloc(sizeof(Profile));
	strcpy(node->name, name);
	strcpy(node->email, email);
	node->next=NULL;
	return node;
}

void addProfileLast(char name[], char email[]){
	Profile* new_node = makeProfile(name, email);
	if(first == NULL && last ==NULL){
		first = new_node;
		last = new_node;
	}
	else{
		last->next =new_node;
		last = new_node;
	}
}

void deleteNode(char* name){
	//Find the number of the node with the name;
	int count = 0;
	if(first == NULL && last ==NULL) return NULL;
	else{
		for(Profile* ptr = first; ptr != NULL; ptr = ptr->next){
			count++;
			if(strcmp(name, ptr->name) == 0){
				break;
			}
			count = 0;
		}
	}
	//Delete the node at that position
	Profile* previous = first;
	Profile* current = first;
	if(count == 1){
		first = current->next;
		free(current);
		current = NULL;
	}
	else if(count == 0) printf("There is no student with the name %s in the list.\n", name);
	else{
		do{
			previous = current;
			current = current->next;
			count--;
		} while(count !=1);
		previous->next = current->next;
		free(current);
		current = NULL;
	}
}
void findProfile(char name[]){
    for(Profile* ptr = first; ptr != NULL ;ptr = ptr->next){
        if(strcmp(name, ptr->name) == 0){
            printf("%s - %s\n", ptr->name, ptr->email);
        }
    }
}

void load(char filename[]){
	FILE* fptr = fopen(filename, "r");
	if(fptr == NULL) printf("File not found!\n");
	else{
		while(!feof(fptr)){
		char name[30];
		char email[30];
		fscanf(fptr,"%s-%s", name, email);
		addProfileLast(name, email);
		}
	}
	fclose(fptr);
}

void store(char filename[]){
	FILE* fptr = fopen(filename, "w+");
	Profile* ptr;
	for(ptr = first; ptr != NULL; ptr = ptr->next){
		fprintf(fptr,"%s-%s\n", ptr->name,ptr->email);
	}
	fclose(fptr);
}

int main(){
	int mode;
	char name[30];
	char email[30];
	char nameDel[30];
	char nameFind[30];
	initList();
	printf("Menu: \n");
	printf("0. Exit\n");
	printf("1. Load data from text file\n");
	printf("2. Print the information of student\n");
	printf("3. Add a new profile at the end of the list\n");
	printf("4. Remove a profile\n");
	printf("5. Find a profile given a name\n");
	printf("6. Store list into an external text file\n");

	do{
		printf("Choose mode: ");
		scanf("%d", &mode);
			switch(mode){
				case 1:;
                        char filenameload[30];
						printf("Enter file name: ");
						scanf("%s", filenameload);
						load(filenameload);
				    break;
				case 2:
						printList();
                    break;
				case 3:
						printf("Enter the name: ");
						scanf("%s", &name);
						printf("Enter the email: ");
						scanf("%s", &email);
						addProfileLast(name, email);
                    break;
				case 4:
						printf("Enter the name: ");
						scanf("%s", &nameDel);
						deleteNode(nameDel);
                    break;
				case 5:
                        printf("Enter the name: ");
                        scanf("%s", &nameFind);
                        findProfile(nameFind);
				    break;
				case 6:;
                        char filenamestore[30];
						printf("Enter file name: ");
						scanf("%s", filenamestore);
						store(filenamestore);
				    break;
			}
	}while(mode !=0);
	return 0;
}
