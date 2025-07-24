//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Romeo and Juliet
//Start of code snippet

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
} Person;

typedef struct {
    int key;
    int offset;
} Index;

void createIndexFile(FILE *dataFile, FILE *indexFile) {
    int count = 0;
    Index tempIndex;
    Person tempPerson;
    fseek(dataFile, 0, SEEK_SET);
    while (fread(&tempPerson, sizeof(Person), 1, dataFile) == 1) {
        tempIndex.key = tempPerson.id;
        tempIndex.offset = count * sizeof(Person);
        fwrite(&tempIndex, sizeof(Index), 1, indexFile);
        count++;
    }
}

int searchPerson(int id, FILE *dataFile, FILE *indexFile, Person *person) {
    int low = 0, high, mid;
    Index tempIndex;
    fseek(indexFile, 0, SEEK_END);
    high = ftell(indexFile) / sizeof(Index);
    while (low <= high) {
        mid = (low + high) / 2;
        fseek(indexFile, mid * sizeof(Index), SEEK_SET);
        fread(&tempIndex, sizeof(Index), 1, indexFile);
        if (tempIndex.key == id) {
            fseek(dataFile, tempIndex.offset, SEEK_SET);
            fread(person, sizeof(Person), 1, dataFile);
            return 1;
        }
        else if (tempIndex.key < id) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return 0;
}

int main() {
    FILE *dataFile, *indexFile;
    dataFile = fopen("people.dat", "rb");
    indexFile = fopen("people.idx", "wb");
    createIndexFile(dataFile, indexFile);
    fclose(dataFile);
    fclose(indexFile);
    dataFile = fopen("people.dat", "rb");
    indexFile = fopen("people.idx", "rb");
    Person person;
    if (searchPerson(3, dataFile, indexFile, &person)) {
        printf("Person found:\nID: %d\nName: %s\nAge: %d\n", person.id, person.name, person.age);
    }
    else {
        printf("Person not found.\n");
    }
    fclose(dataFile);
    fclose(indexFile);
    return 0;
}

//End of code snippet