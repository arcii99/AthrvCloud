//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: inquisitive
#include <stdio.h>

int main() {
    // Welcome the user to the C Resume Parsing System
    printf("Welcome to the C Resume Parsing System!\n");

    // Initialize variables
    char name[50];
    int age;
    char education[50];
    char experience[50];
    char skills[50];

    // Ask for user input for each variable
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("Please enter your age: ");
    scanf("%d", &age);

    printf("Please enter your highest level of education: ");
    scanf("%s", education);

    printf("Please enter your most recent work experience: ");
    scanf("%s", experience);

    printf("Please enter your top three skills (separated by commas): ");
    scanf("%s", skills);

    // Output the parsed information
    printf("\nResume Parsed:\n");
    printf("================\n");
    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("Education: %s\n", education);
    printf("Experience: %s\n", experience);
    printf("Skills: %s\n", skills);

    // Thank the user for using the system
    printf("\nThank you for using the C Resume Parsing System!\n");

    return 0;
}