#include <stdio.h>
#include <stdlib.h>
#include "contact.h"

void princon(contact c);

int main() {
	return 0;
}

void printcon(contact c) {
	printf("%s, %s, %s, %s, %s, %s\n", c.last_name, c.first_name, c.phone_number, c.email, c.address, c.website);
}
