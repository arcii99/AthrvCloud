//FormAI DATASET v1.0 Category: Database Indexing System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Struct for a person */
typedef struct {
    char name[50];
    int age;
} Person;

/* Struct for an index */
typedef struct {
    char name[50];
    int offset;
    int length;
} Index;

/* Function for creating an index */
void createIndex(FILE *file, Index *index) {
    fseek(file, 0, SEEK_SET);
    fgets(index->name, sizeof(index->name), file);
    index->offset = ftell(file);
    while(fgets(index->name, sizeof(index->name), file)) {
        index->length = ftell(file) - index->offset;
        index++;
        index->offset = ftell(file);
    }
}

/* Function for searching the index */
void searchIndex(Index *index, char *name) {
    int i;
    for(i = 0; index[i].name[0] != '\0'; i++) {
        if(strcmp(name, index[i].name) == 0) {
            break;
        }
    }
    printf("Found person %s at offset %d with length %d\n", name, index[i].offset, index[i].length);
}

int main() {
    FILE *file;
    Index index[100] = {{'\0', 0, 0}};
    Person person;

    /* Create a binary file with some people */
    file = fopen("people.dat", "wb");
    strcpy(person.name, "Alice");
    person.age = 25;
    fwrite(&person, sizeof(Person), 1, file);
    strcpy(person.name, "Bob");
    person.age = 30;
    fwrite(&person, sizeof(Person), 1, file);
    strcpy(person.name, "Charlie");
    person.age = 35;
    fwrite(&person, sizeof(Person), 1, file);
    fclose(file);

    /* Open the binary file for reading */
    file = fopen("people.dat", "rb");

    /* Create an index */
    createIndex(file, index);

    /* Search the index */
    searchIndex(index, "Bob");

    fclose(file);
    return 0;
}