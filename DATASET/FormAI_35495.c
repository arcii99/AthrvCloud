//FormAI DATASET v1.0 Category: Database simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char name[50];
    int id;
    int age;
} Person;

typedef struct {
    Person arr[MAX_SIZE];
    int size;
} Database;

typedef struct {
    int num;
    Person person;
} Result;

int find(Database *database, int id) {
    int index = -1;
    int i;
    for (i = 0; i < database->size; i++) {
        if (database->arr[i].id == id) {
            index = i;
            break;
        }
    }
    return index;
}

void insert(Database *database, Person person) {
    if (database->size >= MAX_SIZE) {
        fprintf(stderr, "Error: Database is full!\n");
        return;
    }
    database->arr[database->size++] = person;
}

void delete(Database *database, int id) {
    int index = find(database, id);
    if (index == -1) {
        fprintf(stderr, "Error: Person with ID %d not found!\n", id);
        return;
    }
    int i;
    for (i = index; i < database->size - 1; i++) {
        database->arr[i] = database->arr[i + 1];
    }
    database->size--;
}

Result search(Database *database, int id) {
    Result result = {0};
    int index = find(database, id);
    if (index >= 0) {
        result.num = 1;
        result.person = database->arr[index];
    }
    return result;
}

void print(Database *database) {
    printf("ID\tName\tAge\n");
    printf("----------------------------------\n");
    int i;
    for (i = 0; i < database->size; i++) {
        printf("%d\t%s\t%d\n", database->arr[i].id, database->arr[i].name, database->arr[i].age);
    }
}

int main() {
    Database database = {.size = 0};

    Person person1 = {"Alice", 1, 22};
    Person person2 = {"Bob", 2, 31};
    Person person3 = {"Charlie", 3, 45};

    insert(&database, person1);
    insert(&database, person2);
    insert(&database, person3);

    print(&database);

    Result result = search(&database, 2);
    if (result.num == 1) {
        printf("Found person with ID 2: %s, %d years old\n", result.person.name, result.person.age);
    } else {
        printf("Person with ID 2 not found!\n");
    }

    delete(&database, 3);

    printf("After deleting person with ID 3:\n");
    print(&database);

    return 0;
}