#ifndef CONTACT_H_
#define CONTACT_H_


typedef struct contactData {
	
	char * firstName;
	char * lastName;
	char * phone;
	char * email;

} contact; // contact

void printcon(contact c);


#endif // CONTACT_H_