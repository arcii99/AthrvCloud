//FormAI DATASET v1.0 Category: Data structures visualization ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// defining a struct for a student record
struct student {
    char name[30];
    int roll_no;
    float average_marks;
};

// a function to display all details of a student
void display_student(struct student);

int main() {
    // initializing an array of struct students
    struct student students[5] = {
        {"John", 1, 75.5},
        {"Mary", 2, 89.0},
        {"Tim", 3, 92.3},
        {"Anne", 4, 68.7},
        {"Bob", 5, 80.1}
    };

    // printing the details of all the students in the array
    for(int i = 0; i < 5; i++) {
        printf("Student %d\n", i+1);
        display_student(students[i]);
        printf("\n");
    }

    return 0;
}

void display_student(struct student s) {
    printf("Name: %s\n", s.name);
    printf("Roll No: %d\n", s.roll_no);
    printf("Average Marks: %.2f\n", s.average_marks);
}