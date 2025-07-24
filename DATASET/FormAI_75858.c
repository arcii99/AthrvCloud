//FormAI DATASET v1.0 Category: Database querying ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

// Structure to represent a student record in the database
struct student {
    int id;
    char name[MAX_STRING_LENGTH];
    int age;
    char major[MAX_STRING_LENGTH];
    float gpa;
};

// Function to read a student record from a file
void read_student_from_file(FILE *fp, struct student *s) {
    fscanf(fp, "%d %s %d %s %f", &s->id, s->name, &s->age, s->major, &s->gpa);
}

// Function to print a student record
void print_student(struct student s) {
    printf("ID: %d\nName: %s\nAge: %d\nMajor: %s\nGPA: %.2f\n", s.id, s.name, s.age, s.major, s.gpa);
}

int main() {
    // Open the database file for reading
    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file\n");
        return 1;
    }

    // Determine the number of records in the database
    int num_records = 0;
    char line[MAX_STRING_LENGTH];
    while (fgets(line, MAX_STRING_LENGTH, fp) != NULL) {
        num_records++;
    }

    // Allocate memory for the database
    struct student *db = malloc(num_records * sizeof(struct student));
    if (db == NULL) {
        printf("Error: Out of memory\n");
        return 1;
    }

    // Rewind the file pointer to the beginning of the file
    rewind(fp);

    // Read each student record from the file into the database
    for (int i = 0; i < num_records; i++) {
        read_student_from_file(fp, &db[i]);
    }

    // Close the file
    fclose(fp);

    // Query the database for students with a GPA above a certain threshold
    float threshold_gpa = 3.0;
    int num_matches = 0;
    for (int i = 0; i < num_records; i++) {
        if (db[i].gpa >= threshold_gpa) {
            print_student(db[i]);
            num_matches++;
        }
    }

    // Print the number of matches found
    printf("%d matches found\n", num_matches);

    // Free the memory allocated for the database
    free(db);

    return 0;
}