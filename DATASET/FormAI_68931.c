//FormAI DATASET v1.0 Category: Sorting ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int age;
    char name[50];
} Person;

int compare_person(const void* a, const void* b) {
    return ((Person*)a)->age - ((Person*)b)->age;
}

void sort_people(Person* people, int length) {
    qsort(people, length, sizeof(Person), compare_person);
}

int main() {
    Person people[5] = {
        { 29, "Alice" },
        { 45, "Bob" },
        { 15, "Charlie" },
        { 76, "David" },
        { 37, "Emily" }
    };
    
    printf("Before sorting:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d: %s\n", people[i].age, people[i].name);
    }
    
    sort_people(people, 5);
    
    printf("After sorting:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d: %s\n", people[i].age, people[i].name);
    }
    
    return 0;
}