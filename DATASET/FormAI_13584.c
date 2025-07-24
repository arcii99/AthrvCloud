//FormAI DATASET v1.0 Category: Database Indexing System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for each item in the database
typedef struct {
    int id;
    char name[50];
    int age;
} Person;

// Define the struct for the index
typedef struct {
    char name[50];
    int offset;
} Index;

int main() {
    int num_people = 5;
    Person people[num_people];
    Index index[num_people];

    // Populate the People array with sample data
    Person p1 = {1, "John", 25};
    Person p2 = {2, "Jane", 30};
    Person p3 = {3, "Bob", 40};
    Person p4 = {4, "Mary", 22};
    Person p5 = {5, "Sarah", 28};
    people[0] = p1;
    people[1] = p2;
    people[2] = p3;
    people[3] = p4;
    people[4] = p5;

    // Populate the index with the names of the people in the people array
    for (int i = 0; i < num_people; i++) {
        Index ind;
        strcpy(ind.name, people[i].name);
        ind.offset = i;
        index[i] = ind;
    }

    // Sort the index alphabetically
    for (int i = 0; i < num_people - 1; i++) {
        for (int j = i + 1; j < num_people; j++) {
            if (strcmp(index[i].name, index[j].name) > 0) {
                Index temp = index[i];
                index[i] = index[j];
                index[j] = temp;
            }
        }
    }

    // Print out the sorted index
    printf("Sorted Index:\n");
    for (int i = 0; i < num_people; i++) {
        printf("%d %s\n", index[i].offset, index[i].name);
    }
    printf("\n");

    // Print out the original array in order of the sorted index
    printf("People sorted by name:\n");
    for (int i = 0; i < num_people; i++) {
        printf("%d %s %d\n", people[index[i].offset].id, people[index[i].offset].name, people[index[i].offset].age);
    }
    printf("\n");

    return 0;
}