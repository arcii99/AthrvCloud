//FormAI DATASET v1.0 Category: Educational ; Style: expert-level
#include <stdio.h>

// define struct for data
typedef struct {
    char name[50];
    int age;
    float weight;
} Person;

// function to print person data
void displayPersonData(Person person) {
    printf("Name: %s\n", person.name);
    printf("Age: %d\n", person.age);
    printf("Weight: %f\n", person.weight);
}

int main() {
    // create Person objects
    Person person1 = {"Samantha", 27, 135.5};
    Person person2 = {"Jacob", 34, 180.0};

    // display data for person1
    printf("Person 1 data:\n");
    displayPersonData(person1);

    // display data for person2
    printf("\nPerson 2 data:\n");
    displayPersonData(person2);

    return 0;
}