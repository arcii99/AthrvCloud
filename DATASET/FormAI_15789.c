//FormAI DATASET v1.0 Category: Funny ; Style: portable
#include <stdio.h>

// function to print a given message with a given number of exclamation marks
void printExcitement(char* message, int numMarks) {
    printf("%s", message); // print the message itself
    for (int i = 0; i < numMarks; i++) {
        printf("!"); // print the number of exclamation marks specified
    }
    printf("\n"); // print a newline character at the end of the line
}

int main() {
    printf("Welcome to the Excitement Machine!\n\n");

    // get user input for a message and the number of exclamation marks to add
    char message[100];
    int numMarks;

    printf("What message do you want to print with excitement?\n");
    scanf("%s", message);
    printf("How many exclamation marks do you want to add?\n");
    scanf("%d", &numMarks);

    // print the message with the specified level of excitement
    printExcitement(message, numMarks);

    printf("\nThanks for using the Excitement Machine!\n");

    return 0;
}