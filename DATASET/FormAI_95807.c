//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

struct person {
    char name[BUFFER_SIZE];
    int age;
};

void initialize_person(struct person* p, const char* name, int age) {
    strncpy(p->name, name, BUFFER_SIZE-1);
    p->age = age;
}

void print_person(const struct person* p) {
    printf("Name: %s, Age: %d\n", p->name, p->age);
}

int main() {
    int num_people = 5;
    struct person people[num_people];

    initialize_person(&people[0], "John", 25);
    initialize_person(&people[1], "Jane", 30);
    initialize_person(&people[2], "Mike", 20);
    initialize_person(&people[3], "Sally", 35);
    initialize_person(&people[4], "Bob", 28);

    int i;
    for (i = 0; i < num_people; i++) {
        print_person(&people[i]);
    }

    return 0;
}