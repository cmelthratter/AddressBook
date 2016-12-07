#ifndef CONTACT_H_
#define CONTACT_H_


typedef struct contact {
	
	char * firstName;
	char * lastName;
	char * phone;
	char * email;

} contact; // contact

void printcon(contact c);


#endif // CONTACT_H_