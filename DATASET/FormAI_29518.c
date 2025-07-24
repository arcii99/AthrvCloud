//FormAI DATASET v1.0 Category: Data structures visualization ; Style: immersive
#include <stdio.h>

// Structure definition
struct student {
    char name[50];
    int age;
    float marks;
};

// Function to print the details of a student
void printStudent(struct student s) {
    printf("Name: %s\n", s.name);
    printf("Age: %d\n", s.age);
    printf("Marks: %.2f\n", s.marks);
}

int main() {
    // Array of student structures
    struct student class[3] = {
        {"John", 20, 85.5},
        {"Jane", 19, 93.2},
        {"Alex", 21, 77.8}
    };

    // Printing the details of all the students in the class
    printf("Details of all the students in the class:\n\n");
    for(int i=0; i<3; i++) {
        printStudent(class[i]);
        printf("\n");
    }

    return 0;
}