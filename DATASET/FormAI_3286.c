//FormAI DATASET v1.0 Category: Database simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 25
#define MAX_GRADE_LEN 2

struct Student {
    char name[MAX_NAME_LEN];
    char grade[MAX_GRADE_LEN];
};

int main() {
    struct Student students[100];
    int num_students = 0;
    char input[MAX_NAME_LEN + MAX_GRADE_LEN + 2]; // Maximum input length is name + grade + space or newline

    printf("Welcome to the Student Database!\n");
    printf("To add a student, type their name followed by their grade (out of 100), separated by a space. To quit, type 'quit'\n");

    while (1) {
        // Read in input
        fgets(input, MAX_NAME_LEN + MAX_GRADE_LEN + 2, stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline character from end of input

        // Check if user wants to quit
        if (strcmp(input, "quit") == 0) {
            break;
        }

        // Parse name and grade from input
        char name[MAX_NAME_LEN];
        char grade[MAX_GRADE_LEN];
        int num_items = sscanf(input, "%s %s", name, grade);

        // Check if input was valid
        if (num_items != 2 || strlen(name) > MAX_NAME_LEN || strlen(grade) > MAX_GRADE_LEN) {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        // Add student to the database
        strcpy(students[num_students].name, name);
        strcpy(students[num_students].grade, grade);
        num_students++;

        printf("%s added to database.\n", name);
    }

    printf("There are %d students in the database:\n", num_students);
    for (int i = 0; i < num_students; i++) {
        printf("%s - Grade: %s\n", students[i].name, students[i].grade);
    }

    return 0;
}