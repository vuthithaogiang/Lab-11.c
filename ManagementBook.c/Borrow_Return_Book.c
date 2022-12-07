
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define SIZE 100

typedef struct {
	int day;
	int month;
	int year;
}  Date;

typedef struct {
	int code;
	char name[30];
	char author[30];
	int copies;
}  Book;


typedef struct {
	Book book;
	char type[10]; // borrow or return 
	Date dateOfTransaction;
}  Transaction;


void getBookInfo(Book* book);

void showBooks(Book* books, int size);

int findBookById(Book* books, int size, int code);

void getTransactionBook(Transaction* tran);

int finfTransactionByBookCode(Transaction* trans, int size, int code);

void showTransactions(Transaction* trans, int size);

void trimTail(char* str);

void trimHead(char* str);

void trimMidle(char* str);

void removeSpaceInName(char* str);

void toSentenceCase(char* str);

void swapBook(Book* book, Book* bookOther);

void swapTransaction(Transaction* tran, Transaction* tranOther);

void sortBookByASCCode(Book* books, int size);

void sortTransactionByTheSameBook(Transaction* trans, int size);

void findTransactionSameBook(Transaction* trans, int size, Transaction* result, int* found, int code);

void findTransactionByDate(Transaction* trans, int size, Transaction* result, int* found, Date date);

void getDate(Date* date);

int main() {

	int choice = 0;

	Book books[SIZE];

	Transaction trans[SIZE];

	int sizeOfBooks = 0;

	int sizeOfTransactions = 0;

	do {
		printf("\n\t===============================> MENU <====================================");
		printf("\n\t1. Add new book in listed books.");
		printf("\n\t2. Display all of books.");
		printf("\n\t3. Borrow book by book's code.");
		printf("\n\t4. Return book by book's code.");
		printf("\n\t5. Show all transactions.");
		printf("\n\t6. Sort listed transcations by book.");
		printf("\n\t7. Sort listed books by ascending code.");
		printf("\n\t8. Diplay number of transaction's of book.");
		printf("\n\t9. Find information's transactions by date transaction.");
		printf("\n\t0. Exit.");
		printf("\n\t==============================================================================");

		printf("\nYour choice? ");
		scanf("%d", &choice);

		switch (choice) {
		case 0:
		{
			printf("\nThanks for using!");
			break;
		}
		case 1:
		{
			Book book;

			getBookInfo(&book);

			books[sizeOfBooks++] = book;

			break;

		}
		case 2:
		{
			if (sizeOfBooks > 0) {
				showBooks(books, sizeOfBooks);
			}
			else {
				printf("\nThe listed Books is empty. Please add new book first!");
			}
			break;
		}
		case 3:
		{
			if (sizeOfBooks > 0) {

				int code;
				printf("\nEnter the code's book that you want to borrow: ");
				scanf("%d", &code);

				int index = findBookById(books, sizeOfBooks, code);

				if (index == -1) {
					printf("\nDon't find book has code: %d in listed.", code);
					printf("\nPlease try again!");
				}
				else {

					trans[sizeOfTransactions].book = books[index];

					getTransactionBook(&trans[sizeOfTransactions++]); // nhap thong tin con lai
		
				}
				
			}
			else {
				printf("\nThe listed Books is empty. Please add new book first!");
			}
			break;
		}
		case 4 :
		{
			if (sizeOfTransactions > 0) {
				int code;
				printf("\nEnter the code's book that you want to return: ");
				scanf("%d", &code);

				int index = finfTransactionByBookCode(trans, sizeOfTransactions, code);

				if (index == -1) {
					printf("\nDon't find book has code: %d in listed transaction borrowed.", code);
					printf("\nPlease try agian!");
				}
				else {
					
					// add 1 tran return 

					trans[sizeOfTransactions].book = trans[index].book;

					getTransactionBook(&trans[sizeOfTransactions++]);
				}

				printf("\n%d", sizeOfTransactions);

			}
			else {
				printf("\nThe listed Transactions isempty. Please try again!");
			}
			break;
		}
		case 5:
		{
			if (sizeOfTransactions > 0) {
				showTransactions(trans, sizeOfTransactions);
			}
			else {
				printf("\nThe listed Transactions is empty. Please add new transaction first!");
			}
			break;
		}
		case 6:
		{
			if (sizeOfTransactions > 0) {
				sortTransactionByTheSameBook(trans, sizeOfTransactions);

				showTransactions(trans, sizeOfTransactions);
			}
			else {
				printf("\nThe listed Transacntons is empty. Please add new transaction first!");
			}
			break;
		}
		case 7: 
		{
			if (sizeOfBooks > 0) {
				sortBookByASCCode(books, sizeOfBooks);
				
				showBooks(books, sizeOfBooks);
			}
			else {
				printf("\nThe listed Books is empty. Please add new book first!");
			}
			break;
		}
		case 8:
		{
			if (sizeOfTransactions > 0) {

				int code;

				int found = 0;

				Transaction result[SIZE];

				printf("\nEnnter the code's that you want to find number of transactions: ");
				scanf("%d", &code);

				findTransactionSameBook(trans, sizeOfTransactions, result, &found, code);

				if (found == 0) {
					printf("\nDon't find book has code: %d in transaction.", code);
					printf("\nPlease try agian!");
				}
				else {
					showTransactions(result, found);
				}

			}
			else {
				printf("\nThe listed Transactions is empty. Please add new transcation first!");
			}
			break;
		}
		case 9:
		{
			if (sizeOfTransactions > 0) {
				Date date;

				getDate(&date);

				int found = 0;

				Transaction result[SIZE];

				findTransactionByDate(trans, sizeOfTransactions, result, &found, date);

				if (found == 0) {
					printf("\nDon't find transaction has date's transaction: %-2d / %-2d / %-4d in listed. ",
						date.day, date.month, date.year);

					printf("\nPlease try again!");
				}
				else {

					showTransactions(result, found);
				}

			}
			else {
				printf("\nThe listed Transcations is empty. Please add new transaction first!");
			}
			break;
		}
		default:
		{
			printf("\nInvalid choice. Please try again!");
			break;
		}
		}

	} while (choice != 0);

	return 0;
}

