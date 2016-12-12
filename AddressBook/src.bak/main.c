#include <stdio.h>
#include <stdlib.h>
#include "contact.h"

#define true 1
#define false 0
#define FILE_NAME "contacts.dat"

typedef int bool;

void newContact(FILE * fp);
void updateRecord(FILE *fp);
int find(char * first, char * last, FILE * fp, struct contactData *rPtr);

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
			if (find(firstName, lastName, fp, c) == NULL) printf("Contact not found\n");
			else {
				printcon(*c);
			}
		} else if (strcmp(input, "update") == 0) {

			updateRecord(fp);

		} else if (strcmp(input, "remove") == 0) {
			deleteRecord(fp);
		} else {
			printf("unrecognized command\n");
		}
	}
	return 0;
} // main

void newContact(FILE * fp) {
	fseek(fp, 0, SEEK_SET);
	printf(
			"enter contact information [LAST NAME] [FIRST NAME] [9 DIGIT PHONE NUMBER] [EMAIL]:\n");

	char newLast[20]; //allocating memory for the attributes of the new contact
	char newFirst[20];
	char newPhone[20];
	char newEmail[20];
	scanf("%s %s %s %s", newFirst, newLast, newPhone, newEmail);
	

	struct contactData con = {"", "", "", ""};
	con.firstName = newFirst;
	con.lastName = newLast;
	con.phone = newPhone;
	con.email = newEmail;
	printf("new contact ");
	printcon(con);
	printf("saving contact to file ...\n");
	fwrite(&con, sizeof(struct contactData), 1, fp);
	printf("Done.\n");
}


void updateRecord(FILE * fp) {
	printf("who would you like to update?\n");

	char updateFirst[100];
	char updateLastName[100];

	
	scanf(" %s %s", updateFirst, updateLastName);
	printf("%s, %s\n", updateFirst, updateLastName);
	struct contactData newContact = {"", "", "", ""};
	printf("created new empty contact\n");
	struct contactData *current;
	current = &newContact;
	printf("assigned struct pointrer to constact address\n");
	if (find(updateFirst, updateLastName, fp, current) == 0) return;
	printcon(*current);
	printf("What would like to update? (1 - first name, 2 - last name, 3 - phone number, 4 - email)\n");
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

int find(char *first, char *last, FILE *fp, struct contactData *rPtr) {
	fseek(fp, 0, SEEK_SET);
	struct contactData currentContact = {"", "", "", ""};
	printf("created empty contact\n");

	printf("assigned pointer struct to emtpy struct address\n");
	for (int i = 1; i <= 100; i++) {
		printf("reading from file\n");
		printf("Bytes read: %lu\n", fread(&currentContact, sizeof(struct contactData), 1, fp));
		printcon(currentContact);
		if (strcmp(currentContact.lastName, last) == 0 && strcmp(currentContact.firstName, first) == 0) {
			
			printf("found contact, returning address\n");
			rPtr = &currentContact;
			return 1;
			printf("moving on ... \n");
		}
		fseek(fp, (sizeof(struct contactData) * i) - 1, SEEK_SET);
	}

	printf("contact not found.\n");
	return 0;
}

void deleteRecord(FILE * fp) {
	printf("Enter the name of the contact to delete:\n");
	char first[20];
	char last[20];
	scanf("%s %s", first, last);

	struct contactData toDelete;
	if (find(first, last, fp, &toDelete) == 0) return;
	toDelete.firstName = "";
	toDelete.lastName = "";
	toDelete.phone = "";
	toDelete.email = "";
	fwrite(&toDelete, sizeof(struct contactData), 1, fp );
}

