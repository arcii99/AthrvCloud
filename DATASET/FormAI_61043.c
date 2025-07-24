//FormAI DATASET v1.0 Category: Data mining ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold the data to be mined
struct student {
    int id;
    char name[20];
    float cgpa;
};

int main() {
    // Initialize an array of struct student and fill it with data
    struct student students[5] = {
        { 101, "John Smith", 3.8 },
        { 102, "Jane Doe", 3.6 },
        { 103, "Bob Johnson", 3.5 },
        { 104, "Sara Lee", 3.9 },
        { 105, "Jim Jones", 3.4 },
    };

    // Define an array to hold the mined data
    struct student top_students[3];

    // Initialize the top_students array with the first three students
    memcpy(top_students, students, 3 * sizeof(struct student));

    // Loop through the remaining students and update the top_students array
    for (int i = 3; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            if (students[i].cgpa > top_students[j].cgpa) {
                // Shift the bottom elements down
                for (int k = 2; k > j; k--) {
                    memcpy(&top_students[k], &top_students[k-1], sizeof(struct student));
                }
                // Copy the new top student into the array
                memcpy(&top_students[j], &students[i], sizeof(struct student));
                break;
            }
        }
    }

    // Print out the top students
    printf("Top Students:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d\t%s\t%f\n", top_students[i].id, top_students[i].name, top_students[i].cgpa);
    }

    return 0;
}