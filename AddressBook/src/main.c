#include <stdio.h>
#include "contact.h"

#define true 1
#define false 0
#define MAX_CONTACTS 100
#define FILE_NAME "contacts.dat"

typedef int bool;

int equals(const char* str1, const char *str);

contact newContact(char * name);
contact fromName(char * name);

int main(void) {//repl
	FILE * fp;
	fp = fopen(FILE_NAME, "bw+");
	for ( int i = 0; i < MAX_CONTACTS; i++ ) {

	}
	bool running = true;
	while(running == true) {
		
		char input[] = "";
		scanf("%s", input);
		if (true == equals(input, "q")) {
			printf("bye.\n");
			return;
		} else if (equals(input, "new") == true) {
			contact contact = from_name(input);
			printf("new contact ");
			printcon(contact);
		} else if (equals(input, "find") == true) {

		}
		else {
			printf("unrecognized command\n");
		}
	}
	return 0;
}// main

// compares two string, return true(1) or false(0)
int equals(const char * str1, const char * str2) {
	
	for (int i = 0; i < 1; i++) {
		if (str1[i] != str2[i])
			return false;
	}

	return true;
}// equals

contact newContact(char * str) {
	
	
	char * data = strtok(str, ' ');

	contact contact = {data[0], data[1], data[2], data[3], data[4]};

	return contact;
}

contact fromName(char *  str) {

	char * data = strtok(str, ' ');
	contact contact = {data[0], data[1], "", "", ""};

	return contact;
}

contact find(char * lastName) {

	for (int i = 0; i < 100; i++) {

	}
}
