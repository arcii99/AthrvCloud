//FormAI DATASET v1.0 Category: Sorting ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Define a custom struct to hold person information
typedef struct {
    int age;
    char* name;
} Person;

// Define a custom comparison function for sorting People by age
int compare_age(const void* a, const void* b) {
    const Person* pa = (const Person*)a;
    const Person* pb = (const Person*)b;

    if (pa->age < pb->age) {
        return -1;
    } else if (pa->age > pb->age) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    // Create an array of people with random ages and names
    Person people[] = {
        {23, "Alice"},
        {44, "Bob"},
        {31, "Charlie"},
        {19, "David"},
        {55, "Eve"},
        {27, "Frank"}
    };

    int num_people = sizeof(people) / sizeof(people[0]);

    // Print the unsorted list of people
    printf("Unsorted People:\n");
    for (int i = 0; i < num_people; i++) {
        printf("%s (%d)\n", people[i].name, people[i].age);
    }

    // Sort the array of people by age using the custom comparison function
    qsort(people, num_people, sizeof(Person), compare_age);

    // Print the sorted list of people
    printf("\nSorted People:\n");
    for (int i = 0; i < num_people; i++) {
        printf("%s (%d)\n", people[i].name, people[i].age);
    }

    return 0;
}