//FormAI DATASET v1.0 Category: Data validation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char name[20]; // define a string variable to store user's name
    int age; // define a integer variable to store user's age
    char gender; // define a character variable to store user's gender

    // prompt the user to enter their name
    printf("Enter your name: ");
    scanf("%s", name);

    // prompt the user to enter their age
    printf("Enter your age: ");
    scanf("%d", &age);

    // validate user's age
    if (age < 0 || age > 120) {
        printf("Invalid age! Please enter a valid age between 0 and 120.\n");
        exit(0); // exit the program if age is invalid
    }

    // prompt the user to enter their gender
    printf("Enter your gender (M/F): ");
    scanf(" %c", &gender); // use a space before %c to ignore leading white space

    // convert gender to upper case
    gender = toupper(gender);

    // validate user's gender
    if (gender != 'M' && gender != 'F') {
        printf("Invalid gender! Please enter either 'M' or 'F'.\n");
        exit(0); // exit the program if gender is invalid
    }

    // print user's information
    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("Gender: %c\n", gender);

    return 0;
}