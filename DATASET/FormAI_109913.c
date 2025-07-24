//FormAI DATASET v1.0 Category: Online Examination System ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

struct student {
    char name[50];
    int roll;
    float marks;
} s;

int main() {
    printf("~~~~ Welcome to the C Online Examination System ~~~~\n\n");

    printf("Enter student name: ");
    fgets(s.name, sizeof(s.name), stdin);

    printf("Enter roll number: ");
    scanf("%d", &s.roll);

    printf("Enter marks: ");
    scanf("%f", &s.marks);

    // Saving data to file for future reference
    FILE *fptr;
    fptr = fopen("data.txt", "w");
    fprintf(fptr, "Name: %sRoll Number: %d\nMarks: %.2f", s.name, s.roll, s.marks);
    fclose(fptr);

    // Displaying confirmation message
    printf("\n---Data saved successfully!---\n\n");

    // Reading data from file
    fptr = fopen("data.txt", "r");
    printf("---Here's your data---\n\n");
    printf("%s", fgets(s.name, sizeof(s.name), fptr));
    fclose(fptr);

    // Displaying farewell message
    printf("\n---Thank you for using the C Online Examination System!---\n\n");
    return 0;
}