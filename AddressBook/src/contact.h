#ifndef CONTACT_H_
#define CONTACT_H_


typedef struct contact {
	
	char * first_name;
	char * last_name;
	char * phone_number;
	char * email;
	char * address;

} contact; // contact

void printcon(contact c);


#endif // CONTACT_H_