//FormAI DATASET v1.0 Category: Sorting ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for person
typedef struct Person {
    char name[50];
    int age;
} Person;

// Function to compare two people by age
int compareAge(const void *p1, const void *p2) {
    Person *person1 = (Person *)p1;
    Person *person2 = (Person *)p2;
    return person1->age - person2->age;
}

// Function to compare two people by name (alphabetical order)
int compareName(const void *p1, const void *p2) {
    Person *person1 = (Person *)p1;
    Person *person2 = (Person *)p2;
    return strcmp(person1->name, person2->name);
}

int main() {
    // Create an array of people
    Person people[5] = {
        {"John", 20},
        {"Mary", 25},
        {"Bob", 30},
        {"Jane", 22},
        {"Tom", 18}
    };
    
    // Print unsorted array
    printf("Unsorted Array:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s, %d\n", people[i].name, people[i].age);
    }
    
    // Sort array by age using qsort()
    qsort(people, 5, sizeof(Person), compareAge);
    
    // Print sorted array by age
    printf("\nSorted Array by Age:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s, %d\n", people[i].name, people[i].age);
    }
    
    // Sort array by name using qsort()
    qsort(people, 5, sizeof(Person), compareName);
    
    // Print sorted array by name
    printf("\nSorted Array by Name:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s, %d\n", people[i].name, people[i].age);
    }
    
    return 0;
}