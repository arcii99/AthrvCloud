//FormAI DATASET v1.0 Category: Sorting ; Style: curious
#include <stdio.h>

// Define a struct named Person
typedef struct {
    char name[50];
    int age;
    float weight;
} Person;

// Define a function to swap two people
void swap(Person *p1, Person *p2) {
    Person temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

// Define a function to compare two people by age
int compareByAge(const void *p1, const void *p2) {
    Person *person1 = (Person *) p1;
    Person *person2 = (Person *) p2;
    return person1->age - person2->age;
}

// Define a function to compare two people by weight
int compareByWeight(const void *p1, const void *p2) {
    Person *person1 = (Person *) p1;
    Person *person2 = (Person *) p2;
    if (person1->weight < person2->weight) {
        return -1;
    } else if (person1->weight > person2->weight) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    printf("Welcome to the People Sorter 2000!\n");
    printf("We will sort some people by age and weight.\n");

    // Create an array of people to sort
    Person people[5] = {
        {"Alice", 25, 125.5},
        {"Bob", 30, 150.0},
        {"Charlie", 20, 100.2},
        {"David", 35, 175.7},
        {"Eve", 28, 135.3}
    };

    // Print the unsorted list of people
    printf("Before sorting:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s, %d years old, %.1f kg\n", people[i].name, people[i].age, people[i].weight);
    }

    // Sort the people by age
    qsort(people, 5, sizeof(Person), compareByAge);

    // Print the sorted list of people
    printf("After sorting by age:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s, %d years old, %.1f kg\n", people[i].name, people[i].age, people[i].weight);
    }

    // Sort the people by weight
    qsort(people, 5, sizeof(Person), compareByWeight);

    // Print the sorted list of people
    printf("After sorting by weight:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s, %d years old, %.1f kg\n", people[i].name, people[i].age, people[i].weight);
    }

    printf("Thank you for using the People Sorter 2000!\n");
    return 0;
}