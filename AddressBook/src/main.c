#include <stdio.h>
#include <stdlib.h>
#include "contact.h"

#define true 1
#define false 0
#define FILE_NAME "contacts.dat"

typedef int bool;

void newContact(FILE * fp);
void updateRecord(FILE *fp);
contact * find(char * first, char * last, FILE * fp);

int main(void) { //repl

	FILE * fp;
	printf("opening %s ...\n", FILE_NAME);

	

	if ((fp = fopen(FILE_NAME, "rb+")) == NULL) { // check if contacts file is already there
		printf("%s does not exist, creating file ...", FILE_NAME);
		fp = fopen(FILE_NAME, "wb+");
	} // end if

	printf("Successful\n");

	while (true) {

		char * input = (char*) malloc(sizeof(char) * 10);

		scanf("%s", input);
		getchar();
		if (0 == strcmp(input, "q")) {
			printf("bye.\n");
			return 0;
		} else if (strcmp(input, "new") == 0) {
			newContact(fp);
		} else if (strcmp(input, "find") == 0) {
			char lastName[50];
			char firstName[50];
			printf("input a first and last name to search for: \n");
			scanf("%s %s", lastName, firstName);
			getchar();
			printf("stored name\n");
			struct contactData * c = {"", "", "", ""};
			if (c = find(firstName, lastName, fp) == NULL) printf("Contact not found\n");
			else {
				printcon(*c);
			}
		} else if (strcmp(input, "update") == 0) {

			updateRecord(fp);

		} else {
			printf("unrecognized command\n");
		}
	}
	return 0;
} // main

void newContact(FILE * fp) {
	printf("allocating memory ...\n");
	printf(
			"enter contact information [LAST NAME] [FIRST NAME] [9 DIGIT PHONE NUMBER] [EMAIL]:\n");

	char newLast[20]; //allocating memory for the attributes of the new contact
	char newFirst[20];
	char newPhone[20];
	char newEmail[20];
	scanf("%s %s %s %s", newFirst, newLast, newPhone, newEmail);
	getchar();

	struct contactData con = {"", "", "", ""};
	con.firstName = newFirst;
	con.lastName = newLast;
	con.phone = newPhone;
	con.email = newEmail;
	printf("new contact ");
	printcon(con);
	printf("saving contact to file ...\n");
	fseek(fp, sizeof(contact), SEEK_END);
	fwrite(&con, sizeof(contact), 1, fp);
	printf("Done.\n");

}


void updateRecord(FILE * fp) {
	printf("who would you like to update? ");
	char updateFirst[20];
	char updateLast[20];

	
	scanf(" %s %s", updateFirst, updateLast);
	printf("%s, %s", updateFirst, updateLast);

	struct contactData * current = {"", "", "", ""};
	current = find(updateFirst, updateLast, fp);
	printf("What would like to update? (1 - first name, 2 - last name, 3 - phone number, 4 - email\n");
	unsigned int * choice;
	scanf("%u", choice);

	switch(*choice) {
		case 1:
			printf("Enter first name");
			char newFirst[20];
			scanf("%s", newFirst);
			current->firstName = newFirst;
			break;
		case 2:
			printf("Enter last name");
			char newLast[20];
			scanf("%s", newLast);
			current->lastName = newLast;
			break;
		case 3:
			printf("Enter a new phone number");
			char phoneNumber[20];
			scanf("%s", phoneNumber);
			current->phone = phoneNumber;
			break;
		case 4:
			printf("Enter a new email\n");
			char newEmail[20];
			scanf("%s", newEmail);
			current->email = newEmail;
			break;
		default:
		break;
	}

	fwrite(current, sizeof(contact), 1, fp);
}

contact * find(char * first, char* last, FILE * fp) {
	contact current;
	for (int i = 0; i < 100; i++) {
		int result = fread(&current, sizeof(contact), 1, fp);
		if (strcmp(current.lastName, last) == 0) {
			if (strcmp(current.firstName, first) == 0) {
				return &current;
			}
		} else
			fseek(fp, sizeof(contact), SEEK_SET);
	}

	printf("contact not found.\n");
	return NULL;
}

void deleteRecord(FILE * fp) {

	printf("Enter the name of the contact to delete [LAST FIRST]");
	char first[20];
	char last[20];
	scanf("%s %s", first, last);
	int * poisition;

	contact * toDelete;
	toDelete = find(first, last, fp);
	toDelete->firstName = "";
	toDelete->lastName = "";
	toDelete->phone = "";
	toDelete->email = "";
}

//int saveContact(contact * c, FILE * fp)
