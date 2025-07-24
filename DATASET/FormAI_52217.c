//FormAI DATASET v1.0 Category: Database querying ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Struct for defining a person */
typedef struct person {
    int id;
    char name[50];
    int age;
    char email[100];
} Person;

/* Function for querying the database */
void queryDatabase(char *name, int age) {
    /* Open the database connection */
    FILE *db = fopen("database.txt", "r");
    if (db == NULL) {
        printf("Unable to open database");
        return;
    }

    /* Initialize a counter */
    int count = 0;

    /* Loop through each person in the database */
    Person p;
    while (fread(&p, sizeof(Person), 1, db)) {
        /* Check if the name and age match */
        if (strcmp(name, p.name) == 0 && age == p.age) {
            /* Print the details of the person */
            printf("ID: %d\n", p.id);
            printf("Name: %s\n", p.name);
            printf("Age: %d\n", p.age);
            printf("Email: %s\n", p.email);

            /* Increment the counter */
            count++;
        }
    }

    /* Close the database connection */
    fclose(db);

    /* Print a message if no matches were found */
    if (count == 0) {
        printf("No matches found.\n");
    }
}

/* Function for adding a person to the database */
void addPerson(Person p) {
    /* Open the database connection */
    FILE *db = fopen("database.txt", "a");
    if (db == NULL) {
        printf("Unable to open database");
        return;
    }

    /* Write the person to the database */
    fwrite(&p, sizeof(Person), 1, db);

    /* Close the database connection */
    fclose(db);

    /* Print a message to confirm the person was added */
    printf("Person added to database.\n");
}

/* Function for deleting a person from the database */
void deletePerson(int id) {
    /* Open the database connection */
    FILE *db = fopen("database.txt", "r");
    if (db == NULL) {
        printf("Unable to open database");
        return;
    }

    /* Create a temporary file for writing updated data */
    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        printf("Unable to create temp file");
        fclose(db);
        return;
    }

    /* Initialize a counter */
    int count = 0;

    /* Loop through each person in the database */
    Person p;
    while (fread(&p, sizeof(Person), 1, db)) {
        /* Check if the ID matches */
        if (p.id == id) {
            /* Increment the counter */
            count++;
        } else {
            /* Write the person to the temporary file */
            fwrite(&p, sizeof(Person), 1, temp);
        }
    }

    /* Close the database connections */
    fclose(db);
    fclose(temp);

    /* Delete the original database file */
    remove("database.txt");

    /* Rename the temporary file to the original database file */
    rename("temp.txt", "database.txt");

    /* Print a message to confirm the person was deleted */
    if (count == 0) {
        printf("Person not found in database.\n");
    } else {
        printf("Person deleted from database.\n");
    }
}

/* Main function for testing */
int main() {
    /* Create some example persons */
    Person p1 = {1, "John Smith", 35, "johnsmith@example.com"};
    Person p2 = {2, "Jane Doe", 28, "janedoe@example.com"};
    Person p3 = {3, "Bob Johnson", 42, "bobjohnson@example.com"};
    Person p4 = {4, "Alice Williams", 51, "alicewilliams@example.com"};

    /* Add the example persons to the database */
    addPerson(p1);
    addPerson(p2);
    addPerson(p3);
    addPerson(p4);

    /* Query the database for a person with matching name and age */
    queryDatabase("Jane Doe", 28);

    /* Delete a person from the database */
    deletePerson(3);

    /* Query the database again to confirm the person was deleted */
    queryDatabase("Bob Johnson", 42);

    return 0;
}