//FormAI DATASET v1.0 Category: Data mining ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 20
#define MAX_AGE 100

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
} Person;

void print_person(Person p) {
    printf("Name: %s \n", p.name);
    printf("Age: %d \n", p.age);
}

void data_mining(Person* people, int size) {
    int i, count = 0;
    for(i=0; i<size; i++) {
        if(strstr(people[i].name, "Sam")) { // check if name contains "Sam"
            print_person(people[i]);
            count++;
        }
    }

    printf("Number of people named Sam: %d", count);
}

int main() {
    Person people[5];
    strcpy(people[0].name, "John");
    people[0].age = 25;
    strcpy(people[1].name, "Samuel");
    people[1].age = 31;
    strcpy(people[2].name, "Samantha");
    people[2].age = 22;
    strcpy(people[3].name, "Anna");
    people[3].age = 28;
    strcpy(people[4].name, "Sam");
    people[4].age = 34;

    data_mining(people, sizeof(people)/sizeof(Person));

    return 0;
}