//FormAI DATASET v1.0 Category: Data structures visualization ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

/* Define our custom data structure */
struct person {
    char name[20];
    int age;
};

/* Function to print out the contents of a person struct */
void print_person(struct person p) {
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
}

/* Main function */
int main() {
    /* Create an array of person structs */
    struct person people[5] = { 
        {"Alice", 25},
        {"Bob", 32},
        {"Charlie", 41},
        {"David", 19},
        {"Eve", 27},
    };
    
    /* Print out all of the people in our array */
    printf("Our Array of People:\n");
    for(int i = 0; i < 5; i++) {
        print_person(people[i]);
        printf("\n");
    }
    
    /* Replace David with a new person */
    printf("After Replacing David:\n");
    struct person new_person = {"Frank", 45};
    people[3] = new_person;
    for(int i = 0; i < 5; i++) {
        print_person(people[i]);
        printf("\n");
    }
    
    /* Sort the people by age */
    printf("After Sorting by Age:\n");
    for(int i = 0; i < 5; i++) {
        for(int j = i+1; j < 5; j++) {
            if(people[j].age < people[i].age) {
                struct person tmp = people[i];
                people[i] = people[j];
                people[j] = tmp;
            }
        }
    }
    for(int i = 0; i < 5; i++) {
        print_person(people[i]);
        printf("\n");
    }
    
    return 0;
}