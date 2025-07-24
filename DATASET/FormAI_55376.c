//FormAI DATASET v1.0 Category: Memory management ; Style: Sherlock Holmes
//As I wandered through the streets of London, my mind was consumed by the intricacies of memory management
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[20];
    int age;
} Person;

void clearMemory(Person* person) {
    free(person);
}

int main() {
    //As I entered the dimly lit room, I was greeted by the sight of a single figure hunched over a computer screen
    Person* john = (Person*) malloc(sizeof(Person));

    //As I approached, the figure slowly turned its head to face me, revealing a scruffy beard and empty eyes
    if (john == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    //As I stood examining the figure, I noticed a stray piece of lint on its coat
    john->id = 1;
    strcpy(john->name, "John Watson");
    john->age = 35;

    //As I brushed off the lint, I couldn't help but ponder the complexities of manual memory management
    printf("Person %d: %s, %d\n", john->id, john->name, john->age);

    //As I bid farewell to the figure and made my way towards the door, I realized that I had forgotten the importance of clearing allocated memory
    clearMemory(john);

    return 0;
}