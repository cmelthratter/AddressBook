#include <stdio.h>
#include <stdlib.h>
#include "contact.h"

#define true 1
#define false 0
#define MAX_CONTACTS 100
#define FILE_NAME "contacts.dat"
#ifndef NULL
#define NULL ((void *) 0)
#endif

typedef int bool;

void newContact(FILE * fp);
void updateRecord(FILE *fp);
contact * fromName(char * last, char * first);
contact * find(char * name, FILE * fp);

int main(void) { //repl

	contact emptyC = { "", "", "", "" };
	FILE * fp;
	bool newFile = false; //boolean to check if we created a new file
	printf("opening %s ...\n", FILE_NAME);

	if ((fp = fopen(FILE_NAME, "rb+")) == NULL) { // check if contacts file is already there
		printf("%s does not exist, creating file ...", FILE_NAME);
		newFile = true;
		fp = fopen(FILE_NAME, "wb+");
	} // end if

	printf("Successful\n");

	if (newFile == true) //if new file was created, write 100 empty contact records.
		for (int i = 0; i < MAX_CONTACTS; i++)
			fwrite(&emptyC, sizeof(contact), 1, fp);
	contact currentContact = emptyC;
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
			printf("input a last name to search for: \n");
			scanf("%s", lastName);
			printf("stored name\n");
			contact * c = find(lastName, fp);

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
	char phone[20];
	char email[20];
	scanf("%s", newLast);

	printf("stored name\n");

	contact * con;
	con = {newFirst, newLast, phone, email};
	printf("new contact ");
	printcon(*con);

	fseek(fp, sizeof(contact), SEEK_END);
	fwrite(con, sizeof(contact), 1, fp);

}

contact * fromName(char * last, char * first) {

	printf("%s, %s", last, first);
	contact * c = { last, first, "", "", "" };

	return c;
}

void updateRecord(FILE * fp) {
	printf("who would you like to update?");
	char first[20];
	char last[20];
	scanf("%s %s",last, first );
	contact * current = find(first, last, fp);
	printf("What would like to update? (1 - first name, 2 - last name, 3 - phone number, 4 - email\n");
	unsigned int * choice;
	scanf("%u", choice);

	switch(choice) {
		case 1:
			printf("Enter first name");
			char newName[20];
			scanf("%s", newName);
			current->firstName = newName;
	}
}

contact * find(char * first, char* last, FILE * fp) {
	contact current;
	for (int i = 0; i < 100; i++) {
		int result = fread(&current, sizeof(contact), 1, fp);
		if (strcmp(current.lastName, last) == 0) {
			if (strcmp(current.firstName, first) == 0)
				return &current;
		} else
			fseek(fp, sizeof(contact), SEEK_SET);
	}

	printf("contact not found.\n");
	return NULL;
}

//int saveContact(contact * c, FILE * fp)
