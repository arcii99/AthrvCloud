//FormAI DATASET v1.0 Category: File handling ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// define constants
#define MAX_LENGTH 100
#define FILE_PATH "example.txt"

// define struct to hold data
typedef struct {
    int id;
    char name[MAX_LENGTH];
    float score;
} Student;

int main() {
    // create an array of student structures
    Student students[3];

    // populate the array with some sample data
    students[0].id = 1;
    strcpy(students[0].name, "John Doe");
    students[0].score = 90.0;

    students[1].id = 2;
    strcpy(students[1].name, "Jane Smith");
    students[1].score = 85.0;

    students[2].id = 3;
    strcpy(students[2].name, "Bob Johnson");
    students[2].score = 95.0;

    // open the file for writing
    FILE *file = fopen(FILE_PATH, "w");

    // check if the file was opened successfully
    if (file == NULL) {
        printf("File could not be opened for writing.");
        return 1;
    }

    // loop through the array of students and write them to the file
    for (int i = 0; i < 3; i++) {
        fprintf(file, "%d,%s,%.2f\n", students[i].id, students[i].name, students[i].score);
    }

    // close the file
    fclose(file);

    // open the file for reading
    file = fopen(FILE_PATH, "r");

    // check if the file was opened successfully
    if (file == NULL) {
        printf("File could not be opened for reading.");
        return 1;
    }

    // loop through each line of the file and read the data into the array of structures
    char line[MAX_LENGTH];
    int count = 0;
    while (fgets(line, MAX_LENGTH, file) != NULL) {
        sscanf(line, "%d,%[^,],%f", &students[count].id, students[count].name, &students[count].score);
        count++;
    }

    // close the file
    fclose(file);

    // loop through the array of students and print their data to the console
    for (int i = 0; i < 3; i++) {
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Score: %.2f\n", students[i].score);
        printf("\n");
    }

    return 0;
}