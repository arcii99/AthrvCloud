//FormAI DATASET v1.0 Category: Database querying ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_QUERY_LENGTH 100

struct survivor {
    char name[50];
    int age;
    char location[50];
    char occupation[50];
};

void print_survivor(struct survivor s) {
    printf("Name: %s\n", s.name);
    printf("Age: %d\n", s.age);
    printf("Location: %s\n", s.location);
    printf("Occupation: %s\n", s.occupation);
    printf("\n");
}

void init_database(struct survivor* database) {
    strcpy(database[0].name, "John");
    database[0].age = 32;
    strcpy(database[0].location, "New York");
    strcpy(database[0].occupation, "Doctor");

    strcpy(database[1].name, "Sarah");
    database[1].age = 25;
    strcpy(database[1].location, "Chicago");
    strcpy(database[1].occupation, "Nurse");

    strcpy(database[2].name, "David");
    database[2].age = 45;
    strcpy(database[2].location, "Los Angeles");
    strcpy(database[2].occupation, "Police Officer");

    strcpy(database[3].name, "Emily");
    database[3].age = 20;
    strcpy(database[3].location, "Seattle");
    strcpy(database[3].occupation, "Student");

    strcpy(database[4].name, "Michael");
    database[4].age = 38;
    strcpy(database[4].location, "Miami");
    strcpy(database[4].occupation, "Engineer");
}

int main() {
    struct survivor database[MAX_RECORDS];
    init_database(database);

    char query[MAX_QUERY_LENGTH];

    printf("Welcome to the survivor database.\n\n");

    while (1) {
        printf("Enter a query: ");
        fgets(query, MAX_QUERY_LENGTH, stdin);
        query[strlen(query) - 1] = '\0'; // remove newline character
        
        if (strcmp(query, "exit") == 0) {
            printf("Exiting program.\n");
            break;
        } else if (strcmp(query, "list all survivors") == 0) {
            printf("--- All Survivors ---\n");
            for (int i = 0; i < MAX_RECORDS; i++) {
                if (strlen(database[i].name) > 0) {
                    print_survivor(database[i]);
                }
            }
        } else if (strcmp(query, "list survivors by location") == 0) {
            printf("Enter a location: ");
            char location[50];
            fgets(location, 50, stdin);
            location[strlen(location) - 1] = '\0'; // remove newline character
            printf("--- Survivors in %s ---\n", location);
            for (int i = 0; i < MAX_RECORDS; i++) {
                if (strcmp(database[i].location, location) == 0) {
                    print_survivor(database[i]);
                }
            }
        } else if (strcmp(query, "list survivors by occupation") == 0) {
            printf("Enter an occupation: ");
            char occupation[50];
            fgets(occupation, 50, stdin);
            occupation[strlen(occupation) - 1] = '\0'; // remove newline character
            printf("--- Survivors who were %s ---\n", occupation);
            for (int i = 0; i < MAX_RECORDS; i++) {
                if (strcmp(database[i].occupation, occupation) == 0) {
                    print_survivor(database[i]);
                }
            }
        } else {
            printf("Query not recognized.\n");
        }
    }

    return 0;
}