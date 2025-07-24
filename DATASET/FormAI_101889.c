//FormAI DATASET v1.0 Category: Educational ; Style: Dennis Ritchie
#include <stdio.h>

/* Define a struct to represent a person */
struct Person {
    char *name;
    int age;
};

int main() {
    /* Create an array of Person structs */
    struct Person people[3];

    /* Fill the array with data */
    people[0].name = "Bob";
    people[0].age = 25;

    people[1].name = "Alice";
    people[1].age = 30;

    people[2].name = "Charlie";
    people[2].age = 20;

    /* Loop through the array and print out each person's information */
    for (int i = 0; i < 3; i++) {
        printf("%s is %d years old.\n", people[i].name, people[i].age);
    }

    return 0;
}