//FormAI DATASET v1.0 Category: Sorting ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// define a struct for a person
typedef struct Person {
    char name[20];
    int age;
    double height;
} Person;

// define a sorting function to sort people by age
int compareByAge(const void *a, const void *b) {
    Person *personA = (Person *)a;
    Person *personB = (Person *)b;
    return personA->age - personB->age;
}

int main() {
    // create an array of people
    Person people[5] = {
        {"Alice", 27, 1.68},
        {"Bob", 32, 1.82},
        {"Charlie", 23, 1.73},
        {"David", 29, 1.79},
        {"Emma", 25, 1.65}
    };

    // print out the unsorted array
    printf("Before sorting by age:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s is %d years old and is %.2f meters tall.\n", people[i].name, people[i].age, people[i].height);
    }

    // sort the array by age using qsort
    qsort(people, 5, sizeof(Person), compareByAge);

    // print out the sorted array
    printf("\nAfter sorting by age:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s is %d years old and is %.2f meters tall.\n", people[i].name, people[i].age, people[i].height);
    }

    return 0;
}