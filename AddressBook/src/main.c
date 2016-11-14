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
		scanf("%[^\n]s", input);
		if (true == equals(input, "q"))
			running = false;
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

contact newcontact(char * name) {
	contact contact;
	int i = 0;
	int firstIndex = 0;
	int size = 0;
	while(name[i] != '\0') {

		if (name[i] == '\s')
			firstIndex = i;
		i++;
	}
	i++;

	char firstName[firstIndex];
	char lastName[i + 2];

	for (int j = 0; j < firstIndex; j++)
		firstName[i] = name[i];

	for (int j = firstIndex; j < i; j++)
		lastName[j - firstIndex] = name[j];

}







}