//FormAI DATASET v1.0 Category: Educational ; Style: Ada Lovelace
/*
    Ada Lovelace C Example 

    This program takes in a user's name and age and prints out 
    a personalized message based on their age. If they are over 
    18, it will print out "You are legally an adult!" If they are 
    under 18, it will print out "You are a minor."

    By Ada Lovelace
*/

#include <stdio.h>
#include <string.h>

int main() {
    // Declare variables for name and age
    char name[50];
    int age;

    // Ask user to enter their name
    printf("Enter your name: ");
    scanf("%s", name);

    // Ask user to enter their age
    printf("Enter your age: ");
    scanf("%d", &age);

    // Check if user is over 18 years old
    if (age >= 18) {
        printf("Hello %s! You are legally an adult!\n", name);
    } else {
        printf("Hello %s! You are a minor.\n", name);
    }

    return 0;
}