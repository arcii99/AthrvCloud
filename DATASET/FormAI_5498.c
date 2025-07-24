//FormAI DATASET v1.0 Category: Searching algorithm ; Style: interoperable
#include <stdio.h>
#include <string.h>

// Define a struct for a student
typedef struct {
    char name[50];
    int age;
    float gpa;
} Student;

// Define a simple searching function that takes in a key to search for
int search(Student arr[], int size, char key[]) {
    // Loop through array to find key
    for (int i = 0; i < size; i++) {
        // Use strcmp to compare the key with the name in the struct
        if (strcmp(arr[i].name, key) == 0) {
            printf("Match found for %s: \nName: %s\nAge: %d\nGPA: %f\n", key, arr[i].name, arr[i].age, arr[i].gpa);
            // Return the index of the match
            return i;
        }
    }
    // Key not found
    printf("Could not find %s in the array.\n", key);
    return -1;
}

int main(void) {
    // Create an array of students
    Student students[] = {
        {"Alice", 20, 3.8},
        {"Bob", 22, 3.5},
        {"Charlie", 18, 4.0},
        {"David", 19, 3.2},
        {"Emily", 21, 3.7}
    };
    // Get the size of the array
    int size = sizeof(students) / sizeof(Student);

    // Search for a student by name
    printf("--- Searching for a student ---\n");
    search(students, size, "Charlie");

    return 0;
}