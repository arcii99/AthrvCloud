//FormAI DATASET v1.0 Category: Game ; Style: grateful
#include <stdio.h>

int main() {
    printf("Welcome to the Gratitude Game!\n");
    printf("We will take turns expressing gratitude until someone repeats. Let's start!\n");

    char* list[10]; // create array to hold gratitude entries
    int index = 0; // set starting index at 0
    int score = 0; // set starting score at 0

    while (index < 10) { // loop until 10 entries
        char entry[50]; // create string to hold input
        printf("Gratitude #%d: ", index+1); // prompt for input
        scanf("%s", entry); // get input from user

        int unique = 1; // assume input is unique

        for (int i = 0; i < index; i++) { // loop through previous entries
            if (strcmp(list[i], entry) == 0) { // check for repeat
                printf("You already said that! Try again.\n"); // alert user and start again
                unique = 0; // set unique flag to false
                break;
            }
        }

        if (unique) { // if input is unique
            list[index] = entry; // add input to list
            index++; // increment index
            printf("Great! Your gratitude has been added to the list.\n"); // confirm entry
            score++; // increment score
        }

        printf("Your current score is %d.\n", score); // display current score
    }

    printf("You have reached 10 unique gratitudes! Thanks for playing.\n"); // end game message

    return 0; // end program
}