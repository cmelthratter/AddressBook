#include <stdio.h>
#include "contact.h"

#define true 1
#define false 0

typedef int bool;

int equals(const char* str1, const char *str);
contact newcontact(char * name);

int main(void) {//repl
	bool running = true;
	while(running == true) {
		
		char input[] = "";
		scanf("%s", input);
		if (true == equals(input, "q")) {
			running = false;
			continue;
		} else if (equals(input, "new") == true) {
			contact contact = fromname(input);
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

contact newcontact(char * str) {
	contact contact;
	
	char * data = strtok(str, ' ');

	contact.first_name = data[0];
	contact.last_name = data[1];
	contact.phone_number = data[2];
	contact.email = data[3];
	contact.address = data[4];
	contact.website = data[5];

	return contact;
}

contact fromname(char *  str) {

	char * data = strtok(str, ' ');
	contact contact;

	contact.first_name = data[0];
	contact.last_name = data[1];

	return contact;
}
