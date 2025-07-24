//FormAI DATASET v1.0 Category: Database querying ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

typedef struct Student {
    int id;
    char name[MAX_LEN];
    float gpa;
} Student;

int main() {
    // Connect to database
    printf("Connecting to database...\n");

    // Query database for student records
    printf("Querying database for student records...\n");

    // Simulate returned results
    Student results[3];
    results[0].id = 1001;
    strcpy(results[0].name, "John Doe");
    results[0].gpa = 3.65;
    results[1].id = 1002;
    strcpy(results[1].name, "Jane Smith");
    results[1].gpa = 3.8;
    results[2].id = 1003;
    strcpy(results[2].name, "Bob Johnson");
    results[2].gpa = 3.4;

    // Print out results
    printf("\nStudent Records:\n");
    printf("-----------------\n");
    printf("%-10s %-15s %-10s\n", "ID", "NAME", "GPA");
    printf("-----------------\n");
    for (int i = 0; i < 3; i++) {
        printf("%-10d %-15s %-10.2f\n", results[i].id, results[i].name, results[i].gpa);
    }

    // Disconnect from database
    printf("\nDisconnecting from database...\n");

    return 0;
}