void findTransactionByDate(Transaction* trans, int size, Transaction* result, int* found, Date date) {

	for (int i = 0; i < size; i++) {

		if (trans[i].dateOfTransaction.year == date.year && trans[i].dateOfTransaction.month == date.month
			&& trans[i].dateOfTransaction.day == date.day) {

			result[(*found)++] = trans[i];
		}
	}
}


void getDate(Date* date) {
	printf("\nEnter day of date: ");
	scanf("%d", &date->day);

	printf("\nEnter month of date: ");
	scanf("%d", &date->month);

	printf("\nEnter year of date: ");
	scanf("%d", &date->year);

}


void findTransactionSameBook(Transaction* trans, int size, Transaction* result, int* found, int code) {

	for (int i = 0; i < size; i++) {

		if (trans[i].book.code == code) {

			result[(*found)++] = trans[i];

		}
	}
}



void getBookInfo(Book* book) {

	printf("\nEnter code's book: ");
	
	scanf("%d", &book->code);

	printf("\nEnter name's book: ");
	scanf("%*c");
	scanf("%29[^\n]", book->name);
	removeSpaceInName(book->name);
	toSentenceCase(book->name);


	printf("\nEnter author's book: ");
	scanf("%*c");
	scanf("%29[^\n]", book->author);
	removeSpaceInName(book->author);
	toSentenceCase(book->author);

	printf("\nEnter number of copy: ");
	scanf("%d", &book->copies);

}

void showBooks(Book* books, int size) {

	printf("\n\t==========> Listed all of Books <================");

	printf("\n%-15s%-30s%-30s%-15s\n", "Code", "Name", "Author", "Copies");

	for (int i = 0; i < size; i++) {

		printf("%-15d%-30s%-30s%-15d\n", books[i].code, books[i].name, books[i].author, books[i].copies);
	}
}


