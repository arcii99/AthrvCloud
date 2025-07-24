//FormAI DATASET v1.0 Category: Database querying ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    char city[50];
    char country[50];
} Person;

int main() {
    // Create an array of Persons
    Person people[5] = {
        {"Alice", 25, "New York City", "USA"},
        {"Bob", 32, "London", "UK"},
        {"Charlie", 47, "Toronto", "Canada"},
        {"Dave", 19, "Sydney", "Australia"},
        {"Eve", 56, "Tokyo", "Japan"}
    };

    // Find all people who live in Canada
    printf("People who live in Canada:\n");
    for (int i = 0; i < 5; i++) {
        if (strcmp(people[i].country, "Canada") == 0) {
            printf("%s, %d, %s, %s\n", people[i].name, people[i].age, people[i].city, people[i].country);
        }
    }
    printf("\n");

    // Find the oldest person
    int max_age = 0;
    char oldest_person[50];
    for (int i = 0; i < 5; i++) {
        if (people[i].age > max_age) {
            max_age = people[i].age;
            strcpy(oldest_person, people[i].name);
        }
    }
    printf("The oldest person is %s, age %d\n\n", oldest_person, max_age);

    // Update Eve's age to 57
    for (int i = 0; i < 5; i++) {
        if (strcmp(people[i].name, "Eve") == 0) {
            people[i].age = 57;
            break;
        }
    }

    // Display all people's information after update
    printf("All people's information after update:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s, %d, %s, %s\n", people[i].name, people[i].age, people[i].city, people[i].country);
    }

    return 0;
}