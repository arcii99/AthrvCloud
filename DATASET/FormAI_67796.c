//FormAI DATASET v1.0 Category: Database simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    int id;
    char name[50];
    int age;
};

int main() {
    int num_persons;
    printf("How many persons do you want to add to the database? ");
    scanf("%d", &num_persons);
    printf("\n");

    struct Person *persons = malloc(num_persons * sizeof(struct Person));

    for (int i = 0; i < num_persons; i++) {
        struct Person new_person;
        printf("Enter data for person %d:\n", i+1);
        printf("ID: ");
        scanf("%d", &new_person.id);
        printf("Name: ");
        scanf("%s", new_person.name);
        printf("Age: ");
        scanf("%d", &new_person.age);
        printf("\n");

        *(persons + i) = new_person;
    }

    printf("Database contents:\n\n");
    printf("| %-3s | %-20s | %-3s |\n", "ID", "Name", "Age");
    printf("|----|--------------------|----|\n");
    for (int i = 0; i < num_persons; i++) {
        struct Person current_person = *(persons + i);
        printf("| %-3d | %-20s | %-3d |\n", current_person.id, current_person.name, current_person.age);
    }

    free(persons);

    return 0;
}