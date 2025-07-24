//FormAI DATASET v1.0 Category: Educational ; Style: complex
#include <stdio.h>
#include <stdlib.h>

/* Define a struct for a person */
typedef struct {
    char* name;
    int age;
    double height;
} Person;

/* Define a function to create a new Person and initialize their values */
Person* create_person(char* name, int age, double height) {
    Person* p = (Person*)malloc(sizeof(Person));
    p->name = name;
    p->age = age;
    p->height = height;

    return p;
}

/* Define a function to print out a Person's information */
void print_person(Person* p) {
    printf("Name: %s\n", p->name);
    printf("Age: %d\n", p->age);
    printf("Height: %.2f\n", p->height);
}

int main() {
    /* Create a few people */
    Person* alice = create_person("Alice", 25, 5.6);
    Person* bob = create_person("Bob", 32, 6.1);
    Person* carol = create_person("Carol", 38, 5.8);

    /* Print out their information */
    printf("--- Alice ---\n");
    print_person(alice);
    printf("--- Bob ---\n");
    print_person(bob);
    printf("--- Carol ---\n");
    print_person(carol);

    /* Free the memory */
    free(alice);
    free(bob);
    free(carol);

    return 0;
}