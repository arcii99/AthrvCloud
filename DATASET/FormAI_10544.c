//FormAI DATASET v1.0 Category: String manipulation ; Style: real-life
#include <stdio.h>
#include <string.h>

int main() {
    char firstName[20], lastName[20], fullName[40], reversedName[40], initials[4];

    printf("Enter your first name: ");
    fgets(firstName, 20, stdin);
    firstName[strlen(firstName)-1] = '\0'; //Remove the newline character from the input

    printf("Enter your last name: ");
    fgets(lastName, 20, stdin);
    lastName[strlen(lastName)-1] = '\0'; //Remove the newline character from the input

    //Combine the first and last name to form the full name
    sprintf(fullName, "%s %s", firstName, lastName);

    //Print the full name
    printf("\nYour full name is: %s\n", fullName);

    //Find the length of the full name
    int length = strlen(fullName);

    //Reverse the full name and store it in another string
    for(int i=0; i<length; i++) {
        reversedName[i] = fullName[length-i-1];
    }
    reversedName[length] = '\0';

    //Print the reversed name
    printf("Your name in reverse order is: %s\n", reversedName);

    //Extract the initials from the full name
    initials[0] = firstName[0];
    initials[1] = '.';
    initials[2] = lastName[0];
    initials[3] = '\0';

    //Print the initials
    printf("Your initials are: %s\n", initials);

    return 0;
}