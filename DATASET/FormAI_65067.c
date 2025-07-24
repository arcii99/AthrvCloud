//FormAI DATASET v1.0 Category: Database Indexing System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    float gpa;
};

struct Index {
    int id;
    int location;
};

int main() {
    int numStudents = 5;

    // Create and populate students array
    struct Student students[] = {
        {1, "John", 3.5},
        {2, "Jane", 3.8},
        {3, "Bob", 3.2},
        {4, "Sara", 3.9},
        {5, "Mike", 3.7}
    };

    // Initialize index table with student IDs and their corresponding locations in the students array
    struct Index indexTable[numStudents];
    for (int i = 0; i < numStudents; i++) {
        indexTable[i].id = students[i].id;
        indexTable[i].location = i;
    }

    // Print index table
    printf("Index Table:\n");
    printf("ID\tLocation\n");
    for (int i = 0; i < numStudents; i++) {
        printf("%d\t%d\n", indexTable[i].id, indexTable[i].location);
    }

    // Perform search
    int searchID = 4;
    int found = 0;
    int location;
    for (int i = 0; i < numStudents; i++) {
        if (indexTable[i].id == searchID) {
            location = indexTable[i].location;
            found = 1;
            break;
        }
    }

    // Print search result
    if (found == 1) {
        printf("\nSearch result:\n");
        printf("ID\tName\tGPA\n");
        printf("%d\t%s\t%.1f\n", students[location].id, students[location].name, students[location].gpa);
    }
    else {
        printf("\nNo student with ID %d found.\n", searchID);
    }

    return 0;
}