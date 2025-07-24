//FormAI DATASET v1.0 Category: Database Indexing System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORDS 100  // Maximum number of records that can be stored
#define MAX_NAME_LENGTH 30  // Maximum character length for a person's name

// Struct for storing person's record
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char occupation[MAX_NAME_LENGTH];
} Person;

// Struct for storing person's record along with an index key
typedef struct {
    int key;
    Person record;
} IndexedPerson;

// Struct for storing index and the current number of records
typedef struct {
    int index[MAX_RECORDS];
    int count;
} Index;

// Initialization of index
void initIndex(Index *index) {
    index->count = 0;
}

// Insert a new person's record into the database along with assigning a new index key
int insertPerson(IndexedPerson database[], int *currentIndex, Person newPerson) {
    if (*currentIndex >= MAX_RECORDS) {
        return -1;  // If maximum limit is reached, return error
    }
    int newKey = *currentIndex;  // Assign a new index key
    database[*currentIndex].key = newKey;
    database[*currentIndex].record = newPerson;
    (*currentIndex)++;
    return newKey;
}

// Delete a person's record from the database based on an index key
int deletePerson(IndexedPerson database[], int *currentIndex, int indexKey) {
    int i, j;
    for (i = 0; i < *currentIndex; i++) {
        if (database[i].key == indexKey) {
            for (j = i; j < *currentIndex - 1; j++) {
                database[j] = database[j+1];
            }
            (*currentIndex)--;
            return 1;
        }
    }
    return -1; // If index key not found, return error
}

// Retrieve a person's record from the database based on an index key
Person retrievePerson(IndexedPerson database[], int currentIndex, int indexKey) {
    int i;
    for (i = 0; i < currentIndex; i++) {
        if (database[i].key == indexKey) {
            return database[i].record;
        }
    }
    Person notFoundPerson = {"", 0, ""};  // Placeholder person if index key not found
    return notFoundPerson;
}

// Search for people in the database based on their occupation
Index searchByOccupation(IndexedPerson database[], int currentIndex, char occupation[]) {
    int i;
    Index resultIndex;
    initIndex(&resultIndex);
    for (i = 0; i < currentIndex; i++) {
        if (strcmp(database[i].record.occupation, occupation) == 0) {
            resultIndex.index[resultIndex.count] = database[i].key;
            resultIndex.count++;
        }
    }
    return resultIndex;
}

int main() {
    IndexedPerson database[MAX_RECORDS];
    int currentIndex = 0;

    Person person1 = {"John Doe", 25, "Software Engineer"};
    int key1 = insertPerson(database, &currentIndex, person1);

    Person person2 = {"Jane Smith", 32, "Doctor"};
    int key2 = insertPerson(database, &currentIndex, person2);

    Person person3 = {"Mike Johnson", 45, "Lawyer"};
    int key3 = insertPerson(database, &currentIndex, person3);

    Person person4 = {"Sarah Lee", 28, "Software Engineer"};
    int key4 = insertPerson(database, &currentIndex, person4);

    Person person5 = {"Sam Brown", 39, "Doctor"};
    int key5 = insertPerson(database, &currentIndex, person5);

    printf("Person retrieved using index key %d - %s\n", key1, retrievePerson(database, currentIndex, key1).name);

    printf("Deleting person with index key %d\n", key3);
    deletePerson(database, &currentIndex, key3);

    printf("Searching for people with occupation 'Software Engineer'\n");
    Index searchResults = searchByOccupation(database, currentIndex, "Software Engineer");
    int i;
    for (i = 0; i < searchResults.count; i++) {
        printf("Person retrieved using index key %d - %s\n", searchResults.index[i], retrievePerson(database, currentIndex, searchResults.index[i]).name);
    }

    return 0;
}