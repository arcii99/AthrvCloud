//FormAI DATASET v1.0 Category: Database querying ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

// Define a structure for storing data
struct person {
    int id;
    char name[20];
    int age;
    char occupation[20];
};

// Declare the main function
int main() {
    // Create a pointer of type FILE
    FILE *fp;
    struct person p;

    // Open the database file
    fp = fopen("cyber_database.db", "rb");
    if (fp == NULL) {
        printf("Error opening file");
        return 1;
    }

    // Read the data from the file
    while (fread(&p, sizeof(struct person), 1, fp) == 1) {
        // Check if the person is a hacker
        if(strcmp(p.occupation, "Hacker") == 0) {
            printf("Hacker ID: %d\nName: %s\nAge: %d\n", p.id, p.name, p.age);
        }
    }

    // Close the file
    fclose(fp);
    return 0;
}