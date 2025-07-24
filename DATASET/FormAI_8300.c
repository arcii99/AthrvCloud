//FormAI DATASET v1.0 Category: Sorting ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Defining a structure to represent a person
struct Person {
    char name[20];
    int age;
};

// A function to compare two Person structures based on their age
int compareAge(const void *A, const void *B) {
    const struct Person *pA = A, *pB = B;
    if (pA->age > pB->age)
        return 1;
    else if (pA->age < pB->age)
        return -1;
    else
        return 0;
}

// A function to compare two Person structures based on their name
int compareName(const void *A, const void *B) {
    const struct Person *pA = A, *pB = B;
    return strcmp(pA->name, pB->name);
}

int main() {
    // Creating an array of Person structures
    struct Person people[] = {
        {"Alice", 25},
        {"Bob", 18},
        {"Charlie", 36},
        {"David", 22},
        {"Eve", 29},
        {"Frank", 40},
        {"Grace", 31},
        {"Henry", 20},
        {"Isabelle", 27}
    };
    int numPeople = sizeof(people) / sizeof(people[0]);
    
    // Sorting the array of people by age using qsort
    qsort(people, numPeople, sizeof(struct Person), compareAge);
    printf("People sorted by age:\n");
    for (int i = 0; i < numPeople; i++)
        printf("%s, %d\n", people[i].name, people[i].age);
    
    // Sorting the array of people by name using qsort
    qsort(people, numPeople, sizeof(struct Person), compareName);
    printf("\nPeople sorted by name:\n");
    for (int i = 0; i < numPeople; i++)
        printf("%s, %d\n", people[i].name, people[i].age);
    
    return 0;
}