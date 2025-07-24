//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Structure for storing the parsed data
typedef struct {
    char name[20];
    char email[30];
    char phone[15];
} Contact;

// Function to parse the XML file and store the data in an array of Contact structures
Contact* parseXML(char* filename, int* numContacts) {
    FILE* fp;
    char buffer[BUFFER_SIZE];
    char* token;
    Contact* contacts = NULL;
    int i=0;

    if((fp=fopen(filename, "r"))==NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    while(fgets(buffer, BUFFER_SIZE, fp)!=NULL) {
        if(strstr(buffer, "<contact>")!=NULL) { // Start of a new contact
            contacts = realloc(contacts, sizeof(Contact)*(i+1));
            if(contacts==NULL) {
                printf("Error reallocating memory!\n");
                exit(1);
            }
        } else if(strstr(buffer, "<name>")!=NULL) { // Parse the name
            token = strtok(buffer, "<>");
            token = strtok(NULL, "<>");
            strcpy(contacts[i].name, token);
        } else if(strstr(buffer, "<email>")!=NULL) { // Parse the email
            token = strtok(buffer, "<>");
            token = strtok(NULL, "<>");
            strcpy(contacts[i].email, token);
        } else if(strstr(buffer, "<phone>")!=NULL) { // Parse the phone number
            token = strtok(buffer, "<>");
            token = strtok(NULL, "<>");
            strcpy(contacts[i].phone, token);
        } else if(strstr(buffer, "</contact>")!=NULL) { // End of the contact
            i++;
        }
    }

    *numContacts = i;
    fclose(fp);

    return contacts;
}

int main() {
    Contact* contacts;
    int numContacts;

    contacts = parseXML("contacts.xml", &numContacts);

    printf("Number of contacts: %d\n", numContacts);
    for(int i=0; i<numContacts; i++) {
        printf("Contact %d:\n", i+1);
        printf("Name: %s\n", contacts[i].name);
        printf("Email: %s\n", contacts[i].email);
        printf("Phone: %s\n", contacts[i].phone);
    }

    free(contacts);

    return 0;
}