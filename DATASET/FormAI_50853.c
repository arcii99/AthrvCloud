//FormAI DATASET v1.0 Category: Memory management ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char* name;
    int age;
} Person;

void createPerson(Person** pperson, int id, const char* name, int age) {
    (*pperson) = (Person*)malloc(sizeof(Person));
    (*pperson)->id = id;
    (*pperson)->name = (char*)malloc(sizeof(char) * (strlen(name) + 1));
    strcpy((*pperson)->name, name);
    (*pperson)->age = age;
}

void destroyPerson(Person* person) {
    free(person->name);
    free(person);
}

int main() {
    Person* person;
    createPerson(&person, 1, "John", 25);
    printf("Person created with ID=%d, Name=%s, Age=%d\n", person->id, person->name, person->age);
    destroyPerson(person);
    printf("Person destroyed\n");
    return 0;
}