int findBookById(Book* books, int size, int code) {
	for (int i = 0; i < size; i++) {
		if (books[i].code == code) {
			return i;
		}
	}
	return -1;
}


void getTransactionBook(Transaction* tran) {

	printf("\nEnter type transaction (Borrow or Return) book: ");
	scanf("%*c");
	scanf("%9[^\n]", tran->type);
	removeSpaceInName(tran->type);
	toSentenceCase(tran->type);

	printf("\nEnter day of the date of transaction: ");
	scanf("%d", &tran->dateOfTransaction.day);

	printf("\nEnter month of the date of transaction: ");
	scanf("%d", &tran->dateOfTransaction.month);

	printf("\nEnter year of the date of transaction: ");
	scanf("%d", &tran->dateOfTransaction.year);

	
}


int finfTransactionByBookCode(Transaction* trans, int size, int code) {
	for (int i = 0; i < size; i++) {
		if (trans[i].book.code == code) {
			return i;
		}
	}
	return -1;
}


void showTransactions(Transaction* trans, int size) {
	printf("\n\t=========> All of Transactions <===============\n");

	printf("%-15s | %-30s | %-30s | %-15s | %-15s | %-20s\n ",
		             "Code", "Name", "Author","Copy", "Type", "Date Transaction");

	for (int i = 0; i < size; i++) {

		printf("-------------------------------------------------------------------------"
		"--------------------------------------------------------------------------\n");
		printf("%-15d | %-30s | %-30s | %-15d | %-15s | %-2d %s %-2d %s %-4d\n",
			trans[i].book.code, trans[i].book.name, trans[i].book.author, trans[i].book.copies,
			trans[i].type, trans[i].dateOfTransaction.day, "/", trans[i].dateOfTransaction.month,
			 "/", trans[i].dateOfTransaction.year);
	}
}


void trimTail(char* str) {
	int n = strlen(str);
	int count = 0; 
	int i = n - 1;
	while (isspace(str[i])) {
		count++;
		i--;
	}

	str[n - count] = '\0';
}

void trimHead(char* str) {
	int n = strlen(str);
	int count = 0;
	int i = 0;
	while (isspace(str[i])) {
		count++;
		i++;
	}

	for (int i = 0; i < n - count; i++) {
		str[i] = str[i + count];
	}

	str[n - count] = '\0';
}

void trimMidle(char* str) {
	int n = strlen(str);

	for (int i = 0; i < n - 1; i++) {
		if (isspace(str[i]) && isspace(str[i + 1])) {

			for (int j = i; i < n - 1; j++) {

				str[j] = str[j + 1];
			}

			str[n - 1] = '\0';
			n--;
			i--;
		}
	}
}

void removeSpaceInName(char* str) {
	trimTail(str);
	trimHead(str);
	trimMidle(str);
}

void toSentenceCase(char* str) {
	int n = strlen(str);

	str[0] = toupper(str[0]);

	for (int i = 0; i < n - 1; i++) {
		if (i < n - 1 && isspace(str[i]) && !isspace(str[i + 1])) {
			str[i + 1] = toupper(str[i + 1]);
		}
	}

}

void swapBook(Book* book, Book* bookOther) {
	Book tmp = *book;
	*book = *bookOther;
	*bookOther = tmp;

}

void swapTransaction(Transaction* tran, Transaction* tranOther) {
	Transaction tmp = *tran;
	*tran = *tranOther;
	*tranOther = tmp;
}

void sortBookByASCCode(Book* books, int size) {

	for (int i = 0; i < size - 1; i++) {

		for (int j = size - 1; j > i; j--) {

			if (books[j - 1].code > books[j].code) {

				swapBook(&books[j - 1], &books[j]);
			}
		}
	}
}

void sortTransactionByTheSameBook(Transaction* trans, int size) {

	for (int i = 0; i < size - 1; i++) {

		for (int j = size - 1; j > i; j--) {

			if (trans[j - 1].book.code > trans[j].book.code) {

				swapTransaction(&trans[j - 1], &trans[j]);
			}
		}
	}
}

