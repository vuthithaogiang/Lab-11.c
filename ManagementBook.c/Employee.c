
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define SIZE 100

typedef struct {
	int day;
	int month;
	int year;
} Date;

typedef struct {
	int id;
	char fullName[40];
	long salary; 
	Date dateOfStartWorking;

} Employee;



void getEmployeeInfo(Employee * emp);

void showEmployeeInfo(Employee* employees, int size);

void setIncreaseSalary(Employee* employees, int size);

void findEmployeeWorkMore10Year(Employee* employees, int size, Employee* result, int* found);

void trimTail(char* str);

void trimHead(char* str);

void trimMidle(char* str);

void removeSpaceInName(char* str);

void toSentenceCase(char* str);

int main() {
	Employee* employees;

	employees = (Employee*)malloc(SIZE * sizeof(Employee));

	int size = 0;

	int choice = 0;

	do {
		printf("\n\t================================= MENU ===============================");
		printf("\n1. Insert new employee in listed.");
		printf("\n2. Display all of employees in listed.");
		printf("\n3. Display all of employee after increase salary.");
		printf("\n4. Display all of employee had worked more than 10 years.");
		printf("\n0. Exit.");
		printf("\n=========================================================================");

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
			Employee emp;
			getEmployeeInfo(&emp);
			employees[size++] = emp;
			break;

		}
		case 2:
		{
			showEmployeeInfo(employees, size);
			break;
		}
		case 3:
		{
			if (size > 0) {
				setIncreaseSalary(employees, size);
				showEmployeeInfo(employees, size);
			}
			else {
				printf("\nThe listed employees is empty. Please add employee first!");

			}
			break;
		}
		case 4:
		{
			if (size > 0) {
				int found = 0;
				Employee* result;

				result = (Employee*)malloc(SIZE * sizeof(Employee));

				findEmployeeWorkMore10Year(employees, size, result, &found);

				if (found > 0) {
					printf("\n\t====> Information's Employees found <======");

					showEmployeeInfo(result, found);
				}
				else {
					printf("\nDon't find employee has year of working more tha 10 years.");
				}
			}
			else {
				printf("\nThe listed employees is empty. Please add employee first!");

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

void getEmployeeInfo(Employee * emp) {

	printf("\nEnter ID: ");
	scanf("%d", &emp->id);
	   
	printf("\nEnter full name: ");
	scanf("%*c");
	scanf("%39[^\n]", emp->fullName);
	removeSpaceInName(emp->fullName);
	toSentenceCase(emp->fullName);


	printf("\nEnter salary: ");
	scanf("%ld", &emp->salary);

	printf("\nEnter the date started working: ");
	scanf("%d %d %d", &emp->dateOfStartWorking.day, 
		&emp->dateOfStartWorking.month, &emp->dateOfStartWorking.year);

	
}


void showEmployeeInfo(Employee * employees, int size) {

	if (size > 0) {

		printf("\n\t =========> Listed Employees <============");

		printf("\n%-15s%-40s%-15s%-30s\n", "Id", "Full Name", "Salary", "Date Start Work");

		for (int i = 0; i < size; i++) {

			printf("%-15d%-40s%-15ld%-2d%s%-2d%s%-4d\n",
				employees[i].id, employees[i].fullName, employees[i].salary,
				employees[i].dateOfStartWorking.day, "/", employees[i].dateOfStartWorking.month,
				"/", employees[i].dateOfStartWorking.year);
		}

	}
	else {
		printf("\nThe listed employees is empty. Please add employee first!");
	}
}


void setIncreaseSalary(Employee* employees, int size) {

	for (int i = 0; i < size; i++) {
		
		if (employees[i].salary <= 2000) {

			employees[i].salary += employees[i].salary * 15 / 100;

		}
		else if (2000 < employees[i].salary <= 5000) {

			employees[i].salary += employees[i].salary * 10 / 100;

		}
		
	}

}

void findEmployeeWorkMore10Year(Employee* employees, int size, Employee* result, int* found) {

	for (int i = 0; i < size; i++) {

		if (employees[i].dateOfStartWorking.year <=  2012 ) {

			result[(*found)++] = employees[i];

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

	for (int i = 0; i < n - 1; i++) {

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

void removeSpaceInName(char* str) {
	trimTail(str);
	trimHead(str);
	trimMidle(str);

}

void toSentenceCase(char* str) {

	int n = strlen(str);
	str[0] = toupper(str[0]);

	for (int i =  0; i < n - 1; i++) {
		if (i < n - 1 && isspace(str[i]) && !isspace(str[i + 1]) ){

			str[i + 1] = toupper(str[i + 1]);
		}
	}

}