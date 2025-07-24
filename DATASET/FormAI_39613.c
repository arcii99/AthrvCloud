//FormAI DATASET v1.0 Category: Digital Diary ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to print a silly message
void printSillyMessage() {
    printf("You've reached the digital diary of the coolest cat in town.\n");
    printf("Seriously, I'm a cat. Meow.\n");
    printf("But don't worry, I won't scratch your eyes out or anything. Unless you try to steal my tuna.");
}

int main() {
    char* entryDate;
    char* entryText;

    // allocate memory for entry date and text
    entryDate = (char*) malloc(20 * sizeof(char));
    entryText = (char*) malloc(1000 * sizeof(char));

    if (entryDate == NULL || entryText == NULL) {
        printf("Error: Unable to allocate memory for new entry.\n");
        exit(1);
    }

    // get user input for entry date
    printf("Enter the date for your entry (MM/DD/YYYY): ");
    scanf("%s", entryDate);

    // get user input for entry text
    printf("What's on your mind, human? Tell me everything! Just remember to keep it PG.\n");
    scanf(" %[^\n]s", entryText);

    // print silly message
    printSillyMessage();

    // print entry date and text
    printf("\n\n%s\n\n%s\n", entryDate, entryText);

    // free memory
    free(entryDate);
    free(entryText);

    return 0;
}