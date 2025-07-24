//FormAI DATASET v1.0 Category: Educational ; Style: configurable
#include <stdio.h>

// Configurable values
#define MAX_MARKS 5
#define PASS_MARKS 40

int main()
{
    int marks[MAX_MARKS];
    int total_marks = 0, i;
    float average;

    // Taking input of marks
    printf("Enter marks of %d subjects:\n", MAX_MARKS);
    for (i = 0; i < MAX_MARKS; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%d", &marks[i]);
        total_marks += marks[i];
    }

    // Calculating average
    average = (float) total_marks / MAX_MARKS;

    // Checking if student has passed or not
    if (average >= PASS_MARKS) {
        printf("Congratulations! You have passed.\n");
    } else {
        printf("Sorry! You have failed.\n");
    }

    // Printing marks and average
    printf("Marks obtained: ");
    for (i = 0; i < MAX_MARKS; i++) {
        printf("%d ", marks[i]);
    }
    printf("\n");
    printf("Average: %.2f\n", average);

    return 0;
}