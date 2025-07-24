//FormAI DATASET v1.0 Category: Database Indexing System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INDEX_SIZE 26

typedef struct {
    char *name;
    int age;
    float salary;
} Person;

typedef struct {
    char *key;
    Person **data;
    int size;
} Index;

Index *createIndex(char *key) {
    Index *index = (Index *)malloc(sizeof(Index));
    index->key = key;
    index->size = 0;
    index->data = NULL;
    return index;
}

int hash(char *key) {
    return key[0] - 'a';
}

void addToIndex(Index **index, Person *person) {
    int indexKey = hash(person->name);
    Index *current_index = index[indexKey];
    if (current_index == NULL) {
        current_index = createIndex(person->name);
        index[indexKey] = current_index;
    }
    if (current_index->size == 0) {
        current_index->data = (Person **)malloc(sizeof(Person *));
        current_index->data[0] = person;
        current_index->size++;
    } else {
        current_index->data = (Person **)realloc(current_index->data, (current_index->size + 1) * sizeof(Person *));
        current_index->data[current_index->size] = person;
        current_index->size++;
    }
}

Person **findInIndex(Index **index, char *key) {
    int indexKey = hash(key);
    Index *current_index = index[indexKey];
    if (current_index != NULL) {
        int i;
        for (i=0; i<current_index->size; i++) {
            if (strcmp(current_index->data[i]->name, key) == 0) {
                return &(current_index->data[i]);
            }
        }
    }
    return NULL;
}

int main() {

    Index *index[INDEX_SIZE];
    memset(index, 0, sizeof(index));

    Person *p1 = (Person *)malloc(sizeof(Person));
    p1->name = "Alice";
    p1->age = 25;
    p1->salary = 50000.0;
    addToIndex(index, p1);

    Person *p2 = (Person *)malloc(sizeof(Person));
    p2->name = "Bob";
    p2->age = 32;
    p2->salary = 65000.0;
    addToIndex(index, p2);

    Person *p3 = (Person *)malloc(sizeof(Person));
    p3->name = "Chris";
    p3->age = 40;
    p3->salary = 80000.0;
    addToIndex(index, p3);

    Person **p4 = findInIndex(index, "Bob");
    if (p4 != NULL) {
        printf("Bob's age is %d and salary is %.2f\n", (*p4)->age, (*p4)->salary);
    }

    return 0;
}