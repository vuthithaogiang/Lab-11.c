
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 5

typedef struct {
	float yards;
	float feet;
	float inches;
} Length;

void getLengths(Length* lengths);

void showLengths(Length* lengths, int size);

void sortLengths(Length* lengths, int size);

void swap(Length* length, Length* lengthOther);

int main() {

	Length lengths[SIZE];

	int size = 0;

	int choice = 0;

	do {
		printf("\n\t====================> MENU <=====================");
		printf("\n\t1. Get 5 lengths.");
		printf("\n\t2. Show 5 lengths.");
		printf("\n\t3. Sort lengths by ascending.");
		printf("\n\t0. Exit.");
		printf("\n\t=================================================");

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
			for (int i = 0; i < SIZE; i++) {

				getLengths(&lengths[size++]);
			}
			
			break;
		}
		case 2:
		{
			showLengths(lengths, size);
			break;

		}
		case 3:
		{
			sortLengths(lengths, size);

			showLengths(lengths, size);
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

void getLengths(Length* lengths) {
	
		printf("\nEnter yard: ");
		scanf("%f", &lengths->yards);

		lengths->feet = lengths->yards / 3;
		lengths->inches = lengths->yards / 36;

	
}


void showLengths(Length* lengths, int size) {
	printf("\n\t============> Listed Lengths <===============\n");

	printf("\n%-15s%-15s%-15s\n", "Yards", "Feet", "Inches");

	for (int i = 0; i < size; i++) {

		printf("%-15.3f%-15.3f%-15.3f\n", lengths[i].yards, lengths[i].feet, lengths[i].inches);
	}
}

void sortLengths(Length* lengths, int size) {
	for (int i = 0; i < size - 1; i++) {

		for (int j = size - 1; j > i; j--) {

			if (lengths[j - 1].yards > lengths[j].yards) {

				swap(&lengths[j - 1], &lengths[j]);
			}
		}
	}
}

void swap(Length* length, Length* lengthOther) {
	Length tmp = *length;
	*length = *lengthOther;
	*lengthOther = tmp;
}
