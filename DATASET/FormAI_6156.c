//FormAI DATASET v1.0 Category: Sorting ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// The struct represents a person with a name and age
typedef struct {
    char name[50];
    int age;
} person;

// Function to compare two persons based on their age
int compare_age(const void *p1, const void *p2) {
    const person *person1 = p1;
    const person *person2 = p2;
    return person1->age - person2->age;
}

// Function to compare two persons based on their name
int compare_name(const void *p1, const void *p2) {
    const person *person1 = p1;
    const person *person2 = p2;
    return strcmp(person1->name, person2->name);
}

int main() {
    int num_people = 5;
    person people[num_people];

    // Populate the array with some example data
    strcpy(people[0].name, "Alice");
    people[0].age = 30;
    strcpy(people[1].name, "Bob");
    people[1].age = 25;
    strcpy(people[2].name, "Charlie");
    people[2].age = 40;
    strcpy(people[3].name, "David");
    people[3].age = 20;
    strcpy(people[4].name, "Emily");
    people[4].age = 35;

    // Sort the array by age
    qsort(people, num_people, sizeof(person), compare_age);

    // Print the sorted results
    printf("Sorted by age:\n");
    for (int i = 0; i < num_people; i++) {
        printf("%s - %d\n", people[i].name, people[i].age);
    }

    // Sort the array by name
    qsort(people, num_people, sizeof(person), compare_name);

    // Print the sorted results
    printf("Sorted by name:\n");
    for (int i = 0; i < num_people; i++) {
        printf("%s - %d\n", people[i].name, people[i].age);
    }

    return 0;
}