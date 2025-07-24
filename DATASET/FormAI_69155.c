//FormAI DATASET v1.0 Category: Database simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DATABASE_SIZE 100

struct Data {
    int id;
    char* name;
    int age;
};

struct Database {
    struct Data data[MAX_DATABASE_SIZE];
    int size;
};

void initializeDatabase(struct Database* database) {
    for (int i = 0; i < MAX_DATABASE_SIZE; i++) {
        database -> data[i].id = -1;
        database -> data[i].name = NULL;
        database -> data[i].age = -1;
    }
    database -> size = 0;
}

bool isIdUnique(struct Database* database, int id) {
    for (int i = 0; i < database -> size; i++) {
        if (database -> data[i].id == id) {
            return false;
        }
    }
    return true;
}

void addData(struct Database* database, int id, char* name, int age) {
    if (database -> size >= MAX_DATABASE_SIZE) {
        printf("Database is full\n");
        return;
    }
    if (!isIdUnique(database, id)) {
        printf("ID already exists in database\n");
        return;
    }
    database -> data[database -> size].id = id;
    database -> data[database -> size].name = (char*) malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(database -> data[database -> size].name, name);
    database -> data[database -> size].age = age;
    database -> size++;
}

void removeData(struct Database* database, int id) {
    if (database -> size <= 0) {
        printf("Database is empty\n");
        return;
    }
    int indexToRemove = -1;
    for (int i = 0; i < database -> size; i++) {
        if (database -> data[i].id == id) {
            indexToRemove = i;
            break;
        }
    }
    if (indexToRemove == -1) {
        printf("ID not found in database\n");
        return;
    }
    free(database -> data[indexToRemove].name);
    database -> data[indexToRemove].id = -1;
    database -> data[indexToRemove].name = NULL;
    database -> data[indexToRemove].age = -1;
    for (int i = indexToRemove + 1; i < database -> size; i++) {
        database -> data[i - 1].id = database -> data[i].id;
        database -> data[i - 1].name = database -> data[i].name;
        database -> data[i - 1].age = database -> data[i].age;
    }
    database -> size--;
}

void printData(struct Data data) {
    printf("ID: %d\n", data.id);
    printf("Name: %s\n", data.name);
    printf("Age: %d\n", data.age);
}

void printDatabase(struct Database database) {
    if (database.size <= 0) {
        printf("Database is empty\n");
        return;
    }
    for (int i = 0; i < database.size; i++) {
        if (database.data[i].id != -1) {
            printf("------------------------------------\n");
            printData(database.data[i]);
        }
    }
}

int main() {
    struct Database database;
    initializeDatabase(&database);

    addData(&database, 1, "John Doe", 25);
    addData(&database, 2, "Jane Smith", 30);
    addData(&database, 3, "Bob Johnson", 52);
    printDatabase(database);

    removeData(&database, 2);
    printDatabase(database);

    return 0;
}