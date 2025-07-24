//FormAI DATASET v1.0 Category: Database querying ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 1000

typedef struct {
    int id;
    char* first_name;
    char* last_name;
    int age;
} Person;

int num_people = 0;
Person people[MAX_SIZE];

void add_person(int id, char* first_name, char* last_name, int age) {
    Person new_person;
    new_person.id = id;
    new_person.first_name = strdup(first_name);
    new_person.last_name = strdup(last_name);
    new_person.age = age;
    people[num_people++] = new_person;
}

void print_people() {
    printf("ID\tFirst Name\tLast Name\tAge\n");
    for (int i = 0; i < num_people; i++) {
        printf("%d\t%s\t\t%s\t\t%d\n", people[i].id, people[i].first_name, people[i].last_name, people[i].age);
    }
}

int find_person(int id) {
    for (int i = 0; i < num_people; i++) {
        if (people[i].id == id) {
            return i;
        }
    }
    return -1;
}

void remove_person(int id) {
    int index = find_person(id);
    if (index != -1) {
        Person person_to_remove = people[index];
        free(person_to_remove.first_name);
        free(person_to_remove.last_name);
        for (int i = index; i < num_people - 1; i++) {
            people[i] = people[i + 1];
        }
        num_people--;
        printf("Person with ID %d has been removed.\n", id);
    } else {
        printf("Person with ID %d not found.\n", id);
    }
}

void update_person(int id, char* first_name, char* last_name, int age) {
    int index = find_person(id);
    if (index != -1) {
        Person* person = &people[index];
        free(person->first_name);
        free(person->last_name);
        person->first_name = strdup(first_name);
        person->last_name = strdup(last_name);
        person->age = age;
        printf("Person with ID %d has been updated.\n", id);
    } else {
        printf("Person with ID %d not found.\n", id);
    }
}

int main() {
    add_person(1, "John", "Doe", 25);
    add_person(2, "Jane", "Doe", 30);
    add_person(3, "Bob", "Smith", 40);
    add_person(4, "Emily", "Jones", 22);
    
    printf("Initial List of People:\n");
    print_people();
    
    remove_person(2);
    
    printf("List of People after Removing ID 2:\n");
    print_people();
    
    update_person(1, "Jonathan", "Doe", 26);
    
    printf("List of People after Updating ID 1:\n");
    print_people();
    
    return 0;
}