#include <stdio.h>
#include <stdlib.h>
#include "contact.h"

void printcon(contact c);


void printcon(contact c) {
	printf("%s, %s, %s, %s, %s, %s\n", c.lastName, c.firstName, c.phoneNumber, c.email, c.address);
}

