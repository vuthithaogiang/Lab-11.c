

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define SIZE 100

typedef struct {
	int id;
	char fullName[40];
	char course[40];
	int yearOfRegistration;
} Student;


void getStudentInfo(Student* s);

void showStudentInfo(Student* students, int size);

int findStudentById(Student* students, int size, int id);

void findStudentByYearOfRegistration(Student* students, int size, Student* result, int* found, int year);

void removeSpaceInName(char* str);

void toSentenceCase(char* str);

void trimTail(char* str);

void trimHead(char* str);

void trimMidle(char* str);



int main() {

	int size = 0;

	Student* students;

	students = (Student*)malloc(SIZE * sizeof(Student));

	int choice = 0;

	do {
		printf("\n\t================================== MENU ================================");
		printf("\n1. Insert new student.");
		printf("\n2. Display all of students in listed.");
		printf("\n3. Find student by year of registration.");
		printf("\n4. Find student by ID.");
		printf("\n0. Exit.");
		printf("\n==========================================================================");

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
			Student s;
			getStudentInfo(&s);
			students[size++] = s;
			break;

		}
		case 2:
		{
			showStudentInfo(students, size);
			break;

		}
		case 3:
		{
			if (size > 0) {
				int year;
				printf("\nEnter year of the registration that you want to search: ");
				scanf("%d", &year);

				Student* result;

				result = (Student*)malloc(SIZE * sizeof(Student));

				int found = 0;

				findStudentByYearOfRegistration(students, size, result, &found, year);

				if (found > 0) {

					showStudentInfo(result, found);

				}
				else {
					printf("\nDon't find student has year of registration: %d in list.", year);
					printf("\nPlease try again!");
				}
			}
			else {
				printf("\nThe listed Students is empty. Please try again!");

			}
			break;

		}
		case 4:
		{
			if (size > 0) {
				int id;
				printf("\nEnter ID's student that you want to search: ");
				scanf("%d", &id);

				int index = findStudentById(students, size, id);

				if (index == -1) {
					printf("\nDon't find student has ID: %d in listed.", id);
					printf("\nPlease try again!");
				}
				else {
					printf("\n\t---> Information's student found <------");
					printf("\n%-15s%-40s%-40s%-15s\n", "ID", "Full name", "Course", "Year R");
					printf("%-15d%-40s%-40s%-15d\n", students[index].id, students[index].fullName, students[index].course,
						students[index].yearOfRegistration);
				}
			}
			else {
				printf("\nThe listed Students is empty. Please try again!");

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

void getStudentInfo(Student* s) {
	printf("\nEnter ID: ");
	scanf("%d", &s->id);

	printf("\nEnter full name: ");
	scanf("%*c");
	scanf("%39[^\n]", s->fullName);
	removeSpaceInName(s->fullName);
	toSentenceCase(s->fullName);

	printf("\nEnter name's course: ");
	scanf("%*c");
	scanf("%39[^\n]", s->course);

	printf("\nEnter year of registration: ");
	scanf("%d", &s->yearOfRegistration);
}


void showStudentInfo(Student* students, int size) {
	if (size > 0) {

		printf("\n%-15s%-40s%-40s%-15s\n", "ID", "Full name", "Course", "Year R");

		for (int i = 0; i < size; i++) {

			printf("%-15d%-40s%-40s%-15d\n",
				students[i].id, students[i].fullName, students[i].course, students[i].yearOfRegistration);

		}
		

	}
	else {
		printf("\nThe listed Students is empty. Please try again!");
	}
}


int findStudentById(Student* students, int size, int id) {

	for (int i = 0; i < size; i++) {
		if (students[i].id == id) {
			return i;
		}
	}
	return -1;
}

void findStudentByYearOfRegistration(Student* students, int size, Student* result, int* found, int year) {

	for (int i = 0; i < size; i++) {
		if (students[i].yearOfRegistration == year) {

			result[(*found)++] = students[i];
		}
	}
}

void removeSpaceInName(char* str) {
	trimHead(str);
	trimTail(str);
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

			for (int j = i; j < n - 1; j++) {

				str[j] = str[j + 1];
			}

			str[n - 1] = '\0';
			n--;
			i--;
		}
	}
}
