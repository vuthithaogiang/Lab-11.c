



#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 10


typedef struct {
	int code;
	char name[30];
	char author[30];
	int copies; 
} Book;

void getBookInfo(Book* book);


int main() {
	Book* books[SIZE];

	int size = 0; 

	int choice = 0;
	do {
		printf("\n1. Add new book.");
		printf("\n2. Show information's book.");

		printf("\nYour choice? ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
		{
			Book book;
			getBookInfo(&book);
			books[size++] = &book;
			break;
		}
		case 2:
		{
			if (size > 0) {
				for (int i = 0; i < size; i++) {
					printf("\n--------------------------------");
					printf("\nCode:   %d", books[i]->code);
					printf("\nName:   %s", books[i]->name);
					printf("\nAuthor: %s", books[i]->author);
					printf("\nCopy:   %d", books[i]->copies);

				}
			}
			else {
				printf("\nPlease add book first!");
			}
			
			break;
		}
		}

	} while (choice != 0);

	return 0;
}

void getBookInfo(Book* book) {
	printf("\nEnter code: ");
	scanf("%d", &book->code);

	printf("\nEnter name: ");
	scanf("%*c");
	scanf("%29[^\n]", book->name);

	printf("\nEnter author: ");
	scanf("%*c");
	scanf("%29[^\n]", book->author);
	
	printf("\nEnter number of copies: ");
	scanf("%d", &book->copies);

}
