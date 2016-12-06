#include <stdio.h>
#include "contact.h"

#define true 1
#define false 0
#define MAX_CONTACTS 100
#define FILE_NAME "contacts.dat"
#define EMPTY_CONTACT {"", "", "", "", ""};

typedef int bool;

contact * newContact(char * str);
contact * fromName(char * str);
contact * find(char * name, FILE * fp);

int main(void) {//repl
	contact emptyC = EMPTY_CONTACT;
	FILE * fp;
	bool newFile = false;
	printf("opening %s ...\n", FILE_NAME);
	if ( ( fp = fopen(FILE_NAME, "rb+") ) == NULL) {
		printf("%s does not exists, creating file ...", FILE_NAME);
		newFile = true;
		fp = fopen(FILE_NAME, "wb+");
	}
	printf("Successful\n");
	if (newFile == true)
		for (int i = 0; i < MAX_CONTACTS; i++) 
			fwrite(&emptyC, sizeof(contact), 1, fp);
	bool running = true;
	while(running == true) {
		
		char input[] = "";
		scanf("%s", input);
		if (0 == strcmp(input, "q")) {
			printf("bye.\n");
			return;
		} else if (strcmp(input, "new") == 0) {
			char * new;
			printf("enter a name for your contact: ");
			scanf("%s", new);
			contact * c = fromName(new);
			printf("new contact ");
			printcon(*c);
			//saveContact(c, fp);
		} else if (strcmp(input, "find") == 0) {
			char * lastName;
			printf("input a last name to search for: \n");
			scanf("%s", lastName);
			contact * c = find(lastName, fp);

		}
		else {
			printf("unrecognized command\n");
		}
	}
	return 0;
}// main

contact * newContact(char * str) {
	
	
	char * data = strtok(str, " ");
	

	contact * c = {data[0], data[1], data[2], data[3], data[4]};


	return c;
}

contact * fromName(char *  str) {

	char * lastName = strtok(str, " ");
	char * firstName = strtok(NULL, " ");
	printf("%s, %s", lastName, firstName);
	contact * c = {lastName, firstName, "", "", ""};

	return c;
}

contact * find(char * name, FILE * fp) {
	fseek(fp, 0, SEEK_SET);
	char * data = strtok(name, ' ');
	contact c;
	int result;
	for (int i = 0; i < 100; i++) {
		result = fread(&c, sizeof(contact), 1, fp);
		if (strcmp(c.lastName, data[1]) == 0)
			if (strcmp(c.firstName, data[0]) == 0) return &c;

		else fseek(fp, sizeof(contact), SEEK_SET);
	}
	printf("contact not found.\n");
	return NULL;
}

//int saveContact(contact * c, FILE * fp)
