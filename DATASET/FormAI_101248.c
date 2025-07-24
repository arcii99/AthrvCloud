//FormAI DATASET v1.0 Category: Data mining ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define NUM_STUDENTS 10
#define NUM_TESTS 3

struct student {
    char name[20];
    int test_scores[NUM_TESTS];
    float average;
};

void calculate_average(struct student *s) {
    int total = 0;
    for (int i = 0; i < NUM_TESTS; i++) {
        total += s->test_scores[i];
    }
    s->average = (float)total / NUM_TESTS;
}

void print_student(struct student s) {
    printf("Name: %s\n", s.name);
    printf("Test Scores: ");
    for (int i = 0; i < NUM_TESTS; i++) {
        printf("%d ", s.test_scores[i]);
    }
    printf("\n");
    printf("Average: %.2f\n\n", s.average);
}

int main() {
    struct student students[NUM_STUDENTS] = {
        {"John", {85, 78, 92}},
        {"Mary", {90, 88, 94}},
        {"Bob", {75, 80, 85}},
        {"Sue", {86, 92, 89}},
        {"Jim", {79, 81, 83}},
        {"Ann", {91, 95, 97}},
        {"Tom", {80, 84, 88}},
        {"Jane", {73, 77, 81}},
        {"Tim", {89, 90, 91}},
        {"Beth", {82, 83, 85}}
    };

    // Calculate averages for each student
    for (int i = 0; i < NUM_STUDENTS; i++) {
        calculate_average(&students[i]);
    }

    // Print all students with their averages
    for (int i = 0; i < NUM_STUDENTS; i++) {
        print_student(students[i]);
    }

    return 0;
}