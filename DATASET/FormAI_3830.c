//FormAI DATASET v1.0 Category: Sorting ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for our data elements
typedef struct {
    int age;
    char name[20];
} Person;

// Define a comparison function used by qsort to compare two Person structs
int comparePersons(const void *a, const void *b) {
    // Cast the void pointers to Person pointers
    const Person *personA = (Person*)a;
    const Person *personB = (Person*)b;
    
    // Compare the ages
    if (personA->age > personB->age) {
        return 1;
    }
    else if (personA->age < personB->age) {
        return -1;
    }
    else {
        // If ages are equal, compare names
        return strcmp(personA->name, personB->name);
    }
}

// Print out an array of Persons
void printPersons(Person people[], int numPeople) {
    for (int i = 0; i < numPeople; i++) {
        printf("%d %s\n", people[i].age, people[i].name);
    }
}

int main() {
    // Initialize an array of Persons
    Person people[] = {
        {32, "Alice"},
        {25, "Bob"},
        {33, "Charlie"},
        {43, "David"},
        {25, "Eve"}
    };
    
    // Compute the number of People in the array
    int numPeople = sizeof(people) / sizeof(people[0]);
    
    // Print out the unsorted array
    printf("Unsorted:\n");
    printPersons(people, numPeople);
    
    // Sort the array using qsort and our comparison function
    qsort(people, numPeople, sizeof(Person), comparePersons);
    
    // Print out the sorted array
    printf("Sorted:\n");
    printPersons(people, numPeople);
    
    return 0;
}