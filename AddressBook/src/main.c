#include <stdio.h>
#include <stdlib.h>
#include "contact.h"

#define true 1
#define false 0
#define FILE_NAME "contacts.txt"

typedef int bool;

void newContact(FILE * fp, struct contactData data[100], int size);
void updateRecord(FILE *fp, struct contactData data[100], int size);
int find(char * first, char * last, const struct contactData data[100], int size);
void deleteRecord(struct contactData data[100], int size);
int save(FILE * fp, const struct contactData data[100], int size);

int main(void) { //main

	struct contactData data[100];
	int size = 0;

	FILE * fp;
	printf("opening %s ...\n", FILE_NAME);
	

	if ((fp = fopen(FILE_NAME, "r+")) == NULL) { 
	// check if contacts file is already there
		printf("%s does not exist, creating file ...\n", FILE_NAME);
		fp = fopen(FILE_NAME, "w+");
		
	} else {

		int i = 0;
		printf("loading data ...\n");


		
		while (!feof(fp)) {
			char *line[256];
			fgets(line, 256, fp);

			char newFirst[20];
			char newLast[20];
			char newPhone[20];
			char newEmail[20];

			sscanf(line, "%s %s %s %s\n", newFirst, newLast, newPhone, newEmail);

			data[i].firstName = newFirst;
			data[i].lastName = newLast;
			data[i].phone = newPhone;
			data[i].email = newEmail;
			-
			printf("loaded contact: ");
			printcon(data[i]);
			i++;
			if (feof(fp) == EOF) break;
		}

	}//end if

	fp = fopen(FILE_NAME, "w+");



	printf("Successful\n");

	while (true) {//repl

		char * input = (char*) malloc(sizeof(char) * 10);

		scanf("%s", input);
		if (0 == strcmp(input, "q")) {

			printf("bye.\n");
			return 0;

		} else if (strcmp(input, "new") == 0) {

			newContact(fp, data, size);

		} else if (strcmp(input, "find") == 0) {

			char lastName[50];
			char firstName[50];
			printf("input a first and last name to search for: \n");
			scanf("%s %s", firstName, lastName);
			int i = find(firstName, lastName, data, size);
			printcon(data[i]);



		} else if (strcmp(input, "update") == 0) {

			updateRecord(fp, data, size);

		} else if (strcmp(input, "remove") == 0) {

			deleteRecord(data, size);
			save(fp, data, size);

		} else {

			printf("unrecognized command\n");

		}
	}//end repl
	return 0;
} // end main

void newContact(FILE * fp, struct contactData data[100], int size) {
	
	printf("enter contact information [LAST NAME] [FIRST NAME] [9 DIGIT PHONE NUMBER] [EMAIL]:\n");

	char newLast[20]; //allocating memory for the attributes of the new contact
	char newFirst[20];
	char newPhone[20];
	char newEmail[20];
	scanf("%s %s %s %s", newFirst, newLast, newPhone, newEmail);

	data[size].firstName = newFirst;
	data[size].lastName = newLast;
	data[size].phone = newPhone;
	data[size].email = newEmail;

	printf("new contact ");
	printcon(data[size]);
	save(fp, data, size);
	size++;

}//end newContact


void updateRecord(FILE * fp, struct contactData data[100], int size) {//updateRecord

	printf("who would you like to update?\n");

	char updateFirst[100];
	char updateLastName[100];

	
	scanf(" %s %s", updateFirst, updateLastName);
	printf("%s, %s\n", updateFirst, updateLastName);
	int index = 0;
	index = find(updateFirst, updateLastName, data, size);
	printf("What would like to update? (1 - first name, 2 - last name, 3 - phone number, 4 - email)\n");
	unsigned int * choice;
	scanf("%u", choice);

	switch(*choice) {
		case 1:
			printf("Enter first name");
			char newFirst[20];
			scanf("%s", newFirst);
			data[index].firstName = newFirst;
			break;
		case 2:
			printf("Enter last name");
			char newLast[20];
			scanf("%s", newLast);
			data[index].lastName = newLast;
			break;
		case 3:
			printf("Enter a new phone number");
			char phoneNumber[20];
			scanf("%s", phoneNumber);
			data[index].phone = phoneNumber;
			break;
		case 4:
			printf("Enter a new email\n");
			char newEmail[20];
			scanf("%s", newEmail);
			data[index].email = newEmail;
			break;
		default:
		break;

		printf("update contact ");
		printcon(data[index]);
	}

	save(fp, data, size);
}//end updateRecord

int find(char *first, char *last, const struct contactData data[100], int size) {//find

	
	for (int i = 0; i <= size; i++) {
		printf("%s, %s\n", data[i].firstName, data[i].lastName);
		if (strcmp(data[i].firstName, first) == 0 && strcmp(data[i].lastName, last) == 0) 
			return i;

	}

	printf("contact not found.\n");
	return -1;

}//end find

void deleteRecord(struct contactData data[100], int size) {//deleteRecord

	printf("Enter the name of the contact to delete:\n");
	char first[20];
	char last[20];
	scanf("%s %s", first, last);

	int i = find(first, last, data, size);
	data[i].firstName = NULL;
	data[i].lastName = NULL;
	data[i].phone = NULL;
	data[i].email = NULL;
	size--;


}//end deleteRecord

int save(FILE * fp, const struct contactData toWrite[100], int size) {//save

	printf("writing to file ..\n");

	for (int i = 0; i <= size; i++) {
		if (toWrite[i].firstName != NULL && toWrite[i].lastName != NULL && toWrite[i].phone != NULL && toWrite[i].email != NULL)
			fprintf(fp, "%s %s %s %s\n", toWrite[i].firstName, toWrite[i].lastName, toWrite[i].phone, toWrite[i].email);

	}
	printf("done.\n");

}//end save