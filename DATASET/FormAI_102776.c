//FormAI DATASET v1.0 Category: Mailing list manager ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_EMAILS 1000
#define MAX_LEN 100

typedef struct{
    char name[MAX_LEN];
    char email[MAX_LEN];
}Contact;

int main(){
    Contact ContactList[MAX_EMAILS];
    char line[MAX_LEN];
    int numContacts = 0;

    FILE* inputFile = fopen("email_list.txt", "r");
    if(inputFile == NULL){
        printf("Error opening file.\n");
        exit(1);
    }

    while(fgets(line, MAX_LEN, inputFile)){
        char* name = strtok(line, ",");
        char* email = strtok(NULL, ",");
        if(name && email){
            strcpy(ContactList[numContacts].name, name);
            strcpy(ContactList[numContacts].email, email);
            numContacts++;
        }
    }
    fclose(inputFile);

    printf("Contact List:\n");
    for(int i = 0; i < numContacts; i++){
        printf("%s, %s\n", ContactList[i].name, ContactList[i].email);
    }

    char newContact[MAX_LEN];
    printf("Enter new contact in the format name,email: ");
    fgets(newContact, MAX_LEN, stdin);
    newContact[strcspn(newContact, "\n")] = '\0';
    char* name = strtok(newContact, ",");
    char* email = strtok(NULL, ",");
    if(name && email){
        if(numContacts >= MAX_EMAILS){
            printf("Maximum number of contacts reached.\n");
            exit(1);
        }
        strcpy(ContactList[numContacts].name, name);
        strcpy(ContactList[numContacts].email, email);
        numContacts++;
    }

    FILE* outputFile = fopen("updated_list.txt", "w");
    if(outputFile == NULL){
        printf("Error opening file.\n");
        exit(1);
    }

    for(int i = 0; i < numContacts; i++){
        fprintf(outputFile, "%s,%s\n", ContactList[i].name, ContactList[i].email);
    }
    fclose(outputFile);

    printf("Updated contact list saved to updated_list.txt.\n");
    return 0;
}