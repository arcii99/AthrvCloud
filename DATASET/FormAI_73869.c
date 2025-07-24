//FormAI DATASET v1.0 Category: Math exercise ; Style: imaginative
#include <stdio.h>  // Include Standard Input/Output Header File
#include <stdlib.h> // Include Standard Library Header File
#include <time.h>   // Include Time Header File

int main() {
    int a, b, c, answer, user_answer; // Declare Variables
    srand(time(NULL)); // Initialize the Pseudo-Random Number Generator
    a = rand() % 100; // Generate Random Number Between 0 to 99
    b = rand() % 100; // Generate Random Number Between 0 to 99
    c = rand() % 3;   // Generate Random Number Between 0 to 2
    // The variable 'c' is used to select the type of Math Operation
    switch (c) {
        case 0:
            answer = a + b; // Addition - Calculate Answer
            printf("What is %d + %d ?\n", a, b); // Display the Question
            break;
        case 1:
            answer = a - b; // Subtraction - Calculate Answer
            printf("What is %d - %d ?\n", a, b); // Display the Question
            break;
        case 2:
            answer = a * b; // Multiplication - Calculate Answer
            printf("What is %d * %d ?\n", a, b); // Display the Question
            break;
    }
    scanf("%d", &user_answer); // Get User Input
    if (user_answer == answer) { // Check if Answer is Correct
        printf("Correct Answer!"); // Display Correct Message
    } else {
        printf("Incorrect Answer!"); // Display Incorrect Message
    }
    return 0; // End of Program
}