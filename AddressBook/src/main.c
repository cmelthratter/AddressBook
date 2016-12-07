#include <stdio.h>
#include <stdlib.h>
#include "contact.h"

#define true 1
#define false 0
#define MAX_CONTACTS 100
#define FILE_NAME "contacts.dat"

typedef int bool;

void  newContact(FILE * fp);
contact * fromName(char * last, char * first);
contact * find(char * name, FILE * fp);

int main(void) {//repl

	contact emptyC = {"", "", "", ""};
	FILE * fp; 
	bool newFile = false;//boolean to check if we created a new file
	printf("opening %s ...\n", FILE_NAME);

	if ( ( fp = fopen(FILE_NAME, "rb+") ) == NULL) {// check if contacts file is already there
		printf("%s does not exist, creating file ...", FILE_NAME);
		newFile = true;
		fp = fopen(FILE_NAME, "wb+");
	}// end if 

	printf("Successful\n");


	if (newFile == true)//if new file was created, write 100 empty contact records.
		for (int i = 0; i < MAX_CONTACTS; i++) 
			fwrite(&emptyC, sizeof(contact), 1, fp);
	contact currentContact = emptyC;
	while(true) {
		
		char  * input = (char*) malloc(sizeof(char) * 10);

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
}// main

void newContact(FILE * fp) {
	printf("allocating memory ...\n");
	printf("enter contact information [LAST NAME] [FIRST NAME] [9 DIGIT PHONE NUMBER] [EMAIL]:\n");
	char * sentence = (char*) malloc(sizeof(char) * 100);
	char * newLast[20];
	char newFirst[20];
	char phone[20];
	char email[20];
	scanf("%s", sentence, );
	
	printf("stored name\n");

	contact * con;
	con = fromName(newLast, newFirst);
	printf("new contact ");
	printcon(*con);

}

contact * fromName(char * last, char * first) {

	printf("%s, %s", last, first);
	contact * c = {*last, *first, "", "", ""};

	return c;
}

contact * find(char * name, FILE * fp) {
	
	for (int i = 0; i < 100; i++) {
		//result = fread(&c, sizeof(contact), 1, fp);
		//f (strcmp(c.lastName, data[1]) == 0)
			//if (strcmp(c.firstName, data[0]) == 0) return &c;

		//else fseek(fp, sizeof(contact), SEEK_SET);
	}
	printf("contact not found.\n");
	return NULL;
}

//int saveContact(contact * c, FILE * fp)
