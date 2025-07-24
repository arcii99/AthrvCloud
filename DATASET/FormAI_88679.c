//FormAI DATASET v1.0 Category: Database simulation ; Style: imaginative
#include<stdio.h> // header file for standard input-output
#include<stdlib.h> // header file for standard library functions

/* struct definition to create a simulation of a database */
struct database {
    char* name;
    int age;
    char* email;
};

int main() {
    struct database db[5]; // Creating an array of 5 database records
    
    // Taking inputs for the database records from the user
    for(int i=0;i<5;i++) {
        db[i].name = (char*) malloc(100); // Allocating memory of size 100 for the name
        db[i].email = (char*) malloc(100); // Allocating memory of size 100 for the email
        printf("Enter the name of person %d: ", i+1);
        scanf("%s", db[i].name);
        printf("Enter the age of person %d: ", i+1);
        scanf("%d", &db[i].age);
        printf("Enter the email id of person %d: ", i+1);
        scanf("%s", db[i].email);
        printf("\n");
    }
    
    // Displaying the contents of the database
    printf("Displaying the database records\n");
    for(int i=0;i<5;i++) {
        printf("Name: %s\n", db[i].name);
        printf("Age: %d\n", db[i].age);
        printf("Email: %s\n\n", db[i].email);
        free(db[i].name); // Freeing the memory allocated for name
        free(db[i].email); // Freeing the memory allocated for email
    }
    return 0;
}